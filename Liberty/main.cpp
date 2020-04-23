#include "Vista/mainwindow.h"
#include <QApplication>
#include <iostream>

#include "Modello/Interfacce/personaggio.h"
#include "Modello/mago.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Mago* m = new Mago("Mago", 100);
    cout << m->getCostoA1();

    return a.exec();
}
