/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:02 by rozhou            #+#    #+#             */
/*   Updated: 2022/04/12 16:18:02 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    srand(time(0));
    switch (rand() % 3)
    {
        case 0:
            // std::cout << "A" << std::endl;
            return (new A());
        case 1:
            // std::cout << "B" << std::endl;
            return (new B());
        case 2:
            // std::cout << "C" << std::endl;
            return (new C());
    }
    return (0);
}

void identify(Base *p)
{
    Base* ptr;
    if (dynamic_cast<A *>(p))
        std::cout << "Pointed Object is a class A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Pointed Object is a class B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Pointed Object is a class C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        Base &base = dynamic_cast<A &>(p);
        std::cout << "Pointed Object is a class A" << std::endl;
    }
    catch(std::bad_cast e)
    {
        try
        {
            Base &base = dynamic_cast<B &>(p);
            std::cout << "Pointed Object is a class B" << std::endl;
        }
        catch (std::bad_cast e)
        {
            std::cout << "Pointed Object is a class C" << std::endl;
        }
    }
}

int main(void)
{
    A a;
    B b;
    C c;
    Base* Base1;

    Base &baseRef = a;
    Base &baseRef1 = b;
    Base &baseRef2 = c;
    identify(baseRef);
    identify(baseRef1);
    identify(baseRef2);
    Base1 = generate();
    identify(Base1);

    return (0);
}