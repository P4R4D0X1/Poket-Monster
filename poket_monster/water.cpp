#include "water.hpp"

//on passera le terrain en paramètre des actions pour qu'un personnage puisse etudier son etat 

CWater::CWater(){
}

CWater::CWater(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_flood, float p_fall) : CMonster(p_name, p_hp, p_hpMax, p_speed, p_attack, p_defense, Monster::TYPE::water){
	m_flood = p_flood;
	m_fall = p_fall;
}

CWater::~CWater(){
}

void CWater::attack(Monster::ATTACK_SLOT p_attack, CMonster& p_enemy){
	m_hp -= m_attacks[p_attack]->use(*this, p_enemy);
	
	if (flood())
		m_arena->flood();
}

Attack::STATE CWater::applyDamage(Attack::TYPE p_attackType, int p_damage){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	//Si l'attaquant glisse a cause du terrain inondé il se reprend son attaque
	if (m_arena->getState() == Arena::STATE::flooded && l_dist6(l_rng) <= m_fall * 100){
		return Attack::STATE::fallen;
	}
	else{
		//Si c'est un monstre de type electrique il a l'avantage sur le type eau
		if (p_attackType == Attack::TYPE::electric)
			p_damage *= 2;

		m_hp -= p_damage;
		return Attack::STATE::success;
	}
}

bool CWater::flood(){
	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(1, 100);

	return (l_dist6(l_rng) <= m_flood * 100)?true:false;
}