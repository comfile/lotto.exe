#include "lotto.h"
#include "Console_screen.h"

int main(void)
{
	bool hope_continue = true;
	char mode_select_1, mode_select_2;
	do {
		first_screen();
		scanf_s("%c", &mode_select_1);
		getc(stdin);
		if (mode_select_1 == '1') // if user input 1
		{
			system("cls");
			Start_game_screen();
			scanf_s("%c", &mode_select_2);
			getc(stdin);
			if (mode_select_2 == '1') // if user input 1
			{
				system("cls");
				Single_lotto_game();
			}
			else if (mode_select_2 == '2') // if user input 2
			{
				system("cls");
				Mock_lotto_game();
			}
			else if (mode_select_2 == '3') // if user input 3
			{
				system("cls");
				Group_lotto_simulator();
			}
		}
		else if (mode_select_1 == '2') // if user input 2
			hope_continue = false;

		system("cls");
	} while (hope_continue);

	return 0;
}