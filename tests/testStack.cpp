//
// Created by noj on 21.11.20.
//

#include <gtest/gtest.h>
#include <iostream>
#include "data_structures/Stack.h"
#include "algorithms/stack_algorithms.h"

TEST(Stack, Constructor)
{
    Stack<int> empty_stack(std::vector<int>({}));
    EXPECT_TRUE(empty_stack.empty());

    Stack<int> stack({1, 2, 3, 4, 5});
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.pop(), 5);
    EXPECT_EQ(stack.pop(), 4);
    EXPECT_EQ(stack.pop(), 3);
    stack.push(7);
    EXPECT_EQ(stack.peek(), 7);
    EXPECT_EQ(stack.pop(), 7);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.pop(), 0);
    EXPECT_EQ(stack.peek(), 0);
    stack.push(7);
    EXPECT_EQ(stack.pop(), 7);
}


TEST(Stack, AreValidBrackets)
{
    EXPECT_FALSE(areValidBrackets("(()"));
    EXPECT_FALSE(areValidBrackets("(()"));
    EXPECT_TRUE(areValidBrackets("([])"));
    EXPECT_TRUE(areValidBrackets("([]){}"));
    EXPECT_TRUE(areValidBrackets("{([]){}}"));
    EXPECT_FALSE(areValidBrackets("{([]){}}{"));
    EXPECT_TRUE(areValidBrackets("()"));
}

int main(int argc, char **argv)
{
    std::cout << "------------------------------ Starting Stack tests -----------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
