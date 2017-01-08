#include "player.hpp"

CPlayer::CPlayer(){
}

CPlayer::CPlayer(std::string p_name, std::vector<CMonster*>& p_monsters, std::vector<CObject*>& p_objects){
	m_name = p_name;
	m_actualMonster = NULL;
	m_monsters = p_monsters;
	m_objects = p_objects;
}

CPlayer::~CPlayer(){
}	


void CPlayer::chooseMonster(unsigned int p_index){
	m_actualMonster = m_monsters.at(p_index);	
}

Attack::STATE CPlayer::attack(unsigned int p_index, CPlayer& p_enemy, CArena& p_arena){
	return m_actualMonster->attack(p_index, *p_enemy.m_actualMonster, p_arena);
}

void CPlayer::useObject(unsigned int p_index){
	m_actualMonster->useObject(*m_objects.at(p_index));
}

void CPlayer::attackListInfo(){
	m_actualMonster->attacksInfo();
}

void CPlayer::objectListInfo(){
	std::vector<CObject*>::iterator l_it;

	for (l_it = m_objects.begin(); l_it != m_objects.end(); ++l_it){
		std::cout << "\t[ " << std::distance(m_objects.begin(), l_it) << " ]\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
}

int CPlayer::getMonsterSpeed(){
	return m_actualMonster->getSpeed();
}