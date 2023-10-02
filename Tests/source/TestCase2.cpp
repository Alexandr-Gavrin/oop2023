#include <gtest/gtest.h>
#include "TernaryArray/TernaryArray.h"
#include "Ternary/Ternary.h"
using namespace Prog2;
using namespace Prog3;


TEST(TernaryArrayTest, DefaultConstructor) {
    TernaryArray array;
    ASSERT_EQ(array.getSize(), 0);
    ASSERT_TRUE(array.checkUndefined());
}

TEST(TernaryArrayTest, SizeConstructor) {
    TernaryArray array(5);
    ASSERT_EQ(array.getSize(), 5);
    ASSERT_FALSE(array.checkUndefined());

    for (int i = 0; i < array.getSize(); ++i) {
        ASSERT_EQ(array[i].getSignal(), signal::X);
    }
}


TEST(TernaryArrayTest, StringConstructor) {
    TernaryArray array("werhwert");
    for (int i = 0; i < array.getSize(); ++i) {
        ASSERT_EQ(array[i].getSignal(), signal::X);
    }
}


TEST(TernaryArrayTest, ORoperator) {
    TernaryArray tmp1("QWERQWE");
    TernaryArray tmp2("QWE101WE");
    TernaryArray res = tmp2 | tmp1;
    ASSERT_EQ(res[0].getSignal(), signal::X);
}


TEST(TernaryArrayTest, ANDOperator) {
    TernaryArray tmp1("QWEE");
    TernaryArray tmp2("QWEX1WE");
    TernaryArray res = tmp2 & tmp1;
    ASSERT_EQ(res[0].getSignal(), signal::X);
}


TEST(TernaryArrayTest, NOoperator) {
    TernaryArray tmp1("111");
    TernaryArray res = ~tmp1;
    ASSERT_EQ(res[0].getSignal(), signal::_0);
}


TEST(TernaryArrayTest, EQUALoperator) {
    TernaryArray tmp1("ABCC");
    TernaryArray tmp2(4);
    ASSERT_TRUE(tmp1 == tmp2);
}


TEST(TernaryArrayTest, COPYoperator) {
    TernaryArray tmp1("ABCC");
    const TernaryArray& tmp2 = tmp1;
    ASSERT_TRUE(tmp1 == tmp2);
}



TEST(TernaryArrayTest, COPY2operator) {
    TernaryArray tmp1("ABCC");
    const TernaryArray& tmp2(tmp1);
    ASSERT_TRUE(tmp1 == tmp2);
}


TEST(TernaryArrayTest, OutputOperator) {
    TernaryArray tmp(4);
    testing::internal::CaptureStdout();
    std::cout << tmp;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "XXXX");
}



TEST(TernaryArrayTest, CopyOperator) {
    TernaryArray original(3);
    TernaryArray copy;
    copy = original;
    ASSERT_EQ(copy.getSize(), original.getSize());
    for (int i = 0; i < original.getSize(); ++i) {
        ASSERT_EQ(copy[i], original[i]);
    }
}


TEST(TernaryArrayTest, MoveConstructor) {
    TernaryArray original(5);
    TernaryArray moved(std::move(original));
    EXPECT_EQ(moved.getSize(), 5);
    EXPECT_EQ(moved[0], Prog2::signal::X);
    EXPECT_EQ(moved[2], Prog2::signal::X);
}


TEST(TernaryArrayTest, MoveAssignmentOperator) {
    TernaryArray original(5);
    original[0] = Prog2::signal::X;
    original[2] = Prog2::signal::X;
    TernaryArray destination(3);
    destination = std::move(original);
    EXPECT_EQ(destination.getSize(), 5);
    EXPECT_EQ(destination[0], Prog2::signal::X);
    EXPECT_EQ(destination[2], Prog2::signal::X);
    EXPECT_EQ(original[0], Prog2::signal::X);
}