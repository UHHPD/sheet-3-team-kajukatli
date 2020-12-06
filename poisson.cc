#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double poisson(double mu, int k)
{ 
   double P;
   P = pow(mu,k)*exp((-1)*mu)/tgamma(k+1);
   return P;
}

int main() 
{
  double mu = 3.11538;
  vector<int> a;
  ifstream fin("datensumme.txt");
  ofstream fout("hist.txt");
  ofstream fout1("histpoi.txt");
  int n_i,i;
  for(i=0;i<234;++i)
 {
   fin>>n_i;
   a.push_back(n_i);
 }
  fin.close();
  int counter[11]={0};
  for(unsigned int k=0;k<a.size();++k)
  {
    counter[a[k]]++;
  }
    for (int k=0;k<11;++k)
    {  
      double result = 234*poisson(mu,k);
      fout<<k<<" "<<counter[k]<<endl;
      fout1<<k<<" "<<counter[k]<<" "<<result<<endl;
    }
    fout.close();
    fout1.close();
}