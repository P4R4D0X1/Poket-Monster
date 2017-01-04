#include "grass.hpp"

CGrass::CGrass(){
}

CGrass::CGrass(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::grass){
}

CGrass::~CGrass(){
}

void CGrass::attack(Monster::ATTACK_SLOT p_attack, CMonster&  p_enemy){
}

Attack::STATE CGrass::applyDamage(Attack::TYPE p_attackType, int p_damage){
	if (p_attackType == Attack::TYPE::fire)
		p_damage *= 2;

	m_hp -= p_damage;
	return Attack::STATE::success;
}

void CGrass::info(){
	CMonster::info();
}