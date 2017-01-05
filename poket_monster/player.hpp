#ifndef PLAYER_HPP_INCLUDE
#define PLAYER_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>

#include "monster.hpp"
#include "object.hpp"
/*
*	Le player peut avoir jusqu'a 3 monstres et 5 objets (pour commencer ils auront 3 monstres et 5 objets)
*	3 ACTIONS POSSIBLES
*	|_Donner l'ordre à son monstre d'attaquer
*	|_Utiliser un objet
*	|_Changer de monstre sur le terrain
*
*	[-] Pouvoir recuperer l'etat de l'inventaire (quels objets sont utilisables ou non)
*/


class CPlayer{
	public:
		CPlayer();
		virtual ~CPlayer();

		void action(Player::ACTION p_action, CPlayer& p_enemy);
		void chooseMonster(unsigned int p_index);

	protected:
		void attack(unsigned int p_index, CPlayer& p_enemy);

		std::string m_name;

		CMonster* m_actualMonster;
		std::vector<CMonster*> m_monster;
		std::vector<CObject*> m_objet;
};

#endif