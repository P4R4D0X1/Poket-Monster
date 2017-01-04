#ifndef ROCK_H_INCLUDE
#define ROCK_H_INCLUDE

#include "monster.hpp"

class CRock : public CMonster{
	public:
		CRock();
		CRock(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense);
		virtual ~CRock();

		void hide(); //hides during 3 rounds

	protected:
		int m_hiddenRound;
};



#endif