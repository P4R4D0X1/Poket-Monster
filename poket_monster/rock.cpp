#include "rock.hpp"

CRock::CRock(){
}

CRock::CRock(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::rock){
	m_hiddenRound = -1;
}

CRock::~CRock(){
}

void CRock::attack(Monster::ATTACK_SLOT p_attack, CMonster& p_enemy){
	m_hp -= m_attacks[p_attack]->use(*this, p_enemy);
}

Attack::STATE CRock::applyDamage(Attack::TYPE p_attackType, int p_damage){
	if (p_attackType == Attack::TYPE::grass)
		p_damage *= 2;

	m_hp -= p_damage;
	return Attack::STATE::success;
}

void CRock::hide(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 3);

	m_hiddenRound = l_dist6(l_rng);
	m_defense *= 2;
}