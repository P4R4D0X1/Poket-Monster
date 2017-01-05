#include "grass.hpp"

CGrass::CGrass(){
}

CGrass::CGrass(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_type){
}

CGrass::~CGrass(){
}

void CGrass::attack(unsigned int p_index, CMonster&  p_enemy){
}

Attack::STATE CGrass::applyDamage(Attack::TYPE p_attackType, int p_damage){
	m_hp -= p_damage;
	return Attack::STATE::success;
}

void CGrass::updateState(){
	if (m_arena->getState() == Arena::STATE::flooded)
		m_hp += (int)m_hpMax / 20;
	
	CMonster::updateState();
}

void CGrass::info(){
	CMonster::info();
}

