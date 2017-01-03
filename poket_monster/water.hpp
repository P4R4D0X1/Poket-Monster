#ifndef WATER_HPP_INCLUDE
#define WATER_HPP_INCLUDE

#include "monster.hpp"

class CWater : public CMonster{
	public:
		CWater();
		virtual ~CWater();

		bool flood();

	protected:
		float m_flood;
		float m_fall;
};

#endif