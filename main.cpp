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
    
    //-SignalInit();
    
    
    boost::thread::attributes attrs;
    attrs.set_stack_size(1024);
    
#ifdef PLATFORM_DREAMFLOWER
    //STM32串口处理:传感器数据
    boost::thread uartStm32ReadTh(attrs, thread);	//-变量 uartStm32ReadTh 被创建，该 thread() 函数就在其所在线程中被立即执行。 
    uartStm32ReadTh.detach(); 	//-使用detach() 的方法，允许类型为 boost::thread 的变量从它对应的线程里分离。
#endif    
    
  string str;
  
  cin>>str;
  cout<<str<<endl;
  std::cout<<"[ ReadHandle Start ]Time :"<<"\n";
  	
  while (GlobalConfig::QuitFlag_G) {
  	
  	boost::this_thread::sleep(boost::posix_time::seconds(2));
  }
  return 0;
}
