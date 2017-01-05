#ifndef GAME_HPP_INCLUDE 
#define GAME_HPP_INCLUDE

#include <iostream>

#include "namespace.hpp"
#include "player.hpp"
#include "arena.hpp"

class CGame{
	public:
		CGame();
		virtual ~CGame();

	protected:
		CPlayer* m_playerOne;
		CPlayer* m_playerTwo;
		CArena m_arena;
};

#endif