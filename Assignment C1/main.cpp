//  main.cpp
//  Spring 2014
//  Assignment C1
//  Description of problem: declare a class and test it with specific data

#include <iostream>

class Car{
private:
    std::string reportingMark;
    int         carNumber;
    std::string kind;
    bool        loaded;
    std::string destination;
public:
    void output();
    void setUp(std::string rm, int cn, std::string k, bool l, std::string d);
};

void input(std::string* rm, int* cn, std::string* k, bool* l, std::string* d){
    // Let user to enter the data into the class. //
    std::cout << "Enter the reporting mark (2-4 uppercase characters): ";
    std::cin  >> *rm;
    
    std::cout << "Enter the car number: ";
    std::cin  >> *cn;
    
    std::cout << "Enter the kind of car (Box, Tank, Flat, Other): ";
    std::cin  >> *k;
    
    std::string temp;
    std::cout << "Enter true if the car is loaded. If not, enter false: ";
    std::cin  >> temp;
    
    if (temp == "true")
        *l = true;
    else
        *l = false;

    if (*l)
        std::cout << "Enter your destination: ";
    else
        std::cout << "Enter your destination or None: ";
    std::cin.ignore();
    getline(std::cin, *d);
}
void Car::output(){
    // Print the data input into the screen. //
    std::cout << "Reporting Mark: " << reportingMark << std::endl;
    std::cout << "Car Number    : " << carNumber     << std::endl;
    std::cout << "Kind          : " << kind          << std::endl;
    std::cout << "Loaded        : " << loaded        << std::endl;
    std::cout << "Destination   : " << destination   << std::endl;
}
void Car::setUp(std::string mark, int num, std::string kind_car, bool loaded_car, std::string place){
    // Store the data entered into a car object. //
    reportingMark = mark;
    carNumber     = num;
    kind          = kind_car;
    loaded        = loaded_car;
    destination   = place;
}

int main() {
    Car car;
    
    std::string report_mark;
    int         car_num;
    std::string kind_car;
    bool        loaded_car;
    std::string d_place;
    
    input(&report_mark, &car_num, &kind_car, &loaded_car, &d_place);
    car.setUp(report_mark, car_num, kind_car, loaded_car, d_place);
    car.output();
    
    return 0;
}

