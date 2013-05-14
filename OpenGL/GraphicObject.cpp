#include "GraphicObject.h"

const double GraphicObject::DELTA_POINT_DISTANCE = 25;

void GraphicObject::setMatrix(Transform matrix)
{
	this->matrix = matrix;
}

Transform GraphicObject::getMatrix()
{
	return this->matrix;
}

Point4D GraphicObject::getBoundingBoxCenter()
{
	return boundingBox->getCenter();
}

void GraphicObject::draw()
{
	Point4D* point;
	glColor3f(color.getRed(), color.getGreen(), color.getBlue());

	glPushMatrix();
    glMultMatrixd(matrix.GetData());

	glBegin(primitive);

	for(auto it = points.begin(); it != points.end(); it++)
	{
		point = (*it);
		glVertex2f(point->GetX(),point->GetY());
	}

	glEnd();
	boundingBox->draw();

	for(auto it = children.begin(); it != children.end(); it++)
		(*it)->draw();

	glPopMatrix();
}

void GraphicObject::setColor(Color color)
{
	this->color = color;
}

Point4D* GraphicObject::selectedPoint(Point4D pointClicked)
{
	if (!pointIsInside(pointClicked))
		return nullptr;

	Point4D* point;

	for(auto it = points.begin(); it != points.end(); it++)
	{
		point = (*it);

		if(calculatePointsDistance(point, &pointClicked) <= DELTA_POINT_DISTANCE)
			return point;
	}

	return nullptr;

}

double GraphicObject::calculatePointsDistance(Point4D* point, Point4D* other)
{
	return pow((point->GetX() - other->GetX()), 2) + pow((point->GetY() - other->GetY()), 2);
}

bool GraphicObject::pointIsInside(Point4D point)
{
	if (!boundingBox->pointInBoundingBox(point))
		return false;

	Point4D* objectPoint;
	Point4D* nextObjectPoint;

	int edgesIntersected = 0;

	for (int i = 0; i < points.size(); i++)
	{
		objectPoint = points.at(i);
		nextObjectPoint = points.at((i + 1) % points.size());

		if (objectPoint->GetY() != nextObjectPoint->GetY())
		{
			double delta = ((point.GetY() - objectPoint->GetY()) / (nextObjectPoint->GetY() - objectPoint->GetY()));

			Point4D intersectionPoint(objectPoint->GetX() +  ((nextObjectPoint->GetX() - objectPoint->GetX()) * delta), point.GetY());

			if(intersectionPoint.GetX() == point.GetX())
				return true;
			else
				if (intersectionPoint.GetX() > point.GetX() && delta >= 0 && delta <= 1)
					edgesIntersected++;
		}
		else
			if ((point.GetY() == objectPoint->GetY()) &&
				point.GetX() >= min(objectPoint->GetX(), nextObjectPoint->GetX()) &&
				point.GetX() <= max(objectPoint->GetX(), nextObjectPoint->GetX()))
				return true;
	}

	return edgesIntersected % 2 != 0;
}

void GraphicObject::simulateNewPoint(float x, float y)
{
	Point4D* point = points.back();

	point->SetX(x);
	point->SetY(y);
}

void GraphicObject::removeLastSimulatedPoint()
{
	auto it = points.end();
	it--;

	Point4D* point = *it;

	points.erase(it);
	delete point;
}

void GraphicObject::addChild(GraphicObject* child)
{
	children.push_back(child);
}

void GraphicObject::addPoint(Point4D* point)
{
	points.push_back(point);

	if (points.size() == 1)
		points.push_back(new Point4D(point->GetX(), point->GetY()));

	updateBoundingBox();
}

void GraphicObject::removePoint(Point4D* point)
{
	for (auto it = points.begin(); it != points.end(); it++)
	{
		if ((*it) == point){
			points.erase(it);
			break;
		}
	}
	
	updateBoundingBox();
}

void GraphicObject::update()
{
	updateBoundingBox();
}

void GraphicObject::updateBoundingBox()
{
	boundingBox->fromPoints(points);
}
