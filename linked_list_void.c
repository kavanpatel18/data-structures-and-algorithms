#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;               // Stores data of the node
    struct Node* next;      // Pointer to the next node
};

//  Global head pointer (represents start of the linked list)
struct Node* head = NULL;

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory
    newNode->data = data;  // Assign data
    newNode->next = NULL;  // Initialize next as NULL
    return newNode;        // Return created node
}

// Function to display the linked list
void display() {
    struct Node* temp = head;    // Start from head
    while (temp) {               // Traverse until NULL
        printf("%d -> ", temp->data); // Print node value
        temp = temp->next;       // Move to next node
    }
    printf("NULL\n");            // End of list
}

// Insert node at the front
void insertFront() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct Node* newNode = createNode(val); // Create node
    newNode->next = head;   // Link new node to current head
    head = newNode;         // Update head to new node

    display();              // Show updated list
}


// Insert node at the end
void insertEnd() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct Node* newNode = createNode(val); // Create node

    if (head == NULL) {     // If list is empty
        head = newNode;     // New node becomes head
        display();
        return;
    }

    struct Node* temp = head;
    while (temp->next)      // Traverse to last node
        temp = temp->next;

    temp->next = newNode;   // Link last node to new node
    newNode->next=NULL;
    
    display();
}

// Insert node at specific position
void insertPos() {
    int val, pos;
    printf("Enter value : ");
    scanf("%d", &val);
    printf("Enter position : ");
    scanf("%d", &pos);

    if (pos == 1) { // Insert at beginning
        struct Node* newNode = createNode(val);
        newNode->next = head;
        head = newNode;
        display();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) // Traverse till pos-1
        temp = temp->next;

    if (!temp) { // If position is invalid
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = createNode(val); // Create node
    newNode->next = temp->next; // Link new node to next
    temp->next = newNode;       // Link previous node to new node
    display();
}

// Delete node from the front
void deleteFront() {
    if (head == NULL) { // If list is empty
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;  // Store head
    head = head->next;         // Move head to next node
    free(temp);                // Free old head

    display();
}

// Delete node from the end
void deleteEnd() {
    if (head == NULL) { // If empty
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) { // If only one node
        free(head);
        head = NULL;
        display();
        return;
    }

    struct Node* temp = head;
    while (temp->next->next)   // Traverse till second last node
        temp = temp->next;

    free(temp->next);          // Free last node
    temp->next = NULL;         // Set next of second last to NULL

    display();
}

// Delete node from specific position
void deletePos() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1 && head != NULL) { // Delete first node
        struct Node* temp = head;
        head = head->next;
        free(temp);
        display();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) // Traverse till pos-1
        temp = temp->next;

    if (!temp || !temp->next) { // Invalid position
        printf("Invalid position!\n");
        return;
    }

    struct Node* delNode = temp->next; // Node to delete
    temp->next = delNode->next;        // Bypass node
    free(delNode);                     // Free memory

    display();
}

// Reverse linked list
void reverseList() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current) {              // Traverse entire list
        next = current->next;      // Store next node
        current->next = prev;      // Reverse pointer
        prev = current;            // Move prev forward
        current = next;            // Move current forward
    }

    head = prev;                   // Update head
    display();
}

//Concatenating 2 linked lists
void concatenate() {
    struct Node* head2 = NULL;
    struct Node* temp = NULL;
    int n, val;

    printf("Enter number of nodes for second list: ");
    scanf("%d", &n);

    // Build second list
    for (int i = 0; i < n; i++) {
        printf("Enter value at node %d : ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head2 == NULL) {   // First node of list 2
            head2 = newNode;
            temp = newNode;
        } else {               // Append to list 2
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Reversing the reversed list to get original list
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current) {
        next = current->next;   // Store next node
        current->next = prev;   // Reverse pointer
        prev = current;         // Move prev forward
        current = next;         // Move current forward
    }

    head = prev;  // now head points to original list

    if (head == NULL) {  // If first list is empty, set head = head2
        head = head2;
    } else {
        temp = head;
        while (temp->next)      // Traverse to last node of first list
            temp = temp->next;
        temp->next = head2;     // Link last node of first list to second list
    }

    printf("Concatenated List: ");
    display();
}

// Main function
int main() {
    struct Node* temp = NULL;
    int n, val, ch;

    // Build initial linked list
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value at node %d : ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {  // If first node
            head = newNode;
            temp = newNode;
        } else {             // Append to end
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked List: ");
    display();

    // Menu-driven operations
    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Front\n2. Insert End\n3. Insert at Position\n");
        printf("4. Delete Front\n5. Delete End\n6. Delete at Position\n");
        printf("7. Reverse List\n8. Concatenate\n9. Exit\n");
        printf("Choose one option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertFront(); break;
            case 2: insertEnd(); break;
            case 3: insertPos(); break;
            case 4: deleteFront(); break;
            case 5: deleteEnd(); break;
            case 6: deletePos(); break;
            case 7: reverseList(); break;
            case 8: concatenate(); break;
        }
    } while (ch != 9);

    return 0;
}




	



