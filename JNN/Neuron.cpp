#include "Neuron.h"
Neuron::Neuron() { init(); }
Neuron::Neuron(Vec2 p):pos(p) { init(); }
double f(double x) {
    return 1/(1+exp(-x));
}
bool Neuron::activate() {
    if(f(NET)>=T) {
        for(int i=0;i<nOutput;i++) {

        }
        return true;
    }
    return false;
}
void Neuron::stimulate(int signal) {
    NET += signal;

}
void Neuron::render() {
    renderer->render(this);
}
void Neuron::init() {
    renderer = new NeuronRenderer();
    output = new Neuron*[MAX_OUTPUTS];
    weight = new double[MAX_OUTPUTS];
    nOutput = 0;
}
bool Neuron::addOutput(Neuron* neuron, double w) {
    if(nOutput == MAX_OUTPUTS) return false;
    output[nOutput] = neuron;
    weight[nOutput] = w;
    nOutput++;
    
    return true;
}