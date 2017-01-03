#ifndef GRASS_HPP_INCLUDE
#define GRASS_HPP_INCLUDE

#include "monster.hpp"

class CGrass : public CMonster{
	public:
		CGrass();
		CGrass(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense);
		virtual ~CGrass();

	protected:

};

#endif