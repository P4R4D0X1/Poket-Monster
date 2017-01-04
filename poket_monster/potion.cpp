#include "potion.hpp"

CPotion::CPotion(){
	m_heal = 0;
}

CPotion::CPotion(int p_heal){
	m_heal = p_heal;
}

void CPotion::setHeal(int p_heal){
	m_heal = p_heal;
}

int CPotion::getHeal(){
	return m_heal;
}

Potion::TYPE CPotion::getType(){
	return m_type;
}

void CPotion::usePotion(CMonster &p_monster){
	p_monster.usePotion(*this);
}