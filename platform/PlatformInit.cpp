#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <fstream>
#include <boost/algorithm/string/split.hpp> 
#include <boost/algorithm/string/classification.hpp>

#include "../common/GlobalConfig.hpp"
//-#include "PlatformInit.hpp"

#ifdef PLATFORM_MIPS
const std::string GlobalConfig::UartName_G = "/dev/ttyS1";
const std::string GlobalConfig::KEthname = "eth0.2";
const std::string GlobalConfig::KWlanname = "wlan0";
const std::string GlobalConfig::K3gname = "3g-ppp0";
//数据库文件
const std::string GlobalConfig::DbName_G = "/etc/configenv/wlhome.db";

#elif defined PLATFORM_MIPS_H3C
const std::string GlobalConfig::UartName_G = "/dev/ttyS1";
const std::string GlobalConfig::KEthname = "eth0.2";
const std::string GlobalConfig::KWlanname = "wlan0";
const std::string GlobalConfig::K3gname = "3g-ppp0";
//数据库文件
const std::string GlobalConfig::DbName_G = "/etc/configenv/wlhome.db";

#elif defined PLATFORM_MIPS_7620
const std::string GlobalConfig::UartName_G = "/dev/ttyS1";
const std::string GlobalConfig::KEthname = "eth0.2";
const std::string GlobalConfig::KWlanname = "wlan0";
const std::string GlobalConfig::K3gname = "3g-ppp0";
//数据库文件
const std::string GlobalConfig::DbName_G = "/etc/configenv/wlhome.db";

#elif defined PLATFORM_ARM
const std::string GlobalConfig::UartName_G = "/dev/ttySAC2";
const std::string GlobalConfig::KEthname = "eth0";
const std::string GlobalConfig::KWlanname = "wlan0";
const std::string GlobalConfig::K3gname = "eth0";
//数据库文件
const std::string GlobalConfig::DbName_G = "/etc/configenv/wlhome.db";

#elif defined PLATFORM_ARM_IPCAMERA
const std::string GlobalConfig::UartName_G = "/dev/ttyAMA1";
const std::string GlobalConfig::KEthname = "eth0";
const std::string GlobalConfig::KWlanname = "wlan0";
const std::string GlobalConfig::K3gname = "eth0";
//数据库文件
const std::string GlobalConfig::DbName_G = "/etc/configenv/wlhome.db";
int GlobalConfig::MaxDevNum = 3;

#elif defined PLATFORM_DREAMFLOWER
const std::string GlobalConfig::UartName_G = "/dev/ttyS0";
const std::string GlobalConfig::UartStm32Name_G = "/dev/ttyS1";
const std::string GlobalConfig::KEthname = "eth0.2";
const std::string GlobalConfig::KWlanname = "wlan0";
const std::string GlobalConfig::K3gname = "3g-ppp0";
//数据库文件
const std::string GlobalConfig::DbName_G = "/etc/configenv/wlhome.db";
std::string GlobalConfig::MsgCO2_G = "";         //co2值
std::string GlobalConfig::MsgVoc_G = "";         //Voc值
std::string GlobalConfig::MsgHumidity_G = "";    //湿度值
std::string GlobalConfig::MsgPM25_G = "";        //PM2.5值
std::string GlobalConfig::MsgNoise_G = "";       //噪音值
std::string GlobalConfig::Weather_G = "";
int GlobalConfig::AudioSwitch_G = 1;
int GlobalConfig::AudioNormal_G = 1;
int GlobalConfig::AudioNetHit_G = 1;
int GlobalConfig::AudioAssist_G = 1;
int GlobalConfig::Weather_Type = -1;
int GlobalConfig::Zigbee_Test_G = 0;
int GlobalConfig::Stm32_Test_G=0;
int GlobalConfig::Language_G = 0;
int GlobalConfig::LCD_Display_G = -1;
int GlobalConfig::LCD_Display_Value_G = 0;
int GlobalConfig::Volumemixer_G = 0;
int GlobalConfig::Zigbee_Flag = 0;
//-int GlobalConfig::OCTL_SLEEPTIME_G = OTCTL_SECOENDS;
//-int GlobalConfig::OCTL_SLEEPTIME_INCREASE_G = OTCTL_SECOENDS;
#else
const std::string GlobalConfig::UartName_G = "/dev/ttyACM0";
const std::string GlobalConfig::KEthname = "eth0";
const std::string GlobalConfig::KWlanname = "eth0";
const std::string GlobalConfig::K3gname = "eth0";
//数据库文件
const std::string GlobalConfig::DbName_G = "/etc/configenv/wlhome.db";
#endif
int GlobalConfig::ZigbeeNetFlag = 0;
std::string GlobalConfig::GWMacAddr_G = "";
std::string GlobalConfig::GWName_G = "";
std::string GlobalConfig::GWLocation_G = "";
std::string GlobalConfig::GWIpAddr_G = "";
std::string GlobalConfig::TimeSceneButton_G = "";
const int GlobalConfig::CloudServerPort_G = 7005;
const int GlobalConfig::ClientListenPort_G = 7002;
long GlobalConfig::RoomMaxId_G = 0;
int GlobalConfig::ProgramID_G = 0;
long GlobalConfig::BindDevMaxId_G = 0;
long GlobalConfig::SceneMaxId_G = 0;
int GlobalConfig::QuitFlag_G = 1; 
pid_t GlobalConfig::SigPid_G = 0;
DevInfoContainer GlobalConfig::DevInfoList_G;
DevRealDataContainer GlobalConfig::DevRealDataList_G;
int GlobalConfig::DevHeatBeatFreq = 5;
int GlobalConfig::DevHeatBeatTime = 10;
int GlobalConfig::HeatBeatTimes = 0;
int GlobalConfig::HeatBeatTimesMax = 6;
int GlobalConfig::BoardType_G = 0;
int GlobalConfig::SupportRule_G = 0;
int GlobalConfig::RUN_MODE = 0;
int GlobalConfig::Sequence_G = 0;
int GlobalConfig::RESSUE_TIME = 300;

