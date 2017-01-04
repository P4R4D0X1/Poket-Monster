#include <iostream>
#include <string>

#include "parse.hpp"

/*
*
*	On fais une fonction getFourAttackByType() dans le parse
*	
*	Gerer le player
*	Gerer l'attribution des objets et des pokemon
*
*	coder la mecanique de jeu basique
*
*/


using namespace std;

int main(int argc, char **argv){

	CParse l_parse;

	l_parse.parseMonsters("monsters.pkmn");
	l_parse.parseAttack("attacks.pkmn");
	l_parse.parseObjects("objects.pkmn");

	system("pause");
	return EXIT_SUCCESS;
}