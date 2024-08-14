#include<stdio.h>

//trong truong hop khong them in nua thi de const
void tachso(const double in, long long *intPart, double *fracPart){
	*intPart = (long long)in;
	
	*fracPart = in - *intPart;	
}

//Khong de scanf printf trong ham chuc nang tachso

int main(){
	double input;
	long long intPart;
	double fracPart;
	
	scanf("%lf", &input);
	
	tachso(input, &intPart, &fracPart);
	
	printf("%ld\n", intPart);
	printf("%g\n", fracPart);
	
	return 0;
	
}
