#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
           
    /* put in the data  */
    new_node->data  = new_data;
               
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
       
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
void printList(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);    
        temp = temp->next;  
    }
}   
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
   	 int a,x,i;
   	 scanf("%d",&a);
   	 for(i=0; i<a; i++){
   	 	scanf("%d",&x);
   	 	push(&head, x);
   	 }	
   
     
     reverse(&head);                      
     printList(head);    
     getchar();
}
