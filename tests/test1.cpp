#include <gtest/gtest.h>

namespace {
    int GetMeaningOfLife() {return 42;};
}

TEST(TestTopic, TrivialEquality){
    EXPECT_EQ(GetMeaningOfLife(), 42);
}

TEST(TestTopic, MoreEquality){
ASSERT_EQ(GetMeaningOfLife(), 41) << "Mistake!";

EXPECT_FLOAT_EQ(23.23F, 23.23F);
}
