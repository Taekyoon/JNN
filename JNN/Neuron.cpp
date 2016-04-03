#include "Neuron.h"
Neuron::Neuron() { init(); }
Neuron::Neuron(Vec2 p):pos(p) { init(); }
double f(double x) {
    return 1/(1+exp(-x));
}
bool Neuron::activate() {
    if(f(NET)>=T && !activated) {
        activated = true;
        lastActivated = clock();
        return true;
    }
    return false;
}
void Neuron::stimulate(double signal) {
    if(!activated)
        NET += signal;
}
void Neuron::degenerate() {
    for(int i=0;i<nOutput;i++) {
        if(!activated && !output[i]->activated)
            weight[i] = fmax(weight[i] - degen[i], 0.0);
    }
}
void Neuron::grow(Neuron** neurons) {
    
}
void Neuron::release() {
    if(activated && clock()-lastActivated>=10) {
        double alpha = 0.5;
        for(int i=0;i<nOutput;i++) {
            output[i]->stimulate(f(NET) * weight[i]);
            weight[i] = fmin(weight[i] + alpha * f(NET), 1.0);
            degen[i] -= degen[i] * degenRate;
        }
        activated = false;
        NET = -2.0;
    }
}
void Neuron::render() {
    renderer->render(this);
}
void Neuron::init() {
    renderer = new NeuronRenderer();
    output = new Neuron*[MAX_OUTPUTS];
    weight = new double[MAX_OUTPUTS];
    degen = new double[MAX_OUTPUTS];
    degenRate = 0.001;
    lastConnected = new long[MAX_OUTPUTS];
    NET = -2.0;
    nOutput = 0;
    activated = false;
    T=0.5;
}
bool Neuron::addOutput(Neuron* neuron, double w) {
    if(nOutput == MAX_OUTPUTS) return false;
    output[nOutput] = neuron;
    weight[nOutput] = w;
    degen[nOutput] = 0.01f;
    lastConnected[nOutput] = clock();
    nOutput++;
    return true;
}
bool Neuron::addOutput(Neuron* neuron) {
    return addOutput(neuron, (int)(rand()%10)/100.0);
}