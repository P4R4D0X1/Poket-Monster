#include "object.hpp"

CObject::CObject(){
}

CObject::CObject(std::string p_name){
	m_name = p_name;
}

CObject::~CObject(){
}

std::string CObject::getName(){
	return m_name;
}

Object::TYPE CObject::getType(){
	return m_type;
}

void CObject::info(){
	std::cout << m_name << std::endl;
}