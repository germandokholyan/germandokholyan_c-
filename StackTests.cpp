#include "CppUnitTest.h"
#include "../Stack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTests
{
    TEST_CLASS(StackTest)
    {
    public:
        TEST_METHOD(Constructor_EmptyStack_IsEmpty)
        {
            Stack stack;
            Assert::IsTrue(stack.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), stack.size());
        }

        TEST_METHOD(Push_OneElement_NotEmpty)
        {
            Stack stack;
            stack.push(42);
            Assert::IsFalse(stack.isEmpty());
            Assert::AreEqual(static_cast<size_t>(1), stack.size());
        }

        TEST_METHOD(Pop_OneElement_EmptyStack)
        {
            Stack stack;
            stack.push(42);
            int value = stack.pop();
            Assert::AreEqual(42, value);
            Assert::IsTrue(stack.isEmpty());
        }

        TEST_METHOD(Peek_AfterPush_ReturnsCorrectValue)
        {
            Stack stack;
            stack.push(10);
            stack.push(20);
            Assert::AreEqual(20, stack.peek());
            Assert::AreEqual(static_cast<size_t>(2), stack.size());
        }

        TEST_METHOD(Pop_EmptyStack_ThrowsException)
        {
            Stack stack;
            auto func = [&stack]() { stack.pop(); };
            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(Peek_EmptyStack_ThrowsException)
        {
            Stack stack;
            auto func = [&stack]() { stack.peek(); };
            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(InitializerList_Constructor_CorrectOrder)
        {
            Stack stack = { 1, 2, 3 };
            Assert::AreEqual(1, stack.pop());
            Assert::AreEqual(2, stack.pop());
            Assert::AreEqual(3, stack.pop());
        }

        TEST_METHOD(CopyConstructor_IndependentCopies)
        {
            Stack stack1;
            stack1.push(10);
            stack1.push(20);

            Stack stack2(stack1);
            stack2.pop();

            Assert::AreEqual(static_cast<size_t>(2), stack1.size());
            Assert::AreEqual(static_cast<size_t>(1), stack2.size());
        }

        TEST_METHOD(AssignmentOperator_IndependentCopies)
        {
            Stack stack1;
            stack1.push(10);
            stack1.push(20);

            Stack stack2;
            stack2 = stack1;
            stack2.pop();

            Assert::AreEqual(static_cast<size_t>(2), stack1.size());
            Assert::AreEqual(static_cast<size_t>(1), stack2.size());
        }

        TEST_METHOD(ToString_EmptyStack_ReturnsEmptyBrackets)
        {
            Stack stack;
            Assert::AreEqual(std::string("[]"), stack.toString());
        }

        TEST_METHOD(ToString_NonEmptyStack_ReturnsCorrectString)
        {
            Stack stack = { 1, 2, 3 };
            Assert::AreEqual(std::string("[1, 2, 3]"), stack.toString());
        }
    };
}
