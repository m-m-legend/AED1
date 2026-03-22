# 📊 AED1 - Algorithms and Data Structures I

A repository dedicated to storing **classic algorithms** and **fundamental data structures**, implemented in **C++**.

## 📋 Description

This repository contains implementations of essential algorithms and data structures learned during the Algorithms and Data Structures I course at UERJ and supplemented with learning through online courses. The main focus is to consolidate fundamental knowledge through practical and efficient implementations.

## 🎯 Objective

- 📚 Document learning in AED I
- 💻 Correctly implement classic algorithms
- 🏗️ Build data structures from scratch
- 🚀 Serve as a reference for efficient implementations
- 📈 Preparation for technical interviews and more complex problems

## 📂 Repository Structure

```
AED1/
├── ... (C++ algorithms)
README.md
```

## 🚀 Content

### 🏗️ Data Structures

- **Arrays and Matrices**: Manipulation and basic operations
- **Linear Lists**: Simple and doubly linked lists
- **Stacks**: LIFO, classic applications
- **Queues**: FIFO, classic applications
- **Binary Trees**: Traversals, search, insertion
- **Heaps**: Min-heap, Max-heap

### 🧮 Algorithms

- **Sorting**: Selection Sort, Insertion Sort, Merge Sort
- **Search**: Linear Search, Binary Search
- **Complexity Analysis**: O(n), O(log n), O(n²), etc.

## 🛠️ Technologies

- ![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white)
- C++11 or higher

## 📖 How to Use

1. **Clone the repository**:
   ```bash
   git clone https://github.com/m-m-legend/AED1.git
   cd AED1
   ```

2. **Compile a specific file**:
   ```bash
   g++ program_file.cpp -std=c++11 -o program
   ```

3. **Run the program**:
   ```bash
   ./program
   ```

## 📚 Implemented Data Structures

### Basic
- [x] Dynamic array
- [x] Simple linked list
- [x] Stack
- [x] Queue

### Intermediate
- [x] Binary search tree
- [x] Doubly linked list
- [x] Deque (Double-ended queue)

## 🧮 Implemented Algorithms

### Sorting
- [x] Selection Sort - O(n²)
- [x] Insertion Sort - O(n²)
- [x] Merge Sort - O(n log n)
- [x] Bubble Sort - O(n²)


### Search
- [x] Linear Search - O(n)
- [x] Binary Search - O(log n)

## 💡 Key Learnings

- Deep understanding of data structures
- Time and space complexity analysis
- Correct implementation of pointers and references in C++
- OOP principles applied to data structures
- Algorithm optimization

## 🔗 Key Concepts

```cpp
// Example: Stack Implementation with OOP
class Stack {
private:
    vector<int> data;
public:
    void push(int value) { data.push_back(value); }
    int pop() { 
        int temp = data.back();
        data.pop_back();
        return temp;
    }
    bool isEmpty() { return data.empty(); }
};
```

## 📖 References

- **Book**: "Introduction to Algorithms" - CLRS
- **Platform**: LeetCode, CodeSignal
- **Courses**: MIT OpenCourseWare, Coursera

## 🤝 Contribution

This is a personal learning repository. Suggestions, corrections and improvements are welcome through issues or pull requests.

## 📄 License

This project is under the [MIT](LICENSE) license - feel free to use it as a reference or basis for your own projects.

## 📞 Contact

- GitHub: [@m-m-legend](https://github.com/m-m-legend)
- Email: [nintendo_64m@outlook.com]

---

**Last update**: 2026  
**Status**: Active development
