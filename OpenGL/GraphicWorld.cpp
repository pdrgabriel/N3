#include "GraphicWorld.h"

void GraphicWorld::zoomIn()
{
	maximumX--;
	maximumY--;
	
	minimumX++;
	minimumY++;
}

void GraphicWorld::zoomOut()
{
	maximumX++;
	maximumY++;
	
	minimumX--;
	minimumY--;
}

void GraphicWorld::addGraphicObject(GraphicObject* graphicObject)
{
	graphicObjects.push_back(graphicObject);
}

void GraphicWorld::setOrtho2d()
{
	gluOrtho2D(minimumX, maximumX, minimumY, maximumY);
}

void GraphicWorld::draw()
{
	for(auto it = graphicObjects.begin(); it != graphicObjects.end(); it++)
		(*it)->draw();
}

GraphicObject* GraphicWorld::selectedGraphicObject(Point4D point)
{
	GraphicObject* selectedGraphicObject;

	for (auto it = graphicObjects.begin(); it != graphicObjects.end(); it++)
	{
		selectedGraphicObject = (*it);

		if (selectedGraphicObject->pointIsInside(point))
			return selectedGraphicObject;
	}

	return nullptr;
}

void GraphicWorld::drawSRU()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(1.0f);
	glBegin( GL_LINES );
	glVertex2f( 0.0f, 0.0f );
	glVertex2f(  10.0f, 0.0f );
	glEnd();
 
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin( GL_LINES);
	glVertex2f(  0.0f, 0.0f);
	glVertex2f(  0.0f,  10.0f );
	glEnd();	
}