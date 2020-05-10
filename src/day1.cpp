// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <stdio.h>
#include <string> 
#include <utility>

class Solution {
public:
    
    // find median element
    // if median element is bad next check is median / 2
    // if median element is good, next check is median * 1.5

    int v = 1702766719;

    bool isBadVersion(int version){

        if (version >= v) {
            return true;
        }

        else {
            return false;
        }
    };

    int firstBadVersion(int n) {
        int badVersion = 0;
        int checkVersion = n / 2;

        std::pair <int,bool> lastcheckVersion (0,false);

        //int checkVersion = n;
        int i = 1;
        while (badVersion == 0) {

            printf("checkVersion = %i \n ", checkVersion);
            if (isBadVersion(checkVersion) == true) {

                if ((lastcheckVersion.second == false) && (checkVersion == lastcheckVersion.first + 1)) {
                    badVersion = checkVersion;
                    printf("badVersion found in: %i", i);
                }

                else {
                    int diff = abs(lastcheckVersion.first - checkVersion) / 2;
                    if (diff == 0) {diff++;}
                    lastcheckVersion.first = checkVersion;
                    lastcheckVersion.second = true;

                    checkVersion = checkVersion - (diff);
                }

            }
            
            else {
                if ((lastcheckVersion.second == true) && (checkVersion == lastcheckVersion.first - 1)) {
                    badVersion = lastcheckVersion.first;
                    printf("badVersion found in: %i \n", i);
                }

                else {

                    int diff = abs(lastcheckVersion.first - checkVersion) / 2;
                    if (diff == 0) {diff++;}
                    lastcheckVersion.first = checkVersion;
                    lastcheckVersion.second = false;
                    checkVersion = checkVersion + (diff);
                }
                
            }

            i++;
                     
        } 
        
        return badVersion;
    }
    
};

int main( int  argc, char* arg[]) {

    Solution s = Solution();
    printf("%i", s.firstBadVersion(2126753390));

 };

