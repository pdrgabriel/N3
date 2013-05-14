#include "Transformer.h"

const double Transformer::ONE_DEGREE_IN_RADIANS = 0.017453292519943295769236907684886;

Transform Transformer::makeTranslationLeft(GraphicObject* graphicObject)
{
	translationMatrix.MakeTranslation(Point4D(-translactionFactor,0,0));

	return graphicObject->getMatrix() * translationMatrix;
}

Transform Transformer::makeTranslationRight(GraphicObject* graphicObject)
{
	translationMatrix.MakeTranslation(Point4D(translactionFactor,0,0));

	return graphicObject->getMatrix() * translationMatrix;
}

Transform Transformer::makeTranslationUp(GraphicObject* graphicObject)
{
	translationMatrix.MakeTranslation(Point4D(0,translactionFactor,0));

	return graphicObject->getMatrix() * translationMatrix;
}

Transform Transformer::makeTranslationDown(GraphicObject* graphicObject)
{
	translationMatrix.MakeTranslation(Point4D(0,-translactionFactor,0));

	return graphicObject->getMatrix() * translationMatrix;
}

Transform Transformer::makeScaleUp(GraphicObject* graphicObject)
{
	return makeScale(graphicObject, scaleFactor);
}

Transform Transformer::makeScaleDown(GraphicObject* graphicObject)
{
	return makeScale(graphicObject, scaleFactor/4);
}

Transform Transformer::makeScale(GraphicObject* graphicObject, double factor)
{
	Point4D boundingBoxCenter = graphicObject->getBoundingBoxCenter();

	translationMatrix.MakeTranslation(-boundingBoxCenter);

	scaleMatrix.MakeScale(factor, factor, 1);

	reverseTranslationMatrix.MakeTranslation(boundingBoxCenter);

	return graphicObject->getMatrix() * (reverseTranslationMatrix * ( scaleMatrix * translationMatrix));
}

Transform Transformer::makeRotation(GraphicObject* graphicObject)
{
	Point4D boundingBoxCenter = graphicObject->getBoundingBoxCenter();

	translationMatrix.MakeTranslation(-boundingBoxCenter);

	rotationMatrix.MakeZRotation(ONE_DEGREE_IN_RADIANS * rotationAngle);

	reverseTranslationMatrix.MakeTranslation(boundingBoxCenter);

	return graphicObject->getMatrix() * (reverseTranslationMatrix * (rotationMatrix * translationMatrix));
}