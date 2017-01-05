#include "object.hpp"

CObject::CObject(){
}

CObject::CObject(std::string p_name, Object::TYPE p_type){
	m_name = p_name;
	m_type = p_type;
	m_used = false;
}

CObject::~CObject(){
}

void CObject::use(class CMonster& p_monster){
	if (m_used)
		return;

	m_used = true;
}

std::string CObject::getName(){
	return m_name;
}

Object::TYPE CObject::getObjectType(){
	return m_type;
}

void CObject::info(){
	std::cout << m_name << std::endl;
}