#ifndef GRAPHIC_HPP_INCLUDE
#define GRAPHIC_HPP_INCLUDE

#include <iostream>
#include <map>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "namespace.hpp"

class CMonster;

class CGraphic{
	public:
		CGraphic();
		virtual ~CGraphic();
		
		void update();
		bool displayMenuAction(std::map<std::string, Menu::TYPE>& p_actions, std::map<std::string, Menu::TYPE>::iterator& p_action);
		bool displayMenuMonster(std::vector<CMonster*>& p_monsters, std::vector<CMonster*>::iterator& p_monster);
		bool displayMenuAttack(std::vector<CAttack*>& p_attacks, std::vector<CAttack*>::iterator& p_attack);

	protected:
		sf::RenderWindow m_window;
		sf::Font m_font;

};


#endif




