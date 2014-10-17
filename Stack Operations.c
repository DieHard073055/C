#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct IntegerCarrier
{
	int num;
	struct IntegerCarrier * next;

}IntegerCarrier;


IntegerCarrier * createElement(int num);
void destroyElement(IntegerCarrier * victim);
int getNumberElements(IntegerCarrier * head);
void peek(IntegerCarrier * head);
void emptyStack(IntegerCarrier * head);
void pop(IntegerCarrier * head);
void DisplayALL(IntegerCarrier * head);

int main()
{
	int input;
	bool stackExists = false;
	IntegerCarrier *head,* curr, * previous;
	head = NULL;
	do
	{
		printf("\tPlease Choose an option\n\t1)Insert a new Element\n\t2)Pop\n\t3)Peek\n\t4)Display All\n\t5)Delete Everything\n\t6)Get number of Elements\n\t7)Quit\n\tYour Choice :");
		scanf("%i",&input);
		if(input == 1)
		{
			printf("\n\tPlease Enter the Number You would like to enter to your Element\n\tnumber: \n");
			scanf("%i",&input);

			if(head == NULL)
			{
				curr = head;
				curr = createElement(input);
				curr->next = NULL;
				head = curr;
				stackExists = true;
			}
			else
			{
				previous = curr;
				curr = createElement(input);
				previous->next = curr;
				curr->next = NULL;
			}

		}
		else if (input == 2)
		{
			if (stackExists == true)
			{
				pop(head);
				if(head == NULL)
				{
					stackExists = false;
				}
			}
		}
		else if(input == 3)
		{
			peek(head);
		}
		else if(input == 4)
		{
			DisplayALL(head);
		}
		else if(input == 5)
		{
			emptyStack(head);
			stackExists = false;
		}
		else if(input == 6)
		{
			printf("\n\tNumber of elements = %i",getNumberElements(head));
		}
		else if(input == 7)
		{
			exit(0);
		}
	}while(input != 7);
	return 0;
}
void pop(IntegerCarrier * head)
{
	IntegerCarrier * curr;

	for(curr = head; (curr->next) != NULL; curr = curr->next)
	{
		if((curr->next) == NULL)
			destroyElement(curr);
	}
}
IntegerCarrier * createElement(int num)
{
	IntegerCarrier * new;
	new = ( IntegerCarrier *) malloc(sizeof(IntegerCarrier));
	new->num = num;

	return new;
}
void destroyElement(IntegerCarrier * victim)
{
	if(victim != NULL)
	{
		free(victim);
	}
}
int getNumberElements(IntegerCarrier * head)
{
	int i=0;
	IntegerCarrier * curr;

	for(curr = head; curr->next != NULL; curr = curr->next)
	{
		i++;
	}
	return i;

}
void peek(IntegerCarrier * head)
{
	IntegerCarrier * curr;
	for(curr = head; curr->next != NULL; curr = curr->next)
	{
		if((curr->next) == NULL)
		printf("\n\nLast Inserted Element : %i\n",curr->num );
	}

}
void DisplayALL(IntegerCarrier * head)
{
	IntegerCarrier * curr;
	int i = 0;
	for(curr = head; (curr->next) != NULL; curr = curr->next)
	{
		printf("\n\tYou num %i : %i",i++,curr->num );
	}
}
void emptyStack(IntegerCarrier * head)
{
	if((head->next)!= NULL)
	{
		emptyStack(head->next);
	}
	free(head);
}


