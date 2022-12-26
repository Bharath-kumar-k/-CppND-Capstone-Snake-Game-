#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <algorithm>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height){}

  void setInitHead(int x, int y){
  	head_x = x;
    head_y = y;
  }

  void GrowBody();
  void HitObs();
  bool SnakeCell(int x, int y);

  void Update();

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;


 private:
  void UpdateHead();
  // void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell, Snake &otherSnake);
    void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  bool hitObs{false};
  int grid_width;
  int grid_height;

};

#endif