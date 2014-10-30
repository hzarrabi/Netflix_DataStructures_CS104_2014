#include "../lib/MergeSort.h"
#include "../lib/Set.h"
#include "gtest/gtest.h"

using namespace std;

TEST (setUnionTest1, BasicCase) {
 

  Set<int> set1;//first set
  Set<int> set2;//second set

  set1.add(267);
  set1.add(55);
  set1.add(196);
  set1.add(6);
  set1.add(87);
  set1.add(1233323);
  set1.add(207);
  set1.add(1253343);
  set2.add(353);
  set2.add(260);
  set2.add(3003240);
  set2.add(99);
  set2.add(124);
  set2.add(300);
  set2.add(174);
  set2.add(23);
  set2.add(90);


  Set<int> setFinal =set1.setUnion(set2);//using set union
  vector<int> v;
  try
  {
    for(Set<int>::Iterator a = setFinal.begin(); a!=setFinal.end(); ++a)
    {
      cout<<*a<<endl;
      v.push_back(*a);//copying from set to vector
    }
}

catch(NoSuchElementException e){}

  vector<int> v_sorted=MergeSort::sort(v);
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