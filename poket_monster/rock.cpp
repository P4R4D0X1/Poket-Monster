#include "rock.hpp"

CRock::CRock(){
}

CRock::CRock(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_protect) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::rock){
	m_protect = p_protect;
	m_hiddenRound = -1;
}

CRock::~CRock(){
}

void CRock::attack(Monster::ATTACK_SLOT p_attack, CMonster& p_enemy){
	m_hp -= m_attacks[p_attack]->use(*this, p_enemy);
	
	if (hide() && m_hiddenRound == -1){
		std::mt19937 l_rng;
		l_rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 3);

		m_hiddenRound = l_dist6(l_rng);
		m_defense *= 2;
	}
}

Attack::STATE CRock::applyDamage(Attack::TYPE p_attackType, int p_damage){
	if (p_attackType == Attack::TYPE::grass)
		p_damage *= 2;

	m_hp -= p_damage;
	return Attack::STATE::success;
}

bool CRock::hide(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist62(0, 100);

	return (l_dist62(l_rng) <= (unsigned int)m_protect * 100) ? true : false;
}

void CRock::info(){
	CMonster::info();
	std::cout << "Protect : " << m_protect << std::endl;
}