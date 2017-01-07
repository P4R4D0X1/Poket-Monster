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
		void flood(float p_stateImpactProb);
		bool stateImpact();

		Arena::STATE getState();

	protected:
		Arena::STATE m_state;
		int m_stateLongevity;
		float m_stateImpactProb;
};

#endif