#pragma once
#include <iostream>
#include <map>

class Poly {
    public:
        Poly();
        Poly(float coefficient);
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
};