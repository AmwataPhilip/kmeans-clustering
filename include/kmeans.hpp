#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <cstdio>
#include <iostream>
#include <vector>

namespace AMWPHI001
{

class Kmean
{
private:
	/* data */
public:
	Kmean(/* args */);
	~Kmean();

	typedef std::vector<std::vector<int>> vecVec;

	void setInitValues();
	double square(double num);
	double l2Distance(double x, double y);
	vecVec kMeans(const vecVec data, size_t k, size_t iter);
};

} // namespace AMWPHI001

#endif // !KMEANS_HPP
#define KMEANS_HPP
