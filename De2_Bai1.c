#include<stdio.h>
#include<string.h>

FILE *f;
int m, n;

void input(FILE *f, int a[][50]);
void MaxAm(int a[][50]);
void MaxCot(int a[][50]);
void SumHang(int a[][50]);

int main(){
    char tenf[20];
    fgets(tenf, 20, stdin);
    tenf[strcspn(tenf, "\n")] = '\0';
    f=fopen(tenf, "rt");
    fscanf(f, "%d%d", &m, &n);
    int a[m][n];
    input(f, a);
    MaxAm(a);
    MaxCot(a);
    SumHang(a);
}

void input(FILE *f, int a[][50])
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
}

void MaxAm(int a[][50])
{
    int max;
    // tim 1 gia tri am dat lam max
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] < 0){
                max = a[i][j];
                goto nextphase; // nhay toi buoc tiep theo sau khi tim duoc
            }
        }
    }
    int countAm = 0;
    nextphase:
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] < 0){
                countAm++;
                if(max < a[i][j]) max = a[i][j];
            }
        }
    }
    if(countAm == 0){
        printf("Ma tran khong co gia tri am.\n");
    }else{
        printf("Phan tu gia tri am lon nhat cua ma tran la: %d\n", max);
    }

}

void MaxCot(int a[][50])
{
    for(int j = 0; j < n; j++){
        int max = a[0][j];
        for(int i = 0; i < m; i++){
            if(a[i][j] > max){
                max = a[i][j];
            }
        }
        printf("Max cot %d la: %d\n", j+1, max);
    }
}

void SumHang(int a[][50])
{
    for(int i = 0; i < m; i++){
        int sum=0;
        for(int j = 0; j < n; j++){
            sum += a[i][j];
        }
        printf("Tong hang %d la: %d\n", i+1, sum);
    }
}
