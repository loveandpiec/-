#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include "Character.h"

class CharacterManager
{
public:
	static CharacterManager* instance();

	Character* get_enemy() 
	{ 
		return enemy; 
	}
	Character* get_player() 
	{
		return player; 
	}

	void on_input(const ExMessage& msg);
	void on_update(float delta);
	void on_render();

private:
	static CharacterManager* manager;

	Character* enemy = nullptr;
	Character* player = nullptr;

private:
	CharacterManager();
	~CharacterManager();
};

#endif // !CHARACTER_MANAGER