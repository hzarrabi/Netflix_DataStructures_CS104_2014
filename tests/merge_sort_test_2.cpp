#include "../lib/MergeSort.h"
#include "gtest/gtest.h"



TEST (MergeSortTest, BasicCase) {
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