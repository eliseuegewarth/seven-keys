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

/**
 * [MouseButtonEvent::MouseButtonEvent description]
 * @method MouseButtonEvent::MouseButtonEvent
 * @param  x                    [Mouse position in axis x(horizontal)]
 * @param  y                    [Mouse position in axis y(vertical)]
 * @param  state                 [State of the button (if are pressed or not)]
 * @param  button                [Button that are pressed]
 */
MouseButtonEvent::MouseButtonEvent(ButtonState state, Button button,
                                    double x, double y)
{
    assert((state >= 0) && "state can't be negative");
    assert((button >= 0) && "button can't be negative");

    m_state = state;
    m_button = button;
    m_x = x;
    m_y = y;
}

/**
 * [MouseButtonEvent::state             State of the buttons,
 * 									 	if it is pressed or not]
 * @method MouseMotionEvent::state
 * @return                         [Return the state of button]
 */
MouseButtonEvent::ButtonState
MouseButtonEvent::state() const
{
    return m_state;
}

/**
 * [MouseButtonEvent::button                Button that are pressed]
 * @method MouseButtonEvent::button
 * @return                                  [Return the button that is pressed]
 */
MouseButtonEvent::Button
MouseButtonEvent::button() const
{
    return m_button;
}

/**
 * [MouseButtonEvent::x         position where the mouse button was
 * 					 			pressed on the screen in axis x(horizontal)]
 * @method MouseButtonEvent::x
 * @return                  [Returns the mouse position in axis x(horizontal)]
 */
double MouseButtonEvent::x() const
{
    return m_x;
}

/**
 * [MouseButtonEvent::x             position where the mouse button was
 * 					 				pressed on the screen in axis y(vertical)]
 * @method MouseButtonEvent::x
 * @return                   [[Returns the mouse position in axis y(vertical)]
 */
double MouseButtonEvent::y() const
{
    return m_y;
}

/**
 * [MouseButtonEvent::from_SDL      Reads the state of the buttons from the
 * 							   		SDL library and returns the states for class]
 * @method MouseButtonEvent::from_SDL
 * @param  event                      [mouse event detected by the SDL library]
 * @return                            [mouse buttons event]
 */
MouseButtonEvent MouseButtonEvent::from_SDL(const SDL_Event& event)
{
    MouseButtonEvent::ButtonState state = MouseButtonEvent::PRESSED;
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        state = MouseButtonEvent::PRESSED;
    }else
    {
        state = MouseButtonEvent::RELEASED;
    }

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
