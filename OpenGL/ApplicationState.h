#include "GraphicWorld.h"

#pragma once;
/** Abstract class that represents the state of the application. See AdditionState and EditionState.*/
class ApplicationState
{
protected:
	GraphicWorld* graphicWorld;

	ApplicationState(GraphicWorld* graphicWorld)
	{
		this->graphicWorld = graphicWorld;
	}

	~ApplicationState()
	{
		delete graphicWorld;
	}

public:
	virtual void handleKeyBoardSpecialKeyCommand(int key, GLint px, GLint py) = 0;
	virtual void handleKeyBoardCommand(unsigned char key, int x, int y) = 0;
	virtual void handleMouseClickCommand(int button,int state, int x, int y) = 0;
	virtual void handleMouseMoveCommand(int x, int y) = 0;
};