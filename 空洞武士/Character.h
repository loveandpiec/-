#ifndef CHARACTER_H
#define CHARACTER_H

#include "Vector2.h"
#include "animation.h"
#include "collision_box.h"
#include "StateMachine.h"

#include <string>
#include <graphics.h>
#include <unordered_map>

class Character
{
public:
	Character();
	~Character();

	void decrease_hp();

	int get_hp()const
	{
		return hp;
	}
	void set_position(const Vector2& position)
	{
		this->position = position;
	}
	const Vector2& get_position()const
	{
		return position;
	}
	void set_velocity(const Vector2& velocity)
	{
		this->velocity = velocity;
	}
	const Vector2& get_velocity()const
	{
		return velocity;
	}
	Vector2 get_logic_center()const
	{
		return Vector2(position.x, position.y - logic_height / 2);
	}
	void set_gravity_enabled(bool flag)
	{
		enable_gravity = flag;
	}
	CollisionBox* get_hit_box()
	{
		return hit_box;
	}
	CollisionBox* get_hurt_box()
	{
		return hurt_box;
	}
	bool is_on_floor()const
	{
		return position.y >= FLOOR_Y;
	}
	float get_floor_y()const
	{
		return FLOOR_Y;
	}
	void make_invulnerable()
	{
		is_invulnerable = true;
		timer_invunlunerable_status.restart();
	}
	virtual void on_input(const ExMessage& msg) {}
	virtual void on_update(float delta);
	virtual void on_render();

	virtual void on_hurt() {}

	void switch_state(const std::string& id);
	void set_animation(const std::string& id);

protected:
	struct AnimationGroup
	{
		Animation left;
		Animation right;
	};
protected:
	const float FLOOR_Y = 620;		// �ذ����ֱ��������
	const float GRAVITY = 980 * 2;	// ������С

protected:
	int hp = 10;													// ��ɫ����ֵ
	Vector2 position;												// ��ɫ�ŵ�λ��
	Vector2 velocity;												// ��ɫ�ٶ�
	float logic_height = 0;											// ��ɫ���߼��߶�
	bool is_facing_left = true;										// ��ǰ��ɫ�Ƿ�����
	StateMachine state_machine;										// ��ɫ�߼�״̬��
	bool enable_gravity = true;										// ��������ģ��
	bool is_invulnerable = false;									// ��ǰ�Ƿ��޵�
	Timer timer_invulunerable_blink;								// �޵���˸״̬��ʱ��
	Timer timer_invunlunerable_status;								// �޵�״̬��ʱ��
	bool is_blink_invisible = false;								// ��ǰ�Ƿ�����˸�Ĳ��ɼ�֡
	CollisionBox* hit_box = nullptr;								// ������ײ��
	CollisionBox* hurt_box = nullptr;								// �ܻ���ײ��
	AnimationGroup* current_animation = nullptr;					// ��ǰ��ɫ����
	std::unordered_map<std::string, AnimationGroup>animation_pool;	// ��ɫ������
};

#endif // !CHARACTER_H