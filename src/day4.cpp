// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <stdio.h>
#include <iostream>
#include <string> 
#include <utility>
#include <map>
#include <algorithm>
#include <bitset>
using namespace std;
class Solution {
public:
    void findComplement(int num) {
        int cmp;
        std::string cmp_bitstr; 
        
        std::string b = std::bitset<32>(num).to_string();
        cout << cmp << "\n" << endl;
        std::string tmp = b.substr(b.find_first_of("1"));
        cout << tmp << "\n" << endl;
        for (char& x : tmp ) {
            switch (x) {
            case '0': 
                cmp_bitstr+="1";
                break;
            case '1': 
                cmp_bitstr+="0";
                break;
            default:
                break;
            } 
        }

        cmp = std::bitset<32>(cmp_bitstr).to_ulong();
        cout << cmp << endl;
    }
};

int main( int  argc, char* arg[]) {

    
    Solution s = Solution();
    int str = 71;
    s.findComplement(str);
    //printf("%d \n", s.findComplement(str));
    //std::string str;

    return 0;
 };