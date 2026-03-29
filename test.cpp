#include "CppUnitTest.h"
#include "..\Oval\Point.h"
#include "..\Oval\Oval.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(PointTest)
    {
    public:
        TEST_METHOD_INITIALIZE(Initialize)
        {
            Point::setMaxCoord(1000);
        }

        TEST_METHOD(Constructor_ValidData_Success)
        {
            Point p(100, 200);
            Assert::AreEqual(p.getX(), 100u);
            Assert::AreEqual(p.getY(), 200u);
        }

        TEST_METHOD(SetX_ValidValue_Success)
        {
            Point p;
            p.setX(500);
            Assert::AreEqual(p.getX(), 500u);
        }

        TEST_METHOD(OperatorEquals_EqualPoints_ReturnsTrue)
        {
            Point p1(100, 200);
            Point p2(100, 200);
            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(OperatorNotEquals_DifferentPoints_ReturnsTrue)
        {
            Point p1(100, 200);
            Point p2(200, 100);
            Assert::IsTrue(p1 != p2);
        }
    };

    TEST_CLASS(OvalTest)
    {
    public:
        TEST_METHOD(Constructor_ValidData_Success)
        {
            Point center(100, 100);
            Oval oval(center, 50, 30);
            
            std::string expected = "Oval(Center: (100,100), A: 50, B: 30)";
            Assert::AreEqual(oval.toString(), expected);
        }

        TEST_METHOD(GetArea_Calculation_Success)
        {
            Point center(100, 100);
            Oval oval(center, 10, 5);
            double expected = M_PI * 10 * 5;
            Assert::AreEqual(oval.getArea(), expected);
        }

        TEST_METHOD(GetPerimeter_Calculation_Success)
        {
            Point center(100, 100);
            Oval oval(center, 10, 5);
            double h = pow(10 - 5, 2) / pow(10 + 5, 2);
            double expected = M_PI * (10 + 5) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
            Assert::AreEqual(oval.getPerimeter(), expected);
        }

        TEST_METHOD(Contains_PointInside_ReturnsTrue)
        {
            Point center(100, 100);
            Oval oval(center, 50, 30);
            Point insidePoint(120, 110);
            Assert::IsTrue(oval.contains(insidePoint));
        }

        TEST_METHOD(Contains_PointOutside_ReturnsFalse)
        {
            Point center(100, 100);
            Oval oval(center, 50, 30);
            Point outsidePoint(151, 100);
            Assert::IsFalse(oval.contains(outsidePoint));
        }

        TEST_METHOD(StreamOperator_Output_Success)
        {
            Point center(100, 100);
            Oval oval(center, 50, 30);
            std::ostringstream oss;
            oss << oval;
            std::string expected = "Oval(Center: (100,100), A: 50, B: 30)";
            Assert::AreEqual(oss.str(), expected);
        }

        TEST_METHOD(StreamOperator_Input_Success)
        {
            std::istringstream iss("(200,200) 60 40");
            Oval oval;
            iss >> oval;
            std::string expected = "Oval(Center: (200,200), A: 60, B: 40)";
            Assert::AreEqual(oval.toString(), expected);
        }
    };
}
