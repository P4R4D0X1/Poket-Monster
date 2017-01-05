#include "player.hpp"

CPlayer::CPlayer(){
}

CPlayer::~CPlayer(){
}	


void CPlayer::chooseMonster(unsigned int p_index){
	m_actualMonster = m_monster.at(p_index);	
}

void CPlayer::attack(unsigned int p_index, CPlayer& p_enemy){
	m_actualMonster->attack(p_index, *(p_enemy.m_actualMonster));
}

void CPlayer::useObject(unsigned int p_index){
	m_actualMonster->useObject(*m_object.at(p_index));
}

void CPlayer::attackListInfo(){
	m_actualMonster->attacksInfo();
}

void CPlayer::objectListInfo(){
	std::vector<CObject*>::iterator l_it;

	for (l_it = m_object.begin(); l_it != m_object.end(); ++l_it){
		std::cout << "\t[ " << std::distance(m_object.begin(), l_it) << " ]\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
}

int CPlayer::getMonsterSpeed(){
	return m_actualMonster->getSpeed();
}