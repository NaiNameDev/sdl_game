class input {
private:
	SDL_Event event;
	const Uint8* key_board_state;

public:
	input() {
		key_board_state = SDL_GetKeyboardState(nullptr);
	}

	bool is_key_pressed (size_t index) {
		return key_board_state[index];
	}
	
	unsigned int get_input() {
		SDL_PollEvent( &event );
		return event.type;
	}
};
