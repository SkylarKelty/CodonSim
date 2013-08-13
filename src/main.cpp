#include "common.h"
#include "population.h"

int main(int argc, char *argv[]) {
	srand(frandom());

	int count = 10, ticks = 100;
	if (argc > 1) {
		count = atoi(argv[1]);
	}
	if (argc > 2) {
		ticks = atoi(argv[2]);
	}
	
	
	printf("--------------------------------------\n", count);
	printf("  Creating population with %d cells.  \n", count);
	Population *pop = new Population(count);
	
	printf("--------------------------------------\n", count);
	printf("Best possible time: %f\n", pop->get_optimal());
	printf("Worst possible time: %f\n", pop->get_suboptimal());
	printf("--------------------------------------\n", count);
	printf("Cell Count: %d\n", count);
	printf("Ticking: %d\n", ticks);
	printf("--------------------------------------\n", count);
	printf("Step, Best Time, Worst Time, Product\n", count);


	for (int i = 0; i < ticks; i++) {
		pop->process(10);
		printf("%d, %f, %f, %d\n", i, pop->get_best(), pop->get_worse(), pop->get_product());
	}

	printf("--------------------------------------\n", count);
	printf("          Simulation complete         \n", count);
	printf("--------------------------------------\n", count);

	delete pop;

	return 0;
}
