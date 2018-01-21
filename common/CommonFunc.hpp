#ifndef _WL_COMMONFUNC_WL_
#define _WL_COMMONFUNC_WL_
//-#include "DevInfo.hpp"

//*******************网关内部版本***********************
#ifdef PLATFORM_MIPS_YUNJIA
#define GWVERSION "3.2.10"
#elif defined PLATFORM_MIPS_7620
#define GWVERSION "3.1.10"
#elif defined PLATFORM_ARM
#define GWVERSION "3.4.10"
#elif defined PLATFORM_ARM_IPCAMERA
#define GWVERSION "3.5.10"
#elif defined PLATFORM_DREAMFLOWER
#define GWVERSION "3.6.10" //梦想之花[有路由有硬盘]
                           //梦想之花[有路由无硬盘]  3.7.XX
#else
#define GWVERSION "3.3.10"
#endif
//********************     end    **********************

#ifdef PLATFORM_DREAMFLOWER
const int DefalutVolume = 80;
const int OTCTL_SECOENDS = 180;
#endif
enum TIME_SIZE{
    TIME_MINUTE=5,
    TIME_SECEOND=8
};

enum ObjType{
    TYPE_Phone = 0,//手机客户端
    TYPE_CloudServer = 1//云服务器
};

//获取服务器时间
extern void GetTimeNet(char* timebuf,int type=0);
extern void GetTime_(char * time_buff,TIME_SIZE len) ;
extern int SetTime(unsigned long seconds, int milliseconds = 0);
extern void GetWeekday(char* week_buf) ;
//extern void GetDateTime(std::string& datetime);
extern int GetTaskDay(std::string weekday);
extern void SetZoneInfo(int zone);
extern std::string Time2Cron(std::string &time, std::string &weekend);
extern void SignalInit();
extern long MemAvailable();
extern void CacheRelease();
extern int CheckFileVersion(int argc, char** argv);
extern int FindMacAddr();
extern void GetBoardName();
extern int GetDevEpnum(int devType);
extern int GetSequence();
extern void ChangeCronFlag(std::string& cronexp, std::string oldflag, std::string replaceflag);
extern void GetProtocol37();
extern std::string GetTimeZone();
extern int system_custom(const char *cmd, char *buf);
extern bool GetDevReissueFlag(int iType);
extern std::string GetFileContent(std::string fileName, int line);

#ifdef PLATFORM_DREAMFLOWER
extern void HexGet(unsigned char *read, int len, char *rets);
extern unsigned int MOD_KG_CRC16(unsigned char *MOD_KG_CRC16_start,unsigned char MOD_KG_CRC16_bytes);
extern int GetTaskDay_PlayTime(std::string weekday);
extern int CalcDiffTime(std::string &currentTime, std::string &setTime);

#endif

#endif
