#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"
#include "pow.hpp"

#include "Mult.hpp"

#include "Add.hpp"

#include "Div.hpp"

#include "Sub.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(MultTest, MultEvaluateTwoPositive) {
	Op* pos1 = new Op(4);
	Op* pos2 = new Op(6);
	Mult* test = new Mult(pos1, pos2);
	EXPECT_EQ(test->evaluate(), 24);
}

TEST(AddTest, AddEvaluateTwoPositive) {
	Op* pos1 = new Op(10);
	Op* pos2 = new Op(100);	
	Add* test = new Add(pos1, pos2);
	EXPECT_EQ(test->evaluate(), 110);
}

TEST(DivTest, DivEvaluateTwoPositive) {
	Op* pos1 = new Op(100);
	Op* pos2 = new Op(10);
	Div* test = new Div(pos1, pos2);
	EXPECT_EQ(test->evaluate(), 10);
}

TEST(SubTest, SubEvaluateTwoPositive) {
	Op* pos1 = new Op(50);
	Op* pos2 = new Op(30);
	Sub* test = new Sub(pos1, pos2);
	EXPECT_EQ(test->evaluate(), 20);
}

TEST(RandTest, RandEvaluateNonZero) {
	Rand* test = new Rand();
	// EXPECT_THAT(test->evaluate(), AllOf(Ge(0),Le(101)));
	EXPECT_TRUE( (test->evaluate() >= 0) && (test->evaluate() <= 100));
	EXPECT_TRUE( (test->evaluate() >= 0) && (test->evaluate() <= 100));
}

TEST(PowTest, PowEvaluateTwoPositive) {
	Op* pos1 = new Op(2);
	Op* pos2 = new Op(8);
	Pow* pow1 = new Pow(pos1, pos2);
	Pow* pow2 = new Pow(pos2, pos1);
	EXPECT_EQ(pow1->evaluate(), 256);
	EXPECT_EQ(pow2->evaluate(), 64);
}

TEST(PowTest, PowEvaluateOneNegative) {
	Op* pos1 = new Op(-3);
	Op* pos2 = new Op(5);
	Pow* pow1 = new Pow(pos1, pos2);
	Pow* pow2 = new Pow(pos2, pos1);
	EXPECT_EQ(pow1->evaluate(), -243);
	EXPECT_EQ(pow2->evaluate(), 0.008);
}	

TEST(PowTest, PowEvaluateTwoNegative) {
	Op* pos1 = new Op(-2);
	Op* pos2 = new Op(-5);
	Pow* pow1 = new Pow(pos1, pos2);
	Pow* pow2 = new Pow(pos2, pos1);
	EXPECT_EQ(pow1->evaluate(), -0.03125);
	EXPECT_EQ(pow2->evaluate(), 0.04);
}
	
TEST(PowTest, PowEvaluateZeroExponent) {
	Op* val = new Op(2);
	Op* exp = new Op(0);
	Pow* test = new Pow(val, exp);
	EXPECT_EQ(test->evaluate(), 1);
}

#endif //__OP_TEST_HPP__
