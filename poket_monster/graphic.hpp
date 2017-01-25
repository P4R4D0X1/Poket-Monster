#ifndef GRAPHIC_HPP_INCLUDE
#define GRAPHIC_HPP_INCLUDE

#include <iostream>
#include <map>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "particle.hpp"
#include "namespace.hpp"

class CMonster;
class CAttack;
class CObject;

class CGraphic{
	public:
		CGraphic();
		virtual ~CGraphic();
		
		void update();
		void updateParticle();
		bool displayLooser(std::string p_name);
		void displayPlayerName(std::string p_name);
		void displayMonsters(CMonster& p_playerMonster, CMonster& p_enemyMonster);
		bool displayMenuAction(std::map<std::string, Menu::TYPE>& p_actions, std::map<std::string, Menu::TYPE>::iterator& p_action);
		bool displayMenuMonster(std::vector<CMonster*>& p_monsters, std::vector<CMonster*>::iterator& p_monster);
		bool displayMenuAttack(std::vector<CAttack*>& p_attacks, std::vector<CAttack*>::iterator& p_attack);
		bool displayMenuObject(std::vector<CObject*>& p_objects, std::vector<CObject*>::iterator& p_object);

	protected:
		sf::RenderWindow m_window;
		sf::Font m_font;
		sf::FloatRect m_playerName;
		sf::FloatRect m_monsters;
		CParticleSystem m_particleSystem;
		sf::Clock m_clock;
		sf::Time m_elapsedTime;
};


#endif





