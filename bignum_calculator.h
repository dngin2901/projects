#include <iostream>
#include<stack>

#ifndef BIGNUM_CALCULATOR_H
#define BIGNUM_CALCULATOR_H

class bignum_calculator
{
	public:
		//used to represent bignum numbers. a bignum is a number in reverse order
		//i.e., the real number 1234 would be the bignum 4,3,2,1
		typedef  std::stack<int>bignum; //TODO: choose the appropriate data structure to represent a bignum

		//default constructor, needs no args
		bignum_calculator();

		//default destructor
		~bignum_calculator();

		//converts the number in str to a bignum and stores it in num
		void str_to_bignum(std::string str, bignum *num);

		//returns true if both bignums are the same, false otherwise
		bool compare_bignum(bignum num_1, bignum num_2);

		//converts the bignum number to a string and returns the value of said string
		std::string bignum_to_str(bignum num);

		//sums num_1 and num_2 and stores the result in sum
		void add(bignum num_1, bignum num_2, bignum *sum);

		//multiplies num_1 and num_2 and stores the result in product
		void multiply(bignum num_1, bignum num_2, bignum *product);

		//reverse stack
		void reverse_stack(std::stack<int>& s);




};

#endif