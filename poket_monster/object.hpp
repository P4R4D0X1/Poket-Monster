#ifndef OBJECT_HPP_INCLUDE
#define OBJECT_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>

class CObject{
public:
	CObject();
	virtual ~CObject();

protected:
	std::string m_name;

};


#endif