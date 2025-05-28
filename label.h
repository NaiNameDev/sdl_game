class label {
public:
	SDL_Surface* font_surface;
	vector2 position;
	int scale;
	std::string text = "1234567890";
	int h;
	int w;
	int sx = 3;
	int sy = 5;
	
	label() {
		font_surface = IMG_Load("numbers.png");
		scale = 1;
		h = font_surface->h;
		w = font_surface->w;
		position = vector2(32, 32);
	}

	void draw_full_text(scene* scn) {
		for (int i = 0; i < text.size(); i++) {
			switch(text[i]) {
				case '0':
					draw_number(scn, 9, i);
					break;
				case '1':
					draw_number(scn, 0, i);
					break;
				case '2':
					draw_number(scn, 1, i);
					break;
				case '3':
					draw_number(scn, 2, i);
					break;
				case '4':
					draw_number(scn, 3, i);
					break;
				case '5':
					draw_number(scn, 4, i);
					break;
				case '6':
					draw_number(scn, 5, i);
					break;
				case '7':
					draw_number(scn, 6, i);
					break;
				case '8':
					draw_number(scn, 7, i);
					break;
				case '9':
					draw_number(scn, 8, i);
					break;
					
			}
		}
	}

	void draw_number(scene* scn, int index, int x_adding) {
		int bpp;
		Uint8 *p;
		for (int i = 0; i < sx; i++) {
			for (int j = 0; j < sy; j++) {
				bpp = font_surface->format->BytesPerPixel;
    			p = (Uint8 *)font_surface->pixels + j * font_surface->pitch + (i + index * sx) * bpp;
				
				if (*(Uint32*)p < 4294967295) {
					scn->buffer_set_pixel(i + (x_adding * (sx + 1)) + position.x, j + position.y, color(255, 255, 255, 0));
				}
			}
		}
	}

};
