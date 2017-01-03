#ifndef ATTACK_HPP_INCLUDE
#define ATTACK_HPP_INCLUDE

#include <iostream>
#include <string>
#include "monster.hpp"

class CAttack{
	public:
		CAttack();
		virtual ~CAttack();

	protected:
		std::string m_name;
		Monster::TYPE m_type;

		int m_nbUse;
		int m_power;
		int m_failProbability;
};


#endif