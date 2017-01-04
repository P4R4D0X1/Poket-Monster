#ifndef POTION_HPP_INCLUDE
#define POTION_HPP_INCLUDE

#include "object.hpp"

class CPotion : public CObject{
	public:
		CPotion();
		CPotion(std::string, int p_heal);
		virtual ~CPotion();

		void usePotion(CMonster &p_monster);

	protected:
		int m_heal;
};


#endif