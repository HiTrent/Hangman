#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void draw(int body)
{
	printf("%10s\n", "+----+");
	printf("%5c", '|'); printf("%5c\n", '|');

	if(body == 1 || body == 2)
	{
		printf("%5c", '*');
		printf("%5c\n", '|');
	}
	
	else if(body == 3)
	{
		printf("%5s", "_*");
		printf("%5c\n", '|');
	}

	else if(body > 3)
	{
		printf("%6s", "_*_");
		printf("%4c\n", '|');
	}

	else printf("%10c\n", '|');

	if(body > 1)
	{
		printf("%5c", '|');
		printf("%5c\n", '|');
	}
	else printf("%10c\n", '|');


	if(body == 5)
	{
		printf("%4c", '/');
		printf("%6c\n", '|');
	}

	else if(body > 5)
	{
		printf("%6s", "/ \\");
		printf("%4c\n", '|');
	}
	
	else printf("%10c\n", '|');
	
	printf("%10c\n", '|');
	printf("%12s\n\n", "--------+--");
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	
	int mis = 0;
	draw(mis);
	printf("Enter a word = ");
	char word[256]; scanf("%s", &word);
	int n = strlen(word);

	char part[n];
	for (int i = 0; i < n; i++)
	{
		word[i] = toupper(word[i]);
		part[i] = '?';
	}

	char errors[256] = {};
	int last = 0;

	while(1)
	{
		system("cls");
		draw(mis);
		if(mis > 5) break;

		printf("Word:");
		int c = 0;
		for(int i = 0; i < n; i++)
		{
			if(part[i] == '?')
			{
				printf(" _");
				c++;
			}

			else printf(" %c", part[i]);
		}
		if(!c) break;

		printf("\nMistakes (%d): %s", mis, errors);
		printf("\nLetter: ");
		char letter;
		scanf(" %c", &letter);
		fflush(stdin);
		letter = toupper(letter);

		int found = 0;
		for(int i = 0; i < n; i++)
			if(letter == word[i])
			{
				part[i] = letter;
				found = 1;
			}

		if(!found)
		{
			int repeat = 0;
			for(int i = 0; i < strlen(errors); i++)
				if(letter == errors[i])
				{					
					repeat = 1;
					break;
				}

			if(!repeat)
			{
				mis++;
				errors[last] = letter; last++;
				errors[last] = ','; last++;
				errors[last] = ' '; last++;
			}
		}
	}

	if(mis > 5)
	{
		printf("Word:");
		for(int i = 0; i < n; i++)
			printf(" %c", word[i]);

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("\nUnfortunately you lose.\n");
	}
	else printf("\nCongratulations! You win!\n");
	
	while(!kbhit());
	system("cls");
}