#ifndef OBJECT_HPP_INCLUDE
#define OBJECT_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>

#include "namespace.hpp"

class CObject{
	public:
		CObject();
		CObject(std::string p_name);
		virtual ~CObject();

		std::string getName();
		Object::TYPE getType();
		void info();

	protected:
		std::string m_name;
		Object::TYPE m_type;
};


#endif