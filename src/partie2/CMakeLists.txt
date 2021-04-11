cmake_minimum_required(VERSION 3.15)
project(essaiTrieNode)

set(CMAKE_CXX_STANDARD 14)

add_executable(essaiTrieNode main.cpp automate.cpp automate.hpp node.cpp node.hpp trie.cpp trie.hpp items.cpp items.hpp)