#include <iostream>



class AreaCalculator {

public:

    virtual double calculateArea() = 0;

};



class RectangleAreaCalculator : public AreaCalculator {

private:

    double width;

    double height;



public:

    RectangleAreaCalculator(double w, double h) : width(w), height(h) {}



    double calculateArea() override {

        return width * height;

    }

};



class TriangleAreaCalculator : public AreaCalculator {

private:

    double base;

    double height;



public:

    TriangleAreaCalculator(double b, double h) : base(b), height(h) {}



    double calculateArea() override {

        return 0.5 * base * height;

    }

};



class CircleAreaCalculator : public AreaCalculator {

private:

    double radius;



public:

    CircleAreaCalculator(double r) : radius(r) {}



    double calculateArea() override {

        return 3.14159 * radius * radius;

    }

};

class RhombusAreaCalculator : public AreaCalculator {
private:
    int diagonal1;
    int diagonal2;

public:
    RhombusAreaCalculator(int d1, int d2) : diagonal1(d1), diagonal2(d2) {}

    double calculateArea() override {
        return (diagonal1 * diagonal2) / 2.0;
    }
};



class Shape {

private:

    AreaCalculator* areaCalculator;



public:

    Shape(AreaCalculator* calculator) : areaCalculator(calculator) {}



    double calculateArea() {

        return areaCalculator->calculateArea();

    }

};




int main() {

    RectangleAreaCalculator rectangleCalculator(4, 5);

    TriangleAreaCalculator triangleCalculator(3, 6);

    CircleAreaCalculator circleCalculator(2);

    RhombusAreaCalculator rhombusCalculator(3, 2);



    Shape rectangle(&rectangleCalculator);

    Shape triangle(&triangleCalculator);

    Shape circle(&circleCalculator);

    Shape rhombus(&rhombusCalculator);



    std::cout << "Rectangle Area: " << rectangle.calculateArea() << std::endl;

    std::cout << "Triangle Area: " << triangle.calculateArea() << std::endl;

    std::cout << "Circle Area: " << circle.calculateArea() << std::endl;

    std::cout << "Rhombus Area: " << rhombus.calculateArea() << std::endl;

    return 0;

}