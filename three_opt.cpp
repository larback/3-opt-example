#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <string.h>
#include <bitset>
#include <random>
#include <ratio>
#include <string>
using namespace std;

std::vector<int> myvector, v2,fixados;
vector<vector<int> > permutacoes;

void print(std::vector<int> s){
  for (int i=0;i<s.size();++i)
    cout << s[i] << " ";
  cout << endl;
  return 0l;
}

void movimento1(std::vector<int> solution, std::vector<int> &temp, int p1, int p2, int p3){
  temp.clear();
  // Em ordem até o ponto 1
  for (int j=0;j<=p1;++j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 2 até ponto 1 +1
  for (int j=p2;j>p1;--j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 3 até o ponto 2 +1
  for (int j=p3;j>p2;--j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 3 + 1 até o final
  for (int j=p3+1;j<solution.size();++j){
    temp.push_back(solution[j]);
  }
  
}

void movimento2(std::vector<int> solution, std::vector<int> &temp, int p1, int p2, int p3){
  temp.clear();
  // Em ordem até o ponto 1
  for (int j=0;j<=p1;++j){
    temp.push_back(solution[j]);
  }
  // Ponto 1 segue para Ponto 2+1 até Ponto 3
  for (int j=p2+1;j<=p3;++j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 1+1 até o ponto 2
  for (int j=p1+1;j<=p2;++j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 3 + 1 até o final
  for (int j=p3+1;j<solution.size();++j){
    temp.push_back(solution[j]);
  }
}

void movimento3(std::vector<int> solution, std::vector<int> &temp, int p1, int p2, int p3){
  temp.clear();
  // Em ordem até o ponto 1
  for (int j=0;j<=p1;++j){
    temp.push_back(solution[j]);
  }
  // Ponto 1 segue para Ponto 3, inverte até Ponto 2 +1
  for (int j=p3;j>p2;--j){
    temp.push_back(solution[j]);
  }
  // Pega do Ponto 1+1 até Ponto 2
  for (int j=p1+1;j<=p2;++j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 3 + 1 até o final
  for (int j=p3+1;j<solution.size();++j){
    temp.push_back(solution[j]);
  }
}

void movimento4(std::vector<int> solution, std::vector<int> &temp, int p1, int p2, int p3){
  temp.clear();
  // Em ordem até o ponto 1
  for (int j=0;j<=p1;++j){
    temp.push_back(solution[j]);
  }
  // Ponto 1 segue para Ponto 3, inverte até Ponto 1 +1
  for (int j=p3;j>p1;--j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 3 + 1 até o final
  for (int j=p3+1;j<solution.size();++j){
    temp.push_back(solution[j]);
  }
}

void movimento5(std::vector<int> solution, std::vector<int> &temp, int p1, int p2, int p3){
  temp.clear();
  // Em ordem até o ponto 1
  for (int j=0;j<=p1;++j){
    temp.push_back(solution[j]);
  }
  // Ponto 1 segue para último, inverte até Ponto 3 + 1
  for (int j=solution.size()-1;j>p3;--j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 2 + 1 até o Ponto 3
  for (int j=p2+1;j<=p3;++j){
    temp.push_back(solution[j]);
  }
  // Pega do ponto 2, inverte até Ponto 1-1
  for (int j=p2;j>p1;--j){
    temp.push_back(solution[j]);
  }
}

void movimento6(std::vector<int> solution, std::vector<int> &temp, int p1, int p2, int p3){
  temp.clear();
  // Em ordem até o ponto 1
  for (int j=0;j<=p1;++j){
    temp.push_back(solution[j]);
  }
  // Ponto 2, inverte até Ponto 2+1
  for (int j=p2;j>=p1+1;--j){
    temp.push_back(solution[j]);
  }
  // Pega do Ponto 2+1 até o final
  for (int j=p2+1;j<solution.size();++j){
    temp.push_back(solution[j]);
  }
}

void movimento7(std::vector<int> solution, std::vector<int> &temp, int p1, int p2, int p3){
  temp.clear();
  // Em ordem até o ponto 1
  for (int j=0;j<=p1;++j){
    temp.push_back(solution[j]);
  }
  // Ponto 2+1, segue até Ponto 3
  for (int j=p2+1;j<=p3;++j){
    temp.push_back(solution[j]);
  }
  // Pega do Ponto 2, inverte até P1+1
  for (int j=p2;j>p1;--j){
    temp.push_back(solution[j]);
  }
  // Pega do Ponto 3+1, segue até o final
  for (int j=p3+1;j<solution.size();++j){
    temp.push_back(solution[j]);
  }
}
void three_opt(std::vector<int> &solution){
  std::vector<int> temp;
  for (int i=0;i<solution.size();++i){
    for (int j=i+1;j<solution.size();++j){
      for (int k=j+1;k<solution.size();++k){
        movimento1(solution, temp, i,j,k);
        cout << "1:";
        print(temp); 
        movimento2(solution, temp, i,j,k);
        cout << "2:";
        print(temp); 
        cout << "3:";
        movimento3(solution, temp, i,j,k);
        print(temp); 
        cout << "4:";
        movimento4(solution, temp, i,j,k);
        print(temp); 
        cout << "5:";
        movimento5(solution, temp, i,j,k);
        print(temp); 
        cout << "6:";
        movimento6(solution, temp, i,j,k);
        print(temp); 
        cout << "7:";
        movimento7(solution, temp, i,j,k);
        print(temp); 
        cout << endl;
      }
    }    
  }  
}


int main (){
  std::vector<int> solucao;
  for (int i=0;i<50;++i)
    solucao.push_back(i+1);
  

  three_opt(solucao);
  
}
