#ifndef ELECTRIC_H_INCLUDE
#define ELECTRIC_H_INCLUDE

#include <iostream>
#include "monster.hpp"

class CElectric : public CMonster{
	public:
		CElectric();
		virtual ~CElectric();

		bool paralyze(); //indicates if enemy is paralysed or not after the attack


	private:
		float m_paralysis;
};

#endif