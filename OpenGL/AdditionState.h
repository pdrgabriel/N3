#include "ApplicationState.h"

/** Represents the state of addition. This state provides handlers for input events during the creation of new GraphicObjects*/
class AdditionState : public ApplicationState
{
private:
	GraphicObject* graphicObject;
	GLenum currentPrimitive;
	GraphicObject* parentGraphicObject;

public:

	AdditionState(GraphicWorld* graphicWorld)
		: ApplicationState(graphicWorld)
	{
		currentPrimitive = GL_LINE_LOOP;
		graphicObject = nullptr;
		parentGraphicObject = nullptr;
	}

	~AdditionState()
	{
		delete graphicObject;
	}

	void handleKeyBoardSpecialKeyCommand(int key, GLint px, GLint py);
	void handleKeyBoardCommand(unsigned char key, int x, int y);
	void handleMouseClickCommand(int button,int state, int x, int y);
	void handleMouseMoveCommand(int x, int y);
};