var minMoves = function(nums) {
    const sum = nums.reduce((acc, val) => acc + val, 0);
    const min = Math.min(...nums);
    return sum - min * nums.length;
};