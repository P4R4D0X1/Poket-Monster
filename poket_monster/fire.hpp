#ifndef FIRE_HPP_INCLUDE
#define FIRE_HPP_INCLUDE

#include "monster.hpp"

class CFire : public CMonster{
	public:
		CFire();
		CFire(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_burn);
		CFire(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_burn, std::vector<CAttack*>& p_attacks);
		virtual ~CFire();

		void specialAttack(CMonster& p_enemy, CArena& p_arena);
		void info();

	protected:
		bool fire();

		float m_burn;

};

#endif