#include "arena.hpp"

CArena::CArena(){
}

CArena::~CArena(){
}

void CArena::flood(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 3);

	m_floodedTour = l_dist6(l_rng);
}

Arena::STATE CArena::getState(){
	return m_state;
}

void CArena::setState(Arena::STATE p_state){
	m_state = p_state;
}