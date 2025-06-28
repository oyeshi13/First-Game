#include "iGraphics.h"
#include "iSound.h"
#include <windows.h>
int jumpLimit = 180;
int minnieHeight = 239;
int minnieWidth = 187;
int timer1 = 70;
int timer2 = 50;
int timer3 = 40;
int timer4 = 30;
int timer5 = 25;
int scoreLeft = 1010;
Image menu, leaderboard, help, obstacle_1, obstacle_2, player_name, gameover, diamond, level_comp;
// char minnie_idle[2][100]={"assets/images/idle/1.png","assets/images/idle/2.png"};
char minnie_running[6][100] = {"assets/images/My Game/minnie_running/tile000.png", "assets/images/My Game/minnie_running/tile001.png", "assets/images/My Game/minnie_running/tile002.png", "assets/images/My Game/minnie_running/tile003.png", "assets/images/My Game/minnie_running/tile004.png", "assets/images/My Game/minnie_running/tile005.png"};
char minnie_jumping[6][100] = {"assets/images/My Game/minnie_jumping/jumping000.png", "assets/images/My Game/minnie_jumping/jumping001.png", "assets/images/My Game/minnie_jumping/jumping002.png", "assets/images/My Game/minnie_jumping/jumping003.png", "assets/images/My Game/minnie_jumping/jumping004.png", "assets/images/My Game/minnie_jumping/jumping005.png"};
char digbazi[6][100] = {"assets/images/My Game/minnie_digbazi/digbazi000.png", "assets/images/My Game/minnie_digbazi/digbazi001.png", "assets/images/My Game/minnie_digbazi/digbazi002.png", "assets/images/My Game/minnie_digbazi/digbazi003.png", "assets/images/My Game/minnie_digbazi/digbazi004.png", "assets/images/My Game/minnie_digbazi/digbazi005.png"};
char level[5][100] = {"assets/images/My Game/level/level 1.jpg", "assets/images/My Game/level/level 2.png", "assets/images/My Game/level/level 3.png", "assets/images/My Game/level/level 4.png", "assets/images/My Game/level/level 5.png"};
// bg1,bg2,bg3,bg4,space_images[3];
int game_state = 0;
int minnieX = 30;
int minnieY = 150;
int groundY = 150;
int minnie_idx = 0;
int minnie_jump = 0;
int minnie_width = 140;
int minnie_height = 200;
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
int diamondY = 650;
int diamond_width = 70;
int diamond_height = 100;
bool level_complete = false;
bool show_diamond = true;
// int minnie_jump_idx=0;
/*
function iDraw() is called again and again by the system.
*/

void load_image()
{
    iLoadImage(&menu, "assets/images/My Game/Menu.jpg");
    iLoadImage(&leaderboard, "assets/images/My Game/leaderboard 3.png");
    iLoadImage(&help, "assets/images/My Game/help.png");
    iLoadImage(&player_name, "assets/images/My Game/player name.png");
    iLoadImage(&obstacle_1, "assets/images/My Game/obstacle_1.png");
    iLoadImage(&obstacle_2, "assets/images/My Game/obstacle_2.png");
    iLoadImage(&gameover, "assets/images/My Game/Game_over.png");
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
        // iSetColor(255, 0, 0);
        // iFilledRectangle(0, 0, 200, 200);
    }
    else if (game_state == 1)
    {
        if (levels == 0)
        {
            iSetColor(212, 120, 28);
            iFilledRectangle(501, 418, 190, 21);
            iShowImage(0, 0, "assets/images/My Game/player name.png");
        }
        for (int i = 0; i <= 5; i++)
        {
            // if(!isJumping && !isRunning){
            //         isStanding=true;
            //     }
            if (levels == i + 1)
            {
                iShowImage(0, 0, level[i]);
                if (levels == 1)
                {
                    // iText(1000,700,"Timer:%d",GLUT_BITMAP_TIMES_ROMAN_24);
                    sprintf(timer, "Time Left: %d", timer1);
                    sprintf(score, "Score: %d", scoreLeft);
                    iShowImage(platform1X, platform1Y, "assets/images/My Game/obstacle_1.png");
                    iShowImage(platform2X, platform2Y, "assets/images/My Game/obstacle_2.png");
                    iShowImage(platform3X, platform3Y, "assets/images/My Game/obstacle_1.png");
                    iShowImage(platform4X, platform4Y, "assets/images/My Game/obstacle_2.png");
                    iShowImage(platform5X, platform5Y, "assets/images/My Game/obstacle_2.png");
                    iShowImage(platform6X, platform6Y, "assets/images/My Game/obstacle_2.png");
                    if (show_diamond)
                    {
                        iShowImage(diamondX, diamondY, "assets/images/My Game/diamond.png");
                    }
                    iSetColor(255, 255, 255);
                    iText(1000, 800, timer, GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(70, 800, score, GLUT_BITMAP_TIMES_ROMAN_24);
                }
                if (isStanding)
                {
                    iShowImage(minnieX, minnieY, minnie_jumping[0]);
                }

                else
                {
                    if (isRunning)
                    {
                        iShowImage(minnieX, minnieY + minnie_jump, minnie_running[minnie_running_idx]);
                        Sleep(35);
                    }
                    else if (isJumping)
                    {
                        isRunning = false;
                        iShowImage(minnieX, minnieY + minnie_jump, minnie_jumping[minnie_jumping_idx]);
                    }
                }
                if (gameOver)
                {
                    iShowImage(0, 0, "assets/images/My Game/Game_over.png");
                    count++;
                    if (count >= 70)
                    {
                        game_state = 0;
                    }
                }
                int k = 0;
                if (level_complete)
                {
                    iShowImage(0, 0, "assets/images/My Game/level_complete.jpg");
                    k++;
                    if(k >= 10)
                    {
                        levels=2;
                        level_complete=false;
                    }
                }
            }
        }
    }
    if (game_state == 2)
    {
        iShowImage(0, 0, "assets/images/My game/leaderboard 3.png");
    }
    if (game_state == 3)
    {
        iShowImage(0, 0, "assets/images/My Game/help.png");
    }
}
// void platform_collision(){
//     if(minnieX+minnie_width>=platform4X&&minnieX<=platform4X+obstacle2_width){
//         if(minnieY+minnie_jump>=platform4Y+obstacle2_height){
//             minnie_jump=platform4Y+obstacle2_height;
//              onPlatform=true;
//         }

//     }
// }
void scoreUpdate()
{
    scoreLeft--;
}
void timerUpdate()
{
    if (levels == 1)
    {
        if (timer1 > 0)
        {
            timer1--;
        }
        if (timer1 == 0)
        {
            gameOver = true;
        }
    }
    if (levels == 2)
    {
        if (timer2 > 0)
        {
            timer2--;
        }
    }
    if (levels == 3)
    {
        if (timer3 > 0)
        {
            timer3--;
        }
    }
    if (levels == 4)
    {
        if (timer4 > 0)
        {
            timer4--;
        }
    }
    if (levels == 5)
    {
        if (timer5 > 0)
        {
            timer5--;
        }
    }
}
void platform_collision()
{
    int minnieFeetX1 = minnieX;
    int minnieFeetX2 = minnieX + minnie_width;
    int minnieFeetY = minnieY + minnie_jump;
    if (minnieFeetX2 >= platform4X && minnieFeetX1 <= platform4X + obstacle2_width)
    {
        if (minnieFeetY >= platform4Y + obstacle2_height - 5 && minnieFeetY <= platform4Y + obstacle2_height + 10 && !jumpUp)
        {
            // minnie_jump=0;
            //  minnieY = platform4Y + obstacle2_height-minnie_jump;
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
            // minnie_jump=0;
            //  minnieY = platform4Y + obstacle2_height-minnie_jump;
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
            // minnie_jump=0;
            //  minnieY = platform4Y + obstacle2_height-minnie_jump;
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
            // minnie_jump=0;
            //  minnieY = platform4Y + obstacle2_height-minnie_jump;
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
            // minnie_jump=0;
            //  minnieY = platform4Y + obstacle2_height-minnie_jump;
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
            // minnie_jump=0;
            //  minnieY = platform4Y + obstacle2_height-minnie_jump;
            onPlatform6 = true;
            onPlatform1 = onPlatform2 = onPlatform3 = onPlatform4 = onPlatform5 = false;
        }
    }
    else
    {
        onPlatform6 = false;
    }
}
void diamond_collect()
{
    int minnieFeetX1 = minnieX;
    int minnieFeetX2 = minnieX + minnie_width;
    int minnieFeetY = minnieY + minnie_jump;
    if (minnieFeetX2 > diamondX - 5 && minnieFeetX1 < diamondX + diamond_width + 5)
    {
        if (minnieFeetY > diamondY - 5 && minnieFeetY < diamondY + diamond_height + 5)
        {
            level_complete = true;
            show_diamond = false;
        }
    }
}
void change_obstacle()
{
    platform1X += dx * dx1;
    platform2X += dx * dx2;
    if (platform1X + obstacle1_width >= 1200 || platform1X <= 0)
    {
        dx1 *= -1;
    }
    else if (platform2X + obstacle2_width >= 1200 || platform2X <= 0)
    {
        dx2 *= -1;
    }
}
void update_running()
{
    if (onPlatform3)
    {
        // if(minnie_jump<(platform3Y+obstacle1_height)){
        //     minnie_jump=platform3Y+obstacle1_height;

        // }
        minnieY = platform3Y + obstacle1_height;
    }
    if (onPlatform4)
    {
        minnieY = platform4Y + obstacle2_height;
    }
    if (onPlatform5)
    {
        minnieY = platform5Y + obstacle2_height;
    }
    if (onPlatform6)
    {
        minnieY = platform6Y + obstacle2_height;
    }
    if (onPlatform1)
    {
        minnieY = platform1Y + obstacle1_height;
        minnieX += dx * dx1;
    }
    if (onPlatform2)
    {
        minnieY = platform2Y + obstacle2_height;
        minnieX += dx * dx2;
    }
    if (!onPlatform1 && !onPlatform2 && !onPlatform3 && !onPlatform4 && !onPlatform5 && !onPlatform6 && !isJumping && minnieY > 150)
    {
        minnieY -= 10;
        if (minnieY <= 150)
        {
            minnieY = 150;
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
            if (minnieY + minnie_jump >= 900)
            {
                jumpUp = false;
            }
        }

        else
        {
            // if (onPlatform3 && minnieY < platform3Y + obstacle1_height)
            // {
            //     minnieY = platform3Y + obstacle1_height;
            // }
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
        while (game_state == 0)
        {
            if (mx >= 100 && mx <= 379)
            {
                if (my >= 94 && my <= 181)
                {
                    iPlaySound("assets/sounds/mouse_click.wav", false, 100);
                    game_state = 1;
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
            j++;
        }
        j = 0;
        while (j < 1)
        {
            if (mx >= 477 && mx <= 721)
            {
                if (my >= 405 && my <= 444)
                {
                    iPlaySound("assets/sounds/mouse_click.wav", false, 100);
                    // FILE *playername=(player_name);
                    game_state = 1;
                    levels = 1;
                }
            }
            j++;
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
        minnieX -= 10;
        minnie_running_idx--;
        if (minnie_running_idx <= 1)
        {
            minnie_running_idx = 5;
        }
        if (minnieX <= -50)
        {
            minnieX = 1210;
        }
        // if(minnieX+minnieWidth>=obstacle_1_X&&minnieX+minnieWidth<=obstacle_1_X+150){
        //     if(minnieY>=350){
        //         onPlatform=true;
        //     }
        // }
        // d
        // it(0);
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
        if (minnieX >= 1200)
        {
            minnieX = -10;
        }
        // isRunningB=false;
        minnieX += 10;
        // if(minnieX+minnieWidth>=obstacle_1_X&&minnieX+minnieWidth<=obstacle_1_X+150){
        //     if(minnieY>=250){
        //         onPlatform=true;
        //     }
        // }
        break;
    case GLUT_KEY_UP:
        if (!isJumping)
        {
            isJumping = true;
            jumpUp = true;
        }

        // if(minnieX+minnieWidth>=obstacle_1_X&&minnieX+minnieWidth<=obstacle_1_X+150){
        //     if(minnieY+minnie_jump>=250){
        //         onPlatform=true;
        //     }
        // }
        break;
    case GLUT_KEY_END:
        exit(0);
    case GLUT_KEY_HOME:
        game_state = 0;
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    load_image();
    // space();
    // iSetTimer(150,update_minnie);
    // iSetTimer(150,update_running);
    //  if(game_state==2){
    iSetTimer(45, update_jump);
    iSetTimer(50, change_obstacle);
    iSetTimer(50, update_running);
    iSetTimer(50, platform_collision);
    iSetTimer(1000, timerUpdate);
    iSetTimer(300, scoreUpdate);
    iSetTimer(30, diamond_collect);
    // place your own initialization codes here.
    iInitializeSound();
    iInitialize(1200, 850, "MY GAME");

    return 0;
}