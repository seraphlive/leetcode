/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 *
 * https://leetcode.com/problems/advantage-shuffle/description/
 *
 * algorithms
 * Medium (46.96%)
 * Likes:    880
 * Dislikes: 55
 * Total Accepted:    38.8K
 * Total Submissions: 77.8K
 * Testcase Example:  '[2,7,11,15]\n[1,10,4,11]'
 *
 * Given two arrays A and B of equal size, the advantage of A with respect to B
 * is the number of indices i for which A[i] > B[i].
 * 
 * Return any permutation of A that maximizes its advantage with respect to
 * B.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [2,7,11,15], B = [1,10,4,11]
 * Output: [2,11,7,15]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [12,24,8,32], B = [13,25,32,11]
 * Output: [24,32,8,12]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length = B.length <= 10000
 * 0 <= A[i] <= 10^9
 * 0 <= B[i] <= 10^9
 * 
 * 
 * 
 * 
 */

// @lc code=start
// greedy, using multiset. O(nlogn), O(n)
// we'd like to use as many elements in A as possible.
// for B[i], we want the smallest A[i] that A[i] > B[i];
// if not exist, use the smallest element in A.
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)
    {
        multiset<int> s(begin(A), end(A));
        for (int i = 0; i < B.size(); ++i)
        {
            auto it = *s.rbegin() > B[i] ? s.upper_bound(B[i]) : s.begin();
            A[i] = *it;
            s.erase(it);
        }
        return A;
    }
};
// @lc code=end

