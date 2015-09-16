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

void add_good(struct Goods *ware)
{
  scanf("%s", ware->name);

  strcpy(ware->description, "Väldigt goda fina gula frukter som malin har plockat");
  strcpy(ware->shelf, "A24");
  ware->amount = 1337;
  ware->price = 5;
}

void add_string(char *text, char *info)
{ 
  printf("%s", info);
  scanf("%s", text);

}


void print_good(struct Goods *ware)
{
  printf("\n%s\n", ware->name);
  printf("%s\n", ware->description);
  printf("%s\n", ware->shelf);
  printf("%d\n", ware->amount);
  printf("%d\n", ware->price);
}
