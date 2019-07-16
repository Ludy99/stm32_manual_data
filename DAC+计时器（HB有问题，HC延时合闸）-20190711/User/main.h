#ifndef __MAIN_H
#define __MAIN_H
#include "stm32f10x.h"
#include"Delay.h"
#include "math.h"
#include "SineWave1.h"


float radian=30;//正弦波平移弧度，radian的取值范围是0~360
float  V=1000; /*正弦波峰峰值为1.8Vpp*/ 
#define  Um (V/1000) /*正弦波峰峰值为1.8Vpp*/
#define PI 3.1415926
#define  DL (256)//正弦波描点数
uint16_t DualSine12bit[DL]; //正弦波用函数封装
float Wave1_Fre=50.0;//初始频率50Hz（触摸屏变化范围为20~200Hz）

u8 time_start_flag=0;  //计时启动标志
u8 time_stop_flag=0;  //计时停止标志
int time_count_ms=0;  //计时器初始值
int Time_show;//时间显示变量
int Qianwei;//time_count_ms千位
int Baiwei;//time_count_ms百位
int Shiwei;//time_count_ms十位
int Gewei;//time_count_ms个位



#define DAC_DHR12R1    (u32)&(DAC->DHR12R1)   //DAC通道1输出地址
#define DAC_DHR12R2    (u32)&(DAC->DHR12R2)   //DAC通道2输出地址

 void SineWave_Data( u16 cycle ,u16 *D)
{
	u16 i;
    for( i=0;i<cycle;i++)
    {
		D[i]=(u16)((Um*sin(( 1.0*i/(cycle-1))*2*PI+radian*0.017453)+Um)*4095/3.3);
    }
}

/* Private  ------------------------------------------------------------*/
#define RELAY_A_Port					GPIOD
#define RELAY_A_Pin						GPIO_Pin_0                           
#define RELAY_A_RCC_APB2Periph			RCC_APB2Periph_GPIOD  //PD0   RELAYA

#define RELAY_B_Port					GPIOD
#define RELAY_B_Pin						GPIO_Pin_1
#define RELAY_B_RCC_APB2Periph			RCC_APB2Periph_GPIOD  //PD1   RELAYB       

#define RELAY_C_Port					GPIOD
#define RELAY_C_Pin						GPIO_Pin_2
#define RELAY_C_RCC_APB2Periph			RCC_APB2Periph_GPIOD  //PD2   RELAYC  

#define RELAY_D_Port					GPIOD
#define RELAY_D_Pin						GPIO_Pin_3
#define RELAY_D_RCC_APB2Periph			RCC_APB2Periph_GPIOD  //PD3   RELAYD

#define RELAY_E_Port					GPIOD
#define RELAY_E_Pin						GPIO_Pin_4
#define RELAY_E_RCC_APB2Periph			RCC_APB2Periph_GPIOD  //PD4   RELAYE

#define RELAY_F_Port					GPIOD
#define RELAY_F_Pin						GPIO_Pin_5
#define RELAY_F_RCC_APB2Periph			RCC_APB2Periph_GPIOD  //PD5    RELAYF


//#define TRIGGER_TA_Port						GPIOA
//#define TRIGGER_TA_Pin						GPIO_Pin_5
//#define TRIGGER_TA_RCC_APB2Periph			RCC_APB2Periph_GPIOA //PA5   TA-CPU


//#define TRIGGER_TB_Port						GPIOA
//#define TRIGGER_TB_Pin						GPIO_Pin_4
//#define TRIGGER_TB_RCC_APB2Periph			RCC_APB2Periph_GPIOA //PA4   TB-CPU

#define TRIGGER_TC_Port						GPIOA
#define TRIGGER_TC_Pin						GPIO_Pin_3
#define TRIGGER_TC_RCC_APB2Periph			RCC_APB2Periph_GPIOA //PA3   TC-CPU

#define TRIGGER_HA_Port						GPIOA
#define TRIGGER_HA_Pin						GPIO_Pin_2
#define TRIGGER_HA_RCC_APB2Periph			RCC_APB2Periph_GPIOA //PA2   HA-CPU

#define TRIGGER_HB_Port						GPIOA
#define TRIGGER_HB_Pin						GPIO_Pin_1
#define TRIGGER_HB_RCC_APB2Periph			RCC_APB2Periph_GPIOA //PA1   HB-CPU

#define TRIGGER_HC_Port						GPIOA
#define TRIGGER_HC_Pin						GPIO_Pin_0
#define TRIGGER_HC_RCC_APB2Periph			RCC_APB2Periph_GPIOA //PA0   HC-CPU

#define TRIGGER_TD_Port						GPIOD
#define TRIGGER_TD_Pin						GPIO_Pin_13
#define TRIGGER_TD_RCC_APB2Periph			RCC_APB2Periph_GPIOD //PD13   TD-CPU


#define TRIGGER_TE_Port						GPIOD
#define TRIGGER_TE_Pin						GPIO_Pin_12
#define TRIGGER_TE_RCC_APB2Periph			RCC_APB2Periph_GPIOD //PD12   TE-CPU


#define TRIGGER_TF_Port						GPIOD
#define TRIGGER_TF_Pin						GPIO_Pin_11
#define TRIGGER_TF_RCC_APB2Periph			RCC_APB2Periph_GPIOD //PD11   TF-CPU


#define TRIGGER_HD_Port						GPIOD
#define TRIGGER_HD_Pin						GPIO_Pin_10
#define TRIGGER_HD_RCC_APB2Periph			RCC_APB2Periph_GPIOD //PD10   HD-CPU

#define TRIGGER_HE_Port						GPIOD
#define TRIGGER_HE_Pin						GPIO_Pin_9
#define TRIGGER_HE_RCC_APB2Periph			RCC_APB2Periph_GPIOD //PD9   HE-CPU

#define TRIGGER_HF_Port						GPIOD
#define TRIGGER_HF_Pin						GPIO_Pin_8
#define TRIGGER_HF_RCC_APB2Periph			RCC_APB2Periph_GPIOD //PD8   HF-CPU

#define H025_Port					GPIOE
#define H025_Pin					GPIO_Pin_15
#define H025_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE15   H025

#define H050_Port					GPIOE
#define H050_Pin					GPIO_Pin_14
#define H050_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE14   H050

#define H100_Port					GPIOE
#define H100_Pin					GPIO_Pin_13
#define H100_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE13   H100

#define H150_Port					GPIOE
#define H150_Pin					GPIO_Pin_12
#define H150_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE12   H150

#define H200_Port					GPIOE
#define H200_Pin					GPIO_Pin_11
#define H200_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE11   H200

#define H250_Port					GPIOE
#define H250_Pin					GPIO_Pin_10
#define H250_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE10   H250

#define T025_Port					GPIOE
#define T025_Pin					GPIO_Pin_9
#define T025_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE9   T025

#define T050_Port					GPIOE
#define T050_Pin					GPIO_Pin_8
#define T050_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE8   T050


#define T100_Port					GPIOE
#define T100_Pin					GPIO_Pin_7
#define T100_RCC_APB2Periph			RCC_APB2Periph_GPIOE //PE7   T100

#define T150_Port					GPIOB
#define T150_Pin					GPIO_Pin_2
#define T150_RCC_APB2Periph			RCC_APB2Periph_GPIOB //PB2   T150


#define T200_Port					GPIOB
#define T200_Pin					GPIO_Pin_1 
#define T200_RCC_APB2Periph			RCC_APB2Periph_GPIOB //PB1   T200

#define T250_Port					GPIOB
#define T250_Pin					GPIO_Pin_0 
#define T250_RCC_APB2Periph			RCC_APB2Periph_GPIOB //PB0   T250

#define TIMEn                                          6   
#define PhaseSize                                       6           //未用
#define TimeSize									    6           //未用
#define RELAYn                                          6 
#define TriggerSize										12          //未用  
#define TRIGGERn 										12
#define MAKETIME(low,high) \
        ((uint16_t)(((uint8_t)(low)) | ((uint16_t)((uint8_t)(high))) << 8))

typedef enum 
{
  TIME1 = 0,
  TIME2 = 1,
  TIME3 = 2,
  TIME4 = 3,
  TIME5 = 4,
  TIME6 = 5,
} Time_TypeDef;

typedef enum 
{
  RELAY1 = 0,
  RELAY2 = 1,
  RELAY3 = 2,
  RELAY4 = 3,
  RELAY5 = 4,
  RELAY6 = 5,
} Relay_TypeDef;

typedef enum 
{
  TRIGGER1 = 0,
  TRIGGER2 = 1,
  TRIGGER3 = 2,
  TRIGGER4 = 3,
  TRIGGER5 = 4,
  TRIGGER6 = 5,
  TRIGGER7 = 6,
  TRIGGER8 = 7,
  TRIGGER9 = 8,
  TRIGGER10= 9,
  TRIGGER11= 10,
} Trigger_TypeDef;

typedef enum {FALSE = 0, TRUE = !FALSE} bool;
typedef enum {BUF_NO1=0,BUF_NO2=1}BUF_NO;
bool Buf_Ok;	              //BUF是否已经可用
BUF_NO Free_Buf_Now;

uint8_t  Flag=0;
uint8_t  TH_2=0; //ABC三相标志 1代表三相操作 0代表单相操作
uint8_t  TH_3=0; //DEF三相标志 1代表三相操作 0代表单相操作
uint8_t  TH_4=0; //双跳标志
uint8_t  TH_5=0; //断路器失灵标志
uint8_t  TH_6=0; //断路器失灵延时时间标志

uint16_t Time_T[6]={0,0,0,0,0,0}; //跳闸时间
uint16_t Time_H[6]={0,0,0,0,0,0}; //合闸时间
uint16_t TimeT_Correct[6]={0,0,0,0,0,0}; //跳闸校正时间
uint16_t TimeH_Correct[6]={0,0,0,0,0,0}; //合闸校正时间

u8 USART1_DMA_Buf1[512];
u8 USART1_DMA_Buf2[512];
u8 USART3_DMA_Buf1[512];
u8 USART3_DMA_Buf2[512];

u8 Relay_Status[18]={0x5A,0xA5,0x0F,0x82,0x00,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};   //ABC,DEF6个继电器的状态
u8 Machine_Status[8]={0x5A,0xA5,0x05,0x82,0x00,0x25,0x00,0x00}; //断路器现在是正常状态还是失灵状态

//u8 USART1_SEND_DATA[512];     
//u8 USART2_SEND_DATA[512]; 
u8 USART1_RECEIVE_DATA[512]; 
u8 USART2_RECEIVE_DATA[512];
u8 USART3_RECEIVE_DATA[512]; 

/***************key******************/

//#define CHOOSE_MODE GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)

/***************key******************/

#define USART3_ENABLE	
uint8_t  Flag_u=0;//BUF1空闲本地远程标志20190531

//TA[8]={0x5A,0xA5,0x05,0x82,0x00,0x34,0x00,0x00};
//0x5AA5:帧头（2个字节）
//0x05:数据长度,该项右侧全部数据（指令、数据、CRC校验 ）的长度和
//0x82:写数据存储区指令（指令0x80-0x84之一）
//0x00,0x34:数据（N字节，应符合各个控件的要求）
//0x00,0x01:CRC校验,不包括帧头和数据长度，仅针对指令和数据进行校验（2字节）可无CRC校验，CONFIG.TXT文件的R2.4决定是否启用。
//启用 CRC 帧校验并开启自动应答功能后（R2.4=1，RC.3=1）

//发送 80 指令使用 40 寄存器将上述数据存入存储器中：
//5A A5 0C 80 0x40 5A（申请更新） 50（写入数据库） 0x40,0x00,0x00,0x00（数据库首地址） 0x00,0x10（变量地址） 0x00,0x16（写入数据的长度）
uint8_t StatusBuffer_Save[15]={0x5A,0xA5,0x0C,0x80,0x40,0x5A,0x50,0x40,0x00,0x00,0x00,0x00,0x10,0x00,0x16};	 //0x20->0x40把变量存储空间的值包括时间设置、补偿时间、电流设置模式设置写入字库
uint8_t StatusBuffer_Restore[15]={0x5A,0xA5,0x0C,0x80,0x40,0x5A,0xA0,0x40,0x00,0x00,0x00,0x00,0x10,0x00,0x16};	//0x20->0x40开机把保存在字库里面的数据读入变量存储空间
uint8_t Tx_Change[7]={0x5A,0xA5,0x04,0x80,0x03,0x00,0x10};      //切换到断路器失灵界面 0x10=16（页），0x03：（读：当前显示页面ID，写：切换到指定页面）
uint8_t Tx_Return[7]={0x5A,0xA5,0x04,0x80,0x03 ,0x00,0x0B};		//返回主界面 0x0B=11（页）
uint8_t Tx_Tips[7]={0x5A,0xA5,0x04,0x80,0x03,0x00,0x11};		//切换到断路器失灵倒数计时20秒界面 0x11=17（页）
uint8_t Tx_Cancle[8]={0x5A,0xA5,0x05,0x82,0x00,0x25,0x00,0x00};	//版本号：0x00，断路器失灵按钮（0x25）恢复正常
uint8_t Ts[7]={0x5A,0xA5,0x04,0x83,0x00,0x10,0x16};	 			//0x20->0x40开机去读变量存储空间的内容22个字的内容用来后续程序的恢复上次的工作模式
uint8_t F_Res[8]={0x5A,0xA5,0x05,0x82,0x50,0x03,0xF8,0x00};	   //0x26(频率)显示变量的描述指针属性（描述指针5000），5003为颜色显示指针，F800为红色		
uint8_t V_Res[8]={0x5A,0xA5,0x05,0x82,0x50,0x13,0xF8,0x00};	   //0x27(幅值)显示变量的描述指针属性（描述指针5010），5013为颜色显示指针，F800为红色		

uint8_t TA[8]={0x5A,0xA5,0x05,0x82,0x00,0x34,0x00,0x00};          
uint8_t TB[8]={0x5A,0xA5,0x05,0x82,0x00,0x35,0x00,0x00};            
uint8_t TC[8]={0x5A,0xA5,0x05,0x82,0x00,0x36,0x00,0x00};            
uint8_t TD[8]={0x5A,0xA5,0x05,0x82,0x00,0x37,0x00,0x00};            
uint8_t TE[8]={0x5A,0xA5,0x05,0x82,0x00,0x38,0x00,0x00};           
uint8_t TF[8]={0x5A,0xA5,0x05,0x82,0x00,0x39,0x00,0x00};            

uint8_t HA[8]={0x5A,0xA5,0x05,0x82,0x00,0x34,0x00,0x01};            //0x34：A相合闸变量地址
uint8_t HB[8]={0x5A,0xA5,0x05,0x82,0x00,0x35,0x00,0x01};            //1合闸，0跳闸
uint8_t HC[8]={0x5A,0xA5,0x05,0x82,0x00,0x36,0x00,0x01};
uint8_t HD[8]={0x5A,0xA5,0x05,0x82,0x00,0x37,0x00,0x01};
uint8_t HE[8]={0x5A,0xA5,0x05,0x82,0x00,0x38,0x00,0x01};
uint8_t HF[8]={0x5A,0xA5,0x05,0x82,0x00,0x39,0x00,0x01};

uint8_t Count_21[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x15};	    //断路器失灵20秒倒计显示
uint8_t Count_20[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x14};
uint8_t Count_19[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x13};
uint8_t Count_18[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x12};
uint8_t Count_17[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x11};
uint8_t Count_16[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x10};
uint8_t Count_15[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x0F};
uint8_t Count_14[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x0E};
uint8_t Count_13[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x0D};
uint8_t Count_12[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x0C};
uint8_t Count_11[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x0B};
uint8_t Count_10[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x0A};
uint8_t Count_9[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x09};
uint8_t Count_8[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x08};
uint8_t Count_7[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x07};
uint8_t Count_6[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x06};
uint8_t Count_5[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x05};
uint8_t Count_4[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x04};
uint8_t Count_3[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x03};
uint8_t Count_2[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x02};
uint8_t Count_1[8]={0x5A,0xA5,0x05,0x82,0x00,0x3B,0x00,0x01};

uint8_t Qianwei_9[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x09};   //计时器千位
uint8_t Qianwei_8[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x08};
uint8_t Qianwei_7[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x07};
uint8_t Qianwei_6[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x06};
uint8_t Qianwei_5[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x05};
uint8_t Qianwei_4[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x04};
uint8_t Qianwei_3[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x03};
uint8_t Qianwei_2[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x02};
uint8_t Qianwei_1[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x01};
uint8_t Qianwei_0[8]={0x5A,0xA5,0x05,0x82,0x00,0x30,0x00,0x00};

uint8_t Baiwei_9[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x09};   //计时器百位
uint8_t Baiwei_8[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x08};
uint8_t Baiwei_7[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x07};
uint8_t Baiwei_6[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x06};
uint8_t Baiwei_5[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x05};
uint8_t Baiwei_4[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x04};
uint8_t Baiwei_3[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x03};
uint8_t Baiwei_2[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x02};
uint8_t Baiwei_1[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x01};
uint8_t Baiwei_0[8]={0x5A,0xA5,0x05,0x82,0x00,0x31,0x00,0x00};

uint8_t Shiwei_9[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x09};   //计时器十位
uint8_t Shiwei_8[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x08};
uint8_t Shiwei_7[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x07};
uint8_t Shiwei_6[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x06};
uint8_t Shiwei_5[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x05};
uint8_t Shiwei_4[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x04};
uint8_t Shiwei_3[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x03};
uint8_t Shiwei_2[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x02};
uint8_t Shiwei_1[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x01};
uint8_t Shiwei_0[8]={0x5A,0xA5,0x05,0x82,0x00,0x32,0x00,0x00};

uint8_t Gewei_9[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x09};   //计时器个位
uint8_t Gewei_8[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x08};
uint8_t Gewei_7[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x07};
uint8_t Gewei_6[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x06};
uint8_t Gewei_5[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x05};
uint8_t Gewei_4[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x04};
uint8_t Gewei_3[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x03};
uint8_t Gewei_2[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x02};
uint8_t Gewei_1[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x01};
uint8_t Gewei_0[8]={0x5A,0xA5,0x05,0x82,0x00,0x33,0x00,0x00};

uint8_t TxBuffer1[12]={0x5A,0xA5,0x09,0x82,0x00,0x34,0x00,0x01,0x00,0x01,0x00,0x01};	//ABC三相全部合闸 1合闸
uint8_t TxBuffer2[12]={0x5A,0xA5,0x09,0x82,0x00,0x37,0x00,0x01,0x00,0x01,0x00,0x01};	//DEF三相全部合闸
uint8_t TxBuffer3[12]={0x5A,0xA5,0x09,0x82,0x00,0x34,0x00,0x00,0x00,0x00,0x00,0x00};	//ABC三相全部跳闸 0跳闸
uint8_t TxBuffer4[12]={0x5A,0xA5,0x09,0x82,0x00,0x37,0x00,0x00,0x00,0x00,0x00,0x00};	//DEF三相全部跳闸	 

uint8_t TimeT1[8]={0x5A,0xA5,0x05,0x82,0x00,0x12,0x00,0xFA};	//下拉菜单1对应的跳闸电流250mA，0x12为跳闸电流显示变量地址
uint8_t TimeT2[8]={0x5A,0xA5,0x05,0x82,0x00,0x12,0x01,0xF4};	//下拉菜单2对应的跳闸电流500mA，0x01F4=500
uint8_t TimeT3[8]={0x5A,0xA5,0x05,0x82,0x00,0x12,0x03,0xE8};	//下拉菜单3对应的跳闸电流1000mA
uint8_t TimeT4[8]={0x5A,0xA5,0x05,0x82,0x00,0x12,0x05,0xDC};	//下拉菜单4对应的跳闸电流1500mA
uint8_t TimeT5[8]={0x5A,0xA5,0x05,0x82,0x00,0x12,0x07,0xD0};	//下拉菜单5对应的跳闸电流2000mA
uint8_t TimeT6[8]={0x5A,0xA5,0x05,0x82,0x00,0x12,0x09,0xC4};	//下拉菜单6对应的跳闸电流2500mA

uint8_t TimeH1[8]={0x5A,0xA5,0x05,0x82,0x00,0x13,0x00,0xFA};	//下拉菜单1对应的合闸电流250mA 0x13为合闸电流显示变量地址
uint8_t TimeH2[8]={0x5A,0xA5,0x05,0x82,0x00,0x13,0x01,0xF4};	//下拉菜单2对应的合闸电流500mA
uint8_t TimeH3[8]={0x5A,0xA5,0x05,0x82,0x00,0x13,0x03,0xE8};	//下拉菜单3对应的合闸电流1000mA
uint8_t TimeH4[8]={0x5A,0xA5,0x05,0x82,0x00,0x13,0x05,0xDC};	//下拉菜单4对应的合闸电流1500mA
uint8_t TimeH5[8]={0x5A,0xA5,0x05,0x82,0x00,0x13,0x07,0xD0};	//下拉菜单5对应的合闸电流2000mA
uint8_t TimeH6[8]={0x5A,0xA5,0x05,0x82,0x00,0x13,0x09,0xC4};	//下拉菜单6对应的合闸电流2500mA																		//下拉菜单6对应的跳闸电流2500mA

uint8_t Rad1[8]={0x5A,0xA5,0x05,0x82,0x00,0x29,0x00,0x1E};	//30rad	         
uint8_t Rad2[8]={0x5A,0xA5,0x05,0x82,0x00,0x29,0x00,0x2D};	//45rad	       
uint8_t Rad3[8]={0x5A,0xA5,0x05,0x82,0x00,0x29,0x00,0x3C};	//60rad      
uint8_t Rad4[8]={0x5A,0xA5,0x05,0x82,0x00,0x29,0x00,0x5A};	//90rad        
uint8_t Rad5[8]={0x5A,0xA5,0x05,0x82,0x00,0x29,0x00,0xB4};	//180rad      
uint8_t Rad6[8]={0x5A,0xA5,0x05,0x82,0x00,0x29,0x01,0x0E};	//270rad       

uint8_t TMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x10,0x00,0x78}; //最大的跳闸时间 0x78=120ms，0x10为跳闸时间显示变量地址
uint8_t TMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x10,0x00,0x14}; //最小的跳闸时间 0x14=20ms
uint8_t HMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x11,0x02,0x58}; //最大的合闸时间 0x258=600ms，0x11为合闸时间显示变量地址
uint8_t HMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x11,0x00,0x28}; //最小的合闸时间 0x28=40ms

uint8_t Time_Offset_A_TMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x16,0x00,0x14}; //最大跳闸时间自动补偿 20ms
uint8_t Time_Offset_A_TMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x16,0x00,0x00}; //最小跳闸时间自动补偿 0ms
uint8_t Time_Offset_B_TMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x17,0x00,0x14}; //最大跳闸时间自动补偿 20ms
uint8_t Time_Offset_B_TMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x17,0x00,0x00}; //最小跳闸时间自动补偿 0ms
uint8_t Time_Offset_C_TMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x18,0x00,0x14}; //最大跳闸时间自动补偿 20ms
uint8_t Time_Offset_C_TMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x18,0x00,0x00}; //最小跳闸时间自动补偿 0ms
uint8_t Time_Offset_D_TMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x19,0x00,0x14}; //最大跳闸时间自动补偿 20ms
uint8_t Time_Offset_D_TMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x19,0x00,0x00}; //最小跳闸时间自动补偿 0ms
uint8_t Time_Offset_E_TMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x1A,0x00,0x14}; //最大跳闸时间自动补偿 20ms
uint8_t Time_Offset_E_TMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x1A,0x00,0x00}; //最小跳闸时间自动补偿 0ms
uint8_t Time_Offset_F_TMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x1B,0x00,0x14}; //最大跳闸时间自动补偿 20ms
uint8_t Time_Offset_F_TMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x1B,0x00,0x00}; //最小跳闸时间自动补偿 0ms

uint8_t Time_Offset_A_HMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x1C,0x00,0x28}; //最大合闸时间自动补偿 40ms
uint8_t Time_Offset_A_HMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x1C,0x00,0x00}; //最小合闸时间自动补偿 0ms
uint8_t Time_Offset_B_HMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x1D,0x00,0x28}; //最大合闸时间自动补偿 40ms
uint8_t Time_Offset_B_HMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x1D,0x00,0x00}; //最小合闸时间自动补偿 0ms
uint8_t Time_Offset_C_HMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x1E,0x00,0x28}; //最大合闸时间自动补偿 40ms
uint8_t Time_Offset_C_HMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x1E,0x00,0x00}; //最小合闸时间自动补偿 0ms
uint8_t Time_Offset_D_HMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x1F,0x00,0x28}; //最大合闸时间自动补偿 40ms
uint8_t Time_Offset_D_HMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x1F,0x00,0x00}; //最小合闸时间自动补偿 0ms
uint8_t Time_Offset_E_HMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x20,0x00,0x28}; //最大合闸时间自动补偿 40ms
uint8_t Time_Offset_E_HMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x20,0x00,0x00}; //最小合闸时间自动补偿 0ms
uint8_t Time_Offset_F_HMax[8]={0x5A,0xA5,0x05,0x82,0x00,0x21,0x00,0x28}; //最大合闸时间自动补偿 40ms
uint8_t Time_Offset_F_HMin[8]={0x5A,0xA5,0x05,0x82,0x00,0x21,0x00,0x00}; //最小合闸时间自动补偿 0ms

uint8_t Frequency_Max[8]={0x5A,0xA5,0x05,0x82,0x00,0x26,0x00,0x46};	//最大频率设置70，0x27为频率显示变量地址																
uint8_t Frequency_Min[8]={0x5A,0xA5,0x05,0x82,0x00,0x26,0x00,0x1E};	//最大频率设置30
uint8_t Voltage_Max  [8]={0x5A,0xA5,0x05,0x82,0x00,0x27,0x06,0x72};	//最大幅值为1650，0x27为幅值显示变量地址											
uint8_t Voltage_Min  [8]={0x5A,0xA5,0x05,0x82,0x00,0x27,0x00,0x00};	//最小幅值为0												
uint8_t Angle_Max    [8]={0x5A,0xA5,0x05,0x82,0x00,0x28,0x01,0x68};	//最大角度为360，0x28为平移相位显示变量地址														
uint8_t Angle_Min    [8]={0x5A,0xA5,0x05,0x82,0x00,0x28,0x00,0x00};	//最小角度为360

uint8_t key_FALSE[7]={0x5A,0xA5,0x04,0x80,0x03,0x00,0x21}; //密码输入错误切换到失败界面，0x21（33页）
uint8_t key_OK[7]={0x5A,0xA5,0x04,0x80,0x03,0x00,0x12}; //密码输入正确切换到跳合时间补偿界面，0x12（18页）

uint16_t key=0; //收到的密码
uint16_t key_True=2019; //正确的密码
uint16_t Current_T=0;
uint16_t Current_H=0;
uint16_t Rad=0;

u8 Start=0;	//0初始化状态,1自动进入状态，2手动进入状态，3进入查询状态																			                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
u8 USART1_TX_Finish=1;
u8 USART3_TX_Finish=1;
u8 UART4_TX_Finish=1;
u8 flag_mode=0;
u16 fac_ms=0;//ms延时倍乘数

DMA_InitTypeDef DMA_InitStructure;
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
GPIO_TypeDef* Trigger_GPIO_PORT[TRIGGERn] = {TRIGGER_TC_Port, TRIGGER_HA_Port,
                                             TRIGGER_TC_Port, TRIGGER_HB_Port,
                                             TRIGGER_TC_Port, TRIGGER_HC_Port,
                                             TRIGGER_TD_Port, TRIGGER_HD_Port,
											 TRIGGER_TE_Port, TRIGGER_HE_Port,
                                             TRIGGER_TF_Port, TRIGGER_HF_Port};                               
uint16_t Trigger_GPIO_PIN[TRIGGERn] = {TRIGGER_TC_Pin, TRIGGER_HA_Pin,
                                       TRIGGER_TC_Pin, TRIGGER_HB_Pin,
                                       TRIGGER_TC_Pin, TRIGGER_HC_Pin,
                                       TRIGGER_TD_Pin, TRIGGER_HD_Pin, 
                                       TRIGGER_TE_Pin, TRIGGER_HE_Pin,
									   TRIGGER_TF_Pin, TRIGGER_HF_Pin};                         
uint32_t Trigger_GPIO_CLK[TRIGGERn] = {TRIGGER_TC_RCC_APB2Periph, TRIGGER_HA_RCC_APB2Periph,
                                       TRIGGER_TC_RCC_APB2Periph, TRIGGER_HB_RCC_APB2Periph,
                                       TRIGGER_TC_RCC_APB2Periph, TRIGGER_HC_RCC_APB2Periph,
									   TRIGGER_TD_RCC_APB2Periph, TRIGGER_HD_RCC_APB2Periph,
                                       TRIGGER_TE_RCC_APB2Periph, TRIGGER_HE_RCC_APB2Periph,
                                       TRIGGER_TF_RCC_APB2Periph, TRIGGER_HF_RCC_APB2Periph};                            
GPIO_TypeDef* TimeH_GPIO_PORT[TIMEn]={H025_Port,H050_Port,H100_Port,
                                      H150_Port,H200_Port,H250_Port};
GPIO_TypeDef* TimeT_GPIO_PORT[TIMEn]={T025_Port,T050_Port,T100_Port,
                                      T150_Port,T200_Port,T250_Port};
uint16_t TimeH_GPIO_PIN[TIMEn]={H025_Pin, H050_Pin,H100_Pin,
                                H150_Pin, H200_Pin,H250_Pin};
uint16_t TimeT_GPIO_PIN[TIMEn]={T025_Pin, T050_Pin,T100_Pin,
                                T150_Pin, T200_Pin,T250_Pin};
uint32_t TimeH_GPIO_CLK[TIMEn]={H025_RCC_APB2Periph,H050_RCC_APB2Periph,H100_RCC_APB2Periph,
                                H150_RCC_APB2Periph,H200_RCC_APB2Periph,H250_RCC_APB2Periph};
uint32_t TimeT_GPIO_CLK[TIMEn]={T025_RCC_APB2Periph,T050_RCC_APB2Periph,T100_RCC_APB2Periph,
                                T150_RCC_APB2Periph,T200_RCC_APB2Periph,T250_RCC_APB2Periph};						     
GPIO_TypeDef*RELAY_GPIO_PORT[RELAYn]={RELAY_A_Port,RELAY_B_Port,RELAY_C_Port,
                                      RELAY_D_Port,RELAY_E_Port,RELAY_F_Port};
uint16_t RELAY_GPIO_PIN[RELAYn] ={RELAY_A_Pin,RELAY_B_Pin,RELAY_C_Pin,
                                  RELAY_D_Pin,RELAY_E_Pin,RELAY_F_Pin};
uint32_t RELAY_GPIO_CLK[RELAYn]={RELAY_A_RCC_APB2Periph,RELAY_B_RCC_APB2Periph,RELAY_C_RCC_APB2Periph,
                                 RELAY_D_RCC_APB2Periph,RELAY_E_RCC_APB2Periph,RELAY_F_RCC_APB2Periph};
								 
/* Private function prototypes -----------------------------------------------*/
void TimeBase_Configuration(uint8_t Timer,uint8_t Time);
void CT_Operation(uint16_t Num);
void CH_Operation(uint16_t Num);
void RAD_Operation(uint16_t Num);
void Send(uint8_t*TxBuffer,uint8_t NbrOfDataToSend);
void USART_Configuration(void);
void UART4_Configuration(void);
//void USART3_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);																 
void LedGPIO_Configuration(void);
void KeyGPIO_Configuration(void);
void Menu_Handle(uint8_t *Buffer);
void Led(void);
void TIMET_Init(Time_TypeDef Time);
void TIMEH_Init(Time_TypeDef Time);
void RELAY_Init(Relay_TypeDef Relay);
void TRIGGER_Init(Trigger_TypeDef Trigger);
void DMA_Configuration(void);
void DMA2_Configuration(void);
void Send_Series_Data(uint8_t*TxBuffer,uint8_t NbrOfDataToSend);
void CurrentT_Operation(uint8_t Num);
void CurrentT_Handle(uint8_t Num);
void CurrentH_Operation( uint8_t Num);
void CurrentH_Handle(uint8_t Num);
void Rad_Operation( uint8_t Num);
void Rad_Handle(uint8_t Num);
void Status_Init(void);
uint8_t Get_Trigger_Value(void);
void Trigle_Handle(uint8_t Value);
void EXTI_Configuration(void);
void RCC_Configuration(void);
void Send_Series_Time(uint8_t Count);
void Save(uint8_t*TxBuffer_Save,uint8_t NbrOfDataToSend);
void Restore(uint8_t*TxBuffer_Restore,uint8_t NbrOfDataToSend);


void DMA_Configuration(void)
{
  /* DMA clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);//DMA1

  /* DMA1 Channel4 (triggered by USART1 Tx event) Config */
  DMA_DeInit(DMA1_Channel4);  
  DMA_InitStructure.DMA_PeripheralBaseAddr = 0x40013804;
 // DMA_InitStructure.DMA_MemoryBaseAddr = (u32);
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 512;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel4, &DMA_InitStructure);
  
  DMA_ITConfig(DMA1_Channel4, DMA_IT_TC, ENABLE);
  DMA_ITConfig(DMA1_Channel4, DMA_IT_TE, ENABLE);
  /* Enable USART1 DMA TX request */
  USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
  
  DMA_Cmd(DMA1_Channel4, DISABLE);
   
  /* DMA1 Channel5 (triggered by USART1 Rx event) Config */
  DMA_DeInit(DMA1_Channel5);  
  DMA_InitStructure.DMA_PeripheralBaseAddr = 0x40013804;
  DMA_InitStructure.DMA_MemoryBaseAddr = (u32)USART1_DMA_Buf1;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_BufferSize = 512;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel5, &DMA_InitStructure);
  
  DMA_ITConfig(DMA1_Channel5, DMA_IT_TC, ENABLE);
  DMA_ITConfig(DMA1_Channel5, DMA_IT_TE, ENABLE);
  
  /* Enable USART1 DMA RX request */
  USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);
  
  DMA_Cmd(DMA1_Channel5, ENABLE);
  //初始化BUF标志
  Free_Buf_Now=BUF_NO2;
  Buf_Ok=FALSE;  
}

void DMA2_Configuration(void)
{
  /* DMA clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);//DMA2

  /* DMA1 Channel4 (triggered by USART1 Tx event) Config */
  DMA_DeInit(DMA2_Channel5);  
  DMA_InitStructure.DMA_PeripheralBaseAddr = 0x40004C04;
 // DMA_InitStructure.DMA_MemoryBaseAddr = (u32);
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 512;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA2_Channel5, &DMA_InitStructure);
  
  DMA_ITConfig(DMA2_Channel5, DMA_IT_TC, ENABLE);
  DMA_ITConfig(DMA2_Channel5, DMA_IT_TE, ENABLE);
  /* Enable USART1 DMA TX request */
  USART_DMACmd(UART4, USART_DMAReq_Tx, ENABLE);
  
  DMA_Cmd(DMA2_Channel5, DISABLE);
   
  /* DMA2 Channel2 (triggered by USART1 Rx event) Config */
  DMA_DeInit(DMA2_Channel2);  
  DMA_InitStructure.DMA_PeripheralBaseAddr = 0x40004C04;
  DMA_InitStructure.DMA_MemoryBaseAddr = (u32)USART1_DMA_Buf1;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_BufferSize = 512;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA2_Channel2, &DMA_InitStructure);
  
  DMA_ITConfig(DMA2_Channel2, DMA_IT_TC, ENABLE);
  DMA_ITConfig(DMA2_Channel2, DMA_IT_TE, ENABLE);
  
  /* Enable USART1 DMA RX request */
  USART_DMACmd(UART4, USART_DMAReq_Rx, ENABLE);
  
  DMA_Cmd(DMA2_Channel2, ENABLE);

  //初始化BUF标志
  Free_Buf_Now=BUF_NO2;
  Buf_Ok=FALSE;  
}

void RCC_Configuration(void)
{
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2|RCC_APB1Periph_TIM3|RCC_APB1Periph_TIM4|RCC_APB1Periph_TIM5|RCC_APB1Periph_TIM6|RCC_APB1Periph_TIM7, ENABLE);
}

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* 第1步：打开GPIO和USART部件的时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* 第2步：将USART Tx的GPIO配置为推挽复用模式 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;                      //PA9:TXD
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* 第3步：将USART Rx的GPIO配置为浮空输入模式
	由于CPU复位后，GPIO缺省都是浮空输入模式，因此下面这个步骤不是必须的
	但是，我还是建议加上便于阅读，并且防止其它地方修改了这个口线的设置参数
	*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;                    //PA10:RXD
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
/*****************************USART3******************************************/	
//	  	/* 第1步：打开GPIO和USART3部件的时钟 */
//  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
//  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

//  	/* 第2步：将USART Tx的GPIO配置为推挽复用模式 */
//  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  	GPIO_Init(GPIOB, &GPIO_InitStructure);

//  	/* 第3步：将USART Rx的GPIO配置为浮空输入模式
//  	由于CPU复位后，GPIO缺省都是浮空输入模式，因此下面这个步骤不是必须的
//  	但是，我还是建议加上便于阅读，并且防止其它地方修改了这个口线的设置参数
//  	*/
//  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
//  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//  	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	
	/*****************************UART4******************************************/	
	  	/* 第1步：打开GPIO和USART3部件的时钟 */
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);

  	/* 第2步：将USART Tx的GPIO配置为推挽复用模式 */
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;                 //PC10:RXD1
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);

  	/* 第3步：将USART Rx的GPIO配置为浮空输入模式
  	由于CPU复位后，GPIO缺省都是浮空输入模式，因此下面这个步骤不是必须的
  	但是，我还是建议加上便于阅读，并且防止其它地方修改了这个口线的设置参数
  	*/
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;                  //PC11:TXD1
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);		
}

void USART_Configuration(void)
{
	USART_InitTypeDef USART_InitStructure;
  	/* 第4步：配置USART参数
  	- BaudRate = 115200 baud
  	- Word Length = 8 Bits
  	- One Stop Bit
  	- No parity
  	- Hardware flow control disabled (RTS and CTS signals)
  	- Receive and transmit enabled
  	*/
  	USART_InitStructure.USART_BaudRate = 9600;
  	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  	USART_InitStructure.USART_StopBits = USART_StopBits_1;
  	USART_InitStructure.USART_Parity = USART_Parity_No;
  	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  	USART_Init(USART1, &USART_InitStructure);
	
  	/* Enable USART1 DMA Rx Tx request */
  	//USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);
  	//USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
  	//空闲中断
  	USART_ITConfig(USART1, USART_IT_IDLE , ENABLE);
	
	/* 第5步：使能 USART， 配置完毕 */
  	USART_Cmd(USART1, ENABLE);  
	/* CPU的小缺陷：串口配置好，如果直接Send，则第1个字节发送不出去
  	如下语句解决第1个字节无法正确发送出去的问题 */
  	USART_ClearFlag(USART1, USART_FLAG_TC);     /* 清发送外城标志，Transmission Complete flag */
}

//void USART3_Configuration(void)
//{
//	USART_InitTypeDef USART_InitStructure;
//	USART_ClockInitTypeDef USART_ClockInitStructure;
//  	/* 第4步：配置USART参数
//  	- BaudRate = 115200 baud
//  	- Word Length = 8 Bits
//  	- One Stop Bit
//  	- No parity
//  	- Hardware flow control disabled (RTS and CTS signals)
//  	- Receive and transmit enabled
//  	*/
//  	USART_InitStructure.USART_BaudRate = 19200;
//  	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//  	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//  	USART_InitStructure.USART_Parity = USART_Parity_No;
//  	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//  	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	  USART_Init(USART3, &USART_InitStructure);
//	
//		USART_ClockInitStructure.USART_Clock	=	USART_Clock_Disable;
//		USART_ClockInitStructure.USART_CPHA	=	USART_CPHA_2Edge;
//		USART_ClockInitStructure.USART_CPOL	=	USART_CPOL_Low;
//		USART_ClockInitStructure.USART_LastBit	=	USART_LastBit_Disable;
//		USART_ClockInit(USART3,&USART_ClockInitStructure);

//  	/* Enable USART1 DMA Rx Tx request */
//  	//USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);
//  	//USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
//  	//空闲中断
//  	USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);
//	
//	/* 第5步：使能 USART， 配置完毕 */
//  	USART_Cmd(USART3, ENABLE);  
//	/* CPU的小缺陷：串口配置好，如果直接Send，则第1个字节发送不出去
//  	如下语句解决第1个字节无法正确发送出去的问题 */
//  	USART_ClearFlag(USART3, USART_FLAG_TC);     /* 清发送外城标志，Transmission Complete flag */
//}

void UART4_Configuration(void)
{
	USART_InitTypeDef USART_InitStructure;
	USART_ClockInitTypeDef USART_ClockInitStructure;
  	/* 第4步：配置USART参数
  	- BaudRate = 115200 baud
  	- Word Length = 8 Bits
  	- One Stop Bit
  	- No parity
  	- Hardware flow control disabled (RTS and CTS signals)
  	- Receive and transmit enabled
  	*/
  	USART_InitStructure.USART_BaudRate = 9600;
  	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  	USART_InitStructure.USART_StopBits = USART_StopBits_1;
  	USART_InitStructure.USART_Parity = USART_Parity_No;
  	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(UART4, &USART_InitStructure);

	USART_ClockInitStructure.USART_Clock	=	USART_Clock_Disable;
	USART_ClockInitStructure.USART_CPHA	=	USART_CPHA_2Edge;
	USART_ClockInitStructure.USART_CPOL	=	USART_CPOL_Low;
	USART_ClockInitStructure.USART_LastBit	=	USART_LastBit_Disable;
	USART_ClockInit(UART4,&USART_ClockInitStructure);

  	/* Enable USART1 DMA Rx Tx request */
  	//USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);
  	//USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
  	//空闲中断
  	USART_ITConfig(UART4, USART_IT_IDLE, ENABLE);
	
	/* 第5步：使能 USART， 配置完毕 */
  	USART_Cmd(UART4, ENABLE);  
	/* CPU的小缺陷：串口配置好，如果直接Send，则第1个字节发送不出去
  	如下语句解决第1个字节无法正确发送出去的问题 */
  	USART_ClearFlag(UART4, USART_FLAG_TC);     /* 清发送外城标志，Transmission Complete flag */
}

void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  /* Configure one bit for preemption priority */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
  
  /* Enable the USART1 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
//	  /* Enable the USART3 Interrupt */
//  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);

		  /* Enable the USART3 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
  //Enable DMA Channel4 Interrupt 
  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  /*Enable DMA Channel5 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
/************************USART3**************************************/	
//	  //Enable DMA Channel2 Interrupt 
//  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
// 
//  /*Enable DMA Channel3 Interrupt */
//  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel3_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
/******************************************************************/	

/*************************UART4**************************************/	
//Enable DMA Channel2 Interrupt 
  NVIC_InitStructure.NVIC_IRQChannel = DMA2_Channel5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
 
  /*Enable DMA Channel3 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = DMA2_Channel2_IRQn;//原DMA2_Channel3_IRQn
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
/******************************************************************/	

  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);


	  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

	  /* Enable the TIM3 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

	  /* Enable the TIM4 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

	  /* Enable the TIM5 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

	  /* Enable the TIM8 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

	  /* Enable the TIM8 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);
}  


void LedGPIO_Configuration(void)
	{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);						 
		 
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;          //PE7 LED
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}
	
void Led(void)
{
	if (GPIO_ReadOutputDataBit(GPIOE,GPIO_Pin_7))
	GPIO_ResetBits(GPIOE, GPIO_Pin_7);
	else
	GPIO_SetBits(GPIOE, GPIO_Pin_7);

}

void KeyGPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure the GPIO_LED pin */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;          //PE1  LED:本地模式(1) 远程模式(0)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

void TIM5_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE); //时钟使能
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值，定时器周期
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器


	TIM_Cmd(TIM5, ENABLE);  //使能TIMx					 
}

	/**																											 
	* 函数名：void Menu_Handle(uint16_t *Buffer)
	* 描述  ：如果有菜单被按下，根据菜单传来的响应数组进行相应的处理
	* 输入  ：响应数组的头地址
	* 输出  ：无
	*/
 	void Menu_Handle(uint8_t *Buffer)
	{
		uint8_t temp=0;
		uint16_t data=0;
	if((Buffer[0]==0x5A)&&(Buffer[1]==0xA5))
	{
	if(Buffer[2]==0x06)
	{
	switch(Buffer[5])
	{
		
	case 0x01: 
	if(Buffer[8]==1)
	{
		Restore(&StatusBuffer_Restore[0],15);		 //开机命令把字库的内容读入变量空间，这里出错了！！！！
		Delay_ms(200);
		Start=2;		 //	进入手动状态
		Send(&Ts[0],7);							
	} 
	break; 
		
		
	case 0x26:										//频率设置		
		Wave1_Fre=MAKETIME(Buffer[8],Buffer[7]);
		if(Wave1_Fre>70)
		{
          Wave1_Fre=70;  
		  Send_Series_Data(&Frequency_Max[0],8);		
		}
		if(Wave1_Fre<30)
		{
          Wave1_Fre=30;
		  Send_Series_Data(&Frequency_Min[0],8);		
		}	
		  SineWave1_Init();			
	    break;
			
		
	case 0x27:										//幅值设置
		  V=MAKETIME(Buffer[8],Buffer[7]);
		  time_start_flag=1;
		  time_count_ms=0;
		if(V>1650)
		{
		  V=1650;
		  Send_Series_Data(&Voltage_Max[0],8);		
		}
		  SineWave1_Init();	
	      TIM5_Int_Init(49,1439);// Tout= ((49+1)*( 1439+1))/72=1000us=1ms。	
	    break;
		
		
	case 0x28:										 //平移角度设置
		  radian=MAKETIME(Buffer[8],Buffer[7]);
		if(radian>360)
		{
          radian=360;
		  Send_Series_Data(&Angle_Max[0],8);		
		}
	      SineWave1_Init();	
		 break;
		
		
		case 0x29:										//合闸电流下拉菜单设置
			temp=Buffer[8];
			Rad_Operation(temp); 
	    break;
				
	/*A相动作*/
	case 0x34:

	if(TH_2)		//ABC三相操作 （TH_2=1）
	{ 
	if(Buffer[8])  //ABC三相合闸 
	{	
	Send_Series_Data(&TxBuffer1[0],12);
	GPIOD->BSRR =0x0007;//PD0-PD2置1
	Relay_Status[7]=1;	
	Relay_Status[9]=1;
	Relay_Status[11]=1;																		    				  									
	}
	else			 //ABC三相跳闸
	{	 
	if(TH_4)	//ABC三相双跳闸，TH_4=1双跳
	{
	if(TH_3)		//ABC三相双跳闸，DEF三相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);	
		Send_Series_Data(&TxBuffer4[0],12);	
		GPIOD->BRR =0x003F;	//PD0-PD5置0
		Relay_Status[7]=0;	
		Relay_Status[9]=0;
		Relay_Status[11]=0;	
		Relay_Status[13]=0;	
		Relay_Status[15]=0;
		Relay_Status[17]=0;																										  
	}
	else			 //ABC三相双跳闸，DEF单相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);
		Send_Series_Data(&TD[0],8);
		GPIOD->BRR =0x000F;	
		Relay_Status[7]=0;	
		Relay_Status[9]=0;
		Relay_Status[11]=0;	
		Relay_Status[13]=0;										  				  
	}

	}
	else	 	//ABC三相单跳闸
	{
		Send_Series_Data(&TxBuffer3[0],12);
		GPIOD->BRR =0x0007;	
		Relay_Status[7]=0;	
		Relay_Status[9]=0;
		Relay_Status[11]=0;													
	}
	}		
	}
						
	else		//ABC单相A操作  （TH_2=0）
	{	
	if(Buffer[8])  //A单相合闸
	{	
		GPIOD->BSRR=0x0001;    
		Relay_Status[7]=1;				  									
	}
	else	 //A单相跳闸
	{	
	if(TH_4)	 //A单相跳闸，双跳
	{
	if(TH_3)	//A单相跳闸，双跳，DEF三相操作  
	{
		Send_Series_Data(&TxBuffer4[0],12);	
		GPIOD->BRR =0x0039;				  
		Relay_Status[7]=0;	
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;																					  
	}
	else		 //A单相跳闸，双跳，DEF单相操作
	{
		Send_Series_Data(&TD[0],8);
		GPIOD->BRR =0x0009;		
		Relay_Status[7]=0;	
		Relay_Status[13]=0;													  				  
	}
			
	}
	else	 //A单相跳闸，单跳
	{

		GPIOD->BRR=0x0001; 
		Relay_Status[7]=0;	
	} 
	}	   
	}
	break;

	/*B相动作*/
	case 0x35:

	if(TH_2)		 //ABC三相操作
	{
	if(Buffer[8])  //ABC三相合闸
	{		    				  									
		Send_Series_Data(&TxBuffer1[0],12);
		GPIOD->BSRR =0x0007;
		Relay_Status[7]=1;
		Relay_Status[9]=1;
		Relay_Status[11]=1;
	}
	else			 //ABC三相跳闸
	{	
	if(TH_4)		 //ABC三相跳闸，双跳
	{
	if(TH_3)		 //ABC三相跳闸，双跳，DEF三相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);				  
		Send_Series_Data(&TxBuffer4[0],12);				
		GPIOD->BRR =0x003F;	
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;
	}
	else		 //ABC三相跳闸，双跳，DEF单相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);				
		Send_Series_Data(&TE[0],8);
		GPIOD->BRR =0x0017;	
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;
		Relay_Status[15]=0;														  				  
	}

	}
	else		//ABC三相跳闸，单跳
	{
		Send_Series_Data(&TxBuffer3[0],12);
		GPIOD->BRR =0x0007;	
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;									
	}   
	}		
	}
		
	else			 //ABC单相B操作
	{
	if(Buffer[8])  		  //ABC单相标志，B合闸
	{		    				  									
		GPIOD->BSRR =0x0002;
		Relay_Status[9]=1;
	}
	else					 //ABC单相标志，B跳闸
	{	
	if(TH_4)				 //ABC单相标志，B跳闸 双跳
	{
	if(TH_3)				//ABC单相标志，B跳闸 双跳 DEF三相操作
	{
		Send_Series_Data(&TxBuffer4[0],8);
		GPIOD->BRR=0x003A;
		Relay_Status[9]=0;
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;
	}
	else					 //ABC单相标志，B跳闸 双跳 DEF单相操作
	{
		Send_Series_Data(&TE[0],8);
		GPIOD->BRR=0x0012;
		Relay_Status[9]=0;
		Relay_Status[15]=0;													  				  
	}				  								
	} 
	else				//ABC单相标志，B跳闸 单跳
	{
		GPIOD->BRR=0x0002;
		Relay_Status[9]=0;													
	}       
	}	   
	}
	break;
		 
	/*C相动作*/
	case 0x36:
	if(TH_2)				//ABC三相操作
	{
	if(Buffer[8])  	 //ABC三相合闸
	{		    				  									
		Send_Series_Data(&TxBuffer1[0],12);
		GPIOD->BSRR =0x0007;
		Relay_Status[7]=1;
		Relay_Status[9]=1;
		Relay_Status[11]=1;
	}
	else		//ABC三相跳闸
	{	
	if(TH_4)			 //ABC三相跳闸，双跳
	{
	if(TH_3)			//ABC三相跳闸，双跳,DEF三相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);
		Send_Series_Data(&TxBuffer4[0],12);	
		GPIOD->BRR =0x003F;	
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;		
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;																				    
	}
	else			//ABC三相跳闸，双跳,DEF单相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);
		Send_Series_Data(&TF[0],8);
		GPIOD->BRR =0x0027;
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;		
		Relay_Status[17]=0;												  				  
	}				
	}
	else			 //ABC三相跳闸，单跳
	{
		Send_Series_Data(&TxBuffer3[0],12);
		GPIOD->BRR =0x0007;	
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;									
	}        
	}		
	}

	else		 	//ABC单相C操作
	{
		if(Buffer[8])  //ABC单相标志，C合闸
	{		    				  									
		GPIOD->BSRR =0x0004;
		Relay_Status[11]=1;	
	}
	else				//ABC单相跳闸
	{	

	if(TH_4)		 //ABC单相跳闸，双跳
	{
	if(TH_3)		//ABC单相跳闸，双跳，DEF三相操作
	{
		Send_Series_Data(&TxBuffer4[0],12);
		GPIOD->BRR=0x002C;	
		Relay_Status[11]=0;	
		Relay_Status[13]=0;	
		Relay_Status[15]=0;	
		Relay_Status[17]=0;																																		  
	}
	else		 //ABC单相跳闸，双跳，DEF单相操作
	{
		Send_Series_Data(&TF[0],8);							
		GPIOD->BRR=0x0024;	
		Relay_Status[11]=0;
		Relay_Status[17]=0;															 			  				  
	}

	} 
	else		 //ABC单相跳闸，单跳
	{
		GPIOD->BRR=0x0004;
		Relay_Status[11]=0;	
	}   

	}	   
	}
	break;
		 	 
	/*D相动作*/
	case 0x37:
	if(TH_3)			//DEF三相操作
	{
	if(Buffer[8])  //DEF三相操作，合闸
	{		    				  									
		Send_Series_Data(&TxBuffer2[0],12);
		GPIOD->BSRR =0x0038;
		Relay_Status[13]=1;
		Relay_Status[15]=1;
		Relay_Status[17]=1;
	}
	else					 //DEF三相操作，跳闸
	{	
	if(TH_4)				 //DEF三相操作，双跳
	{
	if(TH_2)				//DEF三相操作，双跳，ABC三相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);	
		Send_Series_Data(&TxBuffer4[0],12);
		GPIOD->BRR =0x003F;
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;																							  
	}
	else				 	//DEF三相操作，双跳，ABC单相操作
	{
		Send_Series_Data(&TxBuffer4[0],12);				
		Send_Series_Data(&TA[0],8);
		GPIOD->BRR =0x0039;	
		Relay_Status[7]=0;
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;											  				  
	}				  				
	} 
	else			//DEF三相操作，单跳
	{
		Send_Series_Data(&TxBuffer4[0],12);
		GPIOD->BRR =0x0038;	
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;										
	}       
	}		
	}
		
	else		 //DEF单相D操作
	{
		if(Buffer[8])  	//DEF单相操作，D合闸
	{		    				  									
		GPIOD->BSRR =0x0008;
		Relay_Status[13]=1;
	}
	else			//DEF单相操作，D跳闸
	{	
	if(TH_4)		//DEF单相操作，D跳闸，双跳
	{
	if(TH_2)		//DEF单相操作，D跳闸，双跳，ABC三相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);						
		GPIOD->BRR=0x000F;
		Relay_Status[13]=0;
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;
	}
	else	 //DEF单相操作，D跳闸，双跳，ABC单相操作
	{
		Send_Series_Data(&TA[0],8);
		GPIOD->BRR=0x0009;
		Relay_Status[13]=0;
		Relay_Status[7]=0;														  
	}
				
	}
	else		//DEF单相操作，D跳闸，单跳
	{
		GPIOD->BRR=0x0008;
		Relay_Status[13]=0;													
	}        
	}	   
	}
	break;
		 
	/*E相动作*/
	case 0x38:
	if(TH_3)						  //DEF三相操作
	{
	if(Buffer[8]) //DEF三相操作合闸 
	{		    				  									
		Send_Series_Data(&TxBuffer2[0],12);
		GPIOD->BSRR =0x0038;
		Relay_Status[13]=1;
		Relay_Status[15]=1;
		Relay_Status[17]=1;
	}
	else	//DEF三相操作跳闸
	{	
	if(TH_4)	 //DEF三相操作跳闸，双跳
	{
	if(TH_2)	 //DEF三相操作跳闸，双跳，ABC三相操作
	{
		Send_Series_Data(&TxBuffer4[0],12);
		Send_Series_Data(&TxBuffer3[0],12);
		GPIOD->BRR =0x003F;
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;
	}
	else	//DEF三相操作跳闸，双跳，ABC单相操作
	{
		Send_Series_Data(&TxBuffer4[0],12);
		Send_Series_Data(&TB[0],8);
		GPIOD->BRR =0x003A;	
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;
		Relay_Status[9]=0;																  
	}								
	}
	else		//DEF三相操作跳闸，单跳
	{
		Send_Series_Data(&TxBuffer4[0],12);
		GPIOD->BRR =0x0038;		
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;								  				
	}    

	}		
	}
		
	else	//DEF单相E操作
	{
		if(Buffer[8]) //DEF单相操作 E相合闸 
	{		    				  									
		GPIOD->BSRR =0x0010;
		Relay_Status[15]=1;
	}
	else			 //DEF单相操作，E相跳闸
	{	
	if(TH_4)		 //DEF单相操作，E相跳闸，双跳
	{
	if(TH_2)		//DEF单相操作，E相跳闸，双跳，ABC三相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);
		GPIOD->BRR =0x0017;	
		Relay_Status[15]=0;		
		Relay_Status[7]=0;	
		Relay_Status[9]=0;	
		Relay_Status[11]=0;																																  
	}
	else			 //DEF单相操作，E相跳闸，双跳，ABC单相操作
	{
		Send_Series_Data(&TB[0],8);
		GPIOD->BRR =0x0012;	
		Relay_Status[15]=0;	
		Relay_Status[9]=0;															  				  
	}				
	} 
	else	 //DEF单相操作，E相跳闸，单跳
	{
		GPIOD->BRR=0x0010;	
		Relay_Status[15]=0;													
	}       

	}	   
	}
	break;   
		 
	/*F相动作*/
	case 0x39:
	if(TH_3)			  //DEF三相操作
	{
		if(Buffer[8])  	 //DEF三相操作，合闸
	{		    				  									
		Send_Series_Data(&TxBuffer2[0],12);
		GPIOD->BSRR =0x0038;
		Relay_Status[13]=1;
		Relay_Status[15]=1;
		Relay_Status[17]=1;
	}
	else			//DEF三相操作，跳闸
	{	
	if(TH_4)	 	//DEF三相操作，跳闸，双跳
	{
	if(TH_2)	 //DEF三相操作，跳闸，双跳，ABC三相操作
	{
		Send_Series_Data(&TxBuffer3[0],12);	
		Send_Series_Data(&TxBuffer4[0],12);
		GPIOD->BRR =0x003F;	
		Relay_Status[7]=0;
		Relay_Status[9]=0;
		Relay_Status[11]=0;
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;																			  
	}
	else		 //DEF三相操作，跳闸，双跳，ABC单相操作
	{
		Send_Series_Data(&TxBuffer4[0],12);
		Send_Series_Data(&TC[0],8);
		GPIOD->BRR =0x003C;
		Relay_Status[11]=0;
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;												  				  
	}				  				  				
	} 
	else //DEF三相操作，跳闸，单跳
	{
		Send_Series_Data(&TxBuffer4[0],12);
		GPIOD->BRR =0x0038;	
		Relay_Status[13]=0;
		Relay_Status[15]=0;
		Relay_Status[17]=0;									
	}       
	}		
	}
		
	else	//DEF单相F操作
	{
		if(Buffer[8]) //DEF单相合闸 
	{		    				  									
		GPIOD->BSRR =0x0020;
		Relay_Status[17]=1;
	}
	else		 //DEF单相跳闸
	{	
	if(TH_4)		//DEF单相跳闸，双跳
	{
	if(TH_2)		//DEF单相跳闸，双跳，ABC双跳
	{
		Send_Series_Data(&TxBuffer3[0],12);
		GPIOD->BRR=0x0027;
		Relay_Status[17]=0;	
		Relay_Status[7]=0;	
		Relay_Status[9]=0;	
		Relay_Status[11]=0;																																						  
	}
	else		 	//DEF单相跳闸，双跳，ABC单跳
	{
		Send_Series_Data(&TC[0],8);					
		GPIOD->BRR=0x0024;	
		Relay_Status[17]=0;	
		Relay_Status[11]=0;															 			  
	}				
	}
	else		 //DEF单相跳闸，单跳
	{
	GPIOD->BRR=0x0020;
					Relay_Status[17]=0;					
	}        
	}	   
	}
	break;	

	case 0x16:
		  data=MAKETIME(Buffer[8],Buffer[7]);
          TimeT_Correct[0]=data;
		  if(data>20)
		{
          TimeT_Correct[0]=20;         //跳闸时间补偿A相 
		  Send_Series_Data(&Time_Offset_A_TMax[0],8);		
		}				 				
	break; 
		
	case 0x17:
		  data=MAKETIME(Buffer[8],Buffer[7]);
          TimeT_Correct[1]=data;
		if(data>20)
		{
          TimeT_Correct[1]=20;        //跳闸时间补偿B相
		  Send_Series_Data(&Time_Offset_B_TMax[0],8);		
		}				
	break; 
		
	case 0x18:
	      data=MAKETIME(Buffer[8],Buffer[7]);
          TimeT_Correct[2]=data;
		if(data>20)
		{
          TimeT_Correct[2]=20;        //跳闸时间补偿C相
		  Send_Series_Data(&Time_Offset_C_TMax[0],8);		
		}				
	break; 
		
	case 0x19:
	      data=MAKETIME(Buffer[8],Buffer[7]);
          TimeT_Correct[3]=data;
		if(data>20)
		{
          TimeT_Correct[3]=20;        //跳闸时间补偿D相
		  Send_Series_Data(&Time_Offset_D_TMax[0],8);		
		}					
	break; 
		
	case 0x1A:
	      data=MAKETIME(Buffer[8],Buffer[7]);
          TimeT_Correct[4]=data;
		if(data>20)
		{
          TimeT_Correct[4]=20;        //跳闸时间补偿E相
		  Send_Series_Data(&Time_Offset_E_TMax[0],8);		
		}				
	break; 
		
	case 0x1B:
	      data=MAKETIME(Buffer[8],Buffer[7]);
          TimeT_Correct[5]=data;
		if(data>20)
		{
          TimeT_Correct[5]=20;        //跳闸时间补偿F相
		  Send_Series_Data(&Time_Offset_F_TMax[0],8);		
		}				
	break; 
		
	case 0x1C:
		  data=MAKETIME(Buffer[8],Buffer[7]);
          TimeH_Correct[0]=data;
		if(data>40)
		{
          TimeH_Correct[0]=40;        //合闸时间补偿A相
		  Send_Series_Data(&Time_Offset_A_HMax[0],8);		
		}				

	break; 
		
	case 0x1D:
	      data=MAKETIME(Buffer[8],Buffer[7]);
          TimeH_Correct[1]=data;
		if(data>40)
		{
          TimeH_Correct[1]=40;        //合闸时间补偿B相
		  Send_Series_Data(&Time_Offset_B_HMax[0],8);		
		}				
	break; 
		
	case 0x1E:
		  data=MAKETIME(Buffer[8],Buffer[7]);
          TimeH_Correct[2]=data;
		if(data>40)
		{
          TimeH_Correct[2]=40;        //合闸时间补偿C相
		  Send_Series_Data(&Time_Offset_C_HMax[0],8);		
		}				
	break; 
		
	case 0x1F:
	      data=MAKETIME(Buffer[8],Buffer[7]);
          TimeH_Correct[3]=data;
		if(data>40)
		{
          TimeH_Correct[3]=40;        //合闸时间补偿D相
		  Send_Series_Data(&Time_Offset_D_HMax[0],8);		
		}				
	break; 
		
	case 0x20:
	      data=MAKETIME(Buffer[8],Buffer[7]);
          TimeH_Correct[4]=data;
		if(data>40)
		{
          TimeH_Correct[4]=40;        //合闸时间补偿E相
		  Send_Series_Data(&Time_Offset_E_HMax[0],8);		
		}				
	break; 
		
	case 0x21:
	      data=MAKETIME(Buffer[8],Buffer[7]);
          TimeH_Correct[5]=data;
		if(data>40)
		{
          TimeH_Correct[5]=40;        //合闸时间补偿F相
		  Send_Series_Data(&Time_Offset_F_HMax[0],8);		
		}				
	break;  
	
	case 0x10:										//跳闸时间设置
          data=MAKETIME(Buffer[8],Buffer[7]);
          Time_T[0]=data;
          Time_T[1]=data;
          Time_T[2]=data;
          Time_T[3]=data;
          Time_T[4]=data;
          Time_T[5]=data;
		if(data>120)
		{
          Time_T[0]=120;
          Time_T[1]=120;
          Time_T[2]=120;
          Time_T[3]=120;
          Time_T[4]=120;
          Time_T[5]=120;
		  Send_Series_Data(&TMax[0],8);		
		}				
		if(data<20)
		{
          Time_T[0]=20;
          Time_T[1]=20;
          Time_T[2]=20;
          Time_T[3]=20;
          Time_T[4]=20;
          Time_T[5]=20;
		  Send_Series_Data(&TMin[0],8);	
		}
	    break;
					
	case 0x11:										//合闸时间设置
		  data=MAKETIME(Buffer[8],Buffer[7]);
          Time_H[0]=data;
          Time_H[1]=data;
          Time_H[2]=data;
          Time_H[3]=data;
          Time_H[4]=data;
          Time_H[5]=data;
		if(data>600)
		{
          Time_H[0]=600;
          Time_H[1]=600;
          Time_H[2]=600;
          Time_H[3]=600;
          Time_H[4]=600;
          Time_H[5]=600;
		  Send_Series_Data(&HMax[0],8);			
		}
		if(data<40)
		{
          Time_H[0]=40;
          Time_H[1]=40;
          Time_H[2]=40;
          Time_H[3]=40;
          Time_H[4]=40;
          Time_H[5]=40;
		  Send_Series_Data(&HMin[0],8);					
		}  
	    break;
	
	case 0x14:										 //跳闸电流下拉菜单设置
		    temp=Buffer[8]; 
			CurrentT_Operation(temp); 
	    break;

	case 0x15:										//合闸电流下拉菜单设置
			temp=Buffer[8];
			CurrentH_Operation(temp); 
	    break;

			
	case 0x22:									//ABC单相或者三相
        if(Buffer[8])
	    {
		    TH_2=1;            //ABC三相
	    }
		else
	    {
	 	    TH_2=0;           //ABC单相
	    }

	    break;
			
	case 0x23:							 //DEF单相或者三相
        if(Buffer[8])
	    {
		    TH_3=1;                  //DEF三相
	    }
	    else
	    {
	 	    TH_3=0;                 //DEF单相
	    }
	    break;
					
	case 0x24:						 //是否双跳
        if(Buffer[8])
	    {
		    TH_4=1;              //双跳
	    }
	    else
	    {
	 	    TH_4=0;              //单跳
	    }
	    break;
					
	case 0x25:				 //断路器失灵
        if(Buffer[8])
	    {

		  	TH_5=1;						//进入断路器失灵状态
		  	Send_Series_Data(&Tx_Change[0],7);		 //进入断路器失灵界面
			Machine_Status[7]=1; //断路器失灵状态							 
	    }
	    break;
					
	case 0x3A:		 //从断路器失灵状态返回，是不经过外部触发延时20秒的方式
        if(Buffer[8])
	    {									
		    TH_5=0;					//断路器正常状态
		    Send_Series_Data(&Tx_Cancle[0],8);		 //断路器失灵按钮还原
	        Machine_Status[7]=0;  //断路器正常状态
	    }
	    break;			
			
	case 0x3c:		 //登录界面，输入密码
	        key=MAKETIME(Buffer[8],Buffer[7]);							//跳闸时间 
      if(key==key_True)
			{
           Send_Series_Data(&key_OK[0],7); //切换到跳合时间补偿界面	
		   key=0;
			}
			else
			{
				Send_Series_Data(&key_FALSE[0],7); //切换到密码错误界面		
			    key=0;			
			}
	    break;
	    default: break;
	  }
	 }
		
	 
   if(Buffer[2]==0x03)										//配合那个赵老师的上位机软件加的语句
	 {
	 
	 	Send_Series_Data(&Relay_Status[0],18);
	 	Send_Series_Data(&Machine_Status[0],8);	 
	 }
	 if(Buffer[2]==0x30)									//开机上电以后收到的恢复现场（加了校正值）
	 {
			
        if(Buffer[44])									 //ABC单相或者三相
	     {
		    TH_2=1;//ABC三相
	     }
	  	 else
	     {
	 	    TH_2=0;//ABC单相
	     }

        if(Buffer[46])							 //DEF单相或者三相
	    {
		    TH_3=1;  //DEF三相
	    }
	    else
	    {
	 	    TH_3=0;  //DEF单相
	    }

        if(Buffer[48])							//双跳或者单跳

	    {
		    TH_4=1;      //双跳
	    }
	    else
	    {
	 	    TH_4=0;       //单跳
	    }
        if(Buffer[50])							 //断路器失灵
				{
			  TH_5=1;					//断路器失灵状态
		    Send_Series_Data(&Tx_Change[0],7); //切换到断路器失灵界面
				}
					Flag=1;
          TimeT_Correct[0]=Buffer[20];
          TimeT_Correct[1]=Buffer[22];
          TimeT_Correct[2]=Buffer[24];
          TimeT_Correct[3]=Buffer[26];
          TimeT_Correct[4]=Buffer[28];
          TimeT_Correct[5]=Buffer[30];	
          TimeH_Correct[0]=Buffer[32];
          TimeH_Correct[1]=Buffer[34];
          TimeH_Correct[2]=Buffer[36];
          TimeH_Correct[3]=Buffer[38];
          TimeH_Correct[4]=Buffer[40];
          TimeH_Correct[5]=Buffer[42];																								 
		  data=MAKETIME(Buffer[8],Buffer[7]);							//跳闸时间
		  Time_T[0]=data;
		  Time_T[1]=data;
		  Time_T[2]=data;
		  Time_T[3]=data;
		  Time_T[4]=data;
		  Time_T[5]=data;
		  data=MAKETIME(Buffer[10],Buffer[9]);					 //合闸时间
		  Time_H[0]=data;
		  Time_H[1]=data;
		  Time_H[2]=data;
		  Time_H[3]=data;
		  Time_H[4]=data;
		  Time_H[5]=data;
		  Current_T=MAKETIME(Buffer[12],Buffer[11]);	  //跳闸电流
		  CT_Operation(Current_T);
		  Current_H=MAKETIME(Buffer[14],Buffer[13]);	  //合闸电流
		  CH_Operation(Current_H);
		  Rad=MAKETIME(Buffer[18],Buffer[17]);	  //合闸电流
		  RAD_Operation(Rad);			  	 	 
	 }
  }       
}
	
/**
  * @brief 初始化模拟跳合闸的LED端口
  * @param LED端口
  * @retval无
  */
void TIMET_Init(Time_TypeDef Time)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = TimeT_GPIO_PIN[Time];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(TimeT_GPIO_PORT[Time], &GPIO_InitStructure);
}

void TIMEH_Init(Time_TypeDef Time)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = TimeH_GPIO_PIN[Time];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(TimeH_GPIO_PORT[Time], &GPIO_InitStructure);
}

/**
  * @brief 初始化继电器的端口
  * @param 继电器
  * @retval无
  */
void RELAY_Init(Relay_TypeDef Relay)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = RELAY_GPIO_PIN[Relay];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(RELAY_GPIO_PORT[Relay], &GPIO_InitStructure);
}

/**
  * @brief 初始化外部触发的端口
  * @param 外部触发
  * @retval无
  */
void TRIGGER_Init(Trigger_TypeDef Trigger)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = Trigger_GPIO_PIN[Trigger];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(Trigger_GPIO_PORT[Trigger], &GPIO_InitStructure);
}

void EXTI_Configuration(void)
{
  EXTI_InitTypeDef  EXTI_InitStructure;


  EXTI_ClearITPendingBit (EXTI_Line0);
  EXTI_ClearITPendingBit (EXTI_Line1);
  EXTI_ClearITPendingBit (EXTI_Line2);
  EXTI_ClearITPendingBit (EXTI_Line3);
  EXTI_ClearITPendingBit (EXTI_Line4);
  EXTI_ClearITPendingBit (EXTI_Line5);
  EXTI_ClearITPendingBit (EXTI_Line8);
  EXTI_ClearITPendingBit (EXTI_Line9);
  EXTI_ClearITPendingBit (EXTI_Line10);
  EXTI_ClearITPendingBit (EXTI_Line11);
  EXTI_ClearITPendingBit (EXTI_Line12);
  EXTI_ClearITPendingBit (EXTI_Line13);


  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource5);//TA-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource4);//TB-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);//TC-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2);//HA-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);//HB-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);//HC-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource13);//TD-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource12);//TE-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource11);//TF-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource10);//HD-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource9);//HE-CPU
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource8);//HF-CPU

//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource10);

  EXTI_InitStructure.EXTI_Line=	EXTI_Line0|EXTI_Line1|EXTI_Line2|EXTI_Line3|EXTI_Line4|EXTI_Line5|EXTI_Line8|EXTI_Line9|EXTI_Line10|EXTI_Line11|EXTI_Line12|EXTI_Line13;
  EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd=ENABLE;

  EXTI_Init(&EXTI_InitStructure);
}

void SineWave_DMA_Config(void)
{                  
//    DMA_InitTypeDef            DMA_InitStructure;
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);//开启DMA2时钟
//     
//    DMA_StructInit( &DMA_InitStructure);        //DMA结构体初始化
//    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;//从寄存器读数据
//    DMA_InitStructure.DMA_BufferSize = 256;//寄存器大小
//    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设地址不递增
//    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; //内存地址递增
//    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//宽度为半字
//    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//宽度为半字
//    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;//优先级非常高
//    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;//关闭内存到内存模式
//    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//循环发送模式
//    DMA_InitStructure.DMA_PeripheralBaseAddr = DAC_DHR12R1;//外设地址为DAC通道1的地址
//    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)DualSine12bit;//波形数据表内存地址
//    DMA_Init(DMA2_Channel3, &DMA_InitStructure);//初始化
//    DMA_Cmd(DMA2_Channel3, ENABLE); //使能DMA通道3  　　            

	DMA_InitTypeDef DMA_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);//初始化DMA2的时钟

	DMA_DeInit(DMA2_Channel3); //将DMA配置成默认值
	DMA_InitStructure.DMA_PeripheralBaseAddr = DAC_DHR12R1;//指定DMA2通道3的目标地址为DAC1_DHR12R1
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&DualSine12bit;//指定DMA的源地址为数组Sine12bit
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;//外设作为数据传输的目的地
	DMA_InitStructure.DMA_BufferSize = sizeof(DualSine12bit)/2;//DMA缓冲区大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设机地址存器不变
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; //内存地址寄存器递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//外设数据宽度为半字
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//内存数据宽度为半字
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//工作在循环缓存模式，数据传输数为0时，自动恢复配置初值
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;//非常高优先级
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;//通道未被设置成内存到内存模式，与循环模式相对
	DMA_Init(DMA2_Channel3, &DMA_InitStructure);//初始化DMA

	DMA_DeInit(DMA2_Channel4);
	DMA_InitStructure.DMA_PeripheralBaseAddr = DAC_DHR12R2;//指定DMA2通道3的目标地址为DAC2_DHR12R2
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	DMA_Init(DMA2_Channel4, &DMA_InitStructure);

	DMA_Cmd(DMA2_Channel3, ENABLE); //使能DMA的channel3
	DMA_Cmd(DMA2_Channel4, ENABLE); //使能DMA的channel4
}

void SineWave1_Init(void)
{
	u16 f1=(u16)(72000000/sizeof(DualSine12bit)*2/Wave1_Fre);//计算频率72000000
	SineWave_Data( DL ,DualSine12bit);     //生成输出正弦波的波形表
    SineWave_GPIO_Config();             //初始化io
    SineWave_TIM_Config(f1);            //初始化定时器
    SineWave_DAC_Config();              //配置DAC
	SineWave_DMA_Config();	
	TIM_Cmd(TIM2, ENABLE); //打开TIM2 
    TIM_Cmd(TIM6, ENABLE); //打开TIM6
	
}

/**
  * 函数名：void Send_Series_Data(uint8_t*TxBuffer,uint8_t NbrOfDataToSend)
  * 描述  ：主控制器发送若干个字节给迪文屏
  * 输入  ：发送的字节数
  * 输出  ：无
  */
void Send_Series_Data(uint8_t*TxBuffer,uint8_t NbrOfDataToSend)
{
			while(USART1_TX_Finish==0)
			{
			 ;
			}
			USART1_TX_Finish=0; 
			
			DMA_Cmd(DMA1_Channel4, DISABLE); //改变datasize前先要禁止通道工作
			DMA1_Channel4->CNDTR=NbrOfDataToSend; //DMA1传输数据量
			DMA1_Channel4->CMAR=(u32)TxBuffer;
			DMA_Cmd(DMA1_Channel4, ENABLE);
			
				while(UART4_TX_Finish==0)
			{
			 ;
			}	
			UART4_TX_Finish=0;
			DMA_Cmd(DMA2_Channel5, DISABLE); //改变datasize前先要禁止通道工作
			DMA2_Channel5->CNDTR=NbrOfDataToSend; //DMA1传输数据量
			DMA2_Channel5->CMAR=(u32)TxBuffer;
			DMA_Cmd(DMA2_Channel5, ENABLE);
}

void Send_Series_Qianwei(uint8_t Qianwei)
{
  switch(Qianwei)
  {
    case 9:  Send_Series_Data(&Qianwei_9[0],8); 
	break;
    case 8:  Send_Series_Data(&Qianwei_8[0],8); 
	break;
    case 7:  Send_Series_Data(&Qianwei_7[0],8); 
	break;
    case 6:  Send_Series_Data(&Qianwei_6[0],8); 
	break;
    case 5:  Send_Series_Data(&Qianwei_5[0],8); 
	break;
    case 4:  Send_Series_Data(&Qianwei_4[0],8); 
	break;
    case 3:  Send_Series_Data(&Qianwei_3[0],8); 
	break;
    case 2:  Send_Series_Data(&Qianwei_2[0],8); 
	break;
	case 1:  Send_Series_Data(&Qianwei_1[0],8); 
	break;
	case 0:  Send_Series_Data(&Qianwei_0[0],8); 
	break;
	default: break;
  }
}


void Send_Series_Baiwei(uint8_t Baiwei)
{
  switch(Baiwei)
  {
    case 9:  Send_Series_Data(&Baiwei_9[0],8); 
	break;
    case 8:  Send_Series_Data(&Baiwei_8[0],8); 
	break;
    case 7:  Send_Series_Data(&Baiwei_7[0],8); 
	break;
    case 6:  Send_Series_Data(&Baiwei_6[0],8); 
	break;
    case 5:  Send_Series_Data(&Baiwei_5[0],8); 
	break;
    case 4:  Send_Series_Data(&Baiwei_4[0],8); 
	break;
    case 3:  Send_Series_Data(&Baiwei_3[0],8); 
	break;
    case 2:  Send_Series_Data(&Baiwei_2[0],8); 
	break;
	case 1:  Send_Series_Data(&Baiwei_1[0],8); 
	break;
	case 0:  Send_Series_Data(&Baiwei_0[0],8); 
	break;
	default: break;
  }
}


void Send_Series_Shiwei(uint8_t Shiwei)
{
  switch(Shiwei)
  {
    case 9:  Send_Series_Data(&Shiwei_9[0],8); 
	break;
    case 8:  Send_Series_Data(&Shiwei_8[0],8); 
	break;
    case 7:  Send_Series_Data(&Shiwei_7[0],8); 
	break;
    case 6:  Send_Series_Data(&Shiwei_6[0],8); 
	break;
    case 5:  Send_Series_Data(&Shiwei_5[0],8); 
	break;
    case 4:  Send_Series_Data(&Shiwei_4[0],8); 
	break;
    case 3:  Send_Series_Data(&Shiwei_3[0],8); 
	break;
    case 2:  Send_Series_Data(&Shiwei_2[0],8); 
	break;
	case 1:  Send_Series_Data(&Shiwei_1[0],8); 
	break;
	case 0:  Send_Series_Data(&Shiwei_0[0],8); 
	break;
	default: break;
  }
}


void Send_Series_Gewei(uint8_t Gewei)
{
  switch(Gewei)
  {
    case 9:  Send_Series_Data(&Gewei_9[0],8); 
	break;
    case 8:  Send_Series_Data(&Gewei_8[0],8); 
	break;
    case 7:  Send_Series_Data(&Gewei_7[0],8); 
	break;
    case 6:  Send_Series_Data(&Gewei_6[0],8); 
	break;
    case 5:  Send_Series_Data(&Gewei_5[0],8); 
	break;
    case 4:  Send_Series_Data(&Gewei_4[0],8); 
	break;
    case 3:  Send_Series_Data(&Gewei_3[0],8); 
	break;
    case 2:  Send_Series_Data(&Gewei_2[0],8); 
	break;
	case 1:  Send_Series_Data(&Gewei_1[0],8); 
	break;
	case 0:  Send_Series_Data(&Gewei_0[0],8); 
	break;
	default: break;
  }
}

void Send_Series_Time(uint8_t Count)
{
  switch(Count)
  {
    case 20:  Send_Series_Data(&Count_20[0],8); 
	break;
    case 19:  Send_Series_Data(&Count_19[0],8); 
	break;
    case 18:  Send_Series_Data(&Count_18[0],8); 
	break;
    case 17:  Send_Series_Data(&Count_17[0],8); 
	break;
    case 16:  Send_Series_Data(&Count_16[0],8); 
	break;
    case 15:  Send_Series_Data(&Count_15[0],8); 
	break;
    case 14:  Send_Series_Data(&Count_14[0],8); 
	break;
    case 13:  Send_Series_Data(&Count_13[0],8);
	break;
    case 12:  Send_Series_Data(&Count_12[0],8); 
	break;
    case 11:  Send_Series_Data(&Count_11[0],8); 
	break;
    case 10:  Send_Series_Data(&Count_10[0],8);
	break;
    case 9:  Send_Series_Data(&Count_9[0],8); 
	break;
    case 8:  Send_Series_Data(&Count_8[0],8); 
	break;
    case 7:  Send_Series_Data(&Count_7[0],8); 
	break;
    case 6:  Send_Series_Data(&Count_6[0],8); 
	break;
    case 5:  Send_Series_Data(&Count_5[0],8); 
	break;
    case 4:  Send_Series_Data(&Count_4[0],8); 
	break;
    case 3:  Send_Series_Data(&Count_3[0],8); 
	break;
    case 2:  Send_Series_Data(&Count_2[0],8); 
	break;
	case 1:  Send_Series_Data(&Count_1[0],8); 
	break;
	default: break;
  }
}

/**
  * 函数名：void Time_Operation()
  * 描述  ：对按下菜单响应数组进行处理后，根据处理结果进行相应的操作
  * 输入  ：无
  * 输出  ：无
  */
void CurrentT_Operation(uint8_t Num)
{
 switch(Num)
 {
   case 0:	break;
   case 1:	Send_Series_Data(&TimeT1[0],8); CurrentT_Handle(1); Current_T=250; break;
   case	2:	Send_Series_Data(&TimeT2[0],8); CurrentT_Handle(2); Current_T=500; break;
   case	3:	Send_Series_Data(&TimeT3[0],8);	CurrentT_Handle(3); Current_T=1000; break;
   case	4: 	Send_Series_Data(&TimeT4[0],8); CurrentT_Handle(4); Current_T=1500; break;
   case	5:	Send_Series_Data(&TimeT5[0],8); CurrentT_Handle(5); Current_T=2000; break;
   case	6:  Send_Series_Data(&TimeT6[0],8); CurrentT_Handle(6); Current_T=2500; break; 
   default: break; 
 }
}

void CurrentT_Handle(uint8_t Num)
{
   uint8_t i=0;
   Num=Num-1;
   for(i=0;i<TIMEn;i++)
    {
	  if((i==Num))
	  {
	    
        GPIO_SetBits(TimeT_GPIO_PORT[Num],TimeT_GPIO_PIN[Num]);
	
	  }
	  else
	  {
	   	GPIO_ResetBits(TimeT_GPIO_PORT[i],TimeT_GPIO_PIN[i]);
	  }
    }
}

void CurrentH_Operation( uint8_t Num)
{
 switch(Num)
 {
   case 0:	break;
   case 1:	Send_Series_Data(&TimeH1[0],8); CurrentH_Handle(1); Current_H=250; break;
   case	2:	Send_Series_Data(&TimeH2[0],8);	CurrentH_Handle(2); Current_H=500; break;
   case	3:	Send_Series_Data(&TimeH3[0],8);	CurrentH_Handle(3); Current_H=1000; break;
   case	4: 	Send_Series_Data(&TimeH4[0],8); CurrentH_Handle(4); Current_H=1500; break;
   case	5:	Send_Series_Data(&TimeH5[0],8); CurrentH_Handle(5); Current_H=2000; break;
   case	6:  Send_Series_Data(&TimeH6[0],8); CurrentH_Handle(6); Current_H=2500; break; 
   default: break; 
 }
}

 void CurrentH_Handle(uint8_t Num)
{
   uint8_t i=0;
   Num=Num-1;
   for(i=0;i<TIMEn;i++)
    {
	  if((i==Num))
	  {
        GPIO_SetBits(TimeH_GPIO_PORT[Num],TimeH_GPIO_PIN[Num]);
		
	  }
	  else
	  {
	   	GPIO_ResetBits(TimeH_GPIO_PORT[i],TimeH_GPIO_PIN[i]);
	  }
    }
}

void Rad_Operation( uint8_t Num)
{
 switch(Num)
 {
   case 0:	break;
   case 1:	Send_Series_Data(&Rad1[0],8); Rad_Handle(1); Rad=30; break;
   case	2:	Send_Series_Data(&Rad2[0],8); Rad_Handle(2); Rad=45; break;
   case	3:	Send_Series_Data(&Rad3[0],8); Rad_Handle(3); Rad=60; break;
   case	4: 	Send_Series_Data(&Rad4[0],8); Rad_Handle(4); Rad=90; break;
   case	5:	Send_Series_Data(&Rad5[0],8); Rad_Handle(5); Rad=180; break;
   case	6:  Send_Series_Data(&Rad6[0],8); Rad_Handle(6); Rad=270; break; 
   default: break; 
 }
}

 void Rad_Handle(uint8_t Num)
{
   uint8_t i=0;
   Num=Num-1;
   for(i=0;i<TIMEn;i++)
    {
	  if((i==Num))
	  {
        GPIO_SetBits(TimeH_GPIO_PORT[Num],TimeH_GPIO_PIN[Num]);
		
	  }
	  else
	  {
	   	GPIO_ResetBits(TimeH_GPIO_PORT[i],TimeH_GPIO_PIN[i]);
	  }
    }
}

void CT_Operation(uint16_t Num)
{
 switch(Num)
 {
   case 250:	CurrentT_Handle(1);  break;
   case 500:    CurrentT_Handle(2);  break;
   case	1000:	CurrentT_Handle(3);  break;
   case	1500:	CurrentT_Handle(4);  break;
   case	2000: 	CurrentT_Handle(5);  break;
   case	2500:	CurrentT_Handle(6);  break;
   default: break; 
 }
}

void CH_Operation(uint16_t Num)
{
 switch(Num)
 {
   case 250:	CurrentH_Handle(1);  break;
   case 500:    CurrentH_Handle(2);  break;
   case	1000:	CurrentH_Handle(3);  break;
   case	1500:	CurrentH_Handle(4);  break;
   case	2000: 	CurrentH_Handle(5);  break;
   case	2500:	CurrentH_Handle(6);  break;
   default: break; 
 }
}

void RAD_Operation(uint16_t Num)
{
 switch(Num)
 {
   case 30:	    Rad_Handle(1);  break;
   case 45:     Rad_Handle(2);  break;
   case	60:	    Rad_Handle(3);  break;
   case	90:	    Rad_Handle(4);  break;
   case	180: 	Rad_Handle(5);  break;
   case	270:	Rad_Handle(6);  break;
   default: break; 
 }
}

void Save(uint8_t*TxBuffer_Save,uint8_t NbrOfDataToSend)
{
  Send_Series_Data(TxBuffer_Save,NbrOfDataToSend);
}

void Restore(uint8_t*TxBuffer_Restore,uint8_t NbrOfDataToSend)
{
 Send_Series_Data(TxBuffer_Restore,NbrOfDataToSend);
}

void Send(uint8_t*TxBuffer,uint8_t NbrOfDataToSend)
{
  uint8_t i=0;  
  while(i<NbrOfDataToSend)
  {    
	 USART_SendData(USART1,TxBuffer[i]);
	 while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)!=SET);
	 USART_SendData(UART4,TxBuffer[i]);
	 while(USART_GetFlagStatus(UART4,USART_FLAG_TXE)!=SET);
	 i++;
  }
}

void TimeBase_Configuration(uint8_t Timer,uint8_t Time)
{
  switch(Timer)
	{
   case 2:	  
	        TIM_DeInit(TIM2);
          if(Time>=32)
	        {
	          Time=32;	
	        }
          /* Time base configuration */
          TIM_TimeBaseStructure.TIM_Period = 2000*Time;
          TIM_TimeBaseStructure.TIM_Prescaler = 0;
          TIM_TimeBaseStructure.TIM_ClockDivision = 0;
          TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

          TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

          /* Prescaler configuration */
          TIM_PrescalerConfig(TIM2,0x8C9F, TIM_PSCReloadMode_Immediate);
          /* TIM IT enable */
          TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
          /* TIM2 enable counter */
          TIM_Cmd(TIM2, ENABLE);  break;
   
   case 3:    
	        TIM_DeInit(TIM3);
          if(Time>=32)
	        {
	          Time=32;	
	        }
          /* Time base configuration */
          TIM_TimeBaseStructure.TIM_Period = 2000*Time;
          TIM_TimeBaseStructure.TIM_Prescaler = 0;
          TIM_TimeBaseStructure.TIM_ClockDivision = 0;
          TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

          TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

          /* Prescaler configuration */
          TIM_PrescalerConfig(TIM3,0x8C9F, TIM_PSCReloadMode_Immediate);
          /* TIM IT enable */
          TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
          /* TIM2 enable counter */
          TIM_Cmd(TIM3, ENABLE);  break;
   
   case	4:	
	        TIM_DeInit(TIM4);
          if(Time>=32)
	        {
	          Time=32;	
	        }
          /* Time base configuration */
          TIM_TimeBaseStructure.TIM_Period = 2000*Time;
          TIM_TimeBaseStructure.TIM_Prescaler = 0;
          TIM_TimeBaseStructure.TIM_ClockDivision = 0;
          TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

          TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

          /* Prescaler configuration */
          TIM_PrescalerConfig(TIM4,0x8C9F, TIM_PSCReloadMode_Immediate);
          /* TIM IT enable */
          TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
          /* TIM2 enable counter */
          TIM_Cmd(TIM4, ENABLE);  break;
   
   case	5:	
	        TIM_DeInit(TIM5);
          if(Time>=32)
	        {
	          Time=32;	
	        }
          /* Time base configuration */
          TIM_TimeBaseStructure.TIM_Period = 2000*Time;
          TIM_TimeBaseStructure.TIM_Prescaler = 0;
          TIM_TimeBaseStructure.TIM_ClockDivision = 0;
          TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

          TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

          /* Prescaler configuration */
          TIM_PrescalerConfig(TIM5,0x8C9F, TIM_PSCReloadMode_Immediate);
          /* TIM IT enable */
          TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
          /* TIM2 enable counter */
          TIM_Cmd(TIM5, ENABLE);  break;
  
   case	6:	
	        TIM_DeInit(TIM6);
          if(Time>=32)
	        {
	          Time=32;	
	        }
          /* Time base configuration */
          TIM_TimeBaseStructure.TIM_Period = 2000*Time;
          TIM_TimeBaseStructure.TIM_Prescaler = 0;
          TIM_TimeBaseStructure.TIM_ClockDivision = 0;
          TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

          TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

          /* Prescaler configuration */
          TIM_PrescalerConfig(TIM6,0x8C9F, TIM_PSCReloadMode_Immediate);
          /* TIM IT enable */
          TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
          /* TIM2 enable counter */
          TIM_Cmd(TIM6, ENABLE);  break;
   
   case	7:	
	        TIM_DeInit(TIM7);
          if(Time>=32)
	        {
	          Time=32;	
	        }
          /* Time base configuration */
          TIM_TimeBaseStructure.TIM_Period = 2000*Time;
          TIM_TimeBaseStructure.TIM_Prescaler = 0;
          TIM_TimeBaseStructure.TIM_ClockDivision = 0;
          TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

          TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);

          /* Prescaler configuration */
          TIM_PrescalerConfig(TIM7,0x8C9F, TIM_PSCReloadMode_Immediate);
          /* TIM IT enable */
          TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
          /* TIM2 enable counter */
          TIM_Cmd(TIM7, ENABLE);  break;
   default: break;		
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif

#endif
