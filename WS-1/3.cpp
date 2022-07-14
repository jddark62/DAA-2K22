#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
// Moore Voting Algorithm
int majorityElement(std::vector<int>& nums) 
{
        int counter = 0, majority;
        for (int num : nums) {
            if (!counter) {
                majority = num;
            }
            counter += num == majority ? 1 : -1;
        }
        return majority;
}
//Since the majority element appears more than n / 2 times, the n / 2-th element is the majority
//A partial sort by nth element is done.
int majorityElementPartial(std::vector<int>& nums) 
{
        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
}
int main()

{
    std::vector<int> v{ 6, 9, 0, 1, 2, 7, 5, 8, 0, 0, 7, 7, 6, 6, 1 };
    std::cout << majorityElement(v) << std::endl;
}
