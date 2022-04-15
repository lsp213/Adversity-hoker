#include "QtGuiFileTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiFileTest w;
	w.show();
	return a.exec();
}
