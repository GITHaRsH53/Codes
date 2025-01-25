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
