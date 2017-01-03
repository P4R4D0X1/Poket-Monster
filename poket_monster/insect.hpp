#ifndef INSECT_HPP_INCLUDE
#define INSECT_HPP_INCLUDE

#include "grass.hpp"

class CInsect : public CGrass{
	public:
		CInsect();
		CInsect(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense);
		virtual ~CInsect();

	protected:

};

#endif