#ifndef POTION_HPP_INCLUDE
#define POTION_HPP_INCLUDE

#include "object.hpp"

class CPotion : public CObject{
	public:
		CPotion();
		CPotion(int p_heal);
		virtual ~CPotion();

		void setHeal(int p_heal);

		int getHeal();
		Potion::TYPE getType();

		void usePotion(CMonster &p_monster);

	protected:
		int m_heal;
		Potion::TYPE m_type;
};


#endif