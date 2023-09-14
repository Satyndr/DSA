#include<iostream>

using namespace std;

//creating class
class hero{

    private:
    int health;

    public:
    char level;

    int getHealth(){
        return health;
    }

    void setHealth(int data){
        health=data;
    }

};

int main(){

    //creation of object
    hero h1;

    //h1.health = 70;
    h1.setHealth(50);
    h1.level = 'A';

    cout<<"Health is : "<<h1.getHealth()<<endl;
    cout<<"Level is : "<<h1.level<<endl;
    return 0;
}