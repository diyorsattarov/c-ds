#include <gtest/gtest.h>
#include <linkedlist/linkedlist.h>
#include <thread>
#include <vector>
#include <future>
#include <atomic>

template <typename T>
class LinkedListTest : public ::testing::Test {
protected:
    LinkedList<T> list;
};

TYPED_TEST_SUITE_P(LinkedListTest);

TYPED_TEST_P(LinkedListTest, TestMultithreadedIncrement) {
    constexpr int numThreads = 1;
    constexpr int numElements = 2;
    int elements[numElements] = {0, -10000000};
    constexpr int targetValue = 1000000;

    for (int i = 0; i < numElements; ++i) {
        this->list.Push(TypeParam(elements[i]));
    }

    std::vector<std::thread> threads;
    std::vector<std::future<void>> futures;

    std::atomic<int> finishedThreads(0);

    for (int i = 0; i < numThreads; ++i) {
        futures.emplace_back(std::async(std::launch::async, [this, targetValue, numElements, &finishedThreads]() {
            while (true) {
                Node<TypeParam>* current = this->list.head;
                bool done = true;
                while (current != nullptr) {
                    TypeParam data = current->getData();
                    if (data < targetValue) {
                        current->setData(data + 1);
                        done = false;
                    }
                    current = current->getNext();
                }
                if (done) {
                    break;
                }
            }
            finishedThreads++;
        }));
    }

    for (auto& future : futures) {
        future.wait();
    }

    Node<TypeParam>* current = this->list.head;
    while (current != nullptr) {
        EXPECT_EQ(current->getData(), TypeParam(targetValue));
        current = current->getNext();
    }

    while (finishedThreads < numThreads) {
        std::this_thread::yield();
    }
}

REGISTER_TYPED_TEST_SUITE_P(LinkedListTest, TestMultithreadedIncrement);

typedef ::testing::Types<int> MyTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(My, LinkedListTest, MyTypes);
