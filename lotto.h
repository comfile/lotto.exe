#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define cash_5 5000;
#define cash_4 15000;
#define cash_3 5000000;
#define cash_2 50000000;
#define cash_1 1000000000;

#define printingbar printf("______________________________________________________________________________________________________________________\n");

void Single_lotto_game(void);
void Mock_lotto_game(void);
void Group_lotto_simulator(void);
int winning_amount_compare(const void*, const void*);