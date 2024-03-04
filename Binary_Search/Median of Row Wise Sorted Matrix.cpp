#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
// upper bound
int upperBound(vector<int> &arr,int x,int n)
{
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        // maybe an ans
        if(arr[mid]>x)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

// count smallest equal
int countsmallEqual(vector<vector<int>> &matrix, int R, int C, int x)
{
    int cnt=0;
    for(int i=0;i<R;i++)
    {
        cnt+=upperBound(matrix[i],x,C);
    }
    return cnt;
}





int median(vector<vector<int>> &matrix, int R, int C) {
    int low = INT_MAX;
    int high = INT_MIN;

    for(int i = 0; i < R; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C - 1]);
    }
    
    int median = (R * C + 1) / 2; // Calculate median index
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int smallEqual = countsmallEqual(matrix, R, C, mid);
        if (smallEqual >= median)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

};
