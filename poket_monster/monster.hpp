#ifndef MONSTER_HPP_INCLUDE
#define MONSTER_HPP_INCLUDE

#include <iostream>
#include <random>
#include <string>

#include "namespace.hpp"
#include "attack.hpp"


class CMonster{
	public:
		CMonster();
		CMonster(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type);
		virtual ~CMonster();

		virtual void attack(Monster::ATTACK p_attack, CMonster& p_enemy);
		virtual Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		//updateState va prendre en parametre un terrain pour adapter l'etat des monstre en fonction de cet etat #swag
		virtual void updateState();
		//void usePotion(CObject& p_potion);
		int getAttack();
		int getDefense();
		Monster::STATE getState();
		void setState(Monster::STATE p_state);

	protected:
		std::string m_name;
		int m_hp;
		int m_hpMax;
		int m_speed;
		int m_attack;
		int m_defense;
		int m_paralyzedTour;
		Monster::TYPE m_type;
		Monster::STATE m_state;

		std::vector<CAttack&> m_attacks;
};

#endif