#include "JNN.h"
#include <stdio.h>
JNN::JNN() {}
void JNN::init() {
    builder = new JNNBuilder();
    nInput = nHidden = 0;
    buildJNN();
    for(int i=0;i<nInput;i++) {
        input[i]->addOutput(hidden[i]);
    }
}
void JNN::update() {
    for(int i=0;i<nInput;i++)
        input[i]->activate();
    for(int i=0;i<nHidden;i++)
        hidden[i]->activate();
    for(int i=0;i<nInput;i++)
        input[i]->degenerate();
    for(int i=0;i<nHidden;i++)
        hidden[i]->degenerate();
    for(int i=0;i<nInput;i++)
        input[i]->release();
    for(int i=0;i<nHidden;i++)
        hidden[i]->release();
}
void JNN::render() {
    for(int i=0;i<nInput;i++)
        input[i]->render();
    for(int i=0;i<nHidden;i++)
        hidden[i]->render();
}
void JNN::keyEvent(int key) {
    switch(key) {
        case 'a':
            input[0]->stimulate(1.0);
            break;
        case 's':
            input[1]->stimulate(1.0);
            break;
        case 'd':
            input[2]->stimulate(1.0);
            break;
        case 'f':
            input[3]->stimulate(1.0);
            break;
        case 'g':
            input[4]->stimulate(1.0);
            break;
        case 'h':
            input[5]->stimulate(1.0);
            break;
        case 'j':
            input[6]->stimulate(1.0);
            break;
        case 'k':
            input[7]->stimulate(1.0);
            break;
        case 'l':
            for(int i=0;i<nInput;i++)
                input[i]->stimulate(1.0);
            break;
    }
}
void JNN::buildJNN() {
    builder->buildJNN(this);
    printf("Input count is %d.\n", nInput);
    printf("Hidden count is %d.\n", nHidden);
}