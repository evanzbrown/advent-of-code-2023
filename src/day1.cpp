#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "aoc.h"
#include "puzzles.h"

/*
 * Part 1
 */
namespace puzzles
{

void Day1::part1()
{
  std::ifstream input_file{ aoc::get_input_path("day1.txt") };
  if (!input_file.good()) return;
  std::cout << "[+] Opened input file.\n";
  int sum = 0;
  std::string token;
  while (input_file >> token)
  {
    std::vector<int> digits{ }; 
    for (char c : token)
    {
      if (c < '0' || c > '9') continue;
      digits.push_back(static_cast<int>(c - '0'));
    }
    const int value = digits.front() * 10 + digits.back();
    sum += value;
  }
  std::cout << "[+] Result: " << sum << '\n';
  return;
}

/*
 * Part 2
*/

const std::unordered_map<std::string, int> word_digits {
  {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
  {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

std::vector<int> get_digits(const std::string_view &line)
{
  std::vector<int> result{ };
  for (int i = 0; i < line.length(); ++i)
  {
    if (line[i] >= '0' && line[i] <= '9') result.push_back(line[i] - '0');
    for (const auto &pair : word_digits)
    {
      if (line.substr(i, pair.first.length()) == pair.first)
      {
        result.push_back(pair.second);
      }
    }
  }
  return result;
}

void Day1::part2()
{
  std::ifstream input_file{ aoc::get_input_path("day1.txt") };
  if (!input_file.good()) return;
  std::cout << "[+] Opened input file.\n";
  int sum = 0;
  std::string line;
  while (input_file >> line)
  {
    std::vector<int> digits = get_digits(line);
    const int value = digits.front() * 10 + digits.back();
    sum += value;
  }
  std::cout << "[+] Result: " << sum << '\n';
  return;
}

}
