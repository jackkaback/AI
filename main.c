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
	struct bag bags;
	for (int ii = 0; ii < 24; ii++){
		int r = rand();

		if (r % 2){
			bags.items[ii] = true;
		}
		else{
			bags.items[ii] = false;
		}
	}


	printf("Hello, World!\n");
	return 0;
}