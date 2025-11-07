#include <stdio.h>
#include <stdlib.h> 

// Node structure for singly linked list
struct Node {
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to create a new node
struct Node* createNode(int data) {
    // Dynamically allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Assign the data to the node
    newNode->data = data;
    // Initialize the next pointer as NULL (since it's not linked yet)
    newNode->next = NULL;
    // Return the newly created node
    return newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;  // Start from the head node
    while (temp) {             // Traverse until the end (NULL)
        printf("%d -> ", temp->data); // Print data
        temp = temp->next;           // Move to next node
    }
    printf("NULL\n");          // Indicate end of the list
}

// Insert node at the front of the linked list
struct Node* insertFront(struct Node* head) {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    // Create a new node with given value
    struct Node* newNode = createNode(val);

    // New node should point to the current head
    newNode->next = head;

    // Display list after insertion
    display(newNode);

    // Return new node as the new head
    return newNode;
}

// Insert node at the end of the linked list
struct Node* insertEnd(struct Node* head) {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    // Create a new node
    struct Node* newNode = createNode(val);

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        display(newNode);
        return newNode;
    }

    // Otherwise, traverse to the last node
    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    // Link the last node to the new node
    temp->next = newNode;

    // Display updated list
    display(head);

    return head;
}

// Insert node at a specific position
struct Node* insertPos(struct Node* head) {
    int val, pos;
    printf("Enter value : ");
    scanf("%d", &val);
    printf("Enter position : ");
    scanf("%d", &pos);

    // If inserting at the head
    if (pos == 1) {
        struct Node* newNode = createNode(val);
        newNode->next = head;   // Link new node to old head
        display(newNode);
        return newNode;         // New node is the head
    }

    // Traverse to the node before the desired position
    struct Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    // If position is invalid (past end)
    if (!temp) {
        printf("Invalid position!\n");
        return head;
    }

    // Create the new node
    struct Node* newNode = createNode(val);

    // Insert the node: newNode → next of temp
    newNode->next = temp->next;
    temp->next = newNode;

    display(head);
    return head;
}

// Delete node from the front
struct Node* deleteFront(struct Node* head) {
    // If list is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    // Store the old head
    struct Node* temp = head;

    // Move head to the next node
    head = head->next;

    // Free memory of old head
    free(temp);

    display(head);
    return head;
}

// Delete node from the end
struct Node* deleteEnd(struct Node* head) {
    // If list is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    // If only one node exists
    if (head->next == NULL) {
        free(head);  // Delete the only node
        return NULL; // List becomes empty
    }

    // Traverse to the second last node
    struct Node* temp = head;
    while (temp->next->next)
        temp = temp->next;

    // Delete the last node
    free(temp->next);
    temp->next = NULL;

    display(head);
    return head;
}

// Delete node from a specific position
struct Node* deletePos(struct Node* head) {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    // If deleting head
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        display(head);
        return head;
    }

    // Traverse to the node before the one to delete
    struct Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    // If position invalid
    if (!temp || !temp->next) {
        printf("Invalid position!\n");
        return head;
    }

    // Node to be deleted
    struct Node* delNode = temp->next;

    // Bypass delNode
    temp->next = delNode->next;

    free(delNode);

    display(head);
    return head;
}

// Reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;    // Initially, previous is NULL
    struct Node* current = head; // Start with head
    struct Node* next = NULL;

    // Traverse through list
    while (current) {
        next = current->next;   // Save next node
        current->next = prev;   // Reverse pointer
        prev = current;         // Move prev forward
        current = next;         // Move current forward
    }

    display(prev);   // Display reversed list
    return prev;     // New head is 'prev'
}

// Search for a value in the linked list
void search(struct Node* head) {
    int key, pos = 1, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct Node* temp = head;

    // Traverse list to find value
    while (temp) {
        if (temp->data == key) {
            printf("Value %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Value %d not found in the list\n", key);

    display(head);
}

// Concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    // If first list is empty, return second
    if (head1 == NULL) return head2;
    // If second list is empty, return first
    if (head2 == NULL) return head1;

    // Traverse to the last node of first list
    struct Node* temp = head1;
    while (temp->next)
        temp = temp->next;

    // Link last node of first list to head of second
    temp->next = head2;

    display(head1);  // Display concatenated list
    return head1;    // Return head of combined list
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, val, ch;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Build initial linked list
    for (int i = 0; i < n; i++) {
        printf("Enter value at node %d : ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;  // First node is head
            temp = newNode;
        } else {
            temp->next = newNode; // Link new node
            temp = newNode;       // Move temp forward
        }
    }

    printf("Linked List: ");
    display(head);

    // Menu-driven linked list operations
    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Front\n2. Insert End\n3. Insert at Position\n");
        printf("4. Delete Front\n5. Delete End\n6. Delete at Position\n");
        printf("7. Reverse List\n8. Search\n9. Concatenate (self concat demo)\n");
        printf("10. Display\n11. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: head = insertFront(head); break;
            case 2: head = insertEnd(head); break;
            case 3: head = insertPos(head); break;
            case 4: head = deleteFront(head); break;
            case 5: head = deleteEnd(head); break;
            case 6: head = deletePos(head); break;
            case 7: head = reverseList(head); break;
            case 8: search(head); break;
            case 9: head = concatenate(head, head); break; // Demo self-concat
            case 10: display(head); break;
        }
    } while (ch != 11);

    return 0;
}
