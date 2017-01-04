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
		sleep,
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

#endif