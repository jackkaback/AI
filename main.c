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

int makeValue (bool items []){

}

int makeWeight(bool items []){

}

int scorer(bool items []){

}

void init_bags(struct bag *bags){
	struct bag bagger = *bags;

	bagger.weight = 0;
	bagger.score = 0;
	bagger.value = 0;

	for (int ii = 0; ii < 24; ii++) {

		int r = rand();
		//printf("%d\n", r);

		if (r % 2) {
			bagger.items[ii] = true;
		}
		else {
			bagger.items[ii] = false;
		}
	}

	*bags = bagger;
}

int main() {
	srand(time(NULL));
	struct bag bags[512];

	for (int jj = 0; jj < 512; jj++) {
		init_bags(&bags[jj]);
	}
	return 0;
}