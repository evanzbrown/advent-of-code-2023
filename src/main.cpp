#include <unordered_map>
#include <memory>

#include "aoc.h"
#include "puzzles.h"

const std::unordered_map<int, std::shared_ptr<aoc::Puzzle>> my_puzzles {
  { 1, std::make_shared<puzzles::Day1>() },
  { 2, std::make_shared<puzzles::Day2>() }
};

void reset_input()
{
  std::cin.clear();
  std::cin.ignore();
}

int prompt_puzzle_day()
{
  std::cout << "[+] Select puzzle for day: ";
  int day;
  while (!(std::cin >> day))
  {
    reset_input();
    std::cout << "[+] Select puzzle for day: ";
  }
  return day;
}

int prompt_puzzle_part()
{
  std::cout << "[+] Part 1 or 2: ";
  int part;
  while (!(std::cin >> part))
  {
    reset_input();
    std::cout << "[+] Part 1 or 2: ";
  }
  return part;
}

int main()
{
  system("cls");
  aoc::print_title("Selector");
  int day = prompt_puzzle_day();
  while (!my_puzzles.count(day))
  {
    std::cout << "[!] Invalid day specified.\n";
    day = prompt_puzzle_day();
  }
  int part = prompt_puzzle_part();
  while (part != 1 && part != 2)
  {
    std::cout << "[!] Invalid part specified.\n";
    part = prompt_puzzle_part();
  }
  if (part == 1) my_puzzles.at(day)->part1();
  else my_puzzles.at(day)->part2();
  return 0;
}
