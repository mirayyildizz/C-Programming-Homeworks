#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct n{ /* Linked list yapisi icin bir struct olusturdum. */
        int first;
        struct n* next;
}list; 

int read_line(FILE *f){ /* Dosyadaki verileri satir satir okumak icin bir fonksiyon yazdim. */
        int num,num1;
        char com;
        fscanf(f,"%d%c%d", &num, &com, &num1); /* fscanf ile sayiyi virgulu ve virgulden sonrasini almak icin bir kod yazdim.*/
        return num;
}

int isPrime(int number) { /* Asal sayi bulma fonksiyonu. */
        if (number < 2) /* Sayı ikiden kucukse asal degildir. */ 
                return 0;
        if (number == 2) /* Iki asal sayidir. */
                return 1;
        for (int i = 2; i < number; ++i) { /* Ikiden buyuk sayilarin asalligini kontrol et. */
                if (number % i == 0)
                        return 0;
        }
        return 1;
}

void find_prime_array(FILE *f){ /* Dosyayi okuyup arraye atip asal sayilari bulan fonksiyon .*/ 
        int *arr;
        int i = 0;
        int num;
        arr = (int*)malloc(10000 * sizeof(int)); /* Array icin bellekte yer olusturdum */
                while(!feof(f)){ /* Dosya sonuna gelene kadar read_line fonksiyonunu cagirarak her satiri teker teker okudum. */
               
                        num = read_line(f);
                        //printf("num : %d\n", num);
                        arr[i] = num; /* Okudugum sayilari arrayin elemanlarina atadim */ 
                                if (isPrime(arr[i])) /* Asal sayi olup olmadigini kontrol ettim .*/
                                        printf("%d,00\n", arr[i]); /* Asalsa yazdirdim */
                        ++i;
                        arr = realloc(arr, 10000000 * sizeof(int)); /* Alanı genişlettim */      
                }
}

void find_prime_linkedlist(FILE *f){ /* Dosyayi okuyup linked liste atip asal sayilari bulan fonksiyon */
        int num;
                while(!feof(f)){ /* Dosya sonuna gelene kadar read_line fonksiyonunu cagirarak her satiri teker teker okudum. */
                        list* head = (list*)malloc(100 * sizeof(list)); /* Yer olusturdum */
                        num = read_line(f); 
                        head->first = num; /* Linked list yapisi*/
                        head->next = NULL; 
                                if (isPrime(head->first)) /* Asal sayilari bul ve yazdir. */
                                printf("%d,00\n", head->first);            
                }
}

void calculation_time_arr1(FILE *f){ /* 0-500000 arasindaki asal sayilarin okunma süresini dosyaya yazdiran fonksiyon.*/
        int num;
        int *arr;
        int i = 0;
        double total_time;
        clock_t start, end;
        FILE *f2 = fopen("output_prime_dynamic_array.txt", "a"); /* Dosyayi actim. */
        arr = (int*)malloc(10000 * sizeof(int)); /* Yer ayirdim */
        fprintf(f2,"\n\n0-500000\n\n");
                for(i=0; i<500000; i++){ /* 500000 e kadar olan sayilarin zamanini buldum*/
                        num = read_line(f);
                        arr[i] = num;
                                if (isPrime(arr[i])){
                                        start = clock();
                                        //printf("%d,00   ", arr[i]);
                                        fprintf(f2,"%d,00  ", arr[i]);
                                        end = clock();
                                        total_time = (double)(end-start) * 1000;
                                        fprintf(f2,"total time: %.0f \n", total_time); 
                                }
                        arr = realloc(arr, 10000000 * sizeof(int)); 
                }
        fclose(f2);
}

void calculation_time_arr2(FILE *f){ /* 0-750000 arasindaki asal sayilarin okunma süresini dosyaya yazdiran fonksiyon.*/
        int num;
        int *arr1;
        int i = 0;
        double total_time;
        clock_t start, end;
        FILE *f2 = fopen("output_prime_dynamic_array.txt", "a"); /* Dosyayi actim. */
        arr1 = (int*)malloc(10000 * sizeof(int));
        fprintf(f2,"\n\n0-750000\n\n");        
                for(i=0; i<750000; i++){ /* 750000 e kadar olan sayilarin zamanini buldum*/
                        num = read_line(f);
                        arr1[i] = num;
                                if (isPrime(arr1[i])){
                                        start = clock();
                                        fprintf(f2,"%d,00   ", arr1[i]);
                                        end = clock();
                                        total_time = (double)(end-start) * 1000.0;
                                        fprintf(f2,"total time: %.0f \n", total_time); 
                                }
                        arr1 = realloc(arr1, 10000000 * sizeof(int)); 
                }
        fclose(f2);
}

void calculation_time_arr3(FILE *f){ /* 0-1000000 arasindaki asal sayilarin okunma süresini dinamik arrayle dosyaya yazdiran fonksiyon.*/
        int num;
        int *arr2;
        int i = 0;
        double total_time;
        clock_t start, end;
        FILE *f2 = fopen("output_prime_dynamic_array.txt", "a"); /* Dosyayi actim. */
        arr2 = (int*)malloc(10000 * sizeof(int));
        fprintf(f2,"\n\n0-1000000\n\n"); /* Baslik*/       
                for(i=0; i<1000000; i++){ /* 1000000 e kadar olan sayilarin zamanini buldum*/
                        num = read_line(f);
                        arr2[i] = num;
                                if (isPrime(arr2[i])){
                                        start = clock();
                                        fprintf(f2,"%d,00   ", arr2[i]);
                                        end = clock();
                                        total_time = (double)(end-start) * 1000.0;
                                        fprintf(f2,"total time: %.0f \n", total_time); 
                                }
                        arr2 = realloc(arr2, 10000000 * sizeof(int)); 
                }
        fclose(f2);
}

void calculation_time_linkedlist1(FILE *f){ /* 0-500000 arasindaki asal sayilarin okunma süresini linked listle dosyaya yazdiran fonksiyon.*/
        int num, i=0;
        double total_time;
        clock_t start, end;
        FILE *f1 = fopen("output_prime_LiknedList.txt", "a"); /* Dosyayi actim*/
        fprintf(f1,"0-500000\n\n"); /* Baslik */
                for(i=0; i<500000; i++){ /* 500000 e kadar olan sayilarin zamanini buldum*/
                        list* head = (list*)malloc(100 * sizeof(list));
                        num = read_line(f);
                        head->first = num;
                        head->next = NULL; 
                                if (isPrime(head->first)){
                                        start = clock();
                                        fprintf(f1, "%d,00  ", head->first);
                                        //printf("%d,00  ", head->first);            
                                        end = clock();
                                        total_time = (double)(end-start) * 1000.0;
                                        fprintf(f1,"total time: %.0f \n", total_time);
                                 }
                 }
        fclose(f1);
}
void calculation_time_linkedlist2(FILE *f){ /* 0-750000 arasindaki asal sayilarin okunma süresini linked listle dosyaya yazdiran fonksiyon.*/
        int num, i=0;
        double total_time;
        clock_t start, end;
        FILE *f1 = fopen("output_prime_LiknedList.txt", "a"); /* Dosyayı actim*/
        fprintf(f1,"\n\n0-750000\n\n");
                for(i=0; i<750000; i++){ /* 750000 e kadar olan sayilarin zamanini buldum*/
                        list* head = (list*)malloc(100 * sizeof(list));
                        num = read_line(f);
                        head->first = num;
                        head->next = NULL; 
                                if (isPrime(head->first)){
                                        start = clock();
                                        fprintf(f1, "%d,00  ", head->first);
                                        //printf("%d,00  ", head->first);            
                                        end = clock();
                                        total_time = (double)(end-start) * 1000.0;
                                        fprintf(f1,"total time: %.0f \n", total_time);
                                 }
                 }
        fclose(f1);
}
void calculation_time_linkedlist3(FILE *f){ /* 0-1000000 arasindaki asal sayilarin okunma süresini linked listle dosyaya yazdiran fonksiyon.*/
        int num, i=0;
        double total_time;
        clock_t start, end;
        FILE *f1 = fopen("output_prime_LiknedList.txt", "a");
        fprintf(f1,"\n\n0-1000000\n\n");
                for(i=0; i<1000000; i++){ /* 1000000 e kadar olan sayilarin zamanini buldum*/
                        list* head = (list*)malloc(100 * sizeof(list));
                        num = read_line(f);
                        head->first = num;
                        head->next = NULL; 
                                if (isPrime(head->first)){
                                        start = clock();
                                        fprintf(f1, "%d,00  ", head->first);
                                        //printf("%d,00  ", head->first);            
                                        end = clock();
                                        total_time = (double)(end-start) * 1000.0;
                                        fprintf(f1,"total time: %.0f \n", total_time);
                                 }
                 }
        fclose(f1);
}
               
int main(){
        FILE *f = fopen("data.txt", "r"); /* Data dosyasini actim. */
        find_prime_array(f); /* Fonksiyonlari cagirdim*/
        find_prime_linkedlist(f);
        /* Array icin yazdigim fonksiyonlari hep birlikte cagirdigimda, sadece 0-1000000 a kadar olan sayilarin süresini dosyaya yazdırıyor, üc fonksiyondan ikisini yoruma     alip teker teker tekli cagirdigimda hepsini ayri ayri yapabiliyor, ayni olay linked list fonksiyonlari icin de gecerli. */
        calculation_time_arr1(f);
        calculation_time_arr2(f);
        calculation_time_arr3(f); 
        calculation_time_linkedlist1(f);
        calculation_time_linkedlist2(f);
        calculation_time_linkedlist3(f);
        fclose(f);
}
        
        
