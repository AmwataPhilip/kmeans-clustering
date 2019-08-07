#include "../include/kmeans.hpp"

using namespace AMWPHI001;

void Kmean::setInitValues()
{
	std::vector<int> X = {2, 2, 8, 5, 7, 6, 1, 4};
	std::vector<int> Y = {10, 5, 4, 8, 5, 4, 2, 9};
	Kmean::vecVec table = {X, Y};
	std::vector<double> cluster1 = {2, 10};
	std::vector<double> cluster2 = {5, 8};
	std::vector<double> cluster3 = {1, 2};
}

Kmean::Kmean(/* args */)
{
}

Kmean::~Kmean()
{
}
