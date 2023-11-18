#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Complex {
    T real;
    T imaginary;
    
    public:
        Complex(T r, T i): real(r), imaginary(i) {}
        
        Complex<T> operator+(const Complex<T>& other) const {
            return Complex<T>(real + other.real, imaginary + other.imaginary);
        }
        
        Complex<T> operator-(const Complex<T>& other) const {
            return Complex<T>(real - other.real, imaginary - other.imaginary);
        }
        
        Complex<T> operator/(const Complex<T>& other) const {
            T d = other.real * other.real + other.imaginary * other.imaginary;
            T r = (real * other.real + imaginary * other.imaginary) / d;
            T i = (imaginary * other.real - real * other.imaginary) / d;
            return Complex<T>(r, i);
        }
        
        Complex<T> operator*(const Complex<T>& other) const {
            T r = real * other.real - imaginary * other.imaginary;
            T i = real * other.imaginary + imaginary * other.real;
            return Complex<T>(r, i);
        }
        
        double module() const {
            return std::hypot(real, imaginary);
        }
        
        Complex<T> power(int exponent) const {
            double mod = std::pow(module(), exponent);
            double arg = std::atan2(imaginary, real);
            T r = mod * std::cos(exponent * arg);
            T i = mod * std::sin(exponent * arg);
            
            return Complex<T>(r, i);
        }
        
        Complex<T> sqrt(int exponent) const {
            double mod = std::sqrt(module());
            double arg = std::atan2(imaginary, real);
            T r = mod * std::cos(arg / 2);
            T i = mod * std::sin(arg / 2);
            
            return Complex<T>(r, i);
        }
        
        void display() {
            cout << "Complex<" << real << ", " << imaginary << ">" << std::endl;
        }
    };

int main()
{
    Complex<double> z1(2.0, 3.0);
    Complex<double> z2(1.0, -1.0);
    
    Complex<double> power = z1.power(3);
    
    z1.display();
    z2.display();
    power.display();

    return 0;
}
