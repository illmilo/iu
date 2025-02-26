----
# Initialization & Declaration

## Type
**Type** is a set of:
- **Values** of an object of that type
- **Operators** of objects of that type
- **Relationships** between the type and other types
_Examples:_
```c++
class C { ... };
```
- Values: 
  – Cartesian product of class members' sets
- Operators:
  – Construction, destruction, copying, moving
  – Access to class members
  – User-defined operators
- Relationships:
  – With base classes
  – User-defined conversion operators
```c++
int i;
```
- Values:
  – Integer numbers
- Operators:
  – Construction, destruction, copying, moving
  – Arithmetic & comparison operators
  – Shifts; …
- Relationships:
  – Conversions to `bool`, `float`, …
![[types.png]]
### Type Specifiers
| Predefined                                 | User-Defined                                             | Modified (Both)                                                    |
| ------------------------------------------ | -------------------------------------------------------- | ------------------------------------------------------------------ |
| ***Represented by keywords***              | ***Represented by identifiers (i. e., name of entity)*** | ***Special syntax***                                               |
| `int`<br>`float` & `double`<br>`char`<br>… | `class`<br>`enum`<br>`struct`<br>…                       | `const`<br>`*` (pointer)<br>`&` (reference)<br>Functions<br>Arrays |
### Compound Types
- Functions
- C-style Arrays
- Pointer types:
    - Pointer to object
    - Pointer to function
- Pointer to member types:
    - Pointer to data member
    - Pointer to member function
- Reference types:
    - L-value references
    - R-value references
- Enumerated types:
    - Unscoped enumerations
    - Scoped enumerations
- Class types:
    - Structs
    - Classes
    - Unions
## Reference
**Reference** is not an object. It's a **synonym** to some object.
*Example*:
```c++
int a;
int& r = a;
r = 3; // a = 3 
r++;   // a++ 
```
## Pointer

|                    | Pointers                            | Reference                                                     |
| ------------------ | ----------------------------------- | ------------------------------------------------------------- |
| **Status**         | An object                           | Not an object                                                 |
| **Value**          | Address of an object                | No value                                                      |
| **Initialization** | Might be non-initialized (null ptr) | Must be as it **always refer** to an object (no null refence) |
| **Operators**      | `&`(address-of),`*&` (dereference)  | None                                                          |
Also, arrays are treated like pointers to the first array element.
```c++
int Array[10];
Array[0];      // = *Array
```
## Constant Expressions
**Constant expression** is an expression whose value can be calculated at compile time.
`const` variables can't be used in context of constant expressions.
`constexpr` $\implies$ `const`:
```c++
constexpr const int N;
constexpr int N;
```
Those two expressions have the **same semantics.**
*Example:*
```c++
int x; // non-const

struct A {
	constexpr A(bool b) : m(b ? 42 : x) { }
	int m;
}

constexpr int v = A(true).m; // ok
constexpr int w = A(false).m; // ERROR! x is not const
```
## Namespace
**Namespace** is the declarative part where the scope of identifiers like functions, the name of types, classes, etc. are declared. It is used as a named container to avoid the ambiguity that may occur when two identifiers have the same name.
1. Can be extended to several translation units.
   ![[translation units.png]]
2. No namespace is an unnamed namespace.
```c++
int a;
namespace Subsystem {
	int a;
}
int x = Subsystem::a; // a from Subsystem
int z = ::a;          // global a
```

## Type Deduction
To let the program **deduct** the type of a function, we can use `auto` specifier.
```c++
auto [ x, y, z ] = expression;
auto [ x, y, z ] { expression };
auto [ x, y, z ] ( expression );
```
*Example*:
```c++
int a[2] = { 1, 2 };
auto [x, y] = a;    // temp array t created. x and y refer to t[0] and t[1] respectively
auto& [xr, yr] = a; // straight reference to a[0], a[1]
```
It's worth to note that **type deduction** for function return types should be **avoided**.
# Classes
**Class** is:
- A user-defined compound type;
- A user-defined type that behaves by the same rules as predefined types;
- Basis of object-oriented software design & development.
## Class Members
- **Class member** (or **object state**) represent the *structure* (the *state*) of the objects of this type;
- **Methods** (or class member **functions**) specify *operations* (*behavior*) on the objects of this type;
- **Special class members**:
  – Constructor                 (the ways objects get **created**)
  – Destructor                   (the way objects get **destroyed**)
  – Operator functions     (the ways objects **participate** in **operations**)
  – Conversion functions (the ways objects **get converted**)
### Instance members
**Instance members** are specific to an object of the class. Each object of the class will get a copy of the instance member.
```c++
class C {
public:
	int x; // instance variable
	void setX(int value) : x(value) {} // instance method
};

int main() {
	C obj1, obj2; // create an object of the class
	obj1.setX(0); // creates its own `x` variable = 0
	obj2.setX(2); // obj2 has a different `x` variable value
	return 0;
}
```
### Object State
**Class members** (mentioned as **object state**) belong to the class itself and not to any object.
- Shared among all instances;
- Declared via `static` keyword.
```c++
class C {
public:
	static int count; // shared among all objects
	static int incrementCount() : count(count + 1) { // static method
		return count; 
	}
};

// define static variable outside of the class
int C::count = 0;

int main() {
	C obj1, obj2;
	obj1.incrementCount(); // count = 1
	obj2.incrementCount(); // count = 2
	// they share the same static variable `count` amongst
	// all the instances of the class
	return 0;
}
```
### Constructor
```c++
class C {
	int a;
	// default constructor
	C() { a = 0; } 
	// conversion constructor
	C(int i) { a = i; }
	// copy constructor
	C(C& c) { a = c.a; } 
	// operator constructor
	C(int i, int j) { a = i+j; } 
};
C c1 = C();  // default + copy

// convert some type to user-defined
C c1(1);     // conversion
C c1 = C(1); // conversion

C c1 = 1;    // conversion + copy
```
The constructors do not create objects. The compiler sets up the memory allocation for the object prior to the constructor call. The constructor gets called on the uninitialized object.
### Operator Functions
It is possible to modify the **behavior of predefined operators**.
```c++
T operator OpSign (…) {
	…
}
```
### Conversion Functions
It is possible to modify the **behavior of predefined types**.
```c++
operator TargetType() {…} // no params
```
### Destructor
Used to **destroy** the object and **release the occupied memory**.
Recommended to use `delete` keyword and not just calling the destructor. *Reason:* allocated memory is unlikely to be freed if you just call the destructor.
## Inheritance
The problems with members of the same name.
Class instance from the derived class will **hide** from the base class. Let us solve such an overload.
```c++
class Base {
protected: // accessible via inherited classes
	int m1;
};
class Derived : Base {
	float m1;
	
	float f1() { return this->m1; } // refer to Derived class
	float f2() { return Base::m1; } // refer to Base class
};

int main() {
	Derived d;
	d.m1 = ...; // by default, will manage Derived class object
	d.Base::m1 = ...; // m1 from Base can be accessed via explicit qualification
	return 0;
}
```
### Virtual Inheritance
![[inheritance.png]]
```c++
class Car : virtual Vehicle { ... };
class Plane : virtual Vehicke { ... };
class SuperCar : Car, Plane { ... };
```

### Accessibility
```c++
class Base {
private:
	int m1;
protected:
	int m2;
public:
	int m3;
};
class Derived : Base {
	int m1 = Base::m1; // ERROR
	int m2 = Base::m2; // OK
	int m3 = Base::m3; // OK
};
int main() {
	Base b;
	int m1 = b.m1; // ERROR
	int m2 = b.m2; // ERROR
	int m3 = b.m3; // OK
};
```

### Base-Derived Conversion
***Basic principle of OOP***: Object of the **derived** type can be **converted** to an object of the **base** type.
```c++
class Shape { ... };
class Circle : Shape { ... };

int main() {
	Circle circle;
	// let the conversion begin
	Shape* shapeStatic = &circle;
	Shape* shapeDynamic = new Circle();

	Shape* figure = new Shape(); // static type is Shape*
	figure = new Circle();       // dynamic type is Circle*
	return 0;
}
```

### Polymorphism
**Polymorphism** is the ability for **derived** types to **modify** the behavior of the **base** type.
Basically, what you want is to **override** some methods of the base class. For doing so, you use `virtual` and `override` special keywords.
```c++
class Shape {
	virtual void increase() { }
};
class Rectangle : Shape {
	void increase() override;
};
class Square : Rectangle {
	void increase() override;
};
```
Methods in derived classes **don't hide** from the ones in base classes, but **override** them.
## Abstract Class
The class is **abstract** when it has at least one **pure virtual function** `virtual T function(parameters) = 0;`
It's important to note that we **can't create instances of an abstract class.**
```c++
class Shape {
	virtual void increase() = 0; // pure virtual function
};
int main() { 
	Shape* fig = new Shape(); // ERROR
	return 0;
}
```
# Functions
## Lambda Expression
**Lambda expression** is an anonymous function inside another function. 
```c++
[ captureClause ] ( parameters ) -> returnType {
	...
}
```
1. **Non-capturing** lambdas behave like function pointers and consume almost no extra memory.
2. **Capturing** lambdas use memory for storing variables, increasing their size.
3. Storing a lambda in `std::function<>` may cause heap allocation, increasing memory usage.
4. In some cases, normal functions are more **memory-efficient** than lambdas, especially when lambdas capture multiple variables.