#include "../lib/MergeSort.h"
#include "gtest/gtest.h"

TEST (MergeSortTest, BasicCase) {
  vector<int> v;
  v.push_back(1);
  v.push_back(5);
  v.push_back(3);
  v.push_back(2);
  v.push_back(4);
  
  vector<int> v_sorted = MergeSort::sort(v);
  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(v_sorted.at(i), i + 1);
  }
}

//merge test 2
TEST (MergeSortTest2, BasicCase) {
  //this vector has odd numbers starting at 5
  vector<int> v;
  v.push_back(49);
  v.push_back(29);
  v.push_back(31);
  v.push_back(33);
  v.push_back(35);
  v.push_back(39);
  v.push_back(41);
  v.push_back(43);
  v.push_back(7);
  v.push_back(37);
  v.push_back(13);
  v.push_back(15);
  v.push_back(23);
  v.push_back(17);
  v.push_back(21);
  v.push_back(11);
  v.push_back(9);
  v.push_back(27);
  v.push_back(5);
  v.push_back(45);
  v.push_back(19);
  v.push_back(25);
  v.push_back(47);


  
  vector<int> v_sorted = MergeSort::sort(v);
  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(v_sorted.at(i), (i*2) + 5);
  }
}

//merge test 3
TEST (MergeSortTest3, BasicCase) {
 

  vector<int> v;
  v.push_back(267);
  v.push_back(55);
  v.push_back(196);
  v.push_back(6);
  v.push_back(87);
  v.push_back(1233323);
  v.push_back(207);
  v.push_back(1253343);
  v.push_back(353);
  v.push_back(260);
  v.push_back(3003240);
  v.push_back(99);
  v.push_back(124);
  v.push_back(300);
  v.push_back(174);
  v.push_back(23);
  v.push_back(90);
  /*
  if ordered vector would have
  6
  23
  55
  87
  90
  99
  124
  174
  196
  207
  260
  267
  300
  353
  1233323
  1253343
  3003240
  */
  
    vector<int> v_sorted = MergeSort::sort(v);
    EXPECT_EQ(v_sorted.at(0), 6);
    EXPECT_EQ(v_sorted.at(1), 23);
    EXPECT_EQ(v_sorted.at(2), 55);
    EXPECT_EQ(v_sorted.at(3), 87);
    EXPECT_EQ(v_sorted.at(4), 90);
    EXPECT_EQ(v_sorted.at(5), 99);
    EXPECT_EQ(v_sorted.at(6), 124);
    EXPECT_EQ(v_sorted.at(7), 174);
    EXPECT_EQ(v_sorted.at(8), 196);
    EXPECT_EQ(v_sorted.at(9), 207);
    EXPECT_EQ(v_sorted.at(10), 260);
    EXPECT_EQ(v_sorted.at(11), 267);
    EXPECT_EQ(v_sorted.at(12), 300);
    EXPECT_EQ(v_sorted.at(13), 353);
    EXPECT_EQ(v_sorted.at(14), 1233323);
    EXPECT_EQ(v_sorted.at(15), 1253343);
    EXPECT_EQ(v_sorted.at(16), 3003240);

}