#include "electric.hpp"

CElectric::CElectric(){
}

CElectric::CElectric(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense) : CMonster(p_name, p_hp, p_speed, p_attack, p_defense, Monster::TYPE::electric){
}

CElectric::CElectric(){
}

bool CElectric::paralyze(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);


	return (l_dist6(l_rng) <= m_paralysis * 100) ? true : false;
}