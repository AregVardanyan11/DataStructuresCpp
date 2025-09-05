#include <gtest/gtest.h>

#include "list/circularylinkedlist/CircularLinkedList.h"
#include "list/singlylinkedlist/SinglyLinkedList.h"
#include "list/doublylinkedlist/DoublyLinkedList.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

typedef ::testing::Types<
    SinglyLinkedList<int>,
    DoublyLinkedList<int>,
    CircularLinkedList<int>
> ListImplementations;

template <typename T>
class ListTest : public ::testing::Test {
protected:
    T list;
};

TYPED_TEST_SUITE(ListTest, ListImplementations);

// ---------------- Tests ----------------

TYPED_TEST(ListTest, InitiallyEmpty) {
    EXPECT_EQ(this->list.size(), 0);
    EXPECT_TRUE(this->list.isEmpty());
}

TYPED_TEST(ListTest, AddElements) {
    this->list.push_back(10);
    this->list.push_back(20);
    this->list.push_back(30);

    EXPECT_EQ(this->list.size(), 3);
    EXPECT_EQ(this->list.get(0), 10);
    EXPECT_EQ(this->list.get(1), 20);
    EXPECT_EQ(this->list.get(2), 30);
}

TYPED_TEST(ListTest, InsertElements) {
    this->list.push_back(1);
    this->list.push_back(3);
    this->list.insert(1, 2);

    EXPECT_EQ(this->list.size(), 3);
    EXPECT_EQ(this->list.get(0), 1);
    EXPECT_EQ(this->list.get(1), 2);
    EXPECT_EQ(this->list.get(2), 3);
}

TYPED_TEST(ListTest, RemoveElements) {
    this->list.push_back(1);
    this->list.push_back(2);
    this->list.push_back(3);

    this->list.remove(1); // remove index 1 (value 2)

    EXPECT_EQ(this->list.size(), 2);
    EXPECT_EQ(this->list.get(0), 1);
    EXPECT_EQ(this->list.get(1), 3);
}

TYPED_TEST(ListTest, ClearList) {
    this->list.push_back(1);
    this->list.push_back(2);
    this->list.push_back(3);
    this->list.clear();

    EXPECT_TRUE(this->list.isEmpty());
    EXPECT_EQ(this->list.size(), 0);
}

TYPED_TEST(ListTest, ConstGet) {
    this->list.push_back(42);
    const auto& constList = this->list;

    EXPECT_EQ(constList.get(0), 42);
}

TYPED_TEST(ListTest, GetOutOfRangeThrows) {
    this->list.clear();
    EXPECT_THROW(this->list.get(0), std::out_of_range);

    this->list.push_back(10);
    EXPECT_THROW(this->list.get(1), std::out_of_range);
}

TYPED_TEST(ListTest, InsertOutOfRangeThrows) {
    EXPECT_THROW(this->list.insert(1, 10), std::out_of_range);
}

TYPED_TEST(ListTest, RemoveOutOfRangeThrows) {
    EXPECT_THROW(this->list.remove(0), std::out_of_range);
}
