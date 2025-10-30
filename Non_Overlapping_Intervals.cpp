#include<iostream>
using namespace std;

bool compare(vector<int>a, vector<int> b)
{
    return a[1] < b[1];
}

int minRemoval(vector<vector<int>> intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), compare);
    int end = intervals[0][1];
    int count = 0;
    for(int i = 1; i < n; i++)
    {
        int curr = intervals[i][0];
        if ( curr < end)
        {
            count++;
        }
        else
        {
            end = max(end, curr);
        }
    }
    return count;

}

bool compare1(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

void mergeIntervals(vector<vector<int>> intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), compare1);
    int last = intervals[0][1];
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0] > last)
        {
            res.push_back(intervals[i]);
        }
        else // if there is a overlap
        {
            last = res.back();

        }

    }
}

int main()
{
    vector<vector<int>> intervals = 
    				{{1, 2}, {2, 3}, {3, 5}, {1, 4}};
    cout << minRemoval(intervals) << endl;
    mergeIntervals(intervals);
}