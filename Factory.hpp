//
// Created by Matthieu CONTI on 11/4/19.
//

#ifndef ABSTRACTVMCPP_FACTORY_HPP
# define ABSTRACTVMCPP_FACTORY_HPP

# define OPERAND_NUMBER 5

# include "TOperand.hpp"

class Factory {
public:
	IOperand const *			createOperand( eOperandType type, std::string const & value ) const;

private:
	IOperand const *			createInt8( std::string const & value ) const;
	IOperand const *			createInt16( std::string const & value ) const;
	IOperand const *			createInt32( std::string const & value ) const;
	IOperand const *			createFloat( std::string const & value ) const;
	IOperand const *			createDouble( std::string const & value ) const;
};


#endif //ABSTRACTVMCPP_FACTORY_HPP
