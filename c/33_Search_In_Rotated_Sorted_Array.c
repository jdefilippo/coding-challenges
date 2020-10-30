//For problem description, see https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if ((nums[mid] > nums[high]) && (target <= nums[high]))
            {
                cout << "Here!" << endl;
                low = mid + 1;
            }
            else if ((nums[mid] < nums[low]) && (target >= nums[low]))
            {
                cout << "over here!" << endl;
                high = mid - 1;
            }
            else
            {
                // Regular binary search
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] > target)
                    high = mid - 1;
                else if (nums[mid] < target)
                    low = mid + 1;
                else
                {
                }
            }
        }
        return -1;
    }
};