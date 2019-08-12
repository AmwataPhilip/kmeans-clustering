#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>

namespace AMWPHI001
{
class Point
{
private:
	double x, y;
	int group;

public:
	Point(double x, double y) : x(x), y(y), group(-1) {}			   // Centroid case constructor
	Point(double x, double y, int group) : x(x), y(y), group(group) {} // Regular point constructor
	~Point() = default;

	double getX()
	{
		return this->x;
	}

	double getY()
	{
		return this->y;
	}

	void setX(double x)
	{
		this->x = x;
	}

	void setY(double y)
	{
		this->y = y;
	}
};

class Kmean
{
private:
	std::vector<Point> Dataset; // Input data set
	size_t k;					// Number of clusters
	size_t t;					// Number of iterations

public:
	Kmean(std::vector<Point> dataSet, size_t k, size_t t) : Dataset(dataSet), k(k), t(t) {}
	~Kmean() = default;

	double l2Distance(Point datum, Point centroid);
	std::vector<Point> kMeans(const std::vector<Point> data, size_t k, size_t iter);
};

} // namespace AMWPHI001

#endif // !KMEANS_HPP
#define KMEANS_HPP
