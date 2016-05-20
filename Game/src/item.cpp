#include <iostream>
#include <core/image.h>
#include <core/keyboardevent.h>
#include <core/environment.h>
#include <cassert>

#include "item.h"

/**
 * item.cpp
 * @brief [Class that implements item objects from the game]
 * Licença: LGPL. Sem copyright.
 */

Item::Item(Object *parent, ObjectID id, const string& path, double x,
 double y, double mass, bool walkable)
    : Image(parent, id, path)
{
    assert(parent != NULL && "Failed to pick up the instance of Object");
    assert(ObjectID != NULL && "Failed to pick up the instance of ObjectID");
    assert(path != NULL && "Path not found.");

    set_position(x, y);
    set_walkable(walkable);
    set_mass(mass);
}
