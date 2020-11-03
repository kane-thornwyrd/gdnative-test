#include "datatable.h"


using namespace godot;

void Datatable::_register_methods() {
	register_method("_process", &Datatable::_process);
	register_property<Datatable, float>("amplitude", &Datatable::amplitude, 10.0);
	register_property<Datatable, float>("speed", &Datatable::set_speed, &Datatable::get_speed, 1.0);

	register_signal<Datatable>((char *)"position_changed", "node", GODOT_VARIANT_TYPE_OBJECT, "new_pos", GODOT_VARIANT_TYPE_VECTOR2);
}

Datatable::Datatable() {
}

Datatable::~Datatable() {
	// add your cleanup here
}

void Datatable::_init() {
	// initialize any variables here
	time_passed = 0.0;
	amplitude = 10.0;
	speed = 1.0;
}

void Datatable::_process(float delta) {
	time_passed += speed * delta;

	Vector2 new_position = Vector2(
		amplitude + (amplitude * sin(time_passed * 2.0)),
		amplitude + (amplitude * cos(time_passed * 1.5))
	);

	set_position(new_position);

	time_emit += delta;
	if (time_emit > 1.0) {
		emit_signal("position_changed", this, new_position);

		time_emit = 0.0;
	}
}

void Datatable::set_speed(float p_speed) {
	speed = p_speed;
}

float Datatable::get_speed() {
	return speed;
}