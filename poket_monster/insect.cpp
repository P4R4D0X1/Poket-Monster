#include "insect.hpp"

CInsect::CInsect(){
}

CInsect::CInsect(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_poison) : CGrass(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::insect){
	m_poison = p_poison;
}

CInsect::CInsect(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_poison, std::vector<CAttack*>& p_attacks) : CGrass(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_attacks, Monster::TYPE::insect){
	m_poison = p_poison;
}

CInsect::~CInsect(){
}

void CInsect::specialAttack(CMonster& p_enemy, CArena& p_arena){
	if (poison())
		p_enemy.setState(Monster::STATE::poisoned);
}

void CInsect::info(){
	CGrass::info();
	std::cout << "Poison : " << m_poison << std::endl;
}

bool CInsect::poison(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	return (l_dist6(l_rng) <= m_poison * 100) ? true : false;
}
