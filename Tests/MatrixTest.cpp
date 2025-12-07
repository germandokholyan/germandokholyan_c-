#include "CppUnitTest.h"
#include "..\MyLib\Matrix.h"
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(MatrixTest)
    {
    public:

        TEST_METHOD(TestConstructors)
        {
            // Тестируем конструктор принимающий int
            Matrix<int> matr(3);
            matr[0] = -12;
            matr[1] = 100;
            matr[2] = 315;
            Assert::AreEqual(3, matr.getSize());

            // Тестируем конструктор копирования
            Matrix<int> matrCpy(matr);
            Assert::AreEqual(matr[0], matrCpy[0]);
            Assert::AreEqual(matr[1], matrCpy[1]);
            Assert::AreEqual(matr[2], matrCpy[2]);
            Assert::AreEqual(3, matrCpy.getSize());
        }

        TEST_METHOD(TestToString)
        {
            Matrix<int> matr(3);
            matr[0] = -12;
            matr[1] = 100;
            matr[2] = 315;
            std::string s = matr.toString();
            Assert::IsTrue(s == "[-12, 100, 315]");
        }

        TEST_METHOD(TestAssignment)
        {
            // Тестируем оператор присваивания
            Matrix<int> matr(3);
            matr[0] = -12;
            matr[1] = 100;
            matr[2] = 315;

            Matrix<int> matrCpy;
            matrCpy = matr;

            Assert::AreEqual(matr[0], matrCpy[0]);
            Assert::AreEqual(matr[1], matrCpy[1]);
            Assert::AreEqual(matr[2], matrCpy[2]);
            Assert::AreEqual(3, matrCpy.getSize());
        }

        TEST_METHOD(TestStreamInputOutput)
        {
            Matrix<int> matr(3);
            std::stringstream ss("324 -15 6");
            ss >> matr;
            Assert::AreEqual(3, matr.getSize());
            Assert::AreEqual(324, matr[0]);
            Assert::AreEqual(-15, matr[1]);
            Assert::AreEqual(6, matr[2]);

            std::stringstream ssOut;
            ssOut << matr;
            std::string strOut = ssOut.str();
            Assert::IsTrue(strOut == "[324, -15, 6]");
        }

        TEST_METHOD(TestGenerateValues)
        {
            Matrix<int> matr(3);
            std::stringstream ss("-15 7 28");
            miit::algebra::IStreamGenerator* generator = new miit::algebra::IStreamGenerator(ss);

            // Заполняем массив с помощью генератора
            for (int i = 0; i < matr.getSize(); ++i) {
                matr[i] = generator->generate();
            }

            Assert::AreEqual(3, matr.getSize());
            Assert::AreEqual(-15, matr[0]);
            Assert::AreEqual(7, matr[1]);
            Assert::AreEqual(28, matr[2]);

            delete generator;
        }

        TEST_METHOD(TestIndexOutOfRange)
        {
            Matrix<int> matr(3);
            // Проверяем, что доступ по индексу вне диапазона вызывает исключение
            Assert::ExpectException<std::out_of_range>([&]() { matr[-1]; });
            Assert::ExpectException<std::out_of_range>([&]() { matr[3]; });
        }
    };
}
