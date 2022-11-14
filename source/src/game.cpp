#include <SDL2/SDL.h>
#include <algorithm>
#include "graphics.h"
#include "game.h"
#include "input.h"

/* Game Class
 * Class holds all information for main game loop
 */

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 1000/FPS;
}

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game(){

}

void Game::gameLoop(){
	Graphics graphics;
	Input input;
	SDL_Event event;

	// Initialize latest time for loop use
	int latest_time = SDL_GetTicks();

// Begin loop
	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN){
				if (event.key.repeat == 0){
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP){
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT){
				return;
			}
		}

		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)){
			return;
		}

		const int current_time = SDL_GetTicks(); // Current time in milliseconds
		int elapsed_time = current_time - latest_time;
		this->update(std::min(elapsed_time, MAX_FRAME_TIME));
		latest_time = current_time;
	}
}

void Game::draw(Graphics &graphics){

}

void Game::update(float elapsedTime){

}
