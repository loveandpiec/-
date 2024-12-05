#ifndef _ENEMY_H
#define _ENEMY_H

#include "Barb.h"
#include "Sword.h"
#include "Character.h"


class Enemy :public Character
{
public:
	Enemy();
	~Enemy();

	void on_update(float delta) override;
	void on_render()override;

	void on_hurt()override;

	void set_facing_left(bool flag)
	{
		is_facing_left = flag;
	} 
	
	bool get_facing_left()const
	{
		return is_facing_left;
	}

	void set_dashing_in_air(bool flag)
	{
		is_dashing_in_air = flag;
	}

	bool get_dashing_in_air()const
	{
		return is_dashing_in_air;
	}

	void set_dashing_on_floor(bool flag)
	{
		is_dashing_on_floor = flag;
	}

	bool get_dashing_on_floor()const
	{
		return is_dashing_on_floor;
	}

	void set_throwing_silk(bool flag)
	{
		is_throwing_silk = flag;
		collision_box_silk->set_enabled(flag);
	}

	bool get_throwing_silk()const
	{
		return is_throwing_silk;
	}

	void throw_babs();
	void throw_sword();

	void on_dash();
	void on_throw_silk();

private:
	bool is_throwing_silk = false;
	bool is_dashing_in_air = false;
	bool is_dashing_on_floor = false;

	Animation animation_silk;
	AnimationGroup animation_dash_in_air_vfx;
	AnimationGroup animation_dash_on_floor_vfx;
	Animation* current_dash_animation = nullptr;

	std::vector<Barb*> barb_list;
	std::vector<Sword*>sword_list;
	CollisionBox* collision_box_silk = nullptr;
};

#endif // !_ENEMY_H
