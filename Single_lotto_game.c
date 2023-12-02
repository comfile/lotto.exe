#include "lotto.h"

void Single_lotto_game(void)
{
	int win_cash = 0, game_count = 0;
	srand(time(NULL));
	char keep;
	do
	{
		int UserNum[6] = { 0, 0, 0, 0, 0, 0 },
			WinNum[6] = { 0, 0, 0, 0, 0, 0 },
			count_m = 0, bonus_n = rand() % 45 + 1;
		bool is_bonus;
		game_count++;

		printingbar;
		printf("[#%d]\n", game_count);
		printf("Enter 6 numbers between 1 and 45: "); // Getting user`s input number//
		fflush(stdin);
		for (int i = 0; i < 6; i++)
		{
			scanf_s("%d", &UserNum[i]);
			if (i == 5)
				getc(stdin);
		}

		fflush(stdin);

		for (int i = 0; i < 6; i++) // Making different winning number by rand()
		{
			WinNum[i] = (rand() % 45) + 1;
			for (int j = 0; j < i; j++)
				if (WinNum[i] == WinNum[j])
					i--;
		}

		for (int i = 0; i < 6; i++)  // Checking how many numbers are match to winning number//
			for (int k = 0; k < 6; k++)
			{
				if (WinNum[i] == UserNum[k])
					count_m++;
			}
		if (count_m == 5)
			for (int i = 0; i < 6; i++)
				if (bonus_n == UserNum[i])
					is_bonus = true;

		printf("\nYour number: %d %d %d %d %d %d\n", UserNum[0],
			UserNum[1], UserNum[2], UserNum[3], UserNum[4], UserNum[5]);

		printf("Winning/bonus number: %d %d %d %d %d %d / %d\n\n", WinNum[0], WinNum[1], WinNum[2], WinNum[3], WinNum[4], WinNum[5], bonus_n);

		switch (count_m) { // let user know which prize he(or she) 0got//
		case 0: case 1: case 2:
			printf("You didn`t get any prize\n");
			break;
		case 3:
			win_cash += cash_5;
			printf("You won 5th price.\n");
			break;
		case 4:
			win_cash += cash_4;
			printf("You won 4th price.\n");
			break;
		case 5:
			if (!is_bonus)
			{
				win_cash += cash_3;
				printf("You won 3rd price.\n");
			}
			else if (is_bonus)
			{
				win_cash += cash_2;
				printf("You won 2nd price.\n");
			}
			break;
		case 6:
			win_cash += cash_1;
			printf("You won 1st price.\n");
			break;
		}

		printf("Do you want to continue? (y/n): ");
		keep = getchar();
	} while (keep == 'y');
	system("cls");
	printf("#Result\n");
	printf("\nyou got %d won in %d time(s).\n", win_cash, game_count);
	getch();
	printf("You will be back to main screen...");
	_sleep(3000);
	system("cls");

}