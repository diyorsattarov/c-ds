#include <gtest/gtest.h>
#include <node/node.h>

typedef ::testing::Types<int> MyTypes;
TYPED_TEST_SUITE(NodeTest, MyTypes);

template <typename T>
class NodeTest : public ::testing::Test {
public:
    Node<T> node;
};

TYPED_TEST(NodeTest, testConstructor) {
    EXPECT_THROW(this->node.getData(), std::runtime_error);
    Node<int> nodeTemp(1);
    EXPECT_EQ(nodeTemp.getData(), TypeParam(1));
}