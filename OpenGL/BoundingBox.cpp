#include "BoundingBox.h"

Point4D BoundingBox::getCenter()
{
	double centerX = ((maxPoint.GetX() - minPoint.GetX()) / 2) + minPoint.GetX();
	double centerY = ((maxPoint.GetY() - minPoint.GetY()) / 2) + minPoint.GetY();

	return Point4D(centerX, centerY);
}

bool BoundingBox::pointInBoundingBox(const Point4D& point)
{
	if (point.GetX() <= maxPoint.GetX() && point.GetX() >= minPoint.GetX())
		return true;

	if (point.GetY() <= maxPoint.GetY() && point.GetY() >= minPoint.GetY())
		return true;

	return false;
}

void BoundingBox::draw()
{
	glBegin(GL_LINE_LOOP);

	glVertex2f(maxPoint.GetX(), maxPoint.GetY());
	glVertex2f(maxPoint.GetX(), minPoint.GetY());
	glVertex2f(minPoint.GetX(), minPoint.GetY());
	glVertex2f(minPoint.GetX(), maxPoint.GetY());

	glEnd();
}

void BoundingBox::fromPoints(const vector<Point4D*> points)
{
	auto iterator = points.begin();
	Point4D* point = (*iterator);

	float maxX = point->GetX();
	float minX = point->GetX();
	float maxY = point->GetY();
	float minY = point->GetY();

	for(; iterator != points.end(); iterator++)
	{
		point = (*iterator);

		if (point->GetX() > maxX)
			maxX = point->GetX();

		if (point->GetX() < minX)
			minX = point->GetX();

		if (point->GetY() > maxY)
			maxY = point->GetY();

		if (point->GetY() < minY)
			minY = point->GetY();
	}

	this->maxPoint = Point4D(maxX, maxY);
	this->minPoint = Point4D(minX, minY);
}
