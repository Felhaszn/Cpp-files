#include <iostream>
#include <time.h>

#include "bigint.h"

double time1, timedif;

int main() {
	time1 = (double)clock();            /* get initial time */
	time1 = time1 / CLOCKS_PER_SEC;      /*    in seconds    */

	bigint k;
	k = 2;
	std::cout << k.sqr(k, 1024) << std::endl;

	timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
	printf("\n\nAz eltelt ido: %lfs\n", timedif);

	return 0;
}