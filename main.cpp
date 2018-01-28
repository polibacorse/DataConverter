#include <QCoreApplication>
#include <QThreadPool>

#include "dataconverter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataConverter *converter = new DataConverter();
    // QThreadPool takes ownership and deleted 'converter' automatically
    QThreadPool::globalInstance()->start(converter);

    return a.exec();
}
