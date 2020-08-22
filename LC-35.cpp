class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lf = 0, rt = nums.size()-1;
        while(lf <= rt)
        {
            int mid = (lf+rt)/2;
            target > nums[mid] ? lf = mid + 1 : rt = mid - 1;
        }
        return lf;
    }
};