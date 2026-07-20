class Solution {
public:
    int longestSubstring(string s, int k) {
        int longestLen = 0;

        for(int targetUniqueChars = 1; targetUniqueChars <= 26; targetUniqueChars++){
            vector<int> charFreq(26, 0);

            int uniqueChars = 0;
            int charsMeetingKFreq = 0;

            int left = 0, right = 0;
            int n = s.size();

            while(right < n){
                char currChar = s[right];

                if(charFreq[currChar - 'a'] == 0)
                    uniqueChars++;

                if(charFreq[currChar - 'a'] == k - 1)
                    charsMeetingKFreq++;

                charFreq[currChar - 'a']++;

                while(uniqueChars > targetUniqueChars){
                    char leftChar = s[left];

                    if(charFreq[leftChar - 'a'] == 1)
                        uniqueChars--;

                    if(charFreq[leftChar - 'a'] == k)
                        charsMeetingKFreq--;

                    charFreq[leftChar - 'a']--;
                    left++;
                }

                if(uniqueChars == targetUniqueChars &&
                   charsMeetingKFreq == uniqueChars){
                    longestLen = max(longestLen, right - left + 1);
                }

                right++;
            }
        }

        return longestLen;
    }
};