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
void list_goods(struct Goods *listOfGoods, int index, int page);
void create_goods(struct Goods *listOfGoods);

int choose_listedgood(struct Goods *listOfGoods, int index);
//int choose_good(struct Goods *listOfGoods, int index);

struct action
{
  enum { NOTHING, ADD, REMOVE, EDIT } type;
  struct Goods saved;
  struct Goods *mark;
  /*
  union
  {
    struct { Goods saved }; //Remove
    struct { Goods *point, Goods old}; //Edit
  };
  */
};

int main(void)
{
  char input = 1;
  struct Goods all_wares[100];

  int index = 0;

  struct action undo;

  while(input != 'Q' && input != 'q')
    {
      puts("\n\nWelcome to Warehouse number 42\n"
	   "[A]dd a good\n"
	   "[R]emove a good\n"
	   "[E]dit a good\n"
	   "[P]rint a good\n"
	   "[U]ndo a bad decision\n"
	   "[L]ist everything\n"
	   "[Q]uit this amazing program\n");

	input = ask_for_char("Your options:  ", "AaRrEePpUuLlQq");

	if      (input == 'A' || input == 'a')
	  {
	    //ger oss en pekare till en bit av minne med storleken av struct goods
	    struct Goods *temp = malloc(sizeof(struct Goods));
	    //checkar så att pekaren inte är null dvs pekaren är giltig
	    assert(temp != NULL);

      	    add_good(temp, index, all_wares);

	    bool done = false;
	    char choice;

	    while (!done)
	      {
		 print_good(temp);
		 choice = ask_for_char("\nSave, Discard, Edit :", "SsDdEe");
		 
		 if      (choice == 'S' || choice == 's')
		   {
		     undo.type = 1;
		     undo.mark = &all_wares[index];

		     all_wares[index] = *temp;
		     index++;
		     done = true;

		   }
		 else if (choice == 'D' || choice == 'd')
		   {
		     printf("Discarded\n"); //skarv
		     done = true;
		   }
		 else if (choice == 'E' || choice == 'e')
		   {
		     edit_good(temp, index, all_wares);
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
	    int choosenGood = choose_listedgood(all_wares, index);
	    if (choosenGood >= 0)
	      {
		undo.type = 2;
		undo.mark = &all_wares[choosenGood];
		undo.saved = all_wares[choosenGood];
		remove_ware(&all_wares[choosenGood]);
		
	      }
	  }
	else if (input == 'E' || input == 'e')
	  {
	    int choosenGood = choose_listedgood(all_wares, index);
	    if (choosenGood >= 0)
	      {
		undo.type = 3;
		undo.mark = &all_wares[choosenGood];
		undo.saved = all_wares[choosenGood];
		edit_good(&all_wares[choosenGood], index, all_wares);
		
	      }
	  }
	else if (input == 'P' || input == 'p')
	  {
	    int choosenGood = choose_listedgood(all_wares, index);
	    if (choosenGood >= 0)
	      {
		print_good(&all_wares[choosenGood]);
	      }
	  }
	else if (input == 'U' || input == 'u')
	  {
	    if (undo.type == 0)
	      {
		printf("\nNothing to undo");
	      }
	    // Add
	    else if (undo.type == 1)
	      {
		remove_ware(undo.mark);
		undo.type = 0;
		index--;
	      }
	    // Remove
	    else if (undo.type == 2)
	      {
		*undo.mark = undo.saved;
		undo.type = 0;
	      }
	    // Edit
	    else if (undo.type == 3)
	      {
		*undo.mark = undo.saved;
		undo.type = 0;
	      }
	  }
	else if (input == 'L' || input == 'l')
	  {
	    int page = 0;
	    char choice = 1;
	    while (choice != 'C' && choice != 'c')
	      {

		list_goods(all_wares, index, page);
		//för att se om det finns mer varor på nästa page, annars är det "end page"
		if (index >((1+page)*20))
		  {
		    
		    choice = ask_for_char("\nNext page or Cancel ", "NnCc");
		  }
		else 
		  {
		    choice = ask_for_char("\nEnd page, please Cancel", "Cc"); 
		  }	
		if (choice == 'N' || choice == 'n')
		  {
		    page++;
		  }
	      }
	  }
	else
	  {
	    printf("Du are Dolig\n");
	  }
    }
  return 0;
}


int choose_listedgood(struct Goods *listOfGoods, int index)
{
  int page = 0;
  char choice = 1;

  while (choice != 'C' && choice != 'c')
    {

      list_goods(listOfGoods, index, page);
      if (index >((1+page)*20))
	{	    
	  choice = ask_for_char("\nChoose ware, Next page or Cancel", "WwNnCc");
	}
      else 
	{
	  choice = ask_for_char("\nEnd page, Choose ware or Cancel", "WwCc"); 
	}	
      if (choice == 'N' || choice == 'n')
	{
	  page++;
	}
      else if (choice == 'W' || choice == 'w')
	{
	  //Returna valet-1 så det blir det correcta indexet
	  return (ask_for_int("Choose ware: ", 20) -1);	  
	}
    }
  //för att acceptera att man cancelar ifrån den här functionen utan att ange en vara.
  return -1;
}


void list_goods(struct Goods *listOfGoods, int index, int page)
{
  for (int i = 0; i < 20 && i < index; i++)
    {
      printf("\n%d. %s", (i+1), listOfGoods[i+(page*20)].name);
    }
}
