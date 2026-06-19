#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

 int maxel(vector<int>& nums, int n) {
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    int sumofel(vector<int>& nums, int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return sum;
    }
    int noofstudents(vector<int>& nums, int n, int m, int cap) {
        int sum1 = 0;
        int student = 1;
        for (int i = 0; i < n; i++) {
            if (sum1 + nums[i] > cap) {
                student++;
                sum1 = nums[i];
            } else {
                sum1 += nums[i];
            }
        }
        return student;
    }
    int findPages(vector<int>& nums, int m) {
        int n = nums.size();
        if (n < m) {
            return -1;
        }
        int maxim = maxel(nums, n);
        int summ = sumofel(nums, n);
        int low = maxim, high = summ;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = noofstudents(nums, n, m, mid);
            if (value <= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
int main(){
    vector<int> nums={10,20,30,40};
    int m=2;
    int ans=findPages(nums,m);  
    cout<<"Minimum number of pages: "<<ans<<endl;
    return 0;   
}