/* name : Source
 * date: 2015-01-11
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
#include <QObject>
#include <QApplication>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QWidget>
#include <QPushButton>

using namespace std;

int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	QTextStream cout(stdout);

	QSqlDatabase northwind = QSqlDatabase::addDatabase("QMYSQL");
	northwind.setHostName("localhost");
	northwind.setDatabaseName("northwind");
	northwind.setUserName("jakub");
	northwind.setPassword("");

	bool ok = northwind.open();

	cout << (ok ? "yes" : "no") << endl; // to check if we have connection 
										 //	to DBMS
 	QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM northwind.Customers");

	northwind.close();

	QWidget *window = new QWidget;
	window->resize(800,640);

    QTableView *view = new QTableView(window);
	view->resize(700,300);
    view->setModel(model);

	window->show();	
	return app.exec();
}
