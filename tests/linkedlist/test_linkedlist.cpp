#include <gtest/gtest.h>
#include <string>
#include <linkedlist/linkedlist.h>

template <typename T>
class LinkedListTest : public ::testing::Test {
protected:
};

TYPED_TEST_SUITE_P(LinkedListTest);

TYPED_TEST_P(LinkedListTest, TestConstructor) {
    LinkedList<TypeParam> list;
    EXPECT_EQ(list.Size(), 0);
    EXPECT_TRUE(list.Empty());
}

REGISTER_TYPED_TEST_SUITE_P(LinkedListTest, TestConstructor);

typedef ::testing::Types<int> MyTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(My, LinkedListTest, MyTypes);