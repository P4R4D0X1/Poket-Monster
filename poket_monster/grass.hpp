#ifndef GRASS_HPP_INCLUDE
#define GRASS_HPP_INCLUDE

#include "monster.hpp"

class CGrass : public CMonster{
	public:
		CGrass();
		CGrass(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense);
		virtual ~CGrass();

		virtual void attack(Monster::ATTACK_SLOT p_attack, CMonster&  p_enemy);
		Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);

	protected:

};

#endif