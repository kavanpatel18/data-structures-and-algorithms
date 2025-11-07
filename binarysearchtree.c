#include <stdio.h>
#include <stdlib.h>

// Node structure for Binary Search Tree (BST)
struct Node {
    int data;               // value stored in the node
    struct Node* left;      // pointer to left child
    struct Node* right;     // pointer to right child
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // allocate memory
    newNode->data = data;   // assign value
    newNode->left = NULL;   // left child initially null
    newNode->right = NULL;  // right child initially null
    return newNode;
}

// Insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    // If tree is empty, create root
    if (root == NULL) return createNode(data);

    // If data is smaller, insert into left subtree
    if (data < root->data)
        root->left = insert(root->left, data);
    // If data is greater, insert into right subtree
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return unchanged root pointer
    return root;
}

// Inorder Traversal (Left → Root → Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;          // base case
    inorderTraversal(root->left);      // visit left subtree
    printf("%d ", root->data);         // visit root
    inorderTraversal(root->right);     // visit right subtree
}

// Preorder Traversal (Root → Left → Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);         // visit root
    preorderTraversal(root->left);     // visit left subtree
    preorderTraversal(root->right);    // visit right subtree
}

// Postorder Traversal (Left → Right → Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);    // visit left subtree
    postorderTraversal(root->right);   // visit right subtree
    printf("%d ", root->data);         // visit root
}

// Search for a value in BST
void searchNode(struct Node* root, int key) {
    // Traverse the tree until NULL or value found
    while (root != NULL) {
        if (key == root->data) {       // if value matches root
            printf("Value %d found in the BST.\n", key);
            return;
        }
        // Move to left if smaller, right if greater
        root = (key < root->data) ? root->left : root->right;
    }
    // If reached NULL, value not found
    printf("Value %d not found in the BST.\n", key);
}

// Main function with menu-driven program
int main() {
    struct Node* root = NULL; // start with empty tree
    int choice, n, val;

    // Initial insertion of nodes into the BST
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value to insert: ");
        scanf("%d", &val);
        root = insert(root, val); // insert node
    }

    // Infinite loop for menu-driven operations
    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert a new node
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2: // Inorder Traversal
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3: // Preorder Traversal
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4: // Postorder Traversal
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5: // Search a value
                printf("Enter value to search: ");
                scanf("%d", &val);
                searchNode(root, val);
                break;

            case 6: // Exit program
                printf("Exiting program.\n");
                exit(0);

            default: // Invalid input
                printf("Invalid choice. Try again.\n");
        }
    }
}
