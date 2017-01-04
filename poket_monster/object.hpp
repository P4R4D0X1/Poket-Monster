#ifndef OBJECT_HPP_INCLUDE
#define OBJECT_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>

#include "potion.hpp"
#include "drug.hpp"

class CObject{
public:
	CObject();
	virtual ~CObject();

protected:
	std::string m_name;

	std::vector <CDrug> m_drugs;
	std::vector <CPotion> m_potions;

};


#endif