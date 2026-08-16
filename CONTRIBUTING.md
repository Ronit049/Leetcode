# Contributing to LeetCode Solutions

Thank you for your interest in contributing to this repository! 🎯

This repository is focused on **LeetCode problem solving, Data Structures & Algorithms, coding patterns, and interview preparation**.

Contributions are welcome if they improve the quality, clarity, organization, or learning value of the repository.

---

## 📌 How You Can Contribute

You can contribute in several ways:

* Add a new LeetCode solution
* Improve an existing solution
* Add a better or more efficient approach
* Fix bugs or incorrect solutions
* Improve explanations
* Add time and space complexity analysis
* Add DSA notes
* Add useful problem-solving patterns
* Improve documentation
* Fix spelling, formatting, or broken links

---

## 📂 Repository Structure

Before contributing, please follow the existing repository structure.

```text
leetcode/
│
├── LeetCode-Solutions/
│   ├── Easy/
│   ├── Medium/
│   └── Hard/
│
├── Questions/
│   ├── Easy/
│   ├── Medium/
│   └── Hard/
│
├── Topics/
│
├── Patterns/
│
├── Notes/
│
├── README.md
├── ROADMAP.md
├── PROGRESS.md
├── CONTRIBUTING.md
├── LICENSE
└── .gitignore
```

---

## 💻 Adding a New Solution

When adding a solution, place it in the appropriate difficulty folder.

For example:

```text
LeetCode-Solutions/
└── Easy/
    └── 0001-two-sum/
        ├── solution.py
        └── README.md
```

Use the following naming convention:

```text
problem-number-problem-name
```

Example:

```text
0001-two-sum
0013-roman-to-integer
0020-valid-parentheses
```

---

## 📝 Solution Format

Each solution should preferably contain:

1. Problem name
2. Problem number
3. Problem link
4. Approach
5. Algorithm
6. Time complexity
7. Space complexity
8. Implementation

Example:

````markdown
# Two Sum

**LeetCode:** #1

## Problem

Given an array of integers `nums` and an integer `target`,
return indices of the two numbers such that they add up to target.

## Approach

Use a hash map to store previously visited numbers and their indices.

For every element, calculate:

complement = target - nums[i]

If the complement already exists in the hash map, return its index
and the current index.

## Complexity

- Time: O(n)
- Space: O(n)

## Solution

```python
class Solution:
    def twoSum(self, nums, target):
        seen = {}

        for i, num in enumerate(nums):
            complement = target - num

            if complement in seen:
                return [seen[complement], i]

            seen[num] = i
````

````

---

## 🔀 Multiple Approaches

If a problem has multiple important approaches, contributors are encouraged to include them.

For example:

```text
Approach 1 → Brute Force
Approach 2 → Hash Map
Approach 3 → Sorting + Two Pointers
````

Clearly mention which approach is more efficient.

---

## ⏱️ Complexity Analysis

Every solution should include complexity analysis whenever possible.

Use the standard format:

```text
Time Complexity: O(n)
Space Complexity: O(n)
```

Avoid adding incorrect or unnecessary complexity claims.

---

## 🧹 Code Quality

Please make sure your code is:

* Easy to understand
* Properly formatted
* Free from unnecessary code
* Properly indented
* Consistent with the language style
* Tested before submission

Avoid:

```python
# unnecessary comments everywhere
# duplicate code
# unused variables
```

Prefer clean and readable implementations.

---

## 🌐 Supported Languages

Solutions can be contributed in commonly used programming languages, including:

* Python
* C++
* Java
* JavaScript
* TypeScript
* C

When possible, use the language's standard conventions.

---

## 🐛 Reporting an Issue

If you find a problem, please open a GitHub Issue.

Useful issues include:

* Incorrect solution
* Wrong complexity analysis
* Broken link
* Typographical error
* Missing explanation
* Poorly formatted code
* Incorrect problem categorization

When reporting an issue, provide enough information to reproduce or understand the problem.

---

## 🔄 Pull Request Process

Follow these steps:

### 1. Fork the Repository

Create your own fork of the repository.

### 2. Clone Your Fork

```bash
git clone https://github.com/Ronit049/Leetcode.git
```

### 3. Create a Branch

Use a meaningful branch name:

```bash
git checkout -b add-two-sum-solution
```

Other examples:

```text
fix-roman-to-integer
add-array-notes
improve-sliding-window
update-readme
```

### 4. Make Your Changes

Add or modify the required files.

### 5. Test Your Solution

Make sure the solution works correctly before submitting.

### 6. Commit Your Changes

Use a clear commit message:

```bash
git add .
git commit -m "Add Two Sum solution"
```

### 7. Push Your Branch

```bash
git push origin add-two-sum-solution
```

### 8. Open a Pull Request

Create a Pull Request from your branch to the `main` branch.

---

## 📋 Pull Request Checklist

Before submitting a Pull Request, make sure:

* [ ] The solution is correct
* [ ] The code has been tested
* [ ] The correct difficulty folder is used
* [ ] The problem number and name are correct
* [ ] The explanation is clear
* [ ] Time complexity is included
* [ ] Space complexity is included
* [ ] No unnecessary files are included
* [ ] Code follows the repository structure
* [ ] Commit messages are clear

---

## 🚫 What Not to Submit

Please avoid submitting:

* Plagiarized solutions without meaningful contribution
* Unrelated projects
* Executable or binary files
* API keys or passwords
* `.env` files containing secrets
* Personal information
* Malicious code
* Unnecessary dependencies

**Never commit secrets or API keys to this repository.**

---

## 🤝 Code of Conduct

All contributors are expected to be respectful and constructive.

Please:

* Be respectful to other contributors
* Give constructive feedback
* Help others learn
* Avoid offensive or inappropriate content
* Respect different approaches and programming styles

The goal of this repository is to **learn, practice, and improve together**.

---

## 💡 Suggestions

If you have an idea that could improve the repository, feel free to open an Issue and describe:

1. What you want to improve
2. Why it would be useful
3. How you think it could be implemented

---

## ⭐ Support the Repository

If you find this repository useful:

* ⭐ Star the repository
* 🍴 Fork it
* 🐛 Report issues
* 💡 Suggest improvements
* 🤝 Contribute solutions

Every contribution helps make this repository better for DSA and interview preparation.

---

## 📄 License

By contributing to this repository, you agree that your contributions will be licensed under the repository's **MIT License**.

See the [LICENSE](LICENSE) file for more information.

---

## 👨‍💻 Maintainer

**Ronit Raj**

GitHub: [@Ronit049](https://github.com/Ronit049)

---

Thank you for contributing! 🚀

**Happy Coding & Keep Solving! 💻**
