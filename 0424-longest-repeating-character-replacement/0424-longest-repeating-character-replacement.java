class Solution {
    public int characterReplacement(String s, int k) {

        int[] count = new int[26];

        int left = 0;
        int right = 0;

        int maxFrequency = 0;
        int maxLength = 0;

        while (right < s.length()) {

            // 1. Get current character
            char current = s.charAt(right);

            // 2. Increase its frequency
            count[current - 'A']++;

            // 3. Update maxFrequency
            maxFrequency = Math.max(
                maxFrequency,
                count[current - 'A']
            );

            // 4. Calculate current window length
            int windowLength = right - left + 1;

            // 5. If window is invalid, shrink it
            while (windowLength - maxFrequency > k) {

                // Remove left character
                count[s.charAt(left) - 'A']--;

                // Move left forward
                left++;

                // Recalculate window length
                windowLength = right - left + 1;
            }

            // 6. Update longest valid window
            maxLength = Math.max(maxLength, windowLength);

            // 7. Move right forward
            right++;
        }

        return maxLength;
    }
}