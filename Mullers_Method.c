

#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex f( double complex x );
double complex muller( double complex p_0, double complex p_1, double complex p_2 );


int main(){
	muller( 0.5, -0.5, 0 );
	muller( 0.5, 1.0, 1.5 );
	muller( 1.5, 2.0, 2.5 );
	return 0;
}

double complex f( double complex x ){
	return 1*cpow( x, 4 ) - 3 * cpow( x, 3) + cpow ( x, 2) + x + 1; 
}

double complex muller( double complex p_0, double complex p_1, double complex p_2 ){
	double complex h_1 = p_1 - p_0, h_2 = p_2 - p_1;
	double complex delta_1 = ( f( p_1 ) - f( p_0 ) ) / h_1, delta_2 = ( f( p_2 ) - f( p_1 ) ) / h_2;
	double complex d = ( delta_2 - delta_1 ) / ( h_2 + h_1 );
	double TOL = pow( 10, -5);
	double complex E, D, b, h, p;

	int i = 3, N_0=1000;
	printf( "___________________________________________________________\n" );
	printf( "p_0 =   %lf + %lfi\tp_1=  %lf + %lfi\t\np_2=  %lf + %lfi\n\n", creal( p_0 ), cimag( p_0 ), creal( p_1 ), cimag( p_1 ), creal( p_2 ), cimag( p_2 ));
	printf( "i\t|\tp_i\t|\tf(p_i)\n" );
	printf( "___________________________________________________________\n" );
	while ( i <= N_0 ){
		b = delta_2 + h_2 * d;
		D =  csqrt( cpow( b, 2 ) - 4 * f( p_2 ) * d ); 
		if ( cabs(b - D ) <  cabs( b + D ) ){
			E = b + D;
		}
		else
		{
			 E = b - D; 
		}
		 h = -2 * f( p_2 ) / E;
		p = p_2 + h;
		printf( "%d\t%lf + %lfi\t", i, creal( p ), cimag( p ));
		printf( "%lf + %lfi\n", creal( f( p ) ), cimag( f( p )));
		if( cabs( h ) < TOL )
		{
			printf( "\n\nROOT IS: " );
			printf( "%lf + %lfi\n", creal( p ), cimag( p ));
			printf( "ROOT FOUND AND PROGRAM FINISHED SUCCESFULLY.\n" );
			printf( "___________________________________________________________\n" );
			return 0;
		}
		p_0 = p_1;
		p_1 = p_2;
		p_2 = p;
		h_1 = p_1 - p_0;
		h_2 = p_2 - p_1;
		delta_1 = ( f(p_1) -f( p_0 )) / h_1;
		delta_2 = ( f(p_2) -f( p_1 )) / h_2;
		d = ( delta_2 - delta_1 ) / ( h_2 + h_1 );
		i += 1;
	}
	printf( "\nMETHOD FAILED AFTER N_0 ITERATIONS N_0 = %d", N_0 );
	printf( "\nTHE PROCEDURE WAS UNSUCCESSFUL" );
}
