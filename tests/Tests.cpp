#include <gtest/gtest.h>

#include "generalTests.cpp"
#include "subscriptGeneratingTests.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
