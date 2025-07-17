# `COPY ASSIGNMENT OPERATOR`

checks whether the object is being assigned to itself — that is, it prevents self-assignment.

🔁 Why check for self-assignment?
When we do:

`vect2 a;`
`// ... do something ...`
`a = a;`

Without this check, the assignment operator would proceed to copy the data from `a` to itself, potentially causing problems if:

1. There are resources (like dynamically allocated memory or file handles) that are released and then accessed again.
2. The called function (in this case createVector()) re-initializes or reallocates internal structures.

`this` is a pointer to the current object — the one on the left-hand side of the assignment.

`a = b;` → `a.this`

`&other` is the address of the object on the right-hand side (b)

# `<< OVERLOADING`

Used for printing our vect2 class to an output stream (like std::cout).

🔁 Return value std::ostream&
Returning a reference to the stream allows us to chain output operations, like:

`std::cout << v1 << v2 << std::endl;`
Each << operator must return the stream so the next << can use it.

📥 Parameters

`std::ostream& os`
The first parameter is the output stream we're printing to (std::cout, std::ofstream, etc.).

It's a non-const reference because we're modifying it by inserting data into it.

`const vect2& v`
The second parameter is our vect2 object being printed.
Passed as a const reference to:

Avoid unnecessary copying
Guarantee we won't modify `v` during printing

# `+ AND += OVERLOADING`

operator+ should reuse operator+=.

1. operator+= is the fundamental operation
It directly modifies the object in-place.
It’s more efficient because it avoids unnecessary copying.
It's usually simpler and lower-level.

2. operator+ is syntactic sugar built on +=
It produces a new value without modifying either operand.

The easiest and cleanest way to do that is to:

Copy the left-hand operand (*this)
Apply += to the copy
Return the result

🔁 Return value in operator+

Returning const prevents move assignment and chaining like:

`vect2 a, b, c;`
`(a + b) = c;` // won’t compile if return is const

So, if `vect2` class doesn’t support assignment-to-temporaries, keeping const is okay. If it should support, return by copy.

# `[] OVERLOADING`

C++ uses const-correctness to decide which function to call

1. Const version (for read-only access):

`int vect2::operator[](int index) const {`
    `return _arr[index];`
`}`

Used when the object is const, or when only read access is needed:

`const vect2 v;`
`int x = v[0];`  // Read-only access

2. Non-const version (for modification):

`int& vect2::operator[](int index) {`
    `return _arr[index];`
`}`
Used when you want to modify the value:

vect2 v;
v[0] = 10;  // Modifies v 

# `PRETFIX AND POSTFIX INCREMENT/DECREMENT OVERLOADING`

1. Prefix incrementing/decrementing

Modifies the object and reuses
`x = ++v` → v is incremented before, so x gets the updated value.

We return reference because we want:
    1. the result can be used in chained expressions like:
    `(--v1) -= v2;`
    2. the result can be modified like here:
    `(++v).x = 5;`

2. Postfix incrementing/decrementing

Return old value
`x = v++` → v is incremented after, so x should get the original value.

# `UNARY MINUS -V2 OVERLOADING`

The expression `-v2` creates a new, temporary object that represents the negated version of `v2`. Since it's a new object, there's no reason (and no way) to return it as an lvalue reference.

If we tried this:

`vect2& vect2::operator-() const { ... }` // ❌ Wrong!

We’d end up returning a reference to a temporary object — which leads to undefined behavior.

`vect2 v2 = -v1;` // Calls operator-, returns temporary, assigns to `v2`

`-v1` is a `prvalue` (pure rvalue) — a temporary value — and that's exactly what we want here.