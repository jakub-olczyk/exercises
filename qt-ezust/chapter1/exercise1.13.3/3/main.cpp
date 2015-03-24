/* name: main.cpp
 * author: Jakub Olczyk <jakub.olczyk@openmailbox.org>
 * date: 2014-12-26
 * license: Beerware (rev 42)
 * description:
 * Simple game of dices. Based on pseudorandom numbers.
 * If player gets 7 or 11 he wins. If player gets 2 he looses.
 * Otherwise he's playing as long as he wins or looses.
 */

#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QTextStream>

inline int roll_dice()
{
	return 1 + rand()%6;
}

inline bool check_win(int p_num)
{
	return (p_num == 7)|(p_num == 11);
}

inline bool check_loose(int p_num)
{
	return (p_num == 2);
}

int msg_win()
{
	return QMessageBox::question(0,"Dice Game",
				"You won!\nWanna play again?",
				QMessageBox::Yes | QMessageBox::No);
}

int msg_loose()
{
	return QMessageBox::question(0,"Dice Game",
				"You lost!\nWanna play again?",
				QMessageBox::Yes | QMessageBox::No);
}
int main(int argc, char* argv[])
{
QApplication app(argc,argv);
QTextStream cout(stdout);
std::srand(time(0));						  //initialize the random generator

QString info = "This is Dice Game!\nThe rules are simple:\n"
			   "* If you roll 7 or 11 at first you win! :)\n"
			   "* However if you roll 2 in your first roll you loose :(\n"
			   "* If none of above happen you keep playing until you get\n"
			   "  the value you rolled in the first time - this means you won\n"
			   "  or until you get 7 or 11 - this means that you loose\n";

QMessageBox::information(0,"Dice Game",info);

int player_num;
int answer = 0;
int current_roll=0;
do {
	player_num = roll_dice() + roll_dice();

	QMessageBox::information(0,"Dice Game",
			QString("Your number for this game: %1").arg(player_num));
	if (check_win(player_num)) 
		answer = msg_win();
	else if (check_loose(player_num))
		answer = msg_loose();	
	else{
		do {
			current_roll = roll_dice() + roll_dice(); 
			QMessageBox::information(0,"Dice Game",
					QString("Keep playing!\nYou rolled: %1")
					.arg(current_roll));
			if (check_win(current_roll)) answer = msg_loose();
			if (current_roll == player_num) answer = msg_win();
		}while (current_roll != player_num and !check_win(current_roll));
	}
} while(answer == QMessageBox::Yes);

return EXIT_SUCCESS;
}
