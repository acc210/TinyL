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
#include <math.h>
#include "InstrUtils.h"
#include "Utils.h"



int check2(int num){
  if(num==0){
    return 0;
  }
  
  while(num!=1){
	if(n%2 != 0){
	  return 0; 
	}
	n=n/2;
  }
  return 1;
  
}

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	
	Instruction * ptr = head;
	
	Instruction * a;

	
	while(ptr!=NULL){
	  if(ptr->opcode == LOADI){
		a=ptr->next;
		if(a->opcode == MUL){
		  if(check2(ptr->field1)){
		    ptr->opcode= LSHIFTI;
		    ptr->field1= a->field1;
		    ptr->field2= 2;
		    ptr->field3= a->field3;
		    ptr->next=a->next;
		    free(a);  
		  }
		}else if(a->opcode == DIV){
		   if(check2(ptr->field1)){
		    ptr->opcode= RSHIFTI;
		    ptr->field1= a->field1;
		    ptr->field2= 2;
		    ptr->field3= a->field3;
		    ptr->next=a->next;
		    free(a);  
		  }
		  
		}else{
		  
		}
	  }
	  ptr=ptr->next;
	  
	}

	if (head) 
		PrintInstructionList(stdout, head);
	    DestroyInstructionList(head);
	DestroyInstructionList(ptr);
	
	return EXIT_SUCCESS;
}

