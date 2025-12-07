#include "CppUnitTest.h"
#include "..\MyLib\Ex1.h"
#include "..\MyLib\IStreamGenerator.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTests
{
    TEST_CLASS(Ex1Test)
    {
    public:

        TEST_METHOD(Task1_ReplacesFirstNegative)
        {
            std::istringstream input("-5 10 -3 7");
            auto gen = std::make_unique<miit::algebra::IStreamGenerator>(input);
            miit::algebra::Ex1 ex(4, std::move(gen));
            ex.fillMatrix();

            ex.Task1(); // Должен заменить -5 на 0

            Assert::AreEqual(0, (*ex.matrix)[0]);
            Assert::AreEqual(10, (*ex.matrix)[1]);
            Assert::AreEqual(-3, (*ex.matrix)[2]); // остальные не меняются
            Assert::AreEqual(7, (*ex.matrix)[3]);
        }

        TEST_METHOD(Task1_NoNegative)
        {
            std::istringstream input("1 2 3 4");
            auto gen = std::make_unique<miit::algebra::IStreamGenerator>(input);
            miit::algebra::Ex1 ex(4, std::move(gen));
            ex.fillMatrix();

            ex.Task1(); // ничего не должно измениться

            Assert::AreEqual(1, (*ex.matrix)[0]);
            Assert::AreEqual(2, (*ex.matrix)[1]);
            Assert::AreEqual(3, (*ex.matrix)[2]);
            Assert::AreEqual(4, (*ex.matrix)[3]);
        }
    };
}
