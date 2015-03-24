/* name : Source
 * date:  
 * author: Jakub Olczyk (jakub.olczyk@openmailbox.com)
 * license : Beerware license similar to the one below. But the beer goes to me ;) 
 *
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */
#include <QTextStream>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QListView>
#include <QTableView>
#include <QWidget>


int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	QTextStream cout(stdout);

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setUserName("jakub");
	db.setDatabaseName("northwind");
	db.setPassword("");

	cout << "connected: "<<(db.open() ? "yes" : "no") << endl;
	
	QSqlQueryModel* mod = new QSqlQueryModel;
	mod->setQuery("SELECT * FROM Customers");

	db.close();

	QWidget* window = new QWidget();
	window->resize(700,700);


	QListView* lista = new QListView(window);
	lista->resize(700,500);
	lista->setModel(mod);
	lista->setGeometry(0,0,700,350);

	QTableView* tab = new QTableView(window);
	tab->resize(700,500);
	tab->setModel(mod);
	tab->setGeometry(0,350,700,350);

	window->show();

	return app.exec();
}
