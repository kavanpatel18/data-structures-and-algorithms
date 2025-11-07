#include <stdio.h>
#include <stdlib.h>

/*
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head=NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data= data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void display(){
    struct Node* temp=head;
    while(temp){
        print("%d<->",temp->data);
        temp=temp->next;
    }
    print("NULL\n");
}

struct Node* insertFront(struct Node* head){
    int val;
    printf("Enter value:");
    scanf("%d",&val);

    struct Node* newNode=createNode(val);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    display();
}

struct Node* insertEnd(struct Node* head){
    int val;
    printf("Enter value:");
    scanf("%d",&val);
    struct Node* newNode=createNode(val);

    if(head==NULL){
        head=newNode;
        display();
        return head;
    }

    struct Node* temp= head;
    while(temp){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=NULL;
    display();
    return head;
}

struct Node* insertPos(struct Node* head){
    int val, pos;
    printf("Enter value and position:");
    scanf("%d %d",&val,&pos);
    struct Node* newNode=createNode(val);

    if(pos==1) insertFront(head);

    struct Node* temp = head;
    for(int i=0; temp && i<pos-1; i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;

    temp->next=newNode;
    newNode->prev=temp;
    display();
    return head;
}

struct Node* deleteFront(struct Node* head){
    if(head==NULL)print("LIssT EMpTy hehe");

    struct Node* temp = head;
    head=head->next;
    free(temp);
    display();
    return head;
}

struct Node* deleteEnd(struct Node* head){
    if(head==NULL)print("LIssT EMpTy hehe");

    struct Node* temp = head;
    while(temp->next->next) temp=temp->next;
    free(temp->next);
    temp->next=NULL;    

    display();
    return head;
}

struct Node* deletePos(struct Node* head){
    int pos;
    printf("Enter POSSY:");
    scanf("%d",&pos);
    if(pos==1) deleteFront(head);

    struct Node* temp = head;
    for(int i=0; temp && i<pos-1;i++) temp=temp->next;
    temp->next=temp->next->next;
    free(temp->next);
    display();
    return head;
}

void reverselist(){
    struct Node* prev= NULL;
    struct Node* temp=head;
    struct NOde* next=NULL;

    while(temp){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    display();

}

int main(){
    int i,n,data;
    printf("How many nodes?");
    scanf("%d",&n);
    printf("Enter initial linked list:");
    for(i=0;i<n;i++){
        scanf("%d",&data);
        struct Node* newNode=createNode(data);
        if(head=NULL) head=newNode;
        else {struct Node* temp = head;
            while(temp)temp=temp->next;
            temp->next=newNode;
            newNode->prev=temp;
        }
    }
}
    

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node*));
    newNode->data= data;
    newNode->left= NULL;
    newNode->right= NULL;
}

struct Node* insert(struct Node* root, int data){
    if (root=NULL) return createNode(data);
    if (data<root->data) root->left=insert(root->left,data);
    if (data>root->data) root->right=insert(root->right,data);
    return root;
}

void inorderTraversal(struct Node* root){
    if(root=NULL) return;
    inorderTraversal(root->left);
    printf('%d', root->data);
    inorderTraversal(root->right);
}


void preorderTraversal(struct Node* root){
    if(root=NULL) return;
    printf('%d', root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


void postorderTraversal(struct Node* root){
    if(root=NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf('%d', root->data);
}

void searchNode(struct Node* root, int key){
    while (root){
        if (key=root->data){
            printf("Value found in BST");
            return;}
        root=(key<root->data) ? root->left : root->right;

    }
}

struct Node {
int data; // Vertex number
struct Node* next; // Pointer to the next node in the adjacency list
};
// Function to create a new node with given data
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = data; // Set the vertex value
newNode->next = NULL; // Next pointer is NULL initially
return newNode; // Return the created node
}

void insertEdge(struct Node* adj[], int src, int dest){
    struct Node* newNode1=createNode(dest);
    newNode1->next=adj[src];
    adj[src]=newNode1;

    struct Node* newNode2=createNode(src);
    newNode2->next=adj[dest];
    adj[dest]=newNode2;
}

void deleteEdge(struct Node* adj[], int src, int dest){
    struct Node* prev, *temp;
    temp=adj[src];
    prev=NULL;
    
    while (temp && temp->data!=dest){
        prev=temp;
        temp=temp->next
    }
    if(temp!=NULL){
        if(prev==NULL) adj[src]=temp->next;
        else prev->next=temp->next;
        free(temp);
    }

    temp=adj[dest];
    prev=NULL;
    
    while (temp && temp->data!=src){
        prev=temp;
        temp=temp->next
    }
    if(temp!=NULL){
        if(prev==NULL) adj[dest]=temp->next;
        else prev->next=temp->next;
        free(temp);
    }

}

void deleteNode(struct Node* adj[], int v, int vertex){
    if(vertex<0 || vertex>=V){
        printf("Invalid vertex");
        return;
    }

    struct Node* temp = adj[vertex];
    while(temp){
        int connectedVertex=temp->data;
        deleteEdge(adj, vertex, connectedVertex);
        temp=adj[vertex];
    }
}

int main(){
    int v;
    struct Node** adj = (struct Node**)malloc(V*sizeof(struct Node*));

    for (int i=0;i<V;i++){
        adj[i]=NULL;
    }
    int choice, src, dest, vertex;
    printf("Enter src and dest vertices");
    if(src>=0 && src<V && dest>=0 && dest<V){
        insertEdge(adj,src,dest);
    }
}
*/