#ifndef Neuron_h
#define Neuron_h

#include "Vec2.h"
#include "NeuronRenderer.h"
#include <stdlib.h>
#include <time.h>

#define MAX_OUTPUTS 10

class Neuron {
public:
    Neuron**            output;
    double*             weight;
    long*               lastConnected;
    Vec2                pos;
    NeuronRenderer*     renderer;
    double              NET, T;
    double              *degen, degenRate; // Degeneration value
    int                 nOutput;
    bool                activated;
    long                lastActivated;
    
    Neuron();
    Neuron(Vec2 p);
    bool                activate();
    void                stimulate(double signal);
    void                degenerate();
    void                grow(Neuron** neurons);
    void                render();
    void                release();
    bool                addOutput(Neuron* neuron, double w);
    bool                addOutput(Neuron* neuron);
private:
    void init();
};

#endif