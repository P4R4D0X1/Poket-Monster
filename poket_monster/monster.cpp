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

void CMonster::attack(Monster::ATTACK_SLOT p_attack, CMonster& p_enemy){
	m_hp -= m_attacks[p_attack]->use(*this, p_enemy);
}

Attack::STATE CMonster::applyDamage(Attack::TYPE p_attackType, int p_damage){
}

void CMonster::updateState(){
	float l_rescueProb = (6.0f - m_stateLongevity)/6.0f;

	if (m_type == Monster::TYPE::grass && m_arena->getState() == Arena::STATE::flooded){
		m_hp += (int)m_hpMax / 20;
	}

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
				m_state == Monster::STATE::feelgood;
			}
			else{
				m_hp -= (int)m_attack / 10;
				m_stateLongevity--;
			}
			break;

		case Monster::STATE::paralized:
			std::mt19937 l_rng;
			l_rng.seed(std::random_device()());
			std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

			if (l_dist6(l_rng) <= (int)l_rescueProb * 100){
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
				m_state == Monster::STATE::feelgood;
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

void CMonster::usePotion(CPotion& p_potion){
	if (p_potion.getType() == Potion::TYPE::fullRestore){
		//Redonner tous les pv au pokémon et soigner l'état
		m_hp = m_hpMax;
		m_state = Monster::STATE::feelgood;
		std::cout << "HP and state retored! You used one Full Restore" << std::endl;
	}
	else if (p_potion.getType() == Potion::TYPE::maxPotion){
		//Redonner tous les PVs au pokémon
		m_hp = m_hpMax;
		std::cout << "HP restored to the max!You used one Max Potion" << std::endl;

	}
	else if (p_potion.getType() == Potion::TYPE::potion || p_potion.getType() == Potion::TYPE::hyperPotion || p_potion.getType() == Potion::TYPE::superPotion){
		//Recuperer m_heal et l'ajouter au PV du pokémon
		m_hp += p_potion.getHeal();
		std::cout << "You used " << p_potion.getName() << "!" << std::endl;
		std::cout << "HP + " << p_potion.getHeal() << std::endl;
	}
}


void CMonster::useDrug(CDrug& p_drug){

	if (p_drug.getType() == Drug::TYPE::burnHeal){
		if (m_state == Monster::STATE::burned){
			m_state = Monster::STATE::feelgood;
			std::cout << "Pokemon not burned any more!" << std::endl;
		}
	}
	else if (p_drug.getType() == Drug::TYPE::iceHeal){
		if (m_state == Monster::STATE::freezed){
			m_state = Monster::STATE::feelgood;
			std::cout << "Pokemon not freezed any more!" << std::endl;
		}
	}
	else if (p_drug.getType() == Drug::TYPE::antidote){
		if (m_state == Monster::STATE::poisoned){
			m_state = Monster::STATE::feelgood;
		std::cout << "Pokemon not poisoned any more!" << std::endl;
		}
	}
	else if (m_name == "Paralyse Heal"){
		if (m_state == Monster::STATE::paralized){
			m_state = Monster::STATE::feelgood;
		std::cout << "Pokemon not paralyzed any more!" << std::endl;
		}
	}
	else if (m_name == "Awakening"){
		if (m_state == Monster::STATE::asleep){
			m_state = Monster::STATE::feelgood;
		std::cout << "Pokemon not asleep any more!" << std::endl;
		}
	}
	std::cout << "You used one" << p_drug.getName() << "!" << std::endl;
}


int CMonster::getAttack(){
	return m_attack;
}

int CMonster::getDefense(){
	return m_defense;
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