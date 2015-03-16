#include "testrunner.h"

TestRunner &TestRunner::Instance() {
    static TestRunner instance;
    return instance;
}

int TestRunner::RunAll(int argc, char *argv[]) {
    int errorCode = 0;
    QStringList lit;
    lit << "" << "-silent";
    std::for_each( begin(m_tests), end(m_tests), [&] (QSharedPointer<QObject>& test) {
        errorCode |= QTest::qExec(test.data(), lit);
        std::cout << std::endl;
    } );

    return errorCode;
}


