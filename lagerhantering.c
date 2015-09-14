#include <stdio.h>
#include <stdbool.h>

struct Goods
{
  char *name;
  char *description;
  char *shelf;
  int amount;
  int price;
}; 

void print_good(struct Goods *ware);


void add_string(char *text);

void add_good(struct Goods *ware);

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
	printf("Your option: [A,a,R,r,E,e,U,u,L,l,Q,q] : ");
        //while(getchar() != '\n');
	scanf("%s", &input);
	
	if      (input == 'A' || input == 'a')
	  {
	    add_good(&all_wares[index]);
	    print_good(&all_wares[index]);
	    index++;
	  }
	else if (input == 'R' || input == 'r');
	else if (input == 'E' || input == 'e');
	else if (input == 'U' || input == 'u');
	else if (input == 'L' || input == 'l');
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

void add_good(struct Goods *ware)
{
  add_string(ware->name);
  ware->description = "Väldigt goda fina gula frukter som malin har plockat";
  ware->shelf = "A24";
  ware->amount = 1337;
  ware->price = 5;
}

void add_string(char *text)
{
  while(scanf("%s", text) == 0)
    {
      printf("\n SO PUTTENUTTIGT, BUT ITS WRONG\n :");
      scanf("%s", text);
    }
}


void print_good(struct Goods *ware)
{
  printf("\n%s\n", ware->name);
  printf("%s\n", ware->description);
  printf("%s\n", ware->shelf);
  printf("%d\n", ware->amount);
  printf("%d\n", ware->price);
}

bool correct_action(char *input)
{
  printf("Your option: [A,a,R,r,E,e,U,u,L,l,Q,q]\n | ");
  
  scanf("%c", input);
  return false;
}
