#ifndef PLAYER_HPP_INCLUDE
#define PLAYER_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "monster.hpp"
#include "object.hpp"
#include "graphic.hpp"

class CPlayer{
	public:
		//CONSTRUCTOR / DESTRUCTOR
		CPlayer();
		CPlayer(std::string p_name, std::vector<CMonster*>& p_monsters, std::vector<CObject*>& p_objects);
		virtual ~CPlayer();

		//GRAPHX DEV
		bool showMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui);

		void updateActionMenu();
		void showActionMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui);

		bool showMonsterMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui);

		void updateObjectMenu();
		bool showObjectMenu(CPlayer& p_enemy, CArena& p_arena, CGraphic& p_ui);

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

		Menu::TYPE m_menu;

		std::map<std::string, Menu::TYPE>::iterator m_action;
		std::map<std::string, Menu::TYPE> m_actions;

		std::vector<CMonster*>::iterator m_monster;
		std::vector<CMonster*> m_monsters;

		std::vector<CObject*>::iterator m_object;
		std::vector<CObject*> m_objects;

		
};

#endif