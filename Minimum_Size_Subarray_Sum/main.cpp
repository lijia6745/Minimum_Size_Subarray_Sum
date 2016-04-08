//
//  main.cpp
//  Minimum_Size_Subarray_Sum
//
//  Created by 李佳 on 15/10/22.
//  Copyright © 2015年 LiJia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int sum = 0;
        int minLength = INT_MAX;
        int startPos = 0;
        int matchPos = 0;
        
        while (matchPos < nums.size())
        {
            int i = matchPos;
            for (; i < nums.size(); ++i)
            {
                sum += nums[i];
                if (sum >= s) //找到一个子串
                {
                    //向后找 重新定位开始位置。
                    int j = startPos;
                    while (sum - nums[j] >= s && j < i) //可以舍弃
                    {
                        sum -= nums[j++];
                    }
                    if (i == j)
                        return 1;
            
                    startPos = j + 1;
                    sum -= nums[j];
                    minLength = std::min(minLength, i - j + 1);
                    break;
                }
            }
            matchPos = i + 1;
        }
        
        return minLength == INT_MAX ? 0 : minLength;
    }
};

void Test_FunAgain()
{
    
}

int main(int argc, const char * argv[])
{
    Solution* pSol = new Solution;
    vector<int>nums = {2,3,1,2,4,3,7};
    int result = pSol->minSubArrayLen(7, nums);
    printf("reuslt = %d", result);
    delete pSol;
    return 0;
}
