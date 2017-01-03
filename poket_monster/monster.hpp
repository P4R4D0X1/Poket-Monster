#ifndef MONSTER_HPP_INCLUDE
#define MONSTER_HPP_INCLUDE

#include <iostream>
#include <string>

namespace State{
	enum TYPE{
		poisoned,
		paralized,
		burned
	};
}

class CMonster{
	public:
		CMonster();
		virtual ~CMonster();


	protected:
		std::string m_name;
		int m_hp;
		int m_speed;
		int m_attack;
		int m_defense;
		State::TYPE m_state;
};

#endif