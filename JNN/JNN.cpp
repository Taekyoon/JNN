#include "JNN.h"
#include <stdio.h>
void JNN::init() {
    builder = new JNNBuilder();
    nInput = nHidden = 0;
    buildJNN();
}
void JNN::update() {

}
void JNN::render() {
    for(int i=0;i<nInput;i++)
        input[i]->render();
    for(int i=0;i<nHidden;i++)
        hidden[i]->render();
}
void JNN::buildJNN() {
    builder->buildJNN(this);
    printf("Input count is %d.\n", nInput);
    printf("Hidden count is %d.\n", nHidden);
}