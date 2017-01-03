#include "grass.hpp"

CGrass::CGrass(){
}

CGrass::CGrass(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense) : CMonster(p_name, p_hp, p_speed, p_attack, p_defense, Monster::TYPE::grass){
}

CGrass::~CGrass(){
}