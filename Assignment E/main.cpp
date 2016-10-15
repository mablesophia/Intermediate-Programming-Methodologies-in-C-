//  main.cpp
//  Spring 2014
//  Assignment E
//  Description of problem: use a linked list to print the car objects.

#include <iostream>
#include <fstream>

enum Kind{
    business, maintenance, other, box, tank, flat, otherfreight, chair, sleeper, otherPassenger
};
const int NUM_KIND = 10;
std::string KIND_ARRAY[NUM_KIND] = {"business", "maintenance", "other", "box", "tank", "flat",
    "otherfreight", "chair", "sleeper", "otherPassenger"};

class Car{
protected:
    std::string reportingMark;
    int         carNumber;
    Kind        kind;
    bool        loaded;
    std::string destination;
    
public:
    void setUp(std::string mark, int num, std::string kind_car, bool loaded_car, std::string place);
    virtual void output();
    virtual void setKind(std::string const_string);
    Car(){
        reportingMark = "";
        carNumber     = 0;
        kind          = other;
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
    Car& operator=(const Car& carB){
        // Return the left hand operator by reference. //
        reportingMark = carB.reportingMark;
        carNumber     = carB.carNumber;
        kind          = carB.kind;
        loaded        = carB.loaded;
        destination   = carB.destination;
        
        return *this;
    }
    friend bool operator==(Car &car_a, Car &car_b){
        // compare car1, car2, car3. //
        return (car_a.reportingMark == car_b.reportingMark && car_a.carNumber == car_b.carNumber);
    }
};

class FreightCar : public Car{
public:
    FreightCar(){
        reportingMark = "";
        carNumber     = 0;
        kind          = other;
        loaded        = false;
        destination   = "None";
    }
    FreightCar(const FreightCar& obj){
        reportingMark = obj.reportingMark;
        carNumber     = obj.carNumber;
        kind          = obj.kind;
        loaded        = obj.loaded;
        destination   = obj.destination;
    }
    FreightCar(std::string rm, int cn, std::string k, bool l, std::string d);
    void setKind(std::string const_string){
        // Set the correct Kind to the FreightCar class. //
        if (const_string == "box")
            kind = box;
        else if (const_string == "tank")
            kind = tank;
        else if (const_string == "flat")
            kind = flat;
        else
            kind = otherfreight;
    }
};

class PassengerCar : public Car{
public:
    PassengerCar(){
        reportingMark = "";
        carNumber     = 0;
        kind          = other;
        loaded        = false;
        destination   = "None";
    }
    PassengerCar(const PassengerCar& obj){
        reportingMark = obj.reportingMark;
        carNumber     = obj.carNumber;
        kind          = obj.kind;
        loaded        = obj.loaded;
        destination   = obj.destination;
    }
    PassengerCar(std::string rm, int cn, std::string k, bool l, std::string d);
    void setKind(std::string const_string){
        // Set the correct Kind to the PassengerCar class. //
        if (const_string == "chair")
            kind = chair;
        else if (const_string == "sleeper")
            kind = sleeper;
        else
            kind = otherPassenger;
    }
};

class Node{
private:
    Node* next;
    Car* data;
    Node(){
        next = 0;
        data = 0;
    }
public:
    friend class StringOfCars;
};

class StringOfCars{
private:
    Node* head;
    Node* tail;
    
public:
    StringOfCars(){
        head = 0;
        tail = 0;
    }
    StringOfCars(const StringOfCars& oldObj){
        Node* currentPtr;
        head = 0;
        tail = 0;
        
        head = oldObj.head;
        tail = oldObj.tail;
        
        if (oldObj.head != 0)
        {
            while(currentPtr != 0){
                push(*currentPtr->data);
                currentPtr = currentPtr->next;
            }
        }
    }
    ~StringOfCars(){
    }
    void push (Car &car_p){
        Car*  currentCarPtr;
        Node* currentNodePtr;
        
        currentNodePtr = new Node;
        currentCarPtr  = new Car(car_p);
        currentNodePtr->next = 0;
        currentNodePtr->data = currentCarPtr;
        
        if (head == 0){
            head = currentNodePtr;
            tail = currentNodePtr;
        }
        else{
            tail->next = currentNodePtr;
            tail       = currentNodePtr;
        }
    }
    void output(){
        Node* currentPtr;
        
        if (head == 0)
            std::cout << "NO CARS" << std::endl;
        else{
            currentPtr = head;
            while(currentPtr != 0){
                currentPtr->data->output();
                currentPtr = currentPtr->next;
            }
        }
    }
};
void buildCar(std::string& rm, int& cn, std::string& k, bool& l, std::string& d, StringOfCars& const_string){
    Car n_Car(std::string rm, int cn, std::string k, bool l, std::string d);
    class Car car_object;
    car_object.setUp(rm, cn, k, l, d);
    car_object.setKind(k);
    const_string.push(car_object);
}
void buildFreightCar(std::string& rm, int& cn, std::string& k, bool& l, std::string& d, StringOfCars& const_string){
    Car f_Car(std::string rm, int cn, std::string k, bool l, std::string d);
    class FreightCar car_object;
    car_object.setUp(rm, cn, k, l, d);
    car_object.setKind(k);
    const_string.push(car_object);
}
void buildPassengerCar(std::string& rm, int& cn, std::string& k, bool& l, std::string& d, StringOfCars& const_string){
    Car p_Car(std::string rm, int cn, std::string k, bool l, std::string d);
    class PassengerCar car_object;
    car_object.setUp(rm, cn, k, l, d);
    car_object.setKind(k);
    const_string.push(car_object);
}

void input(StringOfCars& a_string){
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
            
            if (type == "Car")
                buildCar(rm, cn, k, l, d, a_string);
            if (type == "FreightCar")
                buildFreightCar(rm, cn, k, l, d, a_string);
            if (type == "PassengerCar")
                buildPassengerCar(rm, cn, k, l, d, a_string);
            
        }
    }
    else{
        exit(EXIT_FAILURE);
    }
    inputFile.close();
}
void Car::output(){
    // Print the data input into the screen. //
    std::cout << "Reporting Mark: " << reportingMark   << std::endl;
    std::cout << "Car Number    : " << carNumber       << std::endl;
    std::cout << "Kind          : " << KIND_ARRAY[kind]<< std::endl;
    std::cout << "Loaded        : " << loaded          << std::endl;
    std::cout << "Destination   : " << destination     << std::endl;
    std::cout << std::endl;
}
void Car::setUp(std::string mark, int num, std::string kind_car, bool loaded_car, std::string place){
    reportingMark = mark;
    carNumber     = num;
    setKind(kind_car);
    loaded        = loaded_car;
    destination   = place;
}
void Car::setKind(std::string const_string){
    // Set the correct Kind to the Car class. //
    if (const_string == "business")
        kind = business;
    else if (const_string == "maintenance")
        kind = maintenance;
    else
        kind = other;
}

int main() {
    StringOfCars string1;
    input(string1);
    
    StringOfCars string_of_car(string1);
    string_of_car.output();
    
    return 0;
}