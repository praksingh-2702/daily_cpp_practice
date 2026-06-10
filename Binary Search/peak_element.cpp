#include <iostream>
#include <vector>
using namespace std;
/*int findpeakelement(vector<int> &vec,int n){//Brute force approach
    if(n==1){
        return vec[0];
    }
    if(vec[0]>vec[1]){
        return vec[0];
    }
    if(vec[n-1]>vec[n-2]){
        return vec[n-1];
    }
    for(int i=1;i<=n-2;i++){
        if(vec[i]>vec[i-1] && vec[i]>vec[i+1]){
            return vec[i];
        }
    }
    return -1; // This line will never be reached since there is always a peak element
}*/
int findpeakelementbin(vector<int>& vec,int n){
        if (n == 1) {
            return 0;
        }
        if (vec[0] > vec[1]) {
            return 0;
        }
        if (vec[n - 1] > vec[n - 2]) {
            return n - 1;
        }
        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (vec[mid] > vec[mid + 1] && vec[mid] > vec[mid - 1]) {
                return mid;
            } else if (vec[mid] > vec[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
int main(){
    vector<int> vec={5,4,3,2,1};
    int n=vec.size();
    int ans=findpeakelementbin(vec,n);
    cout<<"Peak element is: "<<ans<<endl;
}