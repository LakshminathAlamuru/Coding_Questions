#include<iostream>
using namespace std;


int findClosest(vector<int>arr, int target)
{
    int lo = 0;
    int hi = arr.size()-1;
    int res = arr[0];

    while(lo <= hi)
    {
        int mid = (lo+hi)/2;

        if(abs(arr[mid]-target) < abs(res-target))
        {
            res = arr[mid];
        }
        if(abs(arr[mid]-target) == abs(res - target))
        {
            res = max(res, arr[mid]);
        }

        if(arr[mid] == target)
        {
            return arr[mid];
        }
        else if(target > arr[mid])
        {
            lo = mid+1;
        }
        else{
            lo = mid-1;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 6, 6, 8, 8, 9};
    int target = 11;
  
    cout << findClosest(arr, target) << endl;
    return 0;
}