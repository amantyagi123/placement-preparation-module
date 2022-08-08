class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int N = A.size(), i = N - 1;
        while (i - 1 >= 0 && A[i - 1] >= A[i]) --i; // find the first element of a descending subarray from the end.
        reverse(begin(A) + i, end(A)); // reverse this descending subarray
        if (i - 1 >= 0) swap(*upper_bound(begin(A) + i, end(A), A[i - 1]), A[i - 1]); // swap A[i-1] with the first element greater than `A[i-1]` in the subarray.
    }
};