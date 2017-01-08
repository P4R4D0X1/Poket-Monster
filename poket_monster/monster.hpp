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
		//CONSTRUCTOR / DESTRUCTOR
		CMonster();
		CMonster(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, Monster::TYPE p_type);
		CMonster(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, std::vector<CAttack*>& p_attacks, Monster::TYPE p_type);
		virtual ~CMonster();

		//FUNCTION
		unsigned int chooseAttack(CMonster& p_enemy, CArena& p_arena); 
		Attack::STATE attack(unsigned int p_index, CMonster& p_enemy, CArena& p_arena);
		virtual void specialAttack(CMonster& p_enemy, CArena& p_arena) = 0;
		void applyDamage(unsigned int p_damage);
		virtual void updateState(CArena& p_arena);
		void useObject(CObject& p_object);
		bool isOperational();
		
		//INFO
		virtual void info();
		void attacksInfo();

		//GETTER / SETTER
		int getSpeed();
		int getAttack();
		int getDefense();
		Monster::TYPE getType();
		Monster::STATE getState();
		void setState(Monster::STATE p_state);


	protected:
		//PROTECTED FUNCTION
		virtual void usePotion(CPotion& p_potion);
		virtual void useDrug(CDrug &p_drug);
		void displayMonsterType();

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