#pragma once;

/** This class represents colors using the RGB notation. Some predefined colors are presented through static methods.*/
class Color{
private:
	unsigned char rgb[3];

public:
	Color()
	{
		rgb[0] = 0;
		rgb[1] = 0;
		rgb[2] = 0;
	}

	Color(unsigned char red, unsigned char green, unsigned char blue)
	{
		rgb[0] = red;
		rgb[1] = green;
		rgb[2] = blue;
	}

	unsigned char getRed()
	{
		return rgb[0];
	}

	unsigned char getGreen()
	{
		return rgb[1];
	}

	unsigned char getBlue()
	{
		return rgb[2];
	}

	static Color RED()
	{
		return Color(255, 0, 0);
	}

	static Color GREEN()
	{
		return Color(0, 255, 0);
	}

	static Color BLUE()
	{
		return Color(0, 0, 255);
	}

	static Color BLACK()
	{
		return Color(0, 0, 0);
	}

	static Color YELLOW()
	{
		return Color(255, 255, 0);
	}

	static Color PURPPLE()
	{
		return Color(64, 0, 128);
	}
};