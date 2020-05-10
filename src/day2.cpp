// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <stdio.h>
#include <string> 
#include <utility>

class Solution {
public:

    int numJewelsInStones(std::string J, std::string S) {

        int J_counter = 0;

        for(char& c : S) {
            if ( J.find(c) != std::string::npos) {
                J_counter++;
            };
        };

        return J_counter;
        
    };

};

int main( int  argc, char* arg[]) {

    std::string jw = "aA";
    std::string st = "aAAbbbb";

    Solution s = Solution();
    printf("%i \n", s.numJewelsInStones(jw,st));
    //std::string str;

    return 0;
 };