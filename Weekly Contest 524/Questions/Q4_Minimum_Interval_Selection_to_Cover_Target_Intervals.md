```
You are given two 2D integer arrays, availableIntervals and targetIntervals, each representing a list of closed intervals.

Select a subset of intervals from availableIntervals so that every real point contained in any interval in targetIntervals belongs to at least one selected interval.

Points outside the target intervals do not need to be covered. Selected intervals may overlap or extend beyond the target intervals.

Return the minimum number of intervals you need to select. If it is impossible to cover all the target intervals, return -1.

 

Example 1:

Input: availableIntervals = [[1,4],[1,7],[3,9],[5,10],[10,15]], targetIntervals = [[1,3],[2,5],[7,8],[10,13],[11,15],[12,13]]

Output: 3

Explanation:

The target intervals cover the ranges [1, 5], [7, 8], and [10, 15]. By selecting [1, 4], [3, 9], and [10, 15] from availableIntervals, all target intervals can be fully covered with three intervals.

Example 2:

Input: availableIntervals = [[4,6],[1,4],[2,5]], targetIntervals = [[3,4],[2,5],[6,7]]

Output: -1

Explanation:

It is impossible to select intervals from availableIntervals to cover all the intervals in targetIntervals.

Example 3:

Input: availableIntervals = [[1,2],[3,4]], targetIntervals = [[1,4]]

Output: -1

Explanation:

Selecting both available intervals leaves every real point strictly between 2 and 3 uncovered. For example, 2.5 belongs to the target interval but to neither available interval.

 

Constraints:

1 <= availableIntervals.length, targetIntervals.length <= 5 * 104
availableIntervals[i].length == targetIntervals[j].length == 2
1 <= availableIntervals[i][0] <= availableIntervals[i][1] <= 105
1 <= targetIntervals[j][0] <= targetIntervals[j][1] <= 105
```