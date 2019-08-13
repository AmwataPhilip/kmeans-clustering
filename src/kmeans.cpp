#include "../include/kmeans.hpp"

using namespace AMWPHI001;

double Kmean::l2Distance(Point datum, Point centroid)
{
	return sqrt(pow(datum.getX() - centroid.getX(), 2.0) + pow(datum.getY() - centroid.getY(), 2.0));
}

void Kmean::runKMeans(std::vector<Point> centroidVec, clusVec clusters, std::string fName)
{
	std::ofstream resultsFile(fName);
	std::vector<Point> curDataset = this->Dataset;
	std::vector<Point> cenVecLocal = centroidVec;
	std::vector<size_t> assigned(curDataset.size());

	for (size_t iter = 0; iter < this->t; ++iter)
	{
		for (size_t point = 0; point < curDataset.size(); ++point)
		{
			double bestDistance = std::numeric_limits<double>::max();
			size_t bestCluster = 0;

			for (size_t cluster = 0; cluster < this->k; ++cluster)
			{
				const double distance = l2Distance(curDataset[point], cenVecLocal[cluster]);

				if (distance < bestDistance)
				{
					bestDistance = distance;
					bestCluster = cluster;
				}
			}
			assigned[point] = bestCluster;
			clusters[bestCluster].push_back(curDataset[point]);
		}
		Point empty1(0.0, 0.0),
			empty2(0.0, 0.0), empty3(0.0, 0.0); // 3 empty points to avoid segfault
		// Add up all values in clusters and count them
		std::vector<Point> newCentroidVec{empty1, empty2, empty3};
		std::vector<size_t> counts(this->k, 0);

		for (size_t point = 0; point < curDataset.size(); ++point)
		{
			const auto cluster = assigned[point];
			newCentroidVec[cluster].setX(newCentroidVec[cluster].getX() + curDataset[point].getX());
			newCentroidVec[cluster].setY(newCentroidVec[cluster].getY() + curDataset[point].getY());
			counts[cluster] += 1;
		}

		// Divide the sums calculated above to get new centroids
		for (size_t cluster = 0; cluster < this->k; ++cluster)
		{
			// Avoid zero division error by making 0/0 into 0/1
			const auto count = std::max<size_t>(1, counts[cluster]);

			cenVecLocal[cluster].setX(newCentroidVec[cluster].getX() / count);
			cenVecLocal[cluster].setY(newCentroidVec[cluster].getY() / count);
		}

		// Print out results to the console and to a text file
		std::vector<int> added;
		if (resultsFile.is_open())
		{
			resultsFile << "Iteration " << iter + 1 << "\n\n";
			std::cout << "Iteration " << iter + 1 << "\n\n";
			for (size_t n = 0; n < clusters.size(); ++n)
			{
				resultsFile << "Cluster " << n + 1 << ": ";
				std::cout << "Cluster " << n + 1 << ": ";
				for (auto point : clusters[n])
				{
					if (std::find(added.begin(), added.end(), point.getGroup()) != added.end())
					{
						continue;
					}
					else
					{
						added.push_back(point.getGroup());
						resultsFile << point.getGroup() << ", ";
						std::cout << point.getGroup() << ", ";
					}
				}
				resultsFile << "\n"
							<< "Centroid: "
							<< "( " << cenVecLocal[n].getX() << ", " << cenVecLocal[n].getY() << " )\n\n";
				std::cout << "\n"
						  << "Centroid: "
						  << "( " << cenVecLocal[n].getX() << ", " << cenVecLocal[n].getY() << " )\n\n";
			}
			resultsFile << "----------------------\n";
			std::cout << "----------------------\n";
		}
		else
		{
			std::cout << "Unable to open file!\n";
		}
	}
	std::cout << "Question 1: How many iterations needed for dataset to converge?\n3\n";
	resultsFile << "Question 1: How many iterations needed for dataset to converge?\n3\n";
	resultsFile.close();
}
