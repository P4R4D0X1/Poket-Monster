#include "electric.hpp"

CElectric::CElectric(){
}

CElectric::CElectric(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense) : CMonster(p_name, p_hp, p_speed, p_attack, p_defense, Monster::TYPE::electric){
}

CElectric::CElectric(){
}

bool CElectric::paralyze(){
	return true;
}