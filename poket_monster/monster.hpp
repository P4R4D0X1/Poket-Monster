#ifndef MONSTER_HPP_INCLUDE
#define MONSTER_HPP_INCLUDE

#include <iostream>
#include <string>

#include "attack.hpp"

namespace Monster{
	enum TYPE{
		electric,
		water,
		rock,
		fire,
		grass
	};

	enum STATE{
		poisoned,
		paralized,
		burned
	};

	enum ATTACK{
		first,
		second,
		third,
		fourth
	};
}

class CMonster{
	public:
		CMonster();
		virtual ~CMonster();

		virtual void attack(Monster::ATTACK p_attack, CMonster& const p_enemy);
		virtual Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);

	protected:
		std::string m_name;
		int m_hp;
		int m_speed;
		int m_attack;
		int m_defense;
		Monster::TYPE m_type;
		Monster::STATE m_state;
};

#endif