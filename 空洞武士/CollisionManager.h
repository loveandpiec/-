#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "collision_box.h"

#include <vector>

class CollisionManager
{
public:
	static CollisionManager* instance();

	CollisionBox* create_collision_box();
	void destroy_collision_box(CollisionBox* collision_box);

	void process_collide();
	void on_debug_render();

private:
	static CollisionManager* manager;

	std::vector<CollisionBox*>collision_box_list;

private:
	CollisionManager();
	~CollisionManager();
};

#endif // !COLLISION_MANAGER_H
