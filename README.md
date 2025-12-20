*This project has been created as part of the 42 curriculum by rhssayn.*

# Push_swap

## Description
Push_swap is a project designed to sort data on a stack using a limited set of operations.  
The goal is to sort a stack of integers in **ascending order** with the **minimum number of moves**, using only two stacks (`a` and `b`) and the following allowed operations:

- `sa`, `sb`, `ss` – swap the first two elements of a stack
- `pa`, `pb` – push the top element from one stack to the other
- `ra`, `rb`, `rr` – rotate stack (top element becomes last)
- `rra`, `rrb`, `rrr` – reverse rotate stack (last element becomes first)

The project emphasizes **algorithm optimization**, understanding of **linked lists**, and **efficient move calculation**.

## Instructions

### Compilation
To compile the main program:

```bash
make        # compile push_swap
make clean  # remove object files
make fclean # remove object files and executables
make re     # recompile everything
```
For the bonus checker program:

```bash
make bonus  # compile checker
```

### Execution

To run the push_swap program:

```bash
./push_swap [numbers]
```

Example:

```bash
./push_swap 3 2 1 6 5
```

To run the bonus checker program:

```bash
./checker [numbers]
```

## Resources

- [42 Push_swap PDF](https://cdn.intra.42.fr/pdf/pdf/189068/en.subject.pdf)
- [C Standard Library Documentation](https://www.cplusplus.com/reference/cstdlib/)
- [Linked List Data Structure](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)
- Tutorials and articles on sorting algorithms (e.g., LIS, insertion sort)

### AI Usage

AI was used to:
- Explain complex algorithmic parts (e.g., minimal moves, LIS calculation)