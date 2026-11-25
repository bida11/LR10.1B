#include "pch.h"
#include "CppUnitTest.h"
#define UNIT_TEST
#include "C:\Users\sasab\source\repos\LR10.1B\LR10.1B\LR10.1B.cpp"
#include <cmath>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

Student* Sample()
{
    Student* s = new Student[4];
    s[0] = { "Shevchenko", 2, CS, 5, 5,{ 5 } };
    s[1] = { "Koval", 1, INF, 5, 4,{ 0 } };
    s[1].numerical = 5;
    s[2] = { "Bondar", 1, ME, 4, 4,{ 0 } };
    s[2].pedagogy = 4;
    s[3] = { "Adam", 2, CS, 5, 5,{ 4 } };
    return s;
}

namespace UnitTests
{
    TEST_CLASS(StudentTests)
    {
    public:
        TEST_METHOD(Test1)
        {
            Student* s = Sample();
            bool ok = (Average(s[0]) == 5.0);
            delete[] s;
            Assert::IsTrue(ok);
        }
        TEST_METHOD(Test2)
        {
            Student* s = Sample();
            bool ok = (ThirdGrade(s[1]) == 5 && ThirdGrade(s[2]) == 4);
            delete[] s;
            Assert::IsTrue(ok);
        }
        TEST_METHOD(Test3)
        {
            Student* s = Sample();
            bool ok = (abs(PercentAbove(s, 4) - 75.0) < 0.0001);
            delete[] s;
            Assert::IsTrue(ok);
        }
        TEST_METHOD(Test4)
        {
            Student* s = Sample();
            bool ok = (PercentAbove(s, 0) == 0);
            delete[] s;
            Assert::IsTrue(ok);
        }
        TEST_METHOD(Test5)
        {
            Student* s = Sample();
            bool ok = (PercentAbove(s + 2, 1) == 0);
            delete[] s;
            Assert::IsTrue(ok);
        }
    };
}
