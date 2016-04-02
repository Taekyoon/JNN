//
//  JNNBuilder.h
//  JNN
//
//  Created by 황준호 on 2016. 4. 2..
//  Copyright © 2016년 황준호. All rights reserved.
//

#ifndef JNNBuilder_h
#define JNNBuilder_h

#include <stdlib.h>
#include <queue>
#include <vector>
#include "Vec2.h"
#include "Neuron.h"

class JNN;
class JNNBuilder {
public:
    const int MAX_NEURON_COUNT = 500;
    void buildJNN(JNN* jnn); // Returns created neuron count
    int createSpreadNeurons(Neuron*** neurons, Vec2 p1, Vec2 p2, double radius, double lambda); // Returns created neuron count
    void createStraightNeurons(Neuron*** neurons, Vec2 p1, Vec2 p2, int nCount);
    void makeRandomSynapses(Neuron** neurons, int nCount, int piv, double radius);
    void makeSynapse(Neuron* from, Neuron* to);
    Neuron* createNeuron(Vec2 pos);
};

#endif /* JNNBuilder_h */