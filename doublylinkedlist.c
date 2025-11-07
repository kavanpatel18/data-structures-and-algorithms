#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;              // Data part of node
    struct Node* prev;     // Pointer to previous node
    struct Node* next;     // Pointer to next node
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);  // Print data with link symbol
        current = current->next;
    }
    printf("NULL\n"); // End of list
}

// Insert node at beginning
struct Node* insertAtBeginning(struct Node* head) {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);

    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode; // If list empty, new node is head
    } else {
        newNode->next = head; // Link new node to old head
        head->prev = newNode; // Backward link
        head = newNode;       // Update head
    }
    displayList(head);
    return head;
}

// Insert node at end
struct Node* insertAtEnd(struct Node* head) {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);

    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode; // If list empty, new node is head
    } else {
        struct Node* current = head;
        while (current->next != NULL) { // Traverse to last node
            current = current->next;
        }
        current->next = newNode; // Link last node to new node
        newNode->prev = current; // Link back to previous
    }
    displayList(head);
    return head;
}

// Insert node at a specific position
struct Node* insertAtPosition(struct Node* head) {
    int data, pos;
    printf("Enter value: ");
    scanf("%d", &data);
    printf("Enter position: ");
    scanf("%d", &pos);

    struct Node* newNode = createNode(data);

    // Case 1: Insert at beginning or empty list
    if (head == NULL || pos == 1) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
    } else {
        struct Node* current = head;
        int i = 1;
        // Traverse to node before insertion position
        while (i < pos - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }
        // Insert between current and current->next
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    displayList(head);
    return head;   
}

// Delete node at start
struct Node* deleteAtStart(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* temp = head; // Store head for deletion
    head = head->next;        // Move head to next node
    if (head != NULL) {
        head->prev = NULL;    // Remove backward link
    }
    free(temp);               // Free memory of deleted node
    displayList(head);
    return head;  
}

// Delete node at end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (head->next == NULL) { // Only one node
        free(head);
        return NULL;
    }

    struct Node* current = head;
    // Traverse to second last node
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);   // Free last node
    current->next = NULL;  // Make second last node the end
    displayList(head);
    return head;
}

// Delete node at specific position
struct Node* deleteAtPosition(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    int position;
    printf("Enter position: ");
    scanf("%d", &position);

    if (position == 1) { // Delete first node
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    } else {
        struct Node* current = head;
        int i = 1;
        while (i < position && current != NULL) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("Invalid position. Cannot delete.\n");
            return head;
        }
        // Relink previous and next nodes
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    }
    displayList(head);
    return head;
}

// Reverse the doubly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;

    // Swap prev and next pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to "next" node (which is prev now)
    }

    // Update head (temp->prev points to new head after loop)
    if (temp != NULL) {
        head = temp->prev;
    }
    displayList(head);
    return head;
}

// Concatenate a new list to the existing list
struct Node* concatenateLists(struct Node* head) {
    int n;
    printf("Enter number of nodes for the second list: ");
    scanf("%d", &n);
    struct Node* head2 = NULL;

    // Create second list
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head2 == NULL) {
            head2 = newNode;
        } else {
            struct Node* current = head2;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // If original list empty, return second list
    if (head == NULL) return head2;
    // If second list empty, return original
    if (head2 == NULL) return head;

    // Traverse to end of first list
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Link last node of list1 to head of list2
    current->next = head2;
    head2->prev = current;

    displayList(head);
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, n;

    // Initial list creation
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode; // First node
        } else {
            struct Node* current = head;
            while (current->next != NULL) { // Go to end
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Menu-driven program
    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete at start\n5. Delete at end\n6. Delete at position\n");
        printf("7. Reverse list\n8. Concatenate lists\n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head = insertAtBeginning(head); break;
            case 2: head = insertAtEnd(head); break;
            case 3: head = insertAtPosition(head); break;
            case 4: head = deleteAtStart(head); break;
            case 5: head = deleteAtEnd(head); break;
            case 6: head = deleteAtPosition(head); break;
            case 7: head = reverseList(head); break;
            case 8: head = concatenateLists(head); break;
            case 9: displayList(head); break;
            case 10: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
