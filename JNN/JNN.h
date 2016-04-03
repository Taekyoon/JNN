#ifndef JNN_h
#define JNN_h

#include "Neuron.h"
#include "JNNBuilder.h"

class JNN {
public:
    Neuron          **input, **hidden;
    JNNBuilder*     builder;
    int             nInput, nHidden;
    JNN();
    void            init();
    void            update();
    void            render();
    void            keyEvent(int key);
private:
    void            buildJNN();
};

#endif