#include <units/base.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/geometry/Translation2d.h>
#include <frc/geometry/Pose2d.h>
#include <frc/trajectory/TrapezoidProfile.h>

namespace Constants {
    inline constexpr unsigned char accelerometerUpdateFrequency = 50; //Change?
    inline constexpr unsigned char driveControllerPort = 0;
    inline constexpr float driveControllerStopBelowThis = 0.01f;
    inline constexpr char laptopIPAddress[1] = {'\0'}; //TODO
    inline constexpr char jetsonIPAddress[1] = {'\0'}; //TODO
    inline constexpr char roboRioIPAddress[1] = {'\0'}; //TODO
    inline constexpr char laptopLANAddress[1] = {'\0'}; //Only necessary for debugging purposes
    inline constexpr char jetsonLANAddress[1] = {'\0'}; //TODO
    inline constexpr char roboRioLANAddress[1] = {'\0'}; //TODO

    namespace Measurements {
        inline constexpr float driveWheelDiameter = 0.1016f;
        inline constexpr float maxTranslationalSpeed = 1.0f; //TODO
        inline constexpr float maxAngularSpeed = 1.0f; //TODO
        inline constexpr float robotWidth = 1.0f; //TODO
        inline constexpr float robotHeight = 1.0f; //TODO
        inline constexpr float robotDiagonal = 1.0f; //TODO
    };

    namespace Video {
        inline constexpr unsigned char frameRate = 60; //TODO
        inline constexpr unsigned short int resolutionWidth = 1280; //TODO
        inline constexpr unsigned short int resolutionHeight = 720; //TODO
        inline constexpr unsigned char log2Image = 20;
        inline constexpr double laptopRefreshTime =  1.0 / frameRate * 1000000000;
    };

    namespace Swerve {
        namespace Turn {
            inline constexpr float kP = 0.5f; //Change?
            //Doubles instead of floats since they'll be multiplied by doubles later---avoids promotion overhead
            inline constexpr double gearRatio = 1.0; //TODO
            inline constexpr double radsPerRotation = gearRatio * 2.0 * 3.141592653;
            inline constexpr float maxSpeed = 1.0f; //TODO

            namespace Motors {
                inline constexpr unsigned char leftUpID = 5;
                inline constexpr unsigned char leftDownID = 6;
                inline constexpr unsigned char rightUpID = 7;
                inline constexpr unsigned char rightDownID = 8;

                inline constexpr bool leftUpInvert = false; //TODO
                inline constexpr bool leftDownInvert = false; //TODO
                inline constexpr bool rightUpInvert = false; //TODO
                inline constexpr bool rightDownInvert = false; //Done
            };
            
            namespace Encoders {
                inline constexpr unsigned char leftUpID = 0;
                inline constexpr unsigned char leftDownID = 1;
                inline constexpr unsigned char rightUpID = 2;
                inline constexpr unsigned char rightDownID = 3;

                inline constexpr bool leftUpInvert = false; //TODO
                inline constexpr bool leftDownInvert = false; //TODO
                inline constexpr bool rightUpInvert = false; //TODO
                inline constexpr bool rightDownInvert = false; //TODO

                inline constexpr double leftUpOffset = 0.0; //TODO
                inline constexpr double leftDownOffset = 0.0; //TODO
                inline constexpr double rightUpOffset = 0.0; //TODO
                inline constexpr double rightDownOffset = 0.0; //TODO
            };
        };

        namespace Drive {
            inline constexpr double gearRatio = 1.0 / 6.12;
            inline constexpr double metresPerRotation = gearRatio * Measurements::driveWheelDiameter * 3.141592653;
            inline constexpr float stopBelowThisVelocity = 0.001f; //Change?
            inline constexpr float maxSpeed = 5700.0f; //5708.57128906
            inline constexpr float leftToRightDistanceMetres = 0.685f;
            inline constexpr float upToDownDistanceMetres = 0.685f;
            //No constexpr definition of the constructor
            extern frc::SwerveDriveKinematics<4> driveKinematics;

            namespace Motors {
                inline constexpr unsigned char leftUpID = 1;
                inline constexpr unsigned char leftDownID = 2;
                inline constexpr unsigned char rightUpID = 3;
                inline constexpr unsigned char rightDownID = 4;

                inline constexpr bool leftUpInvert = false; //TODO
                inline constexpr bool leftDownInvert = false; //TODO
                inline constexpr bool rightUpInvert = false; //TODO
                inline constexpr bool rightDownInvert = true; //Done
            };
        };

        namespace Field {
            inline constexpr float outXMin[1] = {0.0f}; //TODO
            inline constexpr float outYMin[1] = {0.0f}; //TODO
            inline constexpr float outXMax[1] = {0.0f}; //TODO
            inline constexpr float outYMax[1] = {0.0f}; //TODO

            inline constexpr float fieldLength = 0.0f; //TODO
            inline constexpr float fieldWidth = 0.0f; //TODO
        };

        namespace Trajectory {
            inline constexpr float maxTranslationAcceleration = 1.0f; //TODO
            inline constexpr float maxAngularAcceleration = 1.0f; //TODO
            inline constexpr float robotAvoidance = Measurements::robotDiagonal / 2.0f;
            inline constexpr unsigned char xSteps = 100; //Change?
            inline constexpr unsigned char ySteps = 100; //Change?
            inline constexpr bool useNodeBounds = true; //Change?
            inline constexpr frc::Pose2d controllerTolerance{units::unit_t<units::meters>{0.0}, units::unit_t<units::meters>{0.0}, frc::Rotation2d{units::radian_t{0.0}}}; //TODO
            inline constexpr float kX[3] = {0.0f, 0.0f, 0.0f}; //TODO
            inline constexpr float kY[3] = {0.0f, 0.0f, 0.0f}; //TODO
            inline constexpr float kAngle[3] = {0.0f, 0.0f, 0.0f}; //TODO
            //No constexpr definition of the constructor
            extern frc::TrapezoidProfile<units::meters>::Constraints angleConstraints;
        };
    };
};