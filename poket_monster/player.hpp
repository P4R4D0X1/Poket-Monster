#ifndef PLAYER_HPP_INCLUDE
#define PLAYER_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>

#include "monster.hpp"
#include "object.hpp"

class CPlayer{
	public:
		//CONSTRUCTOR / DESTRUCTOR
		CPlayer();
		CPlayer(std::string p_name, std::vector<CMonster*>& p_monsters, std::vector<CObject*>& p_objects);
		virtual ~CPlayer();

		//FUNCTION
		void chooseAction(CPlayer& p_enemy, CArena& p_arena);
		void action(Player::ACTION p_action, CPlayer& p_enemy, CArena& p_arena);
		
		unsigned int chooseMonster();	
		void chooseAttack(CPlayer& p_enemy, CArena& p_arena);
		void chooseObject();

		//INFO 
		void actionsListInfo();
		void monstersListInfo();
		void objectListInfo();

		//GETER / SETER
		int getMonsterSpeed();

	protected:
		//MEMBER
		std::string m_name;

		CMonster* m_actualMonster;
		std::vector<CMonster*> m_monsters;
		std::vector<CObject*> m_objects;
};

#endif