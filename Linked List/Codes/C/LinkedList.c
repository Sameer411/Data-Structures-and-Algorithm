// Iterative C program to search an element in linked list

/*
List of Operations 

1) Push operation: To Insert the data 
2) Search Operation 
3) Print List 

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node /* Link list node */
{
        int key;
        struct Node *next;
};

/* Given a reference (pointer to pointer) to the head
                                                                of a list and an int, push a new node on the front
                                                                of the list. */
void push(struct Node **head_ref, int new_key)
{
        /* allocate node */
        struct Node *new_node =
            (struct Node *)malloc(sizeof(struct Node));

        new_node->key = new_key;      /* put in the key */
        new_node->next = (*head_ref); /* link the old list off the new node */
        (*head_ref) = new_node;       /* move the head to point to the new node */
}

// This function prints contents of linked list starting from
// the given node
void printList(struct Node *n)
{
        while (n != NULL)
        {
                printf(" %d ", n->key);
                n = n->next;
        }
}

bool search(struct Node *head, int x) /* Checks whether the value x is present in linked list */
{
        struct Node *current = head; // Initialize current
        while (current != NULL)
        {
                if (current->key == x)
                        return true;
                current = current->next;
        }
        return false;
}

/* Driver program to test count function*/
int main()
{
        /* Start with the empty list */
        struct Node *head = NULL;
        int x = 21;

        /* Use push() to construct below list
                                                        	14->21->11->30->10 */
        push(&head, 10);
        push(&head, 30);
        push(&head, 11);
        push(&head, 21);
        push(&head, 14);

        printf("\nElements inserted in Linked List are: ");

        printList(head);

        printf("\nWe are searching number 21 is present in list or not?");

        search(head, 21) ? printf("\nYes 21 is present in list") : printf("\nNo");
        return 0;
}