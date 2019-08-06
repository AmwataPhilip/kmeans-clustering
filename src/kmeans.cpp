#include "../include/kmeans.hpp"

using namespace AMWPHI001;

void Kmean::setInitValues()
{
	Kmean::vecVec table;
	std::vector<int> X = {2, 2, 8, 5, 7, 6, 1, 4};
	std::vector<int> Y = {10, 5, 4, 8, 5, 4, 2, 9};
	std::vector<int> cluster1, cluster2, cluster3;

	table.push_back(X);
	table.push_back(Y);
}

Kmean::Kmean(/* args */)
{
}

Kmean::~Kmean()
{
}
