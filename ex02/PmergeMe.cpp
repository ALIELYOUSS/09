#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return (*this);
}

void PmergeMe::mergeVector(std::vector<int>& vec, std::vector<int>& left, std::vector<int>& right)
{
	size_t i = 0, j = 0, k = 0;
	
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
			vec[k++] = left[i++];
		else
			vec[k++] = right[j++];
	}
	
	while (i < left.size())
		vec[k++] = left[i++];
	
	while (j < right.size())
		vec[k++] = right[j++];
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	size_t mid = vec.size() / 2;
	std::vector<int> left(vec.begin(), vec.begin() + mid);
	std::vector<int> right(vec.begin() + mid, vec.end());

	mergeInsertSortVector(left);
	mergeInsertSortVector(right);
	mergeVector(vec, left, right);
}

void PmergeMe::mergeDeque(std::deque<int>& dq, std::deque<int>& left, std::deque<int>& right)
{
	size_t i = 0, j = 0, k = 0;
	
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
			dq[k++] = left[i++];
		else
			dq[k++] = right[j++];
	}
	
	while (i < left.size())
		dq[k++] = left[i++];
	
	while (j < right.size())
		dq[k++] = right[j++];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& dq)
{
	if (dq.size() <= 1)
		return;

	size_t mid = dq.size() / 2;
	std::deque<int> left(dq.begin(), dq.begin() + mid);
	std::deque<int> right(dq.begin() + mid, dq.end());

	mergeInsertSortDeque(left);
	mergeInsertSortDeque(right);
	mergeDeque(dq, left, right);
}

void PmergeMe::sort(int argc, char* argv[])
{
	// Parse input and populate both containers
	for (int i = 1; i < argc; i++)
	{
		char* endptr;
		long num = std::strtol(argv[i], &endptr, 10);

		if (*endptr != '\0' || num < 0)
			throw std::runtime_error("Error");

		_vector.push_back(static_cast<int>(num));
		_deque.push_back(static_cast<int>(num));
	}

	// Display before sorting
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << _vector[i];
	}
	std::cout << std::endl;

	// Sort vector and measure time
	clock_t start = clock();
	mergeInsertSortVector(_vector);
	clock_t end = clock();
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	// Sort deque and measure time
	start = clock();
	mergeInsertSortDeque(_deque);
	end = clock();
	_dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	displayResults();
}

void PmergeMe::displayResults()
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << _vector[i];
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size() 
		<< " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() 
		<< " elements with std::deque : " << _dequeTime << " us" << std::endl;
}
