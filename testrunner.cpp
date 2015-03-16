#include "testrunner.h"

TestRunner &TestRunner::Instance() {
    static TestRunner instance;
    return instance;
}

int TestRunner::RunAll() {
    int errorCode = 0;
    QStringList list;
    list << "" << "-silent";
    std::for_each( begin(m_tests), end(m_tests), [&] (QSharedPointer<QObject>& test) {
        errorCode |= QTest::qExec(test.data(), list);
        std::cout << std::endl;
    } );

    return errorCode;
}


