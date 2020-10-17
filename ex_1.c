#include<stdio.h>
#include<math.h>

double v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, y;
double fv1, fv2, fv3, fv4, fv5, fv6, fv7, fv8, fv9, fv10, fv11, fv12, fv13;
double rv1, rv2, rv3, rv4, rv5, rv6, rv7, rv8, rv9, rv10, rv11, rv12, rv13;

double sac(double x1, double x2, double x3){
	v1 = x1;
	v2 = x2;
	v3 = x3;
	v4 = v1*v2;
	v5 = sin(v1);
	v6 = v1 * v1;
	v7 = v6 * v3;
	v8 = v6 * v1;
	v9 = v2 - v3;
	v10 = exp(v9);
	v11 = v8 * v10;
	v12 = v7 - v11;
	v13 = v5 + v12;
	y = v13;
	return(y);
}

double forward_differentiated_code(double d_x1, double d_x2, double d_x3){
	fv1 = d_x1;
	fv2 = d_x2;
	fv3 = d_x3;
	fv4 = ((v1 * fv2) + (fv1 * v2));
	fv5 = cos(v4) * fv4;
	fv6 = 2 * v1 * fv1;
	fv7 = ((v6 * fv3) + (fv6 * v3));
	fv8 = ((v6 * fv1) + (fv6 * v1));
	fv9 = (fv2 - fv3);
	fv10 = exp(v9) * fv9;
	fv11 = ((fv8 * v10) + (v8 * fv10));
	fv12 = fv7 - fv11;
	fv13 = fv5 + fv12;
	return(fv13);

}

double reverse_differentiated_code(){
	rv13 = 1;
	rv12 = rv13 * 1;
	rv11 = rv12 * (-1);
	rv10 = rv11 * v8;
	rv9 = rv10 * exp(v9);
	rv8 = rv11 * v10;
	rv7 = rv12;
	rv6 = ((rv7 * v3) + (rv8 * v1));
	rv5 = rv13;
	rv4 = rv5 * cos(v4);
	rv3 = ((rv7 * v6) - rv9);
	rv2 = (rv9 + (rv4 * v1));
	rv1 = ((rv4 * v2) + (rv6 * v1 * 2) + (rv8 * v6));
	printf("The derivatives of Y w.r.t x1 : %lf \t x2 : %lf \t x3 : %lf \n", rv1, rv2, rv3); 
}

int main(){
	double x1, x2, x3;
	printf("Input for :\t");
	printf("x1 :\n");
	scanf("%lf", &x1);
	printf("x2 :\n");
	scanf("%lf", &x2);
	printf("x3 :\n");
	scanf("%lf", &x3);
	double result, fd_x1, fd_x2, fd_x3;
	result = sac(x1, x2, x3);
	printf("Evaluation Trace :\t%lf\n",result);
	printf("-----FORWARD MODE-----\n");
	fd_x1 = forward_differentiated_code(1, 0, 0);
	printf("Directional Derivative w.r.t x1 is :\t%lf\n", fd_x1);
	fd_x2 = forward_differentiated_code(0, 1, 0);
	printf("Directional Derivative w.r.t x2 is :\t%lf\n", fd_x2);
	fd_x3 = forward_differentiated_code(0, 0, 1);
	printf("Directional Derivative w.r.t x3 is :\t%lf\n", fd_x3);
	printf("-----REVERSE MODE-----\n");
	reverse_differentiated_code();
	return(0);
}
