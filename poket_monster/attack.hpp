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
		virtual ~CAttack();

	protected:
		std::string m_name;
		Attack::TYPE m_type;

		int m_nbUse;
		int m_power;
		int m_failProbability;
};


#endif