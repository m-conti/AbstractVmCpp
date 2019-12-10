//
// Created by matthieu CONTI on 05/12/2019.
//

#include "helpers.hpp"

void 	noTrailingZero(std::string &str) {
	if (str.find('.') != std::string::npos)
		str.erase(str.find_last_not_of('0') + 1, std::string::npos);
}