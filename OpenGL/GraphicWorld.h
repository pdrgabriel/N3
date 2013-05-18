#include <vector>

#include "GraphicObject.h"

/** Represents the graphical space.*/
class GraphicWorld
{
private:
	float minimumX;
	float maximumX;
	float minimumY;
	float maximumY;

	vector<GraphicObject*> graphicObjects;
	vector<GraphicObject*>::iterator iterator;

public:
	GraphicWorld()
	{
		maximumX = 500;
		maximumY = 0;

		minimumX = 0;
		minimumY = -500;
	}

	~GraphicWorld()
	{
		for(auto it = graphicObjects.begin(); it != graphicObjects.end(); it++)
			delete *it;

		graphicObjects.clear();
	}

	/** Given a Point4D, returns the GraphicObject selected, i.e, the GraphicObject which the point is inside.
	Returns nullptr if no GraphichObject was selected*/
	GraphicObject* selectedGraphicObject(Point4D point);

	void deselectAllGraphicObjects();
	void addGraphicObject(GraphicObject* graphicObject);
	void zoomIn();
	void zoomOut();

	void drawSRU();
	void draw();

	void setOrtho2d();

	/** Returns, in sequence of inclusion, the GraphicObjects contained in the graphical space.
	This method only iterates through the parent GraphicObjects, children GraphicObjects are not included.*/
	GraphicObject* getNextObject();
};
