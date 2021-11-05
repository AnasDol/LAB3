#pragma once
#include "square_matrix.h"

#define rows order

class rectangular_matrix :
    public square_matrix
{

public:

    rectangular_matrix(int rows, int cols);
    rectangular_matrix(int rows, int cols, int** data);

    virtual char* to_string();
    void fill_rand(int a = -100, int b = 100);

    rectangular_matrix transpose();
    rectangular_matrix multiple_num(int num);

    int get_rows() { return rows; }
    int get_columns() { return cols; }

    ~rectangular_matrix();

private:

    int cols;


};

