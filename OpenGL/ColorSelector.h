#include <cstdlib>

#include "Color.h"

/**This class provides a way to get a random Color instance. */
class ColorSelector
{
private:
	Color colors[6];

public:
	ColorSelector()
	{
		colors[0] = Color::BLACK();
		colors[1] = Color::RED();
		colors[2] = Color::GREEN();
		colors[3] = Color::PURPPLE();
		colors[4] = Color::YELLOW();
		colors[5] = Color::BLUE();
	}

	/** Returns a Color initialized with random values for Red, Green and Blue.*/
	Color getRandomColor();
};