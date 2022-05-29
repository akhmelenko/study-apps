
#include "gtest/gtest.h"
#include "square/square.h"
#include "cube/cube.h"

TEST(SquareTests, Basics)
{
    EXPECT_EQ(Square(-1), 1);
    EXPECT_EQ(Square(1), 1);
    EXPECT_EQ(Square(2), 4);
    EXPECT_EQ(Square(3), 9);
    EXPECT_EQ(Cube(3), 27);
}