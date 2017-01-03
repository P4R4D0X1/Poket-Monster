#ifndef ELECTRIC_HPP_INCLUDE
#define ELECTRIC_HPP_INCLUDE

#include <iostream>
#include "monster.hpp"

class CElectric : public CMonster{
	public:
		CElectric();
		virtual ~CElectric();

		bool paralyze(); //indicates if enemy is paralysed or not after the attack

	protected:
		float m_paralysis;
};

#endif