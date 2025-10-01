#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
}Node;

Node* insererTri(Node* head, int val){
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = val;
	newnode->prev = NULL;
	newnode->next = NULL;
	
	//case 1: si la list est vide
	if(head == NULL){
		head = newnode;
		return head;
	}
	
	//case2 : insertion au debut
	if(val <= head->data ){
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
		return head;
	}
	
	Node* current = head;
	//parcourir la liste pour trouver la position de val
	while((current->next != NULL) && (current->next->data < val))
		current = current->next;
	//case 3; insertion a la fin
	if(current->next == NULL){
		current->next = newnode;
		newnode->prev = current;
		
	}else{//insertion au millieu
		newnode->next = current->next;
		newnode->prev = current;
		current->next->prev  = newnode;   
		current->next = newnode;
	}  
	return head;
}

//afficher les elements de la list
void afficheList(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp = temp->next; 
	}
	printf("NULL");
}


int main(){
	int i, n , val;
	Node* list = NULL;
	
	printf("\nEnter the number of Values: ");
	scanf("%d", &n);
	printf("\nEnter values: \n");
	for (i=0; i<n; i++){
		scanf("%d", &val);
		list = insererTri(list, val);
	}
	afficheList(list);
	return 0;
}
