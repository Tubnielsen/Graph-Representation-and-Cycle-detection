#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "graph.h"
#include "cycledetection.h"

/*
 * Prints the usage to the console.
 */
void show_usage() {
	printf("===================================\n");
	printf("=======     Usage      ============\n");
	printf("===================================\n");
	printf(" ./program graph-file \n");
	printf("===================================\n");
}

// First command line parameter - input file
int main(int argc, char *argv[]) {
	/*
	// Error checking
	if( argc != 2) {
		show_usage();
		return 0;
	}

	// Build a graph from the input
	graph *g = read_graph(argv[1]);

	// Run cycle detection algorithm and output result
	cycle_detection(g);*/
	linked_list *test;
	int *myData = 5;
	int *myData2 = 7;
	int *myData3 = 8;
	add_element(test, myData);
	add_element(test, myData2);
	add_element(test, myData3);
	add_element(test, myData);

}
