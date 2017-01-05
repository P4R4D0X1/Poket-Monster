#ifndef DRUG_HPP_INCLUDE
#define DRUG_HPP_INCLUDE

#include "object.hpp"

class CDrug : public CObject{
	public:
		CDrug();
		CDrug(std::string p_name, Drug::TYPE p_type);
		virtual ~CDrug();

		void use(class CMonster& p_monster);
		Drug::TYPE getType();

		void info();

	protected:
		Drug::TYPE m_type;

};

#endif