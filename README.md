# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Game objective and rules
* This game is a two hand Snake game play.
  * Objective of the game: 
    * Eat maximum food with out hitting the end game
  * Controllers: 
    * Right hand control: Up, Down, Left and Right key in keyboard
    * Left hand control: W, S, A and D in keyboard 
  * Increasing dynamic Obstacle: 
    * After every few frames/ time, 2 random obstruction is introduced in the game environment
    * The speed of both the snakes also increases by factor od 0.02 at the same regular intervals
	* The total score is incremented if either of the snake ate a food
  * Snakes grows after it eats food
  * End game: The game ends, 
    * If a left hand controlled snake collides with right hand controlled snake.
    * If any snake collides with its own body it dies.
    * If either of the snakes dies but hitting the obstacle.
    

## list of the Rubric points 
* Rubric points
	  * README
    	* Project Chossen : 2 Snake Game
        * The README is included with the project and has instructions for building/running the project.

    * Compiling and Testing
    	* The project code is compiled and ran without errors. cmake and make is used.

    * Loops, Functions, I/O
    	* The project demonstrates an understanding of C++ functions and control structures:
        * Check: PlaceObstruction() in game.cpp 
      * The project reads data from a file and process the data, or the program writes data to a file.
        * Check: "Controller.cpp" method "HandleInput", where two controllers from keyboard are taken
      * The project accepts user input and processes the input.
        * Check: "Controller.cpp" method "HandleInput", where two controllers from keyboard are taken

    * Object Oriented Programming
    	* The project uses Object Oriented Programming techniques:
        * Snake Class, Game Class, Renderer and Controller Class.
      * Classes use appropriate access specifiers for class members: 
        * All class memebers and member function are using the appropriate acess specifiers. Check *.cpp && *.h files
      * Class constructors utilize member initialization lists:
        * Check Snake, Game, Renderer and Controller Class constructor
      * Classes encapsulate behavior: 
        * Check Snake, Game, Renderer and Controller Class private members
      * Overloaded functions allow the same function to operate on different parameters:
        * Check UpdateWindowTitle() in renderer.h 

    * Memory Management
    	* The project makes use of references in function declarations: 
        * Check Run() in Game.h 
        * Check Controller() constructor && HandleInput() in Controller.h
      * The project uses destructors appropriately:
        * Check ~Renderer() in renderer.cpp
      * The project uses move semantics to move data, instead of copying it, where possible.
        * emplace_back() is used in PlaceObstruction() in game.cpp. emplace_back() uses move semantics which is defined in vector class
    
    * Concurrency
    	* The project uses multithreading: 
        * Check Run() in Game.cpp to run Controller.HandleInput() simulatenously from both hand input.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
