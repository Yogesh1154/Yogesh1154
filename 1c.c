#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void selectionSort(struct Node* start) {
    struct Node *i, *j;
    int min;

    for (i = start; i != NULL; i = i->next) {
        struct Node* min_ptr = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min_ptr->data)
                min_ptr = j;
        }
        swap(i, min_ptr);
    }
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    int elements[] = {64, 34, 25, 12, 22, 11, 90};
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); ++i)
        insertAtEnd(&head, elements[i]);

    printf("Linked List before sorting:\n");
    printList(head);

    selectionSort(head);

    printf("Linked List after sorting:\n");
    printList(head);

    return 0;
}
