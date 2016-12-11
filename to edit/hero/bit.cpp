#include "hero/bit.h"

Bit::Bit()
{
	x = y = 0;
	active = false;
	vel = 0;
}

Bit::~Bit()
{
	free();
}

void Bit::free()
{
	x = y = 0;
	active = false;
	vel = 0;
}

bool Bit::isActive()
{
	return active;
}

void Bit::start( int vel, int startX, int startY )
{
	if( !active )
	{
		active = true;
		this->vel = vel;
		this->x = startX;
		this->y = startY;
	}
}

void Bit::go()
{
	if( active )
		x += vel;
}
	
void Bit::reset()
{
	active = false;
	x = y = 0;
	vel = 0;
}

	
int Bit::getX()
{
	return x;
}

int Bit::getY()
{
	return y;
}

int Bit::getVel()
{
	return vel;
}
