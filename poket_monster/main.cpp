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

#include <iostream>
#include <string>

#include "parse.hpp"

using namespace std;

int main(int argc, char **argv){

	CParse l_parse;
	vector<CMonster*> l_pokedex;
	vector<CMonster*>::iterator l_it;

	l_parse.parseMonsters("monsters.pkmn");
	l_parse.parseAttack("attacks.pkmn");
	l_parse.parseObjects("objects.pkmn");
	l_parse.info();

	l_pokedex = l_parse.createMonsterVector(4);

	for (l_it = l_pokedex.begin(); l_it != l_pokedex.end(); ++l_it){
		cout << "________________" << endl;
		cout << "\n_________\n[MONSTER]\n_________\n\n";
		cout << "\t[ " << distance(l_pokedex.begin(), l_it) << " ]\n";
		(*l_it)->info();
		cout << "\n_________\n[ATTACKS]\n_________\n\n";
		(*l_it)->attacksInfo();
		cout << "________________" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}