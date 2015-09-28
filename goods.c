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
void edit_good(struct Goods *ware, int index, struct Goods *savedgoods);
void print_good_edit(struct Goods *ware);
void shelfie(struct Goods *array, struct shelf *temp, int index);
bool shelfcheck(struct Goods *array, struct shelf *temp, char letter, char number, int index);

void add_good(struct Goods *ware, int index, struct Goods *savedgoods)
{ 
  // char inputLetter; 
  // int  inputNumber;
  //add_string(ware->name, "\nInsert name :");
  strcpy(ware->name, ask_for_string("\nInsert name ", sizeof(ware->name)));

  //add_string(ware->description,"\nInsert description :");
  strcpy(ware->description, ask_for_sentence("\nInsert description ", sizeof(ware->description)));
  
  //add_string(ware->shelf,"\nInsert shelf :");
  shelfie(savedgoods, &ware->place, index);

   //add_int(&ware->amount, "\nInsert amount :");
   ware->amount = ask_for_int("\nInsert amount", 0);

   // add_int(&ware->price, "\nInsert price :");
   ware->price = ask_for_int("\nChoose price", 0);
}


void shelfie(struct Goods *array, struct shelf *temp, int index)
{
  // fråga om namn och nummer här sen checka med alla varor om det finns
  // annars kalla rekursivt på denna funnktion igen, tills den är klar.
  char letter;
  int number;
  do {
    letter = ask_for_char("\nChoose shelf letter: ", "ASCII");
    number = ask_for_int("\nChoose shelf number: ", 0);
  } while (shelfcheck(array, temp, letter, number, index));

  temp->nmr = number;
  temp->letter = letter;
}

bool shelfcheck(struct Goods *array, struct shelf *temp, char letter, char number, int index)
{
  for (int i = 0; i < index; i++)
    { 
      if (((array+i)->place.letter == letter) && ((array+i)->place.nmr == number))
	{
	  printf("%s\n","Try again, shelf already exists with another ware");
	  return true;
	}
    }
  return false;
}

void edit_good(struct Goods *ware, int index, struct Goods *array)
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
      shelfie(array , &ware->place, index);
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
  printf("\nShelf : %c%d", ware->place.letter, ware->place.nmr);
  printf("\nAmount : %d", ware->amount);
  printf("\nPrice : %d", ware->price);
}

void print_good_edit(struct Goods *ware)
{
  printf("\n1: %s\n", ware->name);
  printf("2: %s\n", ware->description);
  printf("3: %c%d\n", ware->place.letter, ware->place.nmr);
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

void remove_ware(struct Goods *ware)
{
  strcpy(ware->name, "");
  strcpy(ware->description, "");
  ware->place.letter = '\0';
  ware->place.nmr = 0;
  ware->amount = 0;
  ware->price = 0;
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


  
