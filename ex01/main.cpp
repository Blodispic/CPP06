/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:15:15 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/12 15:15:15 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "conv.hpp"

uintptr_t serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data* ptr = new Data;
    Data* ptr2;
    uintptr_t raw;

    ptr->f = 50.0;
    ptr->i = 40;
    std::cout << "Adress: " << ptr << std::endl
              << "Value of f: " << ptr->f << std::endl
              << "Value of i: " << ptr->i << std::endl;
    raw = serialize(ptr);
    std::cout << "Adress of raw: " << raw << std::endl;
    ptr2 = deserialize(raw);
    std::cout << "Adress: " << ptr2 << std::endl
              << "Value of f: " << ptr2->f << std::endl
              << "Value of i: " << ptr2->i << std::endl;
    delete ptr;
    return (0);
}