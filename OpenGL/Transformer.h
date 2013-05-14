#include "GraphicObject.h"

class Transformer
{
private:
	static const double ONE_DEGREE_IN_RADIANS;

	Transform translationMatrix;
	double translactionFactor;
	double scaleFactor;
	Transform reverseTranslationMatrix;    
	Transform scaleMatrix;
	Transform rotationMatrix;
	double rotationAngle;

	Transform makeScale(GraphicObject* graphicObject, double factor);

public:

	Transformer()
	{
		rotationAngle = 5.0;
		translactionFactor = 2.0f;
		scaleFactor = 2;
	}

	Transform makeTranslationLeft(GraphicObject* graphicObject);
	Transform makeTranslationRight(GraphicObject* graphicObject);
	Transform makeTranslationUp(GraphicObject* graphicObject);
	Transform makeTranslationDown(GraphicObject* graphicObject);

	Transform makeScaleUp(GraphicObject* graphicObject);
	Transform makeScaleDown(GraphicObject* graphicObject);

	Transform makeRotation(GraphicObject* graphicObject);
};