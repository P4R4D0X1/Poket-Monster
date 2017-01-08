#ifndef PLANT_HPP_INCLUDE
#define PLANT_HPP_INCLUDE

#include "grass.hpp"

class CPlant : public CGrass{
	public:
		CPlant();
		CPlant(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_heal);
		CPlant(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_heal, std::vector<CAttack*>& p_attacks);
		virtual ~CPlant();

		void specialAttack(CMonster& p_enemy, CArena& p_arena);
		void info();

	protected:
		bool heal();

		float m_heal;
};

#endif