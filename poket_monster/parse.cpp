#include "parse.hpp"

CParse::CParse(){
}

CParse::~CParse(){
}

void CParse::parseMonsters(std::string m_path){
	std::string l_tmp1, l_tmp, l_hp, l_speed, l_attack, l_defense, l_name, l_Smin, l_Smax, l_Sparalysis, l_Sfall, l_Sflood, l_Sburn, l_Sprotect, l_Sheal, l_Spoison;
	int l_min, l_max;
	float l_paralysis, l_fall, l_flood, l_burn, l_heal, l_protect, l_poison;
	Monster::TYPE l_type;
	

	std::fstream l_file(m_path.c_str(), std::ios::in);

	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
	}

	while (!l_file.eof()){

		std::getline(l_file, l_tmp1);

		if (l_tmp1 == "Monster"){
			sMonster* l_monster = NULL;
			l_monster = new sMonster();
			do {
				std::getline(l_file, l_tmp);

				if (!(l_tmp.find("Name") == std::string::npos)){
					l_name = l_tmp.erase(0, 7);
					l_monster->m_name = l_name;
				}

				else if (!(l_tmp.find("Type") == std::string::npos)){
					l_tmp = l_tmp.erase(0, 7);
					if (l_tmp.compare("Electric")){
						l_type = Monster::TYPE::electric;
					}
					else if (l_tmp.compare("Water")){
						l_type = Monster::TYPE::water;
					}
					else if (l_tmp.compare("Plant")){
						l_type = Monster::TYPE::plant;
					}
					else if (l_tmp.compare("Insect")){
						l_type = Monster::TYPE::insect;
					}
					else if (l_tmp.compare("Fire")){
						l_type = Monster::TYPE::fire;
					}
					else if (l_tmp.compare("Rock")){
						l_type = Monster::TYPE::rock;
					}
					else{
						std::cerr << "Error while parsing monsters : type not recognized." << std::endl;
					}

					l_monster->m_type = l_type;
				}


				else if (!(l_tmp.find("HP") == std::string::npos)){
					l_hp = l_tmp.erase(0, 6);

					l_Smin = l_hp;
					l_Smax = l_hp;

					l_Smin = l_Smin.erase(l_hp.find('\t'), l_hp.size());
					l_min = atoi(l_Smin.c_str());

					l_Smax = l_Smax.erase(0, l_Smin.size());
					l_max = atoi(l_Smax.c_str());

					l_monster->m_hpMin = l_min;
					l_monster->m_hpMax = l_max;
				}

				else if (!(l_tmp.find("Speed") == std::string::npos)){
					l_speed = l_tmp.erase(0, 8);

					l_Smin = l_speed;
					l_Smax = l_speed;

					l_Smin = l_Smin.erase(l_speed.find('\t'), l_speed.size());
					l_min = atoi(l_Smin.c_str());

					l_Smax = l_Smax.erase(0, l_Smin.size());
					l_max = atoi(l_Smax.c_str());

					l_monster->m_speedMin = l_min;
					l_monster->m_speedMax = l_max;
				}

				else if (!(l_tmp.find("Attack") == std::string::npos)){
					l_attack = l_tmp.erase(0, 9);

					l_Smin = l_attack;
					l_Smax = l_attack;

					l_Smin = l_Smin.erase(l_attack.find('\t'), l_attack.size());
					l_min = atoi(l_Smin.c_str());

					l_Smax = l_Smax.erase(0, l_Smin.size());
					l_max = atoi(l_Smax.c_str());

					l_monster->m_attackMin = l_min;
					l_monster->m_attackMax = l_max;
				}

				else if (!(l_tmp.find("Defense") == std::string::npos)){
					l_defense = l_tmp.erase(0, 10);

					l_Smin = l_defense;
					l_Smax = l_defense;

					l_Smin = l_Smin.erase(l_defense.find('\t'), l_defense.size());
					l_min = atoi(l_Smin.c_str());

					l_Smax = l_Smax.erase(0, l_Smin.size());
					l_max = atoi(l_Smax.c_str());

					l_monster->m_defenseMin = l_min;
					l_monster->m_defenseMax = l_max;
				}

				else if (!(l_tmp.find("Paralysis") == std::string::npos)){
					l_Sparalysis = l_tmp.erase(0, 12);
					l_paralysis = std::stof(l_Sparalysis.c_str());

					l_monster->m_paralysis = l_paralysis;
				}

				else if (!(l_tmp.find("Flood") == std::string::npos)){
					l_Sflood = l_tmp.erase(0, 8);
					l_flood = std::stof(l_Sflood.c_str());

					l_monster->m_flood = l_flood;
				}

				else if (!(l_tmp.find("Fall") == std::string::npos)){
					l_Sfall = l_tmp.erase(0, 7);
					l_fall = std::stof(l_Sfall.c_str());

					l_monster->m_fall = l_fall;
				}

				else if (!(l_tmp.find("Burn") == std::string::npos)){
					l_Sburn = l_tmp.erase(0, 7);
					l_burn = std::stof(l_Sburn.c_str());

					l_monster->m_burn = l_burn;
				}

				else if (!(l_tmp.find("Protect") == std::string::npos)){
					l_Sprotect = l_tmp.erase(0, 10);
					l_protect = std::stof(l_Sprotect.c_str());

					l_monster->m_protect = l_protect;
				}

				else if (!(l_tmp.find("Heal") == std::string::npos)){
					l_Sheal = l_tmp.erase(0, 7);
					l_heal = std::stof(l_Sheal.c_str());

					l_monster->m_heal = l_heal;
				}

				else if (!(l_tmp.find("Poison") == std::string::npos)){
					l_Spoison = l_tmp.erase(0, 9);
					l_poison = std::stof(l_Spoison.c_str());

					l_monster->m_poison = l_poison;
				}
			} while (l_tmp != "EndMonster");


			m_tabMonsters.push_back(l_monster);
		}
	}
}

void CParse::parseAttack(std::string m_path){
	std::string l_tmp1, l_tmp, l_name, l_sPower, l_sNbUse, l_sFail;
	int l_min, l_max, l_power, l_nbUse;
	float l_paralysis, l_fall, l_flood, l_burn, l_heal, l_protect, l_poison, l_fail;
	Attack::TYPE l_type;

	std::fstream l_file(m_path.c_str(), std::ios::in);

	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
	}

	while (!l_file.eof()){
		std::getline(l_file, l_tmp1);
		if (l_tmp1 == "Attack"){
			CAttack *l_attack = NULL;
			do {
				std::getline(l_file, l_tmp);

				if (!(l_tmp.find("Name") == std::string::npos)){
					l_name = l_tmp.erase(0, 6);
				}

				else if (!(l_tmp.find("Type") == std::string::npos)){
					l_tmp = l_tmp.erase(0, 7);
					if (l_tmp.compare("Electric")){
						l_type = Attack::TYPE::electric;
					}
					if (l_tmp.compare("Water")){
						l_type = Attack::TYPE::water;
					}
					if (l_tmp.compare("Grass")){
						l_type = Attack::TYPE::grass;
					}
					if (l_tmp.compare("Fire")){
						l_type = Attack::TYPE::fire;
					}
					if (l_tmp.compare("Rock")){
						l_type = Attack::TYPE::rock;
					}
				}

				else if (!(l_tmp.find("Power") == std::string::npos)){
					l_sPower = l_tmp.erase(0, 7);
					l_power = atoi(l_sPower.c_str());
				}

				else if (!(l_tmp.find("NbUse") == std::string::npos)){
					l_sNbUse = l_tmp.erase(0, 7);
					l_nbUse = atoi(l_sNbUse.c_str());
				}

				else if (!(l_tmp.find("Fail") == std::string::npos)){
					l_sFail = l_tmp.erase(0, 7);
					l_fail = std::stof(l_sFail.c_str());
				}

			} while (l_tmp != "EndAttack" );
			l_attack = new CAttack(l_name, l_type, l_nbUse, l_power, l_fail);
			m_tabAttacks.push_back(l_attack);
		}
	}
}

void CParse::parseObjects(std::string m_path){
	std::string l_tmp1, l_tmp, l_name, l_sHeal;
	int l_heal;
	Object::TYPE l_type;

	std::fstream l_file(m_path.c_str(), std::ios::in);

	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
	}

	while (!l_file.eof()){
		std::getline(l_file, l_tmp1);
		if (l_tmp1 == "Object"){
			CObject *l_object = NULL;
			do {
				std::getline(l_file, l_tmp);

				if (!(l_tmp.find("Name") == std::string::npos)){
					l_name = l_tmp.erase(0, 6);
				}

				else if (!(l_tmp.find("Type") == std::string::npos)){
					l_tmp = l_tmp.erase(0, 6);

					if (l_tmp.compare("Potion")){
						l_type = Object::TYPE::potion;
					}
					else if (l_tmp.compare("Drug")){
						l_type = Object::TYPE::drug;
					}
				}

				else if (!(l_tmp.find("Heal") == std::string::npos)){
					l_sHeal = l_tmp.erase(0, 6);
					l_heal = atoi(l_sHeal.c_str());
				}

			} while (l_tmp != "EndObject");

			if (l_type == Object::TYPE::potion){
				l_object = new CPotion(l_name, l_heal);
			}
			else if (l_type == Object::TYPE::drug){
				l_object = new CDrug(l_name);
			}

			m_tabObjects.push_back(l_object);
		}
	}
}

void CParse::infoStructMonster(sMonster *p_monster){
	std::cout << p_monster->m_name << "\n";
	std::cout << "Type : " << p_monster->m_type << std::endl;
	std::cout << "HP : [" << p_monster->m_hpMin << ", " << p_monster->m_hpMax << "]" << std::endl;
	std::cout << "Speed : [" << p_monster->m_speedMin << ", " << p_monster->m_speedMax << "]" << std::endl;
	std::cout << "Attack : [" << p_monster->m_attackMin << ", " << p_monster->m_attackMax << "]" << std::endl;
	std::cout << "Defense : [" << p_monster->m_defenseMin << ", " << p_monster->m_defenseMax << "]" << std::endl;

	//Pour afficher les membres spécifiques au type de monstre
	/*switch (p_monster.m_type){
		case (0) :
			break;
		case (1) :
			break;
		case (2) :
			break;
		case (3) :
			break;
	}*/

}

void CParse::info(){
	int i;
	std::cout << "[PRINTING VALUES]" << std::endl;

	std::cout << "[MONSTERS]" << std::endl;
	for (i = 0; i < m_tabMonsters.size(); i++){
		infoStructMonster(m_tabMonsters[i]);
		std::cout << std::endl;
	}

	std::cout << "[ATTACKS]" << std::endl;
	for (i = 0; i < m_tabAttacks.size(); i++){
		m_tabAttacks[i]->info();
		std::cout << std::endl;
	}

	std::cout << "[OBJECTS]" << std::endl;
	for (i = 0; i < m_tabObjects.size(); i++){			
				m_tabObjects[i]->info();
				std::cout << std::endl;
	}
}