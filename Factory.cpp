//
// Created by Matthieu CONTI on 11/4/19.
//

#include "Factory.hpp"

IOperand const *createOperand( eOperandType type, std::string const &value ) {
	IOperand const *(*createOperandArray[OPERAND_NUMBER])( std::string const &value ) = {
			&createInt8,
			&createInt16,
			&createInt32,
			&createFloat,
			&createDouble
	};
	return ((*createOperandArray[static_cast<int>(type)])( value ));
}

IOperand const *createInt8( std::string const &value ) {
	return ( new TOperand<int8_t>( value, eOperandType::Int8 ) );
}

IOperand const *createInt16( std::string const &value ) {
	return ( new TOperand<int16_t>( value, eOperandType::Int16 ) );
}

IOperand const *createInt32( std::string const &value ) {
	return ( new TOperand<int32_t>( value, eOperandType::Int32 ) );
}

IOperand const *createFloat( std::string const &value ) {
	return ( new TOperand<float>( value, eOperandType::Float) );
}

IOperand const *createDouble( std::string const &value ) {
	return ( new TOperand<double>( value, eOperandType::Double) );
}