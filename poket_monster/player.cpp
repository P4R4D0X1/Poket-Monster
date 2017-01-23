#include "player.hpp"

//CONSTRUCTOR / DESTRUCTOR

CPlayer::CPlayer(){
}

CPlayer::CPlayer(std::string p_name, std::vector<CMonster*>& p_monsters, std::vector<CObject*>& p_objects){
	m_name = p_name;
	m_monsters = p_monsters;
	m_monster = m_monsters.begin();
	m_objects = p_objects;
	m_object = m_objects.begin();
	m_menu = Menu::monster;
	updateActionMenu();
}

CPlayer::~CPlayer(){
}	

//GRAPHX DEV

bool CPlayer::showMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	bool l_tourDone(false);

	switch (m_menu){
		case Menu::action:
			showActionMenu(p_enemy, p_arena, p_ui);
			break;
		
		case Menu::monster:
			l_tourDone = showMonsterMenu(p_enemy, p_arena, p_ui);
			break;

		case Menu::attack:
			l_tourDone = showAttackMenu(p_enemy, p_arena, p_ui);
			break;

		case Menu::object:
			l_tourDone = showObjectMenu(p_enemy, p_arena, p_ui);
			break;
	}

	if (l_tourDone){
		m_menu = Menu::action;

		p_enemy.updateMonsters(p_arena);
		p_arena.updateState();
		updateActionMenu();
	}

	return l_tourDone;
}

void CPlayer::updateActionMenu(){
	m_actions.clear();

	if (m_monsters.size()){
		std::pair<std::string, Menu::TYPE> pairMonster("MONSTER", Menu::TYPE::monster);
		m_actions.insert(pairMonster);
	}

	if (m_monsters.size() && m_monster != m_monsters.end()){
		std::pair<std::string, Menu::TYPE> pairAttack("ATTACK", Menu::TYPE::attack);
		m_actions.insert(pairAttack);
	}

	if (m_objects.size() && m_monster != m_monsters.end()){
		std::pair<std::string, Menu::TYPE> pairObject("OBJECT", Menu::TYPE::object);
		m_actions.insert(pairObject);
	}

	if (m_monsters.size() && m_monster == m_monsters.end()){
		m_menu = Menu::monster;
		m_monster = m_monsters.begin();
	}

	m_action = m_actions.begin();
}

void CPlayer::showActionMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	if (p_ui.displayMenuAction(m_actions, m_action)){
		m_menu = m_action->second;
	}
}

bool CPlayer::showMonsterMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	if (p_ui.displayMenuMonster(m_monsters, m_monster))
		return true;
	else
		return false;
}

bool CPlayer::showAttackMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	if ((*m_monster)->showAttackMenu(**(p_enemy.m_monster), p_arena, p_ui))
		return true;
	else
		return false;
}

void CPlayer::updateObjectMenu(){
}

bool CPlayer::showObjectMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	return true;
}

//FUNCTION

void CPlayer::updateMonsters(CArena& p_arena){
	std::vector<CMonster*>::iterator l_it;
	
	//Si le monstre n'est plus operationel on le supprime
	if (m_monster != m_monsters.end()){
		(*m_monster)->updateState(p_arena);
		
		if (!(*m_monster)->isOperational()){
			delete(*m_monster);
			m_monsters.erase(m_monster);
			m_monster = m_monsters.end();
		}
	}
}

//GETTER / SETTER

int CPlayer::getMonsterSpeed(){
	//return m_actualMonster->getSpeed();
	return 1;
}