//
// Created by Matthieu CONTI on 11/4/19.
//

# include "EOperandType.hpp"
# include "Vm.hpp"
# include "Factory.hpp"
# include "TOperand.hpp"

int main( int ac, char **av ) {

	Vm vm;

//	std::cout << "pop empty :" << std::endl;
//	vm.popNDelete();
	std::cout << "push Int8(122) :" << std::endl;
	vm.push( eOperandType::Int8, "0" );
	std::cout << "push Int16(122) :" << std::endl;
	vm.push( eOperandType::Int16, "122" );
	std::cout << "push Int32(-1) :" << std::endl;
	vm.push( eOperandType::Int32, "-1" );
	std::cout << "dump" << std::endl;
	vm.dump();
	std::cout << "pop" << std::endl;
	vm.popNDelete();
	std::cout << "dump" << std::endl;
	vm.dump();
	std::cout << "div :" << std::endl;
	vm.div();
	std::cout << "dump" << std::endl;
	vm.dump();
	return (0);
}