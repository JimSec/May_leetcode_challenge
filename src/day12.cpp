#include <stdio.h>
#include <iostream>
#include <string> 
#include <utility>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <typeinfo>
using namespace std;

class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        int ret;
        unordered_map<int, int> map;
        for (auto x : nums) {
            if (!map[x]) {
                map[x] = 1;
            }
            else {
                map.erase(x);
            }
        }
        for (auto m : map ){
            ret = m.first;
        }  
        return ret; 
    }
};

int main( int  argc, char* argv[]) {

    vector<int> v = {3,3,7,7,10,11,11};
    Solution s = Solution();

    s.singleNonDuplicate(v);

    return 0;
 }