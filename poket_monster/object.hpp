#ifndef OBJECT_HPP_INCLUDE
#define OBJECT_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>

#include "namespace.hpp"

class CObject{
	public:
		CObject();
		CObject(std::string p_name, Object::TYPE p_type);
		virtual ~CObject();

		virtual void use(class CMonster& p_monster);
		std::string getName();
		Object::TYPE getObjectType();
		virtual void info();

	protected:
		std::string m_name;
		Object::TYPE m_type;
		bool m_used;
};


#endif