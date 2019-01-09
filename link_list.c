#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct list{
    int number;
    int id;
    struct list *next;
};

typedef struct list node;

int id;

void createNode(node *p);
int countNodes(node *p);
void displayNode(node *p);
void displayAllNodes(node *p);
void updateNode(node *p);

int main(){

    int exitStatus = 1;
    int choice, nodeCtr;
    node *head = NULL;
    id = 1;

    while(exitStatus){
        printf("\n\nChoose an option\n");
        printf("1: Create a Node\n");
        printf("2: Display a Node\n");
        printf("3: Display all Nodes\n");
        printf("4: Update a Node\n");
        // printf("5: Delete a Node\n");
        // printf("6: Insert a Node\n");
        printf("7: Display Node count\n");
        printf("8: Exit\n");
        printf("\nEnter option number ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1: if(head == NULL){
                        head = (node *)malloc(sizeof(node));
                        printf("\tEnter a Number: ");
                        int no;
                        scanf("%d", &no);
                        printf("\n");
                        head->number = no;
                        head->next =  NULL;
                        head->id = id++;
                    }else{
                        createNode(head);
                    }
                    printf("\tNODE ADDED!\t");
                    break;
            
            case 2: displayNode(head);break;

            case 3: displayAllNodes(head);break;

            case 4: updateNode(head);break;

            case 7: nodeCtr = countNodes(head);
                    printf("\tTotal Node count: %d\n", nodeCtr);
                    break;

            case 8: exitStatus = 0;break;
            default: printf("\nInvaid Entry of Choice.Please select from the above lits of options");
        }
    }
    return 0;
}


void createNode(node *list){ 
    node *lastNode = list;
    while(lastNode->next != NULL)
        lastNode = lastNode->next;
    int n;
    printf("\tEnter a number: ");
    scanf("%d", &n);
    printf("\n");
    node *p;
    p = (node *)malloc(sizeof(node));
    p->number = n;
    p->next = NULL;
    p->id = id++;
    lastNode->next = p;
}

void displayNode(node *list){
    printf("\tSelect a Parameter\n");
    printf("\t1: Enter Position of Node to be displayed\n");
    printf("\t2: Enter the id of Node to be displayed\n\n");
    printf("\tEnter Selection: ");
    int param, pos, data;
    scanf("%d", &param);
    printf("\n");

    switch(param){
        case 1: printf("\t\tEnter Position: ");
                scanf("%d", &pos);
                printf("\n");
                if(pos <= countNodes(list)){
                    node *n = list;
                    for(int i=1;i<=pos;i++) n = n->next;
                    printf("\tPosition : %d Id : %d Data = %d", pos, n->id, n->number);
                }else{
                    printf("\tInvalid Entry.Process Terminated\n");return;
                }
                break;

        case 2: printf("\t\tEnter id: ");
                scanf("%d", &data);
                printf("\n");
                pos = 0;
                for(node *i=list;i!=NULL;i=i->next){
                    pos++;
                    if(data == i->id){
                        printf("\tPosition: %d Id : %d Data = %d\n", pos,data, i->number);return;
                    }
                }
                printf("\tNo such Node found\n");
                break;

        default: printf("\tInvalid Entry.Process Terminated\n");return;
    }
}

void updateNode(node *list){
    printf("\tSelect a Parameter\n");
    printf("\t1: Enter Position of Node to be updated\n");
    printf("\t2: Enter the id of Node to be updated\n");
    printf("\tEnter Selection: ");
    int param, pos, data;
    scanf("%d", &param);
    printf("\n");

    switch(param){
        case 1: printf("\t\tEnter Position: ");
                scanf("%d", &pos);
                printf("\n");
                if(pos <= countNodes(list)){
                    node *n = list;
                    for(int i=1;i<=pos;i++) n = n->next;
                    printf("\t\t\tEnter New Data");
                    scanf("%d", &data);
                    printf("\n");
                    n->number = data;
                    printf("\tNODE UPDATED\n");
                }else{
                    printf("\tInvalid Entry.Process Terminated\n");return;
                }
                break;

        case 2: printf("\t\tEnter id: ");
                scanf("%d", &data);
                printf("\n");
                for(node *i=list;i!=NULL;i=i->next){
                    pos++;
                    if(data == i->id){
                        printf("\t\t\tEnter New Data: ");
                        scanf("%d", &pos);
                        printf("\n");
                        i->number = pos;
                        printf("\tNODE UPDATED\n");return;
                    }
                }
                printf("\tNo such Node found\n");
                break;

        default: printf("\tInvalid Entry.Process Terminated\n");return;
    }
}

void displayAllNodes(node *list){
    printf("\t");
    for(node *i=list;i!=NULL;i=i->next){
        printf("%d-->", i->number);
    }
    printf(" [END]\n");
}

int countNodes(node *list){
    int ctr = 0;
    for(node *i = list; i!=NULL; i=i->next){
        ctr++;
    }
    return ctr;
}



