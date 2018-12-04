//
// Created by naveenkh on 12/4/18.
//

#ifndef PROGRAM_SAMPLES_RINGBUFFER_H
#define PROGRAM_SAMPLES_RINGBUFFER_H

#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
class RingBuffer {

private:
    struct RB {
        size_t sz;
        T *buffer;
        T *head,*tail;
        T *begin, *end;
        size_t count;
        RB(size_t sz) : sz(sz), buffer(new T[sz]),head(buffer), tail(buffer), begin(buffer), end(buffer+sz-1),count(0) {};
    };


private:
    RB *ringbuf;

public:
    RingBuffer(size_t sz){
        ringbuf = new RB(sz);
    }

    int PushIntoBuffer(T elem);
    T PopFromBuffer();
    bool Full();
    bool Empty();
    void DisplayBuffer();

};
#endif //PROGRAM_SAMPLES_RINGBUFFER_H
