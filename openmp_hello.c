#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void openmp_hello(void);
int main(int argc, char* argv[]) {
int thread_count = strtol(argv[1], NULL, 10);
int ID = omp_get_thread_num();
int threads = omp_get_num_threads();
#pragma omp parallel num_threads(thread_count)
openmp_hello();
return 0;
}
void openmp_hello(void) {
int ID = omp_get_thread_num();
int threads = omp_get_num_threads();
if((ID % 2)==0)
printf("Feliz cumpleaños %d\n", threads);
else
printf("Saludos del hilo %d\n", ID);
} /*openmp_hello*/
