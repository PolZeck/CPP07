/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:47:18 by pledieu           #+#    #+#             */
/*   Updated: 2026/01/19 09:47:19 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

/**
 * @brief A non-template function to increment an integer.
 * Used to test iter with standard functions.
 */
void increment(int & n) {
    n++;
}

int main() {
    // Test 1: Integer Array
    int intArray[] = {0, 1, 2, 3, 4};
    std::cout << "Original int array: ";
    ::iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    // Modifying the array using iter and the increment function
    ::iter(intArray, 5, increment);
    std::cout << "After incrementing: ";
    ::iter(intArray, 5, printElement<int>);
    std::cout << "\n" << std::endl;

    // Test 2: String Array
    std::string strArray[] = {"C++", "Templates", "are", "powerful"};
    std::cout << "String array: ";
    ::iter(strArray, 4, printElement<std::string>);
    std::cout << "\n" << std::endl;

    // Test 3: Const Array (verifying const-correctness) 
    const int constArray[] = {42, 21, 84};
    std::cout << "Constant int array: ";
    // Note: We pass the template function explicitly for const elements
    ::iter(constArray, 3, printElement<const int>);
    std::cout << std::endl;

    return 0;
}