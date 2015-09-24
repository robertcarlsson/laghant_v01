#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "goods.c"
//#include "add_from_stdin.c"
/*
void print_good(struct Goods *ware);


void add_string(char *text, char *info);

void add_good(struct Goods *ware);
*/
void list_goods(struct Goods *listOfGoods, int index);
void create_goods(struct Goods *listOfGoods);
//int choose_good(struct Goods *listOfGoods, int index);



int main(void)
{
  bool should_quit = false;
  bool valid_input = false;
  char input;
  struct Goods all_wares[100];
  struct Goods saved_wares[100];
  int index = 0;
  bool add_bool = false;
  bool change_action = false;

  while(!should_quit)
    {
      puts("\nWelcome to Warehouse number 42\n"
	   "[A]dd a good\n"
	   "[R]emove a good\n"
	   "[E]dit a good\n"
	   "[U]ndo a bad decision\n"
	   "[L]ist everything\n"
	   "[Q]uit this amazing program\n");

      valid_input = false;
      
      while(!valid_input){

	input = ask_for_char("Your options:  ", "AaRrEeUuLlQq");
	valid_input = true;


	if      (input == 'A' || input == 'a')
	  {
	    //ger oss en peakre till en bit av minne med storleken av struct goods
	    struct Goods *temp = malloc(sizeof(struct Goods));
	    //checkar så att pekaren inte är null dvs pekaren är giltig
	    assert(temp != NULL);

      	    add_good(temp);

	    bool done = false;
	    while (!done)
	      {
		 print_good(temp);
       	         int choice;
		 choice = ask_for_char("\nSave, Discard, Edit :", "SsDdEe");
		 
		 if      (choice == 'S' || choice == 's')
		   {
		     *saved_wares = *all_wares;
		     all_wares[index] = *temp;
		     index++;
		     done = true;
		     add_bool = true;
		     change_action = true;
		   }
		 else if (choice == 'D' || choice == 'd')
		   {
		     printf("Discarded\n"); //skarv
		     done = true;
		   }
		 else if (choice == 'E' || choice == 'e')
		   {
		     edit_good(temp);
		     done = false;
		   }
		 else
		   {
		     printf("\nFaulty code");
		   }
	      }
	    assert(temp != NULL);
	    free(temp);
	  }
	else if (input == 'R' || input == 'r')
	  {
	    change_action = true;
	    *saved_wares = *all_wares;
	  }
	else if (input == 'E' || input == 'e')
	  {
	    list_goods(all_wares, index);
	    change_action = true;
	  }
	else if (input == 'U' || input == 'u')
	  {
	    if (true)
	      {
		printf("\nNo action to undo: ");
	      }
	    else
	      {
		printf("\nAction Undone");
         	*all_wares = *saved_wares;
		if (add_bool)
		  {
		    index--;
		    add_bool = false;
		  }
	      }
	  }
	else if (input == 'L' || input == 'l')
	  {
	    list_goods(all_wares, index);
	  }
	else if (input == 'Q' || input == 'q')
	  {
	    printf("You can never escape\n");
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


void list_goods(struct Goods *listOfGoods, int index)
{
  char ans[1];
  for (int i = 0; i < 5; i++)
    {
      for (int j = 0;((i*20)+j < index) && (j < 20); j++)
	{
	  printf("\n%d : %s", (j+1), listOfGoods[(i*20)+j].name); 
	}
      /*
      printf("\n[N]ext, [C]ancel");
      scanf("%s" ,ans);
      if       ((ans == 'N' || ans == 'n') && (i*20) < index)
	{
	  
	}
*/							      
    }
}
/*
int choose_good(struct Goods *listOfGoods, int index)
{
  /*
      printf("\n\nChoose [W]are, [N]ext page, [C]ancel :");
      char choice[2];
      scanf("%s", choice);
      if      (*choice == 'W' || *choice == 'w')
	{ 
	  //totalindex = bigindex + smallindex
	  int totalindex;
	  //välja 
	  choose_good(&totalindex,(i*20));
	  //printa
	  print_good(&listOfGoods[totalindex]);
	}
      else if (*choice == 'C' || *choice == 'c')
	{
	  break;
	}
      else if (*choice == 'N' || *choice == 'n');  
  return 0;
}
*/

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
