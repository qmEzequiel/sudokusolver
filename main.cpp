#include <iostream>
#include <fstream>

struct position {
    int r;
    int c;
};

class Sudoku {
private:
    int m[9][9];
    bool control(position p, int a);
    position square_finder(position p);
public:
    Sudoku(std::ifstream & fp);
    void print();
    void solve();
};

int main(){
    //receiving the input file
    std::ifstream inputFile("sample.txt");
    Sudoku sudoku(inputFile);
    inputFile.close();
    char a='y';
    sudoku.print();
    while(a=='y'){
        std::cout<<"Continue?(y or n): ";
        std::cin>>a;
        std::cout<<std::endl;
        sudoku.solve();
        sudoku.print();
    }
    return 0;
}

Sudoku::Sudoku(std::ifstream & fp){
    for (unsigned int i = 0; i < 9; i++) {
        for (unsigned int j = 0; j < 9; j++) {
            fp >> m[i][j];
        }
    }
}

void Sudoku::print(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(m[i][j] == 0) std::cout<<"  ";
            else std::cout<<m[i][j]<<" ";
            if(j==2 || j==5) std::cout<<"|";
        }
        std::cout<<std::endl;
        if(i==2 || i==5) std::cout<<"------|------|------"<<std::endl;
    }
    std::cout<<std::endl;
}

position Sudoku::square_finder(position p){
    if(p.r<3){
        if(p.c<3)   return {0, 0};
        if(p.c<6)   return {0, 3};
                    return {0, 6};
    }if(p.r<6){
        if(p.c<3)   return {3, 0};
        if(p.c<6)   return {3, 3};
                    return {3, 6};
    }
        if(p.c<3)   return {6, 0};
        if(p.c<6)   return {6, 3};
                    return {6, 6};
}

bool Sudoku::control(position p, int a){
    //row control
    for(unsigned int i=0; i<9; i++)
        if (m[p.r][i]==a) return false;
    //column control
    for(unsigned int i=0; i<9; i++)
        if (m[i][p.c]==a) return false;
    //square control
    position t = (*this).square_finder(p);
    for(unsigned int i=t.r; i<t.r+3; i++){
        for (unsigned int j=t.c; j<t.c+3; j++)
            if(m[i][j]==a) return false;
    }
    return true;
}

void Sudoku::solve(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int n=0, a=0;
            if(m[i][j] == 0){
                for(int z=1; z<=9; z++){
                    if((*this).control({i,j},z)) {
                        a=z;
                        n++;
                    }
                }
                if(n==1) m[i][j]=a;
            }
        }
    }
}