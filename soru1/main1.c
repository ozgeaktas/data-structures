
#include<stdio.h> 
#include<stdlib.h> 
  
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
 void ekle(struct Node** head_ptr,int new_data){
 	//new_node için alan ayýrýyoruz.
 	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
 	
 	//deðerleri ekleyelim.
 	new_node->data = new_data;
 	new_node->next=(*head_ptr);
 	*head_ptr=new_node;
 }
 
 int say(struct Node *head){
 	int count=0;
	 
	 if(head==NULL){
	 	return 0;
	 }
	 return 1+ say(head->next);
 }

int main(){
	struct Node *head=NULL; //Boþ bir pointer tanýmlayarak baþlatýyoruz
	ekle(&head, 1); 
    ekle(&head, 2); 
    ekle(&head, 3); 
    ekle(&head, 4); 
    ekle(&head, 5); 
    
    printf("uzunluðu: %d",say(head));
    return 0;
    
}
