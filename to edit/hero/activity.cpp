#include "hero/activity.h"

Activity::Activity()
{
	active = false;
	line = 0;
	counter = 0;
}

Activity::~Activity()
{
	free();
}

void Activity::free()
{
	active = false;
	line = 0;
	counter = 0;
}



void Activity::start()
{
	if( counter == 0 )
	{
		// active = true;
		counter = 1;
	}
}

void Activity::check()
{
	if( counter >= line )
	{
		// active = false;
		counter = 0;
	}
	else if( counter > 0 )
	{
		// active = true;
		counter++;
	}
}

bool Activity::Do()
{
	if( counter == 0 )
	{
		return true;
	}
	
	return false;
}


void Activity::setActive( bool a )
{
	active = a;
}

bool Activity::isActive()
{
	return active;
}

void Activity::setLine( sf::Uint8 nr )
{
	line = nr;
}

sf::Uint8 Activity::getLine()
{
	return line;
}