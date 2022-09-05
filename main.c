#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_matrix(FILE *fp, int m[9][9]);
void print_matrix(int m[9][9]);
void solve_matrix(int m[9][9]);
bool row_control(int r[9], int value);
bool column_control(int m[9][9], int c, int value);
bool square_control(int m[9][9], int r, int c, int value);

int main(void){
    FILE *fp;
    int m[9][9];
    //open the sample file with the sudoku to solve
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    }
    //read the file and save it in a matrix
    read_matrix(fp, m);
    fclose(fp);
    //print the matrix with the sudoku unsolved
    print_matrix(m);
    //solve the sudoku
    solve_matrix(m);
    //print the matrix with the sudoku solved 
    printf("\n");
    print_matrix(m);

    return 0;
}

void read_matrix(FILE *fp, int m[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            fscanf(fp, "%d", &m[i][j]);
        }
    }
}
void print_matrix(int m[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(m[i][j] == 0) printf("  ");
            else printf("%d ", m[i][j]);
            if(j==2 || j==5) printf("|");
        }
        printf("\n");
        if(i==2 || i==5) printf("------|------|------\n");
    }
}

void solve_matrix(int m[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int n=0, a=0;
            if(m[i][j] == 0){
                for(int z=1; z<=9; z++){
                    if(row_control(m[i], z) && column_control(m, j, z) && square_control(m,i,j,z)) {
                        a=z;
                        n++;
                    }
                }
                if(n==1) m[i][j]=a;
            }
        }
    }
}

bool row_control(int r[9], int value){
    for(int i=0; i<9; i++)
        if(r[i]==value) return false;
    return true;
}
bool column_control(int m[9][9], int c, int value){
    for(int i=0; i<9; i++)
        if(m[c][i]==value) return false;
    return true;
}
bool square_control(int m[9][9], int r, int c, int value){
    for(int i=r/3; i<r/3+3; i++){
        for(int j=c/3; j<c/3+3; j++){
            if(m[i][j]==value) return false;
        }
    }
    return true;
}
