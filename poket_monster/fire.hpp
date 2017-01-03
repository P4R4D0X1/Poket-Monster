#ifndef FIRE_HPP_INCLUDE
#define FIRE_HPP_INCLUDE

#include "monster.hpp"

class CFire : public CMonster{
	public:
		CFire();
		CFire(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense);
		virtual ~CFire();

		virtual void attack(Monster::ATTACK p_attack, CMonster&  p_enemy);
		virtual Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		void fire(CMonster& p_enemy);

	protected:

};

#endif