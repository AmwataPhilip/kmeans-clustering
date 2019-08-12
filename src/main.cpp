/*
*
* Author: Philip Amwata
* Version: 1.0
*
*/
#include "../include/kmeans.hpp"

int main(int argc, const char **argv)
{
    using namespace AMWPHI001;

    int clusterNum = 3;
    int iterNum = 10;

    std::vector<Point> Dataset;                       // Input data set
    std::vector<double> cluster1, cluster2, cluster3; // Partitioning cluster

    Point centroid1(2.0, 10.0), centroid2(5.0, 8.0), centroid3(1.0, 2.0); // Initial centroids for each cluster

    Kmean::Kmean meanK(Dataset, clusterNum, iterNum);
    return 0;
}
