#include "monster.hpp"

CMonster::CMonster(){
}

CMonster::~CMonster(){
}

void CMonster::attack(Monster::ATTACK p_attack, CMonster& const p_enemy){

}

Attack::STATE CMonster::applyDamage(Attack::TYPE p_attackType, int p_damage){

}

void CMonster::setState(Monster::STATE p_state){
	m_state = p_state;
}

void CMonster::updateState(){
	//Et la du coup si c'est inondé on lodifie l'etat du monstre en fonction de sa reaction à la flotte 
}