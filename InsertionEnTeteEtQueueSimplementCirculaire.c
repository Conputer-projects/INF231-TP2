#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* newnode = (Node*)malloc(sizeof(Node)); 
    if(newnode == NULL){
        printf("!Failed to allocate memory!");
        return NULL;
    }
    newnode->data = val;
    newnode->next = newnode; // Point sur lui meme pour liste circulaire
    return newnode; // Return the node
}

Node* inserTete(Node* head, int val){
    Node* newnode = createNode(val);
    if(newnode == NULL) return head;
    
    if(head == NULL){
        return newnode;
    }
    
    // trouver le dernier node
    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;
    
    // inserer en tete 
    temp->next = newnode;
    newnode->next = head;
    return newnode;
}

Node* inserQueue(Node* head, int val){
    Node* newnode = createNode(val);
    if(newnode == NULL) return head;
    
    if(head == NULL){
        return newnode;
    }
    
    // trouver le dernier node
    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;
    
    // Inserer en queue
    temp->next = newnode;
    newnode->next = head;
    return head;
}

void afficheList(Node* head){
    if(head == NULL){
        printf("Empty List\n");
        return;
    }
    
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
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
    afficheList(List1);
    
    printf("\nEntrez les elements pour insertion en queue:\n");
    for(i=0; i<n; i++){
        scanf("%d", &val);
        List2 = inserQueue(List2, val);
    }
    afficheList(List2);
    
    return 0;
}
