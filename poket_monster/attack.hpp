#ifndef ATTACK_HPP_INCLUDE
#define ATTACK_HPP_INCLUDE

#include <iostream>
#include <string>

namespace Type{
	enum TYPEP{
		electric,
		water,
		rock,
		fire,
		grass,
		normal
	};
}

class CAttack{
	public:
		CAttack();
		virtual ~CAttack();



	protected:
		std::string m_name;
		Type::TYPEP m_type;

		int m_nbUse;
		int power;
		int m_probabilityFail;
};


#endif