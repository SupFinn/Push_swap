*This project has been created as part of the 42 curriculum by rhssayn.*

# 🔁 push_swap

## 📌 Description

**push_swap** is an algorithmic project from the 42 curriculum that consists of sorting a stack of integers using a **limited set of operations** and **two stacks** (`a` and `b`), while producing the **minimum number of moves possible**.

The challenge is not only to sort the data correctly, but to do so **efficiently**, which requires choosing and implementing an optimized algorithm.

---

## 🎯 Project Objectives

- 🧠 Understand algorithmic problem-solving
- 📚 Manipulate linked lists and stacks
- 🔄 Work with constrained operations
- ⚡ Optimize the number of instructions
- 🧪 Handle edge cases and input validation
- 🚀 Develop a scalable sorting strategy

---

## ⚙️ Allowed Operations

| Operation | Description |
|---------|-------------|
| `sa` / `sb` | Swap the first two elements |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push top element between stacks |
| `ra` / `rb` | Rotate stack up |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate |
| `rrr` | `rra` and `rrb` simultaneously |

---

## 🧠 Algorithm Choice

### ✅ Longest Increasing Subsequence (LIS) + Greedy Strategy

For large inputs, this project uses a **LIS-based approach** combined with a **greedy reinsertion strategy**.

### 🔍 Why LIS?

- The **Longest Increasing Subsequence** represents elements already in correct relative order
- These elements are kept in **stack A**
- All other elements are pushed to **stack B**
- This reduces unnecessary operations

### 🧩 Strategy Overview

1. Convert stack A into an array
2. Compute the **LIS** using **Dynamic Programming**
3. Keep LIS elements in stack A
4. Push remaining elements to stack B
5. Reinsert elements from B to A with minimal cost
6. Final rotation to fully sort stack A

---

## 🧮 Algorithm Concepts Used

- 📈 Dynamic Programming (LIS computation)
- 🎯 Greedy algorithm (best move selection)
- 🔢 Indexing / normalization
- 🔁 Stack rotations optimization
- 🧠 Cost calculation for moves

---

## ▶️ Usage

### 📦 Compilation
```bash
make
