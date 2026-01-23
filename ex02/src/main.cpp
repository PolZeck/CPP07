/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:53:38 by pledieu           #+#    #+#             */
/*   Updated: 2026/01/23 10:26:18 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

#include <iostream>

// void testTableauClassique() {
//     int tab[5] = {1, 2, 3, 4, 5};

//     std::cout << "--- Tableau Classique (Dangereux) ---" << std::endl;
//     // On accède à l'index 10 alors que le tableau s'arrête à 4
//     std::cout << "Valeur à tab[10] : " << tab[110] << std::endl; 
// }

int main() {

    // testTableauClassique();




    // Test 1: Empty array
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    // Test 2: Array of 5 integers
    Array<int> numbers(5);
    std::cout << "Array size: " << numbers.size() << std::endl;

    // Filling the array
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 2;

    // Test 3: Deep copy verification
    Array<int> copy(numbers);
    copy[0] = 42; // Change copy, original shouldn't change
    std::cout << "Original[0]: " << numbers[0] << " (should be 0)" << std::endl;
    std::cout << "Copy[0]: " << copy[0] << " (should be 42)" << std::endl;

    // Test 4: Exception handling
    try {
        std::cout << "Accessing index 10: " << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 5: String array
    Array<std::string> strings(2);
    strings[0] = "Hello";
    strings[1] = "World";
    std::cout << strings[0] << " " << strings[1] << std::endl;

    return 0;
}