//  main.cpp
//  Spring 2014
//  Assignment D1
//  Description of problem: read cars from a file, and put the data into the Car class.

#include <iostream>
#include <fstream>

class Car{
private:
    std::string reportingMark;
    int         carNumber;
    std::string kind;
    bool        loaded;
    std::string destination;
    
public:
    void setUp(std::string mark, int num, std::string kind_car, bool loaded_car, std::string place);
    void output();
    Car(){
        reportingMark = "";
        carNumber     = 0;
        kind          = "other";
        loaded        = false;
        destination   = "None";
    }
    Car(const Car& obj){
        reportingMark = obj.reportingMark;
        carNumber     = obj.carNumber;
        kind          = obj.kind;
        loaded        = obj.loaded;
        destination   = obj.destination;
    }
    Car(std::string rm, int cn, std::string k, bool l, std::string d)
    {setUp(rm, cn, k, l, d);}
    ~Car(){}
    friend bool operator==(Car &car_a, Car &car_b){
        // compare car1, car2, car3. //
        return (car_a.reportingMark == car_b.reportingMark && car_a.carNumber == car_b.carNumber);
    }
};

void input(){
    // Read the data from a text file and then close it. //
    std::string rm;
    int         cn;
    std::string  k;
    bool         l;
    std::string  d;
    
    std::string loaded_car;
    std::string type;
    
    std::ifstream inputFile;
    inputFile.open("input.txt");
    
    if (inputFile){
        while (inputFile.peek() != EOF) {
            inputFile >> type >> rm >> cn >> k >> loaded_car;
            if (loaded_car == "true")
                l = true;
            else
                l = false;
            
            while (inputFile.peek() == ' ') {
                inputFile.get();
            }
            getline(inputFile, d);
            
            Car temp(rm, cn, k, l, d);
            temp.output();
        }
    }
    else{
        std::cerr << "Error opening the file " << std::endl;
    }
    inputFile.close();
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
    input();
    return 0;
}



