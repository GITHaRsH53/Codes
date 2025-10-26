#include<bits/stdc++.h> 
using namespace std;

// public inheritance - makes public members of the base class public in the derived class, and the protected members of the base class remain protected in the derived class.
// protected inheritance - makes the public and protected members of the base class protected in the derived class.
// private inheritance - makes the public and protected members of the base class private in the derived class.

class A {
    public:
        int x;

    protected:
        int y;

    private:
        int z;
    };
    // Public inheritance
    class B : public A {
        // x is public
        // y is protected
        // z is not accessible from B
    };
    // Protected inheritance
    class C : protected A {
        // x is protected
        // y is protected
        // z is not accessible from C
    };
    // Private inheritance
    class D : private A // 'private' is default for classes
    {
        // x is private
        // y is private
        // z is not accessible from D
};

// to access public and protected

//----------------------------------------------
// C++ program to demonstrate to access the private members in the derived class or subclass
// using getter and setter functions we can access the private members of the base class in the derived class
class Base {
    private:
        int privateVar;

    public:
        // Constructor to initialize privateVar
        Base(int val){
            privateVar = val;
        }

        // Public getter function to get the value of privateVar
        int getPrivateVar() const { 
            return privateVar; 
        }

        // Public setter function to set the value of privateVar
        void setPrivateVar(int val) { 
            privateVar = val; 
        }
};

// Derived class
class Derived : public Base {
    public:
        // Constructor to initialize the base class
        Derived(int val) : Base(val){
            
        }

        // Function to display the private member of the base
        // class
        void displayPrivateVar()
        {
            // Accessing privateVar using the public member
            // function of the base class
            cout << "Value of privateVar in Base class: "
                << getPrivateVar() << endl;
        }

        // Function to modify the private member of the base
        // class
        void modifyPrivateVar(int val)
        {
            // Modifying privateVar using the public member
            // function of the base class
            setPrivateVar(val);
        }
};

//----------------------------------------------

class Car{  // class
    public:
        int max_speed; // member variables or data members
        int max_gear;
        int max_passengers;
        Car (){                    // default constructor
            max_speed = 40;        // default values
            max_gear = 3;
            max_passengers = 2;
        }
        Car(int speed, int gear, int passenger){  // parametrized constructor
            this->max_speed = speed;
            this->max_gear = gear;
            this->max_passengers = passenger;
        }
        void gear_up(int &curr_gear){     // member functions
            if(curr_gear<max_gear) curr_gear++;
        }
        void gear_down(int &curr_gear){     // member functions
            if(curr_gear>0) curr_gear--;
        }
        void speed_up(int &curr_speed){
            if(curr_speed<max_speed) curr_speed++;
        }
        void speed_down(int &curr_speed){
            if(curr_speed>0) curr_speed--;
        }
        void add_passenger(int &curr_passengers){
            if(curr_passengers<max_passengers) curr_passengers++;
        }
        void remove_passenger(int &curr_passengers){
            if(curr_passengers>0) curr_passengers--;
        }
        ~Car(){                         // destructor -> when scope of object ends this is called to free the memory
            cout << "Destructor called" << endl;
        }
};

int main(){
    Car Alto; // object
    Car Nios(100, 5, 4);  // max values of car
    int curr_speed = 0, curr_gear = 0, curr_passenger = 0;
    Alto.speed_up(curr_speed);
    Alto.gear_up(curr_gear);
    Alto.add_passenger(curr_passenger);
    cout << curr_speed << " " << curr_gear << " " << curr_passenger << endl;
    return 0;
}  // scope of object ends here


//types of inheritance

// 1. Single Inheritance
// 2. Multiple Inheritance
// 3. Multilevel Inheritance
// 4. Hierarchical Inheritance
// 5. Hybrid Inheritance
// 6. Multipath Inheritance
// 7. Cyclic Inheritance

// 1. Single Inheritance: In single inheritance, a class is allowed to inherit from only one class. i.e. one sub class is inherited by one base class only.     

// An object of class child has all data members and member functions of class parent
// so we try accessing the parents method and data from the child class object.

// code for single inheritance is given below:

class A {              // A is a base class
    public:
        void display() {
            cout << "Base class content." << endl;
        }
};
class B: public A {   // B is a sub class of A class
    public:
        void show() {
            cout << "Derived class content." << endl;
        }
        // u can use a memeber function of base class in derived class here
};

int main() {
    B obj;
    obj.display(); // calling base class function
    obj.show();   // calling derived class function
    return 0;
}
// Output: 
// Base class content.
// Derived class content.



// 2. Multiple Inheritance: In multiple inheritance, a class is allowed to inherit from more than one class. i.e. one sub class is inherited by more than one base class.
// code for multiple inheritance is given below.
class A {
    public:
        void display() {
            cout << "Base class A content." << endl;
        }
};
class B {
    public:
        void show() {
            cout << "Base class B content." << endl;
        }
};
class C: public A, public B {
    public:
        void view() {
            cout << "Derived class content." << endl;
        }
};
int main() {
    C obj;
    obj.display(); // calling base class A function
    obj.show(); // calling base class B function
    obj.view(); // calling derived class function
    return 0;
}
// Output: B
// Base class A content.
// Base class B content.
// Derived class content.


// 3. Multilevel Inheritance: In multilevel inheritance, a class is allowed to inherit from another class and that class can also inherit from another class. i.e. one sub class is inherited by another sub class and so on.
// code for multilevel inheritance is given below.
class A {
    public:
        void display() {
            cout << "Base class A content." << endl;
        }
};
class B: public A {
    public:
        void show() {
            cout << "Derived class B content." << endl;
        }
};
class C: public B {
    public:
        void view() {
            cout << "Derived class C content." << endl;
        }
};  
int main() {
    C obj;
    obj.display(); // calling base class A function
    obj.show(); // calling derived class B function
    obj.view(); // calling derived class C function
    return 0;
}
// Output:
// Base class A content.        
// Derived class B content.
// Derived class C content. 

// 4. Hierarchical Inheritance: In hierarchical inheritance, a class is allowed to inherit from more than one class. i.e. one base class is inherited by more than one sub class.
// code for hierarchical inheritance is given below.
class A {
    public:
        void display() {
            cout << "Base class A content." << endl;
        }
};
class B: public A {
    public:
        void show() {
            cout << "Derived class B content." << endl;
        }
};
class C: public A {
    public:
        void view() {
            cout << "Derived class C content." << endl;
        }
};
int main() {
    B obj1;
    C obj2;
    obj1.display(); // calling base class A function
    obj1.show(); // calling derived class B function
    obj2.display(); // calling base class A function
    obj2.view(); // calling derived class C function
    return 0;
}

// Output:
// Base class A content.
// Derived class B content.
// Base class A content.
// Derived class C content.

// 5. Hybrid Inheritance: In hybrid inheritance, a class is allowed to inherit from more than one class and that class can also inherit from another class. i.e. one base class is inherited by more than one sub class and that sub class can also inherit from another base class.
// code for hybrid inheritance is given below.

class A {
    public:
        void display() {
            cout << "Base class A content." << endl;
        }
};
class B: public A {
    public:
        void show() {
            cout << "Derived class B content." << endl;
        }
};
class C: public A {
    public:
        void view() {
            cout << "Derived class C content." << endl;
        }
};
class D: public B, public C {
    public:
        void print() {
            cout << "Derived class D content." << endl;
        }
};
int main() {
    D obj;
    obj.display(); // calling base class A function
    obj.show(); // calling derived class B function
    obj.view(); // calling derived class C function
    obj.print(); // calling derived class D function
    return 0;
}
// Output:
// Base class A content.
// Derived class B content.
// Derived class C content.
// Derived class D content.

// 6. Multipath Inheritance: In multipath inheritance, a class is allowed to inherit from more than one class and that class can also inherit from another class. i.e. one base class is inherited by more than one sub class and that sub class can also inherit from another base class. This is also called as diamond problem in c++.
// code for multipath inheritance is given below.
class A {
    public:
        void display() {
            cout << "Base class A content." << endl;
        }
};
class B: public A {
    public:
        void show() {
            cout << "Derived class B content." << endl;
        }
};
class C: public A {
    public:
        void view() {
            cout << "Derived class C content." << endl;
        }
};
class D: public B, public C {
    public:
        void print() {
            cout << "Derived class D content." << endl;
        }
};
int main() {
    D obj;
    obj.display(); // calling base class A function
    obj.show(); // calling derived class B function
    obj.view(); // calling derived class C function
    obj.print(); // calling derived class D function
    return 0;
}
// Output:
// Base class A content.
// Derived class B content.
// Derived class C content.
// Derived class D content.
// In this case, the compiler will not be able to determine which base class function to call. This is called as diamond problem in c++.
// To resolve this problem, we can use virtual inheritance. Virtual inheritance is a way to solve the diamond problem in c++. In virtual inheritance, the base class is inherited virtually. This means that the base class is shared among all the derived classes. This way, the compiler will be able to determine which base class function to call.

// 7. Cyclic Inheritance: In cyclic inheritance, a class is allowed to inherit from another class and that class can also inherit from the first class. i.e. one base class is inherited by another sub class and that sub class can also inherit from the first base class. This is not allowed in c++ as it will create an infinite loop. This is also called as circular inheritance in c++.
// code for cyclic inheritance is given below.
class A {
    public:
        void display() {
            cout << "Base class A content." << endl;
        }
};
class B: public A {
    public:
        void show() {
            cout << "Derived class B content." << endl;
        }
};
class A: public B {
    public:
        void view() {
            cout << "Derived class C content." << endl;
        }
};
int main() {
    A obj;
    obj.display(); // calling base class A function
    obj.show(); // calling derived class B function
    obj.view(); // calling derived class C function
    return 0;
}
// Output:
// Base class A content.
// Derived class B content.
// Derived class C content.
// In this case, the compiler will not be able to determine which base class function to call. This is called as circular inheritance in c++. This is not allowed in c++ as it will create an infinite loop.
// To resolve this problem, we can use virtual inheritance. Virtual inheritance is a way to solve the circular inheritance problem in c++. In virtual inheritance, the base class is inherited virtually. This means that the base class is shared among all the derived classes. This way, the compiler will be able to determine which base class function to call.


// In C++, virtual inheritance ensures that a derived class inherits only one copy of a base class, even when the base class is inherited through multiple paths, preventing the "diamond problem" of multiple inheritance. 
// The Problem:
// Without virtual inheritance, if a class D inherits from classes B and C, and both B and C inherit from the same class A, then D would inherit two separate copies of A's members, one through each path.
// The Solution:
// Virtual inheritance solves this by declaring the base class A as virtual in the inheritance declarations of B and C.
// How it works:
// When D inherits from B and C, which in turn inherit virtually from A, D will only have one copy of A's members.

class A {
    public:
        int x;
};

class B : virtual public A {
};

class C : virtual public A {
};

class D : public B, public C {
};

// In this example, D will only have one copy of A's member x. 
// Virtual inheritance is primarily used to resolve the "diamond problem" in multiple inheritance scenarios, ensuring a clean and unambiguous inheritance hierarchy. 