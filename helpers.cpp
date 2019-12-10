//
// Created by matthieu CONTI on 05/12/2019.
//

#include "helpers.hpp"

void 	noTrailingZero(std::string &str) {
	uint8_t	pos;
	if (str.find('.') != std::string::npos) {
		pos = (str.find_last_not_of('0') == str.find('.')) ? 0 : 1;
		str.erase(str.find_last_not_of('0') + pos, std::string::npos);
	}
}