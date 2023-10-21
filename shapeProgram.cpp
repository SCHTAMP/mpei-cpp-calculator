#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GeometricObject {
    public:
        virtual double GetArea() const = 0;
        virtual void DisplayInfo() const = 0;
        virtual void DisplayShortInfo() const = 0;
        
        bool operator<(const GeometricObject &other) const {
            return GetArea() < other.GetArea();
        }
        
        bool operator<=(const GeometricObject &other) const {
            return GetArea() <= other.GetArea();
        }
        
        bool operator>(const GeometricObject &other) const {
            return GetArea() > other.GetArea();
        }
        
        bool operator>=(const GeometricObject &other) const {
            return GetArea() >= other.GetArea();
        }
        
        bool operator==(const GeometricObject &other) const {
            return GetArea() == other.GetArea();
        }
        
        bool operator!=(const GeometricObject &other) const {
            return GetArea() != other.GetArea();
        }
};

class Point : public GeometricObject {
    public:
        Point(double x, double y) : x_(x), y_(y) {}
        
        double GetArea() const override {
            return 0.0;
        }
        
        void DisplayInfo() const override {
            std::cout << "Point: (" << x_ << ", " << y_ << ")" << std::endl;
        }
        
        void DisplayShortInfo() const override {
            std::cout << "Point(" << x_ << "," << y_ << ")";
        }
        
    private:
        double x_;
        double y_;
};

class EqTriangle : public GeometricObject {
    public:
        EqTriangle(double side) : side_(side) {}
        
        double GetArea() const override {
            return (sqrt(3) / 4) * side_ * side_;
        }
        
        void DisplayInfo() const override {
            std::cout << "EqTriangle: Side = " << side_ << ", Area = " << GetArea() << std::endl;
        }
        
        void DisplayShortInfo() const override {
            std::cout << "EqTriangle(Side=" << side_ << ",Area=" << GetArea() << ")";
        }
        
    private:
        double side_;
};

class Square : public GeometricObject {
    public:
        Square(double side) : side_(side) {}
        
        double GetArea() const override {
            return side_ * side_;
        }
        
        void DisplayInfo() const override {
            std::cout << "Square: Side = " << side_ << ", Area = " << GetArea() << std::endl;
        }
        
        void DisplayShortInfo() const override {
            std::cout << "Square(Side=" << side_ << ",Area=" << GetArea() << ")";
        }
        
    private:
        double side_;
};

class Cube : public GeometricObject {
    public:
        Cube(double side) : side_(side) {}
        
        double GetArea() const override {
            return 6 * side_ * side_;
        }
        
        void DisplayShortInfo() const override {
            std::cout << "Square(Side=" << side_ << ",Area=" << GetArea() << ")";
        }
        
        void DisplayInfo() const override {
            std::cout << "Square: Side = " << side_ << ", Area = " << GetArea() << std::endl;
        }
        
    private:
        double side_;
};

int main()
{
    
    Cube shape(6.0);
    Cube shape2(8.0);
    
    shape.DisplayInfo();
    shape2.DisplayInfo();
    
    std::cout << "Operator ==: " << (shape == shape2) << std::endl;
    std::cout << "Operator !=: " << (shape != shape2) << std::endl;

    std::cout << "Operator >: " << (shape > shape2) << std::endl;
    std::cout << "Operator >=: " << (shape >= shape2) << std::endl;
    
    std::cout << "Operator <: " << (shape < shape2) << std::endl;
    std::cout << "Operator <=: " << (shape <= shape2) << std::endl;


    return 0;
}
