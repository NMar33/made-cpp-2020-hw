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

bool operator|| (
    const vector<double>& a,
    const vector<double>& b
){
    double k;

    for(int i = 0; i < a.size(); ++ i) {
        if ((a[i] != 0) && (b[i] != 0)) {
            k = a[i] / b[i];
            break;
        }
    }
    
     for(int i = 0; i < a.size(); ++ i) {
        if ((a[i] - b[i] * k > 1e-7) or (b[i] * k - a[i] > 1e-7))  {
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

    for(int i = 0; i < a.size(); ++ i) {
        if ((a[i] != 0) && (b[i] != 0)) {
            k = a[i] / b[i];
            break;
        }
    }
    if (k < 0) {
        return false;
    }

     for(int i = 0; i < a.size(); ++ i) {
        if ((a[i] - b[i] * k > 1e-7) or (b[i] * k - a[i] > 1e-7)) {
            return false;
        }   

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

}  // namespace task
