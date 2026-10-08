# C++ Module 09: STL

Solutions for **42's C++ Module 09**, focused on the Standard Template Library and
the practical use of associative containers, stacks, sequences, and algorithms.

## Exercises

| Directory | Program | Main topic | STL container |
| --- | --- | --- | --- |
| `ex00` | `btc` | Bitcoin exchange-rate lookup | `std::map` |
| `ex01` | `RPN` | Reverse Polish Notation evaluation | `std::stack` |
| `ex02` | `PmergeMe` | Ford-Johnson merge-insert sorting | `std::vector`, `std::deque` |

## Requirements

- A C++ compiler with C++98 support
- `make`
- Unix-like environment

Every exercise is compiled with:

```text
c++ -Wall -Wextra -Werror -std=c++98
```

## Build

Each exercise is independent and has its own Makefile:

```bash
cd ex00 && make
cd ../ex01 && make
cd ../ex02 && make
```

The available Make targets are `all`, `clean`, `fclean`, and `re`.

## Usage

### `ex00` - Bitcoin Exchange

`btc` reads historical prices from `data.csv` in the current directory and
processes an input file containing lines in the form `date | value`.

```bash
cd ex00
make
./btc input.txt
```

The database must use comma-separated records such as:

```text
date,exchange_rate
2011-01-03,0.3
2011-01-04,0.4
```

The input file contains one transaction per line:

```text
date | value
2011-01-03 | 2
```

When an exact date is unavailable, the program uses the closest earlier rate.

### `ex01` - Reverse Polish Notation

`RPN` evaluates a space-separated expression using the operators `+`, `-`, `*`,
and `/`. Operands are single digits.

```bash
cd ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# 42
```

### `ex02` - PmergeMe

`PmergeMe` sorts positive integer arguments with the Ford-Johnson
merge-insert algorithm and compares the performance of `std::vector` and
`std::deque`.

```bash
cd ex02
make
./PmergeMe 3 5 9 7 4
```

The program reports the input sequence, the sorted sequence, and the execution
time for each container.

## Project Structure

```text
.
├── ex00/
│   ├── BitcoinExchange.cpp
│   ├── BitcoinExchange.hpp
│   ├── Makefile
│   └── main.cpp
├── ex01/
│   ├── Makefile
│   ├── RPN.cpp
│   ├── RPN.hpp
│   └── main.cpp
├── ex02/
│   ├── Makefile
│   ├── PmergeMe.cpp
│   ├── PmergeMe.hpp
│   └── main.cpp
└── README.md
```

## Cleanup

Remove build artifacts from one exercise with:

```bash
make fclean
```

Or clean all exercises from the repository root:

```bash
for directory in ex00 ex01 ex02; do make -C "$directory" fclean; done
```

## C++98 Constraints

This project intentionally uses C++98. No external libraries or C++11-and-later
features are required. The exercises demonstrate STL usage while following the
module's restrictions, including Orthodox Canonical Form where applicable.
