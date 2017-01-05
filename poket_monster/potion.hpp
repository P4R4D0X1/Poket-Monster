#ifndef POTION_HPP_INCLUDE
#define POTION_HPP_INCLUDE

#include "object.hpp"

class CPotion : public CObject{
	public:
		CPotion();
		CPotion(std::string p_name,int p_heal, Potion::TYPE p_type);
		virtual ~CPotion();
		
		void use(class CMonster& p_monster);
		Potion::TYPE getType();
		int getHeal();

		void info();

	protected:
		int m_heal;
		Potion::TYPE m_type;
};


#endif