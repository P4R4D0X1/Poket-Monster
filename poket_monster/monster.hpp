#ifndef MONSTER_HPP_INCLUDE
#define MONSTER_HPP_INCLUDE

#include <iostream>
#include <random>
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
		feelgood,
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
		CMonster(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type);
		virtual ~CMonster();

		virtual void attack(Monster::ATTACK p_attack, CMonster& const p_enemy);
		virtual Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		void setState(Monster::STATE p_state);
		//updateState va prendre en parametre un terrain pour adapter l'etat des monstre en fonction de cet etat #swag
		virtual void updateState();

	protected:
		std::string m_name;
		int m_hp;
		int m_speed;
		int m_attack;
		int m_defense;
		int m_paralyzedTour;
		Monster::TYPE m_type;
		Monster::STATE m_state;
};

#endif