#include <iostream>
using namespace std;
class pid
{
 public:
 float Kp,Ki,Kd; //pid constants
 float error_prev; //previous error
 float t; //time
 float max,min;//for pid overshooting
 float o;
 pid(float max1,float min1)
 {
   Kp=0.05;
   Ki=0.000001;
   Kd=0;
   max=max1;
   min=min1;
}
float calc(float setpoint,float depth)
{
 float error=setpoint-depth;
 float proportional=Kp*error;
 float i;
 i=i+error*t;
 float integral=Ki*i;
 float d=(error-error_prev)/t;
 float derivative=Kd*d;
 float o=proportional+integral+derivative;
//regulation of overshoots
 if(o>max)
 o=max;
 else if(o<min)
 o=min;
error_prev=error;

return o;
}
~pid()
{}
};

   
 

 

