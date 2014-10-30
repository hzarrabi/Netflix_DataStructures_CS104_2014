#include "../lib/MergeSort.h"
#include "../lib/Set.h"
#include "gtest/gtest.h"

using namespace std;


//Uniontest #1
TEST (setUnionTest1, BasicCase) {
 

  Set<int> set1;//first set
  Set<int> set2;//second set

  set1.add(300);//
  set1.add(23522);
  set1.add(55);//1
  set1.add(196);
  set1.add(1222);//
  set1.add(62462);
  set1.add(90);//
  set1.add(1233323);
  set1.add(70);//
  set1.add(22);
  set1.add(532);//

  set2.add(353);
  set2.add(55);//1
  set2.add(3003240);
  set2.add(99);
  set2.add(124);
  set2.add(300);//2
  set2.add(174);
  set2.add(23);
  set2.add(90);//3
  set2.add(70);//2
  set2.add(90);
  set2.add(1222);//5
  set2.add(95);
  set2.add(532);//6
  set2.add(93);



  Set<int> setFinal =set1.setIntersection(set2);//using set union
  vector<int> v;
  try
  {
    for(Set<int>::Iterator a = setFinal.begin(); a!=setFinal.end(); ++a)
    {
      v.push_back(*a);//copying from set to vector
    }
}

catch(NoSuchElementException e){}

  vector<int> v_sorted=MergeSort::sort(v);
  /*
  if ordered vector would have
55
70
90
300
532
1222

  */
  
    EXPECT_EQ(v_sorted.at(0), 55);
    EXPECT_EQ(v_sorted.at(1), 70);
    EXPECT_EQ(v_sorted.at(2), 90);
    EXPECT_EQ(v_sorted.at(3), 300);
    EXPECT_EQ(v_sorted.at(4), 532);
    EXPECT_EQ(v_sorted.at(5), 1222);


}




//Uniontest #2
TEST (setUnionTest2, BasicCase) {
 

  Set<int> set1;//first set
  Set<int> set2;//second set

  set1.add(453);//
  set1.add(23522);
  set1.add(29);//1
  set1.add(196);
  set1.add(23432);//
  set1.add(62462);
  set1.add(86);//
  set1.add(1233323);
  set1.add(55);//
  set1.add(22);
  set1.add(600);//

  set2.add(353);
  set2.add(29);//1
  set2.add(3003240);
  set2.add(99);
  set2.add(124);
  set2.add(453);//4
  set2.add(174);
  set2.add(23);
  set2.add(86);//3
  set2.add(55);//2
  set2.add(90);
  set2.add(23432);//5
  set2.add(95);
  set2.add(600);//6
  set2.add(93);



  Set<int> setFinal =set1.setIntersection(set2);//using set union
  vector<int> v;
  try
  {
    for(Set<int>::Iterator a = setFinal.begin(); a!=setFinal.end(); ++a)
    {
      v.push_back(*a);//copying from set to vector
    }
}

catch(NoSuchElementException e){}

  vector<int> v_sorted=MergeSort::sort(v);
  /*
  if ordered vector would have
55
70
90
300
532
1222

  */
  
    EXPECT_EQ(v_sorted.at(0), 29);
    EXPECT_EQ(v_sorted.at(1), 55);
    EXPECT_EQ(v_sorted.at(2), 86);
    EXPECT_EQ(v_sorted.at(3), 453);
    EXPECT_EQ(v_sorted.at(4), 600);
    EXPECT_EQ(v_sorted.at(5), 23432);


}

//intersection test 3
TEST (setUnionTest, BasicCase) {
 

  Set<int> set1;//first set
  Set<int> set2;//second set

  set1.add(453);//
  set1.add(23522);
  set1.add(29);//1
  set1.add(196);
  set1.add(3003240);//
  set1.add(36);
  set1.add(86);//
  set1.add(1233323);
  set1.add(55);//
  set1.add(353);//
  set1.add(463);

  set2.add(342335);
  set2.add(353);
  set2.add(29);//1
  set2.add(3003240);
  set2.add(34534);
  




  Set<int> setFinal =set1.setIntersection(set2);//using set union
  vector<int> v;
  try
  {
    for(Set<int>::Iterator a = setFinal.begin(); a!=setFinal.end(); ++a)
    {
      v.push_back(*a);//copying from set to vector
    }
}

catch(NoSuchElementException e){}

  vector<int> v_sorted=MergeSort::sort(v);
  /*
  if ordered vector would have
55
70
90
300
532
1222

  */
  
    EXPECT_EQ(v_sorted.at(0), 29);
    EXPECT_EQ(v_sorted.at(1), 353);
    EXPECT_EQ(v_sorted.at(2), 3003240);


}