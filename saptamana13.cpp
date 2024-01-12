/* VirtualM*/
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Shape {
public:
    // Constructor
    Shape(const string& name) : name_(name) {}

    // Pure virtual function to calculate area (abstract method)
    virtual double CalculateArea() const = 0;

    // Virtual function to display shape information
    virtual void DisplayDetails() const {
        cout << "Shape: " << name_ << endl;
    }

protected:
    string name_;
};

// Derived class for a circle
class Circle : public Shape {
public:
    // Constructor
    Circle(const string& name, double radius) : Shape(name), radius_(radius) {}

    // Override method to calculate the area of a circle
    double CalculateArea() const override {
        return 3.14 * radius_ * radius_;
    }

    // Override method to display information about the circle
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Circle\nRadius: " << radius_ << endl;
    }

private:
    double radius_;
};

// Derived class for a rectangle
class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(const string& name, double length, double width)
        : Shape(name), length_(length), width_(width) {}

    // Override method to calculate the area of a rectangle
    double CalculateArea() const override {
        return length_ * width_;
    }

    // Override method to display information about the rectangle
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Rectangle\nLength: " << length_ << "\nWidth: " << width_ << endl;
    }

private:
    double length_;
    double width_;
};

int main() {
    Shape* v[4];



    // Creating an object of type Circle and calling virtual methods
    Circle circle("My Circle", 5.0);
    circle.DisplayDetails();
    cout << "Area: " << circle.CalculateArea() << endl;

    cout << "\n------------------------\n";

    // Creating an object of type Rectangle and calling virtual methods
    Rectangle rectangle("My Rectangle", 4.0, 6.0);
    rectangle.DisplayDetails();
    cout << "Area: " << rectangle.CalculateArea() << endl;
    v[0] = new Circle("circle2",7.0);

    v[1] = new Rectangle("rectangle",3,4);

    v[2] = new Rectangle("rectangle1",5,6);

    v[3] = new Circle("circle1",10);
    for (int i = 0; i < 4; i++) {
    v[i]->DisplayDetails();
    cout << "area " << v[0]->CalculateArea() << endl;
}


    return 0;
}
/*Custom Exception
#include <iostream>
#include <stdexcept>
using namespace std;

// Clasa custom de exceptii pentru impartire la zero
class DivisionByZeroException : public runtime_error {
public:
    DivisionByZeroException() : runtime_error("Division by zero is not allowed.") {}
};

// Clasa care efectueaza operatia de impartire si arunca exceptii
class Divider {
public:
    static double PerformDivision(double numerator, double denominator) {
        try {
            if (denominator == 0) {
                // Aruncam o exceptie de tipul nostru
                throw DivisionByZeroException();
            }
            return numerator / denominator;
        }
        catch (const DivisionByZeroException& e) {
            // Prindem si gestionam exceptia noastra
            cerr << "Custom Exception caught: " << e.what() << endl;
            // Returnam un rezultat special pentru a indica situatia exceptionala
            return numeric_limits<double>::quiet_NaN();
        }
    }
};

int main() {
    try {
        double result = Divider::PerformDivision(10.0, 2.0);
        cout << "Result: " << result << endl;

        result = Divider::PerformDivision(5.0, 0.0);  // Aici se va arunca o exceptie
        cout << "Result: " << result << endl;  // Aceasta linie nu va fi executata
    }
    catch (const DivisionByZeroException& e) {
        // Prindem si gestionam exceptia noastra
        cerr << "Main function custom exception caught: " << e.what() << endl;
    }

    return 0;
}*/


/* TryCatch
#include <iostream>
#include <stdexcept>

// Functie care efectueaza impartirea si arunca o exceptie in caz de impartire la zero
double PerformDivision(double numerator, double denominator) {
    // Utilizam blocul try pentru a gestiona posibilele exceptii
    try {
        if (denominator == 0) {
            // Aruncam o exceptie daca incercam sa impartim la zero
            throw std::runtime_error("Division by zero is not allowed.");
        }
        // Daca nu exista exceptie, returnam rezultatul impartirii
        return numerator / denominator;
    }
    catch (const std::exception& e) {
        // Prindem si gestionam exceptiile standard C++
        std::cerr << "Exception caught: " << e.what() << std::endl;
        // Returnam un rezultat de valoare speciala pentru a indica o situatie exceptionala
        return std::numeric_limits<double>::quiet_NaN(); // NaN (Not a Number)
    }
}

int main() {
    // Utilizam functia PerformDivision in blocuri try-catch
    try {
        double result = PerformDivision(10.0, 2.0);
        std::cout << "Result: " << result << std::endl;

        result = PerformDivision(5.0, 0.0);  // Aici se va arunca o exceptie
        std::cout << "Result: " << result << std::endl;  // Aceasta linie nu va fi executata
    }
    catch (const std::exception& e) {
        // Prindem si gestionam exceptiile standard C++
        std::cerr << "Main function exception caught: " << e.what() << std::endl;
    }

    return 0;
}*/



/*Diamond Solved
#include <iostream>

// Virtual base class
class A {
public:
    virtual void Show() const {
        std::cout << "A\n";
    }
};

// First derived class with virtual inheritance
class B : virtual public A {};

// Second derived class with virtual inheritance
class C : virtual public A {};

// Class derived from both classes B and C
class D : public B, public C {};

int main() {
    D d;

    // Accessing members of A in D, no more ambiguity
    d.Show();

    return 0;
}*/



/* VirtualM
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Shape {
public:
    // Constructor
    Shape(const string& name) : name_(name) {}

    // Pure virtual function to calculate area (abstract method)
    virtual double CalculateArea() const = 0;

    // Virtual function to display shape information
    virtual void DisplayDetails() const {
        cout << "Shape: " << name_ << endl;
    }

protected:
    string name_;
};

// Derived class for a circle
class Circle : public Shape {
public:
    // Constructor
    Circle(const string& name, double radius) : Shape(name), radius_(radius) {}

    // Override method to calculate the area of a circle
    double CalculateArea() const override {
        return 3.14 * radius_ * radius_;
    }

    // Override method to display information about the circle
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Circle\nRadius: " << radius_ << endl;
    }

private:
    double radius_;
};

// Derived class for a rectangle
class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(const string& name, double length, double width)
        : Shape(name), length_(length), width_(width) {}

    // Override method to calculate the area of a rectangle
    double CalculateArea() const override {
        return length_ * width_;
    }

    // Override method to display information about the rectangle
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Rectangle\nLength: " << length_ << "\nWidth: " << width_ << endl;
    }

private:
    double length_;
    double width_;
};

int main() {
    Shape* v[4];



    // Creating an object of type Circle and calling virtual methods
    Circle circle("My Circle", 5.0);
    circle.DisplayDetails();
    cout << "Area: " << circle.CalculateArea() << endl;

    cout << "\n------------------------\n";

    // Creating an object of type Rectangle and calling virtual methods
    Rectangle rectangle("My Rectangle", 4.0, 6.0);
    rectangle.DisplayDetails();
    cout << "Area: " << rectangle.CalculateArea() << endl;
    v[0] = new Circle("circle2",7.0);

    v[1] = new Rectangle("rectangle",3,4);

    v[2] = new Rectangle("rectangle1",5,6);

    v[3] = new Circle("circle1",10);
    for (int i = 0; i < 4; i++) {
    v[i]->DisplayDetails();
    cout << "area " << v[0]->CalculateArea() << endl;
}


    return 0;
}*/
