#include<stdio.h>


int main(int argc, char* argv[]){
	double width, height;
	
	if(argc != 3){
		printf("Wrong number of arguments!\n");
		return 1;
	}
	
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	
	printf("The rectangle's area is %f\n", width*height);
	printf("The rectangle's perimeter is %f\n", 2*(width + height));
	
	
	return 0;
}
