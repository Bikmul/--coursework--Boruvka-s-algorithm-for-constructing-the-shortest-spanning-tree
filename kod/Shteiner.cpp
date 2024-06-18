#include "Shteiner.hpp"

Shteiner::Shteiner(int v, std::map<int, int> arr)
{
    this->v = v;
    this->arr_graph = arr;
    this->matrix = init_matrix();
    this->flag = init_flag_matrix();
    this->sum = 0;
}

Shteiner::~Shteiner() 
{
    delete[] matrix;
    delete[] flag;
    this->arr_graph.clear();
}

int **Shteiner::init_matrix()
{
    int m = this->v;
    int **matrix = new int *[m];

    for(int i = 0;i < m;i++)
        matrix[i] = new int [m];

    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < m;j++)
            matrix[i][j] = 0;
    }
    return(matrix);
}

int **Shteiner::init_flag_matrix()
{
    int f = this->v;
    int **flag = new int *[f];

    for(int i = 0;i < f;i++)
        flag[i] = new int [f];

    for(int i = 0;i < f;i++)
    {
        for(int j = 0;j < f;j++)
        {
            if(i == j)
                flag[i][j] = 1;
            else
                flag[i][j] = 0;
        }
    }
    return(flag);
}

void Shteiner::printer()
{
    std::cout << "Количество вершин графа = " << this->v << std::endl;
    for(int i=0;i< this->v;i++)
    {
        std::cout <<"Вершина №" << i << std::endl;
        std::cout <<"=============================================="<< std::endl;
        std::cout <<"Координата по X: " << this->arr_graph[i]/10 << std::endl;
        std::cout <<"Координата по Y: " << this->arr_graph[i]%10 << std::endl;
        std::cout <<"=============================================="<< std::endl;
    }
    std::cout << "Матрица смежности графа до начала вычислений: " << std::endl;
    std::cout <<"=============================================="<< std::endl;
    for(int i = 0; i < this->v; i++)
    {
        for(int j = 0;j < this->v; j++)
            std::cout << matrix[i][j];
        std::cout << std::endl;
    }
    std::cout <<"=============================================="<< std::endl;
    std::cout << "Матрица флагов вершин до начала вычислений: " << std::endl;
    std::cout <<"=============================================="<< std::endl;
    for(int i = 0; i < this->v; i++)
    {
        for(int j = 0;j < this->v; j++)
            std::cout << flag[i][j];
        std::cout << std::endl;
    }
    std::cout <<"=============================================="<< std::endl;
}

void Shteiner::dop_print()
{
    std::cout << "Матрица смежности графа после вычислений: " << std::endl;
    std::cout <<"=============================================="<< std::endl;
    for(int i = 0; i < this->v; i++)
    {
        for(int j = 0;j < this->v; j++)
            std::cout << matrix[i][j];
        std::cout << std::endl;
    }
    std::cout <<"=============================================="<< std::endl;
    // std::cout << "Матрица флагов вершин после вычислений: " << std::endl;
    // std::cout <<"=============================================="<< std::endl;
    // for(int i = 0; i < this->v; i++)
    // {
    //     for(int j = 0;j < this->v; j++)
    //         std::cout << flag[i][j];
    //     std::cout << std::endl;
    // }
    // std::cout <<"=============================================="<< std::endl;
    std::cout << "Вес покрывающего дерева: " << this->sum << std::endl;
}

void Shteiner::algoritm()
{
    int v = 0;

    while(v < (this->v-1))
    {
        int x = 0;
        int y = 0;
        int min = 9999;
        float d = 0;
        for(int i = 0; i < this->v; i++)
        {
            for(int j = 0; j < this->v;j++)
            {
                if(this->flag[i][j] != 1)
                {
                    if(min > (abs((this->arr_graph[i]/10)-(this->arr_graph[j]/10)) + abs((this->arr_graph[i]%10)-(this->arr_graph[j]%10))))
                    {
                        min = abs((this->arr_graph[i]/10)-(this->arr_graph[j]/10)) + abs((this->arr_graph[i]%10)-(this->arr_graph[j]%10));
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (min < 1000)
        {
            this->matrix[x][y] = this->matrix[y][x] = min;
            this->flag[x][y] = this->flag[y][x] = 1;
            d = sqrt(pow((abs((this->arr_graph[x]/10)-(this->arr_graph[y]/10))),2) + pow((abs((this->arr_graph[x]%10)-(this->arr_graph[y]%10))),2));
            this->sum = this->sum + d;
            v++;
        }   
    }
}

int **Shteiner::getFlag() const
{
    return(this->flag);
}

int Shteiner::get_v() const
{
    return(this->v);
}