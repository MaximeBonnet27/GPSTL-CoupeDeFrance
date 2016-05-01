#include "FeedbackCurrent.h"

void FeedbackCurrent::init() {
    this->left = new AnalogIn(PA_0);
    this->right = new AnalogIn(PA_1);
}

float FeedbackCurrent::read_right() {
    return this->right->read();
}

float FeedbackCurrent::read_left() {
    return this->left->read();
}
