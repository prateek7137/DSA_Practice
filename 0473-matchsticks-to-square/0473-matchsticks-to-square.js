var makesquare = function(matchsticks) {
    const total = matchsticks.reduce((a, b) => a + b, 0);
    if (total % 4 !== 0) return false;
    const side = total / 4;
    matchsticks.sort((a, b) => b - a);

    const sides = [0, 0, 0, 0];

    function backtrack(index) {
        if (index === matchsticks.length) {
            return sides.every(s => s === side);
        }

        for (let i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= side) {
                sides[i] += matchsticks[index];
                if (backtrack(index + 1)) return true;
                sides[i] -= matchsticks[index];
            }
        }

        return false;
    }

    return backtrack(0);
};