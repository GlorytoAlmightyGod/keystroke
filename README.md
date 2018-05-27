# keystroke

Purpose for adding this to github
  - Often we find ourselves in a situation wherein we want to simulate keystrokes for some major project so one could easily use this C program without any waste of time.
  
Pre-Requisites
  - Any Linux platform with **C++ & Bash**
  - X11
  
Installation
  - sudo apt install libx11-dev
  - sudo apt-get install libxtst-dev
  - sudo apt-get install x11-utils

Functions/Features
  
  - Simple C program to simulate required keystrokes.
  - One can add required keystrokes as follows:
      - type **xev** on terminal and hit enter.
      - now hit the key you wanna find the keycode value for.
      - you can see that information related to the key appears in the terminal.
      

How to Use?
  - Compile using      gcc -o key keypress.c -lX11 -lXtst
  - Run **./key x**   ,where **x is a number** corresponding to the keystroke you wanna imply.
  - See the program in case of any silly doubts.
