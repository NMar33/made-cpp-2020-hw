#pragma once
#include <vector>
#include <iostream>

using std::vector;

namespace task {

// Your code here...
vector<double> operator+ (
    const vector<double>& a,
    const vector<double>& b
){
    vector<double> c;

    for(int i = 0; i < a.size(); ++ i) {
        c.push_back(a[i] + b[i]);
    }

    return c;
    
}

vector<double> operator- (
    const vector<double>& a,
    const vector<double>& b
){
    vector<double> c;

    for(int i = 0; i < a.size(); ++ i) {
        c.push_back(a[i] - b[i]);
    }

    return c;
    
}

vector<double> operator+ (
    const vector<double>& a
){
    vector<double> c;

    for(int i = 0; i < a.size(); ++ i) {
        c.push_back(a[i] );
    }

    return c;
    
}

vector<double> operator- (
    const vector<double>& a
){
    vector<double> c;

    for(int i = 0; i < a.size(); ++ i) {
        c.push_back(a[i] * (-1));
    }

    return c;
    
}

double operator* (
    const vector<double>& a,
    const vector<double>& b
){
    double c;

    for(int i = 0; i < a.size(); ++ i) {
        c += a[i] * b[i];
    }

    return c;
    
}

vector<double> operator% (
    const vector<double>& a,
    const vector<double>& b
){
    vector<double> c;

    c.push_back(a[1] * b[2] - a[2] * b[1]);
    c.push_back(a[2] * b[0] - a[0] * b[2]);
    c.push_back(a[0] * b[1] - a[1] * b[0]);

    return c;
    
}

bool check_zero (
    const vector<double>& b
){
    for(int i = 0; i < b.size(); ++ i) {
        if (b[i] != 0) {
            return false;
        }
    }
    return true;
}

double find_k (
    const vector<double>& a,
    const vector<double>& b
){
    double k;

    for(int i = 0; i < b.size(); ++ i) {
        if (b[i] != 0) {
            k = a[i] / b[i];
            break;
        }
    }

    return k;
}

bool operator|| (
    const vector<double>& a,
    const vector<double>& b
){
    double k;

    if (check_zero(b)) {
        return true;
    }

    k = find_k(a, b);

    for(int i = 0; i < a.size(); ++ i) {
        if ((fabs(a[i] - b[i] * k ) > 1e-7))  {
            return false;
        }   

    }

    return true;
}

bool operator&& (
    const vector<double>& a,
    const vector<double>& b
){
    double k;

    if (check_zero(b)) {
        return true;
    }

    if (!(a || b)) {
        return false;
    }

    k = find_k(a, b);

    if (k < 0) {
        return false;
    }

    return true;
}

void reverse (vector<double>& a){
    vector<double> c; 
    for(int i = a.size() - 1; i >= 0; -- i) {
        c.push_back(a[i]);
    }
    a = c;
    return;
}

vector<int> operator| (
    const vector<int>& a,
    const vector<int>& b
){
    vector<int> c;

    for(int i = 0; i < a.size(); ++ i) {
        c.push_back(a[i]|b[i]);
    }

    return c;
    
}

vector<int> operator& (
    const vector<int>& a,
    const vector<int>& b
){
    vector<int> c;

    for(int i = 0; i < a.size(); ++ i) {
        c.push_back(a[i] & b[i]);
    }

    return c;
    
}

std::ostream& operator<< (std::ostream &out, const vector<double>& a) {
    for(int i = 0; i < a.size(); ++ i) {
        out << a[i] << " ";
    }
    out << "\n";
    return out;
}

std::istream& operator>> (std::istream &in, vector<double>& a) {
    a = {};
    int n;
    in >> n;
    a.resize(n);
    for(int i = 0; i < n; ++ i) {
        in >> a[i];
    }
    return in;
}

}  // namespace task
