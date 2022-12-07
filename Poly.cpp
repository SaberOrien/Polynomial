#include "Poly.h"
using namespace std;

Poly::Poly(){
}

Poly::Poly(float coefficient){
    coefficients[0] = coefficient;
}

Poly::Poly(const Poly& p2){
    coefficients = map<int, float>(p2.coefficients);
}

float& Poly::operator[](int value){
    return coefficients[value];
}

float Poly::operator()(float atPoint) const{
    float result = 0;
    auto it = coefficients.begin();
    auto itEnd = coefficients.end();
    while(it != itEnd){
        result += (it->second * pow(atPoint, it->first));
        ++it;
    }
    return result;
}

Poly Poly::operator-() const{
    Poly negated_polynomial;
    auto it = coefficients.begin();
    auto itEnd = coefficients.end();
    while(it != itEnd){
        negated_polynomial[it->first] = -it->second;
        ++it;
    }
    return negated_polynomial;
}

Poly operator+(const Poly& p1, const Poly& p2){
    Poly result(p1);
    auto iterator = p2.coefficients.begin();
    auto itEnd2 =  p2.coefficients.end();
    for(iterator = p2.coefficients.begin(); iterator != itEnd2; iterator++){
        result.coefficients[iterator->first] += iterator->second;
    }

    return result;
}

Poly operator-(const Poly& p1, const Poly& p2){
    Poly result(p1);
    auto iterator = p2.coefficients.begin();
    auto itEnd2 =  p2.coefficients.end();
    for(iterator = p2.coefficients.begin(); iterator != itEnd2; iterator++){
        result.coefficients[iterator->first] -= iterator->second;
    }

    return result;
}

Poly operator*(const Poly& p1, const Poly& p2){
    Poly result;
    auto it_p1 = p1.coefficients.begin();
    auto it_p2 = p2.coefficients.begin();
    auto it_end_p1 = p1.coefficients.end();
    auto it_end_p2 = p2.coefficients.end();
    int exponent;
    float coefficient;
    while(it_p1 != it_end_p1){
        it_p2 = p2.coefficients.begin();
        while(it_p2 != it_end_p2){
            coefficient = it_p1->second * it_p2->second;
            exponent = it_p1->first + it_p2->first;
            result[exponent] += coefficient;
            ++it_p2;
        }
        ++it_p1;
    }
    return result;
}

bool Poly::isZero() const{
    auto iterator = coefficients.begin();
    for(unsigned int size = 0; size < coefficients.size(); size++){
        if(iterator->second != 0){
            return false;
        }
    }

    return true;
}

ostream& operator<<(ostream& o, const Poly& p){
    if(p.isZero() == 1){
        return o << 0;
    }
    auto it = p.coefficients.rbegin();
    auto fin = p.coefficients.rend();
    int count = 0;
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
        else if(it->first == 1){
            o << it->second << "x ";
        }
        else{
            o << it->second << "x^(" << it->first << ") ";
        }
        ++it;
        count++;
    }
    return o;
}