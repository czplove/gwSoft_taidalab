#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <fstream>

#include "CommonFunc.hpp"



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
        //-if(strcmp(argv[1], "--debugmode") == 0){
        //-    GlobalConfig::RUN_MODE = 1;
        //-    return 0;
        //-}
        return 1;
    }
    return 0;
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