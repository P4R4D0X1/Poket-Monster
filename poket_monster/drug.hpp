#ifndef DRUG_HPP_INCLUDE
#define DRUG_HPP_INCLUDE

#include "object.hpp"

class CDrug : public CObject{
	public:
		CDrug();
		virtual ~CDrug();

	protected:
		useDrug();
};

#endif