#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <filesystem>

namespace aoc
{

inline void print_title(const std::string_view &title)
{
  std::cout << '\n' << R"(
             _                 _            __    _____          _      
    /\      | |               | |          / _|  / ____|        | |     
   /  \   __| |_   _____ _ __ | |_    ___ | |_  | |     ___   __| | ___ 
  / /\ \ / _` \ \ / / _ \ '_ \| __|  / _ \|  _| | |    / _ \ / _` |/ _ \
 / ____ \ (_| |\ V /  __/ | | | |_  | (_) | |   | |___| (_) | (_| |  __/
/_/    \_\__,_| \_/ \___|_| |_|\__|  \___/|_|    \_____\___/ \__,_|\___|
                                                                       
                                                                       )" << '\n';
  std::cout << '\n' << title << "\n\n";
}

inline std::filesystem::path get_input_path(const std::string_view &file_name)
{
  std::filesystem::path path { CHAL_INPUTS_PATH };
  return path / file_name;
}

class Puzzle abstract
{
  public:
    virtual void part1() = 0;
    virtual void part2() = 0; 

  protected:
    Puzzle(std::string_view name)
      : _name(name)
    {
    }

  private:
    const std::string _name;
};

}
