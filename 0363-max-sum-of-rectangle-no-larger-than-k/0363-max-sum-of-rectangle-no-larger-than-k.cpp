class Solution {
public:
    // The Core Idea Behind This Problem:
    // Let's first consider the 1 dimensional case, and then we can extrapolate to the 2-dimensional case of the problem
    // Let's say we have an array [-3, 6, -2], and we need to find the greatest contiguous subsequence sum <= k=2
    // One approach which may immediately jump to mind is Kadane's algorithm.
    // However, this cannot work for the simple reason that we cannot find the next greatest subsequence sum <= k=2 simply from the previous result.
    // This is best illustrated looking at [-3, 6, -2]. 
    // Firstly, maxSum = -3
    // However, when we reach 6, what do we do? We can choose to take 6 on its own, however this exceeds k=2.
    // We can also take -3+6, however, this is less than 6 on its own (does not guarantee a maximum), and it also exceeds k. There is no reasonable course
	// of action to take in a case like this to guarantee that the maximum BOUNDED 
	// contiguous subarray sum can be found simply by looking at the previous result.
    // So, we do the next best thing. We compute prefix sums
    //
    // Arr:      [-3, 6, -2].
    // Pref: [0,  -3, 3,  1].
    //
    // For those who do not know, a prefix sum essentially is the sum of all of the array elements up to and including index i from 0.
    // Using this prefix sum array, at each index r (standing for right side of contiguous sequence) we find index l 
	// previous such that pref[r] - pref[l] <= k & pref[r] - pref[l] > currMax.
    // This naive algorithm has a time complexity of O(n^2). But can we do better?
    
    // Yes we can! Introducing, the balanced binary search tree.
    // Looking at the above algorithm, we are essentially trying to find pref[l] such at it is
	// maximised, however when added with pref[r] it does not exceed k.
    // This can be done through a binary search in a binary search tree, looking for the 
	// previously encountered prefix sum such that it is >= currPrefixSum - k.
    
    // In the C++ STL, the underlying implementation of the ordered set is a
	// balanced binary search tree (Red-Black tree). We can use this, as well as the in-built
	// function lower_bound to perform this storage and search.
    
    // We store previously encountered prefix sums in our BST (Binary search tree), 
	// and then for every new one we perform this search to try and maximise our sum whilst not exceeding k.
    
    // Insertion and searching a BST are both O(log n) operations. 
	// We perform this insertion and search n times in a loop through our array. This leads to O(n log n) complexity.
    
    // Transitioning to two dimensions:
    // Moving to 2 dimensions is actually surprisingly easy once you have developed this core insight.
    // View each element in your 1 dimensional array as simply the contiguous array sum between two column boundaries, lCol and rCol.
    // Illustrated:
    // For 2D array              Corresponding 1D with lCol = 0, rCol = 0
    // [[1,  0, 1],              [1, 0]
    //  [0, -2, 3]]              Corresponding 1D with lCol = 0, rCol = 1
    //                           [1 + 0, 0 + -2] = [1, -2].
    //                           Corresponding 1D with lCol = 1, rCol = 2
    //                           [0 + 1, -2 + 3] = [1, 1].
    
    // We can efficiently compute these 1D arrays through using prefix sums AGAIN! Phew, that's a lot of prefix sums.
    // Essentially, for each row of the 2D array we compute the prefix sums of the elements
    
    // So for the previous 2D array, the prefix sums look as follows.
    // [[1, 1, 2],
    //  [0, -2, 1]]
    //
    // Now, to find index 0 (row 0) of our 1D array, for lCol = 1 & rCol = 2
    // we take the pref[row = 0][rCol = 2] and subtract away pref[row = 0][lCol - 1 = 0] to remove any sums
    // which do not correspond to our inclusive range.
    
    // Each 1D array is found through iterating through all of the possible lCol, rCol combinations where lCol <= rCol.
    // Then, we perform the same algorithm with the BST (Binary Search Tree) on the current 1D array as outlined above.
    // Maximum is replaced if we find a larger rectangle sum.
    
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // Precompute column prefix sums
        for (int row = 0; row < matrix.size(); ++row) {
            int currSum = 0;
            for (int col = 0; col < matrix[row].size(); ++col) {
                currSum += matrix[row][col];
                matrix[row][col] = currSum;
            }
        }
        
        int maxSum = INT_MIN;
        for (int lCol = 0; lCol < matrix[0].size(); ++lCol) {
            for (int rCol = lCol; rCol < matrix[0].size(); ++rCol) {
                
                set<int> bst; // RB tree
                bst.insert(0);
                
                int rowPrefSum = 0;
                for (int row = 0; row < matrix.size(); ++row) {
                    int currSum = matrix[row][rCol] - (lCol == 0 ? 0 : matrix[row][lCol-1]);
                    rowPrefSum += currSum;
                    
                    auto searchRes = bst.lower_bound(rowPrefSum - k);
                    
                    if (searchRes != bst.end()) {      
                        maxSum = max(maxSum, rowPrefSum - *searchRes);
                    }
                    
                    bst.insert(rowPrefSum);
                }
                
                
            }
        }
        
        return maxSum;
        
    }
};