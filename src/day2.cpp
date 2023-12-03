#include <iostream>
#include <unordered_map>
#include <string>
#include <cstddef>
#include <fstream>
#include <sstream>

#include "aoc.h"
#include "puzzles.h"

namespace puzzles
{

using Bag = std::unordered_map<std::string, int>;

class GameHint
{
  public:
    GameHint()
    {
    }

    int id() const { return _id; }
    Bag max() const { return _max; }

    bool is_game_possible(const Bag &bag) const
    {
      for (const auto &pair : bag)
      {
        if (pair.second < _max.at(pair.first)) return false;
      }
      return true;
    }

    friend std::istream &operator>>(std::istream &stream, GameHint &hint);

  private:
    int _id{ };
    Bag _max{ };
};

std::istream &operator>>(std::istream &stream, GameHint &hint)
{
  stream >> hint._id;
  char c;
  stream.get(c);
  while (c != '\n')
  {
    int count;
    stream >> count;
    std::stringstream color{ };
    for (stream.get(c); c != ',' && c != ';' && c !='\n'; stream.get(c))
    {
      if (c == ' ') continue;
      color << c;
    }
    if (hint._max[color.str()] < count) hint._max[color.str()] = count;
  }
  return stream;
}

/*
 * Part 1
 */

void Day2::part1()
{
  std::ifstream input_file{ aoc::get_input_path("day2.txt") };
  if (!input_file.good()) return;
  std::cout << "[+] Opened input file.\n";
  std::vector<GameHint> hints{ };
  std::string token;
  while (input_file >> token)
  {
    if (token != "Game") continue;
    GameHint hint{ };
    input_file >> hint;
    hints.push_back(hint);
  }
  std::cout << "[+] Deserialized " << hints.size() << " hints\n";
  int sum = 0;
  for (const GameHint &hint : hints)
  {
    if (hint.is_game_possible(Bag{ {"red", 12}, {"green", 13}, {"blue", 14} })) sum += hint.id(); 
  }
  std::cout << "[+] Result: " << sum << '\n';
}

/*
 * Part 2
 */

void Day2::part2()
{
  std::ifstream input_file{ aoc::get_input_path("day2.txt") };
  if (!input_file.good()) return;
  std::cout << "[+] Opened input file.\n";
  std::vector<GameHint> hints{ };
  std::string token;
  while (input_file >> token)
  {
    if (token != "Game") continue;
    GameHint hint{ };
    input_file >> hint;
    hints.push_back(hint);
  }
  std::cout << "[+] Deserialized " << hints.size() << " hints\n";
  int power = 0;
  for (const GameHint &hint : hints)
  {
    const Bag max = hint.max();
    power += max.at("red") * max.at("green") * max.at("blue");
  }
  std::cout << "[+] Result: " << power << '\n';
}

}
