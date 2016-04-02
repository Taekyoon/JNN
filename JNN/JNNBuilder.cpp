//
//  JNNBuilder.cpp
//  JNN
//
//  Created by 황준호 on 2016. 4. 2..
//  Copyright © 2016년 황준호. All rights reserved.
//

#include "JNNBuilder.h"
#include "JNN.h"
int min(int a, int b) { return (a<b?a:b); }
void JNNBuilder::buildJNN(JNN* jnn) {
    jnn->nInput = 10;
    createStraightNeurons(&(jnn->input), Vec2(20, 200), Vec2(20, 600), jnn->nInput);
    jnn->nHidden = createSpreadNeurons(&(jnn->hidden), Vec2(150.0, 400.0), Vec2(1000.0, 400.0), 200.0, 0.1);
    makeRandomSynapses(jnn->hidden, jnn->nHidden, 0, 150.0);
}
int JNNBuilder::createSpreadNeurons(Neuron*** neurons, Vec2 p1, Vec2 p2, double radius, double lambda) {
    (*neurons) = new Neuron*[MAX_NEURON_COUNT];
    // TODO: refactoring
    Vec2 v = p2 - p1;
    int N = min(lambda * v.size(), MAX_NEURON_COUNT), nCount = 0;
    for(int i=1;i<=N;i++) {
        Vec2 p = p1 + v * ((double)i / N);
        double xr = (int)(rand()%10000) * radius / 10000;
        double theta = (int)(rand()%10000) * 2 * 3.14159 / 10000;
        Vec2 r = Vec2(xr * cos(theta), xr * sin(theta));
        (*neurons)[nCount++]=createNeuron(p+r);
    }
    return nCount;
}
void JNNBuilder::createStraightNeurons(Neuron*** neurons, Vec2 p1, Vec2 p2, int nCount) {
    (*neurons) = new Neuron*[MAX_NEURON_COUNT];
    Vec2 v = p2 - p1;
    for(int i=1;i<=nCount;i++) {
        Vec2 p = p1 + v * ((double)i / nCount);
        (*neurons)[i-1]=createNeuron(p);
    }
}
void JNNBuilder::makeRandomSynapses(Neuron** neurons, int nCount, int piv, double radius) {
    std::queue<int> q;
    std::vector<bool> chk(nCount,0);
    std::vector< std::vector<bool> > con(nCount,std::vector<bool>(nCount,0));
    q.push(piv), chk[piv]=1;
    
    while(!q.empty()) {
        int v=q.front(); q.pop();
        for(int i=0;i<nCount;i++) {
            Vec2 vec= neurons[i]->pos - neurons[v]->pos;
            if(vec.size()<radius) {
                double prob = (int)(rand()%10000) / 10000.0;
                if(!chk[i] || (prob>=0.7 && !con[v][i])) {
                    con[v][i]=con[i][v]=1;
                    makeSynapse(neurons[v], neurons[i]);
                }
                if(!chk[i]) {
                    chk[i]=1;
                    q.push(i);
                }
            }
        }
    }
}
Neuron* JNNBuilder::createNeuron(Vec2 pos) {
    Neuron* newNeuron = new Neuron(pos);
    return newNeuron;
}
void JNNBuilder::makeSynapse(Neuron* from, Neuron* to) {
    from->addOutput(to, 0.1);
}