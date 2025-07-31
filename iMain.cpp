#include "iGraphics.h"
#include "iSound.h"
#include <windows.h>
#define MAX_PLAYERS 50
int jumpLimit = 160;
int minnieHeight = 239;
int minnieWidth = 187;
int timer1 = 70;
int timer2 = 50;
int timer3 = 40;
int scoreLeft = 1500;
Image menu, leaderboard, help, obstacle_1, obstacle_2, player_name, gameover, diamond, level_comp;
char minnie_running[6][100] = {"assets/images/My Game/minnie_running/tile000.png", "assets/images/My Game/minnie_running/tile001.png", "assets/images/My Game/minnie_running/tile002.png", "assets/images/My Game/minnie_running/tile003.png", "assets/images/My Game/minnie_running/tile004.png", "assets/images/My Game/minnie_running/tile005.png"};
char minnie_jumping[6][100] = {"assets/images/My Game/minnie_jumping/jumping000.png", "assets/images/My Game/minnie_jumping/jumping001.png", "assets/images/My Game/minnie_jumping/jumping002.png", "assets/images/My Game/minnie_jumping/jumping003.png", "assets/images/My Game/minnie_jumping/jumping004.png", "assets/images/My Game/minnie_jumping/jumping005.png"};
char digbazi[6][100] = {"assets/images/My Game/minnie_digbazi/digbazi000.png", "assets/images/My Game/minnie_digbazi/digbazi001.png", "assets/images/My Game/minnie_digbazi/digbazi002.png", "assets/images/My Game/minnie_digbazi/digbazi003.png", "assets/images/My Game/minnie_digbazi/digbazi004.png", "assets/images/My Game/minnie_digbazi/digbazi005.png"};
char level[4][100] = {"assets/images/My Game/level/level 1.jpg", "assets/images/My Game/level/level 2.png", "assets/images/My Game/level/level 3.png", "assets/images/My Game/level/gamecomplete.jpg"};
char portal[4][100] = {"assets/images/My Game/portal/tile000.png", "assets/images/My Game/portal/tile001.png", "assets/images/My Game/portal/tile002.png", "assets/images/My Game/portal/tile003.png"};
char zombie[6][100] = {"assets/images/My Game/zombie/tile000.png", "assets/images/My Game/zombie/tile001.png", "assets/images/My Game/zombie/tile002.png", "assets/images/My Game/zombie/tile003.png", "assets/images/My Game/zombie/tile004.png", "assets/images/My Game/zombie/tile005.png"};
char details[3][100] = {"assets/images/My Game/details/000.jpg", "assets/images/My Game/details/001.jpg", "assets/images/My Game/details/002.jpg"};
int game_state = 0;
int minnie1X = 30;
int minnie1Y = 150;
int groundY = 150;
int minnie_idx = 0;
int minnie_jump = 0;
int minnie_width = 90;
int minnie_height = 150;
int obstacle1_width = 100;
int obstacle1_height = 30;
int obstacle2_width = 150;
int obstacle2_height = 30;
int dx = 10;
int j = 0;
int minnie_running_idx = 1;
bool isJumping = false;
bool isRunningF = false;
bool isRunningB = false;
bool jumpUp = false;
bool isRunning = false;
bool isStanding = true;
int levels = 0;
int minnie_jumping_idx = 0;
int platform1X = 300;
int platform1Y = 325;
int platform2X = 700;
int platform2Y = 550;
int platform3X = 500;
int platform3Y = 225;
int platform4X = 600;
int platform4Y = 700;
int platform5X = 1000;
int platform5Y = 650;
int platform6X = 200;
int platform6Y = 450;
int dx1 = 1;
int dx2 = -1;
int currentPlatform = -1;
bool onPlatform1 = false;
bool onPlatform2 = false;
bool onPlatform3 = false;
bool onPlatform4 = false;
bool onPlatform5 = false;
bool onPlatform6 = false;
bool gameOver = false;
char timer[100];
char score[100];
int count = 0;
int diamondX = 1050;
int diamondY = 700;
int diamond_width = 58;
int diamond_height = 52;
bool level_complete = false;
bool show_diamond = true;
int minnie2X = 30;
int minnie2Y = 400;
int stage1X = 0;
int stage1Y = 325;
int stage2X = 115;
int stage2Y = 252;
int stage3X = 230;
int stage3Y = 151;
int stage4X = 687;
int stage4Y = 403;
int stage5X = 236;
int stage5Y = 545;
int stage6X = 578;
int stage6Y = 641;
int stage7X = 886;
int stage7Y = 113;
int stage8X = 1014;
int stage8Y = 453;
int stage1H = 63, stage1W = 213, stage2H = 57, stage2W = 346, stage3H = 52, stage3W = 455, stage4H = 55, stage4W = 286, stage5H = 54, stage5W = 283, stage6H = 45, stage6W = 402, stage7H = 37, stage7W = 314, stage8H = 62, stage8W = 186;
bool onStage1 = false;
bool onStage2 = false;
bool onStage3 = false;
bool onStage4 = false;
bool onStage5 = false;
bool onStage6 = false;
bool onStage7 = false;
bool onStage8 = false;
int zombie1X = 830;
int zombie1Y = 465;
int zombie_idx = 0;
int portalX = 270;
int portalY = 230 + stage2H;
int soundPlayed = 0;
int onPlatform = 0;
bool input_mode = false;
int name_idx = 0;
char current_player[50];
int total_score[100];
int scoreidx = 0;
char total_players[50][100];
int playeridx = 0;
bool scoreSaved = false;
char playerNames[MAX_PLAYERS][100];
int playerScores[MAX_PLAYERS];
int playerCount = 0;
int zombie3X = 500;
int zombie3Y = 600;
int minnie3X = 178;
int minnie3Y = 253;
int floor1X = 168;
int floor1Y = 253;
int floor1width = 833;
int floor2X = 69;
int floor2Y = 365;
int floor2width = 212;
int floor3X = 296;
int floor3Y = 389;
int floor3width = 813;
int floor4X = 687;
int floor4Y = 645;
int floor4width = 463;
bool onfloor1 = false;
bool onfloor2 = false;
bool onfloor3 = false;
bool onfloor4 = false;
int onfloor = 0;
int show_coin[5] = {1, 1, 1, 1, 1};
int obstacle3X = 320;
int obstacle3Y = 430;
bool onObstacle3 = false;
int dx3 = 1;
bool show_bomb = true;
int scoreUpdated = 0;
int show_details = 0;
bool onfloor5 = false;
/*
function iDraw() is called again and again by the system.
*/
void loadLeaderboard();
void changeZombiePosition();
void load_image()
{
    iLoadImage(&menu, "assets/images/My Game/Menu.jpg");
    iLoadImage(&leaderboard, "assets/images/My Game/leaderboard 3.png");
    iLoadImage(&help, "assets/images/My Game/help.png");
    iLoadImage(&player_name, "assets/images/My Game/player name.png");
    iLoadImage(&obstacle_1, "assets/images/My Game/obstacle_1.png");
    iLoadImage(&obstacle_2, "assets/images/My Game/obstacle_2.png");
    iLoadImage(&gameover, "assets/images/My Game/Game_over.jpg");
    iLoadImage(&diamond, "assets/images/My Game/diamond.png");
    iLoadImage(&level_comp, "assets/images/My Game/level_complete.jpg");
}

void iDraw()
{
    // place your drawing codes here
    iClear();

    if (game_state == 0)
    {

        iShowImage(0, 0, "assets/images/My Game/Menu.jpg");
    }
    else if (game_state == 1)
    {

        if (levels == 0)
        {
            iShowImage(0, 0, "assets/images/My Game/player name.png");
            iSetColor(0, 0, 0);
            iText(448, 455, current_player, GLUT_BITMAP_HELVETICA_18);
            iSetColor(255, 255, 255);
            iText(500, 400, "PLease click on the box first", GLUT_BITMAP_HELVETICA_18);
            iText(515, 380, "Press 'Enter' to continue", GLUT_BITMAP_HELVETICA_18);
        }
        for (int i = 0; i <= 5; i++)
        {
            if (levels == i + 1)
            {
                iShowImage(0, 0, level[i]);
                if (levels == 1)
                {
                    sprintf(timer, "Time Left: %d", timer1);
                    sprintf(score, "Score: %d", scoreLeft);
                    iShowImage(platform1X, platform1Y, "assets/images/My Game/obstacle_1.png");
                    iShowImage(platform2X, platform2Y, "assets/images/My Game/obstacle_2.png");
                    iShowImage(platform3X, platform3Y, "assets/images/My Game/obstacle_1.png");
                    iShowImage(platform4X, platform4Y, "assets/images/My Game/obstacle_2.png");
                    iShowImage(platform5X, platform5Y, "assets/images/My Game/obstacle_2.png");
                    iShowImage(platform6X, platform6Y, "assets/images/My Game/obstacle_2.png");
                    if (show_coin[0] == 1)
                    {
                        iShowImage(platform1X + 30, platform1Y + obstacle1_height + 20, "assets/images/My Game/coin.png");
                    }
                    if (show_coin[1] == 1)
                    {
                        iShowImage(platform2X + 50, platform2Y + obstacle2_height + 20, "assets/images/My Game/coin.png");
                    }

                    if (show_diamond)
                    {
                        iShowImage(diamondX, diamondY, "assets/images/My Game/diamond.png");
                    }
                    iSetColor(255, 255, 255);
                    iText(1000, 800, timer, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(70, 800, score, GLUT_BITMAP_TIMES_ROMAN_24);

                    if (isStanding)
                    {
                        iShowImage(minnie1X, minnie1Y, minnie_jumping[0]);
                    }

                    else
                    {
                        if (isRunning)
                        {
                            iShowImage(minnie1X, minnie1Y + minnie_jump, minnie_running[minnie_running_idx]);
                        }
                        else if (isJumping)
                        {
                            isRunning = false;
                            iShowImage(minnie1X, minnie1Y + minnie_jump, minnie_jumping[minnie_jumping_idx]);
                        }
                    }
                }
                if (levels == 2)
                {
                    iSetColor(255, 255, 255);
                    sprintf(timer, "Time Left: %d", timer2);
                    sprintf(score, "Score: %d", scoreLeft);
                    iShowImage(zombie1X, zombie1Y, zombie[zombie_idx]);
                    iShowImage(portalX, portalY, portal[3]);
                    iShowImage(stage5X + 10, stage5Y + stage5H, "assets/images/My Game/kata.png");
                    iShowImage(obstacle3X, obstacle3Y, "assets/images/My Game/obstacle_1.png");
                    if (show_coin[2] == 1)
                    {
                        iShowImage(stage3X + 340, stage3Y + stage3H + 50, "assets/images/My Game/coin.png");
                    }
                    if (show_diamond)
                    {
                        iShowImage(1120, 534, "assets/images/My Game/diamond.png");
                    }
                    iSetColor(255, 255, 255);
                    iText(1000, 800, timer, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(70, 800, score, GLUT_BITMAP_TIMES_ROMAN_24);
                    if (isStanding)
                    {
                        iShowImage(minnie2X, minnie2Y + minnie_jump, minnie_jumping[0]);
                    }

                    else
                    {
                        if (isRunning)
                        {
                            iShowImage(minnie2X, minnie2Y + minnie_jump, minnie_running[minnie_running_idx]);
                        }
                        else if (isJumping)
                        {
                            isRunning = false;
                            iShowImage(minnie2X, minnie2Y + minnie_jump, minnie_jumping[minnie_jumping_idx]);
                        }
                    }
                }
                if (levels == 3)
                {
                    iSetColor(255, 255, 255);
                    sprintf(timer, "Time Left: %d", timer3);
                    sprintf(score, "Score: %d", scoreLeft);
                    iShowImage(zombie3X, zombie3Y, zombie[zombie_idx]);
                    iShowImage(800, 650, "assets/images/My Game/kata.png");
                    iShowImage(630, 470, "assets/images/My Game/floor5.png");
                    // iSetColor(0, 0, 0);
                    // iRectangle(minnie3X, minnie3Y + minnie_jump, minnie_width, minnie_height);
                    // iRectangle(630, 470, 100, 40);
                    if (show_diamond)
                    {
                        iShowImage(1030, 686, "assets/images/My Game/diamond.png");
                    }
                    iSetColor(255, 255, 255);
                    iText(1000, 800, timer, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(70, 800, score, GLUT_BITMAP_TIMES_ROMAN_24);
                    if (isStanding)
                    {
                        iShowImage(minnie3X, minnie3Y + minnie_jump, minnie_jumping[0]);
                    }

                    else
                    {
                        if (isRunning)
                        {
                            iShowImage(minnie3X, minnie3Y + minnie_jump, minnie_running[minnie_running_idx]);
                        }
                        else if (isJumping)
                        {
                            isRunning = false;
                            iShowImage(minnie3X, minnie3Y + minnie_jump, minnie_jumping[minnie_jumping_idx]);
                        }
                    }
                }

                if (gameOver && !level_complete)
                {
                    iShowImage(0, 0, "assets/images/My Game/Game_over.jpg");
                }
                if (level_complete)
                {
                    iShowImage(0, 0, "assets/images/My Game/level_complete.jpg");
                }
            }
        }
    }
    if (game_state == 2)
    {

        iShowImage(0, 0, "assets/images/My game/leaderboard 3.png");
        int baseY = 470;
        int rowHeight = 30;
        loadLeaderboard();

        iSetColor(0, 0, 0);
        iText(495, 510, "TOP 5 SCORERS", GLUT_BITMAP_TIMES_ROMAN_24);

        for (int i = 0; i < playerCount && i < 5; i++)
        {
            int y = baseY - i * rowHeight;
            // char buffer[200];
            char rank[5];
            if (i == 0)
                strcpy(rank, "1st");
            else if (i == 1)
                strcpy(rank, "2nd");
            else if (i == 2)
                strcpy(rank, "3rd");
            else if (i == 3)
                strcpy(rank, "4th");
            else if (i == 4)
                strcpy(rank, "5th");
            iText(495, y, rank, GLUT_BITMAP_HELVETICA_18);
            iText(540, y, playerNames[i], GLUT_BITMAP_HELVETICA_18);
            char scoreText[5];
            sprintf(scoreText, "%d", playerScores[i]);
            iText(630, y, scoreText, GLUT_BITMAP_HELVETICA_18);
        }
    }
    if (game_state == 3)
    {

        iShowImage(0, 0, "assets/images/My Game/help.png");
        iSetColor(0,0,0);
        iText(395,320,"4. Press 'END' to exit anytime",GLUT_BITMAP_HELVETICA_18);
    }
}
void scoreUpdate()
{
    if ((levels == 1 || levels == 2 || levels == 3) && (!gameOver && !level_complete))
    {
        scoreLeft--;
    }
}
void timerUpdate()
{
    if (levels == 1)
    {
        // soundPlayed=0;
        if (timer1 > 0)
        {
            timer1--;
        }
        if (timer1 == 3)
        {
            iPlaySound("assets/sounds/timer.wav", false, 100);
        }
        if (timer1 <= 0)
        {
            gameOver = true;
            for (int i = 0; i < 5; i++)
            {
                show_coin[i] = 1;
            }
            FILE *fcharacter_name = fopen("leaderboard.txt", "a");
            if (fcharacter_name != NULL)
            {
                fprintf(fcharacter_name, "%d\n", scoreLeft);
                fclose(fcharacter_name);
            }
            if (soundPlayed != 8)
            {
                iPlaySound("assets/sounds/over.wav", false, 100);
                soundPlayed = 8;
            }
        }
    }
    if (levels == 2)
    {
        if (timer2 > 0)
        {
            timer2--;
        }
        if (timer2 == 3)
        {
            iPlaySound("assets/sounds/timer.wav", false, 100);
        }

        if (timer2 <= 0)
        {
            gameOver = true;
            for (int i = 0; i < 5; i++)
            {
                show_coin[i] = 1;
            }
            if (!scoreSaved)
            {
                FILE *fcharacter_name = fopen("leaderboard.txt", "a");
                if (fcharacter_name != NULL)
                {
                    fprintf(fcharacter_name, "%d\n", scoreLeft);
                    fclose(fcharacter_name);
                }
                scoreSaved = true;
            }
            if (soundPlayed != 9)
            {
                iPlaySound("assets/sounds/over.wav", false, 100);
                soundPlayed = 9;
            }
        }
    }
    if (levels == 3)
    {
        if (timer3 > 0)
        {
            timer3--;
        }
        if (timer3 == 3)
        {
            iPlaySound("assets/sounds/timer.wav", false, 100);
        }
        if (timer3 <= 0 && soundPlayed != 10 && !level_complete)
        {
            gameOver = true;
            for (int i = 0; i < 5; i++)
            {
                show_coin[i] = 1;
            }
            iPlaySound("assets/sounds/over.wav", false, 100);
            soundPlayed = 10;
            if (!scoreSaved)
            {
                FILE *fcharacter_name = fopen("leaderboard.txt", "a");
                if (fcharacter_name != NULL)
                {
                    fprintf(fcharacter_name, "%d\n", scoreLeft);
                    fclose(fcharacter_name);
                }
            }
            scoreSaved = true;
        }
    }
}
void update_zombie()
{
    zombie_idx++;
    if (zombie_idx > 5)
    {
        zombie_idx = 0;
    }
}
void changeZombiePosition()
{
    if (levels == 3 && !gameOver && !level_complete)
    {
        zombie3X = rand() % 1120;
        zombie3Y = rand() % 750;
    }
}
void platform_collision()
{
    if (levels == 1)
    {
        int minnieFeetX1 = minnie1X;
        int minnieFeetX2 = minnie1X + minnie_width;
        int minnieFeetY = minnie1Y + minnie_jump;
        if (minnieFeetX2 >= platform4X && minnieFeetX1 <= platform4X + obstacle2_width)
        {
            if (minnieFeetY >= platform4Y + obstacle2_height - 5 && minnieFeetY <= platform4Y + obstacle2_height + 10 && !jumpUp)
            {
                onPlatform4 = true;
                onPlatform1 = onPlatform2 = onPlatform3 = onPlatform6 = onPlatform5 = false;
            }
        }
        else
        {
            onPlatform4 = false;
        }
        if (minnieFeetX2 >= platform1X && minnieFeetX1 <= platform1X + obstacle1_width)
        {
            if (minnieFeetY >= platform1Y + obstacle1_height - 5 && minnieFeetY <= platform1Y + obstacle1_height + 10 && !jumpUp)
            {
                onPlatform1 = true;
                onPlatform6 = onPlatform2 = onPlatform3 = onPlatform4 = onPlatform5 = false;
            }
        }
        else
        {
            onPlatform1 = false;
        }
        if (minnieFeetX2 >= platform2X && minnieFeetX1 <= platform2X + obstacle2_width)
        {
            if (minnieFeetY >= platform2Y + obstacle2_height - 5 && minnieFeetY <= platform2Y + obstacle2_height + 10 && !jumpUp)
            {
                onPlatform2 = true;
                onPlatform1 = onPlatform6 = onPlatform3 = onPlatform4 = onPlatform5 = false;
            }
        }
        else
        {
            onPlatform2 = false;
        }

        if (minnieFeetX2 >= platform3X && minnieFeetX1 <= platform3X + obstacle1_width)
        {
            if (minnieFeetY >= platform3Y + obstacle1_height - 5 && minnieFeetY <= platform3Y + obstacle1_height + 10 && !jumpUp)
            {
                onPlatform3 = true;

                onPlatform1 = onPlatform2 = onPlatform6 = onPlatform4 = onPlatform5 = false;
            }
        }
        else
        {
            onPlatform3 = false;
        }

        if (minnieFeetX2 >= platform5X && minnieFeetX1 <= platform5X + obstacle2_width)
        {
            if (minnieFeetY >= platform5Y + obstacle2_height - 5 && minnieFeetY <= platform5Y + obstacle2_height + 10 && !jumpUp)
            {
                onPlatform5 = true;
                onPlatform1 = onPlatform2 = onPlatform3 = onPlatform4 = onPlatform6 = false;
            }
        }
        else
        {
            onPlatform5 = false;
        }
        if (minnieFeetX2 >= platform6X && minnieFeetX1 <= platform6X + obstacle2_width)
        {
            if (minnieFeetY >= platform6Y + obstacle2_height - 5 && minnieFeetY <= platform6Y + obstacle2_height + 10 && !jumpUp)
            {
                onPlatform6 = true;
                onPlatform1 = onPlatform2 = onPlatform3 = onPlatform4 = onPlatform5 = false;
            }
        }
        else
        {
            onPlatform6 = false;
        }
    }
    if (levels == 2)
    {
        int minnieFeetX1 = minnie2X;
        int minnieFeetX2 = minnie2X + minnie_width;
        int minnieFeetY = minnie2Y + minnie_jump;
        if (minnieFeetX2 >= stage1X && minnieFeetX1 <= stage1X + 213)
        {
            if (minnieFeetY >= stage1Y + 63 - 5 && minnieFeetY <= stage1Y + 63 + 10 && !jumpUp)
            {
                onStage1 = true;
                onStage2 = onStage3 = onStage4 = onStage5 = onStage6 = onStage7 = onStage8 = onObstacle3 = false;
            }
        }
        else
        {
            onStage1 = false;
        }
        if (minnieFeetX2 >= stage2X && minnieFeetX1 <= stage2X + 346)
        {
            if (minnieFeetY >= stage2Y + 57 - 5 && minnieFeetY <= stage2Y + 57 + 10 && !jumpUp)
            {
                onStage2 = true;
                onStage1 = onStage3 = onStage4 = onStage5 = onStage6 = onStage7 = onStage8 = onObstacle3 = false;
            }
        }
        else
        {
            onStage2 = false;
        }
        if (minnieFeetX2 >= stage3X && minnieFeetX1 <= stage3X + 455)
        {
            if (minnieFeetY >= stage3Y + 52 - 5 && minnieFeetY <= stage3Y + 52 + 10 && !jumpUp)
            {
                onStage3 = true;
                onStage1 = onStage2 = onStage4 = onStage5 = onStage6 = onStage7 = onStage8 = onObstacle3 = false;
            }
        }
        else
        {
            onStage3 = false;
        }
        if (minnieFeetX2 >= stage4X && minnieFeetX1 <= stage4X + 286)
        {
            if (minnieFeetY >= stage4Y + 55 - 5 && minnieFeetY <= stage4Y + 55 + 10 && !jumpUp)
            {
                onStage4 = true;
                onStage1 = onStage3 = onStage2 = onStage5 = onStage6 = onStage7 = onStage8 = onObstacle3 = false;
            }
        }
        else
        {
            onStage4 = false;
        }
        if (minnieFeetX2 >= stage5X && minnieFeetX1 <= stage5X + 283)
        {
            if (minnieFeetY >= stage5Y + 54 - 5 && minnieFeetY <= stage5Y + 54 + 10 && !jumpUp)
            {
                onStage5 = true;
                onStage2 = onStage3 = onStage4 = onStage1 = onStage6 = onStage7 = onStage8 = onObstacle3 = false;
            }
        }
        else
        {
            onStage5 = false;
        }
        if (minnieFeetX2 >= stage6X && minnieFeetX1 <= stage6X + 402)
        {
            if (minnieFeetY >= stage6Y + 45 - 5 && minnieFeetY <= stage6Y + 45 + 10 && !jumpUp)
            {
                onStage6 = true;
                onStage1 = onStage3 = onStage4 = onStage5 = onStage2 = onStage7 = onStage8 = onObstacle3 = false;
            }
        }
        else
        {
            onStage6 = false;
        }
        if (minnieFeetX2 >= stage7X && minnieFeetX1 <= stage7X + 314)
        {
            if (minnieFeetY >= stage7Y + 37 - 5 && minnieFeetY <= stage7Y + 37 + 10 && !jumpUp)
            {
                onStage7 = true;
                onStage1 = onStage2 = onStage4 = onStage5 = onStage6 = onStage3 = onStage8 = onObstacle3 = false;
                ;
            }
        }
        else
        {
            onStage7 = false;
        }
        if (minnieFeetX2 >= stage8X && minnieFeetX1 <= stage8X + 186)
        {
            if (minnieFeetY >= stage8Y + 62 - 5 && minnieFeetY <= stage8Y + 62 + 10 && !jumpUp)
            {
                onStage8 = true;
                onStage1 = onStage3 = onStage2 = onStage5 = onStage6 = onStage7 = onStage4 = onObstacle3 = false;
            }
        }
        else
        {
            onStage8 = false;
        }
        if (minnieFeetX2 >= obstacle3X && minnieFeetX1 <= obstacle3X + 168)
        {
            if (minnieFeetY >= obstacle3Y + 48 - 5 && minnieFeetY <= obstacle3Y + 46 + 10 && !jumpUp)
            {
                onObstacle3 = true;
                onStage1 = onStage3 = onStage2 = onStage5 = onStage6 = onStage7 = onStage4 = false;
            }
        }
        else
        {
            onObstacle3 = false;
        }
        if (minnieFeetX2 >= stage5X + 10 && minnieFeetX1 <= stage5X + 10 + 120)
        {
            if (minnie2Y >= stage5Y + stage5H - 10 && minnie2Y <= stage5Y + stage5H + 30 - 10)
            {
                if (scoreUpdated != 1)
                {
                    scoreLeft -= 100;
                    scoreUpdated = 1;
                }

                if (timer2 > 10)
                {
                    timer2 -= 10;
                }
                else
                {
                    gameOver = true;
                    for (int i = 0; i < 5; i++)
                    {
                        show_coin[i] = 1;
                    }
                    if (soundPlayed != 6)
                    {
                        iPlaySound("assets/sounds/over.wav", false, 100);
                        soundPlayed = 6;
                    }
                }
                minnie2X = 35;
                minnie2Y = 400;
            }
        }
    }
    if (levels == 3)
    {
        int minnieFeetX1 = minnie3X;
        int minnieFeetX2 = minnie3X + minnie_width;
        int minnieFeetY = minnie3Y + minnie_jump;
        if (minnieFeetX2 >= floor1X && minnieFeetX1 <= floor1X + floor1width)
        {
            if (minnieFeetY >= floor1Y - 15 && minnieFeetY <= floor1Y + 10 && !jumpUp)
            {
                onfloor1 = true;
                onfloor2 = onfloor3 = onfloor4 = onfloor5 = false;
            }
        }
        else
        {
            onfloor1 = false;
        }
        if (minnieFeetX2 >= floor2X && minnieFeetX1 <= floor2X + floor2width)
        {
            if (minnieFeetY >= floor2Y + 24 - 5 && minnieFeetY <= floor2Y + 24 + 10 && !jumpUp)
            {
                onfloor2 = true;
                onfloor1 = onfloor3 = onfloor4 = onfloor5 = false;
            }
        }
        else
        {
            onfloor2 = false;
        }
        if (minnieFeetX2 >= floor3X && minnieFeetX1 <= floor3X + floor3width)
        {
            if (minnieFeetY >= floor3Y - 5 && minnieFeetY <= floor3Y + 10 && !jumpUp)
            {
                onfloor3 = true;
                onfloor2 = onfloor1 = onfloor4 = onfloor5 = false;
            }
        }
        else
        {
            onfloor3 = false;
        }
        if (minnieFeetX2 >= floor4X - 10 && minnieFeetX1 <= floor4X + floor4width)
        {
            if (minnieFeetY >= floor4Y - 15 && minnieFeetY <= floor4Y + 10 && !jumpUp)
            {
                onfloor4 = true;
                onfloor2 = onfloor3 = onfloor1 = onfloor5 = false;
            }
        }
        else
        {
            onfloor4 = false;
        }
        if (minnieFeetX2 >= 800 && minnieFeetX1 <= 800 + 120)
        {
            if (minnieFeetY >= 650 - 10 && minnie3Y + minnieFeetY <= 650 + 30 + 5)
            {
                timer3 -= 5;
                scoreLeft -= 100;
                minnie3Y = 253;
                minnie3X = 168;
            }
        }
        if (minnieFeetX2 >= 630 && minnieFeetX1 <= 630 + 100)
        {
            if (minnieFeetY >= 470 - 10 && minnieFeetY <= 470 + 40 + 10 && !jumpUp)
            {
                onfloor5 = true;
                onfloor2 = onfloor3 = onfloor1 = onfloor4 = false;
            }
        }
        else
        {
            onfloor5 = false;
        }
    }
}
void diamond_collect()
{
    if (levels == 1)
    {
        int minnieFeetX1 = minnie1X;
        int minnieFeetX2 = minnie1X + minnie_width;
        int minnieFeetY = minnie1Y + minnie_jump;
        if (minnieFeetX2 > diamondX - 5 && minnieFeetX1 < diamondX + diamond_width + 5)
        {
            if (minnieFeetY > diamondY - 5 && minnieFeetY < diamondY + diamond_height + 5)
            {
                level_complete = true;
                show_diamond = false;
                if (soundPlayed != 1)
                {
                    iPlaySound("assets/sounds/complete.wav", false, 100);
                    soundPlayed = 1;
                }
            }
        }
        if (minnieFeetX2 > platform1X + 30 - 5 && minnieFeetX1 < platform1X + 30 + 40 + 5)
        {
            if (minnieFeetY > platform1Y + obstacle1_height + 20 - 10 && minnieFeetY < platform1Y + obstacle1_height + 20 + 40 + 5)
            {
                if (scoreUpdated != 2)
                {
                    scoreLeft += 50;
                    scoreUpdated = 2;
                }

                show_coin[0] = 0;
                if (soundPlayed != 3)
                {
                    iPlaySound("assets/sounds/coin.wav", false, 100);
                    soundPlayed = 3;
                }
            }
        }
        if (minnieFeetX2 > platform2X + 50 - 5 && minnieFeetX1 < platform2X + 50 + 40 + 5)
        {
            if (minnieFeetY > platform2Y + obstacle2_height + 20 - 15 && minnieFeetY < platform2Y + obstacle2_height + 20 + 40 + 5)
            {
                if (scoreUpdated != 3)
                {
                    scoreLeft += 50;
                    scoreUpdated = 3;
                }

                show_coin[1] = 0;
                if (soundPlayed != 4)
                {
                    iPlaySound("assets/sounds/coin.wav", false, 100);
                    soundPlayed = 4;
                }
            }
        }
    }
    if (levels == 2)
    {
        if (minnie2X + minnie_width - 5 >= 1120 && minnie2X <= 1120 + diamond_width + 5)
        {
            if (minnie2Y + minnie_jump >= 534 - 20 && minnie2Y + minnie_jump <= 534 + diamond_height + 20)
            {
                level_complete = true;
                if (!scoreSaved)
                {
                    FILE *fcharacter_name = fopen("leaderboard.txt", "a");
                    if (fcharacter_name != NULL)
                    {
                        fprintf(fcharacter_name, "%d\n", scoreLeft);
                        fclose(fcharacter_name);
                    }
                    scoreSaved = true;
                }

                show_diamond = false;
                if (soundPlayed != 2)
                {
                    iPlaySound("assets/sounds/complete.wav", false, 100);
                    soundPlayed = 2;
                }
            }
        }
        if (minnie2X >= stage3X + 340 - 10 && minnie2X <= stage3X + 340 + 40 + 5)
        {
            if (minnie2Y >= stage3Y + stage3H - 15 && minnie2Y <= stage3Y + stage3H + 50 + 40 + 15)
            {
                show_coin[2] = 0;
                if (scoreUpdated != 4)
                {
                    scoreLeft += 50;
                    scoreUpdated = 4;
                }

                if (soundPlayed != 5)
                {
                    iPlaySound("assets/sounds/coin.wav", false, 100);
                    soundPlayed = 5;
                }
            }
        }
    }
    if (levels == 3)
    {
        if (minnie3X + minnie_width >= 1030-15 && minnie3X <= 1030 + diamond_width + 5)
        {
            if (minnie3Y+minnie_jump >= 686 - 10  && minnie3Y +minnie_jump<= 686 + diamond_height + 20)
            {
                level_complete = true;
                show_diamond = false;
                if (!scoreSaved)
                {
                    FILE *fcharacter_name = fopen("leaderboard.txt", "a");
                    if (fcharacter_name != NULL)
                    {
                        fprintf(fcharacter_name, "%d\n", scoreLeft);
                        fclose(fcharacter_name);
                    }
                    scoreSaved = true;
                }

                
                if (soundPlayed != 7)
                {
                    iPlaySound("assets/sounds/complete.wav", false, 100);
                    soundPlayed = 7;
                }
            }
        }
    }
}
void change_obstacle()
{
    if (levels == 1)
    {
        platform1X += dx * dx1;
        platform2X += dx * dx2;
        if (platform1X + obstacle1_width >= 1200 || platform1X <= 0)
        {
            dx1 *= -1;
        }
        if (platform2X + obstacle2_width >= 1200 || platform2X <= 0)
        {
            dx2 *= -1;
        }
    }
    if (levels == 2)
    {
        obstacle3X += dx * dx3;
        if (obstacle3X >= 600 || obstacle3X <= 260)
        {
            dx3 *= -1;
        }
    }
}
void update_running()
{
    if (levels == 1)
    {
        if (currentPlatform != 3 && onPlatform3)
        {
            minnie1Y = platform3Y + obstacle1_height;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            currentPlatform = 3;
        }
        if (currentPlatform != 4 && onPlatform4)
        {

            minnie1Y = platform4Y + obstacle2_height;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            currentPlatform = 4;
        }
        if (currentPlatform != 5 && onPlatform5)
        {
            minnie1Y = platform5Y + obstacle2_height;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            currentPlatform = 5;
        }
        if (currentPlatform != 6 && onPlatform6)
        {
            minnie1Y = platform6Y + obstacle2_height;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            currentPlatform = 6;
        }

        if (currentPlatform != 1 && onPlatform1)
        {
            minnie1Y = platform1Y + obstacle1_height;
            minnie1X += dx * dx1;
            currentPlatform = 1;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
        }
        if (currentPlatform == 1 && onPlatform1)
        {
            minnie1Y = platform1Y + obstacle1_height;
            minnie1X += dx * dx1;
        }
        if (currentPlatform != 2 && onPlatform2)
        {
            minnie1Y = platform2Y + obstacle2_height;
            minnie1X += dx * dx2;
            currentPlatform = 2;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
        }
        if (currentPlatform == 2 && onPlatform2)
        {
            minnie1Y = platform2Y + obstacle2_height;
            minnie1X += dx * dx2;
        }
        if (!onPlatform1 && !onPlatform2 && !onPlatform3 && !onPlatform4 && !onPlatform5 && !onPlatform6 && !isJumping && minnie1Y > 150)
        {
            minnie1Y -= 10;
            if (minnie1Y <= 150)
            {
                minnie1Y = 150;
            }
            currentPlatform = -1;
        }
    }
    if (levels == 2)
    {
        if (onStage1)
        {
            minnie2Y = stage1Y + 63;
        }
        if (onStage2)
        {
            minnie2Y = stage2Y + 57;
        }
        if (onStage3)
        {
            minnie2Y = stage3Y + 52;
        }
        if (onStage4)
        {
            minnie2Y = stage4Y + 52;
        }
        if (onStage5)
        {
            minnie2Y = stage5Y + 54;
        }
        if (onStage6)
        {
            minnie2Y = stage6Y + 45;
        }
        if (onStage7)
        {
            minnie2Y = stage7Y + 37;
        }
        if (onStage8)
        {
            minnie2Y = stage8Y + 62;
        }
        if (onPlatform != 3 && onObstacle3)
        {
            minnie2Y = obstacle3Y + 35;
            minnie2X += dx3 * dx;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            onPlatform = 3;
        }
        if (onPlatform == 3 && onObstacle3)
        {
            minnie2Y = obstacle3Y + 35;
            minnie2X += dx3 * dx;
        }
        if (!onStage1 && !onStage2 && !onStage3 && !onStage4 && !onStage5 && !onStage6 && !onStage7 && !onStage8 && !onObstacle3 && !isJumping)
        {
            minnie2Y -= 10;
            if (minnie2Y < 0)
            {
                minnie2Y = 880;
            }
        }
    }
    if (levels == 3)
    {
        if (onfloor1)
        {
            minnie3Y = floor1Y;
        }
        if (onfloor2 && onfloor != 2)
        {
            minnie3Y = floor2Y;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            onfloor = 2;
        }
        if (onfloor3 && onfloor != 3)
        {
            minnie3Y = floor3Y;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            onfloor = 3;
        }
        if (onfloor4 && onfloor != 4)
        {
            minnie3Y = floor4Y;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            onfloor = 4;
        }
        if (onfloor5 && onfloor != 5)
        {
            minnie3Y = 470 + 40;
            isJumping = false;
            jumpUp = false;
            minnie_jump = 0;
            onfloor = 5;
        }
        if (!onfloor1 && !onfloor2 && !onfloor3 && !onfloor4 && !onfloor5 && !isJumping)
        {
            minnie3Y -= 10;
            if (minnie3Y < 0)
            {
                minnie3Y = 880;
            }
        }
    }
}
void portal_collisison()
{
    if (levels == 2)
    {
        if (minnie2X >= portalX && minnie2X <= portalX + 150)
        {
            if (minnie2Y >= portalY - 20 && minnie2Y <= portalY + 75 && !jumpUp)
            {
                minnie2X = stage1X;
                minnie2Y = stage1Y + stage1H;
                
                    timer2 -= 5;
                
                
                
                if (scoreUpdated != 5)
                {
                    scoreLeft -= 10;
                    scoreUpdated = 5;
                }
            }
        }
        if (minnie2X + minnie_width >= zombie1X - 5 && minnie2X <= zombie1X + 100 + 5)
        {
            if (minnie2Y + minnie_jump >= zombie1Y - 20 && minnie2Y + minnie_jump <= zombie1Y + 200 + 20)
            {
                gameOver = true;
                for (int i = 0; i < 5; i++)
                {
                    show_coin[i] = 1;
                }
                if (!scoreSaved)
                {
                    FILE *fcharacter_name = fopen("leaderboard.txt", "a");
                    if (fcharacter_name != NULL)
                    {
                        fprintf(fcharacter_name, "%d\n", scoreLeft);
                        fclose(fcharacter_name);
                    }
                    scoreSaved = true;
                }
                if (soundPlayed != 11)
                {
                    iPlaySound("assets/sounds/over.wav", false, 100);
                    soundPlayed = 11;
                }
            }
        }
    }
    if (minnie3X + minnie_width >= zombie3X - 5 && minnie3X <= zombie3X + 100 + 5)
    {
        if (minnie3Y + minnie_jump >= zombie3Y - 20 && minnie3Y + minnie_jump <= zombie3Y + 200 + 20)
        {
            gameOver = true;
            for (int i = 0; i < 5; i++)
            {
                show_coin[i] = 1;
            }
            if (!scoreSaved)
            {
                FILE *fcharacter_name = fopen("leaderboard.txt", "a");
                if (fcharacter_name != NULL)
                {
                    fprintf(fcharacter_name, "%d\n", scoreLeft);
                    fclose(fcharacter_name);
                }
                scoreSaved = true;
            }
            if (soundPlayed != 12)
            {
                iPlaySound("assets/sounds/over.wav", false, 100);
                soundPlayed = 12;
            }
        }
        if (minnie3Y + minnie_jump + minnie_height >= zombie3Y - 20 && minnie3Y + minnie_jump + minnie_height <= zombie3Y + 200 + 20)
        {
            gameOver = true;
            for (int i = 0; i < 5; i++)
            {
                show_coin[i] = 1;
            }
            if (!scoreSaved)
            {
                FILE *fcharacter_name = fopen("leaderboard.txt", "a");
                if (fcharacter_name != NULL)
                {
                    fprintf(fcharacter_name, "%d\n", scoreLeft);
                    fclose(fcharacter_name);
                }
                scoreSaved = true;
            }
            if (soundPlayed != 13)
            {
                iPlaySound("assets/sounds/over.wav", false, 100);
                soundPlayed = 13;
            }
        }
    }
}
void update_jump()
{
    if (isJumping)
    {
        if (jumpUp)
        {
            minnie_jump += 10;
            minnie_jumping_idx++;
            if (minnie_jumping_idx >= 5)
            {
                minnie_jumping_idx = 5;
            }
            if (minnie_jump >= jumpLimit)
            {
                jumpUp = false;
            }
            if (minnie1Y + minnie_jump >= 900)
            {
                jumpUp = false;
            }
        }

        else
        {
            minnie_jump -= 10;
            minnie_jumping_idx--;
            if (minnie_jumping_idx <= 0)
            {
                minnie_jumping_idx = 0;
            }
            if (minnie_jump <= 0)
            {
                isJumping = false;
                jumpUp = false;
                minnie_jump = 0;
            }
        }
    }
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    // place your codes here
}

/*
function iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (game_state == 0 && levels == 0)
        {
            if (mx >= 100 && mx <= 379)
            {
                if (my >= 94 && my <= 181)
                {
                    iPlaySound("assets/sounds/mouse_click.wav", false, 100);
                    game_state = 1;
                    levels=0;
                }
            }
            if (mx >= 382 && mx <= 804)
            {
                if (my >= 82 && my <= 177)
                {
                    iPlaySound("assets/sounds/mouse_click.wav", false, 100);
                    game_state = 2;
                }
            }
            if (mx >= 818 && mx <= 1107)
            {
                if (my >= 85 && my <= 182)
                {
                    iPlaySound("assets/sounds/mouse_click.wav", false, 100);
                    game_state = 3;
                }
            }
        }

        if (game_state == 1 && levels == 0)
        {
            if (mx >= 430 && mx <= 780)
            {
                if (my >= 440 && my <= 480)
                {
                    iPlaySound("assets/sounds/mouse_click.wav", false, 100);
                    // FILE *playername=(player_name);
                    game_state = 1;
                    input_mode = true;
                }
            }
        }
        if (level_complete)
        {
            if (mx >= 733 && mx <= 1039)
            {
                if (my >= 78 && my <= 205)
                {
                    iPlaySound("assets/sounds/mouse_click.wav", false, 100);
                    level_complete = false;
                    if (levels <= 3)
                    {
                        levels++;
                    }

                    show_diamond = true;
                }
            }
        }
        if (gameOver)
        {
            if (mx >= 878 && mx <= 1071)
            {
                if (my >= 163 && my <= 246)
                {
                    iPlaySound("assets/sounds/mouse_click.wav", false, 100);
                    gameOver = false;
                    // game_state = 0;
                    // levels = 0;
                    // timer1 = 70;
                    // timer2 = 50;
                    // timer3 = 40;
                    // scoreLeft = 1500;
                    // minnie1X = 30;
                    // minnie1Y = 150;
                    // minnie2X = 30;
                    // minnie2Y = 400;
                    // soundPlayed = 0;
                    // show_diamond=true;
                    exit(0);
                }
            }
        }

        // place your codes here
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
    }
}

/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if (input_mode)
    {
        if (key == '\r') // Enter key
        {
            input_mode = false;
            levels = 1; // move to level 1

            // save name to file
            FILE *fcharacter_name = fopen("leaderboard.txt", "a");
            if (fcharacter_name != NULL)
            {
                fprintf(fcharacter_name, "%s\t", current_player);
                fclose(fcharacter_name);
            }
        }
        else if (key == '\b') // Backspace key
        {
            if (name_idx > 0)
            {
                name_idx--;
                current_player[name_idx] = '\0';
            }
        }
        else
        {
            if (name_idx < 49)
            {
                current_player[name_idx++] = key;
                current_player[name_idx] = '\0';
            }
        }
    }

    switch (key)
    {
    case 'q':
        // do something with 'q'
        break;
    // place your codes for other keys here
    default:
        break;
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{
    switch (key)
    {
    case GLUT_KEY_PAGE_UP:
        levels++;
    case GLUT_KEY_LEFT:
        // game_state=2;
        isStanding = false;
        isRunning = true;
        // isRunningF=false;
        if (levels == 1)
        {
            minnie1X -= 10;
            minnie_running_idx--;
            if (minnie_running_idx <= 1)
            {
                minnie_running_idx = 5;
            }
            if (minnie1X <= -50)
            {
                minnie1X = 1210;
            }
        }
        else if (levels == 2)
        {
            minnie2X -= 10;
            minnie_running_idx--;
            if (minnie_running_idx <= 1)
            {
                minnie_running_idx = 5;
            }
            if (minnie2X <= -50)
            {
                minnie2X = 1210;
            }
        }
        if (levels == 3)
        {
            minnie3X -= 10;
            minnie_running_idx--;
            if (minnie_running_idx <= 1)
            {
                minnie_running_idx = 5;
            }
            if (minnie3X <= -50)
            {
                minnie3X = 1210;
            }
        }
        break;
    // place your codes for other keys here
    case GLUT_KEY_RIGHT:
        // game_state=2;
        isStanding = false;
        isRunning = true;
        minnie_running_idx++;
        if (minnie_running_idx >= 6)
        {
            minnie_running_idx = 1;
        }
        if (levels == 1)
        {

            if (minnie1X >= 1200)
            {
                minnie1X = -10;
            }
            // isRunningB=false;
            minnie1X += 10;
        }
        if (levels == 2)
        {
            if (minnie2X >= 1200)
            {
                minnie2X = -10;
            }
            // isRunningB=false;
            minnie2X += 10;
        }
        if (levels == 3)
        {
            if (minnie3X >= 1200)
            {
                minnie3X = -10;
            }
            // isRunningB=false;
            minnie3X += 10;
            if (onfloor1 && minnie3X > 950)
            {
                minnie3X = 950;
            }
            if (minnie3X > floor3X - 60)
            {
                if (minnie3Y > floor3Y - 50 && minnie3Y < floor3Y)
                {
                    minnie3X = floor3X - 60;
                }
            }
            if (onfloor3 && minnie3X > 1050)
            {
                minnie3X = 1050;
            }
        }
        break;
    case GLUT_KEY_UP:
        if (!isJumping)
        {
            isJumping = true;
            jumpUp = true;
        }
        break;
    case GLUT_KEY_END:
        exit(0);
    case GLUT_KEY_HOME:
        game_state = 0;
        levels = 0;
    default:
        break;
    }
}

int compareScores(const void *a, const void *b)
{
    int indexA = *(int *)a;
    int indexB = *(int *)b;
    return playerScores[indexB] - playerScores[indexA]; // Descending order
}

void loadLeaderboard()
{
    FILE *fp = fopen("leaderboard.txt", "r");
    playerCount = 0;

    if (fp != NULL)
    {
        while (fscanf(fp, "%s%d", playerNames[playerCount], &playerScores[playerCount]) == 2)
        {
            playerCount++;
            if (playerCount >= MAX_PLAYERS)
                break;
        }
        fclose(fp);
    }

    // Create an index array to sort by score
    int indices[MAX_PLAYERS];
    for (int i = 0; i < playerCount; i++)
    {
        indices[i] = i;
    }

    qsort(indices, playerCount, sizeof(int), compareScores);

    // Make a temporary copy of sorted names and scores
    char tempNames[MAX_PLAYERS][100];
    int tempScores[MAX_PLAYERS];
    for (int i = 0; i < playerCount; i++)
    {
        strcpy(tempNames[i], playerNames[indices[i]]);
        tempScores[i] = playerScores[indices[i]];
    }

    // Copy back to original arrays
    for (int i = 0; i < playerCount; i++)
    {
        strcpy(playerNames[i], tempNames[i]);
        playerScores[i] = tempScores[i];
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    load_image();
    srand(time(NULL));
    iSetTimer(30, update_jump);
    iSetTimer(30, change_obstacle);
    iSetTimer(30, update_running);
    iSetTimer(30, platform_collision);
    iSetTimer(1000, timerUpdate);
    iSetTimer(300, scoreUpdate);
    iSetTimer(20, portal_collisison);
    iSetTimer(30, diamond_collect);
    iSetTimer(160, update_zombie);
    iSetTimer(1500, changeZombiePosition);
    //   place your own initialization codes here.
    iInitializeSound();
    if (!gameOver && !level_complete)
    {
        iPlaySound("assets/sounds/finalbg.wav", true, 100);
    }
    iInitialize(1200, 850, "JUNGLE JUMBLE");

    return 0;
}