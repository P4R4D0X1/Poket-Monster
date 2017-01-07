#ifndef ROCK_H_INCLUDE
#define ROCK_H_INCLUDE

#include "monster.hpp"

class CRock : public CMonster{
	public:
		CRock();
		CRock(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_protect);
		CRock(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_protect, std::vector<CAttack*>& p_attacks);
		virtual ~CRock();

		void specialAttack(CMonster& p_enemy, CArena& p_arena);
		bool hide(); //hides during 3 rounds max
		
		void info();

	protected:
		float m_protect;
		int m_hiddenRound;
};



#endif