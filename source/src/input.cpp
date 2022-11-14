#include "input.h"

/* Input class
 * Used to track keyboard state
 */

// Reset key status every new frame
void Input::beginNewFrame(){
	this->_pressedkeys.clear();
	this->_releasedkeys.clear();

}

// Called when key is pressed
void Input::keyDownEvent(const SDL_Event& event){
	this->_pressedkeys[event.key.keysym.scancode] = true;
	this->_heldkeys[event.key.keysym.scancode] = true;
}

// Called when key is released
void Input::keyUpEvent(const SDL_Event& event){
	this->_releasedkeys[event.key.keysym.scancode] = true;
	this->_heldkeys[event.key.keysym.scancode] = false;
}

// Check if key was pressed in frame
bool Input::wasKeyPressed(SDL_Scancode key){
	return this->_pressedkeys[key];
}

// Check if key was released in frame
bool Input::wasKeyReleased(SDL_Scancode key){
	return this->_releasedkeys[key];
}

// Check if key is held
bool Input::isKeyHeld(SDL_Scancode key){
	return this->_heldkeys[key];
}
