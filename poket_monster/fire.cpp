#include "fire.hpp"

//on passera le terrain en paramètre des actions pour qu'un personnage puisse etudier son etat 

CFire::CFire(){
}

CFire::CFire(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_burn) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::fire){
	m_burn = p_burn;
}

CFire::CFire(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_burn, std::vector<CAttack*>& p_attacks) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, p_attacks, Monster::TYPE::fire){
	m_burn = p_burn;
}

CFire::~CFire(){	
}

void CFire::specialAttack(CMonster& p_enemy, CArena& p_arena){
	if (fire())
		p_enemy.setState(Monster::STATE::burned);
}

void CFire::info(){
	CMonster::info();
	std::cout << "Burn : " << m_burn << std::endl;
}

bool CFire::fire(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	return (l_dist6(l_rng) <= m_burn * 100) ? true : false;
}