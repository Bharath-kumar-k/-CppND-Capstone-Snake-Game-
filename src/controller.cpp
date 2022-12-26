#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      if(e.key.keysym.sym == _Up){
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
      }else if (e.key.keysym.sym == _Down){
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
      }else if (e.key.keysym.sym == _Right){
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
      }else if (e.key.keysym.sym == _Left){
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
      }

      // switch (e.key.keysym.sym) {
      //   case _Up:
      //     ChangeDirection(snake, Snake::Direction::kUp,
      //                     Snake::Direction::kDown);
      //     break;

      //   case _Down:
      //     ChangeDirection(snake, Snake::Direction::kDown,
      //                     Snake::Direction::kUp);
      //     break;

      //   case _Right:
      //     ChangeDirection(snake, Snake::Direction::kLeft,
      //                     Snake::Direction::kRight);
      //     break;

      //   case _Left:
      //     ChangeDirection(snake, Snake::Direction::kRight,
      //                     Snake::Direction::kLeft);
      //     break;
      // }
    }
  }
} 