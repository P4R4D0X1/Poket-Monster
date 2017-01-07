#ifndef ELECTRIC_HPP_INCLUDE
#define ELECTRIC_HPP_INCLUDE

#include "monster.hpp"

class CElectric : public CMonster{
	public:
		CElectric();
		CElectric(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_paralysis);
		CElectric(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_paralysis, std::vector<CAttack*>& p_attacks);
		virtual ~CElectric();
		
		void specialAttack(CMonster& p_enemy, CArena& p_arena);
		bool paralyze(); 
		
		void info();

	protected:
		float m_paralysis;
};

#endif