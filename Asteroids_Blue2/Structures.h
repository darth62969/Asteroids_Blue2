#pragma once

#include<memory>
#include<vector>



struct point
{
    double x, y, z;
};
struct color
{
    uint16_t r, g, b;
};
struct vector_shape
{
    double v;
    point r;
    point l;
};
struct triangle
{
    point a, b, c;
};
struct layer
{
    std::vector<point> points;
    std::vector<triangle> triangles;
    color clr;
};

