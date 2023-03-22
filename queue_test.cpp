#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <queue>

#include "two_stack_queue.h"

using ::testing::Test;
using ::testing::Types;

template <typename Queue>
class QueueTest : public Test {};

using QueueTypes = Types<std::queue<int>, TwoStackQueue<int>>;
TYPED_TEST_SUITE(QueueTest, QueueTypes);

TYPED_TEST(QueueTest, Empty) {
  using Queue = TypeParam;
  Queue q;

  EXPECT_TRUE(q.empty());
}

TYPED_TEST(QueueTest, FrontAndBack) {
  using Queue = TypeParam;
  Queue q;

  const int kMax = 1000;
  for (int i = 0; i < kMax; ++i) {
    q.push(i);
    EXPECT_EQ(q.front(), 0);
    EXPECT_EQ(q.back(), i);
    const Queue& cq = q;
    EXPECT_EQ(cq.front(), 0);
    EXPECT_EQ(cq.back(), i);
  }
}

TYPED_TEST(QueueTest, PushAndPop) {
  using Queue = TypeParam;
  Queue q;

  const int kMax = 1000;
  for (int i = 0; i < kMax; ++i) {
    q.push(i);
  }
  for (int i = 0; i < kMax; ++i) {
    EXPECT_EQ(q.front(), i);
    q.pop();
  }
  EXPECT_TRUE(q.empty());
}

TYPED_TEST(QueueTest, StaggeredPushAndPop) {
  using Queue = TypeParam;
  Queue q;

  const int kMax = 1000;
  for (int i = 0; i < kMax / 2; ++i) {
    q.push(i);
  }

  EXPECT_EQ(q.front(), 0);
  q.pop();

  for (int i = kMax / 2; i < kMax; ++i) {
    q.push(i);
  }

  for (int i = 1; i < kMax; ++i) {
    EXPECT_EQ(q.front(), i);
    q.pop();
  }
  EXPECT_TRUE(q.empty());
}
