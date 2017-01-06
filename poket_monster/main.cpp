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
	std::vector<CMonster*> l_pokedex;
	std::vector<CMonster*>::iterator l_it;

	l_parse.parseMonsters("monsters.pkmn");
	l_parse.parseAttack("attacks.pkmn");
	l_parse.parseObjects("objects.pkmn");
	l_parse.info();

	l_pokedex = l_parse.createMonsterVector(4);

	for (l_it = l_pokedex.begin(); l_it != l_pokedex.end(); ++l_it){
		std::cout << "________________" << std::endl;
		std::cout << "\t[ " << std::distance(l_pokedex.begin(), l_it) << " ]\n";
		(*l_it)->info();
		(*l_it)->attacksInfo();
		std::cout << "________________" << std::endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}