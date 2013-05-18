#include "GraphicObject.h"

/**Encapsulates the algorithms for transformations applicable to GraphicObjects.*/
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

	/**Returns a Transform matrix that contains all transformations made to the GraphichObject, plus the left translation*/
	Transform makeTranslationLeft(GraphicObject* graphicObject);
	
	/**Returns a Transform matrix that contains all transformations made to the GraphichObject, plus the right translation*/
	Transform makeTranslationRight(GraphicObject* graphicObject);

	/**Returns a Transform matrix that contains all transformations made to the GraphichObject, plus the up translation*/
	Transform makeTranslationUp(GraphicObject* graphicObject);

	/**Returns a Transform matrix that contains all transformations made to the GraphichObject, plus the down translation*/
	Transform makeTranslationDown(GraphicObject* graphicObject);


	/**Returns a Transform matrix that contains all transformations made to the GraphichObject, plus the scale up operation*/
	Transform makeScaleUp(GraphicObject* graphicObject);

	/**Returns a Transform matrix that contains all transformations made to the GraphichObject, plus the scale down operation*/
	Transform makeScaleDown(GraphicObject* graphicObject);

	/**Returns a Transform matrix that contains all transformations made to the GraphichObject, plus the rotation.*/
	Transform makeRotation(GraphicObject* graphicObject);
};