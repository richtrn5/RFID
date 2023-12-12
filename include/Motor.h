#include "Arduino.h"

class Motor
{
private:
    int CW;
    int CCW;
    bool lockState = false;
public:
    Motor(){}
    Motor(int w, int c): CW(w), CCW(c){}
    ~Motor(){}
    void turnCCW(){ // unlock
            digitalWrite(CCW,HIGH); //Motor runs clockwise//
            delay(5000); //for 5 second//
            digitalWrite(CCW,LOW); //Motor runs clockwise//
            lockState = false;
            delay(250); // end delay
        
    }
    void turnCW(){ // lock
            digitalWrite(CW,HIGH);
            delay(5000);
            digitalWrite(CW,LOW);
            lockState = true;
            delay(250);
        
    }
};


        