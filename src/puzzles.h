#include "aoc.h"

#define DECLARE_PUZZLE(name) class name : public aoc::Puzzle { public: name() : Puzzle{ "name" } {} void part1() override; void part2() override; };

namespace puzzles
{

DECLARE_PUZZLE(Day1)
DECLARE_PUZZLE(Day2)

}
