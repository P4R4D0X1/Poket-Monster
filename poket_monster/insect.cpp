#include "insect.hpp"

CInsect::CInsect(){
}

CInsect::CInsect(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_poison) : CGrass(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::insect){
	m_poison = p_poison;
}

CInsect::~CInsect(){
}

void CInsect::attack(unsigned int p_index, CMonster&  p_enemy){
	m_hp -= m_attacks[p_index]->use(*this, p_enemy);

	if (poison() && m_attacks[p_index]->getType() != Attack::TYPE::normal)
		p_enemy.setState(Monster::STATE::poisoned);
}


bool CInsect::poison(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	return (l_dist6(l_rng) <= m_poison * 100) ? true : false;
}

void CInsect::info(){
	CGrass::info();
	std::cout << "Poison : " << m_poison << std::endl;
}