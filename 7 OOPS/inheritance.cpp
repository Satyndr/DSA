#include<iostream>

using namespace std;

class human{

    public:
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }

};

//creating inherited child class
class male: public human{//single inheritance

    public:
    string color;

};



int main(){

    male object1;
    cout<<object1.age<<endl;
    cout<<object1.color<<endl;
    cout<<object1.getAge()<<endl;

    

    return 0;
}