


#include <stdio.h>					//standart input output library for printf function
#include <math.h>					//math library for pow function


double f( double x );				//function for function's value
double precision( double point, double older_point );	//function for relative error


int main(){
	
	double a_1 = 1;					//initializing variables
 	double b_1 = 2;		
	double prep = 1;
	double point=1;
	double older_point=1;
	int    n = 0;
	

	printf( " n  a_n                b_n               point                point val               relative error\n" );
	printf( "------------------------------------------------------------------------------------------------\n" );
	
	
	printf( " %d  a_n = %lf || b_n = %lf  || point = %lf  || point val = %lf\n", n, a_1, b_1 ,point , f(point) );
	while ( prep > pow( 10, -3 )){					//checking relative error condition
	printf( "------------------------------------------------------------------------------------------------\n" );
		n++;										//recursion number
		older_point = point;						//assignment of point to older point for relative error					
		point = (b_1 - a_1 ) / 2 + a_1;				//middle point
	if(   f( point ) == 0   )						//checking if root is found
	{
		printf(	"Root is: %lf\n", point );
	}
	 if (  f( point ) * f( a_1 ) > 0  ){			//checking bisection conditions
	
		a_1 = point;
		}
	if ( ! (f( point )*f( a_1 ) > 0)) {
	
		b_1 = point;
	}
	
	prep = precision( point,  older_point );
	printf( " %d  a_n = %lf ||  b_n = %lf || point = %lf || point val = %lf    ||   %lf\n",n, a_1, b_1 ,point , f(point), prep );	
	

}
	
	
	
	
	printf( "------------------------------------------------------------------------------------------------\n" );
	return 0;
}

double f( double x ){
	double y;
	y = pow( x, 3 ) +  4 * pow( x, 2 ) - 10;
	return y;
}

double precision( double point, double older_point ){
	if( ( ( ( point - older_point ) / older_point ) < 0 ) ){
	
	return - ( ( point - older_point ) / older_point ); }
	else{
	
	return ( point - older_point ) / older_point; }
}


