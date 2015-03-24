/*	name: main.cpp
 *	author: Jakub Olczyk <jakub.olczyk@openmailbox.org>
 *	date: 2014-12-26
 *	license: Beerware (rev 42)
 *	description: 	
 *	Program that converts the Celcius degree value to Farenheit.
 *	Written as an exercise in using Qt framework.
 *	This exercise comes from 'An Introduction to design patterns in C++ and Qt 
 *	(2nd Edition)' 
 *	This is mostly rewritten example 1.5 from the book.
 */

#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>		
#include <QTextStream>

inline double c_convert(double c_value)
{
	return (c_value * 1.8) + 32;
}


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QTextStream cout(stdout);				// Mimicing the STDL

	double celsius_val = 0;
	double farenheit_val = 0;

	/* We need the Celcius degree value from the user */
	celsius_val = QInputDialog::
						getDouble(0,"Temperature converter","Celcius value:",1);

	cout << "The value provided: "<< celsius_val << endl;

	/* Now we compute the corresponding value in F and display it */
	farenheit_val = c_convert(celsius_val);
	
	QString response = QString("%1 Celsius is %2 Farenheit.\n%3")
					.arg(celsius_val).arg(farenheit_val)
					.arg("Displaing the temperature table now.");
	QMessageBox::question(0,"Again?", response, 
				QMessageBox::Yes | QMessageBox::No);
	
	/* Now we are diplaying the corresponding table with converted values 
	 * rangeing from 0 to 100 with a step of 5 */	
	
	cout << "+------------------------------------+" << endl;
	cout << "|         Conversion table           |" << endl;
	cout << "|  Celcius value   | Farenheit value |" << endl;
	cout << "+------------------------------------+" << endl;

	for (int i=0; i<=100; i+=5) {
	cout << QString("|      %1         |       %2       |\n")
			.arg(i,3).arg(c_convert(i),3); // the integer specifies fieldWidth
	}
	cout << "+------------------------------------+" << endl;
	return EXIT_SUCCESS;
}
