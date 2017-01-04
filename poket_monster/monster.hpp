#ifndef MONSTER_HPP_INCLUDE
#define MONSTER_HPP_INCLUDE

#include <iostream>
#include <random>
#include <string>

#include "namespace.hpp"
#include "attack.hpp"
#include "arena.hpp"

#include "potion.hpp"
#include "drug.hpp"


class CMonster{
	public:
		CMonster();
		CMonster(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type);
		virtual ~CMonster();

		virtual void attack(Monster::ATTACK_SLOT p_attack, CMonster& p_enemy);
		virtual Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		virtual void updateState(); //va prendre en parametre un terrain pour adapter l'etat des monstre en fonction de cet etat #swag
		virtual void usePotion(CPotion& p_potion);
		virtual void useDrug(CDrug &p_drug);
		bool isAlive();
		int getAttack();
		int getDefense();
		Monster::STATE getState();
		void setState(Monster::STATE p_state);
		void setArena(CArena& p_arena);
		virtual void info();

	protected:
		std::string m_name;
		int m_hp;
		int m_hpMax;
		int m_speed;
		int m_attack;
		int m_defense;
		int m_stateLongevity;
		Monster::TYPE m_type;
		Monster::STATE m_state;

		std::vector<CAttack*> m_attacks;
		CArena* m_arena;
};

#endif