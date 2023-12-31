//
// Created by Aweso on 12/23/2023.
//
/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   OpenProject Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "../drawMain.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = -1;
static Button projectButtons[MAX_PROJECT_COUNT] = {0};
static char * projectNames;
static float buttonHeight = 100;
static float buttonWidth = 250;
static float bigButtonHeight = 100;
static float bigButtonWidth = 250;
static Button deleteBut;
static Button openBut;
static Button backBut;

//----------------------------------------------------------------------------------
// OpenProject Screen Functions Definition
//----------------------------------------------------------------------------------

// OpenProject Screen Initialization logic
void InitOpenProjectScreen(void)
{
    // TODO: Initialize OpenProject screen variables here!
    framesCounter = 0;
    finishScreen = -1;
    buttonHeight = screenHeight/9;
    buttonWidth = screenWidth * 63.0f/400.0f;
    for(int i = 0;i < projectCount;i++){
        //printf("Project %d\n",i);
        projectNames = getProjectNames();
        strncpy(projectButtons[i].text,&projectNames[i*20],20);
        projectButtons[i].color = theme.dark;
        projectButtons[i].textColor = theme.white;
        projectButtons[i].isSelected = false;
        projectButtons[i].isPressed = false;
        projectButtons[i].isToggle = false;
        projectButtons[i].rect.x = screenWidth*0.05 + (buttonWidth + screenWidth* 9.0f/320.0f)*(i%5);
        projectButtons[i].rect.y = screenHeight*0.05 + (i/5) * (buttonHeight*1.25);
        projectButtons[i].rect.width = buttonWidth;
        projectButtons[i].rect.height = buttonHeight;
        //printf("x:%f, y:%f, w:%f, h:%f\n",projectButtons[i].rect.x,projectButtons[i].rect.y,projectButtons[i].rect.width,projectButtons[i].rect.height);
    }

    bigButtonHeight = 2 * buttonHeight;
    //bigButtonWidth = screenWidth * 0.9 * 5/16 - screenWidth/480;
    bigButtonWidth = screenWidth * 67/240;

    openBut = (Button){
        "Open Project",
        (Rectangle){screenWidth*0.05,screenHeight*0.75,bigButtonWidth,bigButtonHeight},
        theme.accent1,
        theme.white,
        false,
        false,
        false

    };
    deleteBut = (Button){
            "Delete Project",
            (Rectangle){screenWidth*0.05 + bigButtonWidth + screenWidth/32,screenHeight*0.75,bigButtonWidth,bigButtonHeight},
            theme.accent2,
            theme.white,
            false,
            false,
            false
    };
    backBut = (Button){
            "Back",
            (Rectangle){screenWidth*0.05 + 2*(bigButtonWidth + screenWidth/32),screenHeight*0.75,bigButtonWidth,bigButtonHeight},
            theme.black,
            theme.white,
            false,
            false,
            false
    };
}

// OpenProject Screen Update logic
void UpdateOpenProjectScreen(void)
{
    // TODO: Update OpenProject screen variables here!
    for(int i = 0;i<projectCount;i++){
        IsButtonPressed(&projectButtons[i]);
    }
    IsButtonPressed(&openBut);
    IsButtonPressed(&deleteBut);
    if(IsButtonPressed(&backBut))finishScreen = TITLE;
}

// OpenProject Screen Draw logic
void DrawOpenProjectScreen(void)
{
    // TODO: Draw OpenProject screen here!
    DrawRectangle(0, 0, screenWidth, screenHeight, theme.light);

    for(int i = 0;i<projectCount;i++){
        DrawButton(&projectButtons[i]);
    }
    DrawButton(&openBut);
    DrawButton(&deleteBut);
    DrawButton(&backBut);
}

// OpenProject Screen Unload logic
void UnloadOpenProjectScreen(void)
{
    // TODO: Unload OpenProject screen variables here!
    free(projectNames);
}

// OpenProject Screen should finish?
int FinishOpenProjectScreen(void)
{
    return finishScreen;
}