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
	switch (m_menu){
		case Menu::action:
			showActionMenu(p_enemy, p_arena, p_ui);
			break;
		
		case Menu::monster:
			if (showMonsterMenu(p_enemy, p_arena, p_ui)){
				m_menu = Menu::action;
				updateActionMenu();
				return true;
			}
			break;

		case Menu::attack:
			//(*m_monster)->showAttackMenu(p_enemy, p_arena, p_ui);
			break;

		case Menu::object:
			if (showObjectMenu(p_enemy, p_arena, p_ui)){
				m_menu = Menu::action;
				updateActionMenu();
				return true;
			}
			break;
	}

	return false;
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
	if((*m_monster)->showAttackMenu(**(p_enemy.m_monster), p_arena, p_ui)){
	}
}

void CPlayer::updateObjectMenu(){
}

bool CPlayer::showObjectMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	return true;
}

//FUNCTION



void CPlayer::action(Player::ACTION p_action, CPlayer& p_enemy, CArena& p_arena){

	switch (p_action){
		case Player::ACTION::chooseMonster:
			chooseMonster();
			break;

		case Player::ACTION::attack:
			//Afficher la liste d'attaque du monstre actuel puis choisir l'attaque
			chooseAttack(p_enemy, p_arena);
			break;

		case Player::ACTION::useObject:
			//Afficher la liste d'objet et permettre l'utilisation sur le monstre actuel
			chooseObject();
			break;

		default:
			break;
	}

	//Mettre a jour le monstre et l'arène
	p_enemy.updateMonsters(p_arena);
	p_arena.updateState();
}

void CPlayer::chooseAttack(CPlayer& p_enemy, CArena& p_arena){
	//m_actualMonster->chooseAttack(*(p_enemy.m_actualMonster), p_arena);
}

void CPlayer::updateMonsters(CArena& p_arena){
	std::vector<CMonster*>::iterator l_it;
	
	//Si le monstre n'est plus operationel on le supprime
	if (m_monster != m_monsters.end()){
		(*m_monster)->updateState(p_arena);
		if (!(*m_monster)->isOperational()){
			for (l_it = m_monsters.begin(); l_it != m_monsters.end();) {
				if (l_it == m_monster) {
					delete(*l_it);
					l_it = m_monsters.erase(l_it);
				}
				else {
					++l_it;
				}
			}
			m_monster = m_monsters.end();
		}
	}
}

//GETTER / SETTER

int CPlayer::getMonsterSpeed(){
	//return m_actualMonster->getSpeed();
	return 1;
}