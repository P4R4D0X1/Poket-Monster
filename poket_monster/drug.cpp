#include "drug.hpp"
#include "monster.hpp"

CDrug::CDrug(){
}

CDrug::CDrug(std::string p_name, Drug::TYPE p_type) : CObject(p_name, Object::TYPE::drug){
	m_type = p_type;
}

CDrug::~CDrug(){
}

Drug::TYPE CDrug::getType(){
	return m_type;
}

void CDrug::use(class CMonster& p_monster){
	CObject::use(p_monster);

	p_monster.useObject(*this);
}

void CDrug::info(){
	CObject::info();
	std::cout << "Type of drug : " << m_type << std::endl;
}