// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <stdio.h>
#include <iostream>
#include <string> 
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
class Solution {
public:

        int majorityElement(vector<int>& nums) {

            map<int, int> mp;
            float ln = nums.size()/2.0;
            
            for (auto &x : nums) {
                if (!mp.count(x)) {
                    mp[x] = std::count(nums.begin(), nums.end(), x); 
                    if (mp[x] > ln) {
                        return x;
                        break;
                    }             
                }
            }

            return 0;

        }



};

int main( int  argc, char* arg[]) {

    
    Solution s = Solution();
    vector<int> v{2,2,1,1,1,2,2};
    
    //s.majorityElement(v);
    cout << s.majorityElement(v) << endl;


    return 0;
 };