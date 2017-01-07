#include "rock.hpp"

CRock::CRock(){
}

CRock::CRock(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_protect) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::rock){
	m_protect = p_protect;
	m_hiddenRound = -1;
}

CRock::CRock(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_protect, std::vector<CAttack*>& p_attacks) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_attacks, Monster::TYPE::rock){
}

CRock::~CRock(){
}

void CRock::specialAttack(CMonster& p_enemy, CArena& p_arena){
	hide();
}

bool CRock::hide(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(0, 100);
	std::uniform_int_distribution<std::mt19937::result_type> l_dist62(1, 3);

	if (m_hiddenRound == 0 && l_dist6(l_rng) <= (unsigned int)m_protect * 100){
		m_hiddenRound = l_dist6(l_rng);
		m_defense *= 2;
		return true;
	}
	
	return false;
}

void CRock::info(){
	CMonster::info();
	std::cout << "Protect : " << m_protect << std::endl;
}