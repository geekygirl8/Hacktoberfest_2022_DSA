#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
  ifstream file("Ajit.txt",ios::in);
  string curr;
  int count=0;
  while(getline(file, curr))
  {
    for(int i=0;i<curr.size();i++)
      if(curr[i]=='.' || curr[i]=='?' || curr[i]=='!')
        count++;
  }
  cout<<"The total number of sentences are: "<<count<<endl;
  return 0;
}