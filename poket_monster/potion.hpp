#ifndef POTION_HPP_INCLUDE
#define POTION_HPP_INCLUDE

#include "object.hpp"

class CPotion : public CObject{
	public:
		CPotion();
		CPotion(std::string p_name,int p_heal);
		virtual ~CPotion();
		
		void usePotion(class CMonster& p_monster);
		int getHeal();
		Potion::TYPE getType();
		void setHeal(int p_heal);

		void info();

	protected:
		int m_heal;
		Potion::TYPE m_type;
};


#endif