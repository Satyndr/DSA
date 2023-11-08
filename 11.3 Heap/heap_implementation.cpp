#include<bits/stdc++.h>

using namespace std;

class heap{

    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int value){

        size = size + 1;
        int index = size;
        arr[index] = value;

        while( index > 1){

            int parent = index/2;

            if( arr[parent] < arr[index]){
                swap( arr[parent], arr[index] );
                index = parent;
            }
            else{
                return;
            }
        }

    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<i[arr]<<" ";
        }cout<<endl;
    }

    void deleteFromHeap(){//deleting root element

        if( size == 0){
            cout<<"Nothing to delete! "<<endl;
            return ;
        }

        //put last element in first node
        arr[1] = arr[size];
        size--;//remove last element

        //take root node to its corrrect position
        int i = 1;
        while( i<size ){

            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if( leftIndex < size && arr[i] < arr[leftIndex]){
                swap( arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if( rightIndex < size && arr[i] < arr[rightIndex]){
                swap( arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return ;
            }
        }
        
    }

};

int main(){

    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();

    h.print();

    return 0;
}