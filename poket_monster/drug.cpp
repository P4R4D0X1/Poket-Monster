#include "drug.hpp"

CDrug::CDrug(){
}

CDrug::CDrug(std::string p_name){
	m_name = p_name;
}

void CDrug::useDrug(CMonster &p_monster){
	//p_monster.useDrug(*this);
	if (m_name == "Burn Heal"){
		/*if (p_monster.m_state == burned){
			p_monster.m_state = normal;
			std::cout << "Pokemon not burned any more!" << std::endl;
		}
		std::cout << "You used one" << m_name << "!" << std::endl;*/
	}
	else if (m_name == "Ice Heal"){
		/*if (p_monster.m_state == freezed){
			p_monster.m_state = normal;
			std::cout << "Pokemon not freezed any more!" << std::endl;
		}
		std::cout << "You used one" << m_name << "!" << std::endl;*/
	}
	else if (m_name == "Antidote"){
		/*if (p_monster.m_state == poisoned){
			p_monster.m_state = normal;
			std::cout << "Pokemon not poisoned any more!" << std::endl;
		}
		std::cout << "You used one" << m_name << "!" << std::endl;*/
	}
	else if (m_name == "Paralyse Heal"){
		/*if (p_monster.m_state == paralyzed){
		p_monster.m_state = normal;
		std::cout << "Pokemon not paralyzed any more!" << std::endl;
		}
		std::cout << "You used one" << m_name << "!" << std::endl;*/
	}
	else if (m_name == "Awakening"){
		/*if (p_monster.m_state == asleep){
		p_monster.m_state = normal;
		std::cout << "Pokemon not asleep any more!" << std::endl;
		}
		std::cout << "You used one" << m_name << "!" << std::endl;*/
	}
}