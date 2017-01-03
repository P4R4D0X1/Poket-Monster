#include "monster.hpp"
#include "attack.hpp"

CAttack::CAttack(){

}

CAttack::CAttack(std::string p_name, Attack::TYPE p_type, int p_nbUse, int p_power, int p_failProbability){
	m_name = p_name;
	m_type = p_type;
	m_nbUse = p_nbUse;
	m_power = p_power;
	m_failProbability = p_failProbability;
}

CAttack::~CAttack(){
}

int CAttack::use(class CMonster& p_attacker, class CMonster& p_enemy){
	if (m_nbUse <= 0)
		return 0;

	int l_damage;

	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(85, 100);
	std::uniform_int_distribution<std::mt19937::result_type> l_dist62(0, 100);

	l_damage = 11 * p_attacker.getAttack() * m_power;
	l_damage /= p_enemy.getDefense() * 25;
	l_damage += 2;
	l_damage *= (l_dist6(l_rng)/100);

	m_nbUse--;

	//On regarde si l'attaque est reussie ou non
	if (l_dist62(l_rng) <= (unsigned sqint)(m_failProbability * 100))
		return 0;
	
	if (p_enemy.applyDamage(m_type, l_damage) == Attack::STATE::fallen)
		return (int)(l_damage / 4);

	return 0;
}