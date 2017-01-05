#include "monster.hpp"

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
	m_arena = NULL;
}


CMonster::~CMonster(){
}

void CMonster::attack(unsigned int p_index, CMonster& p_enemy){
	m_hp -= m_attacks[p_index]->use(*this, p_enemy);
}

Attack::STATE CMonster::applyDamage(Attack::TYPE p_attackType, int p_damage){
	return Attack::STATE::success;
}

void CMonster::updateState(){
	float l_rescueProb = (6.0f - m_stateLongevity)/6.0f;

	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);


	if (m_stateLongevity == 0){
		m_state = Monster::STATE::feelgood;
		m_arena->updateState();
		return;
	}

	switch (m_state){
		case  Monster::STATE::feelgood:
			break;

		case Monster::STATE::poisoned:
			if (m_arena->getState() == Arena::STATE::flooded){
				m_stateLongevity = 0;
				m_state = Monster::STATE::feelgood;
			}
			else{
				m_hp -= (int)m_attack / 10;
				m_stateLongevity--;
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

		case Monster::STATE::burned:
			if (m_arena->getState() == Arena::STATE::flooded){
				m_stateLongevity = 0;
				m_state = Monster::STATE::feelgood;
			}
			else{
				m_hp -= (int)m_attack / 10;
				m_stateLongevity--;
			}
			break;

		default:
			break;
	}

	m_arena->updateState();
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

bool CMonster::isAlive(){
	return (m_hp <= 0) ? false : true;
}

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

void CMonster::setArena(CArena& p_arena){
	m_arena = &p_arena;
}

void CMonster::info(){
	std::cout << m_name << std::endl;
	std::cout << "Type of monster : " << m_type << std::endl;
	std::cout << "HP : " << m_hp << "/" << m_hpMax << std::endl;
	std::cout << "Speed : " << m_speed << std::endl;
	std::cout << "Attack : " << m_attack << std::endl;
	std::cout << "Defense : " << m_defense << std::endl;
}

void CMonster::attacksInfo(){
	std::vector<CAttack*>::iterator l_it;

	for (l_it = m_attacks.begin(); l_it != m_attacks.end(); ++l_it){
		std::cout << "\t[ " << std::distance(m_attacks.begin(), l_it) << " ]\n";
		(*l_it)->info();
		std::cout << std::endl;
	}
}

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
