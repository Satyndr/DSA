#include<iostream>

using namespace std;

//creating class
class hero{

    public:
    int health;
    char level;
};

int main(){

    //creation of object
    hero h1;

    h1.health = 70;
    h1.level = 'A';

    cout<<"Health is : "<<h1.health<<endl;
    cout<<"Level is : "<<h1.level<<endl;
    return 0;
}