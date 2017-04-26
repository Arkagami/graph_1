#include <time.h>
#include "vstub.h"

namespace std{

int main(void){
    time_t t;
	double a = 0.5, b = 0, y, x, dy = 0,
		   k = 0.001953125, a1 = k * a, b1 = b * k, error;
	// y = ax + b, a' = ak, b' = bk, y = a'x + b' / k, k = 1/512
	drawgrid();
	t = clock();
	setcolor(255, 255, 0);
	// обычное построение по точкам
	for (int i = 0; i < 7000; i++) {
		x = 0; y = 0;
		while (x < 300)
		{
			putpixel(x, 400 - y);
			x += 1;
			y = a*x + b;
		}
	}
	vc << "\nd(Time) - " << (clock() - t) / 7000 << "." << (clock() - t) % 7000 << " seconds";
		GFlush();
		TFlush();
	t = clock();
	// целочисленное уравнение прямой
	setcolor(255, 0, 0);
	for (int i = 0; i < 7000; i++) {
		x = 0; y = 0;
		while (x < 300)
		{
			putpixel(x + 25, 400 - y);
			x += 1;
			y = (a1*x + b1) / k;
		}
	}
	vc << "\nd(Time) - " << (clock() - t) / 7000 << "." << (clock() - t) % 7000 << " seconds";
	GFlush();
	TFlush();
	t = clock();
	// алгоритм Брезенхэма
	setcolor(0, 255, 0);
	for (int i = 0; i < 7000; i++) {
		x = 50; y = 0;
		error = -0.5;
		while (x < 350)
		{
			putpixel(x, 400 - y);
			error = error + a;
			if (error < 0)
				y += 1;
			else
				error -= 1.0;
			x += 1;
		}
	}
	vc << "\nd(Time) - " << (clock() - t) / 7000 << "." << (clock() - t) % 7000 << " seconds";
	GFlush(); 
	TFlush();
	t = clock();
	// целочисленный алгоритм Брезенхэма
	setcolor(0, 0, 255);
	for (int i = 0; i < 7000; i++) {
		x = 75; y = 0;
		error = -1;
		while (x < 375)
		{
			putpixel(x, 400 - y);
			error += 2 * dy;
			if (error < 0)
			{
				y += 1;
				dy = 1;
			}
			else
			{
				dy = 0;
				error -= 2;
			}
			x += 1;
		}
	}
	vc << "\nd(Time) - " << (clock() - t) / 7000 << "." << (clock() - t) % 7000 << " seconds";
	GFlush();
	TFlush();
	
  vgetchar();
  return 0;
}

}