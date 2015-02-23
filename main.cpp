/* 
 * Thanks to 
 * https://marcoarena.wordpress.com/2012/06/23/increase-your-qtest-productivity
 *
 * @aroquemaurel
 */

#include <QApplication>
#include <QString>
#include "testrunner.h"
#include "database/database.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile f(QString(a.applicationDirPath()+"/"+Parameters::DB_FILENAME));

    f.remove();
    return RUN_ALL_TESTS(argc, argv);
}
