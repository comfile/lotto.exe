# lotto.exe

## purpose
This program is based on Korean lotto 6/45, made by only C.

There are 3 mode in this game: single game mode, mock game mode, simulator mode.

## explanation
Single mode is just like common lotto program. Just getting user`s numbers, and then comparting them how much numbers are matched with winning numbers. But, I made this program work repeatly if user input y when it ask.

Mock game mode is that user get money for buying lotto by inputing amount of cash, and then buy lotto. User can stop whenever they want, and then program would let you know if your business was benefit, or loss by comparing first given money and money after lotto.

Simulator mode is that user define the number of people who participate in lotto. They would get money randomly between 1000 and 100000 won, and they would use all of them. After that, program would print out the results of them. 

## How to play & caution
1. selecting mode

There are boxes with number. If you want to go to that mode, input 1 by keyboard and press Enter. If it doesn`t work, try input number double times and press Enter. If both of them didn`t work well, shut it down and repeat it. 

2. How to input number

when you input numbers, you should input like this: "13 27 19 10 3 5" and enter. If input was not like that, unexpected results would occur.

3. input Enter key periodically when it doesn`t move to next process

If there would be no stop point in my program, information which program is providing would be printed one times, which makes program`s readability the worst. So, I made this program do next work when they input enter or any key(as I used getch() for this, it wouldn`t be appropriate explanation).It would usually happen when mode was finished. But in simulator mode, there are too many things to print: lotto`s results, stats of all lotto`s result. As user can define people`s amount, this process would be increased exponentially. So, you should input enter regularly when you think program doesn`t do anything for a little bit time(about 3 seconds over?).
