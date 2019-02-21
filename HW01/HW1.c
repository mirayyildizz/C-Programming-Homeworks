/*Bir dikdortgenin icine sigan en buyuk dairenin alanini, 
Dikdortgeni cevreleyen en kucuk dairenin alanini,
Bir dikdortgen icine sigan en buyuk karenin alanini,
Dikdortgeni cevreleyen en kucuk karenin alanini hesaplar. */

#include<stdio.h>
#include<math.h>

#define PI 3.14

/* Cemberin alanını hesaplayan fonksiyondur. */
double circle_area(double radius){
	double area;
	area = PI * pow(radius,2);
	return area;
}
/*Hipotenusu hesaplayan fonksiyondur. */
double calc_hypotenuse(double side1, double side2){ 
	double hypotenuse;
	hypotenuse = sqrt(pow(side1,2)+pow(side2,2)); /* Hipotenusun sonucunu bulmak icin kenarlarin karesini alip toplayarak kok icine alin. */
	return hypotenuse;	/* Hipotenusu dondurun. */
}
/* Dikdortgeni cevreleyen en kucuk dairenin yaricapini hesaplayan fonksiyondur. */
double calc_radius_of_smallest_circle( double side1, double side2  ){ 
	double hypotenuse;
	double radius1;
	hypotenuse = calc_hypotenuse(side1,side2); /* Hipotenus degiskenine calc_hypotenuse fonksiyonunu cagirin. */
	radius1 = hypotenuse / 2.0 ;
	return radius1; /* radius1'i dondurun. */ 
}
/* Bir dikdortgenin icine sýgan en buyuk dairenin yaricapini hesaplayan fonksiyondur. */
double calc_radius_of_largest_circle(double side1, double side2){ 
	double radius2;
	if(side1<side2){ /* Iký kenardan buyuk olani if ile belirleyip, kenarin yarisini radius2 olarak atayin. */
		radius2 = side1 / 2.0 ; 
	}
	if(side2<side1){
		radius2 = side2 / 2.0 ;
	}
	return radius2; /* radius2'yi dondurun. */
}
/* Dikdortgeni cevreleyen en kucuk dairenin alanini hesaplayan fonksiyondur. */
double calc_area_of_smallest_circle(double side1, double side2){ 
	double area1;
	double radius1;
	radius1 = calc_radius_of_smallest_circle(side1,side2); /* radius1 degiskenine calc_radius_of_smallest_circle fonksiyonunu cagirin. */
	area1 = circle_area(radius1); /* area1'i hesaplamak icin PI ile radius1' in karesini carpin. */
	return area1; /* area1'i dondurun. */
}
/* Bir dikdortgenin icine sigan en buyuk dairenin alanini hesaplayan fonksiyondur. */
double calc_area_of_largest_circle(double side1, double side2){ 
	double area2;
	double radius2;
	radius2 = calc_radius_of_largest_circle(side1,side2); /* radius2 degiskenine calc_radius_of_largest_circle fonksiyonunu cagirin.*/
	area2 = circle_area(radius2); /* area2'yi hesaplamak icin PI ile radius2' nin karesini carpin. */
	return area2; /* area2'yi dondurun. */
}
/* Karenin alanini hesaplayan fonksiyondur. */
double calc_area_of_square (double side){ 
	double square_area;
	square_area = pow(side,2); /* Karenin alanini bulmak icin kenarin karesini alin. */
	return square_area; /* square_area'yi dondurun. */
	}
/* Dikdortgeni cevreleyen en kucuk karenin alanini hesaplayan fonksiyondur. */
double calc_area_of_smallest_square(double side1, double side2){
	double area3;
	if(side1>side2){ /* Buyuk kenari if ile bulup, o kanarin karesini alarak alani hesaplayin. */
		area3 = pow(side1,2);
	}
	if(side2>side1){
		area3 = pow(side2,2); 
	}
	return area3; /* area3'u dondurun. */
}
/* Bir dikdortgen icine sigan en buyuk karenin alanini hesaplayan fonksiyondur. */
double calc_area_of_largest_square(double side1, double side2){
		double area4;
	if(side1<side2){ /* Kucuk kenari if ile bulup, o kenarin karesini alarak alani hesaplayin. */
		area4 = calc_area_of_square(side1); 
	}
	if(side2<side1){
		area4 = calc_area_of_square(side2);
	}
	return area4; /* area4'u dondurun. */
	
}
/* Sonuclari bastiran fonksiyondur. */
void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square){
	double side1, side2;
	printf("Enter first side for rectangle:"); /* Ilk kenari girin. */
	scanf("%lf", &side1);
	printf("Enter second side for rectangle:"); /* Ikinci kenari girin. */
	scanf("%lf", &side2);
	/* Fonksiyonlari sirasiyla atayin. */
	largest_circle = calc_area_of_largest_circle(side1,side2); 
	largest_square = calc_area_of_largest_square(side1,side2);
	smallest_circle = calc_area_of_smallest_circle(side1,side2);
	smallest_square = calc_area_of_smallest_square(side1,side2);
	/*Sonuclari yazdirin. */
	printf("The area of the largest circle that fits inside a rectangle: %.2lf\n",largest_circle); 
	printf("The area of the largest square that fits inside the rectangle: %.2lf\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle: %.2lf\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle: %.2lf\n",smallest_square);
}
/* Fonksiyonlari sirasiyla cagiran fonksiyondur. */
int main(){ 
	double radius;
	double side;
	double side1;
	double side2;
	double largest_circle; 
	double largest_square;
	double smallest_circle;
	double smallest_square;
	calc_hypotenuse(side1, side2);
	calc_area_of_square (side);
	display_results(largest_circle,largest_square,smallest_circle,smallest_square);
	
}
