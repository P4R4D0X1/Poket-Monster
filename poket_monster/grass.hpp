#ifndef GRASS_HPP_INCLUDE
#define GRASS_HPP_INCLUDE

#include "monster.hpp"

class CGrass : public CMonster{
	public:
		CGrass();
		CGrass(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type);
		CGrass(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, std::vector<CAttack*>& p_atacks, Monster::TYPE p_type);
		virtual ~CGrass();

		virtual void attack(unsigned int p_index, CMonster&  p_enemy);
		Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		void updateState();
		void info();

	protected:

};

#endif