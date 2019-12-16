//
// Created by Matthieu CONTI on 2019-06-15.
//

#include "Vm.hpp"

Vm::Vm() {

}

Vm::~Vm() {
	for ( std::list<const IOperand *>::iterator it = stack.begin(); it != stack.end(); ++it ) {
		delete (*it);
	}
}

Vm &Vm::operator=( Vm const &rhs ) {
	if ( this != &rhs ) {

	}
	return (*this);
}

void Vm::push( eOperandType type, std::string const &value ) {
	stack.push_front( createOperand( type, value ));
}

IOperand const *Vm::pop( void ) {
	IOperand const *elem = stack.front();
	if ( !elem ) {
		throw EmptyStackException();
	}
	stack.pop_front();
	return elem;
}

void Vm::popNDelete( void ) {
	try {
		delete pop();
	}
	catch ( EmptyStackException &e ) {
		throw PopEmptyStackException();
	}

}

void Vm::dump( void ) {
	for ( std::list<const IOperand *>::iterator it = stack.begin(); it != stack.end(); ++it )
		std::cout << (*it)->toString() << std::endl;
}

void Vm::ass( eOperandType type, std::string const &value ) {

	if (stack.size() <= 0)
		throw (EmptyStackException());

	const IOperand *front = stack.front();
	const IOperand *op = createOperand( type, value );

	if ( front->getPrecision() != op->getPrecision() ) {
		delete op;
		throw FailAssertTypeException();
	}

	if ( front->toString() != op->toString() ) {
		delete op;
		throw FailAssertValueException();
	}
	delete op;
}

void Vm::add( void ) {
	if (stack.size() < 2) {
		throw OperandMissingException();
	}

	const IOperand *a = pop();
	const IOperand *b = pop();
	try {
		stack.push_front( *a + *b );
	}
	catch (std::exception &e) {
		delete a;
		delete b;
		throw ;
	}
	delete a;
	delete b;
}

void Vm::sub( void ) {
	if (stack.size() < 2) {
		throw OperandMissingException();
	}

	const IOperand *a = pop();
	const IOperand *b = pop();
	try {
		stack.push_front( *a - *b );
	}
	catch (std::exception &e) {
		delete a;
		delete b;
		throw ;
	}
	delete a;
	delete b;
}

void Vm::mul( void ) {
	if (stack.size() < 2) {
		throw OperandMissingException();
	}

	const IOperand *a = pop();
	const IOperand *b = pop();
	try {
		stack.push_front( *a * *b );
	}
	catch (std::exception &e) {
		delete a;
		delete b;
		throw ;
	}
	delete a;
	delete b;
}

void Vm::div( void ) {
	if (stack.size() < 2) {
		throw OperandMissingException();
	}

	const IOperand *a = pop();
	const IOperand *b = pop();
	try {
		stack.push_front( *a / *b );
	}
	catch (std::exception &e) {
		delete a;
		delete b;
		throw ;
	}
	delete a;
	delete b;
}

void Vm::mod( void ) {
	if (stack.size() < 2) {
		throw OperandMissingException();
	}

	const IOperand *a = pop();
	const IOperand *b = pop();
	try {
		stack.push_front( *a % *b );
	}
	catch (std::exception &e) {
		delete a;
		delete b;
		throw ;
	}
	delete a;
	delete b;
}

void Vm::print( void ) {
	const IOperand *front = stack.front();

	if (stack.size() <= 0)
		throw (EmptyStackException());
	if ( front->getType() != eOperandType::Int8 )
		throw PrintNoCharException();
	std::cout << static_cast<char>(std::stoi(front->toString()));
}

void Vm::exit( void ) {

}
