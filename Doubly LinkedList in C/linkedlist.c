//Adi Pillai, arp3np@virginia.edu, 04/20/2021, "linkedlist.c"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define PUSH_FRONT 	0
#define PUSH_BACK 	1
#define POP_FRONT 	2
#define POP_BACK 	3
#define PRINT_LIST 	4
#define HELP 		5
#define QUIT 		6
#define INVALID 	7

#define BUFFER_SIZE 20


struct list_item {
    struct list_item* prev;
    struct list_item* next;
    int datum;
};

struct list {
    struct list_item* head;
    struct list_item* tail;
    unsigned int length;
    
    int (*compare)(const void* key, const void* with);
    void (*datum_delete)(void*);
};

void printOptions();
int readInput(int* val);
int isNumber(const char* token);
int isEmpty(const char* input);

int main(){

	// TODO: INSTANTIATE YOUR LINKED LIST HERE.
  struct list * ddl = (struct list*) malloc(sizeof(struct list));
  ddl->length = 0;

	//----END----
	

	int option, val;
	printOptions();

	do {	  

		option = readInput(&val);
	        struct list_item* node = (struct list_item*) malloc(sizeof(struct list_item));
		node->datum = val;
		switch(option){
			case PUSH_FRONT:				// push onto front of list
				// TODO: Insert code to push val onto front of linked list here. 
			  if(ddl->head == NULL){
			    ddl->head = node;
			    ddl->tail = node;
			    ddl->head->next = ddl->tail;
			    ddl->tail->prev = ddl->head;
			    ddl->length += 1;
			  } else {
			    ddl->head->prev = node;
			    node->next = ddl->head;
			    ddl->head = node;
			    ddl->length += 1;
			  }
				//----END----
				break;
			case PUSH_BACK: 				// push onto back of list
				// TODO: Insert code to push val onto back of linked list here.
			  if(ddl->head == NULL){
			    ddl->head = node;
			    ddl->tail = node;
			    ddl->head->next = ddl->tail;
			    ddl->tail->prev = ddl->head;
			    ddl->length += 1;
			  } else {
                            ddl->tail->next = node;
			    node->prev = ddl->tail;
			    ddl->tail = node;
			    ddl->length += 1;
			  }
			  
				//----END----
				break;
			case POP_FRONT: 				// remove from front of list
				// TODO: Insert code to remove from front of linked list here.
				// If list is empty, do nothing.
			  if(ddl->length == 1){
			    ddl->head = NULL;
			    ddl->tail = NULL;
			    ddl->length -= 1;
			  } else if(ddl->length > 1){
			    ddl->head->next->prev = NULL;
			    ddl->head = ddl->head->next;
			    ddl->length -= 1;
			  }                               
 
				//----END----
				break;
			case POP_BACK:					// remove from back of list
				// TODO: Insert code to remove from back of linked list here.
				// If list is empty, do nothing.
				
			  if(ddl->length == 1){
			    ddl->head = NULL;
			    ddl->tail = NULL;
			    ddl->length -= 1;			  
			  } else if(ddl->length > 1){
			      ddl->tail->prev->next = NULL;
			      ddl->tail = ddl->tail->prev;
			      ddl->length -= 1;
			  }
				//----END----
				break;
			case PRINT_LIST:				// print list
				// TODO: Insert code to print list forwards here.
				// Simply print each element separated by a space as shown below:
				// Elements: 1 2 3 4 5 
				printf("Elements: ");
				struct list_item* printNode = ddl->head;
			        for(int i = 0; i < ddl->length; i++){
				  int value = printNode->datum;
				  printf("%d ", value);
				  printNode = printNode->next;
				}
				printf("\n");


				//----END----
				break;
			case HELP: 						// print menu
				printOptions();
				break;
			case QUIT: 						// quit
				break;
			case INVALID: 					// bad input
				fprintf(stderr,"Invalid command or operand, please input a valid command or help to see the list again.\n");
				break;
		}

	} while(option != QUIT);

	// TODO: free any memory used by your linked list here

	struct list_item* deletion = ddl->head;
	for(int i = 0; i < ddl->length - 1; i++){
	   deletion = deletion->next;
	   deletion->prev = NULL;
	}
	deletion = NULL;
	free(ddl);
	     
	//----END----

	return 0;
}



//---------------------------------------
//NOTE: EVERYTHING BELOW THIS LINE SHOULD NOT BE TOUCHED. IT HANDLES INPUT AND SUCH FOR YOU
//---------------------------------------

int readInput(int* val){
	char input[BUFFER_SIZE]="";
	while(isEmpty(input)){
		printf("Enter command: ");
		fgets(input, BUFFER_SIZE, stdin);
		input[strcspn(input, "\n")] = 0;
	}

	char* token = strtok(input, " ");
	
	if ((strcmp(token, "af")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_FRONT;
		} else return INVALID;
	} else if ((strcmp(token, "ab")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_BACK;
		} else return INVALID;
	} else if ((strcmp(token, "rf")) == 0){
	 	return POP_FRONT;
	} else if ((strcmp(token, "rb")) == 0){
	 	return POP_BACK;
	} else if ((strcmp(token, "p")) == 0){
	 	return PRINT_LIST;
	} else if((strcmp(token, "help")) == 0){
	 	return HELP;
	} else if((strcmp(token, "-1")) == 0){
	 	return QUIT;
	} else {
		return INVALID;
	}
}

void printOptions(){
	printf("----------------------------------------------------\n");
	printf("This test harness operates with one linked list.\n");
	printf("Use any of the following options to manipulate it:\n");
	printf("\t* af <num> --- add integer to front\n");
	printf("\t* ab <num> --- add integer to back\n");
	printf("\t* rf       --- remove front element\n");
	printf("\t* rb       --- remove back element\n");
	printf("\t* p        --- print list forward\n");
	printf("\t* help     --- print off this list\n");
	printf("\t* -1       --- exit harness\n\n");
}

int isNumber(const char* token){
	int length, i = 0;
	if (token == NULL)	return 0;
	if(token[0] == '-') 	i = 1;
	length = strlen(token);
	for (; i < length; i++){
	    if (!isdigit(token[i]))
	    	return 0;
	}

	return 1;
}

int isEmpty(const char* input){
	while (*input != '\0'){
		if (!isspace((unsigned char)*input))
			return 0;
		input++;
	}

	return 1;
}
