#include <iostream>
#include <vector>
using namespace std;

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