#include "Poly.h"
#include <iostream>
#include <cmath>

using namespace std;

Poly::Poly(){
    coefficients = map<int, float>();
    constIterEnd = coefficients.end();
}

Poly::Poly(float coefficient){
    coefficients = map<int, float>();
    constIterEnd = coefficients.end();
    coefficients[0] = coefficient;
}

float& Poly::operator[](int value){
    return coefficients[value];
}

float Poly::operator()(float atPoint) const{
    float result = 0;
    map<int, float>::const_iterator it = coefficients.begin();
    while(it != constIterEnd){
        result += (it->second * pow(atPoint, it->first));
        ++it;
    }
    return result;
}

Poly Poly::operator-() const{
    Poly negated_polynomial;
    map<int, float>::const_iterator it = coefficients.begin();
    while(it != constIterEnd){
        negated_polynomial[it->first] = -it->second;
        ++it;
    }
    return negated_polynomial;
}

Poly operator+(const Poly& p1, const Poly& p2){
    Poly result;
    map<int, float>::const_iterator it_p1 = p1.coefficients.begin();
    map<int, float>::const_iterator it_p2 = p2.coefficients.begin();

    while(it_p1 != p1.constIterEnd && it_p2 != p2.constIterEnd){
        if(it_p1->first == it_p2->first){
            result[it_p1->first] = it_p1->second + it_p2->second;
            ++it_p1;
            ++it_p2;
        }
        else if(it_p1->first > it_p2->first){
            result[it_p1->first] = it_p1->second;
            ++it_p1;
        }
        else if(it_p1->first < it_p2->second){
            result[it_p2->first] = it_p2->second;
            ++it_p2;
        }
    }
    while(it_p1 != p1.constIterEnd){
        result[it_p1->first] = it_p1->second;
        ++it_p1;
    }
    while(it_p2 != p2.constIterEnd){
        result[it_p2->first] = it_p2->second;
        ++it_p2;
    }
    return result;
}

Poly operator-(const Poly& p1, const Poly& p2){
    Poly result;
    map<int, float>::const_iterator it_p1 = p1.coefficients.begin();
    map<int, float>::const_iterator it_p2 = p2.coefficients.begin();
    while(it_p1 != p1.constIterEnd && it_p2 != p2.constIterEnd){
        if(it_p1->first == it_p2->first){
            result[it_p1->first] = it_p1->second - it_p2->second;
            ++it_p1;
            ++it_p2;
        }
        else if(it_p1->first > it_p2->first){
            result[it_p1->first] = it_p1->second;
            ++it_p1;
        }
        else if(it_p1->first < it_p2->second){
            result[it_p2->first] = it_p2->second;
            ++it_p2;
        }
    }
    while(it_p1 != p1.constIterEnd){
        result[it_p1->first] = it_p1->second;
        ++it_p1;
    }
    while(it_p2 != p2.constIterEnd){
        result[it_p2->first] = -it_p2->second;
        ++it_p2;
    }
    return result;
}

Poly operator*(const Poly& p1, const Poly& p2){
    Poly result;
    map<int, float>::const_iterator it_p1 = p1.coefficients.begin();
    map<int, float>::const_iterator it_p2 = p2.coefficients.begin();
    int exponent;
    float coefficient;
    while(it_p1 != p1.constIterEnd){
        it_p2 = p2.coefficients.begin();
        while(it_p2 != p2.constIterEnd){
            coefficient = it_p1->second * it_p2->second;
            exponent = it_p1->first + it_p2->first;
            result[exponent] += coefficient;
            ++it_p2;
        }
        ++it_p1;
    }
    return result;
}

ostream& operator<<(ostream& o, const Poly& p){
    map<int, float>::const_reverse_iterator it = p.coefficients.rbegin();
    map<int, float>::const_reverse_iterator fin = p.coefficients.rend();
    unsigned int size = 0;
    unsigned int coef_zero = 0;
    int count = 0;
    
    for(size = 0; size < p.coefficients.size(); size++){
        if(it->second == 0){
            coef_zero++;
        }
    }
    if(coef_zero == size){
        return o << 0;
    }

    while(it!=fin){
        if((it->second > 0) && (count > 0)){
            o << "+";
        }
        if(it->second == 1){
            o << "x^(" << it->first << ") ";
        }
        else if(it->second == -1){
            o << "-x^(" << it->first << ") ";
        }
        else if(it->first == 0){
            o << it->second;
        }
        else{
            o << it->second << "x^(" << it->first << ") ";
        }
        ++it;
        count++;
    }

    o << "";
    return o;
}