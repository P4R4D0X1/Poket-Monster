#include "potion.hpp"
#include "monster.hpp"

CPotion::CPotion(){
	m_heal = 0;
}

CPotion::CPotion(std::string p_name, int p_heal, Potion::TYPE p_type): CObject(p_name, Object::TYPE::potion){
	m_heal = p_heal;
	m_type = p_type;
}

CPotion::~CPotion(){
}

void CPotion::use(class CMonster& p_monster){
	CObject::use(p_monster);

	p_monster.useObject(*this);
}

int CPotion::getHeal(){
	return m_heal;
}

Potion::TYPE CPotion::getType(){
	return m_type;
}

void CPotion::info(){
	CObject::info();
	std::cout << "Type of potion : " << m_type << std::endl;
	std::cout << "Heal : " << m_heal << std::endl;
}