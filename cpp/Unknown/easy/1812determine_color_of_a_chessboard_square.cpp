/*
 * @lc app=leetcode id=1812 lang=cpp
 *
 * [1812] Determine Color of a Chessboard Square
 *
 * https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/
 *
 * algorithms
 * Easy (77.57%)
 * Likes:    46
 * Dislikes: 2
 * Total Accepted:    5.3K
 * Total Submissions: 6.8K
 * Testcase Example:  '"a1"'
 *
 * You are given coordinates, a string that represents the coordinates of a
 * square of the chessboard. Below is a chessboard for your reference.
 * 
 * 
 * 
 * Return true if the square is white, and false if the square is black.
 * 
 * The coordinate will always represent a valid chessboard square. The
 * coordinate will always have the letter first, and the number second.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coordinates = "a1"
 * Output: false
 * Explanation: From the chessboard above, the square with coordinates "a1" is
 * black, so return false.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coordinates = "h3"
 * Output: true
 * Explanation: From the chessboard above, the square with coordinates "h3" is
 * white, so return true.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coordinates = "c7"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * coordinates.length == 2
 * 'a' <= coordinates[0] <= 'h'
 * '1' <= coordinates[1] <= '8'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool squareIsWhite(string c)
    {
        // int x = coordinates[0] - 'a';
        // int y = coordinates[1] - '0';
        // if ((x + y) % 2 == 0) return true;
        // else return false;
        return (c[0] + c[1]) % 2;
    }
};
// @lc code=end

