#include "ColorSelector.h"

Color ColorSelector::getRandomColor()
{
	unsigned char randomRedFactor = (rand() % 255);
	unsigned char randomGreenFactor = (rand() % 255);
	unsigned char randomBlueFactor = (rand() % 255);

	return Color(randomRedFactor, randomGreenFactor, randomBlueFactor);
}