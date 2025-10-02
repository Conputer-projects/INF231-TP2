#include<stdio.h>
#include<stdlib.h>

typedef struct cellule{
    int val;
    struct cellule* suiv;
}cellule;

//creer nouveau cellule
cellule* createNode(int val){
    cellule* newCellule = (cellule*)malloc(sizeof(cellule));
    if(newCellule == NULL )
     {
        printf("Erreur D'allocation\n");
        exit(1);
     }   
    newCellule->val = val;
    newCellule->suiv = NULL; 
}

//inserer a la fin de liste
void insererFin(cellule** head,int val ){
    cellule* newCellule = createNode(val);
    if(*head == NULL)
        *head = newCellule;
    else
    {
        cellule* temp =  *head;
        while(temp->suiv != NULL)
            temp = temp->suiv;
        temp->suiv = newCellule;
    }
}
void afficheListe(cellule* head){
    if (head == NULL)
        printf("\nLa Liste est vide!");
    else
    {
        cellule* temp = head;
        while(temp != NULL)
        {
            printf("%d -> ", temp->val);
            temp = temp->suiv;
        }
    }
}

void suppressionOccurence(cellule** head, int elem){
    cellule* temp = *head;
    cellule* prev = NULL;

    while(temp!=NULL)
    {
        if(temp->val == elem){
            cellule* toDelete = temp;
            if(prev == NULL){
                *head = temp->suiv;
                temp = *head;
            }
            else{
                prev->suiv = temp->suiv;
                temp = temp->suiv;
            }
            free(toDelete);
        }else{
            prev = temp;
            temp =  temp->suiv;
        }
    }
}

int main(){
    cellule *head = NULL;
    int n, val, elem;

    printf("\nCombien d'elements voulez-vous inserer: ");
    scanf("%d", &n);

    printf("\nEntrez les elements : ");
    for(int i = 0; i<n; i++){
        scanf("%d", &val);
        insererFin(&head, val);
    }
    printf("\nListe avant supression: ");
    afficheListe(head);
    printf("\nEntrez l'element a supprimer: ");
    scanf("%d", &elem);

    suppressionOccurence(&head, elem);
    printf("Liste aprez suppresion: ");
    afficheListe(head);


    return 0;
}