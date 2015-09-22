#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "goods.c"

/*
void print_good(struct Goods *ware);


void add_string(char *text, char *info);

void add_good(struct Goods *ware);
*/
void list_goods(struct Goods *listOfGoods, int index);
void create_goods(struct Goods *listOfGoods);

bool correct_action(char *input);

int main(void)
{
  bool should_quit = false;
  bool valid_input = false;
  char input;
  struct Goods all_wares[100];
  int index = 0;


  while(!should_quit)
    {
      puts("Welcome to Warehouse number 42\n"
	   "[A]dd a goodie good\n"
	   "[R]emove a badie good\n"
	   "[E]dit a not so goodie good\n"
	   "[U]ndo a bad decision\n"
	   "[L]ist everything\n"
	   "[Q]uit this amazing program\n");
      
      while(!valid_input){
	printf("\nYour option: [A,a,R,r,E,e,U,u,L,l,Q,q] : ");
        //while(getchar() != '\n');
	scanf("%s", &input);
	
	if      (input == 'A' || input == 'a')
	  {
	    struct Goods *temp = malloc(sizeof(struct Goods));
	    assert(temp != NULL);

	    add_good(temp);
	    print_good(temp);
	    int choice;	   
	    printf("1:Save  2:Discard  3:Edit   :");
	    scanf("%d", &choice);
	    if      (choice == 1)
	      {
		all_wares[index] = *temp;
		index++;
	      }
	    else if (choice == 2)
	      {
		printf("Discarded\n");
	      }
	    else if (choice == 3)
	      {
		edit_good(&all_wares[index]);
	      }
	    assert(temp != NULL);
	    free(temp);
	  }
	else if (input == 'R' || input == 'r')
	  {
	    //create_goods(all_wares);
	    
	  }
	else if (input == 'E' || input == 'e');
	else if (input == 'U' || input == 'u');
	else if (input == 'L' || input == 'l')
	  {
	    list_goods(all_wares, index);
	    int val;
	    printf("\nVal av vara :");
	    scanf("%d", &val);
	    print_good(&all_wares[--val]);
	  }
	else if (input == 'Q' || input == 'q')
	  {
	    printf("You can never escape\n");
	    valid_input = true;
	    should_quit = true;
	  }
	else
	{
	  printf("Du are Dolig\n");
	  valid_input = false;
	}
      }
    }

  return 0;
}



bool correct_action(char *input)
{
  printf("Your option: [A,a,R,r,E,e,U,u,L,l,Q,q]\n | ");
  
  scanf("%c", input);
  return false;
}

void list_goods(struct Goods *listOfGoods, int index)
{
  for (int i = 0; i < 5; i++)
    {
      for (int j = 0; (i*20)+j < index && j < 20; j++)
	{
	  printf("\n%d : %s", (j+1), listOfGoods[(i*20)+j].name);
	  break;
	}
    }
}

void create_goods(struct Goods *listOfGoods)
{
  for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 20; j++)
	{
	  strcpy(listOfGoods[(i*20)+j].name, "Hej");
	}
    }
}
