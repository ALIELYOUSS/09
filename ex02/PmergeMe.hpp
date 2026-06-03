#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
private:
	std::vector<int>	_vector;
	std::deque<int>		_deque;
	double				_vectorTime;
	double				_dequeTime;

	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	// Vector sorting helpers
	void	mergeInsertSortVector(std::vector<int>& vec);
	void	mergeVector(std::vector<int>& vec, std::vector<int>& left, std::vector<int>& right);

	// Deque sorting helpers
	void	mergeInsertSortDeque(std::deque<int>& dq);
	void	mergeDeque(std::deque<int>& dq, std::deque<int>& left, std::deque<int>& right);

public:
	PmergeMe();
	~PmergeMe();

	void	sort(int argc, char* argv[]);
	void	displayResults();
};

#endif
