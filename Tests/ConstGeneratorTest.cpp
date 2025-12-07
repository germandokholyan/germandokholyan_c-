#include "CppUnitTest.h"
#include "..\MyLib\ConstGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(ConstGeneratorTest)
    {
    public:

        TEST_METHOD(GenerateConstant)
        {
            const int VALUE = 777;
            miit::algebra::ConstGenerator gen(VALUE);
            for (int i = 0; i < 5; ++i)
            {
                Assert::AreEqual(VALUE, gen.generate());
            }
        }
    };
}
