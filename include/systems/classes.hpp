#pragma once 
#include "pros/adi.hpp"
#include "pros/colors.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"

extern std::string currInput;

class Intake {
    public:
        Intake(pros::Motor stageOneMotor, pros::Motor stageTwoMotor, pros::Optical ringColorSensor);
        void in(bool stageOneOnly, bool stageTwoOnly, int timer);
        void out();
        void stop();
        void setIntakeSpeed(int voltage);
        bool discardRing();
        bool discarding;
        std::string getColor();
        bool allowed;
        void intakeControl();
        float target = 0;
        double kp = 1000;
        int currState = 0;
        float states[5] = {0, 2.82, 5.5, 8.17, 10.83};
        void nextState();
        bool jam;
    private: 
        static void intakeTaskFn(void* param);
        std::unique_ptr<pros::Task> intakeTask;
        bool stageOne = false;
        bool stageTwo = false;
        bool intakeRunning = false;
        pros::Optical ringColorSensor;
        pros::Motor stageOneMotor;
        pros::Motor stageTwoMotor;
        bool sortNeeded;
        int intakeSpeed;
        int timer;
        std::string color;
};

class Arm {
    public:
        Arm(pros::adi::Pneumatics armPiston);
        void down();
        void up();
    private:
        pros::adi::Pneumatics armPiston;
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
        static int currState;
        int states[6] = {0, 270, 1000, 1800, 2300, 3000};
        bool resetting;
        bool goNext = false;
        bool moving = false;
        int target = 0;
    private:
        double kp = .65;
        pros::Motor ladybrownMotor;
        bool moveIntake;
};
