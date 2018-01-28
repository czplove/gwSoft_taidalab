#include "./threadfunc/ThreadFunc.hpp"


extern int CheckFileVersion(int argc, char** argv);

using namespace std;

void wait(int seconds) 
{ 
  boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
} 

void thread() 
{ 
  for (int i = 0; i < 5; ++i) 
  { 
    wait(1); 
    std::cout << i << std::endl; 
  } 
} 

int main(int argc, char *argv[])
{
    //查看版本信息
    if (CheckFileVersion(argc, argv)) {
        return 0;
    }
    
    boost::thread t(thread); 
    t.join(); 
#ifdef PLATFORM_DREAMFLOWER
    //STM32串口处理:传感器数据
    //-boost::thread uartStm32ReadTh(attrs,UartStm32Start);
    //-uartStm32ReadTh.detach();	//-使用detach() 的方法，允许类型为 boost::thread 的变量从它对应的线程里分离。
#endif    
    
  string str;
  
  cin>>str;
  cout<<str<<endl;
  std::cout<<"[ ReadHandle Start ]Time :"<<"\n";
  	
  return 0;
}
