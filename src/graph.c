#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include <string.h>

graph *read_graph(char *filename) {
	graph G; 
	FILE *fp = fopen(filename, "r");
	if (fp != NULL){
		char line[128];
		int y = 0;
		int x = 0;
	
		char* d = fgets(line, sizeof line, fp); //gets first line which is integer representing the dimensions of the matrix
		int dim = atoi(d); //parse char* to int
		vertex V[dim];
		printf("dim is -> %d \n", dim);
		while(fgets(line, sizeof line, fp) != NULL){
			V[y].id = y;
			V[y].out_neighbours = init_linked_list();
			V[y].in_neighbours = init_linked_list();
			//printf("line number -> %i is -> %s", y, line);
			for(x = 0; x < dim; x++){
				if (line[x] == '1'){
					printf("%d ----> %d \n", x, y);
					int *p = &V[y].id;
					add_element(V[y].out_neighbours, p);

					

					
				}
			}
			y++;
			
			
		}
		//Print checking amount of verteces.
		int b;
		for (b = 0; b < dim; b++){
			printf("vertex -> %d \n", V[b].id);
			printf("element -> %ls \n", V[b].out_neighbours->data);
		}
		fclose(fp);
		
	}
	else {
		printf("No file with given name found");
	}
	
	



	
	
	
	
	return NULL;
}

void print_graph(graph *g) {

}

int main(int argc, char *argv[]) {
	char *file = "/home/tobias/test.txt";
	read_graph(file);
}