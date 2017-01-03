#include "plant.hpp"

CPlant::CPlant(){
}

CPlant::CPlant(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense) : CGrass(p_name, p_hp, p_speed, p_attack, p_defense){
}

CPlant::~CPlant(){
}