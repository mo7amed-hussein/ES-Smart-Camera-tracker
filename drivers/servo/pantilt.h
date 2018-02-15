/*
 * pantilt.h
 *
 * Created: 2/14/2018 2:17:41 PM
 *  Author: mohamed
 */ 


#ifndef PANTILT_H_
#define PANTILT_H_

#include "servo.h"

#define  PAN_PIN PD7
#define TILT_PIN PD6

#define PAN_STEP 5
#define TILT_STEP 5
//current angles
uint8_t currentPanAngle = 0;
uint8_t currentTiltAngle =0;

void initPanTilt();

void resetPan();

void resetTilt();

void moveUp();

void moveDown();

void moveLeft();

void moveRight();

void movePanToAngle(uint8_t angle);
void moveTiltToAngle(uint8_t angle);

#endif /* PANTILT_H_ */