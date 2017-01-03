#ifndef PARSE_HPP_INCLUDE
#define PARSE_HPP_INCLUDE

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "monster.hpp"


class CParse{
	public:
		CParse();
		virtual ~CParse();

	protected:
		void parseMonsters(std::string m_path);
};

#endif