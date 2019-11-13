//
// Created by matthieu CONTI on 13/11/2019.
//

#ifndef ABSTRACTVMCPP_PARSER_HPP
#define ABSTRACTVMCPP_PARSER_HPP

# include "AbstractVm.hpp"

class Vm;

void	parseLine(Vm &vm, std::string const &line);
void	parseFile(Vm &vm, std::string const &file_name);
void	parseInput(Vm &vm);

#endif //ABSTRACTVMCPP_PARSER_HPP
