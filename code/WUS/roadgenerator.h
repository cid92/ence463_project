#ifndef ROADGENERATOR_H_
#define ROADGENERATOR_H_

struct RoadSurf{
	float dzR; 
	float vzR;
	}; 

struct Suspension {
	float zS; 
	float zU;
	float zSU;
	};


extern float returnCurrSpeed(void);

extern RoadSurf roadSurfGen(float currSpeed, int roadType, float tStep);

extern Suspension sensorOutput(RoadSurf roadValues);

extern void speedPulse(float currSpeed);
