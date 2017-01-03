#ifndef WATER_HPP_INCLUDE
#define WATER_HPP_INCLUDE

#include "monster.hpp"

class CWater : public CMonster{
	public:
		CWater();
		virtual ~CWater();

		virtual void attack(Monster::ATTACK p_attack, CMonster& const p_enemy);
		virtual Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		bool flood();

	protected:
		float m_flood;
		float m_fall;
};

#endif