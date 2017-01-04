#include "potion.hpp"

CPotion::CPotion(){
	m_heal = 0;
}

CPotion::CPotion(std::string p_name, int p_heal){
	m_name = p_name;
	m_heal = p_heal;
}

void CPotion::usePotion(CMonster &p_monster){
	//p_monster.usePotion(*this);
	if (m_name == "Full Restore"){
		//Redonner tous les pv au pok�mon et soigner l'�tat
		/*p_monster.m_hp = p_monster.m_hpMax;
		p_monster.m_state = normal;
		std::cout << "HP and state retored! You used one Full Restore" << std::endl;*/
	}
	else if (m_name == "Max Potion"){
		//Redonner tous les PVs au pok�mon
		/*p_monster.m_hp = p_monster.m_hpMax;
		std::cout << "HP restored to the max!You used one Max Potion" << std::endl;*/
		
	}
	else{
		//Recuperer m_heal et l'ajouter au PV du pok�mon
		//p_monster.m_hp += p_potion.m_heal;
		std::cout << "HP + " << m_heal << std::endl;
	}
}