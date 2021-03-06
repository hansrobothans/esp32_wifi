/*
* @file         bsp_wifi.h 
* @brief        ESP32操作wifi
* @details      用户应用程序的入口文件,用户所有要实现的功能逻辑均是从该文件开始或者处理
* @author       hans 
* @par Copyright (c):  
*               qq:304872739
*/
#ifndef BSP_WIFI_H
#define BSP_WIFI_H "BSP_WIFI_H"
/* =============
头文件包含
 =============*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_event_loop.h"
#include "esp_event.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "esp_wpa2.h"
#include "tcpip_adapter.h"
#include "esp_smartconfig.h"



#include "lwip/err.h"
#include "lwip/sys.h"


//下方以及替换到menuconfig中，所以注释掉

// #define SMARTCONFIG true	//是否开启smart配网

//修改此处可以修改热点ap的帐号密码以及最大连接数（不可以超过4）无需多修改其它参数
// #define CONFIG_BSP_ESP_AP_WIFI_SSID      	"HANS_ESP32"
// #define CONFIG_BSP_ESP_AP_WIFI_PASSWORD  	"yong0511"
// #define CONFIG_BSP_ESP_AP_MAX_STA_CONN   	3
//修改此处可以修改要连接的热点的帐号密码。无需多修改其它参数
// #define CONFIG_BSP_ESP_STA_WIFI_SSID      	"HANS"
// #define CONFIG_BSP_ESP_STA_WIFI_PASSWORD  	"yong0511"
// #define CONFIG_BSP_ESP_STA_MAXIMUM_RETRY  	5

//日志消息
#define TAG_WIFI 					"wifi"
// FreeRTOS event group to signal when we are connected to wifi
#define WIFI_CONNECTED_BIT BIT0					//wifi建立成功信号量
#define ESPTOUCH_DONE_BIT BIT1					//smart配网成功
extern EventGroupHandle_t bsp_wifi_event_group;		//wifi建立成功信号量句柄

// 创建热点
void bsp_wifi_init_softap(void);
// 连接热点
void bsp_wifi_init_station(void);
// 根据menuconfig选择sta或者ap模式
void bsp_wifi_init( void );

#endif//SP_WIFI_H