#include "plant.hpp"

CPlant::CPlant(){
}

CPlant::CPlant(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_heal) : CGrass(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::plant){
	m_heal = p_heal;
}

CPlant::CPlant(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_heal, std::vector<CAttack*>& p_attacks) : CGrass(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_attacks, Monster::TYPE::plant){
}

CPlant::~CPlant(){
}

void CPlant::specialAttack(CMonster& p_enemy, CArena& p_arena){
	if (heal())
		m_state = Monster::STATE::feelgood;
}

bool CPlant::heal(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	return (l_dist6(l_rng) <= m_heal * 100) ? true : false;
}

void CPlant::info(){
	CGrass::info();
	std::cout << "Heal : " << m_heal << std::endl;
}