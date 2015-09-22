#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct Goods
{
  char name[30];
  char description[200];
  char shelf[5];
  int amount;
  int price;
};

void choose_good(int *totalindex, int bigindex);
void add_string(char *text, char *info);
void add_int(int *amount, char *info);
void edit_good(struct Goods *ware);
void print_good_edit(struct Goods *ware);

void add_good(struct Goods *ware)
{
  add_string(ware->name, "\nInsert name :");
  add_string(ware->description,"\nInsert description :");
  add_string(ware->shelf,"\nInsert shelf :");
  add_int(&ware->amount, "\nInsert amount :");
  add_int(&ware->price, "\nInsert price :");
}

void edit_good(struct Goods *ware)
{
  int choice;
  printf("\nChoose information to edit");
  print_good_edit(ware);
  printf("Edit :");
  scanf("%d", &choice);
  if      (choice == 1)
    {
      add_string(ware->name, "\nInsert name:");
    }
  else if (choice == 2)
    {
      add_string(ware->description,"\nInsert description :");
    }
  else if (choice == 3)
    {
      add_string(ware->shelf,"\nInsert shelf :");
    }
  else if (choice == 4)
    {
      add_int(&ware->amount, "\nInsert amount :");
    }
  else if (choice == 5)
    {
      add_int(&ware->price, "\nInsert price :");
    }

}

void valid_input(char *info, int *validinputs[])
{
  
}

void add_string(char *text, char *info)
{ 
  printf("%s", info);
  scanf("%s", text);
}

void add_int(int *amount, char *info)
{
  printf("%s", info);
  scanf("%d", amount); 
}


void print_good(struct Goods *ware)
{
  printf("\nName : %s ", ware->name);
  printf("\nDescription : %s ", ware->description);
  printf("\nShelf : %s", ware->shelf);
  printf("\nAmount : %d", ware->amount);
  printf("\nPrice : %d", ware->price);
}

void print_good_edit(struct Goods *ware)
{
  printf("\n1: %s\n", ware->name);
  printf("2: %s\n", ware->description);
  printf("3: %s\n", ware->shelf);
  printf("4: %d\n", ware->amount);
  printf("5: %d\n", ware->price);
} 


void choose_good(int *totalindex, int bigindex)
{
  int smallindex;
  printf("\nChoose a ware :");
  scanf("%d", &smallindex);
  *totalindex = bigindex + (--smallindex);
}

/*
void remove_ware(struct Goods *listOfGoods, int index)
{
for (int i = 0; i < 5; i++)
    {
      for (int j = 0;((i*20)+j < index) && (j < 20); j++)
	{
	  printf("\n%d : %s", (j+1), listOfGoods[(i*20)+j].name); 
	}
      
      printf("\n\nChoose [W]are to remove, [N]ext page, [C]ancel :");
      char choice[2];
      scanf("%s", choice);
      if      (*choice == 'W' || *choice == 'w')
	{ 
	  //totalindex = bigindex + smallindex
	  int totalindex;
	  //välja smallindex
	  choose_good(&totalindex,(i*20));
	  //printa
	  print_good(&listOfGoods[totalindex]);
	  while (true)
	    {
	  printf("\nAre you sure you want to remove this?[y/n]");
	  scanf("%s",&answer);
	  if (answer == y)||(answer == Y); //kall på riktig remove
	  else if (answer == n) || (answer == N) 
				     {
				       break; 
				     } 
	  else {printf("\nInvalid input, try again");
	}
      else if (*choice == 'C' || *choice == 'c')
	{
	  break;
	}
      else if (*choice == 'N' || *choice == 'n');
    }
} 

*/
  
