#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <fstream>
#include <boost/algorithm/string/split.hpp> 
#include <boost/algorithm/string/classification.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp> 
#include <errno.h>
#include "GlobalConfig.hpp"
#include "CommonFunc.hpp"

void GetTimeNet(char* timebuf,int type)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int millisecond = tv.tv_usec / 1000;
    if(type == 0){
        sprintf(timebuf, "%ld%03d", tv.tv_sec, millisecond);
    } else {
        sprintf(timebuf, "%ld", tv.tv_sec);
    }
}

void GetTime_(char time_buff[],TIME_SIZE len)
{
    memset(time_buff, 0, sizeof(time_buff));
    time_t timep;
    time(&timep);
    strcpy(time_buff, ctime(&timep));
    std::string strtemp = time_buff;
    strtemp = strtemp.substr(11, len);
    memset(time_buff, 0, strlen(time_buff));
    strcpy(time_buff, strtemp.c_str());
}

int SetTime(unsigned long seconds, int milliseconds)
{
    struct timeval tv;
    time_t timep = (time_t)seconds;
    tv.tv_sec = timep;
    tv.tv_usec = milliseconds*1000;
    return settimeofday(&tv, NULL);
}


void SetZoneInfo(int zone)
{
    switch(zone){
        case -11:
            system("uci set system.@system[0].zonename='Pacific/Niue'");
            system("uci set system.@system[0].timezone='NUT11'");
            system("uci commit");
            system("echo NUT11 > /etc/TZ");
            break;
        case -10:
            system("uci set system.@system[0].zonename='Pacific/Honolulu'");
            system("uci set system.@system[0].timezone='HST10'");
            system("uci commit");
            system("echo HST10 > /etc/TZ");
            break;
        case -9:
            system("uci set system.@system[0].zonename='Pacific/Gambier'");
            system("uci set system.@system[0].timezone='GAMT9'");
            system("uci commit");
            system("echo GAMT9 > /etc/TZ");
            break;
        case -8:
            system("uci set system.@system[0].zonename='Pacific/Pitcairn'");
            system("uci set system.@system[0].timezone='PST8'");
            system("uci commit");
            system("echo PST8 > /etc/TZ");
            break;
        case -7:
            system("uci set system.@system[0].zonename='America/Phoenix'");
            system("uci set system.@system[0].timezone='MST7'");
            system("uci commit");
            system("echo MST7 > /etc/TZ");
            break;
        case -6:
            system("uci set system.@system[0].zonename='America/Guatemala'");
            system("uci set system.@system[0].timezone='CST6'");
            system("uci commit");
            system("echo CST6 > /etc/TZ");
            break;
        case -5:
            system("uci set system.@system[0].zonename='America/Jamaica'");
            system("uci set system.@system[0].timezone='EST5'");
            system("uci commit");
            system("echo EST5 > /etc/TZ");
            break;
        case -4:
            system("uci set system.@system[0].zonename='America/Anguilla'");
            system("uci set system.@system[0].timezone='AST4'");
            system("uci commit");
            system("echo AST4 > /etc/TZ");
            break;
        case -3:
            system("uci set system.@system[0].zonename='America/Paramaribo'");
            system("uci set system.@system[0].timezone='SRT3'");
            system("uci commit");
            system("echo SRT3 > /etc/TZ");
            break;
        case -2:
            system("uci set system.@system[0].zonename='America/Noronha'");
            system("uci set system.@system[0].timezone='FNT2'");
            system("uci commit");
            system("echo FNT2 > /etc/TZ");
            break;
        case -1:
            system("uci set system.@system[0].zonename='Atlantic/Cape Verde'");
            system("uci set system.@system[0].timezone='CVT1'");
            system("uci commit");
            system("echo CVT1 > /etc/TZ");
            break;
        case 0:
            system("uci set system.@system[0].zonename='Africa/Accra'");
            system("uci set system.@system[0].timezone='GMT0'");
            system("uci commit");
            system("echo GMT0 > /etc/TZ");
            break;
        case 1:
            system("uci set system.@system[0].zonename='Africa/Malabo'");
            system("uci set system.@system[0].timezone='WAT-1'");
            system("uci commit");
            system("echo WAT-1 > /etc/TZ");
            break;
        case 2:
            system("uci set system.@system[0].zonename='Africa/Bujumbura'");
            system("uci set system.@system[0].timezone='CAT-2'");
            system("uci commit");
            system("echo CAT-2 > /etc/TZ");
            break;
        case 3:
            system("uci set system.@system[0].zonename='Africa/Djibouti'");
            system("uci set system.@system[0].timezone='EAT-3'");
            system("uci commit");
            system("echo EAT-3 > /etc/TZ");
            break;
        case 4:
            system("uci set system.@system[0].zonename='Asia/Dubai'");
            system("uci set system.@system[0].timezone='GST-4'");
            system("uci commit");
            system("echo GST-4 > /etc/TZ");
            break;
        case 5:
            system("uci set system.@system[0].zonename='Asia/Aqtau'");
            system("uci set system.@system[0].timezone='AQTT-5'");
            system("uci commit");
            system("echo AQTT-5 > /etc/TZ");
            break;
        case 6:
            system("uci set system.@system[0].zonename='Asia/Dhaka'");
            system("uci set system.@system[0].timezone='BDT-6'");
            system("uci commit");
            system("echo BDT-6 > /etc/TZ");
            break;
        case 7:
            system("uci set system.@system[0].zonename='Asia/Bangkok'");
            system("uci set system.@system[0].timezone='ICT-7'");
            system("uci commit");
            system("echo ICT-7 > /etc/TZ");
            break;
        case 8:
            system("uci set system.@system[0].zonename='Asia/Shanghai'");
            system("uci set system.@system[0].timezone='CST-8'");
            system("uci commit");
            system("echo CST-8 > /etc/TZ");
            break;
        case 9:
            system("uci set system.@system[0].zonename='Asia/Tokyo'");
            system("uci set system.@system[0].timezone='JST-9'");
            system("uci commit");
            system("echo JST-9 > /etc/TZ");
            break;
        case 10:
            system("uci set system.@system[0].zonename='Pacific/Guam'");
            system("uci set system.@system[0].timezone='ChST-10'");
            system("uci commit");
            system("echo ChST-10 > /etc/TZ");
            break;
        case 11:
            system("uci set system.@system[0].zonename='Pacific/Noumea'");
            system("uci set system.@system[0].timezone='NCT-11'");
            system("uci commit");
            system("echo NCT-11 > /etc/TZ");
            break;
        case 12:
            system("uci set system.@system[0].zonename='Pacific/Nauru'");
            system("uci set system.@system[0].timezone='NRT-12'");
            system("uci commit");
            system("echo NRT-12 > /etc/TZ");
            break;
        default:
            break;
    }
}

void GetWeekday(char week_buf[])
{
    memset(week_buf, 0, sizeof(week_buf));
    time_t timep;
    time(&timep);
    strcpy(week_buf, ctime(&timep));
    std::string strtemp = week_buf;
    strtemp = strtemp.substr(0, 3);
    memset(week_buf, 0, strlen(week_buf));
    strcpy(week_buf, strtemp.c_str());
}

/*void GetDateTime(std::string& datetime)
{
    time_t cur;
    time(&cur);
    struct tm* curtm = localtime(&cur);
    int year = curtm->tm_year+1900;
    int mon = curtm->tm_mon+1;
    int day = curtm->tm_mday;
    int hour = curtm->tm_hour;
    int min = curtm->tm_min;
    int sec = curtm->tm_sec;
    char buf[30] = { 0 };
    sprintf(buf,"%4d %02d %02d %02d:%02d:%02d",year,mon,day,hour,min,sec);
    datetime = std::string(buf);
}*/

int GetTaskDay(std::string weekday) {
    int i = -1;
    if (weekday.compare("Mon") == 0) {
        i = 1;
    } else if (weekday.compare("Tue") == 0) {
        i = 2;
    } else if (weekday.compare("Wed") == 0) {
        i = 3;
    } else if (weekday.compare("Thu") == 0) {
        i = 4;
    } else if (weekday.compare("Fri") == 0) {
        i = 5;
    } else if (weekday.compare("Sat") == 0) {
        i = 6;
    } else if (weekday.compare("Sun") == 0) {
        i = 0;
    }
    return i;
}

std::string Time2Cron(std::string &time, std::string &weekend)
{
    std::string DayOfWeek = "";
    for (int i = 0; i < 7; i++) {
        if (weekend.substr(i,1).compare("1") == 0) {
            DayOfWeek = DayOfWeek + "&" + boost::lexical_cast<std::string>(i+1);
        }
    }
    if (DayOfWeek.substr(0,1).compare("&") == 0) {
        DayOfWeek = DayOfWeek.substr(1,DayOfWeek.length()-1);
    }
    std::string crontime = time.substr(3,2) + " " + time.substr(0,2) + " " + "?" + " " + "*" + " " + DayOfWeek;
    return crontime;
}

int GetDevEpnum(int devType)
{
    switch (devType) {
    case 13:
    case 14:
    case 62:
    case 81:
    case 0xB9:
    case 0x1F0:
        return 2;
    case 63:
        return 3;
    case 64:
    case 0xA1:
    case 0xC0:
    case 0x1F1:
        return 4;
    default :
        return 1;
    }
}

void SignalInit()
{
    signal(SIGPIPE, SIG_IGN);
    signal(SIGUSR1, SIG_IGN);
    sigset_t bset, oset;
    sigemptyset(&bset);
    sigaddset(&bset,SIGALRM);
    if (pthread_sigmask(SIG_BLOCK, &bset, &oset) != 0) {
        print_error("Set pthread mask failed\n");
    }
}

long MemAvailable()
{
    std::fstream fileOut;
    long memAvail = 0;

    fileOut.open("/proc/meminfo",std::ios::in | std::ios::app);
    if (fileOut.is_open()) {//文件打开
        while (!fileOut.eof()) {
            std::string macTmp("");
            getline(fileOut,macTmp);
            if (strstr(macTmp.c_str(),"MemFree:") || strstr(macTmp.c_str(),"Buffers:")) {
                std::vector<std::string> vStr;
                boost::split( vStr,macTmp, boost::is_any_of( " " ), boost::token_compress_on );
                memAvail +=  strtol(vStr.at(1).c_str(), NULL, 10);
            }
        }
        fileOut.close();
    } else {
        print_error("Fail To Open Configration File of Memory!\n");
    }

    return memAvail;
}

void CacheRelease()
{
    system("sync;echo 3 > /proc/sys/vm/drop_caches");
}

int CheckFileVersion(int argc, char** argv)
{
    int optionchar;             /*选项字符*/
    if (argc >= 2) {
        optionchar = getopt(argc, argv, "vVhH?");
        switch (optionchar) {
        case 'v':
        case 'V':
            printf("Compile time:%s-%s\n", __DATE__, __TIME__);
            printf("The internal version is:%s.\n", GWVERSION);
            break;
        case 'h':
        case 'H':
        case '?':
            printf("Please input -v or -V to get the file version.\n");
            break;
        default:
            break;
        }
        if(strcmp(argv[1], "--debugmode") == 0){
            GlobalConfig::RUN_MODE = 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

//获取服务器时区
std::string GetTimeZone() {
    const char * getTimeZoneCmd = "uci get system.@system[0].zonename";
    char chRes[100] = {0};
    system_custom(getTimeZoneCmd, chRes);
    std::string zoneInfo(chRes);

    if (zoneInfo.empty()) {
        zoneInfo = "Asia/Shanghai";
    }
    return zoneInfo;
}

void GetBoardName()
{
    std::string strBoardName;
    std::ifstream ifileOut("/tmp/sysinfo/board_name");
    if(ifileOut.is_open()) { //文件打开
        getline(ifileOut,strBoardName);
        ifileOut.close();
    }
    if(strBoardName.compare("icam01-simple")==0){
        GlobalConfig::BoardType_G = 1; //随便看摄像机
    } else if(strBoardName.compare("icam04-ptz")==0){
        GlobalConfig::BoardType_G = 2;//企鹅机
    } else if(strBoardName.compare("icam05-ircut")==0){
        GlobalConfig::BoardType_G = 3; //随便看摄像机(升级版:增加夜视功能)
    } else if(strBoardName.compare("gw7310")==0){
        GlobalConfig::BoardType_G = 6;//梦想之花
    }
}

std::string GetFileContent(std::string fileName, int line)
{
    std::string strFileContent("");
    std::ifstream ifileOut(fileName.c_str());
    if(ifileOut.is_open()) { //文件打开
        int i = 1;
        while (!ifileOut.eof()) {
            if (line == 0) {
                std::string strTemp("");
                getline(ifileOut, strTemp);
                strFileContent += strTemp;
                strFileContent += "\r\n";
            } else {
                std::string strTemp("");
                getline(ifileOut, strTemp);
                strFileContent = strTemp;
                break;
            }
            ++i;
        }
        ifileOut.close();
    }
    return strFileContent;
}

int FindMacAddr()
{
#ifdef PLATFORM_ARM_IPCAMERA
    int iRet = -1;
    std::ifstream ifileOut("/etc/configenv/gwid");
    std::string strMacAddr;
    if(ifileOut.is_open()) { //文件打开
        getline(ifileOut,strMacAddr);
        ifileOut.close();
    }

    boost::regex pattern("([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2}");

    if(boost::regex_match(strMacAddr, pattern)){
        iRet = 0;
    } else {
        print_error("There is no gateway's macaddress.\n");
    }

    return iRet;
#else
    return 0;
#endif
}
int GetSequence()
{
    if(GlobalConfig::Sequence_G != 255){
        ++GlobalConfig::Sequence_G;
    }else{
        GlobalConfig::Sequence_G = 1;
    }
    return GlobalConfig::Sequence_G;
}

void ChangeCronFlag(std::string& cronexp, std::string oldflag, std::string replaceflag)
{
    size_t pos = std::string::npos;
    while((pos = cronexp.find(oldflag)) != std::string::npos) {
          cronexp.replace(pos,1,replaceflag);
    }
}

void GetProtocol37()
{
    std::fstream fileIn;
    fileIn.open("/etc/configenv/protocol37",std::ios::in);
    if (fileIn.is_open()) {//文件打开
        if (!fileIn.eof()) {
            std::string protocol37("");
            getline(fileIn,protocol37);
            int flag = boost::lexical_cast<int>(protocol37);
            if (flag == 2) {
                GlobalConfig::SupportRule_G = 3;
                fileIn.close();
                system("echo 3 > /etc/configenv/protocol37");
                system("cp /etc/configenv/wlhome_bak.db /etc/configenv/wlhome.db");
            } else {
                GlobalConfig::SupportRule_G = flag;
            }
        }
        fileIn.close();
    } else {
        print_error("Fail To Open Configration File of protocol37!\n");
    }
    print_info("Init SupportRule_G = %d\n", GlobalConfig::SupportRule_G);
}


int system_custom(const char *cmd, char *buf)
{
    FILE * fp;
    int res; 
    char temp[1024] = {0};
    if (cmd == NULL) {
        return -1;    
    }

    if ((fp = popen(cmd, "r") ) == NULL) {
        print_error("popen error\n");
        return -1;
    } else {
        buf[0] = '\0';
        while (fgets(temp, sizeof(temp), fp)) {
            strcat(buf, temp);
        }
        res = pclose(fp);
    }

    char *p;
    int pos = 0;
    p = strstr(buf, "\n");
    if(p != NULL){
        pos = p - buf;
        buf[pos] = '\0';
    }

    return res;
}

bool GetDevReissueFlag(int iType)
{
    bool bRet = false;
    switch(iType){
        case 10:
        case 12:
        case 13:
        case 14:
        case 16:
        case 25:
        case 28:
        case 50:
        case 51:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 77:
        case 78:
        case 80:
        case 81:
        case 0x1F0:
        case 0x1F1:
            bRet = true;
            break;
        default:
            break;
    }
    return bRet;
}

#ifdef PLATFORM_DREAMFLOWER
//-计算冗余校验CRC
unsigned int MOD_KG_CRC16(unsigned char *MOD_KG_CRC16_start,unsigned char MOD_KG_CRC16_bytes)
{
    unsigned int bx, cx, i, j;
    bx = 0xffff;
    cx = 0xa001;
    for (i=0;i<MOD_KG_CRC16_bytes;i++) {
        bx=bx^MOD_KG_CRC16_start[i];
        for (j=0;j<8;j++) {
            if ((bx&0x0001)==1) {
                bx=bx>>1;
                bx=bx&0x7fff;
                bx=bx^cx;
            } else {
                bx=bx>>1;
                bx=bx&0x7fff;
            }
        }
    }
    return(bx);
}

void HexGet(unsigned char *read, int len, char *rets)
{
   char tmp[512]={'\0'};
    int i=0,j=0;
    for(int k = len-1; k>=0; k--){
        int h = (int)*(read + k);
        if(h == 0){
            tmp[i] = '0';
            tmp[i+1] = '0';
            i = i+ 2;
        }
        while(h > 0){
            if((h%16)>9){
                tmp[i]=h%16+0x37;
            } else {
                tmp[i]=h%16+0x30;
            }

            h=h/16;
            i++;
        }
        
        if(i%2 != 0){
            tmp[i++] = '0';
        }
    }
    
    i--;
    for(j=0;j<len*2;j++)
    {
        rets[j]=tmp[i];
        i--;
        if(i<0) break;
    }
    rets[++j] = '\0';
}

int GetTaskDay_PlayTime(std::string weekday) {
    int i = -1;
    if (weekday.compare("Mon") == 0) {
        i = 0;
    } else if (weekday.compare("Tue") == 0) {
        i = 1;
    } else if (weekday.compare("Wed") == 0) {
        i = 2;
    } else if (weekday.compare("Thu") == 0) {
        i = 3;
    } else if (weekday.compare("Fri") == 0) {
        i = 4;
    } else if (weekday.compare("Sat") == 0) {
        i = 5;
    } else if (weekday.compare("Sun") == 0) {
        i = 6;
    }
    return i;
}

//currentTime:hhmm
//setTime:hhmm
int CalcDiffTime(std::string &currentTime, std::string &setTime)
{
    //计算时间相对于00:00的分钟数
    int iMinCurr = atoi(currentTime.substr(0,2).c_str())*60 + 
                   atoi(currentTime.substr(2,2).c_str());
    int iMinSet = atoi(setTime.substr(0,2).c_str())*60 + 
                  atoi(setTime.substr(2,2).c_str());

    return iMinCurr - iMinSet;
}
#endif