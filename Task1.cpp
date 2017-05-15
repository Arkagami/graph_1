#include <time.h>
#include "vstub.h"

//What am I doing there? Ya ved' sishy d telefona. Neysheli ya s telefona toshe mogy commitit'???

namespace std{

int main(void){
    time_t t;
	double a = 0.5, b = 0, y, x, dy = 0,
		   k = 0.001953125, a1 = k * a, b1 = b * k, error;
	// y = ax + b, a' = ak, b' = bk, y = a'x + b' / k, k = 1/512
	drawgrid();
	t = clock();
	setcolor(255, 255, 0);
	// îáû÷íîå ïîñòðîåíèå ïî òî÷êàì
	for (int i = 0; i < 7000; i++) {
		x = 0; y = 0;
		while (x < 300)
		{
			putpixel(x, 400 - y);
			x += 1;
			y = a*x + b;
		}
	}
	vc << "\nd(Time) - " << (clock() - t) / 1000 << "." << (clock() - t) % 1000 << " seconds";
		GFlush();
		TFlush();
	t = clock();
	// öåëî÷èñëåííîå óðàâíåíèå ïðÿìîé
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
	vc << "\nd(Time) - " << (clock() - t) / 1000 << "." << (clock() - t) % 1000 << " seconds";
	GFlush();
	TFlush();
	t = clock();
	// àëãîðèòì Áðåçåíõýìà
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
	vc << "\nd(Time) - " << (clock() - t) / 1000 << "." << (clock() - t) % 1000 << " seconds";
	GFlush(); 
	TFlush();
	t = clock();
	// öåëî÷èñëåííûé àëãîðèòì Áðåçåíõýìà
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
	vc << "\nd(Time) - " << (clock() - t) / 1000 << "." << (clock() - t) % 1000 << " seconds";
	GFlush();
	TFlush();
	
  vgetchar();
  return 0;
}

}