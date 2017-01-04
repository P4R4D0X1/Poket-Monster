#include "monster.hpp"

CMonster::CMonster(){
}

CMonster::CMonster(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type){
	m_name = p_name;
	m_hp = p_hp;
	m_hpMax = p_hpMax;
	m_speed = p_speed;
	m_attack = p_attack;
	m_defense = p_defense;
	m_type = p_type;
	m_paralyzedTour = 0;
	m_arena = NULL;
}


CMonster::~CMonster(){
}

void CMonster::attack(Monster::ATTACK_SLOT p_attack, CMonster& p_enemy){
	m_hp -= m_attacks[p_attack]->use(*this, p_enemy);
}

Attack::STATE CMonster::applyDamage(Attack::TYPE p_attackType, int p_damage){
}

void CMonster::updateState(){
	
}

int CMonster::getAttack(){
	return m_attack;
}

int CMonster::getDefense(){
	return m_defense;
}

Monster::STATE CMonster::getState(){
	return m_state;
}

void CMonster::setState(Monster::STATE p_state){
	if (p_state == Monster::STATE::paralized)
		m_paralyzedTour = 6;
	m_state = p_state;
}

void CMonster::setArena(CArena& p_arena){
	m_arena = &p_arena;
}