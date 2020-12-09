#include <iostream>
#include <fstream>
#include <vector>
#include<cmath>
using namespace std; 

double prob(vector<int> daten, double mu, int i) 
 { 
   double L;
   //for (int j=0;j<daten.size();j++)
   //{
    //cout<<i<<"\n";
    //cout<<daten[i+1]<<"\n";
    //cout<<tgamma(daten[i+1])<<"\n-------\n";
     if (daten[i] != 0)
     {
      L=pow(mu,daten[i])*exp((-1)*mu)/tgamma(daten[i] + 1); 
     }
     else
     {
      L=pow(mu,daten[i])*exp((-1)*mu)/1; 
     }
     return L;
    //}
  }
int main() 
{
  double mu = 3.11538;
  vector<int> daten;
  double nll;
  ifstream fin("datensumme.txt");
  ofstream fout("likelihood.txt");
  int zahl,i; 
  for(i=0;i<234;i++)
  {
    fin>>zahl;
    daten.push_back(zahl);
  }
  fin.close();
  
  //for (int j=0; j<daten.size();j++)
  //{
   // cout<<daten[j]<<"\n";
  //}
  //double mu;
  for ( mu=0;mu<6;mu=mu+0.1)
  {
    double result = 1.0;
    for (int i=0;i<234;++i)
    {
      result= result*prob(daten, mu, i);
    }
    //cout<<result;
    fout<<mu<<" "<< result << endl;
  }
  fout.close();
}