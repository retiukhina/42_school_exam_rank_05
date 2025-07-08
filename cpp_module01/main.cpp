#include "vect2.hpp"

int main() {
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
    const vect2 v3(v2); 
    vect2 v4 = v2;
    cout << "v1: " << v1 << endl;
    //cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << endl; // the same output
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;
    cout << "v4: " << v4 << endl;
    // cout << v4++ << endl;
    // cout << ++v4 << endl;
    // cout << v4-- << endl;
    // cout << --v4 << endl;
    // v2 += v3;
    // v1 -= v2;
    // v2 = v3 + v3 * 2;
    // v2 = 3 * v2;
    // v2 += v2 += v3;
    // v1 *= 42;
    // v1 = v1 - v1 + v1;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    // cout << "-v2: " << -v2 << endl;
    // cout << "v1[1]: " << v1[1] << endl;
    // v1[1] = 12;
    // cout << "v1[1]: " << v1[1] << endl;
    // cout << "v3[1]: " << v3[1] << endl;
    // cout << "v1 == v1 " << (v1 == v1) << endl;
    // cout << "v1 != v3 " << (v1 != v3) << endl;
}

