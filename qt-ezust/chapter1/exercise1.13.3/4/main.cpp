/* name: main.cpp
 * author: Jakub Olczyk <jakub.olczyk@openmailbox.org>
 * date: 2014-12-27
 * license: Beerware (rev 42)
 * description: 
 * Program that takes 2 numbers, one that is the actual cost and second that is
 * the money the customer gave. Program must compute the change in 
 * 5$,2$,1$,50c,20c,10c,5c,2c,1c.
 */

#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <cmath>

int to_gr(double price)
{
	return 	
}

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);	

	QString startmsg = "This is the Change dispenser program.\n"
	"It will provide the information about the change in this nominal values\n"
	"50zl, 10zl, 5zl, 2zl, 1zl, 50gr, 20gr, 10gr, 5gr, 2gr, 1gr\n";

	QMessageBox::information(0,"Change dispenser",startmsg);
	int gr_value, gr_given;
	
	gr_value = to_gr(QInputDialog::getDouble(0,"Change dispenser",
				"Give me the cost value:",0));

	return EXIT_SUCCESS;
}
