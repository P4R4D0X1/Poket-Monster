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