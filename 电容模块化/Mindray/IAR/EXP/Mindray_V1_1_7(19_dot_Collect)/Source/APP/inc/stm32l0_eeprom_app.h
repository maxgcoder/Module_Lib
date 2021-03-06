/****************************************************************************************************************************************************************
** 版权:          2017-2027,深圳市信为科技发展有限公司
** 文件名:        stm32l0_eeprom_app.h
** 作者:          庄明群
** 版本:          V1.0.0
** 日期:          2017-05-03
** 描述:          从STM32L072的EEPROM中读取系统内部参数
** 功能:          系统参数读取与处理
*****************************************************************************************************************************************************************
** 修改者:        No
** 版本:          No
** 修改内容:      No
** 日期:          No
****************************************************************************************************************************************************************/

#ifndef __STM32L0_EEPROM_APP_H
#define __STM32L0_EEPROM_APP_H

#include "stm32l0_eeprom.h"
#include "TypeConvert.h"

#define RUN_ADDR_BASE                     0x00                                  //系统参数初始化标志
#define DEVICE_ADDR                       (RUN_ADDR_BASE + 0x01)                //设备地址
#define BAUDRATE                          (DEVICE_ADDR   + 0x01)                //波特率
#define PARITY                            (BAUDRATE      + 0x01)                //奇偶校验
#define FILTER                            (PARITY        + 0x01)                //滤波系数
#define AUTO_UPLOAD                       (FILTER        + 0x01)                //自动上传周期
#define COMPENSATE                        (AUTO_UPLOAD   + 0x01)                //补偿使能
#define FREEZE                            (COMPENSATE    + 0x01)                //是否冻结设备
#define OUTPUTMODE                        (FREEZE        + 0x01)                //输出方式

#define USER_DEFAULT_LEN                  (OUTPUTMODE    + 0x01)                //默认用户数据长度

#define LIQUIDTYPE                        (OUTPUTMODE    + 0x01)                //介质（麻药类型）    
#define HEIGHTRANGE                       (LIQUIDTYPE    + 0x01)                //量程

#define CAP1_0                           (HEIGHTRANGE   + 0x02)            //零点电容0    
#define CAP1_1                           (CAP1_0   + 0x04)                //零点电容1  
#define CAP1_2                           (CAP1_1   + 0x04)                //零点电容2  
#define CAP1_3                           (CAP1_2   + 0x04)                //零点电容3  
#define CAP1_4                           (CAP1_3   + 0x04)                //零点电容4  
#define CAP1_5                           (CAP1_4   + 0x04)                //零点电容5  
#define CAP1_6                           (CAP1_5   + 0x04)                //零点电容6  
#define CAP1_7                           (CAP1_6   + 0x04)                //零点电容7  
#define CAP1_8                           (CAP1_7   + 0x04)                //零点电容8  
#define CAP1_9                           (CAP1_8   + 0x04)                //零点电容9  
#define CAP1_10                          (CAP1_9   + 0x04)                //零点电容10 
#define CAP1_11                          (CAP1_10  + 0x04)                //零点电容11  
#define CAP1_12                          (CAP1_11  + 0x04)                //零点电容12 
#define CAP1_13                          (CAP1_12  + 0x04)                //零点电容13
#define CAP1_14                          (CAP1_13  + 0x04)                //零点电容14 
#define CAP1_15                          (CAP1_14  + 0x04)                //零点电容15  
#define CAP1_16                          (CAP1_15  + 0x04)                //零点电容16 
#define CAP1_17                          (CAP1_16  + 0x04)                //零点电容17  
#define CAP1_18                          (CAP1_17  + 0x04)                //零点电容18 


#define CAPMIN1                          (CAP1_18 + 0x04)                      //  -0 离开水面到零点电容
#define CAPLOW1                          (CAPMIN1 + 0x04)                      //满量程到零点电容
#define CAPHIGH1                         (CAPLOW1)                             //满量程到零点电容
#define CAPMAX1                          (CAPLOW1 + 0x04)                      //满量程电容1

#define CAPMIN2                          (CAPMAX1 + 0x04)                       //-0 离开水面到零点电容
#define CAPLOW2                          (CAPMIN2 + 0x04)                       //满量程到零点电容
#define CAPHIGH2                         (CAPLOW2)                            //满量程到零点电容
#define CAPMAX2                          (CAPLOW2 + 0x04)                       //满量程电容2

#define CAPMIN3                          (CAPMAX2 + 0x04)                       //  -0 离开水面到零点电容
#define CAPLOW3                          (CAPMIN3 + 0x04)                        //满量程到零点电容
#define CAPHIGH3                         (CAPLOW3 )                             //满量程到零点电容
#define CAPMAX3                          (CAPLOW3 + 0x04)                        //满量程电容3

#define CAPMIN4                          (CAPMAX3 + 0x04)                        //  -0 离开水面到零点电容
#define CAPLOW4                          (CAPMIN4 + 0x04)                        //满量程到零点电容
#define CAPHIGH4                         (CAPLOW4)                                //满量程到零点电容
#define CAPMAX4                          (CAPLOW4 + 0x04)                          //满量程电容4

#define CAPMIN5                          (CAPMAX4 + 0x04)                         //  -0 离开水面到零点电容
#define CAPLOW5                          (CAPMIN5 + 0x04)                         //满量程到零点电容
#define CAPHIGH5                         (CAPLOW5)                                 //满量程到零点电容
#define CAPMAX5                          (CAPLOW5 + 0x04)                           //满量程电容5

#define ULRIPLEUP                        (CAPMAX5 + 0x04)                           //换方向灵敏度
#define ULRIPLEDE                        (ULRIPLEUP + 0x04) 

#define FILTERING                        (ULRIPLEDE  + 0x04)                     //滤波等级
#define OPTIMIZ                        (FILTERING  + 0x04)                        //顶端优(0X55开启)

#define CAPADMIN                          (OPTIMIZ     + 0x04)                //电容零点AD值
#define CAPADLOW                          (CAPADMIN      + 0x02)                //电容下刻度AD值
#define CAPADHIH                          (CAPADLOW      + 0x02)                //电容上刻度AD值
#define CAPADMAX                          (CAPADHIH      + 0x02)                //电容满量程AD值
#define CAPDAMIN                          (CAPADMAX      + 0x02)                //电容零点DA值
#define CAPDALOW                          (CAPDAMIN      + 0x02)                //电容下刻度DA值
#define CAPDAHIH                          (CAPDALOW      + 0x02)                //电容上刻度DA值
#define CAPDAMAX                          (CAPDAHIH      + 0x02)                //电容满量程DA值
#define TEMPDAMIN                         (CAPDAMAX      + 0x02)                //温度零点DA值
#define TEMPDAMAX                         (TEMPDAMIN     + 0x02)                //温度满量程DA值
#define CORRECT_K                         (TEMPDAMAX     + 0x02)                //电容修正系数K
#define CORRECT_B                         (CORRECT_K     + 0x02)                //电容修正系数B
#define TEMPER_K1                         (CORRECT_B     + 0x02)                //温度1修正系数K1
#define TEMPER_B1                         (TEMPER_K1     + 0x02)                //温度1修正系数B1
#define CAPLOWHEIGHT1                     (TEMPER_B1     + 0x02)                //下刻度标定高度1
#define CAPHIGHHEIGHT1                    (CAPLOWHEIGHT1 + 0x02)                //上刻度标定高度1
#define CAPLOWHEIGHT2                     (CAPHIGHHEIGHT1 + 0x02)                //下刻度标定高度2
#define CAPHIGHHEIGHT2                    (CAPLOWHEIGHT2 + 0x02)                //上刻度标定高度2
#define CAPLOWHEIGHT3                     (CAPHIGHHEIGHT2 + 0x02)                //下刻度标定高度3
#define CAPHIGHHEIGHT3                    (CAPLOWHEIGHT3 + 0x02)                //上刻度标定高度3
#define CAPLOWHEIGHT4                     (CAPHIGHHEIGHT3 + 0x02)                //下刻度标定高度4
#define CAPHIGHHEIGHT4                    (CAPLOWHEIGHT4 + 0x02)                //上刻度标定高度4
#define CAPLOWHEIGHT5                     (CAPHIGHHEIGHT4 + 0x02)                //下刻度标定高度5
#define CAPHIGHHEIGHT5                    (CAPLOWHEIGHT5 + 0x02)                //上刻度标定高度5
#define CAP_EMPTY                         (CAPHIGHHEIGHT5 + 0x02)                //空电容              

#define RESET_CNT                          (CAP_EMPTY     + 0x04)                //满值报错复位次数

#define PRO_DEFAULT_LEN                   (RESET_CNT - RUN_ADDR_BASE + 0x01)    //系统参数长度 58 bytes

#define SYSTEM_PARAM_BAK1                 (RUN_ADDR_BASE     + PRO_DEFAULT_LEN + 0x04)           //系统参数备份1                       ///偏移400. 
#define SYSTEM_PARAM_BAK2                 (SYSTEM_PARAM_BAK1 + PRO_DEFAULT_LEN + 0x04)           //系统参数备份2

#define ORGANIZATION                      (SYSTEM_PARAM_BAK2 + PRO_DEFAULT_LEN + 0x04)                   //组织机构代码
#define PRODUCTION                        (ORGANIZATION  + 0x30)                //产品代码
#define HARDWAREVER                       (PRODUCTION    + 0x30)                //硬件版本
#define SOFTWAREVER                       (HARDWAREVER   + 0x30)                //软件版本
#define DEVICENUM                         (SOFTWAREVER   + 0x20)                //设备ID
#define CUSTOMER                          (DEVICENUM     + 0x30)                //客户代码



extern UserParaTypeDef UserParam;                                              //用户参数
extern UsartParaTypeDef UsartParam;                                            //串口Usart参数
extern RunVarParaTypeDef RunVarParam;                                          //系统运行参数
extern ProductParaTypeDef ProductParam;                                        //产品参数
extern FLASH_ProcessTypeDef ProcFlash;                                         //Flash处理结构体
extern uint8_t Cur_Param[PRO_DEFAULT_LEN];                                     //系统参数
extern const uint8_t SensorSoftVersion[8];                                    //软件版本

//****************************************************************************************************************************************************************
// 名称               :SwitchCurFilter()
// 创建日期           :2017-05-10
// 作者               :庄明群
// 功能               :切换滤波水平函数
// 输入参数           :filtfactor(滤波系数)
// 输出参数           :无
// 返回结果           :无
// 注意和说明         :滤波水平分9级，数字从低到高对应滤波深度从低到高
// 修改内容           :
//****************************************************************************************************************************************************************

void SwitchCurFilter(uint8_t filtfactor);


//****************************************************************************************************************************************************************
// 名称               :Eeprom_Write3T_MultiBytes()
// 创建日期           :2017-05-03
// 作者               :庄明群
// 功能               :向STM32L072xx内部EEPROM指定位置写多个字节且备份
// 输入参数           :EepAddr(写起始地址)，pWrbuf(固定数据内存),Wrlen(写数据长度)
// 输出参数           :无
// 返回结果           :0(写入成功)，1(写入失败)
// 注意和说明         :写参数前请打开EEPROM写参数使能；地址不能越界
// 修改内容           :
//****************************************************************************************************************************************************************

uint8_t Eeprom_Write3T_MultiBytes(uint16_t EepAddr, uint8_t const *pWrbuf, uint16_t Wrlen);

//****************************************************************************************************************************************************************
// 名称               :Eeprom_SystemParam_Check()
// 创建日期           :2017-05-03
// 作者               :庄明群
// 功能               :EEPROM系统参数检查
// 输入参数           :无
// 输出参数           :无
// 返回结果           :无
// 注意和说明         :写参数前请打开EEPROM写参数使能；地址不能越界
// 修改内容           :
//****************************************************************************************************************************************************************

void Eeprom_SystemParam_Check(void);

//****************************************************************************************************************************************************************
// 名称               :Read_Device_Param()
// 创建日期           :2017-05-10
// 作者               :庄明群
// 功能               :读取设备参数
// 输入参数           :无
// 输出参数           :无
// 返回结果           :无
// 注意和说明         :
// 修改内容           :
//****************************************************************************************************************************************************************

void Read_Device_Param(void);

#endif
