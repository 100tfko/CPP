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

#include "RPN.hpp"

int main(int argc, char **argv)
{
	//i dont know what kind of parse whould I do?
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }


    RPN calculator;
    calculator.Calculator(argv[1]);
}