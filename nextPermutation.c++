#include <iostream>
#include <vector>
using namespace std;

/*
Leetcode Problem 31: Next Permutation
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].

Given an array of integers nums, find the next permutation of nums. The replacement must be in place and use only constant extra memory.
*/

/*
This algorithm can be divided into 3 parts:
    - Finding pivot
    - Finding swapping element
    - Reversing the remaining array

    1. Traverse the array from right to left, until a[i] < a[i+1]. i is the pivot position.
    2. Now traverse the array from right to left again, until a[i] > a[pivot]. Now swap a[i] and a[pivot].
    3. Reverse the elements to the right of a[i], i.e. from a[i+1] to the end.
*/

void findNextPermutation(vector<int>& nums){
    int n = nums.size();
    int ind = -1;
    for (int i = n - 2; i >= 0; i--){
        if (nums[i] < nums[i+1]){
            ind = i;
            break;
        }
    }
    if (ind == -1){
        return reverse(nums.begin(), nums.end());
    }
    for (int i = n - 1; i >= 0; i--){
        if (nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(1);
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    findNextPermutation(nums);
    cout << "RUNNING findNextPermutation()..." << endl;
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}