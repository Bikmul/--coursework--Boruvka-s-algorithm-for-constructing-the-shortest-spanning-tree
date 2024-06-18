#pragma once 

#include "Shteiner.hpp"
#include "fstream"

class Fillfile
{
public:
    Fillfile(int **arr, int v);
    ~Fillfile();

    int **init(int **arr, int v);
    void fillfile(int **arr, int v);
};
