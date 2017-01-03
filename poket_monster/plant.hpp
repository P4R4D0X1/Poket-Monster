#ifndef PLANT_HPP_INCLUDE
#define PLANT_HPP_INCLUDE

#include "grass.hpp"

class CPlant : public CGrass{
	public:
		CPlant();
		CPlant(std::string p_name, int p_hp, int p_speed, int p_attack, int p_defense);
		virtual ~CPlant();

	protected:
		
};

#endif