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

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv){
	if (argc != 2){
		std::cerr << "Error: Bad arguments." << std::endl;
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return (1);
	}
	
	BitcoinExchange	btc(argv[1]);
	if (btc.getLoadFlag())
		btc.loadInput(argv[1]);
}
