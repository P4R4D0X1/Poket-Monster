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
	unsigned int l_damage;

	std::mt19937 l_rng;
	l_rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> l_dist6(85, 100);
	std::uniform_int_distribution<std::mt19937::result_type> l_dist62(0, 100);

	l_damage = (unsigned int)(11.f * (float)p_attacker.getAttack() * (float)m_power);
	l_damage /= (unsigned int)((float)p_enemy.getDefense() * 25.f);
	l_damage += 2;
	l_damage = (unsigned int)((float)l_damage * ((float)l_dist6(l_rng) / 100.f));

	l_damage = (unsigned int)((float)l_damage * computeAttackCoef(p_attacker.getType(), p_enemy.getType()));
	m_nbUse--;

	//On regarde si l'attaque est reussie ou non
	if (p_attacker.getState() == Monster::STATE::paralized){
		//Si le joueur est paralysé il a une chance sur quatre de rater son attaque
		if (l_dist62(l_rng) <= 25)
			return Attack::STATE::fail;
	}
	else if (l_dist62(l_rng) <= (unsigned int)(m_failProbability * 100)){
		return Attack::STATE::fail;
	}
	
	//On regarde si le terrain est inondé et si le joueur rate son attaque
	//Si le joueur tombe parceque le terrain est inondé il se prend un quart de son attaque 
	if (p_attacker.getType() != Monster::TYPE::water && p_arena.getState() == Arena::STATE::flooded && p_arena.stateImpact()){
		p_attacker.applyDamage((unsigned int)p_attacker.getAttack() / 4);
		return Attack::STATE::fallen;
	}

	p_enemy.applyDamage(l_damage);
	if (m_type != Attack::TYPE::normal)
		p_attacker.specialAttack(p_enemy, p_arena);

	return Attack::STATE::success;
}

std::string CAttack::infoToString(){
	std::string l_info;

	l_info = m_name + "\n";
	l_info += "TYPE " + attackTypeToString() + "\n";
	l_info += "USE " + std::to_string(m_nbUse) + "\n";
	l_info += "POWER " + std::to_string(m_power) + "\n";
	l_info += "FAIL " + std::to_string(m_failProbability);

	return l_info;
}

void CAttack::info(){
	std::cout << m_name << std::endl;
	std::cout << "Type : " << m_type << std::endl;
	std::cout << "NbUse : " << m_nbUse << std::endl;
	std::cout << "Power : " << m_power << std::endl;
	std::cout << "Fail : " << m_failProbability << std::endl;
}

std::string CAttack::getName(){
	return m_name;
}

Attack::TYPE CAttack::getType(){
	return m_type;
}

int CAttack::getNbUse(){
	return m_nbUse;
}

std::string CAttack::attackTypeToString(){
	switch (m_type){
	case Attack::TYPE::electric:
		return "Electric";
		break;

	case Attack::TYPE::water:
		return "Water";
		break;

	case Attack::TYPE::rock:
		return "Rock";
		break;

	case Attack::TYPE::fire:
		return "Fire";
		break;

	case Attack::TYPE::grass:
		return "Grass";
		break;

	case Attack::TYPE::normal:
		return "Normal";
		break;

	default:
		std::cerr << "ERROR DISPLAYING ATTACK TYPE" << std::endl;
		return "ERROR";
		break;
	}
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