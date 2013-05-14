#include <vector>

#include "GraphicObject.h"

class GraphicWorld
{
private:
	float minimumX;
	float maximumX;
	float minimumY;
	float maximumY;

	vector<GraphicObject*> graphicObjects;

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

	GraphicObject* selectedGraphicObject(Point4D point);

	void addGraphicObject(GraphicObject* graphicObject);
	void zoomIn();
	void zoomOut();

	void panLeft();
	void panRight();

	void drawSRU();
	void draw();
	void setOrtho2d();
};