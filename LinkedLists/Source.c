#include <stdio.h>
#include <stdlib.h>

#include "McDonalds.h"

// PAL. Monday, Nov. 14, 2022.

void addItem(PLISTNODE*, int);
void deleteItem(PLISTNODE*, int);
void printList(PLISTNODE*);

int main(void) {
	int var;
	PLISTNODE list = NULL;	// There is nothing on our list. List is pointing to NULL.
							// When adding to the list, the new item will point to NULL.
	puts("Enter a number: ");
	scanf_s("%d", &var);
	addItem(&list, var);
	printList(list);

	puts("Enter node number you want to delete: ");
	scanf_s("%d", &var);
	deleteItem(&list, var);
	printList(list);

	return 0;

}

void addItem(PLISTNODE *list, int var) {
	if (*list == NULL) {	

		PLISTNODE newNode = NULL;		// Initializing a new node into our list.
		newNode = (PLISTNODE)malloc(sizeof(LISTNODE));		//Assigning memory in the heap.
		newNode->age = var;				// The new node will be assigning the items of the list.
		newNode->next = *list;			// The new node will point to *list, which dereferences to NULL.
										// This means that the newItem will now point to NULL.
										// So the *list is now pointing to the newItem.
		*list = newNode;
	}
	else {
		PLISTNODE current = *list;
		while (list != NULL) {
			current = current->next;
		}
		PLISTNODE newNode = NULL;		// Initializing a new node into our list.
		newNode = (PLISTNODE)malloc(sizeof(LISTNODE));		//Assigning memory in the heap.
		newNode->age = var;				// The new node will be assigning the items of the list.
		newNode->next = NULL;			// The new node will point to NULL.
		current->next = newNode;
										// This means that the newItem will now point to NULL.
										// So the *list is now pointing to the newItem.
		*list = newNode;
	}
}

void deleteItem(PLISTNODE *list, int var) {

	PLISTNODE current = *list;

	if (current->age == var) {
		if (current->next != NULL) {

			*list = current->next;
		}
		else {
			*list = NULL;
		}
	}
	else {
		return;
	}
	
	free(current);
	return;
}

void printList(PLISTNODE* list) {

	PLISTNODE current = list;
	if (!current)	// list is empty, don't print!
		return;

	do
	{
		printf("%d ", current->age);
		current = current->next;
	} while (current != NULL);

	printf("\n");

}