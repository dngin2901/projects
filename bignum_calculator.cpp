#include "bignum_calculator.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>
//#include <cstdlib>
//#include <bits/stdc++.h>
using namespace std;


typedef bignum_calculator::bignum bignum;

bignum_calculator::bignum_calculator() {
	//nothing to do here
}

bignum_calculator::~bignum_calculator() {
	//nothing to do here
}

void bignum_calculator::reverse_stack(stack<int>& s) {
    queue<int> q;
    // push all elements of stack to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    // push all elements of the queue back to stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
}

void bignum_calculator::str_to_bignum(std::string str, bignum *num) {
	//TODO//converts the number in str to a bignum and stores it in num

	int n = str.length();
    for (int i = 0; i < n; i++){
		num->push((int)(str[i]-'0'));
    }
}

bool bignum_calculator::compare_bignum(bignum num_1, bignum num_2) {
	//TODO		//returns true if both bignums are the same, false otherwise
	bool check = true;
	if(num_1.size() != num_2.size()){
		check = false;
		return check;
	}
	while (num_1.empty() == false){
		if(num_1.top() == num_2.top()){
			num_1.pop();
			num_2.pop();
		}
		else{
			check = false;
			return check;
		}
	}
	return check;
}

std::string bignum_calculator::bignum_to_str(bignum num) {
	//TODO//converts the bignum number to a string and returns the value of said string
	std::string s;
	while(!num.empty()){
		s.append(std::to_string(num.top()));
		num.pop();
	}
	return s;
}

void bignum_calculator::add(bignum num_1, bignum num_2, bignum *sum) {
	//TODO	//sums num_1 and num_2 and stores the result in sum

	int total = 0;
	int carry = 0;

		//calculate addition of "num_1" and "num_2" with carry
		while(!num_1.empty() || !num_2.empty())
		{

			if (!num_1.empty())
			{

				if(!num_2.empty())
				{
					total = ((num_1.top()) + (num_2.top()) + carry);
					num_1.pop();
					num_2.pop();
					carry = total / 10;
					sum->push(total % 10);
				}

					// if "num_1" is the only number left
					else
					{
						total = (num_1.top() + carry);
						num_1.pop();
						carry = total / 10;
						sum->push(total % 10);
					}
			}

				//if "num_2" is the only number left
				else
				{
					total = (num_2.top() + carry);
					num_2.pop();
					carry = total / 10;
					sum->push(total % 10);
				}
		}

		// add remaining carry
		if (carry != 0)
		{
			sum->push(carry);
		}
}

void bignum_calculator::multiply(bignum num_1, bignum num_2, bignum *product) {
//TODO//multiplies num_1 and num_2 and stores the result in product

	bignum n1 = num_1;
	bignum n2 = num_2;

	int counter = 0;

			// remove a number from "n2" after multiplied by each number of "n1".
			while (!n2.empty())
			{
				int carry = 0;
				bignum sum;
				bignum temp_product;
				int zero = 0;

				//push "0's" for long multiplication.
				for (int i = 0; i < counter; i++)
				{
					temp_product.push(zero);
				}

				// calculate "n1" multiplied by "n2" with carry.
				while(!n1.empty())
				{
					temp_product.push(((n1.top() * n2.top()) + carry) % 10);
					carry = (((n1.top() * n2.top()) + carry) / 10);
					n1.pop();
				}

				if (carry != 0)
				{
					temp_product.push(carry);
				}

				n1 = num_1;
				n2.pop();

				// "temp_product", "sum" and "*product" need to be reversed
				// because "bignum_to_str" reverses the output.
				reverse_stack(temp_product);
				add(*product, temp_product, &sum);
				reverse_stack(sum);
				*product = sum;
				counter ++;
			}
			reverse_stack(*product);

			// checks for leading zero's and removes them
			while(product->size() > 1 && product->top() == 0){
				product->pop();
			}

}
