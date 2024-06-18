#pragma once
#include <iostream>
#include <map>
#include "Filereader.hpp"
#include <cmath>

class Shteiner
{
private:
    std::map<int, int> arr_graph;
    int v;
    int **matrix;
    int **flag;
    float sum;
public:
    Shteiner(int v, std::map<int, int> arr);
    ~Shteiner();

    int **init_matrix();
    int **init_flag_matrix();
    void printer();
    void dop_print();
    void algoritm();
    int **getFlag() const;
    int get_v() const;
};