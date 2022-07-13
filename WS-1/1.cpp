#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
//Using Lomuto Partition
std::vector<int> sortArray (std::vector<int>& v)
{
    int n = v.size();
    int i = -1;
    for(int j = 0; j < n; j++)
    {
        if(v[j] % 2 == 0){
            i++;
            std::swap(v[i], v[j]);
        }
    }
    return v;
}
//Using stable partition (Linear Time)
std::vector<int> sortArrayByParity(std::vector<int>& nums) 
{
    std::stable_partition(nums.begin(), nums.end(),
                          [](int x) { return (x % 2 == 0); });
    return nums;
};
int main()
{
    std::vector<int> v{ 6, 9, 0, 1, 2, 7, 5, 8, 0 };
    //sortArray(v);
    sortArrayByParity(v);
    std::copy(v.begin(),
         v.end(),
         std::ostream_iterator<int>(std::cout, " "));
         std::cout<<std::endl;
}