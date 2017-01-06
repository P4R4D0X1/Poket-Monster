#ifndef PLANT_HPP_INCLUDE
#define PLANT_HPP_INCLUDE

#include "grass.hpp"

class CPlant : public CGrass{
	public:
		CPlant();
		CPlant(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_heal);
		CPlant(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_heal, std::vector<CAttack*>& p_attacks);
		virtual ~CPlant();

		virtual void attack(unsigned int p_index, CMonster&  p_enemy);
		bool heal();
		void info();

	protected:
		float m_heal;
};

#endif