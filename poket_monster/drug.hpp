#ifndef DRUG_HPP_INCLUDE
#define DRUG_HPP_INCLUDE

#include "object.hpp"

class CDrug : public CObject{
	public:
		CDrug();
		CDrug(std::string p_name);
		virtual ~CDrug();
		Drug::TYPE getType();
		void useDrug(class CMonster& p_monster);
		void info();

	protected:
		Drug::TYPE m_type;

};

#endif