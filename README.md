# 🧩 LeetCode Solutions

<p align="center">
  <img src="https://img.shields.io/badge/LeetCode-Solutions-orange?style=for-the-badge&logo=leetcode" alt="LeetCode Solutions">
  <img src="https://img.shields.io/badge/DSA-Problem%20Solving-blue?style=for-the-badge" alt="DSA">
  <img src="https://img.shields.io/badge/Language-Python-yellow?style=for-the-badge&logo=python" alt="Python">
  <img src="https://img.shields.io/badge/Status-Actively%20Learning-success?style=for-the-badge" alt="Status">
</p>

<p align="center">
  <b>A structured collection of my LeetCode solutions, DSA practice, problem-solving approaches, and algorithmic learning journey.</b>
</p>

---

## 📌 About This Repository

Welcome to my **LeetCode Solutions** repository! 🚀

This repository contains my solutions to problems I solve while practicing **Data Structures and Algorithms (DSA)** on LeetCode.

The main goal of this repository is not just to collect accepted solutions, but to build a strong understanding of:

* 🧠 Problem-solving techniques
* 📚 Data Structures
* ⚡ Algorithms
* ⏱️ Time and Space Complexity
* 🔍 Pattern recognition
* 🧩 Logical thinking
* 💻 Competitive programming
* 🎯 Technical interview preparation

Every problem is approached with the intention of understanding **why the solution works**, rather than simply obtaining an accepted submission.

This repository will continuously grow as I solve more problems and improve my problem-solving skills.

---

## 🎯 Repository Goals

The primary objectives of this repository are:

1. Build strong fundamentals in **Data Structures and Algorithms**.
2. Develop efficient problem-solving techniques.
3. Practice writing clean and readable code.
4. Understand different algorithmic patterns.
5. Improve time and space complexity analysis.
6. Prepare for coding interviews and technical assessments.
7. Maintain a consistent daily coding practice.
8. Track my progress throughout my DSA journey.
9. Learn multiple approaches to the same problem.
10. Build a publicly accessible reference for future revision.

---

# 🗂️ Topics Covered

The repository is organized around the major DSA concepts commonly used in coding interviews and competitive programming.

### 🟢 Beginner / Fundamentals

* Arrays
* Strings
* Hash Tables
* Sorting
* Searching
* Two Pointers
* Sliding Window
* Prefix Sum
* Basic Recursion
* Mathematical Problems
* Bit Manipulation

### 🟡 Intermediate

* Linked Lists
* Stacks
* Queues
* Binary Trees
* Binary Search Trees
* Heaps
* Priority Queues
* Backtracking
* Greedy Algorithms
* Intervals
* Matrix Problems

### 🔴 Advanced

* Graphs
* Dynamic Programming
* Advanced Backtracking
* Advanced Graph Algorithms
* Trie
* Union Find / Disjoint Set Union
* Topological Sorting
* Shortest Path Algorithms
* Minimum Spanning Tree
* Advanced Binary Search
* Advanced Data Structures

---

# 📁 Repository Structure

The repository follows a topic-based structure to make solutions easy to find and revise.

```text
Leetcode-Solutions/
│
├── README.md
│
├── Arrays/
│   ├── Two_Sum.py
│   ├── Best_Time_to_Buy_and_Sell_Stock.py
│   └── ...
│
├── Strings/
│   ├── Valid_Anagram.py
│   ├── Longest_Common_Prefix.py
│   └── ...
│
├── Hashing/
│   ├── Contains_Duplicate.py
│   └── ...
│
├── Two_Pointers/
│   ├── Valid_Palindrome.py
│   └── ...
│
├── Sliding_Window/
│   ├── Longest_Substring_Without_Repeating_Characters.py
│   └── ...
│
├── Linked_List/
│   ├── Reverse_Linked_List.py
│   ├── Merge_Two_Sorted_Lists.py
│   └── ...
│
├── Stack/
│   ├── Valid_Parentheses.py
│   └── ...
│
├── Queue/
│   └── ...
│
├── Binary_Tree/
│   ├── Maximum_Depth_of_Binary_Tree.py
│   └── ...
│
├── Binary_Search/
│   ├── Binary_Search.py
│   └── ...
│
├── Heap/
│   └── ...
│
├── Greedy/
│   └── ...
│
├── Backtracking/
│   └── ...
│
├── Graph/
│   └── ...
│
├── Dynamic_Programming/
│   └── ...
│
└── Bit_Manipulation/
    └── ...
```

> The folder structure may evolve as the repository grows.

---

# 🧠 Solution Format

Each solution aims to follow a consistent structure.

For example:

```python
# Problem: Two Sum
# Difficulty: Easy
# Topic: Array, Hash Table
# LeetCode: 1

class Solution:
    def twoSum(self, nums, target):
        seen = {}

        for i, num in enumerate(nums):
            complement = target - num

            if complement in seen:
                return [seen[complement], i]

            seen[num] = i
```

Whenever appropriate, solutions include:

* Problem name
* LeetCode problem number
* Difficulty
* Topic
* Approach
* Code
* Time complexity
* Space complexity
* Important observations

---

# ⚙️ Complexity Analysis

Understanding complexity is an important part of this repository.

For every important solution, I try to analyze:

### ⏱️ Time Complexity

How the execution time grows as the input size increases.

Examples:

```text
O(1)       Constant
O(log n)   Logarithmic
O(n)       Linear
O(n log n) Linearithmic
O(n²)      Quadratic
O(2ⁿ)      Exponential
O(n!)      Factorial
```

### 💾 Space Complexity

How much additional memory the algorithm requires.

Examples:

```text
O(1)       Constant extra space
O(n)       Linear extra space
O(log n)   Recursive/stack space
O(n²)      Quadratic space
```

The goal is to gradually learn how to replace inefficient approaches with optimized ones.

---

# 🔥 Important DSA Patterns

One of the major goals of this repository is to recognize reusable problem-solving patterns.

## 1. Two Pointers

Useful for:

* Sorted arrays
* Pair problems
* Palindrome problems
* Removing duplicates
* In-place array manipulation

General idea:

```text
left  → 
        ← right
```

---

## 2. Sliding Window

Useful for:

* Subarrays
* Substrings
* Maximum/minimum windows
* Longest/shortest valid sequences

Typical structure:

```text
left = 0

for right in range(n):

    # expand window

    while condition_is_invalid:
        # shrink window
        left += 1
```

---

## 3. Hashing

Useful for:

* Frequency counting
* Duplicate detection
* Pair-sum problems
* Fast lookups
* Grouping elements

Typical Python tools:

```python
dict
set
collections.Counter
defaultdict
```

---

## 4. Binary Search

Useful when the search space is sorted or when a monotonic condition exists.

Typical complexity:

```text
O(log n)
```

---

## 5. Fast & Slow Pointers

Commonly used with linked lists.

Applications include:

* Detecting cycles
* Finding the middle node
* Finding cycle entry points

---

## 6. Recursion

Useful for:

* Trees
* Graph traversal
* Backtracking
* Divide-and-conquer

---

## 7. Backtracking

Useful for:

* Permutations
* Combinations
* Subsets
* N-Queens
* Sudoku
* Constraint-based problems

General pattern:

```text
Choose
   ↓
Explore
   ↓
Undo
```

---

## 8. Greedy Algorithms

Greedy algorithms make the best available local decision with the expectation that it leads to an optimal solution.

Common applications:

* Activity selection
* Jump problems
* Interval scheduling
* Minimum number of operations

---

## 9. Dynamic Programming

DP is used when a problem contains:

* Overlapping subproblems
* Optimal substructure

Typical approaches:

```text
Top-Down
Memoization
Bottom-Up
Tabulation
```

---

## 10. Graph Traversal

Important algorithms include:

```text
BFS
DFS
Dijkstra
Topological Sort
Union Find
Minimum Spanning Tree
```

---

# 📊 Difficulty Levels

Problems are categorized according to their LeetCode difficulty.

| Difficulty | Description                               |
| ---------- | ----------------------------------------- |
| 🟢 Easy    | Fundamental concepts and basic patterns   |
| 🟡 Medium  | Requires stronger logic and optimization  |
| 🔴 Hard    | Advanced algorithms and complex reasoning |

The objective is to gradually progress from:

```text
Easy
  ↓
Medium
  ↓
Hard
```

rather than trying to solve only difficult problems from the beginning.

---

# 📝 Example Problem Documentation

A well-documented solution may follow this format:

```text
Problem:
Two Sum

Problem Number:
1

Difficulty:
Easy

Topics:
Array, Hash Table

Approach:
Use a hash map to store previously visited numbers.
For every number, calculate its complement with respect
to the target. If the complement already exists, return
the corresponding indices.

Time Complexity:
O(n)

Space Complexity:
O(n)
```

This makes the repository useful not only for submissions but also for **revision before interviews and exams**.

---

# 🏆 Learning Strategy

My approach to solving problems follows a structured process.

### Step 1 — Understand the Problem

Before writing code:

* Read the problem carefully.
* Identify the input.
* Identify the expected output.
* Understand the constraints.
* Check edge cases.

### Step 2 — Think About Brute Force

First determine the simplest possible solution.

This helps understand:

* What the problem is asking.
* Why the brute-force solution works.
* Where the inefficiency comes from.

### Step 3 — Identify the Pattern

Ask:

```text
Can hashing help?
Can two pointers help?
Can I use a sliding window?
Is binary search possible?
Can this be solved recursively?
Is this a DP problem?
Is this a graph problem?
```

### Step 4 — Optimize

Compare possible approaches based on:

* Time complexity
* Space complexity
* Code simplicity
* Input constraints

### Step 5 — Implement

Write clean and readable code.

### Step 6 — Test

Check:

* Normal cases
* Edge cases
* Empty input
* Duplicate values
* Large input
* Negative values
* Boundary conditions

### Step 7 — Analyze

Finally document:

```text
Time Complexity
Space Complexity
Approach
Key Insight
```

---
### 🧠 Problem-Solving Approach

The [`Approach/`](https://github.com/Ronit049/Leetcode/tree/main/Approach) folder contains my visual problem-solving notes and handwritten approaches for selected LeetCode problems, documenting the thought process and logic I use before writing the final solution.

---

# 📈 Progress Tracking

The repository is intended to act as a long-term DSA progress tracker.

A typical progress table can be maintained as follows:

| Category            | Problems Solved |
| ------------------- | --------------: |
| Arrays              |     🔄 Updating |
| Strings             |     🔄 Updating |
| Hashing             |     🔄 Updating |
| Two Pointers        |     🔄 Updating |
| Sliding Window      |     🔄 Updating |
| Linked Lists        |     🔄 Updating |
| Stack               |     🔄 Updating |
| Queue               |     🔄 Updating |
| Binary Search       |     🔄 Updating |
| Trees               |     🔄 Updating |
| Heap                |     🔄 Updating |
| Graphs              |     🔄 Updating |
| Greedy              |     🔄 Updating |
| Backtracking        |     🔄 Updating |
| Dynamic Programming |     🔄 Updating |

> The numbers will be updated as more problems are solved.

---

# 🎯 Roadmap

## Phase 1 — Fundamentals

* [ ] Arrays
* [ ] Strings
* [ ] Hashing
* [ ] Sorting
* [ ] Searching
* [ ] Two Pointers
* [ ] Sliding Window
* [ ] Prefix Sum

## Phase 2 — Linear Data Structures

* [ ] Linked Lists
* [ ] Stacks
* [ ] Queues
* [ ] Deques

## Phase 3 — Non-Linear Data Structures

* [ ] Binary Trees
* [ ] Binary Search Trees
* [ ] Heaps
* [ ] Tries

## Phase 4 — Advanced Algorithms

* [ ] Recursion
* [ ] Backtracking
* [ ] Greedy
* [ ] Graphs
* [ ] Dynamic Programming
* [ ] Union Find
* [ ] Advanced Graph Algorithms

## Phase 5 — Interview Preparation

* [ ] Solve problems without hints
* [ ] Improve speed
* [ ] Practice timed contests
* [ ] Revise common patterns
* [ ] Solve company-tagged problems
* [ ] Practice mock interviews
* [ ] Revisit previously solved problems

---

# 💡 Key Principles

This repository follows a few important principles:

### 1. Understand Before Memorizing

The objective is to understand the algorithm instead of memorizing code.

### 2. Optimize When Necessary

An accepted solution is not always the best solution.

### 3. Learn From Mistakes

Wrong answers and failed approaches are part of the learning process.

### 4. Focus on Patterns

Many seemingly different problems can be solved using the same underlying pattern.

### 5. Write Clean Code

Readable code is easier to debug, maintain, and explain during interviews.

### 6. Stay Consistent

Regular practice is more valuable than solving many problems once and stopping.

---

# 🛠️ Technologies Used

The primary language used in this repository is:

### 🐍 Python

Python is used because of its:

* Simple syntax
* Powerful built-in data structures
* Large standard library
* Fast implementation
* Excellent support for algorithmic problem solving

Commonly used Python features include:

```python
list
dict
set
tuple
deque
heapq
Counter
defaultdict
enumerate()
zip()
sorted()
```

---

# 💻 Running the Solutions Locally

Clone the repository:

```bash
git clone https://github.com/<your-username>/Leetcode-Solutions.git
```

Move into the repository:

```bash
cd Leetcode-Solutions
```

Run a Python solution:

```bash
python filename.py
```

For example:

```bash
python Arrays/Two_Sum.py
```

> Some files are written specifically for the LeetCode platform and may contain only the `Solution` class rather than a standalone input/output program.

---

# 🔍 How to Use This Repository

This repository can be useful for:

### 📚 Learning

Study the approach behind each problem.

### 🔁 Revision

Return to previously solved problems and review important patterns.

### 🎯 Interview Preparation

Practice frequently asked DSA concepts.

### 🧠 Pattern Recognition

Identify which algorithmic technique applies to a new problem.

### 📊 Progress Tracking

Use the repository to measure improvement over time.

---

# 🚀 Future Improvements

As the repository grows, I plan to add:

* 📌 More LeetCode problems
* 🧠 Detailed explanations
* ⚡ Optimized approaches
* 📊 Complexity analysis
* 🗂️ Better topic categorization
* 🔥 Important DSA patterns
* 🎯 Interview-focused problem sets
* 🏢 Company-wise problems
* 📅 Daily/weekly progress tracking
* 📝 Revision notes
* 🧪 Test cases
* 🔄 Multiple approaches for important problems

---

# 🤝 Contributions

This repository is primarily created for personal learning and DSA practice, but suggestions and improvements are welcome.

If you find:

* A bug
* An incorrect solution
* A better approach
* A missing edge case
* An optimization
* A documentation improvement

feel free to open an **Issue** or submit a **Pull Request**.

---

# ⭐ If This Repository Helps You

If you find this repository useful for your own DSA preparation, consider giving it a ⭐.

It helps support the project and encourages me to keep improving and adding more solutions.

---

# 📚 Recommended Practice Approach

Instead of solving problems randomly, focus on patterns.

A useful progression is:

```text
Arrays
   ↓
Hashing
   ↓
Two Pointers
   ↓
Sliding Window
   ↓
Stack & Queue
   ↓
Binary Search
   ↓
Linked Lists
   ↓
Trees
   ↓
Heap
   ↓
Graphs
   ↓
Greedy
   ↓
Backtracking
   ↓
Dynamic Programming
```

Once the fundamentals become comfortable, start mixing different patterns so that you learn to identify the correct technique without being explicitly told which one to use.

---

# 🧠 Problem-Solving Mindset

When facing a new problem, ask yourself:

```text
1. What exactly is being asked?
2. What are the constraints?
3. What would the brute-force solution look like?
4. Can I reduce repeated work?
5. Can hashing help?
6. Can I sort the input?
7. Can I use two pointers?
8. Can I use a sliding window?
9. Is binary search applicable?
10. Is recursion useful?
11. Is there an overlapping-subproblem structure?
12. Can I improve the time complexity?
13. What edge cases can break my solution?
```

These questions help transform problem solving from **guessing** into a systematic process.

---

# 🏁 Final Goal

The ultimate goal of this repository is not simply to achieve a large number of solved problems.

The real goal is to become better at:

> **Thinking → Analyzing → Designing → Optimizing → Implementing → Explaining**

Every solved problem is another step toward becoming a stronger software developer and problem solver.

---

## 📌 Repository Motto

> **Solve problems. Learn patterns. Optimize solutions. Build consistency.**

---

<p align="center">
  <b>💻 Keep Coding • 🧠 Keep Learning • 🚀 Keep Improving</b>
</p>

<p align="center">
  Made with ❤️ and tea ☕ for the DSA journey.
</p>
