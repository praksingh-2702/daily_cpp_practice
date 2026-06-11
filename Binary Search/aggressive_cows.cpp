#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canweplace(vector<int>& nums, int n, int k, int distcheck) {
        int cntcows = 1, last = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] - last >= distcheck) {
                cntcows++;
                last = nums[i];
            }
        }
        if (cntcows >= k) {
            return true;
        }
        return false;
    }
int aggressiveCows(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 1, high = nums[n - 1] - nums[0];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canweplace(nums, n, k, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    int ans = aggressiveCows(nums, k);
    cout << "The largest minimum distance is: " << ans << endl;
    return 0;
}