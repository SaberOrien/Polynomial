#pragma once
#include <iostream>
#include <map>
#include <cmath>
class Poly {
    public:
        Poly();
        Poly(float coefficient);
        Poly(const Poly& p2);
        float &operator[](int );
        float operator()(float atPoint) const;
        Poly operator-() const;
        friend Poly operator+(const Poly& p1, const Poly& p2);
        friend Poly operator-(const Poly& p1, const Poly& p2);
        friend Poly operator*(const Poly& p1, const Poly& p2);
        friend std::ostream& operator << (std::ostream& s, const Poly& polynomial);
    private:
        std::map<int, float>coefficients;
        std::map<int, float>::const_iterator constIterEnd;
        friend bool isZero(const Poly& p);
};