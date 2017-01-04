#include "electric.hpp"
#include "attack.hpp"

CElectric::CElectric(){
}

CElectric::CElectric(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_paralysis) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::electric){
	m_paralysis = p_paralysis;
}

CElectric::~CElectric(){
}

void CElectric::attack(Monster::ATTACK_SLOT p_attack, CMonster& p_enemy){
	m_hp -= m_attacks[p_attack]->use(*this, p_enemy);

	if (paralyze() && m_attacks[p_attack]->getType() != Attack::TYPE::normal)
		p_enemy.setState(Monster::STATE::paralized);
}

Attack::STATE CElectric::applyDamage(Attack::TYPE p_attackType, int p_damage){
	if (p_attackType == Attack::TYPE::rock)
		p_damage *= 2;

	m_hp -= p_damage;
	return Attack::STATE::success;
}

bool CElectric::paralyze(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);
	
	return (l_dist6(l_rng) <= m_paralysis * 100) ? true : false;
}