#include <iostream>
#include <vector>

using namespace std; 

int lengthOfLongestSubstring(string s) {
        
    int maxlen = 0;
    vector<char> ch;        // Keeps current substring
    
    for (int i = 0; i < s.length(); i++)
    {
        // Check if s[i] is in current substring
        auto it = find(ch.begin(), ch.end(), s[i]);
        
        // If s[i] is repeated, save current length & substitute
        if (it != ch.end())
        {
            if (maxlen < ch.size())
            {
                maxlen = ch.size();
            }
            ch.erase(ch.begin(), ++it);     // Erase upto the repeated element
        }
        ch.push_back(s[i]);
    }

    if (maxlen < ch.size())
    {
        maxlen = ch.size();
    }
    
    return maxlen;
}

int main(){
    string str = "abcabcbb"; 
    cout << "The input string is " << str << endl; 
    int len = lengthOfLongestSubstring(str); 
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len; 
    return 0;
}