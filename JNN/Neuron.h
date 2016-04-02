#ifndef Neuron_h
#define Neuron_h

#include "Vec2.h"
#include "NeuronRenderer.h"

#define MAX_OUTPUTS 10

class Neuron {
public:
    Neuron**            output;
    double*             weight;
    Vec2                pos;
    NeuronRenderer*     renderer;
    double              NET, T;
    int                 nOutput;
    
    Neuron();
    Neuron(Vec2 p);
    bool activate();
    void stimulate(int signal);
    void render();
    bool addOutput(Neuron* neuron, double w);
private:
    void init();
};

#endif