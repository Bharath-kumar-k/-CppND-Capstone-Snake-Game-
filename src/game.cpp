#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      l_snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  snake.setInitHead(random_w(engine),random_h(engine));
  l_snake.setInitHead(random_w(engine),random_h(engine));
  PlaceFood();
  PlaceObstruction();
  level = 1;
}

void Game::Run(Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  Controller r_controller(SDLK_UP, SDLK_DOWN, SDLK_RIGHT, SDLK_LEFT);
  Controller l_controller(SDLK_w, SDLK_s, SDLK_d, SDLK_a);
  	
  int iter = 1;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.

    // controller.HandleInput(running, snake);

    // Input, Update, Render - the main game loop.
    std::thread rInput(&Controller::HandleInput, r_controller, std::ref(running), std::ref(snake));
    std::thread lInput(&Controller::HandleInput, l_controller, std::ref(running), std::ref(l_snake));
    rInput.join();
    lInput.join();

    Update();
    renderer.Render(snake, l_snake, food, obstruction);

    if(iter%1000 == 0){
      PlaceObstruction();
      level++;
      snake.speed += 0.02;
      l_snake.speed += 0.02;
    }
    iter++;
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      // renderer.UpdateWindowTitle(score, frame_count);
      renderer.UpdateWindowTitle(level,score,snake.size,frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive || !l_snake.alive) return;

  // Check if there's obs over here
  for (auto const &obs : obstruction){
    if (obs.x == static_cast<int>(snake.head_x) && 
        obs.y == static_cast<int>(snake.head_y)) {
      snake.HitObs();
      snake.alive = false;
      return;
    }
    if (obs.x == static_cast<int>(l_snake.head_x) && 
        obs.y == static_cast<int>(l_snake.head_y)) {
      l_snake.HitObs();
      l_snake.alive = false;
      return;
    }
  }

  // snake collision check
  for (auto const &item : snake.body) {
    if (static_cast<int>(snake.head_x) == item.x && static_cast<int>(snake.head_y) == item.y) {
      snake.alive = false;
      return;
    }
  }
  if (static_cast<int>(snake.head_x) == static_cast<int>(l_snake.head_x) && static_cast<int>(snake.head_y) == static_cast<int>(l_snake.head_y) ) {
    snake.alive = false;
    return;
  }
  for (auto const &item : l_snake.body) {
    if (static_cast<int>(l_snake.head_x) == item.x && static_cast<int>(l_snake.head_y) == item.y) {
      l_snake.alive = false;
      return;
    }
  }
  if (static_cast<int>(l_snake.head_x) == static_cast<int>(snake.head_x) && static_cast<int>(l_snake.head_y) == static_cast<int>(snake.head_y) ) {
    l_snake.alive = false;
    return;
  }

  // std::thread rSnakeUpdate(&Snake::Update, snake);
  // std::thread lSnakeUpdate(&Snake::Update ,l_snake);
  // rSnakeUpdate.join();
  // lSnakeUpdate.join();

  snake.Update();
  l_snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  int l_new_x = static_cast<int>(l_snake.head_x);
  int l_new_y = static_cast<int>(l_snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    // snake.speed += 0.02;
  }

  // Check if there's food over here
  if (food.x == l_new_x && food.y == l_new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    l_snake.GrowBody();
    // snake.speed += 0.02;
  }

}

  void Game::PlaceObstruction(){
  for(int i=0;i<2;i++){
  SDL_Point obs;
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing obstacle.
    if (!snake.SnakeCell(x, y)) {
      obs.x = x;
      obs.y = y;
      obstruction.emplace_back(obs);
      break;
    }
  }
  }

  }


int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
int Game::GetLevel() const { return level; }