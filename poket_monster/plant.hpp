#ifndef PLANT_HPP_INCLUDE
#define PLANT_HPP_INCLUDE

#include "grass.hpp"

class CPlant : public CGrass{
	public:
		CPlant();
		CPlant(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_heal);
		virtual ~CPlant();

		virtual void attack(Monster::ATTACK_SLOT p_attack, CMonster&  p_enemy);
		bool heal();
		void info();

	protected:
		float m_heal;
};

#endif