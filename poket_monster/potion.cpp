#include "potion.hpp"

CPotion::CPotion(){
}

void CPotion::usePotion(CMonster &p_monster){
	//p_monster.usePotion(*this);
	if (m_name == "Full Restore"){
		//Redonner tous les pv au pok�mon et soigner l'�tat
		//p_monster.m_hp = p_monster.m_hpMax;
		//p_monster.m_state = normal;

	}
	else if (m_name == "Max Potion"){
		//Redonner tous les PVs au pok�mon
		//p_monster.m_hp = p_monster.m_hpMax;
		
	}
	else{
		//Recuperer m_heal et l'ajouter au PV du pok�mon
		//p_monster.m_hp += p_potion.m_heal;

	}
}