#ifndef ELECTRIC_HPP_INCLUDE
#define ELECTRIC_HPP_INCLUDE

#include <iostream>
#include "monster.hpp"

class CElectric : public CMonster{
	public:
		CElectric();
		CElectric(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense);
		virtual ~CElectric();
		
		virtual void attack(Monster::ATTACK p_attack, CMonster&  p_enemy);
		virtual Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		bool paralyze(); //indicates if enemy is paralysed or not after the attack

	protected:
		float m_paralysis;
};

#endif