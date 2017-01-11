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
		
		void chooseMonster();	
		void chooseAttack(CPlayer& p_enemy, CArena& p_arena);
		void chooseObject();

		void updateMonsters(CArena& p_arena);

		//INFO 
		void actionsListInfo();
		void monstersListInfo();
		void objectListInfo();

		//GETTER / SETTER
		int getMonsterSpeed();

	protected:
		//MEMBER
		std::string m_name;

		CMonster* m_actualMonster;
		std::vector<CMonster*> m_monsters;
		std::vector<CObject*> m_objects;

		
};

#endif