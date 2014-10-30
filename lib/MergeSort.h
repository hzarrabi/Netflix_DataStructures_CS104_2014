#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

using namespace std;

class MergeSort {
  public:
    template <class T>
    static vector<T> sort (vector<T> a)
    {
    	//if the vector has 1 or no elements return it;base case
    	if (a.size()<=1)//reason we need to account for size 0 is if they initially enter an empty vector
    	{
    		return a;
    	}
    	else
    	{
    		vector<T>leftVec;//this will hold contents of left side part of the vector
    		vector<T>rightVec;//this will hold contents of right side of vector

    		int middle=(a.size()+1)/2;

    		//making a seperate array for left side
    		for(int i=0;i<middle;i++)
    		{
    			leftVec.push_back(a[i]);
    		}

    		//making seperate array for right side
    		for(int i=middle;i<a.size();i++)
    		{
    			rightVec.push_back(a[i]);
    		}

    		vector<T> left=sort(leftVec);//recursive call
    		vector<T> right=sort(rightVec);//recursive call

    		vector<T>FinalVec;//this will be the final vector that is returned
    		FinalVec=merge(left,right);//will merge and sort when all the vectors

            return FinalVec;

    	}
    	


    }

   private:
    template <class T>
   	static vector<T> merge (vector<T> left,vector<T> right)
   	{
	    vector<T> final;
        int l=0;//int used traverse left vector
        int r=0;//int used to traverse righ vector

        while (l<left.size() && r<right.size())//as long as we haven't reached end of either vector
        {
            if(left[l]<right[r])//if left item is less than right
            {
                final.push_back(left[l]);//put it into new vector
                l++;//increment left index because you want to compare it's next item
            }

            else if (left[l]>right[r])//if right item is less than left
            {
                final.push_back(right[r]);
                r++;
            }

            else//if the items are equal put either one in the final vector and incriment both indexes
            {
                final.push_back(left[l]);
                r++;
                l++;
            }
        }

        while(l<left.size()) //if left is left over
        {
            final.push_back(left[l]);
            l++;
        }

        while(r<right.size()) //if right is left over
        {
            final.push_back(right[r]);
            r++;
        }

        return final;
   	}




};
#endif