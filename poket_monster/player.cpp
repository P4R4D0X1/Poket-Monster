#include "player.hpp"

CPlayer::CPlayer(){
}

CPlayer::~CPlayer(){
}	


void CPlayer::chooseMonster(unsigned int p_index){
	m_actualMonster = m_monster.at(p_index);
}

void CPlayer::attack(unsigned int p_index, CPlayer& p_enemy){
	//** TO DO **//
	//Faut faire une fonction dans player pour choisir l'attaque du monstre
	//En attendant on met la première attaque par defaut
	m_actualMonster->attack(Monster::ATTACK_SLOT::first, *(p_enemy.m_actualMonster));
}