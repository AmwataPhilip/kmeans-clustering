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
    int iterNum = 6;
    std::string fName = argv[1];

    // Input data set
    Point one(2.0, 10.0, 1), two(2.0, 5.0, 2), three(8.0, 4.0, 3), four(5.0, 8.0, 4);
    Point five(7.0, 5.0, 5), six(6.0, 4.0, 6), seven(1.0, 2.0, 7), eight(4.0, 9.0, 8);
    std::vector<Point> Dataset{one, two, three, four, five, six, seven, eight};

    std::vector<Point> cluster1, cluster2, cluster3; // Partitioning clusters
    clusVec clusters{cluster1, cluster2, cluster3};
    Point centroid1(2.0, 10.0),
        centroid2(5.0, 8.0), centroid3(1.0, 2.0); // Initial centroids for each cluster
    std::vector<Point> centroidVec{centroid1, centroid2, centroid3};

    Kmean meanK(Dataset, clusterNum, iterNum);

    meanK.runKMeans(centroidVec, clusters, fName);

    return 0;
}
