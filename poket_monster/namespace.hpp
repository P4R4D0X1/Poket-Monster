#ifndef NAMESPACE_HPP_INCLUDE
#define NAMESPACE_HPP_INCLUDE

namespace Attack{
	enum TYPE{
		electric,
		water,
		rock,
		fire,
		grass,
		normal
	};

	enum STATE{
		success,
		fallen
	};
}

namespace Monster{
	enum TYPE{
		electric,
		water,
		rock,
		fire,
		grass
	};

	enum STATE{
		feelgood,
		poisoned,
		paralized,
		burned, 
		freezed, 
		asleep,
		confusion,

	};

	enum ATTACK_SLOT{
		first,
		second,
		third,
		fourth
	};
}

namespace Arena{
	enum STATE{
		normal,
		flooded
	};
}

namespace Potion{
	enum TYPE{
		potion,
		superPotion,
		hyperPotion,
		maxPotion,
		fullRestore
	};
}

namespace Object{
	enum TYPE{
		potion,
		drug
	};
}

namespace Drug{
	enum TYPE{
		burnHeal,
		iceHeal,
		antidote,
		paralizeHeal,
		awakening
	};
}

#endif