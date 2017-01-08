//                 uuuuuuu
//               uu$$$$$$$$$$$uu
//            uu$$$$$$$$$$$$$$$$$uu
//           u$$$$$$$$$$$$$$$$$$$$$u
//          u$$$$$$$$$$$$$$$$$$$$$$$u
//         u$$$$$$$$$$$$$$$$$$$$$$$$$u
//         u$$$$$$$$$$$$$$$$$$$$$$$$$u
//         u$$$$$$"   "$$$"   "$$$$$$u
//         "$$$$"      u$u       $$$$"
//          $$$u       u$u       u$$$
//          $$$u      u$$$u      u$$$
//           "$$$$uu$$$   $$$uu$$$$"
//            "$$$$$$$"   "$$$$$$$"
//              u$$$$$$$u$$$$$$$u
//               u$"$"$"$"$"$"$u
//    uuu        $$u$ $ $ $ $u$$       uuu
//   u$$$$        $$$$$u$u$u$$$       u$$$$
//    $$$$$uu      "$$$$$$$$$"     uu$$$$$$
//  u$$$$$$$$$$$uu    """""    uuuu$$$$$$$$$$
//  $$$$"""$$$$$$$$$$uuu   uu$$$$$$$$$"""$$$"
//   """      ""$$$$$$$$$$$uu ""$"""
//             uuuu ""$$$$$$$$$$uuu
//    u$$$uuu$$$$$$$$$uu ""$$$$$$$$$$$uuu$$$
//    $$$$$$$$$$""""           ""$$$$$$$$$$$"
//     "$$$$$"                      ""$$$$""
//       $$$"                         $$$$"

#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <string>

#include "parse.hpp"
#include "graphic.hpp"

using namespace std;

int main(int argc, char **argv){

	CGraphic l_graphic;
	CParse l_parse;
	vector<CMonster*> l_pokedex;
	vector<CMonster*>::iterator l_it;

	system("color 0E");

	l_graphic.displayHeader("head.pkmn");

	l_parse.parseMonsters("monsters.pkmn");
	l_parse.parseAttack("attacks.pkmn");
	l_parse.parseObjects("objects.pkmn");
	//l_parse.info();

	/*l_pokedex = l_parse.createMonsterVector(4);

	for (l_it = l_pokedex.begin(); l_it != l_pokedex.end(); ++l_it){
		cout << "________________" << endl;
		cout << "\n_________\n[MONSTER]\n_________\n\n";
		cout << "\t[ " << distance(l_pokedex.begin(), l_it) << " ]\n";
		(*l_it)->info();
		cout << "\n_________\n[ATTACKS]\n_________\n\n";
		(*l_it)->attacksInfo();
		cout << "________________" << endl;
	}*/

	system("pause");
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}