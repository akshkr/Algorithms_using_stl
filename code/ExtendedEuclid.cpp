#include <stdio.h>

using namespace std;

/*Call euclidean algorithm recursively and reconstruct the coefficients x and y backwards.
 *x, y and gcd are pass by reference and their values before calling the function don't matter.
 *At the end of the call x and y store the coefficients of Bezouts identity, and gcd the greatest common divisor of a and b.
 *
 * The backwards calculations are based in the next equations
 * a*x + b*y = gcd(a,b)
 *           = gcd(b,a%b)
 *           = b*x' + (a%b)*y'
 *           = b*x' + (a-floor(a/b)*b)*y'
 *			 = a*y' + b*(x'-floor(a/b)*y')
 * So: x = y' and y = (x'-floor(a/b)*y')
 */
void extended_euclid( int a, int b, int &x, int &y, int &gcd ){
	if( b == 0 ){
		x = 1;
		y = 0;
		gcd = a;
		return;
	}
	extended_euclid( b, a%b, x, y, gcd );
	int nx = y;
	int ny = (x - int(a/b) * y);
	x = nx; y = ny;
}

int main(){
	int a, b, x, y, gcd;
	//Read a and b, calculates gcd(a,b) and the coefficients of Bezout's identity
	scanf( "%d %d", &a, &b );
	extended_euclid( a, b, x, y, gcd );
	//a*x + b*y = gcd(a,b)
	printf( "%d*%d + %d*%d = %d\n", a, x, b, y, gcd );
	return 0;
}