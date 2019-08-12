#include "../include/kmeans.hpp"

using namespace AMWPHI001;

double Kmean::l2Distance(Point datum, Point centroid)
{
	return sqrt(pow(datum.getX() - centroid.getX(), 2.0) + pow(datum.getY() - centroid.getY(), 2.0));
}
