class Solution {

    int count = 1; // Count number 0

    public int countNumbersWithUniqueDigits(int n) {

        if (n == 0)
            return 1;

        boolean[] visited = new boolean[10];

        backtrack(0, n, visited);

        return count;
    }

    private void backtrack(int length,
                           int maxLength,
                           boolean[] visited) {

        if (length == maxLength)
            return;

        for (int digit = 0; digit <= 9; digit++) {

            // First digit cannot be 0
            if (length == 0 && digit == 0)
                continue;

            if (visited[digit])
                continue;

            visited[digit] = true;

            count++;

            backtrack(length + 1,
                      maxLength,
                      visited);

            visited[digit] = false;
        }
    }
}