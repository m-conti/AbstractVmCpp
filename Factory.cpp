//
// Created by Matthieu CONTI on 11/4/19.
//

#include "Factory.hpp"

IOperand const *Factory::createOperand( eOperandType type, std::string const & value ) const {
	IOperand const *	(Factory::*createOperandArray[OPERAND_NUMBER])(std::string const & value) const = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	return ( (this->*createOperandArray[static_cast<int>(type)])(value) );
}

IOperand const *Factory::createInt8( std::string const & value ) const {
	return ( new TOperand<int8_t>(std::stoi(value), eOperandType::Int8) );
}

IOperand const *Factory::createInt16( std::string const & value ) const {
	return ( new TOperand<int16_t>(std::stoi(value), eOperandType::Int16) );
}

IOperand const *Factory::createInt32( std::string const & value ) const {
	return ( new TOperand<int32_t>(std::stoi(value), eOperandType::Int32) );
}

IOperand const *Factory::createFloat( std::string const & value ) const {
	return nullptr;
}

IOperand const *Factory::createDouble( std::string const & value ) const {
	return nullptr;
}