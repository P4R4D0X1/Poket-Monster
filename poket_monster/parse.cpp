#include "parse.hpp"

CParse::CParse(){
}

void CParse::parseMonsters(std::string m_path){
	std::string l_tmp1, l_tmp, l_hp, l_speed, l_attack, l_defense, l_type, l_name, l_Smin, l_Smax, m_path = "monsters.pkmn", l_Sparalysis, l_Sfall, l_Sflood, l_Sburn, l_Sprotect, l_Sheal, l_Spoison;
	int l_min, l_max;
	float l_paralysis, l_fall, l_flood, l_burn, l_heal, l_protect, l_poison;

	std::fstream l_file(m_path.c_str(), std::ios::in);

	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
	}

	while (!l_file.eof()){

		std::getline(l_file, l_tmp1);
		if (l_tmp1 == "Monster"){

			do {
				std::getline(l_file, l_tmp);

				if (!(l_tmp.find("Name") == std::string::npos)){
					l_name = l_tmp.erase(0, 7);
					std::cout << l_name << std::endl;
				}

				else if (!(l_tmp.find("Type") == std::string::npos)){
					l_type = l_tmp.erase(0, 7);
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

					std::cout << "DEFENSE : " << l_min << " / " << l_max << std::endl;
				}

				else if (!(l_tmp.find("Paralysis") == std::string::npos)){
					l_Sparalysis = l_tmp.erase(0, 12);
					std::cout << l_Sparalysis << std::endl;
					l_paralysis = std::stof(l_Sparalysis.c_str());

					std::cout << "Paralysis : " << l_paralysis << std::endl;
				}

				else if (!(l_tmp.find("Flood") == std::string::npos)){
					l_Sflood = l_tmp.erase(0, 8);
					l_flood = std::stof(l_Sflood.c_str());

					std::cout << "Flood : " << l_flood << std::endl;
				}

				else if (!(l_tmp.find("Fall") == std::string::npos)){
					l_Sfall = l_tmp.erase(0, 7);
					l_fall = std::stof(l_Sfall.c_str());

					std::cout << "Fall : " << l_fall << std::endl;
				}

				else if (!(l_tmp.find("Burn") == std::string::npos)){
					l_Sburn = l_tmp.erase(0, 7);
					l_burn = std::stof(l_Sburn.c_str());

					std::cout << "Burn : " << l_burn << std::endl;
				}

				else if (!(l_tmp.find("Protect") == std::string::npos)){
					l_Sprotect = l_tmp.erase(0, 10);
					l_protect = std::stof(l_Sprotect.c_str());

					std::cout << "Protect : " << l_protect << std::endl;
				}

				else if (!(l_tmp.find("Heal") == std::string::npos)){
					l_Sheal = l_tmp.erase(0, 7);
					l_heal = std::stof(l_Sheal.c_str());

					std::cout << "Heal : " << l_heal << std::endl;
				}

				else if (!(l_tmp.find("Poison") == std::string::npos)){
					l_Spoison = l_tmp.erase(0, 9);
					l_poison = std::stof(l_Spoison.c_str());

					std::cout << "Poison : " << l_poison << std::endl;
				}

			} while (l_tmp != "EndMonster");
		}

	}

}

void CParse::parseAttack(std::string m_path){
	std::string l_tmp1, l_tmp, l_type, l_name, m_path = "attacks.pkmn", l_sPower, l_sNbUse, l_sFail;
	int l_min, l_max;
	float l_paralysis, l_fall, l_flood, l_burn, l_heal, l_protect, l_poison, l_power, l_nbUse, l_fail;

	std::fstream l_file(m_path.c_str(), std::ios::in);

	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
	}

	while (!l_file.eof()){
		std::getline(l_file, l_tmp1);
		if (l_tmp1 == "Attack"){
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
		}
	}
}