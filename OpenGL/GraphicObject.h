#include <vector>
#include<math.h>
#include "GL/gl.H"
#include "GL/glut.h"

#include "BoundingBox.h"
#include "Color.h"

#include "transform.h"

using namespace std;

#pragma once;

class GraphicObject
{
private:
	GLenum primitive;
	vector<Point4D*> points;
	vector<GraphicObject*> children;
	BoundingBox* boundingBox;
	Color color;
	Transform matrix;

	void updateBoundingBox();
	double calculatePointsDistance(Point4D* point, Point4D* other);

	static const double DELTA_POINT_DISTANCE; //The actual distance is 5px. We use 25 due to performance (sqrt is expensive)

public:
	void removeLastSimulatedPoint();
	void simulateNewPoint(float x, float y);

	void addChild(GraphicObject* child);
	void addPoint(Point4D* point);
	void removePoint(Point4D* point);
	void draw();
	void update();

	void setMatrix(Transform matrix);

	Point4D getBoundingBoxCenter();
	Transform getMatrix();

	void setColor(Color);

	bool pointIsInside(Point4D point);

	Point4D* selectedPoint(Point4D pointClicked);

	GraphicObject(GLenum primitive)
	{
		this->primitive = primitive;
		this->boundingBox = new BoundingBox();
		this->matrix.MakeIdentity();
	}

	~GraphicObject()
	{
		for(auto it = points.begin(); it != points.end(); it++)
			delete *it;

		points.clear();

		delete boundingBox;
	}
};