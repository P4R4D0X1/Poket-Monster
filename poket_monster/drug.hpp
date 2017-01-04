#ifndef DRUG_HPP_INCLUDE
#define DRUG_HPP_INCLUDE

#include "object.hpp"

class CDrug : public CObject{
	public:
		CDrug();
		virtual ~CDrug();

	protected:
		void useDrug(CMonster &p_monster);
};

#endif