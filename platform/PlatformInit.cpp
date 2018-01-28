#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <fstream>
#include <boost/algorithm/string/split.hpp> 
#include <boost/algorithm/string/classification.hpp>

#include "../common/GlobalConfig.hpp"
#include "PlatformInit.hpp"
#include "../common/CommonFunc.hpp"

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
int GlobalConfig::OCTL_SLEEPTIME_G = OTCTL_SECOENDS;
int GlobalConfig::OCTL_SLEEPTIME_INCREASE_G = OTCTL_SECOENDS;
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
PlatformInit::PlatformInit()
{
}

PlatformInit::~PlatformInit()
{
}

void PlatformInit::PlatFormInit()
{
}

void PlatformInit::GwMacAddrInit()
{
#if defined(PLATFORM_MIPS_7620) || defined(PLATFORM_DREAMFLOWER)
    std::fstream fileOut;
    char macAddr[20] = {0};
    fileOut.open("/etc/configenv/id",std::ios::in | std::ios::app);
    std::vector<std::string> vStr;
    if(fileOut.is_open())//文件打开
    {
        while(!fileOut.eof()){
            std::string macTmp("");
            getline(fileOut,macTmp);
            vStr.push_back(macTmp);
        }
        fileOut.close();

        for(int i=0;i<vStr.size();i++){
            const char *p = NULL;
            p = vStr.at(i).c_str();
            int j = 0;
            int k = 0;
            while(p[j]){
                if(p[j] != 0x20 && p[j] != 0x2C && p[j] != ':'){
                    macAddr[k++] = toupper(p[j]);
                }
                j++;
            }
        }
        GlobalConfig::GWMacAddr_G = std::string(macAddr);
        print_info("GW Mac Addr : %s\n",GlobalConfig::GWMacAddr_G.c_str());
    } else {
        print_error("Fail To Open Configration File of id!\n");
    }
#else
    std::ifstream ifileOut("/etc/configenv/gwid");
    char macAddr[20] = {0};
    if (ifileOut.is_open()) {//文件打开
        std::string macTmp("");
        getline(ifileOut,macTmp);
        ifileOut.close();
        const char *p = NULL;
        p = macTmp.c_str();
        int j = 0;
        int k = 0;
        while (p[j]) {
            if (p[j] != 0x20 && p[j] != 0x2C && p[j] != ':') {
                macAddr[k++] = toupper(p[j]);
            }
            j++;
        }
        GlobalConfig::GWMacAddr_G = std::string(macAddr);
    } else {
        std::fstream fileOut;
        system("create_eeprom > /etc/configenv/mac");
        fileOut.open("/etc/configenv/mac",std::ios::in | std::ios::app);
        std::vector<std::string> vStr;
        if (fileOut.is_open()) {
            while (!fileOut.eof()) {
                std::string macTmp("");
                getline(fileOut,macTmp);
                vStr.push_back(macTmp);
            }
            fileOut.close();

            for (int i=0;i<vStr.size();i++) {
                const char *p = NULL;
                if (p = strstr(vStr.at(i).c_str(),":")) {
                    int j = 1;
                    int k = 0;
                    while (p[j]) {
                        if (p[j] != 0x20 && p[j] != 0x2C) {
                            macAddr[k++] = toupper(p[j]);
                        }
                        j++;
                    }
                }
            }
            char temp[4] = { 0 };
            unsigned char ss=0;
            strncpy(temp, &macAddr[10], 2);
            ss = strtol(temp, NULL, 16);
            ss++;
            sprintf(&macAddr[10], "%02X", ss&0x00FF);
            GlobalConfig::GWMacAddr_G = std::string(macAddr);
        } else {
            print_error("Fail To Open Configration File of Mac!\n");
        }
        system("rm /etc/configenv/mac");
    }
    print_info("GW Mac Addr : %s.\n",GlobalConfig::GWMacAddr_G.c_str());
#endif
}

void PlatformInit::GwIpAddrInit()
{
    GetGwIp(GlobalConfig::KEthname);
    if (GlobalConfig::GWIpAddr_G.compare("0.0.0.0") == 0) {
        GetGwIp(GlobalConfig::KWlanname);
    }
    if (GlobalConfig::GWIpAddr_G.compare("0.0.0.0") == 0) {
        GetGwIp(GlobalConfig::K3gname);
    }
}

void PlatformInit::GetGwIp(const std::string &eth_name)
{
    int sockfd;
    char gwip_[16] = {0};
    if (-1 == (sockfd = socket(PF_INET, SOCK_STREAM, 0))) {
        perror_info("socket");
        return ;
    }
    struct ifreq req;
    struct sockaddr_in *host;

    bzero(&req, sizeof(struct ifreq));
    strcpy(req.ifr_name, eth_name.c_str());
    print_info("eth_name = %s\n",eth_name.c_str());
    ioctl(sockfd, SIOCGIFADDR, &req);
    host = (struct sockaddr_in*) &req.ifr_addr;
    close(sockfd);
    if (host) {
        strcpy(gwip_, inet_ntoa(host->sin_addr));
    }

    GlobalConfig::GWIpAddr_G = std::string(gwip_);
    print_info("GW IP Addr : %s\n",GlobalConfig::GWIpAddr_G.c_str());
}

std::vector<std::string> PlatformInit::GetCSAddr()
{
    const char *C_ServerConfigFile = "/etc/configenv/csaddr.conf";
    std::string rmCmd("rm ");
    rmCmd.append(C_ServerConfigFile);
    system(rmCmd.c_str());
#ifdef PLATFORM_MIPS_7620 
    std::string cmd[GlobalConfig::CSDomainNum_G]={"uci get /usr/share/wulian/wulian.icloud.icloud_ip >>","uci get /usr/share/wulian/wulian.icloud.icloud_ip2 >>"};
#elif defined PLATFORM_DREAMFLOWER 
    std::string cmd[GlobalConfig::CSDomainNum_G]={"uci get /usr/share/wulian/wulian.icloud.icloud_ip >>","uci get /usr/share/wulian/wulian.icloud.icloud_ip2 >>"};
#elif defined PLATFORM_ARM_IPCAMERA
    std::string cmd[GlobalConfig::CSDomainNum_G]={"uci get /etc/configenv/share/wulian.icloud.icloud_ip >>","uci get /etc/configenv/share/wulian.icloud.icloud_ip2 >>"};    
#else
    std::string cmd[GlobalConfig::CSDomainNum_G]={"uci get usr.icloud.icloud_ip >>","uci get usr.icloud.icloud_ip2 >>"};
#endif
    for (int i=0;i<GlobalConfig::CSDomainNum_G;i++) {
        cmd[i].append(C_ServerConfigFile);
        system(cmd[i].c_str());
    }
    std::fstream fileOut;
    fileOut.open(C_ServerConfigFile,std::ios::in | std::ios::app);
    std::vector<std::string> vStr;
    vStr.clear();
    if (fileOut.is_open()) {
        while (!fileOut.eof()) {
            std::string CSAddrTmp("");
            getline(fileOut,CSAddrTmp);
            vStr.push_back(CSAddrTmp);
        }
    }
    fileOut.close();
    std::vector<std::string> finalVec;
    finalVec.clear();

    for (int i=0;i<vStr.size();i++) {
        if (!vStr.at(i).empty()) {
            if (i>0) {
                std::vector<std::string> vTmp;
                vTmp.clear();
                boost::split( vTmp,vStr.at(i), boost::is_any_of( " "), boost::token_compress_on );
                for (int i=0;i<vTmp.size();i++) {
                    if (vTmp.at(i).length()>1)
                        finalVec.push_back(vTmp.at(i));
                }
            } else {
                finalVec.push_back(vStr.at(i));
            }
        }
    }

    for (int i=0;i<finalVec.size();i++)
        print_info("[ GetCSAddr ][ ADDR ][ finalVec ]%s\n",finalVec.at(i).c_str());
    return finalVec;
}
#ifdef PLATFORM_DREAMFLOWER
/**************************
RETURN Value:
0:auto
1:chinese
2:englist
***************************/
void PlatformInit::GetLanguage()
{
    char chRes[100] = {0};
    const char * getLangCmd = "uci get luci.main.lang";
    system_custom(getLangCmd, chRes);
    std::string strLang(chRes);
    if(strLang.compare("zh-cn")==0){
        GlobalConfig::Language_G = 1;
    } else if(strLang.compare("en")==0){
        GlobalConfig::Language_G = 2;
    }
}
#endif
#ifdef PLATFORM_ARM_IPCAMERA
void PlatformInit::SetMaxDevNum()
{
    std::string strMaxDevNum;
    int iMaxNum = 0;
    std::ifstream ifileOut("/etc/configenv/max_num");
    if(ifileOut.is_open()) { //文件打开
        getline(ifileOut,strMaxDevNum);
        ifileOut.close();
        iMaxNum = atoi(strMaxDevNum.c_str());
    }

    if (iMaxNum > 0) {
      GlobalConfig::MaxDevNum = iMaxNum; 
    }

    print_info("GetMaxDevNum:%d\n", GlobalConfig::MaxDevNum);
}
#endif
