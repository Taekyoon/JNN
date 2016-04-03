//
//  NeuronRenderer.h
//  JNN
//
//  Created by 황준호 on 2016. 4. 2..
//  Copyright © 2016년 황준호. All rights reserved.
//

#ifndef NeuronRenderer_h
#define NeuronRenderer_h

#include "OpenGL.h"
#include "Vec2.h"
#include <math.h>

class Neuron;
class NeuronRenderer {
public:
    NeuronRenderer();
    void    render(Neuron* neuron);
private:
    void    renderNeuron(Neuron* neuron);
    void    renderSynapses(Neuron* neuron);
    void    renderSynapse(Vec2& from, Vec2& to, double weight);
};

#endif /* NeuronRenderer_h */
