#include <vector>
#include "GL/GL.H"
#include "GL/GLUT.H"

#include "point4d.h"

using namespace std;

#pragma once;

class BoundingBox{
private:
	Point4D maxPoint;
	Point4D minPoint;

public:
	BoundingBox()
	{
	}

	Point4D getCenter();

	void fromPoints(const vector<Point4D*> points);
	void draw();

	bool pointInBoundingBox(const Point4D& point);

	BoundingBox(Point4D maxPoint, Point4D minPoint)
	{
		this->maxPoint = maxPoint;
		this->minPoint = minPoint;
	}
};