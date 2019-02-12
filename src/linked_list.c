/*
 * linked_list.c
 *
 *  Created on: Dec 24, 2013
 *      Author: jacob
 */
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

linked_list *init_linked_list() {
	linked_list *listPointer = malloc(sizeof(linked_list));

	listPointer->data = NULL;
	listPointer->next = NULL;
	listPointer->previous = NULL;
	return listPointer;
}

void add_element( linked_list *list, void *element) {
	linked_list *tail = list;
	if (tail == NULL){
		tail = init_linked_list();
	}

	if (tail->data == NULL){
		tail->data = element;
		return;
	}
	
	while (tail->next != NULL){
		tail = tail->next;
	}
	tail->next = init_linked_list();
	tail->next->previous = tail;
	tail->next->data = element;
}

int linked_list_size(linked_list *list) {
	linked_list *counter = list;
	int size = 1;
	while (counter->next != NULL){
		counter = counter->next;
		size++;
	}
	return size;
}

void *remove_first(linked_list *list) {
	void *firstElement = list->data;
	list->data = NULL;
	list = list->next;
	return firstElement;
}

int remove_element(linked_list *list, void *element) {
	linked_list *index = list;
	if (index->data == element){
		remove_first(index);
		return 0;
	}
	index = index->next;
	while (index->next != NULL){
		if (index->data == element){
			index->data = NULL;
			index->previous->next = index->next;
			index->next->previous = index->previous;
			free(index);
			return 0;
		}
		index = index->next;
	}
	if (index->data == element){
		index->data = NULL;
		index->previous->next = NULL;
		free(index);
		return 0;
	}

	return -1;
}

int main(int argc, char *argv[]) {
	linked_list *test = init_linked_list();
	char *myData = "5";
	char *myData2 = "7 \n";
	char *myData3 = "8 \n";
	add_element(test, myData);
	add_element(test, myData2);
	add_element(test, myData3);
	add_element(test, myData);
	//remove_element(7);
	printf("%d", linked_list_size(test));
	while (test->data != NULL){
		
		printf("%s", (char*)test->data);
		if (test->next != NULL){
			test = test->next;
		}
		else break;
	}
	
	
}