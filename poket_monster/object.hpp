#ifndef OBJECT_HPP_INCLUDE
#define OBJECT_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>

#include "monster.hpp"
#include "namespace.hpp"

class CObject{
public:
	CObject();
	CObject::CObject(std::string p_name);
	virtual ~CObject();

protected:
	std::string m_name;
	Object::TYPE m_type;
};


#endif