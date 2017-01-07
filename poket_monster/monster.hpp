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
		CMonster(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, std::vector<CAttack*>& p_attacks, Monster::TYPE p_type);
		virtual ~CMonster();

		virtual Attack::STATE attack(unsigned int p_index, CMonster& p_enemy, CArena& p_arena);
		virtual void specialAttack(CMonster& p_enemy, CArena& p_arena) = 0;
		void applyDamage(unsigned int p_damage);
		virtual void updateState(CArena& p_arena); //revoir ce merdier depuis le passage du CArena par paramètres
		virtual void useObject(CObject& p_object);
		bool isAlive();
		
		virtual void info();
		void attacksInfo();

		int getSpeed();
		int getAttack();
		int getDefense();
		Monster::TYPE getType();
		Monster::STATE getState();
		void setState(Monster::STATE p_state);

	protected:
		virtual void usePotion(CPotion& p_potion);
		virtual void useDrug(CDrug &p_drug);

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
};

#endif