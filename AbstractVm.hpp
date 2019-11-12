//
// Created by matthieu CONTI on 12/11/2019.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP

# include <fstream>
# include <string>
# include <sstream>
# include <iostream>
# include <array>
# include <regex>


# include "EOperandType.hpp"
# include "Vm.hpp"
# include "Factory.hpp"
# include "TOperand.hpp"

void	parseLine(Vm &vm, std::string const &line);
void	parseFile(Vm &vm, std::string const &file_name);
void	parseInput(Vm &vm);


#endif //ABSTRACTVM_ABSTRACTVM_HPP
