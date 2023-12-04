#include<raylib.h>
#include<iostream>
#include<string>
#include<fstream>
// #include<json.hpp>

// using json = nlohmann::json;


class Game{

    protected: 
    // individual score
    int score;
    int highScore;
    int tryCount;

    // rect
    int rectX;
    int rectY;

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

    // player
    char userName[20]; 


    public:
    // init
    Game() {

        ballX = 100;
        ballY = 100;
        ballSpeedX = 5;
        ballSpeedY = 5;

        rectX = GetScreenWidth()/6 - 50;
        rectY = GetScreenHeight()/4;

        radius = 15;

        lineX = GetScreenWidth()/2;
        lineY = GetScreenHeight() - 50;
        lineSpeedX = 5;

        score = 0;
        highScore = 0;
        tryCount = 1;

        std::cout << "Enter Player Name: "<< std::endl;
        std::cin>>userName;
        //getLine(std::cin, userName);

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
        // error in this logic
        if (ballY + radius >= lineY && ballX + radius >= lineX - 50 && ballX + radius <= lineX + 50) {
            ballSpeedY *= -1;
            score+=1;
        }  

        if(score > highScore){
            highScore = score;
        }

        // check if ball hits bottom
        if (ballY + radius >= GetScreenHeight()) {
            ballX = 100;
            ballY = 100;
            score = 0;
            // tryCount += 1;
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
        
        DrawLineEx(start, end, 2.0f, WHITE);  
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

    void displayUserScore() {
        DrawText(("Player : " + std::string(userName)).c_str(), 10, 50, 20, WHITE);
        DrawText(("Score : " + std::to_string(score)).c_str(), 10, 10, 20, WHITE);
        DrawText(("High Score : " + std::to_string(highScore)).c_str(), 10, 30, 20, WHITE);
    }

};


