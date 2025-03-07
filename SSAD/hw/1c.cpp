#include <iostream>
#include <vector>
#include <type_traits>
#include <assert.h>
#include <string>
#include <cctype>

using namespace std;

string beautifulEmail(string fn, string ln) {
    string res = "";
    res += tolower(fn[0]);
    res += ".";
    for (char c: ln) res += tolower(c);
    return res;
}

class Person {
public:
    string fname, lname;
    static int count;

    Person(string firstName, string lastName) : fname(firstName), lname(lastName) {
        count++;
    }

    virtual string getEmail() = 0;
    virtual ~Person() = default;
    Person(Person& p) = delete;
};
class Student : virtual public Person {
public:
    Student(string f, string l) : Person(f, l) {}
    string getEmail() override {
        return beautifulEmail(fname, lname) + "@students.org";
    }
};
class Employee : virtual public Person {
public:
    Employee(string f, string l) : Person(f, l) {}

    string getEmail() override {
        return beautifulEmail(fname, lname) + "@employees.org";
    }
};
class TA : public Student, public Employee {
public:
    TA(string f, string l) : Person(f, l), Student(f, l), Employee(f, l) {}
    string getEmail() override {
        // return fname[0] + "." + lname + "@employees.org";
        return Employee::getEmail();
    }
};

int Person::count = 0;

int main() {
    freopen("i.txt", "r", stdin);
    static_assert(is_abstract_v<Person>);
    static_assert(is_base_of_v<Person, Employee>);
    static_assert(is_base_of_v<Person, Student>);
    static_assert(is_base_of_v<Person, TA>);
    static_assert(is_base_of_v<Employee, TA>);
    static_assert(is_base_of_v<Student, TA>);
    static_assert(is_polymorphic_v<Student>);
    static_assert(is_polymorphic_v<Employee>);
    static_assert(is_polymorphic_v<TA>);
    static_assert(!is_copy_constructible_v<Person>);
    static_assert(has_virtual_destructor_v<Person>);
    
    string fname, lname;
    
    cin >> fname >> lname;
    Student* s = new Student(fname, lname);
    assert(Person::count == 1);
    
    cin >> fname >> lname;
    Employee* e = new Employee(fname, lname);
    assert(Person::count == 2);
    
    cin >> fname >> lname;
    TA* t = new TA(fname, lname);
    assert(Person::count == 3);

    vector<Person*> people = {s, e, t};
    for(auto& p: people) {
        cout << p->getEmail() << endl;
        delete p;
    }
}