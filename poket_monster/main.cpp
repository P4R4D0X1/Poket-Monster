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
#include "player.hpp"

using namespace std;

int main(int argc, char **argv){

	CParse l_parse;
	CPlayer *l_playerOne, *l_playerTwo;
	CArena l_arena;

	l_parse.parseMonsters("monsters.pkmn");
	l_parse.parseAttack("attacks.pkmn");
	l_parse.parseObjects("objects.pkmn");

	l_playerOne = new CPlayer("PARADOX", l_parse.createMonsterVector(4), l_parse.createObjectVector(4));
	l_playerTwo = new CPlayer("KERA", l_parse.createMonsterVector(4), l_parse.createObjectVector(4));

	while (1){
		l_playerOne->chooseAction(*l_playerTwo, l_arena);
		l_playerTwo->chooseAction(*l_playerOne, l_arena);
	}

	system("pause");
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}