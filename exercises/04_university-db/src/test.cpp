#include "database.hpp"
#include "student.hpp"
#include <gtest/gtest.h>

struct DatabaseTest : ::testing::Test {
    Database db;
};

// TEST_F(DatabaseTest, CanAddStudentToDb_Req1_Req2)
// {
//     Student adam {
//         "Adam",
//         "Kowalski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "11223344556",
//         Gender::Male
//     };

//     EXPECT_TRUE(db.add(adam));
//     EXPECT_FALSE(db.add(adam));
// };

TEST_F(DatabaseTest, DisplayEmptyDb)
{
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
};

TEST_F(DatabaseTest, DisplayNonEmptyDb)
{
    Student adam {
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344556",
        Gender::Male
    };
    db.add(adam);
    // check adding the same person

    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344556; Male";
    EXPECT_EQ(content, expected);
}