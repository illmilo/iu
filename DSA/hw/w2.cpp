// Milena Kuznetsova m.kuznetsova@innopolis.university
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// abstract class implementation in c++
// https://learn.microsoft.com/en-us/cpp/cpp/abstract-classes-cpp?view=msvc-170
class StackADT {
public:
    StackADT() {}

    virtual ~StackADT() = 0;               // destructor to be init outside
    virtual int size()  = 0;        
    virtual bool isEmpty()  = 0;
    virtual void push(string e) = 0;          
    virtual string pop() = 0;                 // removes and returns the top element
    virtual string peek()  = 0;          // returns the top element without removing it
};

StackADT::~StackADT() {}

class ArrayStack : public StackADT {
private:
    string* arr;       
    int capacity;
    int top;    // index of the peek element
    
public:
    ArrayStack(int cap) : capacity(cap), top(-1) {
        arr = new string[capacity];
    }
    ~ArrayStack() override {
        delete[] arr;
    }

    int size()  override {
        return top + 1;
    }
    bool isEmpty()  override {
        return !size();
    }

    void push(string e) override {
        arr[++top] = e;
    }

    string pop() override {
        return arr[top--];
    }
    
    string peek() override {
        return arr[top];
    }
};

int priority(string c) {
    if (c == "+" || c == "-") return 1;
    else if (c == "*" || c == "/") return 2;
    else if (c == "min" || c == "max") return 3;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string shuting_yard() {
    int n = 1000;        // assume max amount of operations in stack
    auto stack = new ArrayStack(n);

    string c;
    string output;
    while (cin >> c) {
        if (isdigit(c[0])) output += c + ' ';
        else if (c == "min" || c == "max" || c == "(") {
            stack->push(c);
        }
        else if (c == "," || c == ")") {
            while (!stack->isEmpty() && stack->peek() != "(") // neglect emptiness
                output += stack->pop() + ' ';
            if (c == ")") {
                stack->pop();   // pop '('
                while (!stack->isEmpty() && priority(stack->peek()) >= 2) 
                    output += stack->pop() + ' ';
            }
        }
        else if (isOperator(c[0])) {
            while (!stack->isEmpty() && 
                priority(stack->peek()) >= priority(c))
                    output += stack->pop() + ' ';
            stack->push(c);
        }
    }
    while (!stack->isEmpty()) output += stack->pop() + ' ';
    delete stack;

    return output;
}

class QueueADT {
public:
    QueueADT() {}

    virtual ~QueueADT() = 0;               // destructor to be init outside
    virtual int size()  = 0;        
    virtual bool isEmpty()  = 0;
    virtual void push(int e) = 0;          
    virtual int pop() = 0;                 // removes and returns the top element
    virtual int peek()  = 0;          // returns the top element without removing it
};

QueueADT::~QueueADT() {}

class ArrayQueue : public QueueADT {
private:
    int* arr;       
    int capacity;
    int top;    // index of the peek element
    
public:
    ArrayQueue(int cap) : capacity(cap), top(-1) {
        arr = new int[capacity];
    }
    ~ArrayQueue() override {
        delete[] arr;
    }

    int size()  override {
        return top + 1;
    }
    bool isEmpty()  override {
        return !size();
    }

    void push(int e) override {
        arr[++top] = e;
    }

    int pop() override {
        return arr[top--];
    }
    
    int peek() override {
        return arr[top];
    }
};

int operationFetch(int b, int a, string op) {
    if (op == "min") return min(a, b);
    else if (op == "max") return max(a, b);
    else if (op == "*") return a * b;
    else if (op == "/") return a / b;
    else if (op == "+") return a + b;
    else if (op == "-") return a - b;
    return 0;
}

void decode_yard(string input) {
    int n = 1000; // Arbitrary stack size
    auto stack = new ArrayQueue(n);

    istringstream inputStream(input);
    string c;
    while (inputStream >> c) {
        if (isdigit(c[0])) {
            stack->push(c[0] - '0'); // convert char to digit
        } 
        else {
            int b = stack->pop();
            int a = stack->pop();

            int result = operationFetch(b, a, c); 
            stack->push(result);
        }
    }

    cout << stack->pop() << endl;

    delete stack;
}


int main() {
    // freopen("i.txt", "r", stdin);

    string encoded = shuting_yard();
    cout << encoded;
    // decode_yard(encoded);
    return 0;
}