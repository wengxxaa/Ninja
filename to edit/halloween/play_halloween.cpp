#include "halloween/play_halloween.h"

Play_halloween::Play_halloween()
{
	state = new State;
	hero = new Hero;
	bg = new Moving_bg;
	brick = new Brick;
	kunai = new Kunai;
	heart = new Heart;
	scope = new Scope;
}

Play_halloween::~Play_halloween()
{
	free();
}

void Play_halloween::free()
{
	delete state;
	delete hero;
	delete bg;
	delete brick;
	delete kunai;
	delete heart;
	delete scope;
}

	
void Play_halloween::load( int screen_w, int screen_h )
{
	bg->load( "data/sprites/play/0.png", screen_w, screen_h );
	brick->load( screen_w, screen_h, 16, 0 );
	kunai->load();
	heart->load();
}

void Play_halloween::setHero( int screen_w, int screen_h, int type )
{
	if( type == 0 )
	{
		hero->load( screen_w, screen_h, "data/sprites/hero/0/" );
	}
	else
	{
		hero->load( screen_w, screen_h, "data/sprites/hero/1/" );
	}
	
	scope->set( hero->getX(), brick->getWidth(), screen_w );
}


void Play_halloween::handle( sf::Event &event )
{
	// hero->handle( event );
}

void Play_halloween::draw( sf::RenderWindow* &window )
{
	mechanics();
	
	bg->fadein( 2 );
	brick->fadein( 2 );
	hero->fadein( 2 );
	kunai->fadein( 2 );
	heart->fadein( 2 );
	
	bg->draw( window );
	brick->drawLadders( window );
	hero->draw( window );
	kunai->draw( window );
	brick->draw( window );
	heart->draw( window );
}

	
State* Play_halloween::getState()
{
	return state;
}

void Play_halloween::set( State* state )
{
	this->state = state;
	state->state = 0;
	
	/*
	// Set chunks
	if( !state->cSwitch )
	{
		backtomenu->turn();
		choice->turn();
	}
	
	// Set music volume
	music->setVolume( state->mVolume );
	
	// Set chunk volume
	backtomenu->setVolume( state->cVolume );
	choice->setVolume( state->cVolume );
	*/
}

	
bool Play_halloween::isQuit()
{
	if( state->state == 3 )
	{
		return true;
	}
	
	return false;
}

bool Play_halloween::nextState()
{
	if( state->state == 1 )
	{
		return true;
	}
	
	return false;
}

bool Play_halloween::backToLevel()
{
	if( state->state == 2 )
	{
		state->state = 0;
		// backtomenu->setState( 0 );
		return true;
	}
		
	return false;
}

	
void Play_halloween::reloadMusic()
{
	// music->reload();
}

