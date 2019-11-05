//
// Created by Matthieu CONTI on 2019-06-15.
//

#include "Vm.hpp"

Vm::Vm() {

}

Vm::~Vm() {
	for ( std::list<const IOperand *>::iterator it = stack.begin(); it != stack.end(); ++it ) {
		std::cout << "delete : " << (*it)->toString() << std::endl;
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
	stack.pop_front();
	return elem;
}

void Vm::popNDelete( void ) {
	delete pop(); // THROW ERROR
}

void Vm::dump( void ) {
	for ( std::list<const IOperand *>::iterator it = stack.begin(); it != stack.end(); ++it )
		std::cout << (*it)->toString() << std::endl;
}

void Vm::ass( eOperandType type, std::string const &value ) {
	const IOperand*	front = stack.front();
	const IOperand* op = createOperand( type, value );
	if ( front->toString() == op->toString() ) {
		delete op;
		// THROW ERROR
	}
	delete op;
}

void Vm::add( void ) {
	const IOperand *a = pop();
	const IOperand *b = pop();
	const IOperand *c = *a + *b;
	delete a;
	delete b;
	stack.push_front( c );
}

void Vm::sub( void ) {
	const IOperand *a = pop();
	const IOperand *b = pop();
	const IOperand *c = *a - *b;
	delete a;
	delete b;
	stack.push_front( c );
}

void Vm::mul( void ) {
	const IOperand *a = pop();
	const IOperand *b = pop();
	const IOperand *c = *a * *b;
	delete a;
	delete b;
	stack.push_front( c );
}

void Vm::div( void ) {
	const IOperand *a = pop();
	const IOperand *b = pop();
	const IOperand *c = *a / *b;
	delete a;
	delete b;
	stack.push_front( c );
}

void Vm::mod( void ) {
	const IOperand *a = pop();
	const IOperand *b = pop();
	const IOperand *c = *a % *b;
	delete a;
	delete b;
	stack.push_front( c );
}

void Vm::print( void ) {
	const IOperand* front = stack.front();

	if (front->getType() != eOperandType::Int8)
		; // THROW ERROR
	std::cout << std::stoi(front->toString());
}

void Vm::exit( void ) {

}
