class cube //ini adalah kelas yang di includekan bersama dengan objek.h di main.cpp
{
  private:
	int width, height;

  public:
	int x, y;

	cube(int x_input, int y_input, int width_input, int height_input); //konstruktor class cube
	void draw()
	{
		glRecti(x, y, x + width, y + height);
	}
	bool check_collision(int x2, int y2, int w2, int h2) //rumus collision, parameternya adalah posisi x objek ke 2,posisi y objeck ke 2,width,height objeck ke dua
	{
		if (x + width >= x2 &&  // r1 right edge past r2 left
			x <= x2 + w2 &&		// r1 left edge past r2 right
			y + height >= y2 && // r1 top edge past r2 bottom
			y <= y2 + h2)		// r1 bottom edge past r2 top
		{
			return true;
		}
		return false;
	}

	bool  check_line_collision(float x3, float x4 , float y3 , float y4)// rumus deteksi batas luar ortho
	{
		float x1 = x;
		float x2 = x + width;
		float y1 = y;
		float y2 = y + height;

		bool kanan = x2 < x4 ? true : false;
		bool kiri = x1 > x3 ? true : false;
		bool atas = y2 < y4 ? true : false;
		bool bawah = y1 > y3 ? true : false;
		printf ("%d %d %d %d %d \n",!(kanan && atas && bawah && kiri) , !atas , !kanan , !bawah , !kiri);
		// printf ("%f %f \n" , y2 , y4);
		// static bool arr[] = {!(kanan && atas && bawah && kiri) , !atas , !kanan , !bawah , !kiri};
		return !(kanan && atas && bawah && kiri) ;
	}

	int *attr() //method untuk mengupdate value pada setiap proses
	{
		static int data[4];
		data[0] = x;
		data[1] = y;
		data[2] = width;
		data[3] = height;
		return data;
	}
};

cube::cube(int x_input, int y_input, int width_input, int height_input) //inisialisasi konstruktornya
{
	width = width_input;
	height = height_input;
	x = x_input;
	y = y_input;
}
