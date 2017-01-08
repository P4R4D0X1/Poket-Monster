#include "electric.hpp"
#include "attack.hpp"

CElectric::CElectric(){
}

CElectric::CElectric(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_paralysis) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::electric){
	m_paralysis = p_paralysis;
}

CElectric::CElectric(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_paralysis, std::vector<CAttack*>& p_attacks) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_attacks, Monster::TYPE::electric){
	m_paralysis = p_paralysis;
}

CElectric::~CElectric(){
}

void CElectric::specialAttack(CMonster& p_enemy, CArena& p_arena){
	if (paralyze())
		p_enemy.setState(Monster::STATE::paralized);
}

void CElectric::info(){
	CMonster::info();
	std::cout << "Paralysis : " << m_paralysis << std::endl;
}

bool CElectric::paralyze(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	return (l_dist6(l_rng) <= m_paralysis * 100) ? true : false;
}
