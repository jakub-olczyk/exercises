/*	name: main.cpp
 *	author: Jakub Olczyk <jakub.olczyk@openmailbox.org>
 *	date: 2014-12-26
 *	license: Beerware (rev 42)
 *	description:
 *
 */

#include <cstdlib>

#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QTextStream>

int main(int argc, char* argv[])
{
QApplication app(argc,argv);
QTextStream cout(stdout);
unsigned long seed = QInputDialog::
			getInt(0,"Random number generator","Seed value:",0);
std::srand(seed);

QMessageBox::information(0, "Random number generator",
	   QString("Here are pseudorandom numbers:\n- %1\n- %2\n- %3\n- %4\n")
	   .arg(rand())
	   .arg(rand())
	   .arg(rand())
	   .arg(rand()));

return EXIT_SUCCESS;
}
