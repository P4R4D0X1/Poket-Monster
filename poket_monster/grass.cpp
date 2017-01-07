#include "grass.hpp"

CGrass::CGrass(){
}

CGrass::CGrass(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_type){
}

CGrass::CGrass(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, std::vector<CAttack*>& p_attacks, Monster::TYPE p_type) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_attacks, p_type){
}

CGrass::~CGrass(){
}

void CGrass::specialAttack(CMonster& p_enemy, CArena& p_arena){
}

void CGrass::updateState(CArena& p_arena){
	if (p_arena.getState() == Arena::STATE::flooded)
		m_hp += (int)m_hpMax / 20;
	
	CMonster::updateState(p_arena);
}

void CGrass::info(){
	CMonster::info();
}

