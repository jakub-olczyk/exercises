#include "editor.hpp"
#include <QApplication>


int main (int argc, char* argv[])
{
	QApplication app(argc,argv);
	Editor e;
	e.show();
	return app.exec();
}
