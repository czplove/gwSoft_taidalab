#ifndef _WL_PLATFORMINIT_H_
#define _WL_PLATFORMINIT_H_

#include <vector>
#include "../utility/MySingleton.hpp"

class PlatformInit : public MySingleton<PlatformInit>
{
public :
    PlatformInit();
    virtual ~PlatformInit();
    void PlatFormInit();
    std::vector<std::string> GetCSAddr();
#ifdef PLATFORM_DREAMFLOWER
    void GetLanguage();
#endif
#ifdef PLATFORM_ARM_IPCAMERA
    int FindMacAddr();
    void SetMaxDevNum();
#endif
private :
    //���ص�ַ��ʼ��
    void GwMacAddrInit();
    //����IP��ʼ��
    void GwIpAddrInit();
    void GetGwIp(const std::string &eth_name);
};

#endif
