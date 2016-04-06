/**
 *       Filename:  main.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  04/06/2016 15:37:56
 *       Compiler:  gcc
 *         Author:  Apacal (apacal.cn), apacalzqz@gmail.com
 *        Company:  tencent
 */

#include "../global.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j <  nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }

        return ret;
    }
};



int main() {
    int num = 0, numCount = 0, numSize = 0;
    bool isStart = true;
    vector<int> nums;
    int target;
    Solution solution;
    while(cin >> num) {
        if (isStart) {
            numSize = num;
            nums.clear();
            numCount = 0;
            isStart = false;
        } else {
            if (numCount < numSize) {
                numCount++;
                nums.push_back(num);
            } else {
                target = num;
                printContainer(nums.size(), nums.begin(), nums.end());
                printValue(target);

                vector<int> ret;
                ret = solution.twoSum(nums, target);
                printContainer(ret.size(), ret.begin(), ret.end());

                isStart = true;
            }
        }
    }
}

