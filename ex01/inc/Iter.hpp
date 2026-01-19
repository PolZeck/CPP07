/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:43:39 by pledieu           #+#    #+#             */
/*   Updated: 2026/01/19 09:47:08 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/**
 * @brief Iterates through an array and applies a function to each element.
 * * @param array Pointer to the first element of the array[cite: 190].
 * @param length The number of elements in the array (passed as const)[cite: 191].
 * @param func The function (or function template) to be called on each element[cite: 192, 194].
 */
template <typename T, typename F>
void iter(T *array, size_t length, F func) {
    if (!array || !func)
        return;

    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

/**
 * @brief A simple template function to print an element.
 * Useful for testing iter with different data types.
 */
template <typename T>
void printElement(T const & element) {
    std::cout << element << " ";
}

#endif