#include "drug.hpp"

CDrug::CDrug(){
}

CDrug::CDrug(std::string p_name){
	m_name = p_name;
}

Drug::TYPE CDrug::getType(){
	return m_type;
}

void CDrug::useDrug(CMonster &p_monster){
	//p_monster.useDrug(*this);
}