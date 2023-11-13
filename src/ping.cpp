#include<raylib.h>
#include<string>



class Game{

    // individual score
    int score;
    int highScore;

    // line
    int lineX;
    int lineY;
    int lineSpeedX;

    // ball
    int ballX;
    int ballY;
    int ballSpeedX;
    int ballSpeedY;
    int radius;  

    public:
    // init
    Game() {
        ballX = 100;
        ballY = 100;
        ballSpeedX = 5;
        ballSpeedY = 5;
        radius = 15;

        lineX = GetScreenWidth()/2;
        lineY = GetScreenHeight() - 50;
        lineSpeedX = 5;
    }


    //ball details
    void updateBall() {
        ballX += ballSpeedX;
        ballY += ballSpeedY;

        // do not allow ball to go out of screen
        if (ballX + radius >= GetScreenWidth() || ballX - radius <= 0)
            ballSpeedX *= -1;

        if (ballY + radius >= GetScreenHeight() || ballY - radius <= 0)
            ballSpeedY *= -1;


        // check if ball hits line
        if (ballY + radius >= lineY && ballX >= lineX - 50 && ballX <= lineX + 50) {
            ballSpeedY *= -1;
            score+=1;
            if(score > highScore){
                highScore = score;
            }
        }

        // check if ball hits bottom
        if (ballY + radius >= GetScreenHeight()) {
            ballX = 100;
            ballY = 100;
            score = 0;
        }

        // check if ball hits ball

    }

    void drawBall() {
        DrawCircle(ballX, ballY, radius, WHITE);
    }


    // line details
    void drawLine() {
        Vector2 start = { static_cast<float>(lineX - 50), static_cast<float>(lineY) };
        Vector2 end = { static_cast<float>(lineX + 50), static_cast<float>(lineY) };
        
        DrawLineEx(start, end, 2.0f, BLACK);  
    }

    void updateLine(){
        if (IsKeyDown(KEY_RIGHT)) {
            if (lineX >= GetScreenWidth() - 50) {
                return;
            }
            lineX += lineSpeedX;
        } else if (IsKeyDown(KEY_LEFT)) {
            if(lineX <= 50){
                return;
            }
            lineX -= lineSpeedX;
        }
    }

    void displayScore() {
        DrawText(("Score: " + std::to_string(score)).c_str(), 10, 10, 20, WHITE);
        DrawText(("High Score: " + std::to_string(highScore)).c_str(), 10, 30, 20, WHITE);
    }


    // void createProfile(){}   
    // void loadProfile(){}
    // void saveProfile(){}
    // void deleteProfile(){}
    // void displayProfile(){}
    // void displayLeaderboard(){}
    // void displaySettings(){}
    // void displayCredits(){}
    // void displayHelp(){}
    // void displayAbout(){}

};