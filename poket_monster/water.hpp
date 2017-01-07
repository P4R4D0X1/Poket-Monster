#ifndef WATER_HPP_INCLUDE
#define WATER_HPP_INCLUDE

#include "monster.hpp"

class CWater : public CMonster{
	public:
		CWater();
		CWater(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_flood, float p_fall);
		CWater(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_flood, float p_fall, std::vector<CAttack*>& p_attacks);
		virtual ~CWater();

		void specialAttack(CMonster& p_enemy, CArena& p_arena);
		bool flood();

		void info();

	protected:
		float m_flood;
		float m_fall;
};

#endif