#include "parse.hpp"
#include "vectorUtils.hpp"

CParse::CParse(){
}

CParse::~CParse(){
	while (!m_tabMonsters.empty()){
		delete m_tabMonsters.back();
		m_tabMonsters.pop_back();
	}

	while (!m_tabAttacks.empty()){
		delete m_tabAttacks.back();
		m_tabAttacks.pop_back();
	}

	while (!m_tabObjects.empty()){
		delete m_tabObjects.back();
		m_tabObjects.pop_back();
	}
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

	std::cout << "[PARSING MONSTERS]" << std::endl;
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

					if (l_tmp.compare("Electric") == 0){
						l_type = Monster::TYPE::electric;
					}
					else if (l_tmp.compare("Water") == 0){
						l_type = Monster::TYPE::water;
					}
					else if (l_tmp.compare("Plant") == 0){
						l_type = Monster::TYPE::plant;
					}
					else if (l_tmp.compare("Insect") == 0){
						l_type = Monster::TYPE::insect;
					}
					else if (l_tmp.compare("Fire") == 0){
						l_type = Monster::TYPE::fire;
					}
					else if (l_tmp.compare("Rock") == 0){
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
	int l_power, l_nbUse;
	float l_fail;
	Attack::TYPE l_type;

	std::fstream l_file(m_path.c_str(), std::ios::in);

	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
	}

	std::cout << "[PARSING ATTACKS]" << std::endl;
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
					l_tmp = l_tmp.erase(0, 6);

					if (l_tmp.compare("Electric") == 0){
						l_type = Attack::TYPE::electric;
					}
					else if (l_tmp.compare("Water") == 0){
						l_type = Attack::TYPE::water;
					}
					else if (l_tmp.compare("Grass") == 0){
						l_type = Attack::TYPE::grass;
					}
					else if (l_tmp.compare("Fire") == 0){
						l_type = Attack::TYPE::fire;
					}
					else if (l_tmp.compare("Rock") == 0){
						l_type = Attack::TYPE::rock;
					}
					else if (l_tmp.compare("Normal") == 0){
						l_type = Attack::TYPE::normal;
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
	int l_heal;
	std::string l_line, l_name, l_sHeal;
	Object::TYPE l_type;
	Potion::TYPE l_potionType;
	Drug::TYPE l_drugType;
	CObject *l_object(NULL);
	std::fstream l_file(m_path.c_str(), std::ios::in);

	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
		return;
	}

	std::cout << "[PARSING OBJECTS]" << std::endl;

	while (!l_file.eof()){
		std::getline(l_file, l_line);

		if (!l_line.compare("Object")){
			l_object = NULL;

			do {
				std::getline(l_file, l_line);

				if (l_line.find("Name") != std::string::npos){
					l_name = l_line.erase(0, 6);
				}
				else if (l_line.find("Type") != std::string::npos){
					l_line = l_line.erase(0, 6);

					if (!l_line.compare("Potion")){
						l_type = Object::TYPE::potion;
					}
					else if (!l_line.compare("Drug")){
						l_type = Object::TYPE::drug;
					}
					else{
						std::cerr << "ERROR PARSING TYPEEEEEE" << std::endl;
					}
				}
				else if (l_line.find("Objectype") != std::string::npos) {
					l_line = l_line.erase(0, 11);

					if (!l_line.compare("potion")){
						l_potionType = Potion::TYPE::potion;
					}
					else if (!l_line.compare("superPotion")){
						l_potionType = Potion::TYPE::superPotion;
					}
					else if (!l_line.compare("hyperPotion")){
						l_potionType = Potion::TYPE::hyperPotion;
					}
					else if (!l_line.compare("maxPotion")){
						l_potionType = Potion::TYPE::maxPotion;
					}
					else if (!l_line.compare("fullRestore")){
						l_potionType = Potion::TYPE::fullRestore;
					}
					else if (!l_line.compare("burnHeal")){
						l_drugType = Drug::TYPE::burnHeal;
					}
					else if (!l_line.compare("iceHeal")){
						l_drugType = Drug::TYPE::iceHeal;
					}
					else if (!l_line.compare("antidote")){
						l_drugType = Drug::TYPE::antidote;
					}
					else if (!l_line.compare("paralizeHeal")){
						l_drugType = Drug::TYPE::paralizeHeal;
					}
					else if (!l_line.compare("awakening")){
						l_drugType = Drug::TYPE::awakening;
					}
					else{
						std::cerr << "ERROR PARSING OBJECT TYPE" << std::endl;
					}
				}
				else if (l_line.find("Heal") != std::string::npos){
					l_sHeal = l_line.erase(0, 6);
					l_heal = atoi(l_sHeal.c_str());
				}

			} while (l_line.compare("EndObject"));
			
			if (l_type == Object::TYPE::potion){
				l_object = new CPotion(l_name, l_heal, l_potionType);
			}
			else if (l_type == Object::TYPE::drug){
				l_object = new CDrug(l_name, l_drugType);
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
	switch (p_monster->m_type){
		case (Monster::TYPE::electric) :
			std::cout << "Paralysis : " << p_monster->m_paralysis << std::endl;
			break;

		case Monster::TYPE::water:
			std::cout << "Flood : " << p_monster->m_flood << std::endl;
			std::cout << "Fall : " << p_monster->m_fall << std::endl;
			break;

		case Monster::TYPE::rock:
			std::cout << "Protect : " << p_monster->m_protect << std::endl;
			break;

		case Monster::TYPE::fire:
			std::cout << "Burn : " << p_monster->m_burn << std::endl;
			break;

		case Monster::TYPE::insect:
			std::cout << "Poison : " << p_monster->m_poison << std::endl;
			break;

		case Monster::TYPE::plant:
			std::cout << "Heal : " << p_monster->m_heal << std::endl;
			break;
	}
}

void CParse::info(){
	unsigned int i;
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
				(*m_tabObjects[i]).info();
				std::cout << std::endl;
	}
}

std::vector<CMonster*> CParse::createMonsterVector(int p_monsterAmount){
	//on abesoin d'un constructeur qui prend en parametre un vector pour monster
	CMonster *l_monster;
	std::vector<sMonster*>::iterator l_it;
	std::vector<sMonster*> l_monsters;
	std::vector<CMonster*> l_vector;

	l_monsters = m_tabMonsters;
	
	while (p_monsterAmount > 0 && l_monsters.size()){
		//On choisit une attaque aléatoirement et on utilise le constructeur de copie de attack pour l'ajouter au tableau d'attaque
		l_it = select_randomly(l_monsters.begin(), l_monsters.end());
		l_monster = createMonster(*l_it);
		l_vector.push_back(l_monster);
		l_monsters.erase(l_it);

		p_monsterAmount--;
	}

	return l_vector;
}

std::vector<CObject*> CParse::createObjectVector(int p_objectAmount){
	CObject *l_object;
	std::vector<CObject*>::iterator l_it;
	std::vector<CObject*> l_objects, l_vector;

	l_objects = m_tabObjects;

	while (p_objectAmount > 0 && l_objects.size()){
		//On choisit un objet aléatoirement et on utilise le constructeur de copie pour ajouter l'objet au vector
		l_it = select_randomly(l_objects.begin(), l_objects.end());
		l_object = new CObject(**l_it);
		l_vector.push_back(l_object);
		l_objects.erase(l_it);

		p_objectAmount--;
	}

	return l_vector;
}

std::vector<CAttack*> CParse::createAttackVector(int p_attackAmount, Attack::TYPE p_type){
	CAttack *l_attack;
	std::vector<CAttack*>::iterator l_it;
	std::vector<CAttack*> l_attacks, l_vector;

	//On remplit un vector avec les adresses de toutes les attaques du type souhaité/normal
	for (l_it = m_tabAttacks.begin(); l_it != m_tabAttacks.end(); ++l_it){
		if ((*l_it)->getType() == Attack::TYPE::normal || (*l_it)->getType() == p_type)
			l_attacks.push_back(*l_it);
	}

	while (p_attackAmount > 0 && l_attacks.size()){
		//On choisit une attaque aléatoirement et on utilise le constructeur de copie de attack pour l'ajouter au tableau d'attaque
		l_it = select_randomly(l_attacks.begin(), l_attacks.end());
		l_attack = new CAttack(**l_it);
		l_vector.push_back(l_attack);
		l_attacks.erase(l_it);

		p_attackAmount--;
	}

	return l_vector;
}

CMonster* CParse::createMonster(sMonster* p_monster){
	int l_hp, l_speed, l_attack, l_defense;
	CMonster *l_monster(NULL);
	std::default_random_engine generator;

	std::uniform_int_distribution<int> distributionHp(p_monster->m_hpMin, p_monster->m_hpMax );
	l_hp = distributionHp(generator);

	std::uniform_int_distribution<int> distributionSpeed(p_monster->m_speedMin, p_monster->m_speedMax);
	l_speed = distributionSpeed(generator);

	std::uniform_int_distribution<int> distributionAttack(p_monster->m_attackMin, p_monster->m_attackMax);
	l_attack = distributionAttack(generator);

	std::uniform_int_distribution<int> distributionDefense(p_monster->m_defenseMin, p_monster->m_defenseMax);
	l_defense = distributionDefense(generator);

	switch (p_monster->m_type){
		case Monster::TYPE::electric:
			l_monster = new CElectric(p_monster->m_name, l_hp, l_hp, l_speed, l_attack, l_defense, p_monster->m_paralysis, createAttackVector(4, Attack::TYPE::electric));
			break;

		case Monster::TYPE::water:
			l_monster = new CWater(p_monster->m_name, l_hp, l_hp, l_speed, l_attack, l_defense, p_monster->m_flood, p_monster->m_fall, createAttackVector(4, Attack::TYPE::water));
			break;

		case Monster::TYPE::rock:
			l_monster = new CRock(p_monster->m_name, l_hp, l_hp, l_speed, l_attack, l_defense, p_monster->m_protect, createAttackVector(4, Attack::TYPE::rock));
			break;

		case Monster::TYPE::fire:
			l_monster = new CFire(p_monster->m_name, l_hp, l_hp, l_speed, l_attack, l_defense, p_monster->m_burn, createAttackVector(4, Attack::TYPE::fire));
			break;

		case Monster::TYPE::insect:
			l_monster = new CInsect(p_monster->m_name, l_hp, l_hp, l_speed, l_attack, l_defense, p_monster->m_poison, createAttackVector(4, Attack::TYPE::grass));
			break;

		case Monster::TYPE::plant:
			l_monster = new CPlant(p_monster->m_name, l_hp, l_hp, l_speed, l_attack, l_defense, p_monster->m_heal, createAttackVector(4, Attack::TYPE::grass));
			break;

		default:
			std::cerr << "ERROR CREATING MONSTER" << std::endl;
			break;
	}

	return l_monster;
}