cmake_minimum_required(VERSION 3.30)
project(Demolol)

set(CMAKE_CXX_STANDARD 20)

add_executable(Demolol main.cpp
        Class/Address.cpp
        Class/Address.h
        Class/Customer.cpp
        Class/Customer.h
        Class/Order.cpp
        Class/Order.h
        Class/Product.cpp
        Class/Product.h
        Class/ShoppingCart.cpp
        Class/ShoppingCart.h
        Class/ShoppingItem.cpp
        Class/ShoppingItem.h
        Functions.cpp)
