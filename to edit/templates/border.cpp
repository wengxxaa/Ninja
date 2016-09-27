#include "templates/border.h"

void Border::set( int x, int y, int w, int h )
{
	left = x;
	top = y;
	width = w;
	height = h;
}


int Border::getX()
{
    return left;
}

int Border::getY()
{
    return top;
}



int Border::getWidth()
{
    return width;
}

int Border::getHeight()
{
    return height;
}



int Border::getLeft()
{
    return left;
}

int Border::getRight()
{
    return left + width;
}



int Border::getTop()
{
    return top;
}

int Border::getBot()
{
    return top + height;
}