/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:26:46 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/08/11 12:26:48 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <cctype>
#include <exception>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		int					_levelVector;
		int					_levelDeque;
		double				_vectorTime;
		double				_dequeTime;
    	struct	BlockComparatorV;
	    struct	BlockComparatorD;

	public:

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void 	printContainers(char **argv) const;
		std::vector<int>	jacobsthal(int size);

		//------ Vector functions ------
		void 	startVector(int argc, char **argv);
		void	sortingVector();
		void	swapPairsVector(int &i , int &pair_size);
		void	binaryPairingVector(int &pair_size);
		void	binaryInsertVector(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &trail, int unit);
		

		//------ Vector functions ------
		void 	startDeque(int argc, char **argv);
		void	sortingDeque();
		void	swapPairsDeque(int &i , int &pair_size);
		void	binaryPairingDeque(int &pair_size);
		void	binaryInsertDeque(std::deque<int> &main, std::deque<int> &pend, std::deque<int> &trail, int unit);
		
};


#endif
