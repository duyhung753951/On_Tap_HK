#include<stdio.h>
#include<string.h>

FILE *f;
int n, i, j;

typedef struct{
    char tens[50], tentg[50];
    int nam;
}SACH;

void input(FILE *f, SACH s[]);
void output(SACH s[]);
void findBook(SACH s[], char tensach[]);
void Bookbf2000(SACH s[]);
void XuatRaTep(SACH s[]);

int main(){
    f=fopen("sach.txt", "rt");
    if(f==NULL){
        perror("Can't open file");
        return;
    }
    fscanf(f, "%d\n", &n);
    SACH s[n];
    input(f, s);
    output(s);
    char tensach[] = "Đắc Nhân Tâm";
    findBook(s, tensach);
    Bookbf2000(s);
}

void input(FILE *f, SACH s[])
{
    for(i = 0; i < n; i++){
        fgets(s[i].tens, 50, f);
        s[i].tens[strcspn(s[i].tens, "\n")] = '\0';
        fgets(s[i].tentg, 50, f);
        s[i].tentg[strcspn(s[i].tentg, "\n")] = '\0';
        fscanf(f, "%d\n", &s[i].nam);
    }
    fclose(f);
}

void output(SACH s[])
{
    printf("Danh sach: \n");
    for(i = 0; i < n; i++){
        printf("%d. %s - %s, Nam: %d\n", i+1, s[i].tens, s[i].tentg, s[i].nam);
    }
}

void findBook(SACH s[], char tensach[])
{
    for(i = 0; i < n; i++){
        if(strcmp(tensach, s[i].tens) == 0){
            printf("\nCuon sach ban tim kiem la: \n");
            printf("%s - %s, Nam: %d\n", s[i].tens, s[i].tentg, s[i].nam);
            break;
        }
    }
    if(i == n){
        printf("Khong tim thay ten sach!\n");
    }
}

void Bookbf2000(SACH s[])
{
    SACH temp;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(s[i].nam > s[j].nam){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("\nNhung cuon sach xuat ban truoc 2000 la: \n");
    int count = 0;
    for(i = 0; i < n; i++){
        if(s[i].nam < 2000){
            printf("%s - %s, Nam: %d\n", s[i].tens, s[i].tentg, s[i].nam);
            count++;
        }
    }
    if(count == 0){
        printf("Khong co sach xuat ban truoc 2000!\n");
    }
    XuatRaTep(s);
}

void XuatRaTep(SACH s[])
{
    int count = 0;
    f=fopen("sach_out.txt", "wt");
    fprintf(f, "Nhung cuon sach xuat ban truoc 2000 la: \n");
    for(i = 0; i < n; i++){
        if(s[i].nam < 2000){
            fprintf(f, "%s - %s, Nam: %d\n", s[i].tens, s[i].tentg, s[i].nam);
            count++;
        }
    }
    if(count == 0){
        fprintf(f, "Khong co sach xuat ban truoc 2000!\n");
    }
    fclose(f);
}
