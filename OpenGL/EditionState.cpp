#include "EditionState.h"

void EditionState::handleKeyBoardSpecialKeyCommand(int key, GLint px, GLint py)
{
	Transform resultMatrix;

	switch(key)
	{
	case GLUT_KEY_LEFT:
		resultMatrix = transformer.makeTranslationLeft(graphicObject);
		break;

	case GLUT_KEY_RIGHT:
		resultMatrix = transformer.makeTranslationRight(graphicObject);
		break;

	case GLUT_KEY_UP:
		resultMatrix = transformer.makeTranslationUp(graphicObject);
		break;

	case GLUT_KEY_DOWN:
		resultMatrix = transformer.makeTranslationDown(graphicObject);
		break;

	case GLUT_KEY_PAGE_UP:
		resultMatrix = transformer.makeScaleUp(graphicObject);
		break;

	case GLUT_KEY_PAGE_DOWN:
		resultMatrix = transformer.makeScaleDown(graphicObject);
		break;

	case GLUT_KEY_F11:
		resultMatrix = transformer.makeRotation(graphicObject);
		break;
	}

	graphicObject->setMatrix(resultMatrix);
}

void EditionState::handleKeyBoardCommand(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'C':
		if (graphicObject != nullptr)
			graphicObject->setColor(Color::GREEN());
		break;

	case 'D':
		if (pointToEdit != nullptr){
			graphicObject->removePoint(pointToEdit);
			pointToEdit = nullptr;
		}
		break;
	}
}

void EditionState::handleMouseClickCommand(int button,int state, int x, int y)
{
	if (state != GLUT_DOWN)
		return;

	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		graphicObject = graphicWorld->selectedGraphicObject(Point4D(x, y));

		if(graphicObject != nullptr)
			pointToEdit = graphicObject->selectedPoint(Point4D(x, y));

		break;

	case GLUT_RIGHT_BUTTON:
		if (pointToEdit != nullptr)
			graphicObject->update();

		pointToEdit = nullptr;

		break;
	}
}

void EditionState::handleMouseMoveCommand(int x, int y)
{
	if (pointToEdit == nullptr)
		return;

	pointToEdit->SetX(x);
	pointToEdit->SetY(y);
}