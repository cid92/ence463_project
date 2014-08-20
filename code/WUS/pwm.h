#ifndef PWM_H_
#define PWM_H_

extern void initPWM(int howmanyPWM);

extern void changeDutyPWM(int whichPWM , int newDuty);

extern void changeFrequrencyPWM(int whichPWMgen , int newFreq);

extern void startPWM(int whichPWM);

extern void stopPWM (int whichPWM);
