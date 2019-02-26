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
		
		printf("dim is -> %d \n", dim);
		
		while(fgets(line, sizeof line, fp) != NULL){
			//printf("line number -> %i is -> %s", y, line);
			for(x = 0; x < dim; x++){
				if (line[x] == '1'){
					printf("%d ----> %d \n", x, y);
				}
			}
			y++;
			
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