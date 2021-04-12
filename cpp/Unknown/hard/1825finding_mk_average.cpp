/*
 * @lc app=leetcode id=1825 lang=cpp
 *
 * [1825] Finding MK Average
 *
 * https://leetcode.com/problems/finding-mk-average/description/
 *
 * algorithms
 * Hard (25.50%)
 * Likes:    56
 * Dislikes: 43
 * Total Accepted:    2.2K
 * Total Submissions: 7.6K
 * Testcase Example:  '["MKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage"]\n' +
  '[[3,1],[3],[1],[],[10],[],[5],[5],[5],[]]'
 *
 * You are given two integers, m and k, and a stream of integers. You are
 * tasked to implement a data structure that calculates the MKAverage for the
 * stream.
 * 
 * The MKAverage can be calculated using these steps:
 * 
 * 
 * If the number of the elements in the stream is less than m you should
 * consider the MKAverage to be -1. Otherwise, copy the last m elements of the
 * stream to a separate container.
 * Remove the smallest k elements and the largest k elements from the
 * container.
 * Calculate the average value for the rest of the elements rounded down to the
 * nearest integer.
 * 
 * 
 * Implement the MKAverage class:
 * 
 * 
 * MKAverage(int m, int k) Initializes the MKAverage object with an empty
 * stream and the two integers m and k.
 * void addElement(int num) Inserts a new element num into the stream.
 * int calculateMKAverage() Calculates and returns the MKAverage for the
 * current stream rounded down to the nearest integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MKAverage", "addElement", "addElement", "calculateMKAverage",
 * "addElement", "calculateMKAverage", "addElement", "addElement",
 * "addElement", "calculateMKAverage"]
 * [[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
 * Output
 * [null, null, null, -1, null, 3, null, null, null, 5]
 * 
 * Explanation
 * MKAverage obj = new MKAverage(3, 1); 
 * obj.addElement(3);        // current elements are [3]
 * obj.addElement(1);        // current elements are [3,1]
 * obj.calculateMKAverage(); // return -1, because m = 3 and only 2 elements
 * exist.
 * obj.addElement(10);       // current elements are [3,1,10]
 * obj.calculateMKAverage(); // The last 3 elements are [3,1,10].
 * ⁠                         // After removing smallest and largest 1 element
 * the container will be [3].
 * ⁠                         // The average of [3] equals 3/1 = 3, return 3
 * obj.addElement(5);        // current elements are [3,1,10,5]
 * obj.addElement(5);        // current elements are [3,1,10,5,5]
 * obj.addElement(5);        // current elements are [3,1,10,5,5,5]
 * obj.calculateMKAverage(); // The last 3 elements are [5,5,5].
 * ⁠                         // After removing smallest and largest 1 element
 * the container will be [5].
 * ⁠                         // The average of [5] equals 5/1 = 5, return 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= m <= 10^5
 * 1 <= k*2 < m
 * 1 <= num <= 10^5
 * At most 10^5 calls will be made to addElement and calculateMKAverage.
 * 
 * 
 */

// @lc code=start
using LL = long long;

class MKAverage {
public:
    MKAverage(int m, int k) : m_(m), k_(k) {}
    
    void addElement(int num)
    {
        q.push_back(num);
        if (q.size() < m_) return;
        else if (q.size() == m_) {
            auto w = q;
            sort(w.begin(), w.end());
            for (int i = 0; i < k_; ++i) L.insert(w[i]);
            for (int i = k_; i < m_ - k_; ++i) M.insert(w[i]);
            for (int i = m_ - k_; i < m_; ++i) R.insert(w[i]);
        }
        else {
            M.insert(num);
            if (*L.s.rbegin() > *M.s.begin()) {
                int x = *M.s.begin();
                int y = *L.s.rbegin();
                M.remove(x), L.insert(x);
                L.remove(y), M.insert(y);
            }
            if (*M.s.rbegin() > *R.s.begin()) {
                int x = *M.s.rbegin();
                int y = *R.s.begin();
                M.remove(x), R.insert(x);
                R.remove(y), M.insert(y);
            }

            num = q[q.size() - 1 - m_];
            if (M.s.find(num) != M.s.end()) M.remove(num);
            else if (L.s.find(num) != L.s.end()) {
                L.remove(num);
                int x = *M.s.begin();
                M.remove(x), L.insert(x);
            }
            else {
                R.remove(num);
                int x = *M.s.rbegin();
                M.remove(x), R.insert(x);
            }
        }
    }
    
    int calculateMKAverage()
    {
        if (q.size() < m_) return -1;
        return M.sum / M.s.size();
    }
private:
    struct Range {
        multiset<int> s;
        LL sum = 0;

        void insert(int x)
        {
            s.insert(x);
            sum += x;
        }

        void remove(int x)
        {
            s.erase(s.find(x));
            sum -= x;
        }

    } L, M, R;

    int m_, k_;
    vector<int> q;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
// @lc code=end

