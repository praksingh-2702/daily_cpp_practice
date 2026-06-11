#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxel(int n, vector<int>& nums) {
        int maxi = nums[0];
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
long long noofhours(vector<int>& nums, int val, int n) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil(double(nums[i]) / double(val));
        }
        return sum;
    }
int minimumRateToEatBananas(vector<int> nums, int h) {
        int n = nums.size();
        int maxim = maxel(n, nums);
        int low = 1, high = maxim;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long value = noofhours(nums, mid, n);
            if (value <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int main() {
        vector<int> nums = {3, 6, 7, 11};
        int h = 8;
        int ans = minimumRateToEatBananas(nums, h);
        cout << "Minimum eating speed: " << ans << endl;
        return 0;
    }