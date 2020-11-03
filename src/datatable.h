#ifndef Datatable_H
#define Datatable_H

#include <Godot.hpp>
#include <Sprite.hpp>

namespace godot {

class Datatable : public Sprite {
	GODOT_CLASS(Datatable, Sprite)

private:
	float time_passed;
	float time_emit;
	float amplitude;
	float speed;

public:
	static void _register_methods();

	Datatable();
	~Datatable();

	void _init(); // our initializer called by Godot

	void _process(float delta);
	void set_speed(float p_speed);
	float get_speed();
};

}

#endif