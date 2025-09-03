/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:26:30 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/08/11 12:26:33 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_vector = other._vector;
	this->_deque = other._deque;
	this->_levelVector = other._levelVector;
	this->_levelDeque = other._levelDeque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
		this->_levelVector = other._levelVector;
		this->_levelDeque = other._levelDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

std::vector<int> PmergeMe::jacobsthal(int size)
{
	std::vector<int> order;
	std::vector<int> jacob;

	jacob.push_back(0);
	jacob.push_back(1);

	while (42)
	{
		int next = jacob[jacob.size() - 1] + (2 * jacob[jacob.size() - 2]);
		jacob.push_back(next);
		if (next > size)
			break;
	}

	int last = -1;
	for (int i = 2; i < static_cast<int>(jacob.size()); ++i)
	{
		int	j = jacob[i];
		if (j -1 > size)
			j = size;
		for (int k = j; k > last; --k)
		{
			if (k < size)
				order.push_back(k);
		}
		last = j;
	}
	return order;
}

struct PmergeMe::BlockComparatorV
{
	bool operator()(const std::vector<int>& block, int value) const
	{
		return block.back() < value;
	}
	bool operator()(int value, const std::vector<int>& block) const
	{
		return value < block.back();
	}
};

struct PmergeMe::BlockComparatorD
{
	bool operator()(const std::deque<int>& block, int value) const
	{
		return block.back() < value;
	}
	bool operator()(int value, const std::deque<int>& block) const
	{
		return value < block.back();
	}
};

void PmergeMe::binaryInsertVector(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &trail, int unit)
{
	std::vector<std::vector<int> > mainBlocks;
	std::vector<std::vector<int> > pendBlocks;
	for (int i = 0; i < static_cast<int>(main.size()); i += unit)
	{
		int end = i + unit;
		if (end > static_cast<int>(main.size()))
			end = static_cast<int>(main.size()); // this should not ve necessary and could i + unit all

		std::vector<int> block(main.begin() + i, main.begin() + end);
		mainBlocks.push_back(block);
	}
	for (int i = 0; i < static_cast<int>(pend.size()); i += unit)
	{
		int end = i + unit;
		if (end > static_cast<int>(pend.size()))
			end = static_cast<int>(pend.size()); // this should not ve necessary and could i + unit all

		std::vector<int> block(pend.begin() + i, pend.begin() + end);
		pendBlocks.push_back(block);
	}

	std::vector<int> insertOrder = jacobsthal(static_cast<int>(pendBlocks.size()));
	for (int i = 0; i < static_cast<int>(pendBlocks.size()); ++i)
	{
		int jacob = insertOrder[i];
		if (jacob >= static_cast<int>(pendBlocks.size()))
			continue;

		std::vector<int> &block = pendBlocks[jacob];
		int key = block.back();
		std::vector< std::vector<int> >::iterator pos = std::upper_bound(mainBlocks.begin(), mainBlocks.end(), key, BlockComparatorV());
		mainBlocks.insert(pos, block);
	}

	main.clear();
	for (int i = 0; i < static_cast<int>(mainBlocks.size()); ++i)
	{
		main.insert(main.end(), mainBlocks[i].begin(), mainBlocks[i].end());
	}
	if (!trail.empty())
	{
		main.insert(main.end(), trail.begin(), trail.end());
	}
}

void PmergeMe::binaryInsertDeque(std::deque<int> &main, std::deque<int> &pend, std::deque<int> &trail, int unit)
{
	std::deque<std::deque<int> > mainBlocks;
	std::deque<std::deque<int> > pendBlocks;
	for (int i = 0; i < static_cast<int>(main.size()); i += unit)
	{
		int end = i + unit;
		if (end > static_cast<int>(main.size()))
			end = static_cast<int>(main.size()); // this should not ve necessary and could i + unit all

		std::deque<int> block(main.begin() + i, main.begin() + end);
		mainBlocks.push_back(block);
	}
	for (int i = 0; i < static_cast<int>(pend.size()); i += unit)
	{
		int end = i + unit;
		if (end > static_cast<int>(pend.size()))
			end = static_cast<int>(pend.size()); // this should not ve necessary and could i + unit all

		std::deque<int> block(pend.begin() + i, pend.begin() + end);
		pendBlocks.push_back(block);
	}

	std::vector<int> insertOrder = jacobsthal(static_cast<int>(pendBlocks.size()));
	for (int i = 0; i < static_cast<int>(pendBlocks.size()); ++i)
	{
		int jacob = insertOrder[i];
		if (jacob >= static_cast<int>(pendBlocks.size()))
			continue;

		std::deque<int> &block = pendBlocks[jacob];
		int key = block.back();
		std::deque< std::deque<int> >::iterator pos = std::upper_bound(mainBlocks.begin(), mainBlocks.end(), key, BlockComparatorD());
		mainBlocks.insert(pos, block);
	}

	main.clear();
	for (int i = 0; i < static_cast<int>(mainBlocks.size()); ++i)
	{
		main.insert(main.end(), mainBlocks[i].begin(), mainBlocks[i].end());
	}
	if (!trail.empty())
	{
		main.insert(main.end(), trail.begin(), trail.end());
	}
}


void PmergeMe::binaryPairingVector(int &pair_size)
{
	int	unit = pair_size / 2;
	if (pair_size + unit > static_cast<int>(_vector.size()))
		return ;

	std::vector<int>	main;
	std::vector<int>	pend; 
	std::vector<int> 	trail;
	int i = 0;
	while (i < pair_size)
	{
		main.push_back(_vector[i]);
		i += 1;
	}
	int flag = 0;
	while (i < static_cast<int>(_vector.size()))
	{
		if (i + unit > static_cast<int>(_vector.size()) && unit > 1)
		{
				while (i < static_cast<int>(_vector.size()))
			{
				trail.push_back(_vector[i]);
				i += 1;
			}
			break; 
		}
		else if (flag == 0)
		{
			for (int j = 0; j < unit ; ++j)
			{
				pend.push_back(_vector[i]);
				i += 1;
			}
			flag = 1;
		}
		else
		{
			for (int j = 0; j < unit ; ++j)
			{
				main.push_back(_vector[i]);
				i += 1;
			}
			flag = 0;
		}
	}

	binaryInsertVector(main, pend, trail, unit);
	_vector = main; // maybe a clear before?
}

void PmergeMe::binaryPairingDeque(int &pair_size)
{
	int	unit = pair_size / 2;
	if (pair_size * 2 > static_cast<int>(_deque.size()))
		return ;

	std::deque<int>	main;
	std::deque<int>	pend; 
	std::deque<int>	trail;
	int i = 0;
	while (i < pair_size)
	{
		main.push_back(_deque[i]);
		i += 1;
	}
	int flag = 0;
	while (i < static_cast<int>(_deque.size()))
	{
		if (i + unit > static_cast<int>(_deque.size()) && unit > 1)
		{
			while (i < static_cast<int>(_deque.size()))
			{
				trail.push_back(_deque[i]);
				i += 1;
			}
			break; 
		}
		else if (flag == 0)
		{
			for (int j = 0; j < unit ; ++j)
			{
				pend.push_back(_deque[i]);
				i += 1;
			}
			flag = 1;
		}
		else
		{
			for (int j = 0; j < unit ; ++j)
			{
				main.push_back(_deque[i]);
				i += 1;
		    }
			flag = 0;
		}
	}

	binaryInsertDeque(main, pend, trail, unit);
	_deque = main; // maybe a clear before?
}

void	PmergeMe::swapPairsVector(int &i , int &pair_size)
{
	int step = pair_size / 2;
	int end = i + step;
	int begin = i - (step - 1);
	int times = step;
	int tmp;

	while (times > 0)
	{
		tmp = _vector[begin];
		_vector[begin] = _vector[end - (times - 1)];
		_vector[end - (times - 1)] = tmp;
		begin += 1;
		times -= 1;
	}
}

void	PmergeMe::swapPairsDeque(int &i , int &pair_size)
{
	int step = pair_size / 2;
	int end = i + step;
	int begin = i - (step - 1);
	int times = step;
	int tmp;

	while (times > 0)
	{
		tmp = _deque[begin];
		_deque[begin] = _deque[end - (times - 1)];
		_deque[end - (times - 1)] = tmp;
		begin += 1;
		times -= 1;
	}
}

void	PmergeMe::sortingVector()
{
	_levelVector += 1;
	int	pair_size = static_cast<int>(std::pow(2, _levelVector));
	int	i = pair_size / 2 - 1;

	while ((i < static_cast<int>(_vector.size()) ) && (i + pair_size / 2) < static_cast<int>(_vector.size()))
	{
		if (_vector[i] > _vector[i + pair_size / 2])
		{
			swapPairsVector(i , pair_size);
			i += pair_size;
		}
		else
			i += pair_size;
	}

	if ((_vector.size() / (pair_size * 2)) > 0)
	{
		PmergeMe::sortingVector();
	}
	binaryPairingVector(pair_size);
	_levelVector -= 1;
}

void	PmergeMe::sortingDeque()
{
	_levelDeque += 1;
	int	pair_size = static_cast<int>(std::pow(2, _levelDeque));
	int	i = pair_size / 2 - 1;

	while ((i < static_cast<int>(_deque.size()) ) && (i + pair_size / 2) < static_cast<int>(_deque.size()))
	{
		if (_deque[i] > _deque[i + pair_size / 2])
		{
			swapPairsDeque(i , pair_size);
			i += pair_size;
		}
		else
			i += pair_size;
	}
	
	if ((_deque.size() / (pair_size * 2)) > 0)
	{
		PmergeMe::sortingDeque();
	}
	binaryPairingDeque(pair_size);
	_levelDeque -= 1;
}

void PmergeMe::startVector(int argc, char **argv)
{
	clock_t start = clock();
	for (int i = 1; i < argc; ++i)
	{
		std::string token(argv[i]);
		int value;
		std::istringstream iss(token);
		iss >> value;
		if (iss.fail() || !iss.eof())
    		throw std::runtime_error("Error: invalid input -> " + token);
		
		if (value <= 0)
			throw std::runtime_error("Error: non-positive integer -> " + token);
		_vector.push_back(value);
	}
	_levelVector = 0;
	sortingVector();
	clock_t end = clock();
	_vectorTime = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;
}

void PmergeMe::startDeque(int argc, char **argv)
{
	clock_t start = clock();
	for (int i = 1; i < argc; ++i)
	{
		std::string token(argv[i]);
		int value;
		std::istringstream iss(token);
		iss >> value;
		if (iss.fail() || !iss.eof())
    		throw std::runtime_error("Error: invalid input -> " + token);
		
		if (value <= 0)
			throw std::runtime_error("Error: non-positive integer -> " + token);
		_deque.push_back(value);
	}
	_levelDeque = 0;
	sortingDeque();
	clock_t end = clock();
	_dequeTime = static_cast<double>((end - start) * 1e6 / CLOCKS_PER_SEC );
}

void PmergeMe::printContainers(char **argv) const
{
	argv += 1;
	std::cout << "Before ";
	while (*argv != NULL) {
		std::cout << " " << *argv;
		argv++;
	}
	std::cout << std::endl;
	std::cout << "After ";
	   for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}