#include "CppUnitTest.h"
#include "..\MyLib\ZeroGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(ZeroGeneratorTest)
    {
    public:

        TEST_METHOD(GenerateZero)
        {
            miit::algebra::ZeroGenerator gen;
            for (int i = 0; i < 5; ++i)
            {
                Assert::AreEqual(0, gen.generate());
            }
        }
    };
}
