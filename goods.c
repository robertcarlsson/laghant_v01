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
  printf("\n%s\n", ware->name);
  printf("%s\n", ware->description);
  printf("%s\n", ware->shelf);
  printf("%d\n", ware->amount);
  printf("%d\n", ware->price);
}

void print_good_edit(struct Goods *ware)
{
  printf("\n1: %s\n", ware->name);
  printf("2: %s\n", ware->description);
  printf("3: %s\n", ware->shelf);
  printf("4: %d\n", ware->amount);
  printf("5: %d\n", ware->price);
}
