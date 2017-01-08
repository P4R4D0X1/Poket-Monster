#include "monster.hpp"

//CONSTRUCTOR / DESTRUCTOR

CMonster::CMonster(){
}

CMonster::CMonster(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type){
	m_name = p_name;
	m_hp = p_hp;
	m_hpMax = p_hpMax;
	m_speed = p_speed;
	m_attack = p_attack;
	m_defense = p_defense;
	m_type = p_type;
	m_stateLongevity = 0;
}

CMonster::CMonster(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, std::vector<CAttack*>& p_attacks, Monster::TYPE p_type){
	m_name = p_name;
	m_hp = p_hp;
	m_hpMax = p_hpMax;
	m_speed = p_speed;
	m_attack = p_attack;
	m_defense = p_defense;
	m_type = p_type;
	m_stateLongevity = 0;
	m_attacks = p_attacks;
}

CMonster::~CMonster(){
	while (!m_attacks.empty()){
		delete m_attacks.back();
		m_attacks.pop_back();
	}
}

//FUNCTION

unsigned int CMonster::chooseAttack(CMonster& p_enemy, CArena& p_arena){
	std::string l_userInput("");
	unsigned l_choice = -1;

	do{
		attacksInfo();
		std::cout << "[CHOICE] : ";

		std::getline(std::cin, l_userInput);
		l_choice = (unsigned int)std::stoi(l_userInput);
	} while (l_choice > m_attacks.size() || l_choice < 0);

	attack(l_choice, p_enemy, p_arena);
}

Attack::STATE CMonster::attack(unsigned int p_index, CMonster& p_enemy, CArena& p_arena){
	Attack::STATE l_state;

	l_state = m_attacks.at(p_index)->use(*this, p_enemy, p_arena);

	if (m_attacks.at(p_index)->getNbUse() <= 0){
		delete(m_attacks.at(p_index));
		m_attacks.erase(m_attacks.begin() + p_index);
	}
	
	return l_state;
}

void CMonster::applyDamage(unsigned int p_damage){
	m_hp -= p_damage;
}

void CMonster::updateState(CArena& p_arena){
	float l_rescueProb = (6.0f - m_stateLongevity)/6.0f;

	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);


	if (m_state != Monster::STATE::feelgood && m_stateLongevity == 0)
		m_state = Monster::STATE::feelgood;


	switch (m_state){
		case  Monster::STATE::feelgood:
			break;

		case Monster::STATE::poisoned || Monster::STATE::burned:
			if (p_arena.getState() == Arena::STATE::flooded){
				m_state = Monster::STATE::feelgood;
				m_stateLongevity = 0;
			}
			else{
				applyDamage((unsigned int)m_attack / 10);
			}
			break;

		case Monster::STATE::paralized:
			if (l_dist6(l_rng) <= (unsigned int)l_rescueProb * 100){
				m_state = Monster::STATE::feelgood;
				m_stateLongevity = 0;
			}
			else{
				m_stateLongevity--;
			}
			break;

		default:
			break;
	}

	if (m_hp <= 0)
		m_state = Monster::STATE::dead;

	if (!m_attacks.size())
		m_state = Monster::STATE::exhausted;
}

void CMonster::useObject(CObject& p_object){
	switch (p_object.getObjectType()){
		case Object::TYPE::potion:
			usePotion((CPotion&)p_object);
			break;

		case Object::TYPE::drug:
			useDrug((CDrug&)p_object);
			break;
	}
}

bool CMonster::isOperational(){
	return (m_state == Monster::STATE::dead || m_state == Monster::STATE::exhausted) ? false : true;
}

//INFO

void CMonster::info(){
	std::cout << m_name << std::endl;
	std::cout << "Type of monster : ";
	displayMonsterType();
	std::cout << "HP : " << m_hp << "/" << m_hpMax << std::endl;
	std::cout << "Speed : " << m_speed << std::endl;
	std::cout << "Attack : " << m_attack << std::endl;
	std::cout << "Defense : " << m_defense << std::endl;
	std::cout << "State : [" << m_stateLongevity << "] " << m_state << std::endl;
}

void CMonster::attacksInfo(){
	std::vector<CAttack*>::iterator l_it;

	std::cout << "_________[ATTACKS]_________\n";
	for (l_it = m_attacks.begin(); l_it != m_attacks.end(); ++l_it){
		std::cout << "{" << std::distance(m_attacks.begin(), l_it) << "}\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
	std::cout << "___________________________\n";
}

//GETTER / SETTER

int CMonster::getSpeed(){
	return m_speed;
}

int CMonster::getAttack(){
	return m_attack;
}

int CMonster::getDefense(){
	return m_defense;
}

Monster::TYPE CMonster::getType(){
	return m_type;
}

Monster::STATE CMonster::getState(){
	return m_state;
}

void CMonster::setState(Monster::STATE p_state){
	if (p_state == Monster::STATE::paralized)
		m_stateLongevity = 6;
	m_state = p_state;
}

//PROTECTED FUNCTION

void CMonster::usePotion(CPotion& p_potion){
	switch (p_potion.getType()){
	case Potion::TYPE::fullRestore:
		m_hp = m_hpMax;
		m_state = Monster::STATE::feelgood;

		std::cout << "HP and state retored! You used one Full Restore" << std::endl;
		break;

	case Potion::TYPE::maxPotion:
		m_hp = m_hpMax;

		std::cout << "HP restored to the max!You used one Max Potion" << std::endl;
		break;

	case Potion::TYPE::potion || Potion::TYPE::hyperPotion || Potion::TYPE::superPotion:
		m_hp += p_potion.getHeal();

		std::cout << "You used " << p_potion.getName() << "!" << std::endl;
		std::cout << "HP + " << p_potion.getHeal() << std::endl;
		break;

	default:
		break;
	}
}


void CMonster::useDrug(CDrug& p_drug){
	switch (p_drug.getType()){
	case Drug::TYPE::burnHeal:
		if (m_state == Monster::STATE::burned){
			m_state = Monster::STATE::feelgood;
			m_stateLongevity = 0;

			std::cout << "Pokemon not burned any more!" << std::endl;
		}
		break;

	case Drug::TYPE::iceHeal:
		if (m_state == Monster::STATE::freezed){
			m_state = Monster::STATE::feelgood;
			m_stateLongevity = 0;

			std::cout << "Pokemon not freezed any more!" << std::endl;
		}
		break;

	case Drug::TYPE::antidote:
		if (m_state == Monster::STATE::poisoned){
			m_state = Monster::STATE::feelgood;
			m_stateLongevity = 0;

			std::cout << "Pokemon not poisoned any more!" << std::endl;
		}
		break;

	case Drug::TYPE::paralizeHeal:
		if (m_state == Monster::STATE::paralized){
			m_state = Monster::STATE::feelgood;
			m_stateLongevity = 0;

			std::cout << "Pokemon not paralized any more!" << std::endl;
		}
		break;

	case Drug::TYPE::awakening:
		if (m_state == Monster::STATE::asleep){
			m_state = Monster::STATE::feelgood;
			m_stateLongevity = 0;

			std::cout << "Pokemon not asleep any more!" << std::endl;
		}
		break;

	default:
		break;

	}

	std::cout << "You used one" << p_drug.getName() << "!" << std::endl;
}

void CMonster::displayMonsterType(){
	switch (m_type){
		case Monster::TYPE::electric:
			std::cout << "Electric" << std::endl;
			break;

		case Monster::TYPE::water:
			std::cout << "Water" << std::endl;
			break;

		case Monster::TYPE::fire:
			std::cout << "Fire" << std::endl;
			break;

		case Monster::TYPE::insect:
			std::cout << "Insect" << std::endl;
			break;

		case Monster::TYPE::plant:
			std::cout << "Plant" << std::endl;
			break;

		case Monster::TYPE::rock:
			std::cout << "Rock" << std::endl;

		default:
			std::cerr << "ERROR DISPLAYING MONSTER TYPE" << std::endl;
			break;
	}
}