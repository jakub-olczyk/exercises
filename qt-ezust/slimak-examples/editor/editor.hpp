#ifndef __EDITOR__HPP
#define __EDITOR__HPP

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>

class Editor : public QMainWindow {

	Q_OBJECT

	public:

		Editor(QWidget* parent = 0);

	private:
		void initUI();
		QTextEdit* editor;

	private slots:
		void openFile();
};

#endif //__EDITOR__HPP
