#include <iostream>
#include <vector>
#include <set>

using namespace std; 

int lengthOfLongestSubstring(string s) {
        
    int maxlen = 0;
    
    for (int i = 0; i < s.length(); i++)
    {
        int j = i, sublen = 1;
        set<char> ch;
        ch.insert(s.at(j));
                
        // Extend substring until a repeating character appears
        while ((++j) < s.length() && ch.find(s.at(j)) == ch.end())
        {
            ch.insert(s.at(j));
            sublen++;
        }
            
        if (sublen > maxlen)
        {
            maxlen = sublen;    
        }
    }
    return maxlen;
}