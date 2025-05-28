class scene {
private:
	SDL_Event event;
	SDL_Renderer* renderer;
	SDL_Window* window;

	vector2i win_size;
	int win_scale = 1;

	Uint32* buffer;
	SDL_Texture* buffer_texture;

	vector2 camera_position;

public:
	scene(int wx, int wy, int scale) {
		SDL_CreateWindowAndRenderer(wx * scale, wy * scale, 0, &window, &renderer);
		SDL_RenderSetScale(renderer, scale, scale);
	
		win_scale = scale;
		win_size = vector2i(wx, wy);
		buffer = new Uint32[win_size.x * win_size.y];
		for (int i = 0; i < win_size.x; i++) {
			for (int j = 0; j < win_size.y; j++) {
				buffer[(j * win_size.x) + i] = 0;
			}
		}
	}

	void clear_buffer() {
		for (int i = 0; i < win_size.x; i++) {
			for (int j = 0; j < win_size.y; j++) {
				buffer[(j * win_size.x) + i] = 0;
			}
		}
	}
	void buffer_set_pixel(int x, int y, color col) {
		if (x >= 0 && y >= 0 && x < win_size.x && y < win_size.y) {
			buffer[(y * win_size.x) + x] = (Uint32)((col.r << 16) + (col.g << 8) + (col.b << 0));
		}
	}
	void buffer_set_pixel_uint(int x, int y, Uint32 col) {
		if (x >= 0 && y >= 0 && x < win_size.x && y < win_size.y) {
			buffer[(y * win_size.x) + x] = col;
		}
	}
	void buffer_fill_square(int x, int y, int sx, int sy, color col) {
		for (int i = 0; i < sx; i++) {
			for (int j = 0; j < sy; j++) {
				buffer_set_pixel(i + x, j + y, col);
			}
		}
	}
	void draw_buffer() {
		buffer_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, win_size.x, win_size.y);
		SDL_UpdateTexture(buffer_texture, nullptr, buffer, win_size.x * 4);

		SDL_RenderCopy(renderer, buffer_texture, nullptr, nullptr);

		SDL_DestroyTexture(buffer_texture);
	}

	void exit_test() {
		while ( SDL_PollEvent( &event ) != 0 ) {
			if (event.type == SDL_QUIT) {
				SDL_DestroyRenderer(renderer);
				SDL_DestroyWindow(window);
				SDL_Quit();
				exit(0);
			}
		}
	}

	void clear() {
		SDL_RenderPresent(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}

	vector2i get_mouse_position() {
		vector2i ret;
		SDL_GetMouseState(&ret.x, &ret.y);

		ret.x += -camera_position.x * win_scale;
		ret.y += -camera_position.y * win_scale;

		return ret;
	}
	
	void set_camera_position(vector2 npos) {
		camera_position = npos;
	}

	vector2 get_camera_position() {
		return camera_position;
	}
	int get_win_scale() {
		return win_scale;
	}
	vector2i get_win_size() {
		return win_size;
	}
	vector2i get_real_win_size() {
		return vector2i(win_size.x * win_scale, win_size.y * win_scale);
	}
};
