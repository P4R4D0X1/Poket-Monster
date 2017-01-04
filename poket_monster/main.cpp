#include <iostream>
#include <string>

#include "parse.hpp"


using namespace std;

int main(int argc, char **argv){

	CParse l_parse;

	l_parse.parseMonsters("monsters.pkmn");
	l_parse.parseAttack("attacks.pkmn");
	l_parse.parseObjects("objects.pkmn");

	system("pause");
	return EXIT_SUCCESS;
}