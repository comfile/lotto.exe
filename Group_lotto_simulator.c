#include "lotto.h"

typedef struct {
	int seed_money;
	int win_money;
	int total_money;

	int how_much_win[8];
} people;

void Group_lotto_simulator(void)
{
	srand(time(NULL));

	int how_much_people; //get how much people would join lotto, by user`s input
	printf("Enter how many people would participate in lotto game: ");
	scanf_s("%d", &how_much_people);
	people *person_id = (people*)malloc(how_much_people * sizeof(people));

	for (int i = 0; i < how_much_people; i++)// using person id like array
	{
		int game_count = 0;
		person_id[i].seed_money = (rand() % 100 + 1) * 1000;
		for (int k = 0; k < 8; k++)
			person_id[i].how_much_win[k] = 0;
		printf("#%d person has %d won\n", i + 1, person_id[i].seed_money);
		getch();
		do
		{
			int UserNum[6] = { 0, 0, 0, 0, 0, 0 }, WinNum[6] = { 0, 0, 0, 0, 0, 0 },
			count_m = 0, bonus_n = rand() % 45 + 1;
			bool is_bonus;
			person_id[i].seed_money -= 1000;
			game_count++;

			printingbar;
			printf("[#%d]\n", game_count);
		
			for (int i = 0; i < 6; i++) // Making different user`s number by rand()
			{
				UserNum[i] = (rand() % 45) + 1;
				for (int j = 0; j < i; j++)
					if (UserNum[i] == UserNum[j])
						i--;
			}
			fflush(stdin);

			for (int i = 0; i < 6; i++) // Making different winning number by rand()
			{
				WinNum[i] = (rand() % 45) + 1;
				for (int j = 0; j < i; j++)
					if (WinNum[i] == WinNum[j])
						i--;
			}

			for (int i = 0; i < 6; i++) 
			{ // Checking how many numbers are match to winning number//
				for (int k = 0; k < 6; k++)
				{
					if (WinNum[i] == UserNum[k])
						count_m++;
				}
			}
			if (count_m == 5)
				for (int i = 0; i < 6; i++)
					if (bonus_n == UserNum[i])
						is_bonus = true;

			printf("\nHis/Her number: %d %d %d %d %d %d\n", UserNum[0],UserNum[1], UserNum[2], UserNum[3], UserNum[4], UserNum[5]);

			printf("Winning/bonus number: %d %d %d %d %d %d / %d\n\n", WinNum[0], WinNum[1], WinNum[2], WinNum[3], WinNum[4], WinNum[5], bonus_n);

			switch (count_m) { // let user know which prize he(or she) 0got//
			case 0:
				printf("He/She didn`t get any prize\n");
				person_id[i].how_much_win[0]++;
				break;
			case 1:
				printf("He/She didn`t get any prize\n");
				person_id[i].how_much_win[1]++;
				break;
			case 2:
				printf("He/She didn`t get any prize\n");
				person_id[i].how_much_win[2]++;
				break;
			case 3:
				person_id[i].win_money += cash_5;
				printf("He/She won 5th price.\n");
				person_id[i].how_much_win[3]++;
				break;
			case 4:
				person_id[i].win_money += cash_4;
				printf("He/She won 4th price.\n");
				person_id[i].how_much_win[4]++;
				break;
			case 5:
				if (!is_bonus)
				{
					person_id[i].win_money += cash_3;
					printf("He/She won 3rd price.\n");
					person_id[i].how_much_win[5]++;
				}
				else if (is_bonus)
				{
					person_id[i].win_money += cash_2;
					printf("He/She won 2nd price.\n");
					person_id[i].how_much_win[6]++;
				}
				break;
			default:
				person_id[i].win_money += cash_1;
				printf("He/She won 1st price.\n");
				person_id[i].how_much_win[7]++;
				// break;
			}
		} while (person_id[i].seed_money);
		getch();
		_sleep(500);
		printingbar;
		printf("#%d`s play times: %d times\n\n", i + 1, game_count);
		printf("Not matched lotto`s number: %d times\n", person_id[i].how_much_win[0]);
		printf("One time matched lotto`s number: %d times\n", person_id[i].how_much_win[1]);
		printf("Two times matched lotto`s number: %d times\n", person_id[i].how_much_win[2]);
		printf("Three times matched lotto`s number: %d times\n", person_id[i].how_much_win[3]);
		printf("four times matched lotto`s number: %d times\n", person_id[i].how_much_win[4]);
		printf("Five times matched lotto`s number: %d times\n", person_id[i].how_much_win[5]);
		printf("Five times and bonus number matched lotto`s number: %d times\n", person_id[i].how_much_win[6]);
		printf("six times matched lotto`s number: %d times\n", person_id[i].how_much_win[7]);
		getch();
		system("cls");
	}
	getch();
	free(person_id);
	
}

int winning_amount_compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}