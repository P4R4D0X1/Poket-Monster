#include "parse.hpp"

CParse::CParse(){
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

			do {
				std::getline(l_file, l_tmp);

				if (!(l_tmp.find("Name") == std::string::npos)){
					l_name = l_tmp.erase(0, 7);
					l_monster->m_name = l_name;

					std::cout << l_name << std::endl;
				}

				else if (!(l_tmp.find("Type") == std::string::npos)){
					l_tmp = l_tmp.erase(0, 7);
					if (l_tmp.compare("Electric")){
						l_type = Monster::TYPE::electric;
					}
					else if (l_tmp.compare("Water")){
						l_type = Monster::TYPE::water;
					}
					else if (l_tmp.compare("Grass")){
						l_type = Monster::TYPE::grass;
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

					std::cout << l_type << std::endl;
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

					std::cout << "HP : " << l_min << " / " << l_max << std::endl;
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

					std::cout << "SPEED : " << l_min << " / " << l_max << std::endl;
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

					std::cout << "ATTACK : " << l_min << " / " << l_max << std::endl;
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

					std::cout << "DEFENSE : " << l_min << " / " << l_max << std::endl;
				}

				else if (!(l_tmp.find("Paralysis") == std::string::npos)){
					l_Sparalysis = l_tmp.erase(0, 12);
					std::cout << l_Sparalysis << std::endl;
					l_paralysis = std::stof(l_Sparalysis.c_str());

					l_monster->m_paralysis = l_paralysis;

					std::cout << "Paralysis : " << l_paralysis << std::endl;
				}

				else if (!(l_tmp.find("Flood") == std::string::npos)){
					l_Sflood = l_tmp.erase(0, 8);
					l_flood = std::stof(l_Sflood.c_str());

					l_monster->m_flood = l_flood;

					std::cout << "Flood : " << l_flood << std::endl;
				}

				else if (!(l_tmp.find("Fall") == std::string::npos)){
					l_Sfall = l_tmp.erase(0, 7);
					l_fall = std::stof(l_Sfall.c_str());

					l_monster->m_fall = l_fall;

					std::cout << "Fall : " << l_fall << std::endl;
				}

				else if (!(l_tmp.find("Burn") == std::string::npos)){
					l_Sburn = l_tmp.erase(0, 7);
					l_burn = std::stof(l_Sburn.c_str());

					l_monster->m_burn = l_burn;

					std::cout << "Burn : " << l_burn << std::endl;
				}

				else if (!(l_tmp.find("Protect") == std::string::npos)){
					l_Sprotect = l_tmp.erase(0, 10);
					l_protect = std::stof(l_Sprotect.c_str());

					l_monster->m_protect = l_protect;

					std::cout << "Protect : " << l_protect << std::endl;
				}

				else if (!(l_tmp.find("Heal") == std::string::npos)){
					l_Sheal = l_tmp.erase(0, 7);
					l_heal = std::stof(l_Sheal.c_str());

					l_monster->m_heal = l_heal;

					std::cout << "Heal : " << l_heal << std::endl;
				}

				else if (!(l_tmp.find("Poison") == std::string::npos)){
					l_Spoison = l_tmp.erase(0, 9);
					l_poison = std::stof(l_Spoison.c_str());

					l_monster->m_poison = l_poison;

					std::cout << "Poison : " << l_poison << std::endl;
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
					std::cout << l_name << std::endl;
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

					std::cout << l_type << std::endl;
				}

				else if (!(l_tmp.find("Power") == std::string::npos)){
					l_sPower = l_tmp.erase(0, 7);
					l_power = atoi(l_sPower.c_str());

					std::cout << l_power << std::endl;
				}

				else if (!(l_tmp.find("NbUse") == std::string::npos)){
					l_sNbUse = l_tmp.erase(0, 7);
					l_nbUse = atoi(l_sNbUse.c_str());

					std::cout << l_nbUse << std::endl;
				}

				else if (!(l_tmp.find("Fail") == std::string::npos)){
					l_sFail = l_tmp.erase(0, 7);
					l_fail = std::stof(l_sFail.c_str());

					std::cout << l_fail << std::endl;
				}

			} while (l_tmp != "EndAttack" );
			CAttack l_attack(l_name, l_type, l_nbUse, l_power, l_fail);
			m_tabAttacks.push_back(l_attack);
		}
	}
}

void CParse::parseObjects(std::string m_path){
	std::string l_tmp1, l_tmp, l_type, l_name, l_sHeal;
	int l_heal;

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

					std::cout << l_name << std::endl;
				}

				else if (!(l_tmp.find("Type") == std::string::npos)){
					l_type = l_tmp.erase(0, 6);

					std::cout << l_type << std::endl;
				}

				else if (!(l_tmp.find("Heal") == std::string::npos)){
					l_sHeal = l_tmp.erase(0, 6);
					l_heal = atoi(l_sHeal.c_str());

					std::cout << "Heal : " << l_heal << std::endl;
				}

			} while (l_tmp != "EndObject");

			CObject l_object(l_name);

			if (l_type == "Potion"){
				//l_object.setHeal(l_heal);
			}

			m_tabObjects.push_back(l_object);
		}
	}
}