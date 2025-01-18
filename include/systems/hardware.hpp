#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"
#include "systems/classes.hpp"


// HARDWARE CONSTRUCTION

// Controller
inline pros::Controller Master(pros::E_CONTROLLER_MASTER);
void driveControl();
void intakeControl();
void mogoControl();
void doinkerControl();
void ladybrownControl();

// Doinker
inline pros::adi::Pneumatics doinkerPiston(2, false);
inline Doinker Doinker(doinkerPiston);

// Mogo Mech
inline pros::adi::Pneumatics mogomechPiston(1, false);
inline MogoMech MogoMech(mogomechPiston);

// Mogo Arm (for goal rush)
inline pros::adi::Pneumatics mogoarmPiston(3, false);
inline MogoArm MogoArm(mogoarmPiston);

// Intake 
inline pros::Motor stageOneMotor(15, pros::MotorGears::blue, pros::v5::MotorUnits::rotations);
inline pros::Motor stageTwoMotor(1, pros::MotorGears::blue, pros::v5::MotorUnits::rotations);
inline pros::Optical ringColorSensor(7);
inline Intake Intake(stageOneMotor, stageTwoMotor, ringColorSensor);

// Lady Brown
inline pros::Motor ladybrownMotor(12, pros::MotorGears::green, pros::v5::MotorEncoderUnits::counts);

// Sensors & Trackers
inline pros::Imu imu(5);
inline pros::Rotation verticalTracker(20);                                                    
inline pros::Rotation horizontalTracker(-18);   
inline lemlib::TrackingWheel horizontal(&horizontalTracker, lemlib::Omniwheel::NEW_2, -0.5); 
inline lemlib::TrackingWheel vertical(&verticalTracker, lemlib::Omniwheel::NEW_275, -5.5);

// Chassis
inline pros::MotorGroup leftMotors({-19, -3, 2}, pros::MotorGearset::blue);     // front, top, bottom (left)
inline pros::MotorGroup rightMotors({11, 9, -8}, pros::MotorGearset::blue);     // front, top, bottom (right)

// LemLib Drive Train Settings
inline lemlib::Drivetrain driveTrain(
    &leftMotors, // left motor group
    &rightMotors, // right motor group
    11.25, // set the trackWidth variable to our LemLib track width
    lemlib::Omniwheel::NEW_325, // set the WheelSize variable to our LemLib wheel size
    450, // set the DriveRPM variable to our LemLib RPM
    2 // set the HorzDrift variable to our horizontal drift tracking in LemLib
);

// Lateral PID Controller
inline lemlib::ControllerSettings linearController(
    8.5,  // proportional gain (kP)
    0.6,  // integral gain (kI)
    40, // derivative gain (kD)
    0.5, // anti windup
    1, // small error range, in inches 1
    100, // small error range timeout, in milliseconds 100
    3, // large error range, in inches 3
    500, // large error range timeout, in milliseconds 500
    0 // maximum acceleration (slew) 20
);

// ANGULAR PID CONTROLLER
inline lemlib::ControllerSettings angularController(
    8,// proportional gain (kP)
    1,   // integral gain (kI) 2
    67, // derivative gain (kD) old: 6x
    .3,   // anti windup
    0,    // small error range, in degrees
    0,    // small error range timeout, in milliseconds
    0,    // large error range, in degrees
    0,    // large error range timeout, in milliseconds
    0     // maximum acceleration (slew)
);

// TROTTLE INPUT CURVE
inline lemlib::ExpoDriveCurve throttleCurve(
    3,    // joystick deadband out of 127
    10,   // minimum output where drivetrain will move out of 127
    1.019 // expo curve gain
);

// STEER INPUT CURVE
inline lemlib::ExpoDriveCurve steerCurve(
    3,    // joystick deadband out of 127
    10,   // minimum output where drivetrain will move out of 127
    1.019 // expo curve gain
);

// ODOMETRY
inline lemlib::OdomSensors sensors(
    &vertical,   // vertical tracking wheel
    nullptr,     // vertical tracking wheel 2, set to nullptr as we don't have a second one
    &horizontal, // horizontal tracking wheel
    nullptr,     // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    &imu         // inertial sensor
);

// DRIVETRAIN
inline lemlib::Chassis chassis(
    driveTrain, 
    linearController, 
    angularController, 
    sensors, 
    &throttleCurve, 
    &steerCurve
);