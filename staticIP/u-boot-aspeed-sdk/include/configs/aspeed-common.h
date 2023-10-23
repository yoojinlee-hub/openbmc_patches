/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) ASPEED Technology Inc.
 *
 * Copyright 2016 IBM Corporation
 * (C) Copyright 2016 Google, Inc
 */

#ifndef __ASPEED_COMMON_CONFIG_H
#define __ASPEED_COMMON_CONFIG_H

#include <asm/arch/platform.h>

#define CONFIG_BOOTFILE		"all.bin"

#define CONFIG_GATEWAYIP	192.168.0.1
#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		192.168.0.120
#define CONFIG_SERVERIP		192.168.0.200

#define CONFIG_STANDALONE_LOAD_ADDR 0x83000000

#define CONFIG_HW_WATCHDOG

/* Misc CPU related */
#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

#define CONFIG_SYS_SDRAM_BASE		(ASPEED_DRAM_BASE + CONFIG_ASPEED_SSP_RERV_MEM)

#ifdef CONFIG_PRE_CON_BUF_SZ
#define CONFIG_SYS_INIT_RAM_ADDR	(ASPEED_SRAM_BASE + CONFIG_PRE_CON_BUF_SZ)
#define CONFIG_SYS_INIT_RAM_SIZE	(ASPEED_SRAM_SIZE - CONFIG_PRE_CON_BUF_SZ)
#else
#define CONFIG_SYS_INIT_RAM_ADDR	(ASPEED_SRAM_BASE)
#define CONFIG_SYS_INIT_RAM_SIZE	(ASPEED_SRAM_SIZE)
#endif

#define SYS_INIT_RAM_END \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_RAM_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(SYS_INIT_RAM_END - GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_BOOTMAPSZ		(256 * 1024 * 1024)
#define CONFIG_SYS_MALLOC_LEN		(32 << 20)

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_BOOTM_LEN 		(0x800000 * 2)

#define CONFIG_EXTRA_ENV_SETTINGS \
    "rootpath=/private/rootfs\0" \
    "nfsip=192.168.0.200\0" \
    "bootargs_nfs=setenv bootargs console=ttyS4,115200n8 mem.devmem=y root=/dev/nfs rootfstype=nfs rw nfsroot=${nfsip}:${rootpath},nolock,tcp,nfsvers=4 ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}::eth0:off loglevel=8 nfsrootdebug\0" \
    "bootargs_ram=setenv bootargs console=ttyS4,115200n8 root=/dev/ram rw init=/linuxrc earlyprintk\0" \
    "verify=yes\0" \
    ""

/* Environment */
#ifdef CONFIG_ASPEED_PALLADIUM
#define CONFIG_ENV_IS_NOWHERE
#endif

#ifndef CONFIG_ENV_SIZE
#define CONFIG_ENV_SIZE			0x10000
#endif

#ifndef CONFIG_ENV_OFFSET
#define CONFIG_ENV_OFFSET		0x2400000
#endif

#define CONFIG_SYS_REDUNDAND_ENVIRONMENT
#define CONFIG_ENV_OVERWRITE

#define AST_FMC_CS0_BASE		0x20000000 /* CS0 */
#define CONFIG_ENV_ADDR			(AST_FMC_CS0_BASE + CONFIG_ENV_OFFSET)
#define CONFIG_ENV_OFFSET_REDUND	(CONFIG_ENV_OFFSET + CONFIG_ENV_SIZE)
#define CONFIG_ENV_ADDR_REDUND		(AST_FMC_CS0_BASE + CONFIG_ENV_OFFSET_REDUND)
#define CONFIG_ENV_SIZE_REDUND		CONFIG_ENV_SIZE

#define CONFIG_ENV_SECT_SIZE	(4 << 10)

/*
 * Ethernet related
 */
#define PHY_ANEG_TIMEOUT		800

/* Uboot size */
#define CONFIG_SYS_MONITOR_LEN ((1024 - 64) * 1024)

#ifdef CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		0
#define CONFIG_SYS_MMC_ENV_PART		0
#define CONFIG_ENV_OFFSET_REDUND	(CONFIG_ENV_OFFSET + CONFIG_ENV_SIZE)
#endif

/* Get MAC Address from EEPROM config */
#define I2C_CLK_100K 100000         // default standard I2C speed 100K
#define EEPROM_I2C_CHANNEL 0        // Base on MB EEPROM deploy
#define EEPROM_ADDRESS 0x50         // Base on MB EEPROM deploy
#define MAC1_EEPROM_OFFSET 0x00     // Base on MB EEPROM deploy
#define MAC2_EEPROM_OFFSET 0x06     // Base on MB EEPROM deploy
#define I2C_CH_SET  EEPROM_I2C_CHANNEL
#define I2C_ADDR_SET    EEPROM_ADDRESS

#endif	/* __ASPEED_COMMON_CONFIG_H */
