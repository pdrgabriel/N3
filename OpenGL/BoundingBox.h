#include <vector>
#include "GL/GL.H"
#include "GL/GLUT.H"

#include "point4d.h"

using namespace std;

#pragma once;

/**Represents the bounding-box of a GraphicObject. */
class BoundingBox{
private:
	Point4D maxPoint;
	Point4D minPoint;

public:
	BoundingBox()
	{
	}

	/**The Point4D representing the graphical center of this instance.*/
	Point4D getCenter();

	/**Updates the coordinates of the bounding-box based on a vector of Point4D.*/
	void fromPoints(const vector<Point4D*> points);
	void draw();

	/**Returns true if the given point is inside the bounding-box. Otherwise, false.*/
	bool pointInBoundingBox(const Point4D& point);

	BoundingBox(Point4D maxPoint, Point4D minPoint)
	{
		this->maxPoint = maxPoint;
		this->minPoint = minPoint;
	}
};