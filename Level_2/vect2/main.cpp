#include "vect2.hpp"
#include <sstream>
#include <assert.h>

void test_4() {
    vect2 v1(0, 0);
    vect2 v2(2, 3);

    vect2 expected_min(-2, -3);
    assert(v1 - v2 == expected_min);

    vect2 expected_after_min(2, 3);
    assert((v2 -= v1) == expected_after_min);

    vect2 expected_post_decrem(2, 3);
    vect2 post_result = v2--;
    assert(post_result == expected_post_decrem);

    vect2 expected_after_post(1, 2);
    assert(v2 == expected_after_post);

    vect2 expected_pre_decrem(0, 1);
    assert((--v2) == expected_pre_decrem);
    assert(v2 == expected_pre_decrem);
}

void test_3() {
    vect2 v1(0, 0);
    vect2 v2(2, 3);

    vect2 expected_sum(2, 3);
    assert(v1 + v2 == expected_sum);

    vect2 expected_after_add(2, 3);
    assert((v1 += v2) == expected_after_add);

    vect2 expected_post_inc(2, 3);
    vect2 post_result = v1++;
    assert(post_result == expected_post_inc);

    vect2 expected_after_post(3, 4);
    assert(v1 == expected_after_post);

    vect2 expected_pre_inc(4, 5);
    assert((++v1) == expected_pre_inc);
    assert(v1 == expected_pre_inc);
}

void test_2() {
    vect2 v1;
    std::ostringstream out;

    out << "{" << v1[0] << ", " << v1[1] << "}";
    assert(out.str() == "{0, 0}");
}

void test_1() {
    vect2 v1;
    assert(v1 == vect2(0, 0));
    vect2 v2(1, 2);
    assert(v2 == vect2(1, 2));
    const vect2 v3(v2); 
    assert(v3 == v2);
    vect2 v4 = v2;
    assert(v4 == v2);
    vect2 v5(4, 4);
    assert(v5 == vect2(4, 4));

}

// main supplied by exam's task
int main() {
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
    const vect2 v3(v2); 
    vect2 v4 = v2;
    vect2 v5(4, 4);
    cout << "v1: " << v1 << endl;
    cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << endl; // the same output
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;
    cout << "v4: " << v4 << endl;

    cout << "v2 + v3: " << v2 + v3 << endl;
    cout << "++v4: " << ++v4 << endl;
    cout << "v4++: " << v4++ << endl;
    cout << "--v4: " << --v4 << endl;
    cout << "v4--: " << v4-- << endl;
    cout << "v2 += v3: " << (v2 += v3) << endl;
    v1 -= v2;
    v2 = v3 + v3 * 2;
    cout << "v2: " << v2 << endl;
    v2 = 3 * v2;
    cout << "v2 = 3 * v2: " << v2 << endl;
    v5 = v2 * 0;
    cout << "v5 * 0: " << v5 << endl;
    v2 += v2 += v3;
    cout << "v2 += v2 += v3: " << v2 << endl;
    v5 = v1 *= 42;
    cout << v5 << endl;
    v1 = v1 - v1 + v1;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "-v2: " << -v2 << endl;
    cout << "v1[1]: " << v1[1] << endl;
    v1[1] = 12;
    cout << "v1[1]: " << v1[1] << endl;
    cout << "v1[0]: " << v1[0] << endl;
    cout << "v3[1]: " << v3[1] << endl;
    cout << "v1 == v1: " << (v1 == v1) << endl;
    cout << "v1 != v3: " << (v1 != v3) << endl;

    //my tests
    test_1();
    test_2();
    test_3();
    test_4();
}

