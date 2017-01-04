#include "potion.hpp"
#include "monster.hpp"

CPotion::CPotion(){
	m_heal = 0;
}

CPotion::CPotion(std::string p_name, int p_heal){
	m_name = p_name;
	m_heal = p_heal;
}

CPotion::~CPotion(){
}

void CPotion::usePotion(class CMonster& p_monster){
	p_monster.usePotion(*this);
}

int CPotion::getHeal(){
	return m_heal;
}

Potion::TYPE CPotion::getType(){
	return m_type;
}

void CPotion::setHeal(int p_heal){
	m_heal = p_heal;
}

void CPotion::info(){
	CObject::info();
	std::cout << "Type of potion : " << m_type << std::endl;
	std::cout << "Heal : " << m_heal << std::endl;
}