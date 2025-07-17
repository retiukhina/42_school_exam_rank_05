`Copy assignment operator`

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

`overload of the << operator`

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

`opearors + and += overloading`

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

`++v (prefix increment) and v++ (postfix increment) operators`


