#ifndef FIRE_HPP_INCLUDE
#define FIRE_HPP_INCLUDE

#include "monster.hpp"

class CFire : public CMonster{
	public:
		CFire();
		CFire(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_burn);
		virtual ~CFire();

		void attack(unsigned int p_index, CMonster&  p_enemy);
		Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		bool fire();
		void info();

	protected:
		float m_burn;

};

#endif