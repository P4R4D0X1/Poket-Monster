#include "monster.hpp"
#include "attack.hpp"

CAttack::CAttack(){

}

CAttack::CAttack(std::string p_name, Attack::TYPE p_type, int p_nbUse, int p_power, float p_failProbability){
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

	l_damage *= computeAttackCoef(p_attacker.getType(), p_enemy.getType());
	m_nbUse--;

	//On regarde si l'attaque est reussie ou non
	if (p_attacker.getState() == Monster::STATE::paralized){
		//Si le joueur est paralysé il a une chance sur quatre de rater son attaque
		if (l_dist62(l_rng) <= 25)
			return 0;
	}
	else if (l_dist62(l_rng) <= (unsigned int)(m_failProbability * 100))
		return 0;
	
	//Si le joueur tombe parceque le terrain est inondé il se prend un quart de son attaque 
	if (p_enemy.applyDamage(m_type, l_damage) == Attack::STATE::fallen)
		return (int)(p_attacker.getAttack() / 4);

	return 0;
}

float CAttack::computeAttackCoef(Monster::TYPE p_attacker, Monster::TYPE p_enemy){
	//WATER vs FIRE
	if (p_attacker == Monster::TYPE::water && p_enemy == Monster::TYPE::fire)
		return 2.f;
	if (p_attacker == Monster::TYPE::fire && p_enemy == Monster::TYPE::water)
		return 0.5f;

	//FIRE vs GRASS
	if (p_attacker == Monster::TYPE::fire && (p_enemy == Monster::TYPE::plant || p_enemy == Monster::TYPE::insect))
		return 2.f;
	if ((p_enemy == Monster::TYPE::plant || p_enemy == Monster::TYPE::insect) && p_enemy == Monster::TYPE::fire)
		return 0.5f;

	//GRASS vs ROCK
	if ((p_enemy == Monster::TYPE::plant || p_enemy == Monster::TYPE::insect) && p_enemy == Monster::TYPE::rock)
		return 2.f;
	if (p_attacker == Monster::TYPE::rock && (p_enemy == Monster::TYPE::plant || p_enemy == Monster::TYPE::insect))
		return 0.5f;

	//ROCK vs ELECTRIC
	if (p_attacker == Monster::TYPE::rock && p_enemy == Monster::TYPE::electric)
		return 2.f;
	if (p_attacker == Monster::TYPE::electric && p_enemy == Monster::TYPE::rock)
		return 0.5f;

	//ELECTRIC vs WATER
	if (p_attacker == Monster::TYPE::electric && p_enemy == Monster::TYPE::water)
		return 2.f;
	if (p_attacker == Monster::TYPE::water && p_enemy == Monster::TYPE::electric)
		return 0.5f;

	return 1.f;
}

Attack::TYPE CAttack::getType(){
	return m_type;
}

void CAttack::info(){
	std::cout << m_name << std::endl;
	std::cout << "Type : " << m_type << std::endl;
	std::cout << "NbUse : " << m_nbUse << std::endl;
	std::cout << "Power : " << m_power << std::endl;
	std::cout << "Fail : " << m_failProbability << std::endl;
}