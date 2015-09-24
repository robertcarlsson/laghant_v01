#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define Clear_stdin while(getchar() != '\n');

char ask_for_char(char *q, char *alt)
{
  char input = 0;

  // If choosen the ASCII all letters are made into the alternative (alt) string
  if (!strcmp("ASCII", alt))
    {
      alt = malloc(sizeof(char[26]));
      for(int i = 0; i < 26;)
	{
	  alt[i] = 65+i;
	  //alt[26+i] = 97+i;
	  i++;
	}
    }


  printf("%s [%s]\n", q, alt);

  do
    {
      if (input)
	{
	  printf("\nBad input '%c', try again [%s]\n", input, alt);
	  Clear_stdin;
	}
      input = getchar();
      ungetc(input, stdin);

    } while (strchr(alt, input) == NULL);
  Clear_stdin;
  return input;
}


int ask_for_int(char *q, int alt)
{
  int ok = 0;
  int input;

  if (alt == 0)
    {
      printf("%s [Integers]", q);
      do
	{
	  ok = scanf("%d" , &input);
	  if (!ok || input < 0)
	    {
	      printf("\nBad input '%d', try again [Integers]\n", input);
	      Clear_stdin;
	    }
	} while (!ok || input < 0);
    }
  else
    {
      printf("%s [1-%d]", q, alt);

      do
	{
	  ok = scanf("%d" , &input);
	  if (!ok || input < 1 || input > alt)
	    {
	      printf("\nBad input '%d', try again [1-%d]\n", input, alt);
	      Clear_stdin;
	    }
	} while (!ok || input < 1 || input > alt);
    }
    

  Clear_stdin;  
  return input;
}

char* ask_for_string(char *q, int size)
{
  char *input = malloc(sizeof(char[size]));
  int ok = 0;
  printf("%s [String] :", q);

  do
    {
      ok = scanf("%s", input);
      if (!ok)
	{
	  printf("\nBad input '%s', try again [String]\n", input);
	  Clear_stdin;
	}
    } while (!ok);

  Clear_stdin;
  return input;
}


char* ask_for_sentence(char *q, int size)
{
  char *input = malloc(sizeof(char[size]));
  char c = 0;
  int ok = 0;
  printf("%s [String] :", q);
  
  while (true)
    {
      c = getchar();
      if (c == '\n' || c == '\0') break;
      strcat(input, &c);
    }
  return input;
}
