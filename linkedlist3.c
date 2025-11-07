#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertFront(struct Node* head) {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct Node* newNode = createNode(val);
    newNode->next = head;
    display(newNode);
    return newNode;
}

struct Node* insertEnd(struct Node* head) {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct Node* newNode = createNode(val);

    if (head == NULL) {
        display(newNode);
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    display(head);
    return head;
}

struct Node* insertPos(struct Node* head) {
    int val, pos;
    printf("Enter value : ");
    scanf("%d", &val);
    printf("Enter position : ");
    scanf("%d", &pos);

    if (pos == 1) {
        struct Node* newNode = createNode(val);
        newNode->next = head;
        display(newNode);
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    display(head);
    return head;
}

struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    display(head);
    return head;
}

struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    
    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    display(head);

    return head;
}

struct Node* deletePos(struct Node* head) {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        display(head);
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp || !temp->next) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    display(head);
    return head;
}

//Reversing a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    display(prev);
    return prev;
}

//Concatenate a linked list
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, val, ch;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value at node %d : ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Linked List: ");
    display(head);

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Front\n2. Insert End\n3. Insert at Position\n4. Delete Front\n5. Delete End\n6. Delete at Position\n7. Reverse List\n9.Concatenate\n8. Display\n9. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: head = insertFront(head); break;
            case 2: head = insertEnd(head); break;
            case 3: head = insertPos(head); break;
            case 4: head = deleteFront(head); break;
            case 5: head = deleteEnd(head); break;
            case 6: head = deletePos(head); break;
            case 7: head = reverseList(head); break;
            case 8: head = concatenate(head, head); break;
            case 9: display(head); break;
        }
    } while (ch != 9);

    return 0;
}
