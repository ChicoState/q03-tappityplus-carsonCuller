/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"

 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, matching){
	tappity test("Type this phrase exactly");
	test.entry("Type this phrase exactly");
	double accuracy = test.accuracy();
	ASSERT_EQ(accuracy, 100);
}

TEST(tappityTest, not_matching_same_length){
	tappity test("Type this phrase exactly");
	test.entry("Type this phrase exactlo");
	double accuracy = test.accuracy();
	ASSERT_NE(accuracy, 100);
}

TEST(tappityTest, not_matching_diff_length){
	tappity test("Type this phrase exactly");
	test.entry("Bad entry");
	double accuracy = test.accuracy();
	ASSERT_NE(accuracy, 100);
}

TEST(tappityTest, same_length){
	tappity test("Test phrase");
	test.entry("Same length");
	int length = test.length_difference();
	ASSERT_EQ(length, 0);
}

TEST(tappityTest, diff_length){
	tappity test("Test phrase");
	test.entry("Different length");
	int length = test.length_difference();
	ASSERT_NE(length, 0);
}

TEST(tappityTest, ref_longer_by_5){
	tappity test("123456");
	test.entry("1");
	int length = test.length_difference();
	ASSERT_EQ(length, 5);
}

TEST(tappityTest, entry_longer_by_5){
	tappity test("1");
	test.entry("123456");
	int length = test.length_difference();
	ASSERT_EQ(length, 5);
}

TEST(tappityTest, empty_ref){
	tappity test("");
	test.entry("123456");
	double accuracy = test.accuracy();
	ASSERT_EQ(accuracy, 0);
}

TEST(tappityTest, empty_entry){
	tappity test("123");
	test.entry("");
	double accuracy = test.accuracy();
	ASSERT_EQ(accuracy, 0);
}

TEST(tappityTest, empty_both){
	tappity test("");
	test.entry("");
	double accuracy = test.accuracy();
	ASSERT_EQ(accuracy, 100);
}

TEST(tappityTest, case_sensitive){
	tappity test("TYPE THIS PHRASE");
	test.entry("type this phrase");
	double accuracy = test.accuracy();
	ASSERT_NE(accuracy, 100);
}

TEST(tappityTest, accuracy_check_first_half){
	tappity test("123456");
	test.entry("123");
	double accuracy = test.accuracy();
	ASSERT_EQ(accuracy, 50);
}

TEST(tappityTest, accuracy_check_second_half){
	tappity test("123456");
	test.entry("...456");
	double accuracy = test.accuracy();
	ASSERT_EQ(accuracy, 50);
}

TEST(tappityTest, accuracy_check_scattered){
	tappity test("123456");
	test.entry("1.3.5.");
	double accuracy = test.accuracy();
	ASSERT_EQ(accuracy, 50);
}

TEST(tappityTest, accuracy_check_oneThird){
	tappity test("123456");
	test.entry("12");
	double accuracy = test.accuracy();
	ASSERT_EQ(accuracy, 33);
}


