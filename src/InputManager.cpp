#include "InputManager.h"

Vector2 InputManager::GetMousePosition()
{
    Vector2 mousePos;
    SDL_GetMouseState(&mousePos.x, &mousePos.y);
    return mousePos;
}