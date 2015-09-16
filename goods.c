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

void add_good(struct Goods *ware)
{
  add_string(ware->name, "\nInsert name :");
  add_string(ware->description,"\nInsert description :");
  add_string(ware->shelf,"\nInsert shelf :");
  add_int(&ware->amount, "\nInsert amount :");
  add_int(&ware->price, "\nInsert price :");
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
