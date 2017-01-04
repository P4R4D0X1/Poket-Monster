#include "drug.hpp"
#include "monster.hpp"

CDrug::CDrug(){
}

CDrug::CDrug(std::string p_name){
	m_name = p_name;
}

CDrug::~CDrug(){
}

Drug::TYPE CDrug::getType(){
	return m_type;
}

void CDrug::useDrug(class CMonster& p_monster){
	p_monster.useDrug(*this);
}