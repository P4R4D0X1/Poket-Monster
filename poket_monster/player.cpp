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

void CPlayer::chooseAction(CPlayer& p_enemy, CArena& p_arena){
	std::string l_userInput("");
	int l_choice = -1;


	
	do{
		std::cout << "_________[ACTION]_________\n";

		if (m_monsters.size())
			std::cout << "{" << Player::ACTION::chooseMonster << "}MONSTERS  ";

		if (m_actualMonster && m_actualMonster->isOperational())
			std::cout << "{" << Player::ACTION::attack << "}ATTACK  ";

		if (m_actualMonster && m_objects.size())
			std::cout << "{" << Player::ACTION::useObject << "}OBJECTS  ";

		std::cout << "\n________________________\n" << std::endl;
		std::cout << "[CHOICE] : ";

		std::getline(std::cin, l_userInput);
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
			//Afficher la liste de monstres puis permettre le changement
			break;

		case Player::ACTION::attack:
			//Afficher la liste d'attaque du monstre actuel puis choisir l'attaque
			break;

		case Player::ACTION::useObject:
			//Afficher la liste d'objet et permettre l'utilisation sur le monstre actuel
			break;

		default:
			break;
	}
	//Mettre a jour le monstre
	//Si le monstre n'est plus operationel on le supprime
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

	std::cout << "_________[OJECTS]_________\n";
	for (l_it = m_objects.begin(); l_it != m_objects.end(); ++l_it){
		std::cout << "{" << std::distance(m_objects.begin(), l_it) << "}\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
	std::cout << "__________________________\n";
}

int CPlayer::getMonsterSpeed(){
	return m_actualMonster->getSpeed();
}