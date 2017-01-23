#ifndef ATTACK_HPP_INCLUDE
#define ATTACK_HPP_INCLUDE

#include <iostream>
#include <string>
#include <random>

#include "namespace.hpp"
#include "arena.hpp"

class CAttack{
	public:
		CAttack();
		CAttack(std::string p_name, Attack::TYPE p_type, int p_nbUse, int p_power, float p_failProbability);
		virtual ~CAttack();

		//Return la valeur de la contre attack
		Attack::STATE use(class CMonster& p_attacker, class CMonster& p_enemy, CArena& p_arena);
		
		std::string infoToString();
		void info();
		
		std::string getName();
		Attack::TYPE getType();
		int getNbUse();

	protected:
		std::string attackTypeToString();
		float computeAttackCoef(Monster::TYPE p_attacker, Monster::TYPE p_enemy);

		std::string m_name;
		Attack::TYPE m_type;

		int m_nbUse;
		int m_power;
		float m_failProbability;
};

#endif