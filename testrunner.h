/* 
 * Thanks to 
 * https://marcoarena.wordpress.com/2012/06/23/increase-your-qtest-productivity
 *
 * @aroquemaurel
 */

#ifndef TESTRUNNER_H
#define TESTRUNNER_H

// Qt includes
#include <QTest>
#include <QSharedPointer>
// std includes
#include <algorithm>
#include <list>
#include <iostream>

// Test Runner allows automatic execution of tests
class TestRunner
{
public:
    static TestRunner& Instance();

    template <typename T> char RegisterTest(QString name) {
        if ( std::find_if( begin(m_tests), end(m_tests), [&name](QSharedPointer<QObject>& elem)
        { return elem->objectName() == name; }) == end(m_tests) ) {
            QSharedPointer<QObject> test(new T());
            test->setObjectName(name);
            m_tests.push_back(test);
        }
        return char(1);
    }

    int RunAll();

private:
   std::list<QSharedPointer<QObject>> m_tests;
};

// Use this macro after your test declaration
#define DECLARE_TEST(className)\
    static char test_##className = TestRunner::Instance().RegisterTest<className>(QString(#className));

// Use this macro to execute all tests
#define RUN_ALL_TESTS()\
    TestRunner::Instance().RunAll();

#endif // TESTRUNNER_H
