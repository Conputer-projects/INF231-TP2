#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

//fonction pour insirer un element dans la list pour que ca rest triee
Node* insererTriee(Node* head, int val){
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = val;
	newnode->next = NULL;
	if((head == NULL) || (val <= head->data)){		//verifie si list est null et inserer en tete
		newnode->next = head;
		return newnode;
	}
	else{
		Node* current = head;
		while((current->next != NULL) && (current->next->data < val)) //si list n'est pas null..parcourir justqua
			current = current->next ;				//pointeur courant pointe sur dernier element qui est < val
		newnode->next = current->next; 			// ici on insire notre val apres dernier element qui est < notre valeur
		current->next = newnode;
		return head;
	}
}

//prend la tete de list et affiche toute les elements
void afficheList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d -> ", temp->data );
		temp = temp->next; 
	}
	printf("NULL");
}

int main(){
	Node* list = NULL;
	int n, i, val;
	
	printf("How many elements do you wish to enter?: ");
	scanf("%d", &n);
	
	printf("\nEnter values:\n");
	for(i=0; i<n; i++){
		scanf("%d", &val);
		list = insererTriee(list, val);
	}
	
	afficheList(list);
	
	return 0;
}
