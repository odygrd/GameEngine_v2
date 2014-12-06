#ifndef CORE_GAME_H
#define CORE_GAME_H

class Game
{
public:
	Game(){}
	virtual ~Game(){}

	virtual auto Init() -> void {}
private:
	//Disallowed Methods
	Game(const Game&);
	Game& operator= (const Game&);
};

#endif