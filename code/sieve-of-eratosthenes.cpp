/*
	sieve-of-eratosthenes.cpp
	by Charles (@c650), 21 Oct 2017

	This program is an implementation of https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
	with the C++ STL.
*/
#include <iostream> /* cin, cout */
#include <vector>

/*
	Returns a vector of prime numbers less than or equal to max.
	Precondition: expects an unsigned integer `max` up to which
		primes will be generated.
	Postcondition: returns a vector (unsigned ints) of primes.
*/
std::vector<unsigned int> primes(const unsigned int& max) {

	/*
		default all numbers [0, max] as prime.
		I suppose you could use std::vector<bool>,
		but that's controversial.
	*/
	std::vector<uint8_t> sieve_vec(max + 1, true);

	/* mark 0 and 1 as not prime. */
	sieve_vec[0] = sieve_vec[1] = false;

	unsigned int primes_count = 0;

	/*
		for each number [2, max]:
		if the number is prime, we will mark
		its multiples as non-prime. If the
		number i is non-prime (composite),
		then it was the multiple of a previous
		prime so it is false. We skip it.
	*/
	for (unsigned int i = 2, j; i <= max; ++i) {
		if (!sieve_vec[i]) continue;

		++primes_count;

		/* mark all multiples of i as non-prime */
		for (j = i * 2; j <= max; j += i) {
			sieve_vec[j] = false;
		}
	}

	/* create a vector to store just primes. */
	std::vector<unsigned int> primes_vec;

	/*
		Ask vector to allocate space, but size is still 0
		What increases here is capacity.
	*/
	primes_vec.reserve(primes_count);

	/* write prime numbers into primes_vec */
	for (unsigned int i = 2; i <= max; ++i) {
		if (sieve_vec[i]) {
			primes_vec.push_back(i);
		}
	}

	return primes_vec;
}

#ifdef TEST_PROGRAM
int main(void) {

	for (const auto& elem : primes(1000)) {
		std::cout << elem << ' ';
	}
	std::cout << "\n";

	return 0;
}
#endif

/*
	Compiling:
	$ g++ -o sieve-of-eratosthenes.out --std=c++17 sieve-of-eratosthenes.cpp -DTEST_PROGRAM && ./sieve-of-eratosthenes.out
*/
