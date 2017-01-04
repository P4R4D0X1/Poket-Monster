#include "potion.hpp"

CPotion::CPotion(){
	m_heal = 0;
}

CPotion::CPotion(int p_heal){
	m_heal = p_heal;
}

void CPotion::setHeal(int p_heal){
	m_heal = p_heal;
}

void CPotion::usePotion(CMonster &p_monster){
	//p_monster.usePotion(*this);
	if (m_name == "Full Restore"){
		//Redonner tous les pv au pokémon et soigner l'état
		/*p_monster.m_hp = p_monster.m_hpMax;
		p_monster.m_state = normal;
		std::cout << "HP and state retored! You used one Full Restore" << std::endl;*/
	}
	else if (m_name == "Max Potion"){
		//Redonner tous les PVs au pokémon
		/*p_monster.m_hp = p_monster.m_hpMax;
		std::cout << "HP restored to the max!You used one Max Potion" << std::endl;*/
		
	}
	else{
		//Recuperer m_heal et l'ajouter au PV du pokémon
		//p_monster.m_hp += p_potion.m_heal;
		std::cout << "HP + " << m_heal << std::endl;
	}
}