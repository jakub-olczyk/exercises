#include "editor.hpp"
#include <QTextEdit>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QCoreApplication>

Editor::Editor(QWidget* parent) : QMainWindow(parent) 
{
	setWindowTitle("Slimak editor");
	resize(640,400);
	initUI();
}

void Editor::initUI()
{
	editor = new QTextEdit("Start text", this);
	setCentralWidget(editor);
	statusBar()->showMessage("Hello world");

	QMenuBar *bar = menuBar();

	QMenu *file = bar->addMenu("&File");

	QAction *open= new QAction("&Open", this);
	connect(open, SIGNAL(triggered()), this, SLOT(openFile()));

	QAction *quit = new QAction("&Quit", this);
	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

	file->addAction(open);
	file->addSeparator();
	file->addAction(quit);
}

void Editor::openFile()
{
	QString name = QFileDialog::getOpenFileName(this, "Select file to open...");
	if (name != ""){
		QFile file(name);
		file.open(QIODevice::ReadOnly);
		QTextStream input(&file);
		editor->setText(input.readAll());
		file.close();
	}

}
