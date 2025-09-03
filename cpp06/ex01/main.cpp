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

#include "Serializer.hpp"

int main (void)
{
	Data	*data = new Data;
	data->str = "sample test";

	std::cout << "Before:\n" << "Address = " << data << std::endl
	<< "data str = " << data->str << "\n" << std::endl;  

	uintptr_t	serializedData = Serializer::serialize(data);
	Data *		deserializedData = Serializer::deserialize(serializedData);
	
	std::cout << "After:\n" << "Address = " << data << std::endl
	<< "data str = " << data->str << std::endl
	<< "serialized = " << serializedData << std::endl
	<< "deserialized Address = " << deserializedData << std::endl
	<< "deserialized str = " << deserializedData->str << std::endl;

	delete	data;
	return 0;
}
