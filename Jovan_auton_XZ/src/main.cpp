
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

motor cat1 = motor(PORT11,gearSetting::ratio36_1,false);
motor intake1 = motor(PORT20, gearSetting::ratio18_1, true);
motor leftfront = motor(PORT3, gearSetting::ratio18_1, true);
motor leftmid =  motor(PORT2, gearSetting::ratio18_1, true);
motor leftback = motor(PORT1, gearSetting::ratio18_1, false);
motor rightfront = motor(PORT10, gearSetting::ratio18_1,false);
motor rightmid = motor(PORT9, gearSetting::ratio18_1, false);
motor rightback = motor(PORT8, gearSetting::ratio18_1, true);

controller H = controller(primary);
controller V = controller(partner);




void autocata(){


if (H.ButtonR2.pressing() == 1){
  cat1.spin(vex::directionType::fwd, 12, vex::voltageUnits::volt);
  vex::task::sleep(700);
  cat1.spin(fwd, 0, vex::voltageUnits::volt);
  vex::task::sleep(300);


  while (LimitSwitchB.pressing() == 0){

    cat1.spin(vex::directionType::fwd, 12, vex::voltageUnits::volt);
    leftfront.spin(vex::directionType::fwd, H.Axis3.value()/(100/12),vex::voltageUnits::volt);
    leftmid.spin(vex::directionType::fwd, H.Axis3.value()/(100/12),vex::voltageUnits::volt);
    leftback.spin(vex::directionType::fwd, H.Axis3.value()/(100/12),vex::voltageUnits::volt);
    rightfront.spin(vex::directionType::fwd, H.Axis2.value()/(100/12),vex::voltageUnits::volt);
    rightmid.spin(vex::directionType::fwd, H.Axis2.value()/(100/12),vex::voltageUnits::volt);
    rightback.spin(vex::directionType::fwd, H.Axis2.value()/(100/12),vex::voltageUnits::volt);
  }
  cat1.stop();
}

}

void workinglimitcat(){

    if(V.ButtonR1.pressing()==1 ){
      cat1.spin(vex::directionType::fwd,12,vex::voltageUnits::volt);



    }
    else if (LimitSwitchB.pressing()==1)
    {

      cat1.spin(vex::directionType::fwd,0,vex::voltageUnits::volt);


    }
    

    else if (V.ButtonR2.pressing() == 1)
    {

      cat1.spin(vex::directionType::fwd,12,vex::voltageUnits::volt);


    }
    else if (V.ButtonR1.pressing() == 0 && V.ButtonR2.pressing() ==0){

      cat1.stop();
    }



}



const float pi = M_PI;
// Include the V5 Library
#include "vex.h"
float dia = 4.85;

const float degToticks = 0.2235;
// Allows for easier use of the VEX Library

void driver(){




leftfront.spin(vex::directionType::fwd,H.Axis3.value(),vex::velocityUnits::pct);
rightfront.spin(vex::directionType::fwd,H.Axis2.value(),vex::velocityUnits::pct);


}
using namespace vex;


void mvbase(int speed){

   leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
   rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);


}


void baseleft(int speed){


    
    leftfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);



}

void baseright(int speed){


    
    leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);



}

void holoright(int speed){


    leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);


}

void hololeft(int speed){


    leftfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);


}

void intake(int speed){

  intake1.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);






}



void mvdfwed(int time, int speed){

   leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);

   vex::task::sleep(time);
   leftfront.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);  
   rightfront.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);


}


void shoot(){


  cat1.spin(vex::directionType::fwd, 12, vex::voltageUnits::volt);
  vex::task::sleep(900);
  cat1.spin(vex::directionType::fwd, 0, vex::voltageUnits::volt);
  vex::task::sleep(300);

  while (LimitSwitchB.pressing() == 0){

    cat1.spin(vex::directionType::fwd, 12, vex::voltageUnits::volt);

  }
  cat1.stop();


}









void encfwd(float dist, int speed){


  float val = 0;
  float RV;
  float LV;
  leftfront.resetRotation();
  rightfront.resetRotation();


  while(val<dist){

    mvbase(speed);
    
 
    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV+LV)/2; 


  }

mvbase(speed*.1);
task::sleep(100);
mvbase(0);

}



void intkfwd(int duration, int speed, int intspd){

mvbase(speed);
intake(intspd);
vex::task::sleep(duration);
mvbase(0);
intake(0);


}







void advfwd(float dist, int speed,int slwspeed){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();
if (dist < 30){


slwdist = dist/5;


}
else if(dist > 30){

slwdist = dist/8;

}

while (run == 1){



 if(val <= dist - slwdist  ){
       Brain.Screen.clearScreen();
       mvbase(speed);

  
      RV = rightfront.rotation(rev)*pi*dia;
      LV = leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist > val ){


    Brain.Screen.clearScreen();
    mvbase(slwspeed);
     

    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      mvbase(-slwspeed);
     
 
    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");


}



void advfwdWintake(int dist, int speed,int slwspeed,int intkspd){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (dist < 30){


slwdist = dist/5;


}
else if(dist > 30){

slwdist = dist/8;

}

while (run == 1){



 if(val< dist - slwdist  ){
       Brain.Screen.clearScreen();
       mvbase(speed);
       intake(intkspd);

  
      RV = rightfront.rotation(rev)*pi*dia;
      LV = leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    mvbase(slwspeed);
    intake(intkspd);
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      mvbase(-slwspeed);
      intake(intkspd);
     
 
    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  intake(0);
  


  Brain.Screen.print("5");


}


void rightsidemv(int dist, int speed){
   int x  = dist/10;
   rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   vex::task::sleep(x*8);
   rightfront.spin(vex::directionType::fwd,speed/6,vex::velocityUnits::pct);
   rightback.spin(vex::directionType::fwd,speed/6,vex::velocityUnits::pct);
   vex::task::sleep(x*2);
   rightfront.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);
   rightback.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);





}


void leftsidemv(int dist, int speed){
   int x  = dist/10;
   leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
   vex::task::sleep(x*8);
   leftfront.spin(vex::directionType::fwd,speed/6,vex::velocityUnits::pct);
   leftback.spin(vex::directionType::fwd,speed/6,vex::velocityUnits::pct);
   vex::task::sleep(x*2);
   leftfront.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);
   leftback.spin(vex::directionType::fwd,0,vex::velocityUnits::pct);





}


void advrev(double dist, int speed,int slwspeed){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();

if (dist < 30){


slwdist = dist/5;


}
else if(dist > 30){

slwdist = dist/8;

}

while (run == 1){



 if(val< dist - slwdist  ){
       Brain.Screen.clearScreen();
       mvbase(-speed);

  
      RV = -rightfront.rotation(rev)*pi*dia;
      LV = -leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    mvbase(-slwspeed);
     

    
    RV = -rightfront.rotation(rev)*pi*dia;
    LV = -leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      mvbase(slwspeed);
     
 
    
    RV = -rightfront.rotation(rev)*pi*dia;
    LV = -leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");


}




 void encturnright (int dist, float speed){


  float val = 0;
  float LV;
  float RV;
  
  leftfront.resetRotation();
  rightfront.resetRotation();

     
  while(val<dist){

    

    
    leftfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);
    wait(10,msec);

    
    RV = rightfront.rotation(deg);
    LV = leftfront.rotation(deg);


    


    val = -(RV - LV)*degToticks;
    Brain.Screen.print(val);

    

  }

  
 leftfront.spin(vex::directionType::fwd,speed/10,vex::velocityUnits::pct);  
 rightfront.spin(vex::directionType::fwd,-speed/10,vex::velocityUnits::pct);
 leftback.spin(vex::directionType::fwd,speed/10,vex::velocityUnits::pct);  
 rightback.spin(vex::directionType::fwd,-speed/10,vex::velocityUnits::pct);
 task::sleep(50);
 mvbase(0);



}

 void encturnleft (int dist, float speed){


  float val = 0;
  float LV;
  float RV;
  
  leftfront.resetRotation();
  rightfront.resetRotation();

     
  while(val<dist){

    

    
    leftfront.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightfront.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd,-speed,vex::velocityUnits::pct);  
    rightback.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
    wait(10,msec);

    
    RV = rightfront.rotation(deg);
    LV = leftfront.rotation(deg);


    


    val = (RV - LV)*degToticks;
    Brain.Screen.print(val);

    

  }

  
 leftfront.spin(vex::directionType::fwd,-speed/10,vex::velocityUnits::pct);  
 rightfront.spin(vex::directionType::fwd,speed/10,vex::velocityUnits::pct);
 leftback.spin(vex::directionType::fwd,-speed/10,vex::velocityUnits::pct);  
 rightback.spin(vex::directionType::fwd,speed/10,vex::velocityUnits::pct);
 task::sleep(60);
 mvbase(0);



}
 
void advturnleft(float degr, int speed, int slwspeed){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (degr <= 30){


slwdist = degr/5;


}
else if(degr > 30){

slwdist = degr/8;

}

while (run == 1){



 if(val< degr - slwdist  ){
       Brain.Screen.clearScreen();
       baseleft(speed);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    baseleft(slwspeed);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      baseleft(-slwspeed);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");


}

void reset(int duration, int speed){


mvbase(speed);
vex::task::sleep(duration);
mvbase(0);





}


void advturnleftWintake(float degr, int speed, int slwspeed,int intkspd){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (degr < 30){


slwdist = degr/5;


}
else if(degr > 30){

slwdist = degr/8;

}

while (run == 1){



 if(val< degr - slwdist  ){
       Brain.Screen.clearScreen();
       baseleft(speed);
       intake(intkspd);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    baseleft(slwspeed);
    intake(intkspd);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      baseleft(-slwspeed);
      intake(intkspd);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToticks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  intake(0);
  


  Brain.Screen.print("5");


}


void intakefwd(int duration, int basespeed, int intkspd){

 intake(intkspd);
 mvbase(basespeed);
 vex::task::sleep(duration);
 intake(0);
 mvbase(basespeed/10);
 vex::task::sleep(duration/10);
 mvbase(0);




}

void advturnright(float degr, int speed, int slwspeed){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();

 
if (degr <= 30){


slwdist = degr/5;


}
else if(degr > 30){

slwdist = degr/8;

}

while (run == 1){



 if(val< degr - slwdist  ){
       Brain.Screen.clearScreen();
       baseright(speed);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    baseright(slwspeed);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      baseright(-slwspeed);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  


  Brain.Screen.print("5");


}

void shoot(int intime, float flyspeed){




}
void flywheel(float flyspeed){

}


void advturnrightWintake(float degr, int speed, int slwspeed, int intakespd){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
leftfront.resetRotation();
rightfront.resetRotation();


if (degr < 30){


slwdist = degr/5;


}
else if(degr > 30){

slwdist = degr/8;

}

while (run == 1){



 if(val< degr - slwdist  ){
       Brain.Screen.clearScreen();
       baseright(speed);
       intake(intakespd);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    baseright(slwspeed);
    intake(intakespd);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);
      


    


      val = (LV - RV)*degToticks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      baseright(-slwspeed);
      intake(intakespd);
      

     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToticks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  mvbase(0);
  intake(0);
  


  Brain.Screen.print("5");


}
void timerleft(int duration, int speed){

int x = duration/100;
baseleft(speed);
vex::task::sleep(x*90);
baseleft(speed/10);
vex::task::sleep(x*10);
baseleft(0);


}


void autonbluemk1(){

 advrev(34.6, 67, 14);
 vex::task::sleep(200);
 advturnright(26,56,10);
 vex::task::sleep(600);
 shoot();
 vex::task::sleep(200);
 advturnleft(45, 80, 15);
 vex::task::sleep(200);
 advfwd(36, 70, 10);
 vex::task::sleep(200);
 advturnright(45, 60,15);
 vex::task::sleep(200);
 intakefwd(700, 60, -85);

}

void autonbluemk2(){

intakefwd(500, 60, -85);
vex::task::sleep(200);
advrev(4, 50, 10);
vex::task::sleep(200);
advturnright(38, 60, 10);
vex::task::sleep(200);
advrev(46, 65, 12);
vex::task::sleep(200);
advturnleft(90,50, 10);
vex::task::sleep(250);
advrev(5.25, 55, 5);
vex::task::sleep(400);
shoot();




}

void autonredmk1(){

 advrev(34, 67, 14);
 vex::task::sleep(200);
 advturnleft(40,56,10);
 vex::task::sleep(200);
 advfwd(29.5, 70, 10);
 vex::task::sleep(200);
 advturnright(26, 60,15);
 vex::task::sleep(200);
 intakefwd(800, 60, -85);

}

void autonredmk2(){

intakefwd(500, 60, -85);
vex::task::sleep(200);
advrev(4, 50, 10);
vex::task::sleep(200);
advturnright(35, 60, 10);
vex::task::sleep(200);
advrev(48, 65, 12);
vex::task::sleep(200);
advturnleft(94,50, 10);
vex::task::sleep(600);
advrev(4, 55, 5);
vex::task::sleep(600);
shoot();




}

void redmk1()
{
  intakefwd(850,100,100);

}

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  autonredmk1();
  //redmk1(); 
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
    vexcodeInit();
  while(1==1){

    leftfront.spin(vex::directionType::fwd, H.Axis3.value()/(100/12),vex::voltageUnits::volt);
    leftmid.spin(vex::directionType::fwd, H.Axis3.value()/(100/12),vex::voltageUnits::volt);
    leftback.spin(vex::directionType::fwd, H.Axis3.value()/(100/12),vex::voltageUnits::volt);
    rightfront.spin(vex::directionType::fwd, H.Axis2.value()/(100/12),vex::voltageUnits::volt);
    rightmid.spin(vex::directionType::fwd, H.Axis2.value()/(100/12),vex::voltageUnits::volt);
    rightback.spin(vex::directionType::fwd, H.Axis2.value()/(100/12),vex::voltageUnits::volt);
    intake1.spin(directionType::fwd,V.Axis3.value(),voltageUnits::volt);
    autocata();


    if(V.ButtonA.pressing()==1)
    {
      DigitalOutC.set(true);
    }

    else
    {
      DigitalOutC.set(false);

    }
    
    



     

  }

}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
