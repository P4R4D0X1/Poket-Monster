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
			return showMonsterMenu(p_enemy, p_arena, p_ui);
			break;

		case Menu::attack:
			//(*m_monster)->showAttackMenu(p_enemy, p_arena, p_ui);
			break;

		case Menu::object:
			return showObjectMenu(p_enemy, p_arena, p_ui);
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

	if (m_monster != m_monsters.end() && m_objects.size()){
		std::pair<std::string, Menu::TYPE> pairObject("ATTACK", Menu::TYPE::object);
		m_actions.insert(pairObject);
	}

	m_action = m_actions.begin();
}

void CPlayer::showActionMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	if (p_ui.displayMenuAction(m_actions, m_action)){
		m_menu = m_action->second;
		updateActionMenu();
	}
}

bool CPlayer::showMonsterMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	if (p_ui.displayMenuMonster(m_monsters, m_monster)){
		return true;
	}

	return false;
}

void CPlayer::updateObjectMenu(){
}

bool CPlayer::showObjectMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui){
	return true;
}

//FUNCTION

void CPlayer::chooseAction(CPlayer& p_enemy, CArena& p_arena){
	/*
	std::string l_userInput("");
	int l_choice = -1;

	do{
		do{
			actionsListInfo();
			std::cout << "[CHOICE] : ";
			std::getline(std::cin, l_userInput);
		} while (l_userInput.empty());
		l_choice = std::stoi(l_userInput);

		switch ((Player::ACTION)l_choice){
			case Player::ACTION::chooseMonster:
				if (!m_monsters.size())
					l_choice = -1;
				break;

			case Player::ACTION::attack:
				if (!m_actualMonster || !m_actualMonster->isOperational())
					l_choice = -1;
				break;

			case Player::ACTION::useObject:
				if (!m_actualMonster || !m_objects.size())
					l_choice = -1;
				break;

			default:
				l_choice = -1;
				break;
		}

	} while (l_choice == -1);

	action((Player::ACTION)l_choice, p_enemy, p_arena);
	*/
}

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
	//m_actualMonster->updateState(p_arena);
	p_enemy.updateMonsters(p_arena);
	p_arena.updateState();
}

void CPlayer::chooseMonster(){
	std::string l_userInput("");
	unsigned l_choice = -1;

	do{
		do{
			monstersListInfo();
			std::cout << "[CHOICE] : ";
			std::getline(std::cin, l_userInput);
		} while (l_userInput.empty());
		l_choice = (unsigned int)std::stoi(l_userInput);

	} while (l_choice > m_monsters.size() || l_choice < 0);

	//m_actualMonster = m_monsters.at(l_choice);
}

void CPlayer::chooseAttack(CPlayer& p_enemy, CArena& p_arena){
	//m_actualMonster->chooseAttack(*(p_enemy.m_actualMonster), p_arena);
}

void CPlayer::chooseObject(){
	std::string l_userInput("");
	unsigned l_choice = -1;

	do{
		do{
			objectListInfo();
			std::cout << "[CHOICE] : ";
			std::getline(std::cin, l_userInput);
		} while (l_userInput.empty());
		l_choice = (unsigned int)std::stoi(l_userInput);

	} while (l_choice > m_objects.size() || l_choice < 0);

	//m_actualMonster->useObject(*(m_objects.at(l_choice)));
}

void CPlayer::updateMonsters(CArena& p_arena){
	std::vector<CMonster*>::iterator l_it;
	/*
	//Si le monstre n'est plus operationel on le supprime
	if (m_actualMonster){
		m_actualMonster->updateState(p_arena);
		if (!m_actualMonster->isOperational()){
			for (l_it = m_monsters.begin(); l_it != m_monsters.end();) {
				if ((*l_it) == m_actualMonster) {
					delete(*l_it);
					l_it = m_monsters.erase(l_it);
				}
				else {
					++l_it;
				}
			}
			m_actualMonster = NULL;
		}
		else{
			m_actualMonster->info();
		}
	}
	*/
}

//INFO 

void CPlayer::actionsListInfo(){
	/*
	std::cout << "_________[ACTIONS]_________\n";

	if (m_monsters.size())
		std::cout << "{" << Player::ACTION::chooseMonster << "}MONSTERS  ";

	if (m_actualMonster && m_actualMonster->isOperational())
		std::cout << "{" << Player::ACTION::attack << "}ATTACK  ";

	if (m_actualMonster && m_objects.size())
		std::cout << "{" << Player::ACTION::useObject << "}OBJECTS  ";

	std::cout << "\n_________________________\n" << std::endl;
	*/
}

void CPlayer::monstersListInfo(){
	/*
	std::vector<CMonster*>::iterator l_it;

	std::cout << "_________[MONSTERS]_________\n";
	for (l_it = m_monsters.begin(); l_it != m_monsters.end(); ++l_it){
		std::cout << "{" << std::distance(m_monsters.begin(), l_it) << "}\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
	std::cout << "____________________________\n";
	*/
}

void CPlayer::objectListInfo(){
	/*
	std::vector<CObject*>::iterator l_it;

	std::cout << "_________[OJECTS]_________\n";
	for (l_it = m_objects.begin(); l_it != m_objects.end(); ++l_it){
		std::cout << "{" << std::distance(m_objects.begin(), l_it) << "}\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
	std::cout << "__________________________\n";
	*/
}

//GETTER / SETTER

int CPlayer::getMonsterSpeed(){
	//return m_actualMonster->getSpeed();
	return 1;
}