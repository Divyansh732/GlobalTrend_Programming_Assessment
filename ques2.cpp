#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int LongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int j = 0;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0)
             mp[s[i - 1]]--;
    
            while (j < n) {
                mp[s[j++]]++;
                if (mp[s[j - 1]] == 2) {
                    mp[s[--j]]--;
                    break;
                }

                maxLength = max(maxLength, j - i);
            }
        }

        return maxLength;
    }

int main(){
    cout<<"enter string"<<endl;
    string str;
    cin>>str;
    cout<<"max length of subtring without repeating is: "<<LongestSubstring(str)<<endl;
}    
    

