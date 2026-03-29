#include "CppUnitTest.h"
#include "..\MyLib\IStreamGenerator.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(IStreamGeneratorTest)
    {
    public:

        TEST_METHOD(GenerateFromStream)
        {
            std::istringstream input("42");
            miit::algebra::IStreamGenerator gen(input);
            Assert::AreEqual(42, gen.generate());
        }

        TEST_METHOD(GenerateMultiple)
        {
            std::istringstream input("10 -5 0");
            miit::algebra::IStreamGenerator gen(input);
            Assert::AreEqual(10, gen.generate());
            Assert::AreEqual(-5, gen.generate());
            Assert::AreEqual(0, gen.generate());
        }
    };
}
