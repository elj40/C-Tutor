/*
* Filename:	main.c
* Date:		16/11/2024
* Name:		EL Joubert
*
* A showcase of how to make and operate on a linked list
* This includes working with stack and queues
*/
#include <stdio.h>
#include <stdlib.h>

// PROBLEM WITH ARRAYS: we need to know how much memory we need to initalise them
// SOLUTION: linked list where each element points to the next one

typedef struct Node Node;

struct Node {
	int data;
	struct Node * next_ptr;
};

void print_linked_list(Node * head);
void add_to_linked_list(Node * head, Node * new_node);
void remove_from_linked_list_by_value(Node ** head, int value);
void remove_from_linked_list_by_index(); // TODO
void free_linked_list(Node * head);

// TODO
void stack_push(Node * head, Node * new_node);
Node * stack_pop(Node * head);
void stack_clear(Node ** pointer_to_head);

void queue_enqueue(Node * head, Node * new_node);
Node * queue_dequeue(Node ** pointer_to_head);

int main()
{
		Node * head = malloc(sizeof(Node));
		head->data = 1;
		head->next_ptr = NULL;

		Node * another_node = malloc(sizeof(Node));
		another_node->data = 2;
		another_node->next_ptr = NULL;

		head->next_ptr = another_node; // head points to another_node

		Node * another_node2 = malloc(sizeof(Node));
		another_node2->data = 3;
		another_node2->next_ptr = NULL;

		another_node->next_ptr = another_node2;

		Node * another_node3 = malloc(sizeof(Node));
		another_node3->data = 7;
		another_node3->next_ptr = NULL;

		add_to_linked_list(head, another_node3);

		Node * * pointer_to_head = &head;
		remove_from_linked_list_by_index(pointer_to_head, 2);

		print_linked_list(head);

		// Remember to free everything
		free_linked_list(head);
		return 0;

}

void print_linked_list(Node * head) {
		Node * current = head;
		int i = 0;
		while (current != NULL) {
                if (i > 20) break;
				printf("%d->", current->data);
				current = current->next_ptr;
            i++;
		}
		printf("NULL");
		printf("\n");
}


void add_to_linked_list(Node * head, Node * new_node) {
	Node * current = head;
	while (current->next_ptr != NULL) {
			current = current->next_ptr;
	}
	current->next_ptr = new_node;
}





void remove_from_linked_list_by_value(Node ** pointer_to_head, int value) {
    // pointer_to_head is a pointer to a pointer to the starting node
    // *pointer_to_head is a pointer to the starting node

    // Remove 3
    // 1->2->3->4->NULL
    //    ^-----^
		Node * current = *pointer_to_head;
		if (current->data == value) {
				*pointer_to_head = current->next_ptr;
		}
		else {
				while (current->next_ptr != NULL) {
						if (current->next_ptr->data == value) {
                                Node * to_remove = current->next_ptr;
								current->next_ptr = current->next_ptr->next_ptr;
								free(to_remove);
								return;
						}
						current = current->next_ptr;
				}
				printf("Could not find node with value: %d\n", value);
		}
}

void remove_from_linked_list_by_index(Node ** pointer_to_head, int index) {
    if (index == 0) {
        *pointer_to_head = (*pointer_to_head)->next_ptr;
    }
    else {
        // Go to index in list
        // Node before this index has to point to node after this index
        int current_index = 0;
        Node * current = *pointer_to_head;
        while (current->next_ptr != NULL && current_index != index-1) {
            current = current->next_ptr;
            current_index++;
        }
        if (current->next_ptr == NULL) {
            return;
        } else {
            current->next_ptr = current->next_ptr->next_ptr; // Skipping one
        }

    }
}


void free_linked_list(Node * head) {
		Node * current = head;
		while (current != NULL) {
				Node * next = current->next_ptr;
				free(current);
				current = next;
		}
}

// TODO
void my_stack_push(Node * head, Node * new_node) {
    Node * current = head;
	while (current->next_ptr != NULL) {
			current = current->next_ptr; //loop untl last node
	}
	current->next_ptr = new_node;
}

Node * stack_pop(Node * head) {
    Node * current = head;
	while (current->next_ptr->next_ptr != NULL) {
			current = current->next_ptr; //loop untl last node
	}
	Node * last_node = current->next_ptr;
	current->next_ptr = NULL;
	return last_node;
}
void stack_clear(Node ** pointer_to_head) {
    free_linked_list(*pointer_to_head);
    *pointer_to_head = NULL;
}

void queue_enqueue(Node * head, Node * new_node) {
    Node * current = head;
	while (current->next_ptr != NULL) {
			current = current->next_ptr; //loop untl last node
	}
	current->next_ptr = new_node;
}
Node * queue_dequeue(Node ** pointer_to_head) {
        Node * first_node = *pointer_to_head;
        *pointer_to_head = first_node->next_ptr;
        return first_node;
}
