#include <stdio.h>

void echangeContenu(int *a, int *b){
    int c = *a;
    *a= *b;
    *b =c;

    printf(" a = %d\n  b =%d\n", *a,*b);

}
int main(void)
{
  int a = 10;
  int b = 5;
  echangeContenu(&a,&b);

    return 0;
}