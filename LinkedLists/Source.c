#include <stdio.h>
#include <stdlib.h>

#include "McDonalds.h"

void addItem(PLISTNODE*, int);

int main(void) {

	int var;

	PLISTNODE list = NULL;	// There is nothing on our list. List is pointing to NULL.
							// When adding to the list, the new item will point to NULL.

	puts("Enter a number: ");
	scanf_s("%d", &var);

	addItem(list, var);

}

void addItem(PLISTNODE *list, int var) {

	if (list == NULL) {	

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

	}
}
