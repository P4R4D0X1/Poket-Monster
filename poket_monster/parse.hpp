#ifndef PARSE_HPP_INCLUDE
#define PARSE_HPP_INCLUDE

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "monster.hpp"
#include "attack.hpp"
#include "object.hpp"

#include "electric.hpp"
#include "water.hpp"
#include "fire.hpp"
#include "plant.hpp"
#include "insect.hpp"
#include "rock.hpp"


typedef struct sMonster{
	std::string m_name;
	Monster::TYPE m_type;

	int m_hpMin;
	int m_hpMax;

	int m_speedMin;
	int m_speedMax;

	int m_attackMin;
	int m_attackMax;

	int m_defenseMin;
	int m_defenseMax;

	float m_paralysis;
	float m_flood;
	float m_fall;
	float m_burn;
	float m_heal;
	float m_protect;
	float m_poison;

}sMonster;


class CParse{
	public:
		CParse();
		virtual ~CParse();

		void parseMonsters(std::string m_path);
		void parseAttack(std::string m_path);
		void parseObjects(std::string m_path);
		std::vector<CMonster*> createMonsterVector(int p_monsterAmount);
		std::vector<CObject*> createObjectVector(int p_objectAmount);

		void infoStructMonster(sMonster *p_monster);
		void info();

	protected:
		std::vector<CAttack*> createAttackVector(int p_attackAmount, Attack::TYPE p_type);
		CMonster* createMonster(sMonster* p_monster);

		std::vector <sMonster*> m_tabMonsters;
		std::vector <CAttack*> m_tabAttacks;
		std::vector <CObject*> m_tabObjects;

};

#endif