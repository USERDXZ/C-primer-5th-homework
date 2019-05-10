#ifndef FIGURE_H
#define FIGURE_H
class Figure{
public:
    Figure(double x, double y):xSize(x), ySize(y) {}
    virtual ~Figure() {}
protected:
    double xSize = 0.0, ySize = 0.0;
};

class Figure_2D:public Figure{
public:
    Figure_2D(double x, double y):Figure(x, y) {}
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
};

class Figure_3D:public Figure{
public:
    Figure_3D(double x, double y, double z):Figure(x, y), zSize(z) {}
    virtual double superficial_area() const = 0;
    virtual double volume() const = 0;
protected:
    double zSize = 0.0;
};

class Rectangle:public Figure_2D{
public:
    Rectangle(double x, double y):Figure_2D(x, y) {}
    double perimeter() const override {return 2 * (xSize + ySize);}
    double area() const override {return xSize * ySize;}
};

class Circle:public Figure_2D{
public:
    Circle(double radius):Figure_2D(radius, 0.0) {} // 半径
    double perimeter() const override {return 2 * 3.14 * xSize;}
    double area() const override {return 3.14 * xSize * xSize;}
};

class Cuboid:public Figure_3D{
public:
    Cuboid(double x, double y, double z):Figure_3D(x, y, z){}
    double superficial_area() const override {return 2 * (xSize * ySize + ySize * zSize + zSize * xSize);}
    double volume() const override {return xSize * ySize * zSize;}
};

class Globe:public Figure_3D{
public:
    Globe(double radius):Figure_3D(radius, 0.0, 0.0) {}
    double superficial_area() const override {return 4 * 3.14 * xSize * xSize;}
    double volume() const override {return 4/3 * 3.14 * xSize * xSize * xSize;}
};
#endif