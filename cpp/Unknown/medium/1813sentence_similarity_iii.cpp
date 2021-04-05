/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 *
 * https://leetcode.com/problems/sentence-similarity-iii/description/
 *
 * algorithms
 * Medium (35.43%)
 * Likes:    64
 * Dislikes: 10
 * Total Accepted:    3.9K
 * Total Submissions: 10.8K
 * Testcase Example:  '"My name is Haley"\n"My Haley"'
 *
 * A sentence is a list of words that are separated by a single space with no
 * leading or trailing spaces. For example, "Hello World", "HELLO", "hello
 * world hello world" are all sentences. Words consist of only uppercase and
 * lowercase English letters.
 * 
 * Two sentences sentence1 and sentence2 are similar if it is possible to
 * insert an arbitrary sentence (possibly empty) inside one of these sentences
 * such that the two sentences become equal. For example, sentence1 = "Hello my
 * name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting
 * "my name is" between "Hello" and "Jane" in sentence2.
 * 
 * Given two sentences sentence1 and sentence2, return true if sentence1 and
 * sentence2 are similar. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
 * Output: true
 * Explanation: sentence2 can be turned to sentence1 by inserting "name is"
 * between "My" and "Haley".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: sentence1 = "of", sentence2 = "A lot of words"
 * Output: false
 * Explanation: No single sentence can be inserted inside one of the sentences
 * to make it equal to the other.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: sentence1 = "Eating right now", sentence2 = "Eating"
 * Output: true
 * Explanation: sentence2 can be turned to sentence1 by inserting "right now"
 * at the end of the sentence.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: sentence1 = "Luky", sentence2 = "Lucccky"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= sentence1.length, sentence2.length <= 100
 * sentence1 and sentence2 consist of lowercase and uppercase English letters
 * and spaces.
 * The words in sentence1 and sentence2 are separated by a single space.
 * 
 * 
 */

// @lc code=start
// use stringstream to split string.
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2)
    {
        if (s1.size() > s2.size()) return areSentencesSimilar(s2, s1);
        stringstream ssin1(s1), ssin2(s2);
        vector<string> a, b;
        string s;
        while (ssin1 >> s) a.push_back(s);
        while (ssin2 >> s) b.push_back(s);

        int i = 0, j = a.size() - 1;
        for (int k = 0; k < b.size() && i < a.size(); ++k) {
            if (a[i] == b[k]) ++i;
            else break;
        }
        for (int k = b.size() - 1; k >= 0 && j >= 0; --k) {
            if (a[j] == b[k]) --j;
            else break;
        }
        return i > j;
    }
};
// @lc code=end

