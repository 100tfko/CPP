/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:22:59 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 12:23:05 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main() {

	srand(time(NULL));
	
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    Span bigSpan(10000);
    std::vector<int> manyNumbers;
    for (int i = 0; i < 10000; ++i)
        manyNumbers.push_back(rand());

    bigSpan.addNumber(manyNumbers.begin(), manyNumbers.end());

    std::cout << "shortest span (massive): " << bigSpan.shortestSpan() << std::endl;
    std::cout << "longest span (massive): " << bigSpan.longestSpan() << std::endl;

    return 0;
}