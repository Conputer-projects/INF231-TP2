#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL){
        printf("!Failed to allocate memory!");
        return NULL;
    }
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

Node* inserTete(Node* head, int val){
    Node* newnode = createNode(val);
    if(newnode == NULL) return head;
    
    if(head == NULL){
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }
    
    // For circular doubly linked list
    Node* last = head->prev;
    
    newnode->next = head;
    newnode->prev = last;
    
    last->next = newnode;
    head->prev = newnode;
    
    return newnode;
}

Node* inserQueue(Node* head, int val){
    Node* newnode = createNode(val);
    if(newnode == NULL) return head;
    
    if(head == NULL){
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }
    
    // For circular doubly linked list
    Node* last = head->prev;
    
    newnode->next = head;
    newnode->prev = last;
    
    last->next = newnode;
    head->prev = newnode;
    
    return head;
}

void afficheList(Node* head){
    if(head == NULL){
        printf("Empty List\n");
        return;
    }
    
    Node* temp = head;
    printf("Head -> ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("Head\n");
}

void afficheListReverse(Node* head){
    if(head == NULL){
        printf("Empty List\n");
        return;
    }
    
    Node* temp = head->prev; // Start from last node
    printf("Head -> ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while(temp != head->prev);
    printf("Head\n");
}


int main(){
    Node* List1 = NULL;
    Node* List2 = NULL;
    int i, n, val;
    
    printf("Entrez le nombre d'elements: ");
    scanf("%d", &n);
    
    printf("\nEntrez les elements pour insertion en tete:\n");
    for(i=0; i<n; i++){
        scanf("%d", &val);
        List1 = inserTete(List1, val);
    }
    printf("Liste 1 (insertion en tete):\n");
    afficheList(List1);
    printf("Liste 1 en sens inverse:\n");
    afficheListReverse(List1);
    
    printf("\nEntrez les elements pour insertion en queue:\n");
    for(i=0; i<n; i++){
        scanf("%d", &val);
        List2 = inserQueue(List2, val);
    }
    printf("Liste 2 (insertion en queue):\n");
    afficheList(List2);
    printf("Liste 2 en sens inverse:\n");
    afficheListReverse(List2);
   
    return 0;
}

