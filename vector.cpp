class vector2i {
public:
	int x, y;
	
	void print() {
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}

	vector2i(int nx = 0, int ny = 0) {
		x = nx;
		y = ny;
	}
};

class vector3i {
public:
	int x, y, z;
	
	vector3i(int nx = 0, int ny = 0, int nz = 0) {
		x = nx;
		y = ny;
		z = nz;
	}
};

class vector4i {
public:
	int x, y, z, w;
	
	vector4i(int nx = 0, int ny = 0, int nz = 0, int nw = 0) {
		x = nx;
		y = ny;
		z = nz;
		w = nw;
	}
};
class vector2 {
public:
	float x, y;
	
	void print() {
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}

	vector2(float nx = 0, float ny = 0) {
		x = nx;
		y = ny;
	}
	//operator+(const vector2& add) const {
	//	return vector2(add.x + x, add.y + y);
	//} 
};

class vector3 {
public:
	float x, y, z;
	
	vector3(float nx, float ny, float nz) {
		x = nx;
		y = ny;
		z = nz;
	}

	vector3 operator+ (const vector3& vec) const {
		return vector3(x + vec.x, y + vec.y, z + vec.z);
	}
	vector3 operator- (const vector3& vec) const {
		return vector3(x - vec.x, y - vec.y, z - vec.z);
	}
};

class vector4 {
public:
	float x, y, z, w;
	
	vector4(float nx, float ny, float nz, float nw) {
		x = nx;
		y = ny;
		z = nz;
		w = nw;
	}
};

class color {
public:
	uint8_t r, g, b, a;
	
	color(uint8_t nr = 0, uint8_t ng = 0, uint8_t nb = 0, uint8_t na = 255) {
		r = nr;
		g = ng;
		b = nb;
		a = na;
	}
};
