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
    //�鿴�汾��Ϣ
    if (CheckFileVersion(argc, argv)) {
        return 0;
    }
    
    //-SignalInit();
    
    
    boost::thread::attributes attrs;
    attrs.set_stack_size(1024);
    
#ifdef PLATFORM_DREAMFLOWER
    //STM32���ڴ���:����������
    boost::thread uartStm32ReadTh(attrs, thread);	//-���� uartStm32ReadTh ���������� thread() ���������������߳��б�����ִ�С� 
    uartStm32ReadTh.detach(); 	//-ʹ��detach() �ķ�������������Ϊ boost::thread �ı���������Ӧ���߳�����롣
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
