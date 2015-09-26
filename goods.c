#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "add_from_stdin.c"

struct shelf
{
  char letter;
  int nmr;
};

struct Goods
{
  char name[30];
  char description[200];
  struct shelf place; 
  int amount;
  int price;
};

void choose_good(int *totalindex, int bigindex);
void add_string(char *text, char *info);
void add_int(int *amount, char *info);
void edit_good(struct Goods *ware);
void print_good_edit(struct Goods *ware);
void shelfcheck(struct Goods *listOfGoods, char letter, int number, int index);
//struct shelf add_check_shelf(struct Goods

void add_good(struct Goods *ware, int index)
{ 
  char letter; 
  int  number;
  //add_string(ware->name, "\nInsert name :");
  strcpy(ware->name, ask_for_string("\nInsert name ", sizeof(ware->name)));

  //add_string(ware->description,"\nInsert description :");
  strcpy(ware->description, ask_for_sentence("\nInsert description ", sizeof(ware->description)));
  
  //add_string(ware->shelf,"\nInsert shelf :"); 
  ware->place.letter = ask_for_char("\nChoose Letter :", "ASCII");
  ware->place.nmr = ask_for_int("\nChoose Number :", 0);
  letter = (ware->place.letter);
  number = (ware->place.nmr); 
  shelfcheck(ware, letter, number, index);
  
  //add_int(&ware->amount, "\nInsert amount :");
  ware->amount = ask_for_int("\nInsert amount", 0);

  // add_int(&ware->price, "\nInsert price :");
  ware->price = ask_for_int("\nChoose price", 0);

}

void shelfcheck(struct Goods *listOfGoods, char letter, int number, int index)
{ 
  for (int i  = 0; i < index; i++)
    { 
      listOfGoods[i];
      if ((listOfGoods->place.letter == letter) && (listOfGoods->place.nmr == number)) 
	{ 
	  printf("Try again, shelf already exists\n");
	  *listOfGoods = listOfGoods[index];
	  add_good(listOfGoods, index);
        } 
      else {}
    }
    
}

void edit_good(struct Goods *ware)
{
  int choice;

  print_good_edit(ware);
  choice = ask_for_int("\nChoose information to edit", 5);

  if      (choice == 1)
    {
      strcpy(ware->name, ask_for_string("\nInsert name :", sizeof(ware->name)));
    }
  else if (choice == 2)
    {
      strcpy(ware->description, ask_for_sentence("\nInsert description :", sizeof(ware->description)));
    }
  else if (choice == 3)
    {
      //fixa egen shelf funcion som kan leta efter andra shelfs.
    }
  else if (choice == 4)
    {
      ware->amount = ask_for_int("\nInsert amount", 0);
    }
  else if (choice == 5)
    {
      ware->price = ask_for_int("\nChoose price", 0);
    }
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
  //printf("\nShelf : %s", ware->shelf);
  printf("\nAmount : %d", ware->amount);
  printf("\nPrice : %d", ware->price);
}

void print_good_edit(struct Goods *ware)
{
  printf("\n1: %s\n", ware->name);
  printf("2: %s\n", ware->description);
  //printf("3: %s\n", ware->shelf);
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


  
