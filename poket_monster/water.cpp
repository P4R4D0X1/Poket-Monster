#include "water.hpp"

CWater::CWater(){
}

CWater::CWater(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_flood, float p_fall) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::water){
	m_flood = p_flood;
	m_fall = p_fall;
}

CWater::CWater(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_flood, float p_fall, std::vector<CAttack*>& p_attacks) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_attacks, Monster::TYPE::water){
	m_flood = p_flood;
	m_fall = p_fall;
}

CWater::~CWater(){
}

void CWater::specialAttack(CMonster& p_enemy, CArena& p_arena){
	if (flood())
		p_arena.flood(m_fall);
}

bool CWater::flood(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	return (l_dist6(l_rng) <= m_flood * 100)?true:false;
}

void CWater::info(){
	CMonster::info();
	std::cout << "Flood : " << m_flood << std::endl;
	std::cout << "Fall : " << m_fall << std::endl;
}