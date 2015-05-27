#ifndef ROOM_H
#define ROOM_H

#include <core/object.h>

class Room: public Object
{
public:
	Room(Object *parent, ObjectID id, string type = "None");

	Room *r_left;
	Room *r_right;
	Room *r_top;
	Room *r_botton;

	string type;

	void check_entry();
	string room_type();
private:
	void draw_id(Room *,Room *, int, int);
	void draw_self();
	void draw_itens(Room *);
	
};

#endif