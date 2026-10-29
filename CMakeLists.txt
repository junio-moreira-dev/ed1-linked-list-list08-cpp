cmake_minimum_required(VERSION 4.2)
project(ed1_linked_list_list08_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(ed1_linked_list_list08_cpp main.cpp
#        src/Exer01_MiddleNode.cpp
#        src/Exer02_PalindromeList.cpp
#        src/Exer03_RemoveDuplicates.cpp
#        src/Exer04_OddEvenList.cpp
#        src/Exer05_AddTwoNumbers.cpp
#        src/Exer05_AddTwoNumbers.h)

# Executáveis individuais para cada exercício da Lista 08
add_executable(Exer01_MiddleNode src/Exer01_MiddleNode.cpp
        include/LinkedList.h)
add_executable(Exer02_PalindromeList src/Exer02_PalindromeList.cpp)
add_executable(Exer03_RemoveDuplicates src/Exer03_RemoveDuplicates.cpp)
add_executable(Exer04_OddEvenList src/Exer04_OddEvenList.cpp)
add_executable(Exer05_AddTwoNumbers src/Exer05_AddTwoNumbers.cpp)

# Se ainda mantiver um main.cpp na raiz, declare-o aqui:
add_executable(main_app main.cpp)