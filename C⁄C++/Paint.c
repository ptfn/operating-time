#ifndef WINBGI_H
#define WINBGI_H
#include <windows.h>        // Provides the mouse message types
#include <limits.h>         // Provides INT_MAX
#include <sstream> 
#include <graphics.h>
#include<stdio.h>
main(){
    initwindow(400,300);
    putpixel(100,100,4)
    getch();
    closegraph();
}