#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <numeric>

#include "vector.cpp"
#include "scene.h"
#include "tilemap.h"
#include "input.cpp"
#include "object.cpp"

#define dc color(128, 0, 0, 255)

float msec = 0;
float fps = 0;
float frame_start;

void init_sdl();

object camera;
box_shape player(vector2(50, 50), vector2(8, 8), dc);

int main() {
	init_sdl();

	scene main_scene(720, 480, 2);
	input main_input;

	tile def_tile(dc);
	tile player_tile(color(32, 32, 32, 255));
	tile_map map(vector2(-30, -30), vector2i(3233, 3233), vector2i(16, 16), def_tile);
	
	for (int i = 0; i < map.size.x; i++) {
		for (int j = 0; j < map.size.y; j++) {
			map.set_tile(tile(color(rand()%255, rand()%255, rand()%255, 255)), vector2i(i, j));
		}
	}
	
	vector2i mouse_pos;
	while(true) {
		mouse_pos = main_scene.get_mouse_position();
		//player.position = vector2(camera.position.x * -1, camera.position.y * -1);
		
		frame_start = SDL_GetTicks();

		main_scene.set_camera_position(camera.position);

		map.draw_full_tilemap(&main_scene);

		player.draw(&main_scene);

		main_scene.draw_buffer();
		main_scene.clear();
		main_scene.clear_buffer();

		if (main_input.is_key_pressed(SDL_SCANCODE_W)) {
			camera.position.y += 1;
		}
		if (main_input.is_key_pressed(SDL_SCANCODE_S)) {
			camera.position.y -= 1;
		}
		if (main_input.is_key_pressed(SDL_SCANCODE_A)) {
			camera.position.x += 1;
		}
		if (main_input.is_key_pressed(SDL_SCANCODE_D)) {
			camera.position.x -= 1;
		}
		if (main_input.is_key_pressed(SDL_SCANCODE_F)) {
			map.set_tile(player_tile, map.global_to_map(mouse_pos.x, mouse_pos.y, main_scene.get_win_scale()));
		}
		switch(main_input.get_input()) {
			case SDL_MOUSEBUTTONDOWN: 
				map.set_tile(player_tile, map.global_to_map(mouse_pos.x, mouse_pos.y, main_scene.get_win_scale()));
				break;
		}

		main_scene.exit_test();

		SDL_Delay(2);

		msec = SDL_GetTicks() - frame_start;
		if(msec > 0) fps = 1000.0 / (double) msec;
		//std::cout << "FPS: " << fps << std::endl;
	}
}
void init_sdl() {
	SDL_Init(SDL_INIT_VIDEO);
}
