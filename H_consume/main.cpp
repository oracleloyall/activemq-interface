/*
 * 基于active mq 的开发程序，实现回调注册
 * need activemq-cpp,pthread,
 */
#include<iostream>
#include"active_/active_.hpp"
using namespace std;
#include"Rand/TRNG.hh"
#include"Timer/TTimer.hh"
string char_="0123456789abcdefABCDEF";
#include<stdio.h>
typedef unsigned short int Word;
#define DBG_PROGRAM 0
#include<stdlib.h>
#define RANDOM(x) (rand()%x)
#define MAC_ADDR_LENGTH 12
#define FMT_MAC_ADDR_LEN (MAC_ADDR_LENGTH+5)
#include<unistd.h>
unsigned char HEXCHAR[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C',
'D','E','F'};
unsigned char genMACAddr[MAC_ADDR_LENGTH];
unsigned char fmtMACAddr[FMT_MAC_ADDR_LEN]={'0','0','-','0','0','-','0','0','-',
'0','0','-','0','0','-','0','0'};

//#define _DEBUG
void formatMACAddr(void)
{
unsigned short i = 0;
unsigned short n = 0;

for( i = 0; i < MAC_ADDR_LENGTH; i++, n++ )
{
if( fmtMACAddr[n] != '-' )
{
fmtMACAddr[n] = genMACAddr[i];
}
else
{
n++;
fmtMACAddr[n] = genMACAddr[i];
}
}
}
#include <hash_map>
#include <ext/hash_map>
//using namespace stdext;
//using namespace stdext;
using namespace std;
#include<vector>
#include<map>
class  MacPro
{
public:
	MacPro();
	void Produce();
    ~MacPro();
    string &find(string &one);
    vector<string> Consume;
    map<string,string>m;
    string GetMac();
    int size();
    int index;
    unsigned short n ;
    unsigned short num;
};
string& MacPro::find(string &one)
{
	map<string, string>::iterator iter1 = m.find(one.c_str());
	if(iter1 !=m.end())
		{
		cout<<"发现\n";
		}
}
string  MacPro::GetMac()
{
    index++;
    if(index<Consume.size())
    return Consume.at(index);
    else
    {
    	index=0;
    	return Consume.at(index);
    }

}
MacPro::MacPro():index(0),n(0),num(20000)
{
	Produce();
	for(int i=0;i<1000000;i++)
	{
		//cout<<"char ru\n";
		char k=i;
		string l(&k);
		m.insert(pair<string,string>(l,string("1")));
	}
}
MacPro::~MacPro()
{
	cout<<Consume.size()<<endl;

}


//
void MacPro::Produce()
{

	srand(getpid());
	for( int j = 0; j < num; j++ )
	{
	for( int i = 0; i < MAC_ADDR_LENGTH; i++ )
	{
	n = RANDOM(16);
	genMACAddr[i] = HEXCHAR[n];
	}
    string mac((char *)genMACAddr);
    Consume.push_back(mac);
}
}
//MacPro macpro;
string global_url("http://122.224.64.245/api10/login?prot_type=0&");
//static int http_copy(const char* flag,const char* buf,char* strbuf,int size)
//{
//	char *iter = NULL;
//	int i = 0, len = 0;
//	iter = strstr((char *)buf, flag);
//	len = strlen(flag);
//	if (iter == NULL) {
//		return -1;
//	} else {
//		if(*(iter + len) == '=')
//		{
//			char * tmp = strstr(iter + len,"&");
//			int slen = 0;
//			if(!tmp)
//				slen = strlen(iter + len) - 1;
//			else
//				slen =tmp - (iter + len + 1);
//			if(slen < size)
//			{
//				memcpy(strbuf,iter + len + 1,slen);
//				return 0;
//			}
//		}
//	}
//	return -1;
//}
#include <dlfcn.h>
////#define _GNU_SOURCE
//void identify_function_ptr( void *func)  {
//	  Dl_info info;
//	  int rc;
//
//	  rc = dladdr(func, &info);
//
//	  if (!rc)  {
//	      printf("Problem retrieving program information for %x:  %s\n", func, dlerror());
//	  }
//
//	  printf("Address located in function %s within the program %s\n", info.dli_fname, info.dli_sname);
//	}
#ifdef _DDEBUG
#include <curl/curl.h>
int main(int argc, char* argv[])
{
	CURL *curl;
	//curl = curl_easy_init();
unsigned short n = 0;
unsigned short i = 0;
unsigned long j = 0;
TTimer t(REAL_TIME );
t.start();
//identify_function_ptr(&curl);
MacPro macpro;
t.stop();
std::cout << "time for recursion = " << t << std::endl;
sleep(1);
t.start();
int w=10000000;
char c=w;
string l(&c);
macpro.find(l);
t.stop();
std::cout << "time for recursion = " << t << std::endl;
//hash_map<string,string> IntHash;
//hash_map<std::string,string> l;
//unsigned long num = 0;
//FILE *fp = 0;
//
//if( argc != 3 )
//{
//printf("Usage: generate_mac_addr savefile.txt 1000");
//return -1;
//}
//
//num = atol( argv[2] );
//
//fp = fopen( argv[1], "w" );
//if( !fp )
//{
//printf("create the file %s failed\r\n",argv[1]);
//return -1;
//}
//
//fprintf( fp, "NO.\t\tMAC Address 1\t\tMAC Address 2\r\n" );
//
//srand(getpid());
//for( j = 0; j < num; j++ )
//{
//for( i = 0; i < MAC_ADDR_LENGTH; i++ )
//{
//n = RANDOM(16);
//#if DBG_PROGRAM
//printf("Times: %d, Random Number: %d, HEX char: %c\r\n",i,n,HEXCHAR[n]);
//#endif
//genMACAddr[i] = HEXCHAR[n];
//}
//#if DBG_PROGRAM
//printf("writing the MAC address......%ld\r\n",(j+1));
//#endif
//
//
//formatMACAddr();
//fprintf( fp, "%ld\t\t%s\t\t%s\r\n", (j+1), genMACAddr, fmtMACAddr );
//}
//
//fclose(fp);
//
//printf("generate the MAC address successfully!\r\n");

return 0;
}
#else

//const int HoursPerDay   = 24;
//const int MinsPerHour   = 60;
//const int SecsPerMin    = 60;
//const int MSecsPerSec   = 1000;
//const int MinsPerDay    = HoursPerDay * MinsPerHour;
//const int SecsPerDay    = MinsPerDay * SecsPerMin;
//const int MSecsPerDay   = SecsPerDay * MSecsPerSec;
//const int UnixDateDelta = 25569;
//const int DateDelta     = 693594;
//bool TryEncodeTime(Word Hour, Word Min, Word Sec, Word MSec, pDouble Time)
//{
//  if ( (Hour < HoursPerDay) and (Min < MinsPerHour) and (Sec < SecsPerMin) and (MSec < MSecsPerSec) )
//  {
//    *Time = ((double)Hour * ((double)MinsPerHour * SecsPerMin * MSecsPerSec) +
//    		(double)Min * (SecsPerMin * MSecsPerSec) +
//    		(double)Sec * MSecsPerSec +
//    		(double)MSec) / MSecsPerDay;
//    return true;
//  }
//  return false;
//}
//
//typedef Word TDayTable[12];
//typedef TDayTable* PDayTable;
//Word MonthDays[2][12] =
//  {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
//   {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
//double EncodeTime(Word Hour, Word Min, Word Sec, Word MSec)
//{
//  double ret;
//  if (!TryEncodeTime(Hour, Min, Sec, MSec, &ret)) return false;
//  return ret;
//}
//
//bool IsLeapYear(Word Year)
//{
//  return ((Year % 4) == 0) && (((Year % 100) != 0) || ((Year % 400) == 0));
//}
//bool TryEncodeDate(Word Year, Word Month, Word Day, pDouble Date)
//{
//  PDayTable DayTable = IsLeapYear(Year) ? &MonthDays[1] : &MonthDays[0];
//  if ((Year >= 1) && (Year <= 9999) && (Month >= 1) && (Month <= 12) &&
//    (Day >= 1) && (Day <= (*DayTable)[Month - 1]))
//  {
//    for (int i = 1 ; i <  Month; i++) Day += (*DayTable)[i - 1];
//    int i = Year - 1;
//    *Date = i * 365 + (i >> 2) - i / 100 + i / 400 + Day - DateDelta;
//    return true;
//  }
//  return false;
//}
//double EncodeDate(Word Year, Word Month, Word Day)
//{
//	double ret;
//    if (!TryEncodeDate(Year, Month, Day, &ret)) return 0;
//    return ret;
//}
//#include<time.h>
//double Now()
//{
//	time_t T;
//	timeval TV;
//	tm UT;
//	gettimeofday(&TV, NULL);
//	T = TV.tv_sec;
//	localtime_r(&T, &UT);
//	return EncodeDate(UT.tm_year + 1900, UT.tm_mon + 1, UT.tm_mday) +
//	    EncodeTime(UT.tm_hour, UT.tm_min, UT.tm_sec, TV.tv_usec / 1000);
//}
const double LOCAL_TIME_DELTA = (double)1 / 3;
const double H_SEC = (double)1 / 24 / 60 / 60;
const double H_SEC_R = (double)1 / H_SEC;
//
//bool DecodeDateFully(const double DateTime, pWord Year, pWord Month, pWord Day, pWord DOW)
//{
//  Word Y, M, D, I;
//  bool ret;
//  PDayTable DayTable;
//  TTimeStamp ts;
//  DateTimeToTimeStamp(DateTime, &ts);
//
//  int T = ts.Date;
//  if (T <= 0)
//  {
//    *Year = 0;
//    *Month = 0;
//    *Day = 0;
//    *DOW = 0;
//    return false;
//  }
//  else
//  {
//    *DOW = Word(T % 7 + 1);
//    T--;
//    Y = 1;
//    while (T >= D400)
//    {
//      T -= D400;
//      Y += 400;
//    }
//    DivMod(T, D100, &I, &D);
//    if (I == 4)
//    {
//      I--;
//      D += D100;
//    }
//    Y += I * 100;
//    DivMod(D, D4, &I, &D);
//    Y += I * 4;
//    DivMod(D, D1, &I, &D);
//    if (I == 4)
//    {
//      I--;
//      D += D1;
//    }
//    Y += I;
//    ret = IsLeapYear(Y);
//    if (ret)
//      DayTable = &MonthDays[1];
//    else
//      DayTable = &MonthDays[0];
//    M = 1;
//    while (true)
//    {
//      I = (*DayTable)[M - 1];
//      if (D < I) break;
//      D -= I;
//      M++;
//    }
//    *Year = Y;
//    *Month = M;
//    *Day = D + 1;
//  }
//  return ret;
//}
//void DecodeDate(const double DateTime, pWord Year, pWord Month, pWord Day)
//{
//  Word Dummy;
//  DecodeDateFully(DateTime, Year, Month, Day, &Dummy);
//}
//void DecodeDateTime(const double AValue, pWord AYear, pWord AMonth, pWord ADay,
//		            pWord AHour, pWord AMinute, pWord ASecond, pWord AMilliSecond)
//{
//	DecodeDate(AValue, AYear, AMonth, ADay);
//	DecodeTime(AValue, AHour, AMinute, ASecond, AMilliSecond);
//}
//string DateToGMTStr(double dt, bool GMTFix)
//{
//    Word y, m, d, h, n, s, z, w, x;
//    if (GMTFix) dt -= LOCAL_TIME_DELTA;
//    DecodeDateTime(dt, &y, &m, &d, &h, &n, &s, &z);
//    DecodeDateWeek(dt, &y, &w, &x);
//    char* buf = new char[256];
//    memset(buf, 0, 256);
//    string t = FormatDateTime("hh:nn:ss", dt);
//    sprintf(buf, "%s, %d %s %d %s GMT", WEEK_DAYS[x - 1].c_str(), d, MONTHS[m - 1].c_str(), y, t.c_str());
//    string a = string(buf);
//    free(buf);
//    return a;
//}
//string DateTimeToGMT(const double AValue)
//{
//    return DateToGMTStr(AValue);
//}
#endif
#ifdef _HJ
int main()
{
    time_t curTime = time(NULL);
    tm * gmTime = gmtime(&curTime);
    char strExperis[50];
    char strTimeBuf[100]={0};
    strftime(strTimeBuf, 100, " %a, %d %b %Y %X GMT;", gmTime);
	unsigned short n = 0;
	unsigned short i = 0;
	unsigned long j = 0;
	unsigned long num = 0;
	cout<<strTimeBuf<<endl;
	//double now = Now();
//	DateTimeToGMT(now)
//	TRNG rng;
//	for(int i=0;i<100;i++)
//	{
//	int m=int(rng.rand(100));
//	cout<<m<<endl;
//	}
//
//	for(int  i = 0; i < MAC_ADDR_LENGTH; i++ )
//	{
//	n = RANDOM(16);
//	//printf("Times: %d, Random Number: %d, HEX char: %c\r\n",i,n,HEXCHAR[n]);
//	genMACAddr[i] = HEXCHAR[n];
//
//	}
//	printf("%s\r\n", genMACAddr);
//	for(int  i = 0; i < MAC_ADDR_LENGTH; i++ )
//	{
//		n = RANDOM(16);
//		//printf("Times: %d, Random Number: %d, HEX char: %c\r\n",i,n,HEXCHAR[n]);
//		genMACAddr[i] = HEXCHAR[n];
//
//		}
//		printf("%s\r\n", genMACAddr);
	return 0;

}
#endif
active_ *al=new active_;
int main(void)
{

   // al->test_send();
    while(1)
       {
       	usleep(2);
       	al->test_send();
       }
    return 0;
}
