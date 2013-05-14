#include "ApplicationState.h"
#include "Transformer.h"

class EditionState : public ApplicationState
{
private:
	GraphicObject* graphicObject;
	Point4D* pointToEdit;
	Transformer transformer;

public:

	EditionState(GraphicWorld* graphicWorld)
		: ApplicationState(graphicWorld)
	{
		graphicObject = nullptr;
		pointToEdit = nullptr;
	}

	~EditionState()
	{
		delete graphicObject;
		delete pointToEdit;
	}

	void handleKeyBoardSpecialKeyCommand(int key, GLint px, GLint py);
	void handleKeyBoardCommand(unsigned char key, int x, int y);
	void handleMouseClickCommand(int button,int state, int x, int y);
	void handleMouseMoveCommand(int x, int y);
};