cmake_minimum_required(VERSION 3.16)
project(CS236_project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS236_project1
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h)
