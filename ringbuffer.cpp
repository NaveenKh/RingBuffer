//
// Created by naveenkh on 12/4/18.
//

#include "ringbuffer.h"



template<typename T>
int RingBuffer <T>:: PushIntoBuffer(T elem) {

    if(Full()) {
        cout<< "Error!! Buffer is full" <<endl;
        return -1;
    }

    *(ringbuf->head) = elem;
    ringbuf->count++;
    if ((ringbuf->head + 1) == (ringbuf->end+1)) {
        ringbuf->head = ringbuf->begin;
    } else {
        ringbuf->head = ringbuf->head+1;
    }
    return 0;
}

template<typename T>
T RingBuffer <T>:: PopFromBuffer() {

    if(Empty()) {
        cout<< "Error!! Buffer is empty" <<endl;
        return -1;
    }

    T temp = *(ringbuf->tail);
    *(ringbuf->tail) = 0;
    cout <<"Popped element " << temp <<endl;
    ringbuf->count--;
    if ((ringbuf->tail + 1) == (ringbuf->end+1)) {
        ringbuf->tail = ringbuf->begin;
    } else {
        ringbuf->tail = ringbuf->tail+1;
    }
    return temp;
}

template<typename T>
bool RingBuffer <T>:: Full() {
    return ((ringbuf->sz == ringbuf->count)?1:0);
}

template<typename T>
bool RingBuffer <T>:: Empty() {
    return ((ringbuf->count == 0)?1:0);
}

template<typename T>
void RingBuffer <T>:: DisplayBuffer() {
    if(Empty()) {
        cout <<" The buffer is empty "<<endl;
        return;
    }
    T *temp = ringbuf->begin;
    cout<< "****************************************************************************************"<<endl;
    while ( temp!= ringbuf->end+1) {
        cout << *temp <<endl;
        temp = temp+1;
    }
    cout<< "****************************************************************************************"<<endl;
}

int main() {
    RingBuffer <int>rb = RingBuffer<int>(10);
    int useroption;
    while(1){
        cout << "#########################Welcome to Skip List##########################\n"
                  << "1. Push\n2. Pop\n3. Display\n"<< "Please press an option:: "<<std::endl;
        cin >>useroption;
        int key;
        switch(useroption){
            case 1: cout<<" Enter the element to insert" <<std::endl;
                cin >> key;
                rb.PushIntoBuffer(key);
                break;
            case 2: cout<<" Popping element" <<std::endl;
                rb.PopFromBuffer();
                break;
            case 3: cout<<" Displaying the buffer elements " <<std::endl;
                rb.DisplayBuffer();
                break;
        }
    }
}