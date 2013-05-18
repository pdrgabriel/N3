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
	bool isSelected;

	void updateBoundingBox();
	double calculatePointsDistance(Point4D* point, Point4D* other);

	static const double DELTA_POINT_DISTANCE; //The actual distance is 5px. We use 25 due to performance (sqrt is expensive)

public:
	/** Remove point used for simulation. This method should be called after user is done drawing the GraphicObject.*/
	void removeLastSimulatedPoint();

	/**Adds a point to help user preview the inclusion of a new point. This point must be removed after user is done drawing.*/
	void simulateNewPoint(float x, float y);
	void addPoint(Point4D* point);

	/**Adds a GraphichObject as child of this instance. All transformations applied to this instance will reflect to all of its children.*/
	void addChild(GraphicObject* child);
	void removePoint(Point4D* point);
	void draw();
	void update();

	/**Indicates if this instance is or is not selected. When selected, bounding-box is shown and line width gets larger.*/
	void setSelected(bool selected);
	void setMatrix(Transform matrix);

	Point4D getBoundingBoxCenter();
	Transform getMatrix();

	void setColor(Color);

	/**Returns true if the given point is inside this instance. Otherwise, false.*/
	bool pointIsInside(Point4D point);

	/**Returns the point(vertex) selected by user. If no vertex was selected, returns nullptr.*/
	Point4D* selectedPoint(Point4D pointClicked);

	GraphicObject(GLenum primitive)
	{
		this->primitive = primitive;
		this->boundingBox = new BoundingBox();
		this->matrix.MakeIdentity();
		this->isSelected = false;
	}

	~GraphicObject()
	{
		for (auto it = children.begin(); it != children.end(); it++)
			delete *it;

		for(auto it = points.begin(); it != points.end(); it++)
			delete *it;

		points.clear();

		delete boundingBox;
	}
};
