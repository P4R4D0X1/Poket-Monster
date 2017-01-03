#include "parse.hpp"

CParse::CParse(){
}

void CParse::parseMonsters(std::string m_path){
	std::string l_tmp, l_type, l_name, l_hp, l_speed;


	std::fstream l_file(m_path.c_str(), std::ios::in);
	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
		return;
	}

	while (!l_file.eof()){
		std::getline(l_file, l_tmp);

		if (l_tmp == "Monster"){
			CMonster l_monster;

			std::getline(l_file, l_tmp);
			if (l_tmp == "EndMonster"){
				return;
			}
			
			/*l_tmp = "Name boreal"

			else if ( l_tmp.find("Name") ){
				std::cout << "OKAY" << std::endl;
			}*/


		}

	}

}