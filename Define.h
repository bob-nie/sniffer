#include "resource.h"
#include <wchar.h>
#include <string.h>
#include <stdio.h>
 
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")
 
#include<sys/types.h>
//#include<sys/socket.h>
 
//#include <ws2tcpip.h>
//#include <winsock2.h>
 
#pragma comment(lib, "ws2_32.lib")
 
 
 
#define BUFFER_SIZE 65535
 
typedef struct _IpHeader{
    union{
        BYTE   Version;
        BYTE   HdrLen;
    };
    BYTE ServiceType;
    WORD TotalLen;
    WORD ID;
    union{
        WORD   Flags;
        WORD   FragOff;
    };
    BYTE TimeToLive;
    BYTE Protocol;
    WORD HdrChksum;
    DWORD   SrcAddr;
    DWORD   DstAddr;
	//BYTE Options;
    //DWORD Options;
}IpHeader, *PIpHeader;
 
 
//
// TCP Packet Structure
//
typedef struct _TcpHeader{
    WORD SrcPort;
    WORD DstPort;
    DWORD SeqNum;
    DWORD AckNum;
    BYTE DataOff;
    BYTE Flags;
    WORD Window;
    WORD Chksum;
    WORD UrgPtr;
}TcpHeader, *PTcpHeader;
 
 
#define SIO_RCVALL 0x98000001
#define IP_HDRINCL 2
