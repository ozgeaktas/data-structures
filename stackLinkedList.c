#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

struct Node{
	int data;
	struct Node *next;
}*top=NULL;

void push(int x){
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	if(t==NULL){
		printf("stack is full\n");
	}
	else{
    	t->data=x;
    	t->next=top;
    	top=t;
    }
}

int pop(){
	struct Node *t;
	int x=-1;
	if(top==NULL){
		printf("stack is empty\n");
	}
	else{
		t=top;
		top=top->next;
		x=t->data;
		free(t);
	}
	return x;
}

void Display(){
	struct Node *p;
	p=top;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

bool matching(char x, char y) 
{ 
    if (x == '(' && y == ')') 
        return true; 
    else if (x == '{' && y == '}') 
        return true; 
    else
        return false; 
} 



bool balanced(const char p[], int n){
	int i;
	
	for(i=0;p[i]!='\0';i++){
		if( p[i]=='('  ||  p[i]=='{' ){
			push(p[i]);
		}
		else if(p[i]==')' || p[i]=='}' ){
			if(top==NULL){
				return false;
			}
			else if(!matching(pop(),p[i])){
				return false;
			}
		}
	}
	if(top==NULL){
		return true;
	}
	else{
		return false;
	}
}

int pre(char x){
	if(x=='+' || x=='-'){
		return 1;
	}
	else if(x=='*'|| x=='/'){
		return 2;
	}
	return 0;	
}

int isOperand(char x){
	if(x=='+'|| x=='-'|| x=='*' || x=='/'){
		return 0;
	}
	else{
		return 1;
	}
}

char* InToPost( char *infix){
	
	int i=0,j=0;
	char *postfix;
    int len=strlen(infix);
	postfix=(char *)malloc((len+2)*sizeof(char));
	
	while(infix[i]!='\0'){
		if(isOperand(infix[i])){
			postfix[j++]=infix[i++];
		}
		else{
			if(pre(infix[i]) >pre(top->data)){
				push(infix[i++]);
			}
			else{
				postfix[j++]=pop();
			}
		}
	}
	
	while(top!=NULL){
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	return postfix;
}

int Evel(char *postfix){
	int i=0;
	int x1,x2,r;
	for(i=0; postfix[i]!='\0';i++){
		if(isOperand(postfix[i])){
			push(postfix[i]-'0');
		}
		else{
			x2=pop();
			x1=pop();
			switch(postfix[i]){
				case '+': r=x1+x2;
				break;
				case '-': r=x1-x2;
				break;
				case '*': r=x1*x2;
				break;
				case '/': r=x1/x2;
				break;
			}
			push(r);
		}
		
	}
	return top->data;
}


int main() {
	
	
	
	char *postfix="234*+82/-";
	printf("results is %d\n", Evel(postfix));
	
	
	
/*	char *infix="a+b*c";
	
	push('#');
	
	char *postfix=InToPost(infix);
	
	printf("%s",postfix);
	
	
	
	
/*	char *p= "{()}{({)}}";
	
	if(balanced(p,13)){
			printf("Karakter ciftleri eslendi.");
	}
	else{
		printf("Karakter ciftleri eslenmedi.");
	}
    
*/

	
	
	return 0;
}
