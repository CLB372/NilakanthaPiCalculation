// This program calculates pi to 51 decimal places and displays it to the user.
// It does so by calculating the Nilakantha series out to 10,001 terms.
//
// The Nilakantha series convergence simplifies to pi = 3 + (4 / (2x3x4)) - (4 / (4x5x6)) + (4 / (6x7x8)) - (4 / (8x9x10)) +...
//
// It converges to pi faster than other solutions like the Leibniz series, which makes it especially useful
// for a toy program/compiler with only standard libraries and data types available (as opposed to, for example,
// the GNU MPFR library that can handle more decimal places). The Nilakantha series requires fewer terms than the
// Leibniz series to achieve comparable accuracy.

#include "pch.h"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "         PI CALCULATION PROGRAM     Created by Chris Bryant. Jan. 2019. clb372@cornell.edu\n\n"
		<< "This program uses the Nilakantha series to calculate pi to 51 decimal places.\n"
		<< "The Nilakantha series converges to pi faster than the Leibniz series, which makes it a superior choice for a\n"
		<< "simple program with relatively few iterations and decimal places. It makes the result more accurate, quicker."
		<< "\n\nRESULT:\n\n";

	double sum = 3;
	int signflip = 1.0;

	for (double i = 2.0; i < 10000; i = i + 2.0)
	{
		sum = sum + (4.0 * signflip) / (i * (i + 1.0) * (i + 2.0));

		signflip *= -1;
	}

	std::cout << std::setprecision(52) << sum << "\n\nProgram complete.\n\n";

	std::cin.ignore();

	return 0;
}


