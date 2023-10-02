#include <gtest/gtest.h>

#include "Ternary/Ternary.h"
using namespace Prog2;


TEST(TernarySignalTest, DefaultConstructor) {
    TernarySignal signal;
    ASSERT_EQ(signal.getSignal(), signal::X);
}


TEST(TernarySignalTest, UndefinedConstructor) {
    TernarySignal signal('q');
    ASSERT_EQ(signal.getSignal(), signal::X);
}


TEST(TernarySignalTest, CharConstructor) {
    TernarySignal signal('0');
    ASSERT_EQ(signal.getSignal(), signal::_0);
}

TEST(TernarySignalTest, Int1Constructor) {
    TernarySignal signal(1);
    ASSERT_EQ(signal.getSignal(), signal::_1);
}


TEST(TernarySignalTest, Int0Constructor) {
    TernarySignal signal(0);
    ASSERT_EQ(signal.getSignal(), signal::_0);
}

TEST(TernarySignalTest, Int3Constructor) {
    TernarySignal signal(12);
    ASSERT_EQ(signal.getSignal(), signal::X);
}

TEST(TernarySignalTest, SignalConstructor) {
    TernarySignal signal(signal::X);
    ASSERT_EQ(signal.getSignal(), signal::X);
}

TEST(TernarySignalTest, OROperator) {
    TernarySignal signal1('0');
    TernarySignal signal2('1');
    TernarySignal result = signal1 || signal2;
    ASSERT_EQ(result.getSignal(), signal::_1);
}

TEST(TernarySignalTest, ANDOperator) {
    TernarySignal signal1('0');
    TernarySignal signal2('1');
    TernarySignal result = signal1 && signal2;
    ASSERT_EQ(result.getSignal(), signal::_0);
}

TEST(TernarySignalTest, NOTOperator) {
    TernarySignal signal('0');
    TernarySignal result = !signal;
    ASSERT_EQ(result.getSignal(), signal::_1);
}

TEST(TernarySignalTest, EqualityOperator) {
    TernarySignal signal1('0');
    TernarySignal signal2('0');
    ASSERT_EQ(signal1, signal2);
}

TEST(TernarySignalTest, InequalityOperator) {
    TernarySignal signal1('0');
    TernarySignal signal2('1');
    ASSERT_NE(signal1, signal2);
}


TEST(TernarySignalTest, OutputOperator) {
    TernarySignal signal('0');
    testing::internal::CaptureStdout();
    std::cout << signal;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "0");
}

