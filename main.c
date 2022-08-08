#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_matrix(FILE *fp, bool m[9][9][9]);
void print_matrix(bool m[9][9][9]);
void solve_matrix(bool m[9][9][9]);

int main(void){
    FILE *fp;
    bool m[9][9][9];
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
    //solve_matrix(m);
    //print the matrix with the sudoku solved 
    //print_matrix(m);

    return 0;
}

void read_matrix(FILE *fp, bool m[9][9][9]){
    int n;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            fscanf(fp, "%d", &n);
            for(int z=1; z<=9; z++){
                if(n==0) m[i][j][z-1]=false;
                else {
                    if(n==z) m[i][j][z-1]=true;
                    else m[i][j][z-1]=false;
                }
            }
        }
    }
}
void print_matrix(bool m[9][9][9]){
    int n;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            for(int z=1; z<=9; z++){
                if(m[i][j][z-1]) {n=z; printf("%d", z);}
                else {n=0;}
            }
            // if(n == 0) printf(" ");
            // else printf("%d", n);
            printf(" ");
        }
        printf("\n");
    }
}

// void solve_matrix(bool m[9][9][9]){
//     int a={1,2,3,4,5,6,7,8,9};
//     for(int i=0; i<9; i++){
//         for(int j=0; j<9; j++){
//             for(int z=0; z<9; z++){
//                 printf("-");
//             }
//         }
//     }
//     printf("\n");
// }