#include <stdio.h>
#include <stdlib.h>

// Node structure for Circular Singly Linked List
struct Node {
    int data;              // Data part of the node
    struct Node* next;     // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;   // Assign data
    newNode->next = NULL;   // Next initialized to NULL
    return newNode;
}

// Function to display the circular list
void displayList(struct Node* head) {
    if (head == NULL) { // Empty list check
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    // Traverse until we reach head again
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n"); // Show circular link
}

// Insert node at beginning
struct Node* insertAtBeginning(struct Node* head) {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);

    struct Node* newNode = createNode(data);

    if (head == NULL) { // Empty list case
        head = newNode;
        newNode->next = head; // Circular link
    } else {
        struct Node* temp = head;
        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode; // Last node points to new node
        newNode->next = head; // New node points to old head
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

    if (head == NULL) { // Empty list
        head = newNode;
        newNode->next = head; // Circular
    } else {
        struct Node* temp = head;
        // Traverse to last node
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode; // Last node points to new node
        newNode->next = head; // New node points to head
    }

    displayList(head);
    return head;
}

// Insert node at specific position
struct Node* insertAtPosition(struct Node* head) {
    int data, pos;
    printf("Enter value: ");
    scanf("%d", &data);
    printf("Enter position: ");
    scanf("%d", &pos);

    struct Node* newNode = createNode(data);

    // Case 1: Insert at beginning or empty list
    if (head == NULL || pos == 1) {
        if (head == NULL) { // Empty list
            head = newNode;
            newNode->next = head;
        } else { // Insert before head
            struct Node* temp = head;
            while (temp->next != head) { // Reach last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    } else {
        // Traverse to node before desired position
        struct Node* temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        // Insert node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    displayList(head);
    return head;
}

// Delete node at beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) { // Empty list
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (head->next == head) { // Only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* last = head;
    // Traverse to last node
    while (last->next != head) {
        last = last->next;
    }
    head=head->next;
    last->next = head;      // Update head
    free(temp);              // Free old head

    displayList(head);
    return head;
}

// Delete node at end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) { // Empty list
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (head->next == head) { // Only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    // Traverse to second last node
    while (temp->next->next != head) {
        temp = temp->next;
    }
    struct Node* last = temp->next; // Last node
    temp->next = head;              // Second last node points to head
    free(last);                     // Free last node

    displayList(head);
    return head;
}

// Delete node at specific position
struct Node* deleteAtPosition(struct Node* head) {
    if (head == NULL) { // Empty list
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) { // Delete first node
        return deleteAtBeginning(head);
    }

    struct Node* temp = head;
    int i = 1;
    // Traverse to node before the position
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == head) { // Invalid position
        printf("Invalid position. Cannot delete.\n");
        return head;
    }

    struct Node* delNode = temp->next; // Node to delete
    temp->next = delNode->next;        // Bypass node
    free(delNode);

    displayList(head);
    return head;
}

// Reverse the circular linked list
struct Node* reverseList(struct Node* head) {
    // Handle empty list or a list with a single node
    if (head == NULL || head->next == head) {
        return head;
    }

    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    // Traverse the list once, reversing pointers
    do {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev one step forward
        current = next;       // Move current one step forward
    } while (current != head);

    // After the loop, `prev` is the new head.
    // The original `head` is now the last node.
    // Connect the new last node (original head) to the new head (prev)
    // to make the list circular again.
    head->next = prev;

    // Update the head pointer to the new head
    head = prev;
    displayList(head);
    return head;
}

// Concatenate two circular lists
struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    int n;
    printf("Enter number of nodes for 2nd list: ");
    scanf("%d", &n);

    // Create second list
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head2 == NULL) { // First node in list2
            head2 = newNode;
            newNode->next = head2;
        } else { // Insert at end of list2
            struct Node* temp = head2;
            while (temp->next != head2) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head2;
        }
        
    }

    if (head1 == NULL) return head2; // If first list empty
    if (head2 == NULL) return head1; // If second list empty

    // Find last nodes of both lists
    struct Node* tail1 = head1;
    while (tail1->next != head1) {
        tail1 = tail1->next;
    }

    struct Node* tail2 = head2;
    while (tail2->next != head2) {
        tail2 = tail2->next;
    }

    // Connect the two lists circularly
    tail1->next = head2;
    tail2->next = head1;
    displayList(head1);
    return head1;
}

// Main function
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

        if (head == NULL) { // First node
            head = newNode;
            newNode->next = head;
        } else { // Insert at end
            struct Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    displayList(head);

    // Menu-driven program
    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete at beginning\n5. Delete at end\n6. Delete at position\n");
        printf("7. Reverse List\n8. Concatenate Lists\n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head = insertAtBeginning(head); break;
            case 2: head = insertAtEnd(head); break;
            case 3: head = insertAtPosition(head); break;
            case 4: head = deleteAtBeginning(head); break;
            case 5: head = deleteAtEnd(head); break;
            case 6: head = deleteAtPosition(head); break;
            case 7: head = reverseList(head); break;
            case 8: head = concatenateLists(head, NULL); break;
            case 9: displayList(head); break;
            case 10: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
