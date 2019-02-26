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
	//Jumps the pointer tail to the end of the list
	while (tail->next != NULL){
		tail = tail->next;
	}

	//Now that its pointing to the last, to the next it adds linkedlist, points it backwards and adds the element to its data.
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
	linked_list *backtrack = list;
	//Saves first element in pointer, since it gets deleted.
	void *firstElement = list->data;
	
	//Deletes first element and pushes pointer to next.
	backtrack->data = NULL;
	backtrack = backtrack->next;

	//Goes through the list
	while (backtrack != NULL){
		//Deletes previous and then adds current to previous
		backtrack->previous->data = NULL;
		add_element(backtrack->previous,backtrack->data);
		//When it gets to the end of the list, it deletes the last element (since its added to the previous also)
		if (backtrack->next == NULL){
			backtrack->data = NULL;
			backtrack->previous->next = NULL;
			free(backtrack);
		}
		backtrack = backtrack->next;
		
	}
	
	return firstElement;
}

int remove_element(linked_list *list, void *element) {
	linked_list *index = list;
	//If the element is found as the first, use remove_first.
	if (index->data == element){
		remove_first(index);
		return 0;
	}
	index = index->next; 

	//If its in the middle (not first or last)
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
	//If its the last.
	if (index->data == element){
		index->data = NULL;
		index->previous->next = NULL;
		free(index);
		return 0;
	}

	return -1;
}
