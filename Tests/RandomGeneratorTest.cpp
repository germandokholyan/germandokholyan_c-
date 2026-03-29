#include "CppUnitTest.h"
#include "..\MyLib\RandomGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(RandomGeneratorTest)
    {
    public:

        TEST_METHOD(GenerateInRange)
        {
            miit::algebra::RandomGenerator gen(-10, 10);
            for (int i = 0; i < 100; ++i)
            {
                int val = gen.generate();
                Assert::IsTrue(val >= -10 && val <= 10);
            }
        }
    };
}
