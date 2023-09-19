// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

//时间：91%
//内存：80.26%

//使用队列一遍扫

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
      int visit[256]={0};
      int ans=0;
      queue<char> substring;
      for(int i=0;i<s.length();i++)
      {
        if(visit[s[i]])
        {
          while(substring.front()!=s[i])
          {
            visit[substring.front()]=0;
            substring.pop();
          }
          substring.pop();
          substring.push(s[i]);
        }
        else
        {
          visit[s[i]]=1;
          substring.push(s[i]);
          ans=substring.size()>ans?substring.size():ans;
        }
      }
      return ans;
    }
};