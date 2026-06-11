#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxel(vector<int>& a, int n) {
        int maxi = a[0];
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, a[i]);
        }
        return maxi;
    }
    int sumofel(vector<int>& a, int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        return sum;
    }
    int noofparts(vector<int>& a, int n, int sum) {
        int parts = 1, sum1 = 0;
        for (int i = 0; i < n; i++) {
            if (sum1 + a[i] > sum) {
                sum1 = a[i];
                parts++;
            } else {
                sum1 += a[i];
            }
        }
        return parts;
    }
int largestSubarraySumMinimized(vector<int>& a, int k) {
        int n = a.size();
        int maxim = maxel(a, n);
        int summ = sumofel(a, n);
        int low = maxim, high = summ;
        while (low <= high) {
            int mid = (low + high) / 2;
            int value = noofparts(a, n, mid);
            if (value <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int main() {
        vector<int> a = {7, 2, 5, 10, 8};
        int k = 2;
        int ans = largestSubarraySumMinimized(a, k);
        cout << "The minimized largest sum is: " << ans << endl;
        return 0;
    }