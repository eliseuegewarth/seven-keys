/*
 * Implementação da classe que representa um evento de botão do mouse.
 *
 * Autor: Edson Alves
 * Data: 22/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include <cassert>
#include "core/mousebuttonevent.h"

#include <cassert>

MouseButtonEvent::MouseButtonEvent(ButtonState state, Button button,
                                    double x, double y)
{
<<<<<<< HEAD
    assert((state >= 0) && "state can't be negative");
    assert((button >= 0) && "button can't be negative");
=======
>>>>>>> 85623008be19eac48dda5c16137aebaefcac4bd2
    m_state = state;
    m_button = button;
    m_x = x;
    m_y = y;
}

MouseButtonEvent::ButtonState
MouseButtonEvent::state() const
{
    return m_state;
}

MouseButtonEvent::Button
MouseButtonEvent::button() const
{
    return m_button;
}

double
MouseButtonEvent::x() const
{
    return m_x;
}

double
MouseButtonEvent::y() const
{
    return m_y;
}

MouseButtonEvent
MouseButtonEvent::from_SDL(const SDL_Event& event)
{
    MouseButtonEvent::ButtonState state = (event.type == SDL_MOUSEBUTTONDOWN ?
        MouseButtonEvent::PRESSED : MouseButtonEvent::RELEASED);

    MouseButtonEvent::Button button;

    switch (event.button.button)
    {
    case SDL_BUTTON_LEFT:
        button = MouseButtonEvent::LEFT;
        break;

    case SDL_BUTTON_RIGHT:
        button = MouseButtonEvent::RIGHT;
        break;

    case SDL_BUTTON_MIDDLE:
        button = MouseButtonEvent::MIDDLE;
        break;
    }

    return MouseButtonEvent(state, button, event.button.x, event.button.y);
}
