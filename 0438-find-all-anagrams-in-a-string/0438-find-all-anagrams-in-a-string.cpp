class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l1=s.size(),l2=p.size();
        if(l1<l2)   return {};
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(int i=0;i<l2;i++)
        {
            hash2[p[i]-'a']++;
        }
        vector<int> ans;
        for(int i=0;i<l2-1;i++)   hash1[s[i]-'a']++;
        for(int i=0;i+l2-1<l1;i++)
        {
            hash1[s[i+l2-1]-'a']++;
            bool same =true;
            for(int i=0;i<26;i++)
            {
                if(hash1[i]!=hash2[i])  same=false;
            }
            if(same)    ans.push_back(i);
            hash1[s[i]-'a']--;
        }
        return ans;
    }
};