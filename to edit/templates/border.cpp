#include "templates/border.h"
#include <stdio.h>

void Border::set( int x, int y, int w, int h )
{
	left = x;
	top = y;
	width = w;
	height = h;
}


const int& Border::getX() const
{
    return left;
}

const int& Border::getY() const
{
    return top;
}



const int& Border::getWidth() const
{
    return width;
}

const int& Border::getHeight() const
{
    return height;
}



const int& Border::getLeft() const
{
    return left;
}

const int Border::getRight() const
{
    return left + width;
}



const int& Border::getTop() const
{
    return top;
}

const int Border::getBot() const
{
    return top + height;
}


bool Border::checkCollision( int x, int y, int w, int h )
{
	if( x + w > left && x < left + width )
	{
		if( y + h > top && y < top + height )
		{
			return true;
		}
	}
	
	return false;
}

bool Border::catchCollision( int x, int y, int w, int h )
{
	if( y + h <= top )
        return false;

    if( y >= top + height )
        return false;

    if( x + w <= left )
        return false;

    if( x >= left + width )
        return false;

    return true;
}


bool Border::catchHorizontally( int x, int w )
{
	if( x + w > left )
		return true;
	
	else if( x < left + width )
		return true;
	
	return false;
}

bool Border::catchVertically( int y, int h )
{
	if( y + h > top )
		return true;
		
	else if( y < top + height )
		return true;
		
	return false;
}