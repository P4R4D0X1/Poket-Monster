#ifndef ATTACK_HPP_INCLUDE
#define ATTACK_HPP_INCLUDE

#include <iostream>
#include <string>

namespace Attack{
	enum TYPE{
		electric,
		water,
		rock,
		fire,
		grass,
		normal
	};

	enum STATE{
		success,
		fallen
	};
}

class CAttack{
	public:
		CAttack();
		CAttack(std::string p_name, Attack::TYPE p_type, int p_nbUse, int p_power, int p_failProbability);
		virtual ~CAttack();

		//Return la valeur de la contre attack
		int use(CMonster& const p_attacker, CMonster& const p_enemy);
		Attack::TYPE getType();

	protected:
		std::string m_name;
		Attack::TYPE m_type;

		int m_nbUse;
		int m_power;
		int m_failProbability;
};

#endif