#include <gtest/gtest.h>
#include <demolib/demolib.h>

// Test to check answer
TEST(demoTest, BasicAssertions) {
  // Expect equality.
  EXPECT_EQ(answerToTheUltimateQuestionOfLifeTheUniverseAndEverything(), 42);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  int ret_val = RUN_ALL_TESTS();

  return ret_val;
}