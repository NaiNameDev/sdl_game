class object {
public:
	vector2 position;

	object(vector2 pos = vector2(0, 0)) {
		position = pos;
	}
};

class box_shape : public object {
public:
	vector2 scale;
	color shape_color;
	
	box_shape(vector2 npos, vector2 nscale = vector2(0, 0), color ncol = color(0, 0, 0, 0)) {
		position = npos;
		scale = nscale;
		shape_color = ncol;
	}

	void draw(scene *scn) {
		scn->buffer_fill_square((int)position.x, (int)position.y, (int)scale.x, (int)scale.y, shape_color);
	}
};
