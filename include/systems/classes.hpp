#pragma once 
#include "pros/adi.hpp"
#include "pros/colors.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"

class Doinker {
    public:
        Doinker(pros::adi::Pneumatics doinkerPiston);
        void down();
        void up();
        void toggle();
    private:
        pros::adi::Pneumatics doinkerPiston;
};

class Intake {
    public:
        Intake(pros::Motor stageOneMotor, pros::Motor stageTwoMotor, pros::Optical ringColorSensor);
        void in(bool stageOneOnly, bool stageTwoOnly);
        void out();
        void stop();
        void setIntakeSpeed(int voltage);
        void setSortColor(pros::Color setColor);
        void colorSort(void* param);
        pros::Color currentRingColor;
    private: 
        // the Intake class is the only class that will use these things, so it is encapsulated in the class
        pros::Optical ringColorSensor;
        pros::Motor stageOneMotor;
        pros::Motor stageTwoMotor;
        bool sortNeeded;
        int intakeSpeed;
};

class MogoArm {
    public:
        MogoArm(pros::adi::Pneumatics mogoarmPiston);
        void down();
        void up();
        void toggle();
    private:
        pros::adi::Pneumatics mogoarmPiston;
};

class MogoMech {
    public:
        MogoMech(pros::adi::Pneumatics mogomechPiston);
        void clamp();
        void release();
        void toggle();
    private:
        pros::adi::Pneumatics mogomechPiston;
        bool last_L1_state;
};

class LadyBrown { 
    public: 
        LadyBrown(pros::Motor ladybrownMotor);
        void nextState();
        void liftControl();
        void setState(int State);
    private:
        int target = 0;
        double kp = .65;
        int states[3] = {0, 325, 2000};
        int currState = 0;
        pros::Motor ladybrownMotor;
};

