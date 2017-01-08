#include "graphic.hpp"


void CGraphic::displayHeader(std::string m_path){
	std::string l_tmp;
	std::fstream l_file(m_path.c_str(), std::ios::in);

	if (!l_file){
		std::cerr << "Error while oppening" << std::endl;
	}

	while (!l_file.eof()){
		std::getline(l_file, l_tmp);
		std::cout << l_tmp << std::endl;
	}
	l_file.close();
}

void CGraphic::displayMenu(){

}

