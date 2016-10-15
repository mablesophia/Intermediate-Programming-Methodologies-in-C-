//  main.cpp
//  Spring 2014
//  Assignment D2
//  Description of problem: read cars from a file, and put the data into the Car class.
//  Also, create another class StringOfCars and print the associated car objects.

#include <iostream>
#include <fstream>

class Car{
protected:
    std::string reportingMark;
    int         carNumber;
    std::string kind;
    bool        loaded;
    std::string destination;
    
public:
    void setUp(std::string mark, int num, std::string kind_car, bool loaded_car, std::string place);
    virtual void output();
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

class StringOfCars : public Car{
public:
    const int ARRAY_MAX_SIZE = 10;
    int size;
    Car* array;
    
    StringOfCars(){
        array = new Car[ARRAY_MAX_SIZE];
        size = 0;
    }
    StringOfCars(const StringOfCars& oldObj){
        if(oldObj.size > 0)
            array = new Car[ARRAY_MAX_SIZE];
        
        size = oldObj.size;
        for (int i=0; i<size; i++)
            array[i] = oldObj.array[i];
    }
    ~StringOfCars(){
        delete [] array;
    }
    void push (Car car_p){
        if(size == ARRAY_MAX_SIZE)
            std::cout << "String is at max size" << std::endl;
        else{
            array[size] = car_p;
            size++;
        }
    }
    Car pop (){
        Car pop_car;
        if(size == 0)
            std::cout << "There is no string remaining" << std::endl;
        else{
            pop_car = array[size-1];
            --size;
        }
        return pop_car;
    }
    void output(){
        if(size > 0){
            for (int i=0; i<size; i++){
                std::cout << "CAR" << i+1 << std::endl;
                array[i].output();
            }
        }
        else
            std::cout << "NO CAR " << std::endl;
    }
};

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
            
            Car temp(rm, cn, k, l, d);
            temp.output();
            a_string.push(temp);
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
    std::cout << "TEST 1" << std::endl;
    Car car1;
    car1.setUp("SP", 34567, "box", true, "Salt Lake City");
    Car car2(car1);
    car2.output();
    
    StringOfCars string1;
    std::cout << "\nTEST 2" << std::endl;
    std::cout << "STRING 1" << std::endl;
    input(string1);
    string1.output();
    
    std::cout << "\nTEST 3" << std::endl;
    Car car3;
    car3 = string1.pop();
    std::cout << "CAR3" << std::endl;
    car3.output();
    std::cout << "STRING 1" << std::endl;
    string1.output();
    
    return 0;
}