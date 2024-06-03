#include<stdio.h>
#include<string.h>
FILE *f;
int n, i, j;

void input(int x[], int y[]);
void countDiem(int x[], int y[]);
void capDiem(int x[], int y[]);

int main(){
    char tenf[20];
    fgets(tenf, 20, stdin);
    tenf[strcspn(tenf, "\n")]='\0';
    f=fopen(tenf, "rt");
    fscanf(f, "%d", &n);
    float x[n], y[n];
    input(x, y);
    countDiem(x, y);
    capDiem(x, y);
}

void input(int x[], int y[]){
    for(i = 0; i < n; i++){
        fscanf(f, "%d%d\n", &x[i], &y[i]);
    }
}

void countDiem(int x[], int y[]){
    int dt = 0, dn = 0;
    for(i = 0; i < n; i++){
        if((x[i]*x[i] + y[i]*y[i]) > 25) dn++;
        if((x[i]*x[i] + y[i]*y[i]) < 25) dt++;
    }
    printf("Co %d diem nam ngoai duong tron\n", dn);
    printf("Co %d diem nam trong duong tron\n", dt);
}
void capDiem(int x[], int y[]){
    printf("Co nhung cap diem: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(x[i]+x[j] == 0 && y[i]+y[j] == 0){
                printf("Cap diem: (%d, %d) va (%d, %d)\n", x[i], y[i], x[j], y[j]);
            }
        }
    }
}
