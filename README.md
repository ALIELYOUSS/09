# C++ Module 09 - STL

42 C++ Module 09: Standard Template Library exercises

## Project Structure

```
09/
├── ex00/                 # Bitcoin Exchange
│   ├── Makefile
│   ├── main.cpp
│   ├── BitcoinExchange.cpp
│   └── BitcoinExchange.hpp
├── ex01/                 # Reverse Polish Notation
│   ├── Makefile
│   ├── main.cpp
│   ├── RPN.cpp
│   └── RPN.hpp
└── ex02/                 # PmergeMe (Merge-Insert Sort)
    ├── Makefile
    ├── main.cpp
    ├── PmergeMe.cpp
    └── PmergeMe.hpp
```

## Exercise 01: Bitcoin Exchange (ex00)

**Program name:** `btc`  
**Container:** `std::map`

### What to do:
- Load bitcoin price data from `data.csv` (CSV format: date,price)
- Read transactions from input file (format: date | value)
- Output the value in bitcoin multiplied by exchange rate
- Use closest lower date if exact date not found

### Build & Run:
```bash
cd ex00
make
./btc input.txt
```

**To test:** You'll need to create `data.csv` with historical Bitcoin prices.

---

## Exercise 02: Reverse Polish Notation (ex01)

**Program name:** `RPN`  
**Container:** `std::stack`

### What to do:
- Parse and evaluate RPN mathematical expressions
- Support operators: `+ - * /`
- Input numbers are single digits (0-9)
- Handle errors appropriately

### Build & Run:
```bash
cd ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"  # Should output: 42
```

---

## Exercise 03: PmergeMe (ex02)

**Program name:** `PmergeMe`  
**Containers:** `std::vector` and `std::deque`

### What to do:
- Implement Ford-Johnson (merge-insert) sort algorithm
- Use TWO different containers
- Sort up to 3000+ integers
- Display unsorted, sorted, and timing for each container

### Build & Run:
```bash
cd ex02
make
./PmergeMe 3 5 9 7 4
```

---

## Compilation Rules

- Compile with: `c++ -Wall -Wextra -Werror -std=c++98`
- Each exercise has its own Makefile
- Makefiles include: `all`, `clean`, `fclean`, `re` targets

## Important Notes

✅ **Allowed:**
- STL containers (map, stack, vector, deque, list, etc.)
- Standard library functions
- Orthodox Canonical Form

❌ **Forbidden:**
- `using namespace std;`
- `friend` keyword
- External libraries
- C++11 and beyond
- `printf()`, `malloc()`, `free()`

---

## Development Tips

1. **Start with ex00** - Map basics
2. **Move to ex01** - Stack usage
3. **Finish with ex02** - Complex data structure manipulation

Each exercise builds on STL knowledge. Once you use a container, you can't use it again in the remaining exercises!

Good luck! 🚀
