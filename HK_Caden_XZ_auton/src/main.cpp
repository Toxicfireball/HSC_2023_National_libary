#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h" 

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// DigitalOutA          digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;



// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.

#pragma endregion VEXcode Generated Robot Configuration

// ----------------------------------------------------------------------------
//                                                                            
//    Project:                                               
//    Author:
//    Created:
//    Configuration:        
//                                                                            
// ----------------------------------------------------------------------------

// Include the V5 Library
#include "vex.h"

// Allows for easier use of the VEX Library
using namespace vex;

motor leftfront = motor(PORT13,gearSetting::ratio18_1,true);
motor leftback = motor(PORT14,gearSetting::ratio18_1,false);
motor rightfront = motor(PORT16,gearSetting::ratio18_1,false);
motor rightback = motor(PORT12,gearSetting::ratio18_1,true);

motor topfly = motor(PORT5,gearSetting::ratio6_1,false);
motor botfly = motor(PORT6,gearSetting::ratio6_1,true);
motor intake1 = motor(PORT7,gearSetting::ratio36_1, true);

motor indexer = motor(PORT1,gearSetting::ratio18_1,true);

controller HController = controller(primary);
controller VController = controller(partner);

int maxspeed = 100;
int slwspeed =  .5 * maxspeed;
const float pi = M_PI;
float dia = 4.85;
const float degToTicks = 0.2235;

// Begin project code
void movebase(double speed){

  leftfront.spin(directionType::fwd,speed/12,voltageUnits::volt);
  leftback.spin(directionType::fwd,speed/12,voltageUnits::volt);
  rightfront.spin(directionType::fwd,speed/12,voltageUnits::volt);
  rightback.spin(directionType::fwd,speed/12,voltageUnits::volt);
}

void moveleft(double speed){

  leftfront.spin(directionType::fwd,-speed/12,voltageUnits::volt);
  leftback.spin(directionType::fwd,-speed/12,voltageUnits::volt);
  rightfront.spin(directionType::fwd,speed/12,voltageUnits::volt);
  rightback.spin(directionType::fwd,speed/12,voltageUnits::volt);
}


void mvleft(double speed){
  leftfront.spin(directionType::fwd,0,voltageUnits::volt);
  leftback.spin(directionType::fwd,0,voltageUnits::volt);

  rightfront.spin(directionType::fwd,speed/12,voltageUnits::volt);
  rightback.spin(directionType::fwd,speed/12,voltageUnits::volt);
}
void moveright(double speed){

  leftfront.spin(directionType::fwd,speed/12,voltageUnits::volt);
  leftback.spin(directionType::fwd,speed/12,voltageUnits::volt);
  rightfront.spin(directionType::fwd,-speed/12,voltageUnits::volt);
  rightback.spin(directionType::fwd,-speed/12,voltageUnits::volt);
}

void moveback(double speed){

  leftfront.spin(directionType::fwd,-speed/12,voltageUnits::volt);
  leftback.spin(directionType::fwd,-speed/12,voltageUnits::volt);
  rightfront.spin(directionType::fwd,-speed/12,voltageUnits::volt);
  rightback.spin(directionType::fwd,-speed/12,voltageUnits::volt);
}

void intake(double speed){
  intake1.spin(directionType::fwd,speed/12,voltageUnits::volt);
}

void roller(double speed){
  indexer.spin(directionType::fwd, speed/12, voltageUnits::volt);
}

void holo(){

leftfront.spin(forward,(HController.Axis3.value() + HController.Axis1.value() + HController.Axis4.value())/(100/12),volt);
rightfront.spin(forward,(HController.Axis3.value() -HController.Axis1.value() - HController.Axis4.value())/(100/12),volt);
leftback.spin(forward,(HController.Axis3.value() + HController.Axis1.value() - HController.Axis4.value())/(100/12),volt);
rightback.spin(forward, (HController.Axis3.value() - HController.Axis1.value() + HController.Axis4.value())/(100/12),volt );



}

void encfwd(float dist, int speed){


  float val = 0;
  float RV;
  float LV;
  leftfront.resetRotation();
  rightfront.resetRotation();


  while(val<dist){

    movebase(speed);
    

    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV+LV)/2; 


  }

movebase(speed*.1);
task::sleep(dist*10);
movebase(0);

}

void advfwd(float dist, int speed,int slwspeed){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
val = 0;
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
       movebase(speed);

  
      RV = rightfront.rotation(rev)*pi*dia;
      LV = leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    movebase(slwspeed);
     

    
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      movebase(-slwspeed);
     
 
    
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
  movebase(0);
  


  Brain.Screen.print("5");


}



void advfwdWintake(float dist, int speed,int slwspeed,int intkspd){

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
       movebase(speed);
       intake(intkspd);
       indexer.spin(vex::directionType::fwd,-12,voltageUnits::volt);

  
      RV = rightfront.rotation(rev)*pi*dia;
      LV = leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    movebase(slwspeed);
    intake(intkspd);
    indexer.spin(vex::directionType::fwd,-12,voltageUnits::volt);
    RV = rightfront.rotation(rev)*pi*dia;
    LV = leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      movebase(-slwspeed);
      intake(intkspd);
      indexer.spin(vex::directionType::fwd,-12,voltageUnits::volt);
     
 
    
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
  movebase(0);
  intake(0);
  


  Brain.Screen.print("5");


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
       movebase(-speed);

  
      RV = -rightfront.rotation(rev)*pi*dia;
      LV = -leftfront.rotation(rev)*pi*dia;
      val = (RV + LV)/2; 
      Brain.Screen.print("1");
      

 }

   else if(val >  dist - slwdist && dist<val ){


    Brain.Screen.clearScreen();
    movebase(-slwspeed);
     

    
    RV = -rightfront.rotation(rev)*pi*dia;
    LV = -leftfront.rotation(rev)*pi*dia;
    val = (RV + LV)/2; 
    Brain.Screen.print("3");

 }

 else if(val > dist){
      Brain.Screen.clearScreen();
      movebase(slwspeed);
     
 
    
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
  movebase(0);
  


  Brain.Screen.print("5");


}



 
void advturnleft(float degr, int speed, int slwspeed){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
val = 0;
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
       moveleft(speed);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToTicks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    moveleft(slwspeed);
    

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToTicks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      moveleft(-slwspeed);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV - LV)*degToTicks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  movebase(0);
  


  Brain.Screen.print("5");


}


 
void advoneleft(float degr, int speed, int slwspeed){

  float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
val = 0;

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
       mvleft(speed);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV)*degToTicks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    mvleft(slwspeed);
    

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV)*degToTicks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      mvleft(-slwspeed);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (RV )*degToTicks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  movebase(0);
  


  Brain.Screen.print("5");


}

void reset(int duration, int speed){


movebase(speed);
vex::task::sleep(duration);
movebase(0);





}




void advturnright(float degr, int speed, int slwspeed){

float val = 0;
float RV;
float LV;
float slwdist;
int run = 1;
val = 0;
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
       moveright(speed);

  
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToTicks;
      

 }

   else if(val >  degr - slwdist && degr<val ){


    Brain.Screen.clearScreen();
    moveright(slwspeed);
     

    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToTicks;
    Brain.Screen.print("3");

 }

 else if(val > degr){
      Brain.Screen.clearScreen();
      moveright(-slwspeed);
     
 
    
      RV = rightfront.rotation(deg);
      LV = leftfront.rotation(deg);


    


      val = (LV - RV)*degToTicks;
    Brain.Screen.print("3");

 }
 else{

   run = 0;
 }

}
  Brain.Screen.clearScreen();
  movebase(0);
  


  Brain.Screen.print("5");


}

void rollerfwd(int speed, int rollspd, int duration)
{

  movebase(speed);
  roller(rollspd);
  task::sleep(duration); 
  roller(rollspd);
  task::sleep(duration/3); 
  movebase(0);
  roller(0);
}

void shoot(float indexspd, float flyspd, int duration)
{
  topfly.spin(directionType::fwd,flyspd,voltageUnits::volt);
  botfly.spin(directionType::fwd,flyspd,voltageUnits::volt);
  task::sleep(960);
  indexer.spin(directionType::fwd,indexspd,voltageUnits::volt);
  intake1.spin(directionType::fwd,indexspd,voltageUnits::volt);
  task::sleep(duration);
  topfly.spin(directionType::fwd,0,voltageUnits::volt);
  botfly.spin(directionType::fwd,0,voltageUnits::volt);
  indexer.spin(directionType::fwd,0,voltageUnits::volt);
  intake1.spin(directionType::fwd,0,voltageUnits::volt);

  task::sleep(400);
 
  
}




void redmk1()
{
 rollerfwd(-50, -100, 900);
 vex::task::sleep(250);
 encfwd(0.7,25);
 vex::task::sleep(250);
 advturnleft(45, 50, 10);
 vex::task::sleep(250);
 advfwdWintake(7.4, 60, 10, 100);
 indexer.spin(vex::directionType::fwd,-12,voltageUnits::volt);
 intake(100);
 advrev(5, 40, 5);
 advturnright(118,50,10);
 vex::task::sleep(250);
 advfwdWintake(78, 60, 10, -100);
 advrev(12,50,10);
 advturnleft(131.4, 60,10);
 intake(100);
 vex::task::sleep(1200);
 indexer.spin(vex::directionType::fwd,0,voltageUnits::volt);
 advfwd(16.75, 40, 10);
 task::sleep(300); 

 intake(0);
 shoot(100, 100, 3600);
 advrev(10,60,10);




}
void preAutonomous(void) {
  // actions to do when the program starts
  Brain.Screen.clearScreen();
  Brain.Screen.print("pre auton code");
  DigitalOutA.set(false);
  wait(1, seconds);
}

void autonomous(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.print("autonomous code");
  // place automonous code here
  DigitalOutA.set(false);
  
  redmk1();



}

void userControl(void) {
  Brain.Screen.clearScreen();
  // place driver control in this while loop
  while (true) {
    
    rightfront.spin(vex::directionType::fwd, (HController.Axis2.value()/8.332),vex::voltageUnits::volt);
    leftfront.spin(vex::directionType::fwd,  (HController.Axis3.value()/8.333),vex::voltageUnits::volt);
    rightback.spin(vex::directionType::fwd,  (HController.Axis2.value()/8.332),vex::voltageUnits::volt);
    leftback.spin(vex::directionType::fwd, (HController.Axis3.value()/8.332),vex::voltageUnits::volt);
    
    

    if(VController.ButtonR2.pressing()==1)
    {
      topfly.spin(directionType::fwd, 12, voltageUnits::volt);
      botfly.spin(directionType::fwd, 12, voltageUnits::volt);
    }

    else if(VController.ButtonR1.pressing()==1)
    {
      topfly.spin(directionType::fwd,10.75,voltageUnits::volt);
      botfly.spin(directionType::fwd,10.75,voltageUnits::volt);
    }

    else 
    {
      topfly.spin(directionType::fwd,0,velocityUnits::pct);
      botfly.spin(directionType::fwd,0,velocityUnits::pct);
    }

    if(HController.ButtonR1.pressing()==1)
    {
      indexer.spin(directionType::fwd, 12 , voltageUnits::volt);
      intake1.spin(directionType::fwd,12,voltageUnits::volt);
    }


    else if(VController.ButtonL1.pressing()==1)
    {
      intake1.spin(directionType::fwd, 12, voltageUnits::volt);
      indexer.spin(directionType::fwd, -12, voltageUnits::volt);
      
    }
    else if(VController.ButtonL2.pressing()==1)
    {
      intake1.spin(directionType::fwd, -12, voltageUnits::volt);
      
    }


    else 
    {
      intake1.spin(directionType::fwd, 0, voltageUnits::volt);
      indexer.spin(directionType::fwd, 0, voltageUnits::volt);
    }

       if(HController.ButtonX.pressing()==1)
    {
      DigitalOutA.set(true);
      

    }
    else{
      DigitalOutA.set(false);
    }

    
    

  }

 



    vex::task::sleep(20);
  }



int main() {
  // create competition instance
  competition Competition;

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(userControl);

  // Run the pre-autonomous function.
  preAutonomous();

  // Prevent main from exiting with an infinite loop.
  while (true) {
 
    wait(1,msec);
  }
}