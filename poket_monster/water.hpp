#ifndef WATER_HPP_INCLUDE
#define WATER_HPP_INCLUDE

#include "monster.hpp"

class CWater : public CMonster{
	public:
		CWater();
		CWater(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_flood, float p_fall);
		virtual ~CWater();

		void attack(Monster::ATTACK_SLOT p_attack, CMonster&  p_enemy);
		Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		bool flood();

	protected:
		float m_flood;
		float m_fall;
};

#endif