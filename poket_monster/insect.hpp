#ifndef INSECT_HPP_INCLUDE
#define INSECT_HPP_INCLUDE

#include "grass.hpp"

class CInsect : public CGrass{
	public:
		CInsect();
		CInsect(std::string p_name, int p_hp, int p_hpMax, int p_speed, int p_attack, int p_defense, float p_poison);
		virtual ~CInsect();

		virtual void attack(Monster::ATTACK_SLOT p_attack, CMonster&  p_enemy);
		bool poison();
		void info();

	protected:
		float m_poison;

};

#endif