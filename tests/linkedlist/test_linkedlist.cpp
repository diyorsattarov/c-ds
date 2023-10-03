#include <gtest/gtest.h>
#include <linkedlist/linkedlist.h>
#include <thread>
#include <vector>

template <typename T>
class LinkedListTest : public ::testing::Test {
protected:
    LinkedList<T> list;
};

TYPED_TEST_SUITE_P(LinkedListTest);

TYPED_TEST_P(LinkedListTest, TestMultithreadedPush) {
    constexpr int numThreads = 8;
    constexpr int numIterationsPerThread = 100000;

    std::vector<std::thread> threads;
    
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back([this, numIterationsPerThread]() {
            for (int j = 0; j < numIterationsPerThread; ++j) {
                this->list.Push(TypeParam(j));
            }
        });
    }

    for (std::thread& thread : threads) {
        thread.join();
    }

    EXPECT_EQ(this->list.Size(), numThreads * numIterationsPerThread);

    EXPECT_FALSE(this->list.Empty());
}

REGISTER_TYPED_TEST_SUITE_P(LinkedListTest, TestMultithreadedPush);

typedef ::testing::Types<int> MyTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(My, LinkedListTest, MyTypes);
