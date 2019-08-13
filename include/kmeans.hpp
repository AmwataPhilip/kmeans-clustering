#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>

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

	int getGroup()
	{
		return this->group;
	}

	void setX(double newX)
	{
		this->x = newX;
	}

	void setY(double newY)
	{
		this->y = newY;
	}
};

typedef std::vector<std::vector<Point>> clusVec;

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
	void runKMeans(std::vector<Point> centroidVec, clusVec clusters);
};

} // namespace AMWPHI001

#endif // !KMEANS_HPP
#define KMEANS_HPP
