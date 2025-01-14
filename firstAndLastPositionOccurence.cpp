#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n - 1;
        int ans=n;
        while (low<=high) {
            int mid=(low + high) / 2;
            if (nums[mid]>=target) {
                ans=mid;
                high=mid - 1;
            } else {
                low=mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;
        int ans= n;
        while (low<=high) {
            int mid=(low+high)/2;
            if (nums[mid]>target) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb =lowerBound(nums, target);
        if (lb==nums.size() || nums[lb]!=target) return {-1, -1};
        return {lb, upperBound(nums, target)-1};
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    vector<int> result = solution.searchRange(nums, target);
    cout <<target<< "[]"<<result[0]<< ", "<< result[1] << "]" << endl;
    return 0;
}
