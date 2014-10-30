#include "../lib/MergeSort.h"
#include "gtest/gtest.h"

TEST (intersectionTest, BasicCase) {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(5);
  v.push_back(3);
  v.push_back(2);
  v.push_back(4);
  

  cout<<"Hello"<<endl;
  std::vector<int> v_sorted = MergeSort::sort(v);
  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(v_sorted.at(i), i+1);
  }
}