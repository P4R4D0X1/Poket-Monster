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
#include <thread>
#include <SFML/Window.hpp>

#include "parse.hpp"
#include "player.hpp"
#include "graphic.hpp"

using namespace std;

int main(int argc, char **argv){

	CParse l_parse;
	CPlayer *l_playerOne, *l_playerTwo, *l_actualPlayer;
	CArena l_arena;
	CGraphic l_graphic;

	l_parse.parseMonsters("monsters.pkmn");
	l_parse.parseAttack("attacks.pkmn");
	l_parse.parseObjects("objects.pkmn");

	l_playerOne = new CPlayer("PARADOX", l_parse.createMonsterVector(1), l_parse.createObjectVector(4));
	l_playerTwo = new CPlayer("KERA", l_parse.createMonsterVector(1), l_parse.createObjectVector(4));

	l_actualPlayer = l_playerOne;

	while (1)
	{
		if (l_actualPlayer == l_playerOne && l_playerOne->showMenu(*l_playerTwo, l_arena, l_graphic))
			l_actualPlayer = l_playerTwo;
		else if (l_actualPlayer == l_playerTwo && l_playerTwo->showMenu(*l_playerOne, l_arena, l_graphic))
			l_actualPlayer = l_playerOne;

		if (!l_actualPlayer->isOperational()){
			std::cout << l_actualPlayer->getName() << " IS DEAD ! \n";
			break;
		}
		l_graphic.update();
	}


	system("pause");
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}