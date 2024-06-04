#include<stdio.h>
#include<string.h>

typedef struct{
    char name[30];
    float pts;
    char uni[1];
}ThiSinh;

FILE *f;

void input(ThiSinh ts[], int n, FILE *f);
void output(ThiSinh ts[], int n);
void SumPtsUni(ThiSinh ts[], int n);
void FindTS(ThiSinh ts[], int n);

int main(){
    int n;
    f=fopen("input.txt", "rt");
    fscanf(f, "%d\n", &n);
    ThiSinh ts[n];
    input(ts, n, f);
    output(ts, n);
    SumPtsUni(ts, n);
    FindTS(ts, n);
}

void input(ThiSinh ts[], int n, FILE *f)
{
    int i;
    for(i = 0; i < n; i++){
        fgets(ts[i].name, sizeof(ts[i].name), f);
        ts[i].name[strcspn(ts[i].name, "\n")]='\0';
        fscanf(f, "%f\n", &ts[i].pts);
        fscanf(f, "%s\n", &ts[i].uni);
    }
}

void output(ThiSinh ts[], int n)
{
    int i;
    for(i = 0; i < n; i++){
        printf("%d. %s: %.2f thuoc truong %s\n", i+1, ts[i].name, ts[i].pts, ts[i].uni);
    }
}

void SumPtsUni(ThiSinh ts[], int n)
{
    int i;
    float SumDiem[4]={0};
    float MaxDiem;
    for(i = 0; i < n; i++){
        if(strcmp(ts[i].uni, "A") == 0) SumDiem[0] += ts[i].pts;
        if(strcmp(ts[i].uni, "B") == 0) SumDiem[1] += ts[i].pts;
        if(strcmp(ts[i].uni, "C") == 0) SumDiem[2] += ts[i].pts;
        if(strcmp(ts[i].uni, "D") == 0) SumDiem[3] += ts[i].pts;
    }
    MaxDiem = SumDiem[0];
    char highest_pts_uni = 'A';
    for(i = 1; i < 4; i++){
        if (SumDiem[i] > MaxDiem) {
            MaxDiem = SumDiem[i];
            highest_pts_uni = 'A' + i;
        }
    }
    printf("Truong co so diem lon nhat la %c voi so diem %.2f.\n", highest_pts_uni, MaxDiem);
}

void FindTS(ThiSinh ts[], int n)
{
    int i;
    char nameTS[30];
    printf("Nhap ten thi sinh: ");
    fgets(nameTS, sizeof(nameTS), stdin);
    nameTS[strcspn(nameTS, "\n")]='\0';
    f=fopen("output.txt", "wt");
    for(i = 1; i < n; i++){
        if(strcmp(nameTS, ts[i].name)==0){
            fprintf(f, "Thi sinh %s: %.2f thuoc truong %s\n", ts[i].name, ts[i].pts, ts[i].uni);
        }
    }
}
