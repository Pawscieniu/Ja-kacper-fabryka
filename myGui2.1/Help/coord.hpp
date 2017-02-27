#ifndef mGUIcoord

#define mGUIcoord

namespace mGUI{
	struct Coord{
		int x;
		int y;
		Coord(int x, int y) : x(x), y(y) {};
		Coord(sf::Vector2i vec) : x(vec.x), y(vec.y) {};
	};
}

#endif

