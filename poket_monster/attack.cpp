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

Attack::STATE CAttack::use(class CMonster& p_attacker, class CMonster& p_enemy, CArena& p_arena){
	/*
	*	TODO gerer les attaques sp�ciales la famille 
	*/
	int l_damage;

	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(85, 100);
	std::uniform_int_distribution<std::mt19937::result_type> l_dist62(0, 100);

	l_damage = 11 * p_attacker.getAttack() * m_power;
	l_damage /= p_enemy.getDefense() * 25;
	l_damage += 2;
	l_damage *= (l_dist6(l_rng)/100);

	l_damage = (unsigned int)((float)l_damage * computeAttackCoef(p_attacker.getType(), p_enemy.getType()));
	m_nbUse--;

	//On regarde si l'attaque est reussie ou non
	if (p_attacker.getState() == Monster::STATE::paralized){
		//Si le joueur est paralys� il a une chance sur quatre de rater son attaque
		if (l_dist62(l_rng) <= 25)
			return Attack::STATE::fallen;
	}
	else if (l_dist62(l_rng) <= (unsigned int)(m_failProbability * 100)){
		return Attack::STATE::fallen;
	}
	
	//On regarde si le terrain est inond� et si le joueur rate son attaque
	//Si le joueur tombe parceque le terrain est inond� il se prend un quart de son attaque 
	if (p_attacker.getType() != Monster::TYPE::water && p_arena.getState() == Arena::STATE::flooded && p_arena.stateImpact()){
		p_attacker.applyDamage((unsigned int)p_attacker.getAttack() / 4);
		return Attack::STATE::fallen;
	}

	return Attack::STATE::success;
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
	std::cout << "Type : ";
	displayAttackType();
	std::cout << "NbUse : " << m_nbUse << std::endl;
	std::cout << "Power : " << m_power << std::endl;
	std::cout << "Fail : " << m_failProbability << std::endl;
}

void CAttack::displayAttackType(){
	switch (m_type){
		case Attack::TYPE::electric:
			std::cout << "Electric" << std::endl;
			break;

		case Attack::TYPE::water:
			std::cout << "Water" << std::endl;
			break;

		case Attack::TYPE::fire:
			std::cout << "Fire" << std::endl;
			break;

		case Attack::TYPE::grass:
			std::cout << "Grass" << std::endl;
			break;

		case Attack::TYPE::rock:
			std::cout << "Rock" << std::endl;

		case Attack::TYPE::normal:
			std::cout << "Normal" << std::endl;
			break;

		default:
			std::cerr << "ERROR DISPLAYING Attack TYPE" << std::endl;
			break;
		}

}