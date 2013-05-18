#include "AdditionState.h"

void AdditionState::handleKeyBoardSpecialKeyCommand(int key, GLint px, GLint py)
{
	switch(key)
	{
	case GLUT_KEY_INSERT:
		parentGraphicObject = graphicWorld->getNextObject();
		break;

	case GLUT_KEY_HOME:
		graphicWorld->deselectAllGraphicObjects();
		parentGraphicObject = nullptr;
		break;
	}
}

void AdditionState::handleKeyBoardCommand(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'S':
		currentPrimitive = GL_LINE_STRIP;
		break;

	case 'L':
		currentPrimitive = GL_LINE_LOOP;
		break;
	}
}

void AdditionState::handleMouseClickCommand(int button,int state, int x, int y)
{
	if (state != GLUT_DOWN)
		return;

	switch(button)
	{
	case GLUT_LEFT_BUTTON:

		if (graphicObject == nullptr)
		{
			graphicObject = new GraphicObject(currentPrimitive);
			if (parentGraphicObject != nullptr)
				parentGraphicObject->addChild(graphicObject);
			else
				graphicWorld->addGraphicObject(graphicObject);
		}

		graphicObject->addPoint(new Point4D(x, y));

		break;

	case GLUT_RIGHT_BUTTON:
		graphicObject->removeLastSimulatedPoint();
		graphicObject = nullptr;
		
		break;
	}
}

void AdditionState::handleMouseMoveCommand(int x, int y)
{
	if (graphicObject != nullptr)
		graphicObject->simulateNewPoint(x, y);
}
