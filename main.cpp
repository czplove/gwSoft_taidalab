#include <iostream>
#include <string>

extern int CheckFileVersion(int argc, char** argv);

using namespace std;

int main(int argc, char *argv[])
{
    //查看版本信息
    if (CheckFileVersion(argc, argv)) {
        return 0;
    }
    
  string str;
  
  cin>>str;
  cout<<str<<endl;
  std::cout<<"[ ReadHandle Start ]Time :"<<"\n";
  	
  return 0;
}
