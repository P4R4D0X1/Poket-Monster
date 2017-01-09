#include "player.hpp"

//CONSTRUCTOR / DESTRUCTOR

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

//FUNCTION

void CPlayer::chooseAction(CPlayer& p_enemy, CArena& p_arena){
	std::string l_userInput("");
	std::vector<CMonster*>::iterator l_it;
	int l_choice = -1;

	//Si le monstre n'est plus operationel on le supprime
	if (m_actualMonster){
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
	m_actualMonster->updateState(p_arena);
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

	m_actualMonster = m_monsters.at(l_choice);
}

void CPlayer::chooseAttack(CPlayer& p_enemy, CArena& p_arena){
	m_actualMonster->chooseAttack(*(p_enemy.m_actualMonster), p_arena);
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

	m_actualMonster->useObject(*(m_objects.at(l_choice)));
}

//INFO 

void CPlayer::actionsListInfo(){
	std::cout << "_________[ACTIONS]_________\n";

	if (m_monsters.size())
		std::cout << "{" << Player::ACTION::chooseMonster << "}MONSTERS  ";

	if (m_actualMonster && m_actualMonster->isOperational())
		std::cout << "{" << Player::ACTION::attack << "}ATTACK  ";

	if (m_actualMonster && m_objects.size())
		std::cout << "{" << Player::ACTION::useObject << "}OBJECTS  ";

	std::cout << "\n_________________________\n" << std::endl;
}

void CPlayer::monstersListInfo(){
	std::vector<CMonster*>::iterator l_it;

	std::cout << "_________[MONSTERS]_________\n";
	for (l_it = m_monsters.begin(); l_it != m_monsters.end(); ++l_it){
		std::cout << "{" << std::distance(m_monsters.begin(), l_it) << "}\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
	std::cout << "____________________________\n";
}

void CPlayer::objectListInfo(){
	std::vector<CObject*>::iterator l_it;

	std::cout << "_________[OJECTS]_________\n";
	for (l_it = m_objects.begin(); l_it != m_objects.end(); ++l_it){
		std::cout << "{" << std::distance(m_objects.begin(), l_it) << "}\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
	std::cout << "__________________________\n";
}

//GETTER / SETTER

int CPlayer::getMonsterSpeed(){
	return m_actualMonster->getSpeed();
}