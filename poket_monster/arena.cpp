#include "arena.hpp"

CArena::CArena(){
}

CArena::~CArena(){
}

void CArena::updateState(){
	m_stateLongevity--;

	if (m_stateLongevity <= 0)
		m_state == Arena::STATE::normal;
}

void CArena::flood(float p_stateImpactProb){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 3);

	m_state = Arena::STATE::flooded;
	m_stateImpactProb = p_stateImpactProb;
	m_stateLongevity = l_dist6(l_rng);
}

bool CArena::stateImpact(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	return (l_dist6(l_rng) <= (unsigned int)m_stateImpactProb * 100) ? true : false;
}

Arena::STATE CArena::getState(){
	return m_state;
}
