#include <iostream>
#include <cmath>
#include <conio.h>
#include <fstream>
#include <string>

float const gravity = -9.8f;
float const deltaTime = 0.1f;

using namespace std;

struct Image
{
	int mx;
	int my;
	int* points;

	void createImage(int tmx, int tmy)
	{
		mx = tmx;
		my = tmy;
		points = new int[tmx * tmy]{ 0 };
	}

	void showImage()
	{
		using namespace std;
		for (int i = 0; i < my; i++)
		{
			for (int j = 0; j < mx; j++)
			{
				cout << getPointImage(j,i) << " ";
			}
			cout << endl;
		}

}	void setPointImage(int x, int y, int color)
	{
		if ((y * mx + x) > mx * my)
		{
			return;
		}
		points[(y * mx + x)] = color;
	}

	int getPointImage(int x, int y) 
	{
		int n;
		n = y * mx + x;
		int color = points[n];
		return color;
	}

	void saveToPnmFile(string fileName) 
	{
		fstream out;
		out.open(fileName, fstream::out);
		out << "P1" << endl;
		out << mx << " " << my << endl;
		for (int i = 0; i < my; i++)
		{
			for (int j = 0; j < mx; j++)
			{
				out << points[i * mx + j] << " ";
			}
			out << endl;
		}
		out.close();
	}

};

int main()
{
	Image img;
	img.createImage(4, 7);
	img.setPointImage(1, 0, 1);
	img.setPointImage(2, 0, 1);
	img.setPointImage(0, 1, 1);
	img.setPointImage(3, 1, 1);
	img.setPointImage(0, 2, 1);
	img.setPointImage(1, 3, 1);
	img.setPointImage(2, 3, 1);
	img.setPointImage(3, 4, 1);
	img.setPointImage(0, 5, 1);
	img.setPointImage(3, 5, 1);
	img.setPointImage(1, 6, 1);
	img.setPointImage(2, 6, 1);
	img.showImage();
	img.saveToPnmFile("S-image.pnm");
	return 0;
}