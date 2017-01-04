#ifndef ARENA_HPP_INCLUDE
#define ARENA_HPP_INCLUDE

#include <iostream>
#include <random>

#include "namespace.hpp"

class CArena{
	public:
		CArena();
		virtual ~CArena();

		void updateState();
		void flood();
		Arena::STATE getState();
		void setState(Arena::STATE p_state);

	protected:
		Arena::STATE m_state;
		int m_stateLongevity;
};

#endif