#include<iostream>

using namespace std;

//creating class
class hero{

    private:
    int health;

    public:
    char level;

    //constructor
    hero(){
        cout<<"Constructor called! "<<endl;
    }

    int getHealth(){
        return health;
    }

    void setHealth(int data){
        health=data;
    }

    //destructor
    ~hero(){
        cout<<"Destructor called! "<<endl;
    }

};

int main(){

    //static allocation
    hero h1;

    h1.setHealth(50);
    h1.level = 'A';

    cout<<"Health is : "<<h1.getHealth()<<endl;
    cout<<"Level is : "<<h1.level<<endl;

    //dynamically allocated
    hero *b = new hero;

    b->setHealth(80);
    b->level = 'B';

    cout<<"Health is : "<<(*b).getHealth()<<endl;
    cout<<"Level is : "<<(*b).level<<endl;

    //OR
    cout<<"Health is : "<<b->getHealth()<<endl;
    cout<<"Level is : "<<b->level<<endl;

    //destructor called for dyanamic memory
    delete b;

    return 0;
}