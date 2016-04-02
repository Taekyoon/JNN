//
//  NeuronRenderer.cpp
//  JNN
//
//  Created by 황준호 on 2016. 4. 2..
//  Copyright © 2016년 황준호. All rights reserved.
//

#include "NeuronRenderer.h"
#include "Neuron.h"

double min(double a, double b) { return a<b?a:b; }
void NeuronRenderer::render(Neuron* neuron) {
    renderSynapses(neuron);
    renderNeuron(neuron);
}
void NeuronRenderer::renderNeuron(Neuron* neuron) {
    double radius = 1.0f;
    glColor3f(0.0f, 0.0f, 1.0f);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(neuron->pos.x, neuron->pos.y);
    for(float angle=1.0f; angle<361.0f; angle+=0.1f) {
        double x2 = neuron->pos.x + sin(angle) * radius;
        double y2 = neuron->pos.y + cos(angle) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();
}
void NeuronRenderer::renderSynapses(Neuron* neuron) {
    for(int i=0;i<neuron->nOutput;i++)
        renderSynapse(neuron->pos, neuron->output[i]->pos, neuron->weight[i]);
}
void NeuronRenderer::renderSynapse(Vec2& from, Vec2& to, double weight) {
    glColor3f(0.36f, 0.36f, 0.36f);
    Vec2 vec = to - from;
    //glLineWidth(min(1.0, 1.0/(vec.size()/50.0)));
    glLineWidth(weight);
    glBegin(GL_LINES);
    glVertex2f(from.x, from.y);
    glVertex2f(to.x, to.y);
    glEnd();
}