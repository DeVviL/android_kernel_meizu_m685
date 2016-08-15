/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    charging.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines bmt internal charger hw setting function.
 *
 * Author:
 * -------
 *  Oscar Liu
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * Revision:   1.0
 * Modtime:   11 Aug 2005 10:28:16
 * Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/hal/peripheral/inc/bmt_chr_setting.h-arc
 *
 * 05 15 2015 wy.chuang
 * [ALPS01990538] [MP Feature Patch Back]MT6312 driver & MT6328 init setting & charging setting
 * .
 *
 * 03 04 2015 wy.chuang
 * [ALPS01921641] [L1_merge] for PMIC and charging
 * .
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CHARGING_H
#define CHARGING_H

#ifndef CONFIG_ARCH_MT8173
#include <mach/mt_charging.h>
#endif

/* ============================================================ */
/* define */
/* ============================================================ */
/*****************************************************************************
 *  Log
 ****************************************************************************/
#define BAT_LOG_CRTI 1
#define BAT_LOG_FULL 2
#define BAT_LOG_DEBG 3

#define battery_xlog_printk(num, fmt, args...) \
do {\
	if (Enable_BATDRV_LOG >= (int)num) \
		pr_debug(fmt, ##args); \
} while (0)

#define battery_log(num, fmt, args...) \
do { \
	if (Enable_BATDRV_LOG >= (int)num) \
		switch (num) {\
		case BAT_LOG_CRTI:\
			pr_err(fmt, ##args); \
			break; \
			/*fall-through*/\
		default: \
			pr_debug(fmt, ##args); \
			break; \
		} \
} while (0)


/* ============================================================ */
/* ENUM */
/* ============================================================ */
typedef enum {
	CHARGING_CMD_INIT,
	CHARGING_CMD_DUMP_REGISTER,
	CHARGING_CMD_ENABLE,
	CHARGING_CMD_ENABLE_MIAN,
	CHARGING_CMD_SET_CV_VOLTAGE,
	CHARGING_CMD_SET_MAIN_CHARGER_CURRENT,
	CHARGING_CMD_SET_CHARGER_CURRENT,
	CHARGING_CMD_SET_INPUT_CURRENT,
	CHARGING_CMD_SET_MAIN_INPUT_CURRENT,
	CHARGING_CMD_GET_CHARGING_STATUS,
	CHARGING_CMD_RESET_WATCH_DOG_TIMER,
	CHARGING_CMD_GET_CHARGER_DET_STATUS,
	CHARGING_CMD_GET_CHARGER_TYPE,
	CHARGING_CMD_GET_PLATFORM_BOOT_MODE,
	CHARGING_CMD_SET_TA_CURRENT_PATTERN,
	CHARGING_CMD_SET_ADC_START,
	CHARGING_CMD_SET_ADC_STOP,
	CHARGING_CMD_MT_USB_CONNECT,
	CHARGING_CMD_INPUT_CURRENT_OPTIMITER,
	CHARGING_CMD_PUMPX_UP,
	CHARGING_CMD_RESET_VCHR,
	CHARGING_CMD_GET_BATTERYTEMP,
	CHARGING_CMD_GET_BATTERYVOL,
	CHARGING_CMD_GET_BATTERYCURR,
	CHARGING_CMD_GET_BATTERYCURR_NOW,
	CHARGING_CMD_GET_BATTERYSOC,
	CHARGING_CMD_CHECK_BATTERYCV,
	CHARGING_CMD_GET_USB_MODE,
	CHARGING_CMD_SET_VINDPM,
	CHARGING_CMD_SET_VBUS_OVP_EN,
	CHARGING_CMD_SET_HV_THRESHOLD,
	CHARGING_CMD_GET_HV_STATUS,
	CHARGING_CMD_NUMBER
} CHARGING_CTRL_CMD;


typedef enum {
	CHARGER_UNKNOWN = 0,
	STANDARD_HOST,		/* USB : 450mA */
	CHARGING_HOST,
	NONSTANDARD_CHARGER,	/* AC : 450mA~1A */
	STANDARD_CHARGER,	/* AC : ~1A */
	APPLE_2_1A_CHARGER,	/* 2.1A apple charger */
	APPLE_1_0A_CHARGER,	/* 1A apple charger */
	APPLE_0_5A_CHARGER,	/* 0.5A apple charger */
	WIRELESS_CHARGER,
} CHARGER_TYPE;


/* Enum of Voltage List */
typedef enum {
	BATTERY_VOLT_00_000000_V = 0,
	BATTERY_VOLT_00_100000_V = 100000,
	BATTERY_VOLT_00_200000_V = 200000,
	BATTERY_VOLT_00_300000_V = 300000,
	BATTERY_VOLT_00_400000_V = 400000,
	BATTERY_VOLT_00_500000_V = 500000,
	BATTERY_VOLT_00_600000_V = 600000,
	BATTERY_VOLT_00_700000_V = 700000,
	BATTERY_VOLT_00_725000_V = 725000,
	BATTERY_VOLT_00_750000_V = 750000,
	BATTERY_VOLT_00_775000_V = 775000,
	BATTERY_VOLT_00_800000_V = 800000,
	BATTERY_VOLT_00_825000_V = 825000,
	BATTERY_VOLT_00_850000_V = 850000,
	BATTERY_VOLT_00_875000_V = 875000,
	BATTERY_VOLT_00_900000_V = 900000,
	BATTERY_VOLT_00_925000_V = 925000,
	BATTERY_VOLT_00_950000_V = 950000,
	BATTERY_VOLT_00_975000_V = 975000,
	BATTERY_VOLT_01_000000_V = 1000000,
	BATTERY_VOLT_01_025000_V = 1025000,
	BATTERY_VOLT_01_050000_V = 1050000,
	BATTERY_VOLT_01_075000_V = 1075000,
	BATTERY_VOLT_01_100000_V = 1100000,
	BATTERY_VOLT_01_125000_V = 1125000,
	BATTERY_VOLT_01_150000_V = 1150000,
	BATTERY_VOLT_01_175000_V = 1175000,
	BATTERY_VOLT_01_200000_V = 1200000,
	BATTERY_VOLT_01_225000_V = 1225000,
	BATTERY_VOLT_01_250000_V = 1250000,
	BATTERY_VOLT_01_275000_V = 1275000,
	BATTERY_VOLT_01_300000_V = 1300000,
	BATTERY_VOLT_01_325000_V = 1325000,
	BATTERY_VOLT_01_350000_V = 1350000,
	BATTERY_VOLT_01_375000_V = 1375000,
	BATTERY_VOLT_01_400000_V = 1400000,
	BATTERY_VOLT_01_425000_V = 1425000,
	BATTERY_VOLT_01_450000_V = 1450000,
	BATTERY_VOLT_01_475000_V = 1475000,
	BATTERY_VOLT_01_500000_V = 1500000,
	BATTERY_VOLT_01_520000_V = 1520000,
	BATTERY_VOLT_01_525000_V = 1525000,
	BATTERY_VOLT_01_540000_V = 1540000,
	BATTERY_VOLT_01_550000_V = 1550000,
	BATTERY_VOLT_01_560000_V = 1560000,
	BATTERY_VOLT_01_575000_V = 1575000,
	BATTERY_VOLT_01_580000_V = 1580000,
	BATTERY_VOLT_01_600000_V = 1600000,
	BATTERY_VOLT_01_620000_V = 1620000,
	BATTERY_VOLT_01_625000_V = 1625000,
	BATTERY_VOLT_01_640000_V = 1640000,
	BATTERY_VOLT_01_650000_V = 1650000,
	BATTERY_VOLT_01_660000_V = 1660000,
	BATTERY_VOLT_01_675000_V = 1675000,
	BATTERY_VOLT_01_680000_V = 1680000,
	BATTERY_VOLT_01_700000_V = 1700000,
	BATTERY_VOLT_01_720000_V = 1720000,
	BATTERY_VOLT_01_725000_V = 1725000,
	BATTERY_VOLT_01_740000_V = 1740000,
	BATTERY_VOLT_01_750000_V = 1750000,
	BATTERY_VOLT_01_760000_V = 1760000,
	BATTERY_VOLT_01_775000_V = 1775000,
	BATTERY_VOLT_01_780000_V = 1780000,
	BATTERY_VOLT_01_800000_V = 1800000,
	BATTERY_VOLT_01_820000_V = 1820000,
	BATTERY_VOLT_01_825000_V = 1825000,
	BATTERY_VOLT_01_840000_V = 1840000,
	BATTERY_VOLT_01_850000_V = 1850000,
	BATTERY_VOLT_01_860000_V = 1860000,
	BATTERY_VOLT_01_875000_V = 1875000,
	BATTERY_VOLT_01_880000_V = 1880000,
	BATTERY_VOLT_01_900000_V = 1900000,
	BATTERY_VOLT_01_920000_V = 1920000,
	BATTERY_VOLT_01_925000_V = 1925000,
	BATTERY_VOLT_01_940000_V = 1940000,
	BATTERY_VOLT_01_950000_V = 1950000,
	BATTERY_VOLT_01_960000_V = 1960000,
	BATTERY_VOLT_01_975000_V = 1975000,
	BATTERY_VOLT_01_980000_V = 1980000,
	BATTERY_VOLT_02_000000_V = 2000000,
	BATTERY_VOLT_02_020000_V = 2020000,
	BATTERY_VOLT_02_040000_V = 2040000,
	BATTERY_VOLT_02_050000_V = 2050000,
	BATTERY_VOLT_02_060000_V = 2060000,
	BATTERY_VOLT_02_080000_V = 2080000,
	BATTERY_VOLT_02_100000_V = 2100000,
	BATTERY_VOLT_02_120000_V = 2120000,
	BATTERY_VOLT_02_125000_V = 2125000,
	BATTERY_VOLT_02_140000_V = 2140000,
	BATTERY_VOLT_02_200000_V = 2200000,
	BATTERY_VOLT_02_275000_V = 2275000,
	BATTERY_VOLT_02_300000_V = 2300000,
	BATTERY_VOLT_02_350000_V = 2350000,
	BATTERY_VOLT_02_425000_V = 2425000,
	BATTERY_VOLT_02_400000_V = 2400000,
	BATTERY_VOLT_02_500000_V = 2500000,
	BATTERY_VOLT_02_575000_V = 2575000,
	BATTERY_VOLT_02_600000_V = 2600000,
	BATTERY_VOLT_02_650000_V = 2650000,
	BATTERY_VOLT_02_700000_V = 2700000,
	BATTERY_VOLT_02_725000_V = 2725000,
	BATTERY_VOLT_02_750000_V = 2750000,
	BATTERY_VOLT_02_800000_V = 2800000,
	BATTERY_VOLT_02_850000_V = 2850000,
	BATTERY_VOLT_02_875000_V = 2875000,
	BATTERY_VOLT_02_900000_V = 2900000,
	BATTERY_VOLT_02_950000_V = 2950000,
	BATTERY_VOLT_03_000000_V = 3000000,
	BATTERY_VOLT_03_025000_V = 3025000,
	BATTERY_VOLT_03_100000_V = 3100000,
	BATTERY_VOLT_03_175000_V = 3175000,
	BATTERY_VOLT_03_200000_V = 3200000,
	BATTERY_VOLT_03_250000_V = 3250000,
	BATTERY_VOLT_03_275000_V = 3275000,
	BATTERY_VOLT_03_300000_V = 3300000,
	BATTERY_VOLT_03_325000_V = 3325000,
	BATTERY_VOLT_03_350000_V = 3350000,
	BATTERY_VOLT_03_400000_V = 3400000,
	BATTERY_VOLT_03_450000_V = 3450000,
	BATTERY_VOLT_03_500000_V = 3500000,
	BATTERY_VOLT_03_520000_V = 3520000,
	BATTERY_VOLT_03_540000_V = 3540000,
	BATTERY_VOLT_03_550000_V = 3550000,
	BATTERY_VOLT_03_560000_V = 3560000,
	BATTERY_VOLT_03_580000_V = 3580000,
	BATTERY_VOLT_03_600000_V = 3600000,
	BATTERY_VOLT_03_620000_V = 3620000,
	BATTERY_VOLT_03_640000_V = 3640000,
	BATTERY_VOLT_03_650000_V = 3650000,
	BATTERY_VOLT_03_660000_V = 3660000,
	BATTERY_VOLT_03_680000_V = 3680000,
	BATTERY_VOLT_03_700000_V = 3700000,
	BATTERY_VOLT_03_720000_V = 3720000,
	BATTERY_VOLT_03_740000_V = 3740000,
	BATTERY_VOLT_03_750000_V = 3750000,
	BATTERY_VOLT_03_760000_V = 3760000,
	BATTERY_VOLT_03_775000_V = 3775000,
	BATTERY_VOLT_03_780000_V = 3780000,
	BATTERY_VOLT_03_800000_V = 3800000,
	BATTERY_VOLT_03_820000_V = 3820000,
	BATTERY_VOLT_03_825000_V = 3825000,
	BATTERY_VOLT_03_840000_V = 3840000,
	BATTERY_VOLT_03_850000_V = 3850000,
	BATTERY_VOLT_03_860000_V = 3860000,
	BATTERY_VOLT_03_880000_V = 3880000,
	BATTERY_VOLT_03_900000_V = 3900000,
	BATTERY_VOLT_03_920000_V = 3920000,
	BATTERY_VOLT_03_940000_V = 3940000,
	BATTERY_VOLT_03_950000_V = 3950000,
	BATTERY_VOLT_03_960000_V = 3960000,
	BATTERY_VOLT_03_975000_V = 3975000,
	BATTERY_VOLT_03_980000_V = 3980000,
	BATTERY_VOLT_04_000000_V = 4000000,
	BATTERY_VOLT_04_012500_V = 4012500,
	BATTERY_VOLT_04_020000_V = 4020000,
	BATTERY_VOLT_04_025000_V = 4025000,
	BATTERY_VOLT_04_037500_V = 4037500,
	BATTERY_VOLT_04_040000_V = 4040000,
	BATTERY_VOLT_04_050000_V = 4050000,
	BATTERY_VOLT_04_060000_V = 4060000,
	BATTERY_VOLT_04_062500_V = 4062500,
	BATTERY_VOLT_04_067500_V = 4067500,
	BATTERY_VOLT_04_075000_V = 4075000,
	BATTERY_VOLT_04_080000_V = 4080000,
	BATTERY_VOLT_04_087500_V = 4087500,
		#ifdef MEIZU_M80
	BATTERY_VOLT_04_096000_V = 4096000,
	#endif
	BATTERY_VOLT_04_100000_V = 4100000,
	BATTERY_VOLT_04_112500_V = 4112500,
	BATTERY_VOLT_04_115000_V = 4115000,
	BATTERY_VOLT_04_116000_V = 4116000,
	BATTERY_VOLT_04_120000_V = 4120000,
	BATTERY_VOLT_04_125000_V = 4125000,
	BATTERY_VOLT_04_137500_V = 4137500,
	BATTERY_VOLT_04_140000_V = 4140000,
	BATTERY_VOLT_04_150000_V = 4150000,
	BATTERY_VOLT_04_160000_V = 4160000,
	BATTERY_VOLT_04_162500_V = 4162500,
	BATTERY_VOLT_04_175000_V = 4175000,
	BATTERY_VOLT_04_180000_V = 4180000,
	BATTERY_VOLT_04_187500_V = 4187500,
	BATTERY_VOLT_04_200000_V = 4200000,
	BATTERY_VOLT_04_212500_V = 4212500,
	BATTERY_VOLT_04_220000_V = 4220000,
	BATTERY_VOLT_04_225000_V = 4225000,
	BATTERY_VOLT_04_237500_V = 4237500,
	BATTERY_VOLT_04_240000_V = 4240000,
	BATTERY_VOLT_04_250000_V = 4250000,
	BATTERY_VOLT_04_260000_V = 4260000,
	BATTERY_VOLT_04_262500_V = 4262500,
	BATTERY_VOLT_04_275000_V = 4275000,
	BATTERY_VOLT_04_280000_V = 4280000,
	BATTERY_VOLT_04_287500_V = 4287500,
	BATTERY_VOLT_04_300000_V = 4300000,
	BATTERY_VOLT_04_312500_V = 4312500,
	BATTERY_VOLT_04_320000_V = 4320000,
	BATTERY_VOLT_04_325000_V = 4325000,
	BATTERY_VOLT_04_337500_V = 4337500,
	BATTERY_VOLT_04_340000_V = 4340000,
	BATTERY_VOLT_04_350000_V = 4350000,
	BATTERY_VOLT_04_360000_V = 4360000,
	BATTERY_VOLT_04_362500_V = 4362500,
	BATTERY_VOLT_04_375000_V = 4375000,
	BATTERY_VOLT_04_380000_V = 4380000,
	BATTERY_VOLT_04_387500_V = 4387500,
	BATTERY_VOLT_04_400000_V = 4400000,
	BATTERY_VOLT_04_411500_V = 4411500,
	BATTERY_VOLT_04_412500_V = 4412500,
	BATTERY_VOLT_04_420000_V = 4420000,
	BATTERY_VOLT_04_425000_V = 4425000,
	BATTERY_VOLT_04_437500_V = 4437500,
	BATTERY_VOLT_04_440000_V = 4440000,
	BATTERY_VOLT_04_450000_V = 4450000,
	BATTERY_VOLT_04_460000_V = 4460000,
	BATTERY_VOLT_04_462500_V = 4462500,
	BATTERY_VOLT_04_475000_V = 4475000,
	BATTERY_VOLT_04_480000_V = 4480000,
	BATTERY_VOLT_04_487500_V = 4487500,
	BATTERY_VOLT_04_500000_V = 4500000,
	BATTERY_VOLT_04_512500_V = 4512500,
	BATTERY_VOLT_04_520000_V = 4520000,
	BATTERY_VOLT_04_525000_V = 4525000,
	BATTERY_VOLT_04_537500_V = 4537500,
	BATTERY_VOLT_04_540000_V = 4540000,
	BATTERY_VOLT_04_550000_V = 4550000,
	BATTERY_VOLT_04_560000_V = 4560000,
	BATTERY_VOLT_04_580000_V = 4580000,
	BATTERY_VOLT_04_600000_V = 4600000,
	BATTERY_VOLT_04_620000_V = 4620000,
	BATTERY_VOLT_04_640000_V = 4640000,
	BATTERY_VOLT_04_660000_V = 4660000,
	BATTERY_VOLT_04_680000_V = 4680000,
	BATTERY_VOLT_04_700000_V = 4700000,
	BATTERY_VOLT_04_720000_V = 4720000,
	BATTERY_VOLT_04_740000_V = 4740000,
	BATTERY_VOLT_04_760000_V = 4760000,
	BATTERY_VOLT_04_780000_V = 4780000,
	BATTERY_VOLT_04_800000_V = 4800000,
	BATTERY_VOLT_04_850000_V = 4850000,
	BATTERY_VOLT_04_950000_V = 4950000,
	BATTERY_VOLT_05_000000_V = 5000000,
	BATTERY_VOLT_05_150000_V = 5150000,
	BATTERY_VOLT_05_250000_V = 5250000,
	BATTERY_VOLT_05_300000_V = 5300000,
	BATTERY_VOLT_05_450000_V = 5450000,
	BATTERY_VOLT_06_000000_V = 6000000,
	BATTERY_VOLT_06_500000_V = 6500000,
	BATTERY_VOLT_06_750000_V = 6750000,
	BATTERY_VOLT_07_000000_V = 7000000,
	BATTERY_VOLT_07_250000_V = 7250000,
	BATTERY_VOLT_07_500000_V = 7500000,
	BATTERY_VOLT_08_000000_V = 8000000,
	BATTERY_VOLT_08_500000_V = 8500000,
	BATTERY_VOLT_09_000000_V = 9000000,
	BATTERY_VOLT_09_500000_V = 9500000,
	BATTERY_VOLT_10_000000_V = 10000000,
	BATTERY_VOLT_10_500000_V = 10500000,
	BATTERY_VOLT_MAX,
	BATTERY_VOLT_INVALID
} BATTERY_VOLTAGE_ENUM;


/* Enum of charger current List */
typedef enum {
	CHARGE_CURRENT_0_00_MA = 0,
	CHARGE_CURRENT_50_00_MA = 5000,
	CHARGE_CURRENT_62_50_MA = 6250,
	CHARGE_CURRENT_70_00_MA = 7000,
	CHARGE_CURRENT_75_00_MA = 7500,
	CHARGE_CURRENT_87_50_MA = 8750,
	CHARGE_CURRENT_99_00_MA = 9900,
	CHARGE_CURRENT_100_00_MA = 10000,
	CHARGE_CURRENT_125_00_MA = 12500,
	CHARGE_CURRENT_150_00_MA = 15000,
	CHARGE_CURRENT_200_00_MA = 20000,
	CHARGE_CURRENT_225_00_MA = 22500,
	CHARGE_CURRENT_250_00_MA = 25000,
	CHARGE_CURRENT_300_00_MA = 30000,
	CHARGE_CURRENT_350_00_MA = 35000,
	CHARGE_CURRENT_375_00_MA = 37500,
	CHARGE_CURRENT_400_00_MA = 40000,
	CHARGE_CURRENT_425_00_MA = 42500,
	CHARGE_CURRENT_450_00_MA = 45000,
	CHARGE_CURRENT_500_00_MA = 50000,
	CHARGE_CURRENT_525_00_MA = 52500,
	CHARGE_CURRENT_550_00_MA = 55000,
	CHARGE_CURRENT_600_00_MA = 60000,
	CHARGE_CURRENT_625_00_MA = 62500,
	CHARGE_CURRENT_650_00_MA = 65000,
	CHARGE_CURRENT_675_00_MA = 67500,
	CHARGE_CURRENT_700_00_MA = 70000,
	CHARGE_CURRENT_750_00_MA = 75000,
	CHARGE_CURRENT_775_00_MA = 77500,
	CHARGE_CURRENT_800_00_MA = 80000,
	CHARGE_CURRENT_825_00_MA = 82500,
	CHARGE_CURRENT_850_00_MA = 85000,
	CHARGE_CURRENT_900_00_MA = 90000,
	CHARGE_CURRENT_925_00_MA = 92500,
	CHARGE_CURRENT_950_00_MA = 95000,
	CHARGE_CURRENT_975_00_MA = 97500,
	CHARGE_CURRENT_1000_00_MA = 100000,
	CHARGE_CURRENT_1050_00_MA = 105000,
	CHARGE_CURRENT_1075_00_MA = 107500,
	CHARGE_CURRENT_1100_00_MA = 110000,
	CHARGE_CURRENT_1125_00_MA = 112500,
	CHARGE_CURRENT_1150_00_MA = 115000,
	CHARGE_CURRENT_1200_00_MA = 120000,
	CHARGE_CURRENT_1225_00_MA = 122500,
	CHARGE_CURRENT_1250_00_MA = 125000,
	CHARGE_CURRENT_1275_00_MA = 127500,
	CHARGE_CURRENT_1300_00_MA = 130000,
	CHARGE_CURRENT_1350_00_MA = 135000,
	CHARGE_CURRENT_1375_00_MA = 137500,
	CHARGE_CURRENT_1400_00_MA = 140000,
	CHARGE_CURRENT_1425_00_MA = 142500,
	CHARGE_CURRENT_1450_00_MA = 145000,
	CHARGE_CURRENT_1500_00_MA = 150000,
	CHARGE_CURRENT_1525_00_MA = 152500,
	CHARGE_CURRENT_1575_00_MA = 157500,
	CHARGE_CURRENT_1600_00_MA = 160000,
	CHARGE_CURRENT_1650_00_MA = 165000,
	CHARGE_CURRENT_1675_00_MA = 167500,
	CHARGE_CURRENT_1700_00_MA = 170000,
	CHARGE_CURRENT_1725_00_MA = 172500,
	CHARGE_CURRENT_1750_00_MA = 175000,
	CHARGE_CURRENT_1800_00_MA = 180000,
	CHARGE_CURRENT_1825_00_MA = 182500,
	CHARGE_CURRENT_1875_00_MA = 187500,
	CHARGE_CURRENT_1900_00_MA = 190000,
	CHARGE_CURRENT_1950_00_MA = 195000,
	CHARGE_CURRENT_1975_00_MA = 197500,
	CHARGE_CURRENT_2000_00_MA = 200000,
	CHARGE_CURRENT_2025_00_MA = 202500,
	CHARGE_CURRENT_2050_00_MA = 205000,
	CHARGE_CURRENT_2100_00_MA = 210000,
	CHARGE_CURRENT_2125_00_MA = 212500,
	CHARGE_CURRENT_2175_00_MA = 217500,
	CHARGE_CURRENT_2200_00_MA = 220000,
	CHARGE_CURRENT_2300_00_MA = 230000,
	CHARGE_CURRENT_2250_00_MA = 225000,
	CHARGE_CURRENT_2275_00_MA = 227500,
	CHARGE_CURRENT_2325_00_MA = 232500,
	CHARGE_CURRENT_2350_00_MA = 235000,
	CHARGE_CURRENT_2400_00_MA = 240000,
	CHARGE_CURRENT_2425_00_MA = 242500,
	CHARGE_CURRENT_2500_00_MA = 250000,
	CHARGE_CURRENT_2575_00_MA = 257500,
	CHARGE_CURRENT_2600_00_MA = 260000,
	CHARGE_CURRENT_2650_00_MA = 265000,
	CHARGE_CURRENT_2700_00_MA = 270000,
	CHARGE_CURRENT_2725_00_MA = 272500,
	CHARGE_CURRENT_2800_00_MA = 280000,
	CHARGE_CURRENT_2875_00_MA = 287500,
	CHARGE_CURRENT_2900_00_MA = 290000,
	CHARGE_CURRENT_3000_00_MA = 300000,
	CHARGE_CURRENT_3100_00_MA = 310000,
	CHARGE_CURRENT_3200_00_MA = 320000,
	CHARGE_CURRENT_MAX
} CHR_CURRENT_ENUM;

/* Enum of charger current List */
typedef enum {
	CHR_VOLT_00_500000_V = 500,
	CHR_VOLT_01_000000_V = 1000,
	CHR_VOLT_04_000000_V = 4000,
	CHR_VOLT_04_500000_V = 4500,
	CHR_VOLT_05_000000_V = 5000,
	CHR_VOLT_05_500000_V = 5500,
	CHR_VOLT_06_000000_V = 6050,
	CHR_VOLT_06_500000_V = 6500,
	CHR_VOLT_07_000000_V = 7000,
	CHR_VOLT_07_500000_V = 7500,
	CHR_VOLT_08_000000_V = 8000,
	CHR_VOLT_08_500000_V = 8500,
	CHR_VOLT_09_000000_V = 9000,
	CHR_VOLT_09_500000_V = 9500,
	CHR_VOLT_10_000000_V = 10000,
	CHR_VOLT_10_500000_V = 10500,
	CHR_VOLT_11_000000_V = 11000,
	CHR_VOLT_11_500000_V = 11500,
	CHR_VOLT_12_000000_V = 12000,
	CHR_VOLT_12_500000_V = 12500,
	CHR_VOLT_13_000000_V = 13000,
	CHR_VOLT_13_500000_V = 13500,
	CHR_VOLT_14_000000_V = 14000,
	CHR_VOLT_14_500000_V = 14500,
	CHR_VOLT_15_000000_V = 15000,
	CHR_VOLT_15_500000_V = 15500,
	CHR_VOLT_16_000000_V = 16000,
	CHR_VOLT_16_500000_V = 16500,
	CHR_VOLT_17_000000_V = 17000,
	CHR_VOLT_17_500000_V = 17500,
	CHR_VOLT_18_000000_V = 18000,
	CHR_VOLT_18_500000_V = 18500,
	CHR_VOLT_19_000000_V = 19000,
	CHR_VOLT_19_500000_V = 19500,
	CHR_VOLT_20_000000_V = 20000,
	CHR_VOLT_MAX,

} CHR_VOLTAGE_ENUM;



/* ============================================================ */
/* structure */
/* ============================================================ */


/* ============================================================ */
/* typedef */
/* ============================================================ */
typedef signed int(*CHARGING_CONTROL) (CHARGING_CTRL_CMD cmd, void *data);

#ifndef BATTERY_BOOL
#define BATTERY_BOOL
typedef enum {
	KAL_FALSE = 0,
	KAL_TRUE  = 1,
} kal_bool;
#endif


/* ============================================================ */
/* External Variables */
/* ============================================================ */
extern int Enable_BATDRV_LOG;
extern kal_bool chargin_hw_init_done;


/* ============================================================ */
/* External function */
/* ============================================================ */
extern signed int chr_control_interface(CHARGING_CTRL_CMD cmd, void *data);
extern unsigned int upmu_get_reg_value(unsigned int reg);
extern void Charger_Detect_Init(void);
extern void Charger_Detect_Release(void);
extern int hw_charging_get_charger_type(void);
extern void mt_power_off(void);
extern unsigned int mt6311_get_chip_id(void);
extern int is_mt6311_exist(void);
extern int is_mt6311_sw_ready(void);

extern void hw_charging_enable_dp_voltage(int ison);


/* switch charger */
extern void switch_charger_set_vindpm(unsigned int chr_v);
extern void mtk_pe20_plugout_reset(void);

/*extern BATTERY_VOLTAGE_ENUM battery_get_cv_voltage(void);*/
/*extern void battery_set_cv_voltage(BATTERY_VOLTAGE_ENUM cv);*/

#if defined(CONFIG_MTK_SMART_BATTERY) || (CONFIG_MZ_SMART_BATTERY)
extern kal_bool pmic_chrdet_status(void);
#else
__weak kal_bool pmic_chrdet_status(void);
#endif
/*BCCT input current control function over switch charger*/
extern unsigned int set_chr_input_current_limit(int current_limit);
#endif				/* #ifndef _CHARGING_H */
