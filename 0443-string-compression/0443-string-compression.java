class Solution {
    public int compress(char[] chars) {
        int index = 0;
        int va = 0;

        while (index < chars.length) {
            char ch = chars[index];
            int count = 0;

            while (index < chars.length && chars[index] == ch) {
                count++;
                index++;
            }

            chars[va++] = ch;

            if (count > 1) {
                for (char digit : Integer.toString(count).toCharArray()) {
                    chars[va++] = digit;
                }
            }
        }

        return va;
    }
}