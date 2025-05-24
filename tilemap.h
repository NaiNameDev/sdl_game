class tile {
public:
	color tile_color;
	
	tile(color ncolor) {
		tile_color = ncolor;
	}
};

class tile_map {
private:
	std::vector<std::vector<tile>> tilemap_vector;

public:
	vector2i size;
	vector2i tile_size;
	vector2 position;
	
	tile_map(vector2 npos, vector2i nsize, vector2i ntile_size, tile fill_tile) {
		position = npos;
		size = nsize;
		tile_size = ntile_size;

		tilemap_vector.resize(nsize.x);
		
		for (int i = 0; i < nsize.x; i++) {
			for (int j = 0; j < nsize.y; j++) {
				tilemap_vector[i].push_back(fill_tile);
			}
		}
	}

	vector2i global_to_map(int gx, int gy, int ws) { // ws - win_scale
		vector2i ret = vector2i(std::floor((gx - position.x * ws) / tile_size.x / ws), std::floor((gy - position.y * ws) / tile_size.y / ws));
	
		if (ret.x < 0) ret.x = 0;
		if (ret.y < 0) ret.y = 0;
		if (ret.x > size.x - 1) ret.x = size.x - 1;
		if (ret.y > size.y - 1) ret.y = size.y - 1;

		return ret;
	}

	void draw_tile(scene* scn, vector2i pos, tile tl) {
		vector2i start_position = vector2i((scn->get_camera_position().x + position.x) + (pos.x * tile_size.x),
										   (scn->get_camera_position().y + position.y) + (pos.y * tile_size.y));
		
		scn->buffer_fill_square(start_position.x, start_position.y, tile_size.x, tile_size.y, tl.tile_color);
	}

	void draw_full_tilemap(scene* scn) {
		vector2i draw_min = global_to_map(scn->get_camera_position().x * -scn->get_win_scale(),
										  scn->get_camera_position().y * -scn->get_win_scale(), scn->get_win_scale());
	
		vector2i draw_max = global_to_map(scn->get_win_size().x * scn->get_win_scale() + scn->get_camera_position().x * -scn->get_win_scale(),
										  scn->get_win_size().y * scn->get_win_scale() + scn->get_camera_position().y * -scn->get_win_scale(), scn->get_win_scale());

		for (int i = draw_min.x; i < draw_max.x + 1; i++) {
			for (int j = draw_min.y; j < draw_max.y + 1; j++) {
				draw_tile(scn, vector2i(i, j), tilemap_vector[i][j]);
			}
		}
	}

	void set_tile(tile new_tile, vector2i pos) {
		tilemap_vector[pos.x][pos.y] = new_tile;
	}
	
	tile get_tile(vector2i pos) {
		return tilemap_vector[pos.x][pos.y];
	}
};
