#ifndef FIRE_HPP_INCLUDE
#define FIRE_HPP_INCLUDE

#include "monster.hpp"

class CFire : public CMonster{
	public:
		CFire();
		virtual ~CFire();

		virtual void attack(Monster::ATTACK p_attack, CMonster& const p_enemy);
		virtual Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		void fire(CMonster& const p_enemy);

	protected:

};

#endif