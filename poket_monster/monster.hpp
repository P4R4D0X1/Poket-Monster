#ifndef MONSTER_HPP_INCLUDE
#define MONSTER_HPP_INCLUDE

#include <iostream>
#include <string>

namespace State{

}

namespace Monster{
	enum TYPE{
		electric,
		water,
		rock,
		fire,
		grass,
		normal
	};

	enum STATE{
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
		Monster::TYPE m_type;
		Monster::STATE m_state;
};

#endif