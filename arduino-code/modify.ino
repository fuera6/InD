#include<Servo.h>
#include<Stepper.h>
Stepper ste1(360,13,11,12,10);
Stepper ste2(360,9,7,8,6);
Servo hor;
int h=90;
Servo ver;
int v=90;
void setup() {
  hor.attach(5);
  ver.attach(3);
  hor.write(h);
  ver.write(v);
  ste1.setSpeed(18);
  ste2.setSpeed(18);
}

void loop() {
  int lt=analogRead(A0);
  int rt=analogRead(A1);
  int ld=analogRead(A2);
  int rd=analogRead(A3);
  int dtime=50;
  int tol=50;
  int avl=(lt+ld)/2;
  int avr=(rt+rd)/2;
  int avt=(lt+rt)/2;
  int avd=(ld+rd)/2;
  int dv=avt-avd;
  int dh=avl-avr;
  if(-1*tol>dh||dh>tol)
  {
    if(avl>avr)
    {
      ++h;
      ste2.step(20);
      if(h<0)
      {
        h=0;
      }
    }
    else if(avl<avr)
    {
      --h;
      ste2.step(-20);
      if(h>180)
      {
        h=180;
      }
    }
    else;
    hor.write(h);
  }
  if((-1*tol>dv||dv>tol)&&(tol*-1<dh&&dh<tol))
  {
    if(avt>avd)
    {
      --v;
      ste1.step(-20);
      ste2.step(20);
      if(v>170)
      {
        --v;
      }
    }
    else if(avt<avd)
    {
      ++v;
      ste1.step(20);
      ste2.step(-20);
      if(v<10)
      {
        ++v;
      }
    }
  }
  delay(dtime);
}
