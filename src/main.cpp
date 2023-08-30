#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "recordsaver.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  std::string path{"../data/record.txt"};
  int max_result{0};

  RecordSaver recordsaver(path);
  recordsaver.Read(max_result);
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, max_result);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}