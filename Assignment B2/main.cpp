//  main.cpp
//  Spring 2014
//  Assignment B2
//  Description of problem: declare a class and test it with specific data

#include <iostream>

class Car{
public:
    std::string reportingMark;
    int         carNumber;
    std::string kind;
    bool        loaded;
    std::string destination;
};

void input(Car* p){
    // Let user to enter the data into the struct. //
    std::cout << "Enter the reporting mark (2-4 uppercase characters): ";
    std::cin  >> p->reportingMark;
    
    std::cout << "Enter the car number: ";
    std::cin  >> p->carNumber;
    
    std::cout << "Enter the kind of car (Box, Tank, Flat, Other): ";
    std::cin  >> p->kind;
    
    std::string temp;
    std::cout << "Enter true if the car is loaded. If not, enter false: ";
    std::cin  >> temp;
    
    if (temp == "true")
    p->loaded = true;
    else
    p->loaded = false;
    
    if (p->loaded)
        std::cout << "Enter your destination: ";
    else
        std::cout << "Enter your destination or None: ";
    std::cin.ignore();
    getline(std::cin, p->destination);
}
void output(Car p){
    // Print the data input into the screen. //
    std::cout << "Reporting Mark: " << p.reportingMark << std::endl;
    std::cout << "Car Number    : " << p.carNumber     << std::endl;
    std::cout << "Kind          : " << p.kind          << std::endl;
    std::cout << "Loaded        : " << p.loaded        << std::endl;
    std::cout << "Destination   : " << p.destination   << std::endl;
}

int main() {
    Car* car = new Car;
    
    input(car);
    output(*car);
    
    delete car;
    car = 0;
    
    return 0;
}

