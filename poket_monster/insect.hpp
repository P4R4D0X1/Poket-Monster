#ifndef INSECT_HPP_INCLUDE
#define INSECT_HPP_INCLUDE

#include "grass.hpp"

class CInsect : public CGrass{
	public:
		CInsect();
		CInsect(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_poison);
		CInsect(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_poison, std::vector<CAttack*>& p_attacks);
		virtual ~CInsect();

		void specialAttack(CMonster& p_enemy, CArena& p_arena);
		bool poison();

		void info();

	protected:
		float m_poison;

};

#endif