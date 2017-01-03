#include "insect.hpp"

CInsect::CInsect(){
}

CInsect::CInsect(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense) : CGrass(p_name, p_hp, p_speed, p_attack, p_defense){
}

CInsect::~CInsect(){
}