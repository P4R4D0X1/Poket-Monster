#include "fire.hpp"

//on passera le terrain en paramètre des actions pour qu'un personnage puisse etudier son etat 

CFire::CFire(){
}

CFire::CFire(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense) : CMonster(p_name, p_hp, p_speed, p_attack, p_defense, Monster::TYPE::fire){
}

CFire::~CFire(){
}

void CFire::attack(Monster::ATTACK p_attack, CMonster& const p_enemy){
}

Attack::STATE CFire::applyDamage(Attack::TYPE p_attackType, int p_damage){
		m_hp -= p_damage;
		return Attack::STATE::success;
}

void CFire::fire(CMonster& const p_enemy){
	p_enemy.setState(Monster::STATE::burned);
}