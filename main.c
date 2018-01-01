#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

typedef struct bag{
	bool items [24];
	int weight;
	int score;
	int value;
};


int main() {
	srand(time(NULL));
	struct bag bags[512];

	for (int jj = 0; jj < 512; jj++) {
		for (int ii = 0; ii < 24; ii++) {

			int r = rand();
			//printf("%d\n", r);

			if (r % 2) {
				bags[jj].items[ii] = true;
			}
			else {
				bags[jj].items[ii] = false;
			}
		}
	}
	return 0;
}