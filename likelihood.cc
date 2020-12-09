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
  //exercise 2e
  double prob_1(vector<int> daten_1,int i)
  {
    double L_1;
    if (daten_1[i] != 0)
     {
      L_1=pow(daten_1[i],daten_1[i])*exp((-1)*daten_1[i])/tgamma(daten_1[i] + 1); 
     }
     else
     {
      L_1=pow(daten_1[i],daten_1[i])*exp((-1)*daten_1[i])/1; 
     }
     return L_1;
  }
int main() 
{
  vector<int> daten;
  vector<int> daten_1;
  ifstream fin("datensumme.txt");
  ifstream fin1("datensumme.txt");
  ofstream fout("likelihood.txt");
  ofstream fout1("nll.txt");
  ofstream fout2("deltanll.txt");
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
 double result=1.0;
 
  // exercise 2a
  for(int j=0;j<234;++j)
  {
    double mu =3.11538;
    result= result*prob(daten,mu,j);
  }
  //cout<<result;
  double result_1=7.76841e-195;

  // exercise 2b and exercise 2c
  double mu;
  for(mu=0;mu<6;mu=mu+0.1)
  { 
   double result1 = 1;
   double result2=1;
   double deltanll=0.0;
   for (int i=0;i<234;++i) 
    { 
      result1 = result1*prob(daten, mu, i);
    }
    //cout<< mu<<" "<< result1 << endl;
    result2= result2*(-2*log(result1));
    deltanll=result2-(-2*log(result_1));          //exercise2d=exercise 2c-exercise 2a
    fout1<< mu << " "<< result2<<endl;
    fout << mu << " " << result1 << endl;
    fout2 << mu << " " << deltanll << endl;
  }
  fout.close();
  fout1.close(); 
  fout2.close();
  for(int i=0;i<234;++i)
  {
    fin1>>zahl;
    daten_1.push_back(zahl);
  }
  fin1.close();
  double result4=1;
  double Lambda;
  double ndof=233;
  for(int i=0;i<234;++i)
  {
    result4 = result4*prob_1(daten_1,i);
    Lambda= result_1/result4;
  }
  //cout<< Lambda<<endl;
  double del_lambda=-2*log(Lambda);
  cout<< del_lambda<<endl;
  //mean= del_lambda/234.0;
  //cout << mean << endl;
  //double std_dev=sqrt(2*ndof);
  //double z= (del_lambda-ndof)/std_dev;
  //cout<< z<<endl;
}