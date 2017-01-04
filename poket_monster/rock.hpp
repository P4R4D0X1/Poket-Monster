#ifndef ROCK_H_INCLUDE
#define ROCK_H_INCLUDE

#include "monster.hpp"

class CRock : public CMonster{
	public:
		CRock();
		CRock(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_protect);
		virtual ~CRock();

		void attack(Monster::ATTACK_SLOT p_attack, CMonster&  p_enemy);
		Attack::STATE applyDamage(Attack::TYPE p_attackType, int p_damage);
		bool hide(); //hides during 3 rounds max

	protected:
		float m_protect;
		int m_hiddenRound;
};



#endif