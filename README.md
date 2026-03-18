# Movie Tracker — Linked List (C++)

A C++ console application for managing a personal movie list using a **singly linked list**. Supports adding, updating, removing, and sorting movies by title, year viewed, or rating. Saves data to a text file and properly deallocates all memory on exit.

---

## Features

- Singly linked list with dynamic node allocation
- Add, update, and remove movies by index
- Sort by title, year viewed, or rating (descending)
- Saves all entries to `movies.txt` on quit
- Full memory deallocation on exit (no leaks)

---

## Concepts Demonstrated

- Singly linked list (manual implementation)
- Dynamic memory allocation and deallocation (`new` / `delete`)
- Linked list traversal, insertion, and removal
- Sorting a linked list by swapping node data
- File I/O with `ofstream`
- Pointer-to-pointer (`Movie*&`) for head node modification

---

## How to Run

### Online (easiest)
Paste `Lab10.cpp` into [onlinegdb.com](https://onlinegdb.com), set language to C++, and hit Run.

### Local (requires g++)
```bash
g++ -o movie_tracker Lab10.cpp
./movie_tracker
```

No input files required.

---

## Usage

```
MENU
Press A ..Add a movie
Press U ..Update a movie
Press E ..Erase a movie
Press L ..List all movies
Press T ..Arrange by title
Press V ..arrange by year viewed
Press R ..arrange by Rating
Press Q ..Quit

Your choice > A

Adding Movie...
Enter a movie's name > Inception
Enter the year you saw Inception [Like 2020]: 2022
Enter your rating of Inception [Like 1, 2, 3, 4, 5]: 5
```

---

## Notes

- Movies are stored in a linked list — new entries are prepended to the head
- On quit, all entries are written to `movies.txt` and all nodes are deallocated
- Sorting swaps node data in place rather than relinking pointers
