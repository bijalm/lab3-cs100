#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

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

#endif //__OP_TEST_HPP__
