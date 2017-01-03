#include "rock.hpp"

CRock::CRock(){
}

CRock::CRock(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense) : CMonster(p_name, p_hp, p_speed, p_attack, p_defense, Monster::TYPE::rock){
}

CRock::~CRock(){
}

void CRock::hide(){
}