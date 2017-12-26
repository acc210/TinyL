/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Fall 2017                                *
 *  Author: Uli                              *
 *  Student Version                          *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) { 
		WARNING("No instructions\n"); 
		exit(EXIT_FAILURE);
	}

	Instruction * ptr = head;
	

	Instruction * b;
	Instruction * c;
	
	while(ptr!=NULL){
	  if(ptr->opcode == ADD){ 
		b= ptr->prev;
		c=ptr->prev->prev;
		 if(b->opcode == LOADI && c->opcode == LOADI){
		   ptr->opcode= LOADI;
		   ptr->field1= c->field1 + b->field1;
		   ptr->field2= ptr->field3;
		   ptr->prev= c->prev;
		   c->prev->next= ptr;
	
		  free(c);
		  free(b);

		 }
		
	  }else if(ptr->opcode == SUB){ 
		b= ptr->prev;
		c=ptr->prev->prev; 
		 if(b->opcode == LOADI && c->opcode == LOADI){
		   ptr->opcode= LOADI;
		   ptr->field1= c->field1 - b->field1;
		   ptr->field2= ptr->field3;
		   ptr->prev= c->prev;
		   c->prev->next= ptr;
	
		  free(c);
		  free(b);

		 }

	  }else if(ptr->opcode == MUL){
		b= ptr->prev;
		c=ptr->prev->prev; 
		 if(b->opcode == LOADI && c->opcode == LOADI){
		   ptr->opcode= LOADI;
		   ptr->field1= c->field1 * b->field1;
		   ptr->field2= ptr->field3;
		   ptr->prev= c->prev;
		   c->prev->next= ptr;
	
		  free(c);
		  free(b);

		 }
		
	  }
	 
	  ptr=ptr->next;
	}
	/* YOUR CODE GOES HERE */

	if (head) 
		PrintInstructionList(stdout, head);
	DestroyInstructionList(head);
	//DestroyInstructionList(ptr);
	
	return EXIT_SUCCESS;
}

