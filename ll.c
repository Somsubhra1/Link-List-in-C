#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node{
    int data;
    struct Node *next;
};

// Typedef Declaration
typedef struct Node node;

// Functions
node *createList();
node *insertAtStart(node *);
node *insertAtEnd(node *);
node *insertAtPos(node *);
node *insertBefore(node *);
node *insertAfter(node *);
node *delAtStart(node *);
node *delAtEnd(node *);
node *delAtPos(node *);
node *delBefore(node *);
node *delAfter(node *);
node *deleteList(node *);
int getListCount(node *);
void dispList(node *);
node *sortList(node *);
void search(node *);

int main(){
    node *head = NULL;
    int status = 1;
    while(status){  
        printf("List of Options\n"); 
        printf("1 : Create Link List\n"); 
        printf("2 : Insert node at start\n"); 
        printf("3 : Insert node at end\n"); 
        printf("4 : Insert node at a certain position\n"); 
        printf("5 : Insert node before another node\n"); 
        printf("6 : Insert node after another node\n"); 
        printf("7 : Delete node from start\n"); 
        printf("8 : Delete node from end\n"); 
        printf("9 : Delete node from a certain position\n"); 
        printf("10 : Delete node from before another node\n"); 
        printf("11 : Delete node from after another node\n"); 
        printf("12 : Display Node List\n"); 
        printf("13 : Display List Length\n");
        printf("14 : Search Operation\n");
        printf("15 : Sort List\n");
        printf("0 : Exit\n");
        printf("Enter Choice\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: head = createList(head);break;
            case 2: head = insertAtStart(head);break;
            case 3: head = insertAtEnd(head);break;
            case 4: head = insertAtPos(head);break;
            case 5: head = insertBefore(head);break;
            case 6: head = insertAfter(head);break;
            case 7: head = delAtStart(head);break;
            case 8: head = delAtEnd(head);break;
            case 9: head = delAtPos(head);break;
            case 10: head = delBefore(head);break;
            case 11: head = delAfter(head);break;
            case 12: dispList(head);break;
            case 13: printf("Length[List] : %d\n", getListCount(head));break;
            case 14: search(head);break;
            case 15: sortList(head);break;
            case 0: status = 0;break;
            default: printf("Invalid Choice\n");
        }
        printf("Program Terminated\n");
    }
}

// Create List
node *createList(){
    node *curNode, *newNode, *head;
    head = (node *)malloc(sizeof(node));
    printf("Enter Node Data\n");
    scanf("%d", &head->data);
    curNode = head;
    for(int i=1;i<5;i++){
        newNode = (node *)malloc(sizeof(node));
        printf("Enter Node Data\n");
        scanf("%d", &newNode->data);
        curNode->next = newNode; 
        curNode = newNode;
    }
    newNode->next = NULL;
    return head;
}

// Display Link List
void dispList(node *head){
    printf("HEAD:");
    for(node *i=head;i!=NULL;i=i->next){
        printf("%d->", i->data);
    }
    printf("NULL\n");
}

// List Count
int getListCount(node *head){
    int ctr = 0;
    for(node *i=head;i!=NULL;i=i->next)ctr++;
    return ctr;
}

// INSERT METHODS

// Insert At Start
node *insertAtStart(node *head){
    printf("Enter Node Data\n");
    int x;
    scanf("%d", &x);
    if(head == NULL){
        head = malloc(sizeof(node));
        head->data = x;
        head->next = NULL;
    }
    else{
        node *n = (node *)malloc(sizeof(node));
        n->data = x;
        n->next = head;
        head = n;
    }
    return head;
}

// Insert at End
node *insertAtEnd(node *head){
    printf("Enter Node Data\n");
    int x;
    scanf("%d", &x);
    if(head == NULL){
        head = malloc(sizeof(node));
        head->data = x;
        head->next = NULL;
    }
    else{
        node *n = (node *)malloc(sizeof(node));
        n->data = x;
        n->next = NULL;
        node *i;
        for(i=head;i->next!=NULL;i=i->next);
        i->next = n;
    }
    return head;
}

// Insert At certain position
node *insertAtPos(node *head){
    if(head == NULL){
        printf("List State:Empty; Head Node will be created\n");
        head = (node *)malloc(sizeof(node));
        printf("Enter Node Data\n");
        scanf("%d", &head->data);
        head->next = NULL;
        return head;
    }
    int pos;
    printf("Enter the position of entry\n");
    scanf("%d", &pos);
    if(pos <= getListCount(head)){
        node *n = (node *)malloc(sizeof(int));
        printf("Enter Node Data\n");
        scanf("%d", &n->data);
        node *t = head;
        for(int i=1;i<=pos-2;i++){
            t = t->next;
        }
        n->next = t->next;
        t->next = n;
    }
    else{
        printf("Invalid Position Entry\n");
    }
    return head;
}

// Insert after a certain Node
node *insertAfter(node *head){
    if(head == NULL){
        printf("List State:Empty; Head Node will be created\n");
        head = (node *)malloc(sizeof(node));
        printf("Enter Node Data\n");
        scanf("%d", &head->data);
        head->next = NULL;
        return head;
    }
    else{
        int x;
        printf("Enter Node Data after which new Node to be inserted\n");
        scanf("%d", &x);
        node *trav = head;
        while(trav->data != x){
            trav = trav->next;
        }
        node *n = (node *)malloc(sizeof(node));
        printf("Enter Node Data\n");
        scanf("%d", &n->data);
        n->next = trav->next;
        trav->next = n;
    }
    return head;
}

// Insert before a certain node
node *insertBefore(node *head){
    if(head == NULL){
        printf("List State:Empty; Head Node will be created\n");
        head = (node *)malloc(sizeof(node));
        printf("Enter Node Data\n");
        scanf("%d", &head->data);
        head->next = NULL;
        return head;
    }
    else{
        int x;
        printf("Enter Node Data before which new Node to be inserted\n");
        scanf("%d", &x);
        node *trav = head;
        while(trav->next->data != x){
            trav = trav->next;
        }
        node *n = (node *)malloc(sizeof(node));
        printf("Enter Node Data\n");
        scanf("%d", &n->data);
        n->next = trav->next;
        trav->next = n;
    }
    return head;
}

// DELETION METHODS

// Delete at Start
node *delAtStart(node *head){
    if(head == NULL){
        printf("List Underflows");
        return NULL;
    }
    else{
        node *del = head;
        head = head->next;
        printf("Node with data %d successfully deleted\n", del->data);
        free(del);
        return head;
    }
}

// Delete At End
node *delAtEnd(node *head){
    if(head == NULL){
        printf("List Underflows");
        return NULL;
    }
    else{
        node *del = head;
        while(del->next->next != NULL)del = del->next;
        node *lNode = del->next;
        del->next = NULL;
        printf("Node with data %d successfully deleted\n", lNode->data);
        free(lNode);
        return head;
    }
}

// Delete at a certain position
node *delAtPos(node *head){
    if(head == NULL){
        printf("List Underflows");
        return NULL;
    }
    printf("Enter the Position where you want to delete a Node\n");
    int pos;
    scanf("%d", &pos);
    if(pos <= getListCount(head)){
        node *trav = head;
        for(int i=1;i<=pos-2;i++){
            trav = trav->next;
        }
        node *del = trav->next;
        trav->next = del->next;
        printf("Node with data %d successfully deleted\n", del->data);
        free(del);
        return head;
    }
}

// Delete Before a Node
node *delBefore(node *head){
    if(head == NULL){
        printf("List Underflows");
        return NULL;
    }
    else{
        printf("Enter the data of the Node\n");
        int x;
        scanf("%d", &x);
        node *curNode = head, *prevNode = head;
        while(curNode->next->data!=x){
            prevNode = curNode;
            curNode = curNode->next;
        }
        prevNode->next = curNode->next;
        printf("Node with Data %d deleted succesfully\n", curNode->data);
        free(curNode);
        return head;
    }
}

// Delete After a Node
node *delAfter(node *head){
    if(head == NULL){
        printf("List Underflows");
        return NULL;
    }
    else{
        printf("Enter the data of the Node\n");
        int x;
        scanf("%d", &x);
        node *trav = head, *del;
        while(trav->data!=x){
            trav=trav->next;
        }
        del = trav->next;
        trav->next = del->next;
        printf("Node with data %d deleted successfully\n");
        free(del);
        return head;
    }
}

// Searching
void search(node *head){
    printf("Enter Data to be searched\n");
    int x;
    int ctr = 0;
    scanf("%d", &x);
    for(node *i=head;i->next!=NULL;i=i->next){
        if(i->data == x){
            ctr++;
        }
    }
    if(ctr == 0)printf("No Match Found\n");
    else printf("%d Matches Found\n", ctr);
}

// Sorting
node *sortList(node *head){
    node *temp = head, *temp1, *min;
    int x;
    while(temp != NULL) {
        temp1 = temp->next;
        min = temp;
        while(temp1 !=  NULL) {
            if(temp1->data < temp->data) {
                min = temp1;
            }
            temp1 = temp1->next;
        }
        x = min->data;
        min->data = temp->data;
        temp->data = x;
        temp = temp->next;

    }
    printf("List sorted in ascending order");
    return head;
}
