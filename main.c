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

void setValueAndWeigt (struct bag *bags){
	struct bag bagger = *bags;

	bagger.weight = 0;
	bagger.score = 0;
	bagger.value = 0;

	int vals [] = {675367, 1677009, 1676628, 1523970, 901489, 97326, 69666, 1296457, 1679693, 1902996, 1844992, 1049289,
	              1319836, 1252836, 953277, 2067538, 825594, 853655, 1826027, 65731, 943972, 577243, 466257, 369261};

	int weights [] = {382745, 799601, 909247, 729069, 467902, 44328, 34610, 698150, 823460, 903959, 853665, 551830,
	                 610856, 670702, 488960, 951111, 323046, 446298, 931161, 31385, 496951, 264724, 224916, 169684};


	for (int ii = 0; ii < 24; ii++) {
		if (bagger.items[ii]){
			bagger.value += vals[ii];
			bagger.weight += weights[ii];
		}
	}

	*bags = bagger;
}

void scorer(struct bag *bags){
	struct bag bagger = *bags;
	setValueAndWeigt(&bagger);

	int temp = bagger.value - (7312160 - bagger.weight);

	//if the bag is over capacity, then the bag gets a 0.1
	if (bagger.weight > 7312160 || temp < 0){
		bagger.score = 1;
	}

	else{
		bagger.score = temp;
	}

	*bags = bagger;
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
	scorer(&bagger);
	*bags = bagger;
}

int main() {
	srand(time(NULL));
	struct bag bags[512];

	for (int jj = 0; jj < 512; jj++) {
		init_bags(&bags[jj]);
		printf("%d\n" , bags->score);
	}
	return 0;
}