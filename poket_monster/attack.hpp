#ifndef ATTACK_HPP_INCLUDE
#define ATTACK_HPP_INCLUDE

#include <iostream>
#include <string>
#include <random>

#include "namespace.hpp"

class CAttack{
	public:
		CAttack();
		CAttack(std::string p_name, Attack::TYPE p_type, int p_nbUse, int p_power, float p_failProbability);
		virtual ~CAttack();

		//Return la valeur de la contre attack
		int use(class CMonster& p_attacker, class CMonster& p_enemy);
		Attack::TYPE getType();

	protected:
		std::string m_name;
		Attack::TYPE m_type;

		int m_nbUse;
		int m_power;
		float m_failProbability;
};

#endif