#include "ApplicationState.h"

class AdditionState : public ApplicationState
{
private:
	GraphicObject* graphicObject;
	GLenum currentPrimitive;

public:

	AdditionState(GraphicWorld* graphicWorld)
		: ApplicationState(graphicWorld)
	{
		currentPrimitive = GL_LINE_LOOP;
		graphicObject = nullptr;
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