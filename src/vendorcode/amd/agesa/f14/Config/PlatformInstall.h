/* $NoKeywords:$ */
/**
 * @file
 *
 * Install of build options for a combination of package type, processor, and features.
 *
 * This file generates the defaults tables for the all platform solution
 * combinations.  The documented build options are imported from a user
 * controlled file for processing.
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGESA
 * @e sub-project:  Core
 * @e \$Revision: 47417 $   @e \$Date: 2011-02-18 12:48:20 -0700 (Fri, 18 Feb 2011) $
 */
/*
 *****************************************************************************
 *
 * Copyright (c) 2011, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***************************************************************************
 *
 */

/*****************************************************************************
 *
 * Start processing the user options:  First, set default settings
 *
 ****************************************************************************/

CONST AMD_MODULE_HEADER mCpuModuleID = {
  //ModuleHeaderSignature
  // Remove 'DOM$' as temp solution before update BinUtil.exe ,
  Int32FromChar ('0', '0', '0', '0'),
  //ModuleIdentifier[8]
  AGESA_ID,
  //ModuleVersion[12]
  AGESA_VERSION_STRING,
  //ModuleDispatcher
  NULL,//(VOID *)(UINT64)((MODULE_ENTRY)AmdAgesaDispatcher),
  //NextBlock
  NULL
};

/* The default fixed MTRR values to be set after memory initialization */
static const AP_MTRR_SETTINGS ROMDATA OntarioApMtrrSettingsList[] =
{
	{ AMD_AP_MTRR_FIX64k_00000, 0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX16k_80000, 0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX16k_A0000, 0x0000000000000000ull },
	{ AMD_AP_MTRR_FIX4k_C0000,  0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX4k_C8000,  0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX4k_D0000,  0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX4k_D8000,  0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX4k_E0000,  0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX4k_E8000,  0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX4k_F0000,  0x1E1E1E1E1E1E1E1Eull },
	{ AMD_AP_MTRR_FIX4k_F8000,  0x1E1E1E1E1E1E1E1Eull },
	{ CPU_LIST_TERMINAL },
};

/* Process solution defined socket / family installations
 *
 * As part of the release package for each image, define the options below to select the
 * AGESA processor support included in that image.
 */

/*  Default sockets to off  */
#define OPTION_FT1_SOCKET_SUPPORT    FALSE

/*  Default families to off  */
#define OPTION_FAMILY14H             FALSE

/*  Enable the appropriate socket support  */
#ifdef INSTALL_FT1_SOCKET_SUPPORT
  #if  INSTALL_FT1_SOCKET_SUPPORT == TRUE
    #undef OPTION_FT1_SOCKET_SUPPORT
    #define OPTION_FT1_SOCKET_SUPPORT  TRUE
  #endif
#endif

// F14 is supported in FT1
#ifdef INSTALL_FAMILY_14_SUPPORT
  #if  INSTALL_FAMILY_14_SUPPORT == TRUE
    #undef OPTION_FAMILY14H
    #define OPTION_FAMILY14H     TRUE
  #endif
#endif

#if (OPTION_FAMILY14H == TRUE)
  #if (OPTION_FT1_SOCKET_SUPPORT == FALSE)
    #undef OPTION_FAMILY14H
    #define OPTION_FAMILY14H  FALSE
  #endif
#endif


/*  Check for invalid combinations of socket/family */

#if (OPTION_FT1_SOCKET_SUPPORT == TRUE)
  #if (OPTION_FAMILY14H == FALSE)
    #error No FT1 supported families included in the build
  #endif
#endif

/* Process AGESA private data
 *
 * Turn on appropriate CPU models and memory controllers,
 * as well as some other memory controls.
 */

/*  Default all models to off  */
#define OPTION_FAMILY14H_ON          FALSE

/*  Default all memory controllers to off  */
#define OPTION_MEMCTLR_ON            FALSE

/*  Default all memory controls to off  */
#define OPTION_HW_WRITE_LEV_TRAINING            FALSE
#define OPTION_SW_WRITE_LEV_TRAINING            FALSE
#define OPTION_CONTINOUS_PATTERN_GENERATION     FALSE
#define OPTION_HW_DQS_REC_EN_TRAINING           FALSE
#define OPTION_NON_OPT_SW_DQS_REC_EN_TRAINING   FALSE
#define OPTION_OPT_SW_DQS_REC_EN_TRAINING       FALSE
#define OPTION_NON_OPT_SW_RD_WR_POS_TRAINING    FALSE
#define OPTION_OPT_SW_RD_WR_POS_TRAINING        FALSE
#define OPTION_MAX_RD_LAT_TRAINING              FALSE
#define OPTION_HW_DRAM_INIT                     FALSE
#define OPTION_SW_DRAM_INIT                     FALSE
#define OPTION_S3_MEM_SUPPORT                   FALSE
#define OPTION_ADDR_TO_CS_TRANSLATOR            FALSE

/*  Defaults for public user options  */
#define OPTION_UDIMMS                           FALSE
#define OPTION_RDIMMS                           FALSE
#define OPTION_SODIMMS                          FALSE
#define OPTION_LRDIMMS                          FALSE
#define OPTION_DDR3                             FALSE
#define OPTION_ECC                              FALSE
#define OPTION_BANK_INTERLEAVE                  FALSE
#define OPTION_DCT_INTERLEAVE                   FALSE
#define OPTION_NODE_INTERLEAVE                  FALSE
#define OPTION_PARALLEL_TRAINING                FALSE
#define OPTION_ONLINE_SPARE                     FALSE
#define OPTION_MEM_RESTORE                      FALSE
#define OPTION_DIMM_EXCLUDE                     FALSE

/*  Default all CPU controls to off  */
#define OPTION_MULTISOCKET                      FALSE
#define OPTION_SRAT                             FALSE
#define OPTION_SLIT                             FALSE
#define OPTION_HT_ASSIST                        FALSE
#define OPTION_ATM_MODE                         FALSE
#define OPTION_CPU_CORELEVLING                  FALSE
#define OPTION_MSG_BASED_C1E                    FALSE
#define OPTION_CPU_CFOH                         FALSE
#define OPTION_C6_STATE                         FALSE
#define OPTION_IO_CSTATE                        FALSE
#define OPTION_CPB                              FALSE
#define OPTION_CPU_LOW_PWR_PSTATE_FOR_PROCHOT   FALSE
#define OPTION_S3SCRIPT                         FALSE
#define OPTION_GFX_RECOVERY                     FALSE

/*  Enable all private controls based on socket/family enables  */

#if (OPTION_FT1_SOCKET_SUPPORT == TRUE)
  #if (OPTION_FAMILY14H == TRUE)
    #undef OPTION_FAMILY14H_ON
    #define OPTION_FAMILY14H_ON  TRUE
    #undef OPTION_MEMCTLR_ON
    #define OPTION_MEMCTLR_ON    TRUE
    #undef OPTION_HW_WRITE_LEV_TRAINING
    #define OPTION_HW_WRITE_LEV_TRAINING  TRUE
    #undef OPTION_CONTINOUS_PATTERN_GENERATION
    #define OPTION_CONTINOUS_PATTERN_GENERATION  TRUE
    #undef OPTION_MAX_RD_LAT_TRAINING
    #define OPTION_MAX_RD_LAT_TRAINING  TRUE
    #undef OPTION_HW_DQS_REC_EN_TRAINING
    #define OPTION_HW_DQS_REC_EN_TRAINING  TRUE
    #undef OPTION_OPT_SW_RD_WR_POS_TRAINING
    #define OPTION_OPT_SW_RD_WR_POS_TRAINING  TRUE
    #undef OPTION_SW_DRAM_INIT
    #define OPTION_SW_DRAM_INIT  TRUE
    #undef OPTION_S3_MEM_SUPPORT
    #define OPTION_S3_MEM_SUPPORT  TRUE
    #undef OPTION_C6_STATE
    #define OPTION_C6_STATE  TRUE
    #undef OPTION_CPB
    #define OPTION_CPB TRUE
    #undef OPTION_IO_CSTATE
    #define OPTION_IO_CSTATE TRUE
    #undef OPTION_S3SCRIPT
    #define OPTION_S3SCRIPT  TRUE
    #undef OPTION_UDIMMS
    #define OPTION_UDIMMS  TRUE
    #undef OPTION_SODIMMS
    #define OPTION_SODIMMS  TRUE
    #undef OPTION_DDR3
    #define OPTION_DDR3  TRUE
    #undef OPTION_BANK_INTERLEAVE
    #define OPTION_BANK_INTERLEAVE  TRUE
    #undef OPTION_MEM_RESTORE
    #define OPTION_MEM_RESTORE  TRUE
    #undef OPTION_DIMM_EXCLUDE
    #define OPTION_DIMM_EXCLUDE  TRUE
  #endif
#endif

#if (OPTION_FAMILY14H == TRUE)
  #undef  GNB_SUPPORT
  #define GNB_SUPPORT   TRUE
#endif

#define OPTION_ACPI_PSTATES             TRUE
#define OPTION_WHEA                     TRUE
#define OPTION_DMI                      FALSE
#define OPTION_EARLY_SAMPLES            FALSE
#define CFG_ACPI_PSTATES_PPC            TRUE
#define CFG_ACPI_PSTATES_PCT            TRUE
#define CFG_ACPI_PSTATES_PSD            TRUE
#define CFG_ACPI_PSTATES_PSS            TRUE
#define CFG_ACPI_PSTATES_XPSS           TRUE
#define CFG_ACPI_PSTATE_PSD_INDPX       FALSE
#define CFG_VRM_HIGH_SPEED_ENABLE       TRUE
#define CFG_VRM_NB_HIGH_SPEED_ENABLE    FALSE
#define OPTION_ALIB                     TRUE
/*---------------------------------------------------------------------------
 *       Processing the options:  Second, process the user's selections
 *--------------------------------------------------------------------------*/
#ifdef BLDOPT_REMOVE_MULTISOCKET_SUPPORT
  #if  BLDOPT_REMOVE_MULTISOCKET_SUPPORT == TRUE
    #undef  OPTION_MULTISOCKET
    #define OPTION_MULTISOCKET          FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_ECC_SUPPORT
  #if  BLDOPT_REMOVE_ECC_SUPPORT == TRUE
    #undef  OPTION_ECC
    #define OPTION_ECC        FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_UDIMMS_SUPPORT
  #if  BLDOPT_REMOVE_UDIMMS_SUPPORT == TRUE
    #undef  OPTION_UDIMMS
    #define OPTION_UDIMMS               FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_RDIMMS_SUPPORT
  #if  BLDOPT_REMOVE_RDIMMS_SUPPORT == TRUE
    #undef  OPTION_RDIMMS
    #define OPTION_RDIMMS               FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_SODIMMS_SUPPORT
  #if  BLDOPT_REMOVE_SODIMMS_SUPPORT == TRUE
    #undef  OPTION_SODIMMS
    #define OPTION_SODIMMS               FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_LRDIMMS_SUPPORT
  #if  BLDOPT_REMOVE_LRDIMMS_SUPPORT == TRUE
    #undef  OPTION_LRDIMMS
    #define OPTION_LRDIMMS               FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_BANK_INTERLEAVE
  #if  BLDOPT_REMOVE_BANK_INTERLEAVE == TRUE
    #undef  OPTION_BANK_INTERLEAVE
    #define OPTION_BANK_INTERLEAVE      FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_DCT_INTERLEAVE
  #if  BLDOPT_REMOVE_DCT_INTERLEAVE == TRUE
    #undef  OPTION_DCT_INTERLEAVE
    #define OPTION_DCT_INTERLEAVE       FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_NODE_INTERLEAVE
  #if  BLDOPT_REMOVE_NODE_INTERLEAVE == TRUE
    #undef  OPTION_NODE_INTERLEAVE
    #define OPTION_NODE_INTERLEAVE      FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_PARALLEL_TRAINING
  #if  BLDOPT_REMOVE_PARALLEL_TRAINING == TRUE
    #undef  OPTION_PARALLEL_TRAINING
    #define OPTION_PARALLEL_TRAINING    FALSE
  #endif
#endif
/* Originally BLDOPT_REMOVE_ONLINE_SPARE_SUPPORT, but inverted alongside the default value */
#ifdef BLDOPT_ENABLE_ONLINE_SPARE_SUPPORT
  #if  BLDOPT_ENABLE_ONLINE_SPARE_SUPPORT == TRUE
    #undef  OPTION_ONLINE_SPARE
    #define OPTION_ONLINE_SPARE         TRUE
  #endif
#endif
#ifdef BLDOPT_REMOVE_MEM_RESTORE_SUPPORT
  #if  BLDOPT_REMOVE_MEM_RESTORE_SUPPORT == TRUE
    #undef  OPTION_MEM_RESTORE
    #define OPTION_MEM_RESTORE         FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_ACPI_PSTATES
  #if  BLDOPT_REMOVE_ACPI_PSTATES == TRUE
    #undef  OPTION_ACPI_PSTATES
    #define OPTION_ACPI_PSTATES         FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_SRAT
  #if  BLDOPT_REMOVE_SRAT == TRUE
    #undef  OPTION_SRAT
    #define OPTION_SRAT                 FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_SLIT
  #if  BLDOPT_REMOVE_SLIT == TRUE
    #undef  OPTION_SLIT
    #define OPTION_SLIT                 FALSE
  #endif
#endif
#ifdef BLDOPT_REMOVE_WHEA
  #if  BLDOPT_REMOVE_WHEA == TRUE
    #undef  OPTION_WHEA
    #define OPTION_WHEA                 FALSE
  #endif
#endif
/* Originally BLDOPT_REMOVE_DMI, but inverted alongside the default value */
#ifdef BLDOPT_ENABLE_DMI
  #if  BLDOPT_ENABLE_DMI == TRUE
    #undef  OPTION_DMI
    #define OPTION_DMI                  TRUE
  #endif
#endif
#ifdef BLDOPT_REMOVE_ADDR_TO_CS_TRANSLATOR
  #if  BLDOPT_REMOVE_ADDR_TO_CS_TRANSLATOR == TRUE
    #undef  OPTION_ADDR_TO_CS_TRANSLATOR
    #define OPTION_ADDR_TO_CS_TRANSLATOR        FALSE
  #endif
#endif

#ifdef BLDOPT_REMOVE_HT_ASSIST
  #if  BLDOPT_REMOVE_HT_ASSIST == TRUE
    #undef  OPTION_HT_ASSIST
    #define OPTION_HT_ASSIST      FALSE
  #endif
#endif

#ifdef BLDOPT_REMOVE_ATM_MODE
  #if  BLDOPT_REMOVE_ATM_MODE == TRUE
    #undef  OPTION_ATM_MODE
    #define OPTION_ATM_MODE      FALSE
  #endif
#endif

#ifdef BLDOPT_REMOVE_MSG_BASED_C1E
  #if  BLDOPT_REMOVE_MSG_BASED_C1E == TRUE
    #undef  OPTION_MSG_BASED_C1E
    #define OPTION_MSG_BASED_C1E      FALSE
  #endif
#endif

#ifdef BLDOPT_REMOVE_C6_STATE
  #if  BLDOPT_REMOVE_C6_STATE == TRUE
    #undef  OPTION_C6_STATE
    #define OPTION_C6_STATE      FALSE
  #endif
#endif

/* Originally BLDOPT_REMOVE_GFX_RECOVERY, but inverted alongside the default value */
#ifdef BLDOPT_ENABLE_GFX_RECOVERY
  #if  BLDOPT_ENABLE_GFX_RECOVERY == TRUE
    #undef  OPTION_GFX_RECOVERY
    #define OPTION_GFX_RECOVERY         TRUE
  #endif
#endif

#ifdef BLDCFG_REMOVE_ACPI_PSTATES_PPC
  #if  BLDCFG_REMOVE_ACPI_PSTATES_PPC == TRUE
    #undef  CFG_ACPI_PSTATES_PPC
    #define CFG_ACPI_PSTATES_PPC        FALSE
  #endif
#endif

#ifdef BLDCFG_REMOVE_ACPI_PSTATES_PCT
  #if  BLDCFG_REMOVE_ACPI_PSTATES_PCT == TRUE
    #undef  CFG_ACPI_PSTATES_PCT
    #define CFG_ACPI_PSTATES_PCT        FALSE
  #endif
#endif

#ifdef BLDCFG_REMOVE_ACPI_PSTATES_PSD
  #if  BLDCFG_REMOVE_ACPI_PSTATES_PSD == TRUE
    #undef  CFG_ACPI_PSTATES_PSD
    #define CFG_ACPI_PSTATES_PSD        FALSE
  #endif
#endif

#ifdef BLDCFG_REMOVE_ACPI_PSTATES_PSS
  #if  BLDCFG_REMOVE_ACPI_PSTATES_PSS == TRUE
    #undef  CFG_ACPI_PSTATES_PSS
    #define CFG_ACPI_PSTATES_PSS        FALSE
  #endif
#endif

#ifdef BLDCFG_REMOVE_ACPI_PSTATES_XPSS
  #if  BLDCFG_REMOVE_ACPI_PSTATES_XPSS == TRUE
    #undef  CFG_ACPI_PSTATES_XPSS
    #define CFG_ACPI_PSTATES_XPSS       FALSE
  #endif
#endif

#ifdef BLDCFG_FORCE_INDEPENDENT_PSD_OBJECT
  #if  BLDCFG_FORCE_INDEPENDENT_PSD_OBJECT == TRUE
    #undef  CFG_ACPI_PSTATE_PSD_INDPX
    #define CFG_ACPI_PSTATE_PSD_INDPX       TRUE
  #endif
#endif

/* Originally BLDCFG_VRM_HIGH_SPEED_ENABLE, but inverted alongside the default value */
#ifdef BLDCFG_VRM_HIGH_SPEED_DISABLE
  #if  BLDCFG_VRM_HIGH_SPEED_DISABLE == TRUE
    #undef  CFG_VRM_HIGH_SPEED_ENABLE
    #define CFG_VRM_HIGH_SPEED_ENABLE       FALSE
  #endif
#endif

#ifdef BLDCFG_VRM_NB_HIGH_SPEED_ENABLE
  #if BLDCFG_VRM_NB_HIGH_SPEED_ENABLE == TRUE
    #undef CFG_VRM_NB_HIGH_SPEED_ENABLE
    #define CFG_VRM_NB_HIGH_SPEED_ENABLE    TRUE
  #endif
#endif

#ifdef BLDCFG_STARTING_BUSNUM
  #define CFG_STARTING_BUSNUM         (BLDCFG_STARTING_BUSNUM)
#else
  #define CFG_STARTING_BUSNUM         (0)
#endif

#ifdef BLDCFG_AMD_PLATFORM_TYPE
  #define CFG_AMD_PLATFORM_TYPE              BLDCFG_AMD_PLATFORM_TYPE
#else
  #define CFG_AMD_PLATFORM_TYPE              0
#endif

CONST UINT32 ROMDATA AmdPlatformTypeCgf = CFG_AMD_PLATFORM_TYPE;

#ifdef BLDCFG_MAXIMUM_BUSNUM
  #define CFG_MAXIMUM_BUSNUM          (BLDCFG_MAXIMUM_BUSNUM)
#else
  #define CFG_MAXIMUM_BUSNUM          (0xF8)
#endif

#ifdef BLDCFG_ALLOCATED_BUSNUM
  #define CFG_ALLOCATED_BUSNUM        (BLDCFG_ALLOCATED_BUSNUM)
#else
  #define CFG_ALLOCATED_BUSNUM        (0x20)
#endif

#ifdef BLDCFG_BUID_SWAP_LIST
  #define CFG_BUID_SWAP_LIST         (BLDCFG_BUID_SWAP_LIST)
#else
  #define CFG_BUID_SWAP_LIST         (NULL)
#endif

#ifdef BLDCFG_HTDEVICE_CAPABILITIES_OVERRIDE_LIST
  #define CFG_HTDEVICE_CAPABILITIES_OVERRIDE_LIST         (BLDCFG_HTDEVICE_CAPABILITIES_OVERRIDE_LIST)
#else
  #define CFG_HTDEVICE_CAPABILITIES_OVERRIDE_LIST         (NULL)
#endif

#ifdef BLDCFG_HTFABRIC_LIMITS_LIST
  #define CFG_HTFABRIC_LIMITS_LIST         (BLDCFG_HTFABRIC_LIMITS_LIST)
#else
  #define CFG_HTFABRIC_LIMITS_LIST         (NULL)
#endif

#ifdef BLDCFG_HTCHAIN_LIMITS_LIST
  #define CFG_HTCHAIN_LIMITS_LIST         (BLDCFG_HTCHAIN_LIMITS_LIST)
#else
  #define CFG_HTCHAIN_LIMITS_LIST         (NULL)
#endif

#ifdef BLDCFG_BUS_NUMBERS_LIST
  #define CFG_BUS_NUMBERS_LIST         (BLDCFG_BUS_NUMBERS_LIST)
#else
  #define CFG_BUS_NUMBERS_LIST         (NULL)
#endif

#ifdef BLDCFG_IGNORE_LINK_LIST
  #define CFG_IGNORE_LINK_LIST         (BLDCFG_IGNORE_LINK_LIST)
#else
  #define CFG_IGNORE_LINK_LIST         (NULL)
#endif

#ifdef BLDCFG_LINK_SKIP_REGANG_LIST
  #define CFG_LINK_SKIP_REGANG_LIST         (BLDCFG_LINK_SKIP_REGANG_LIST)
#else
  #define CFG_LINK_SKIP_REGANG_LIST         (NULL)
#endif

#ifdef BLDCFG_SET_HTCRC_SYNC_FLOOD
  #define CFG_SET_HTCRC_SYNC_FLOOD         (BLDCFG_SET_HTCRC_SYNC_FLOOD)
#else
  #define CFG_SET_HTCRC_SYNC_FLOOD         (FALSE)
#endif

#ifdef BLDCFG_USE_UNIT_ID_CLUMPING
  #define CFG_USE_UNIT_ID_CLUMPING         (BLDCFG_USE_UNIT_ID_CLUMPING)
#else
  #define CFG_USE_UNIT_ID_CLUMPING         (FALSE)
#endif

#ifdef BLDCFG_ADDITIONAL_TOPOLOGIES_LIST
  #define CFG_ADDITIONAL_TOPOLOGIES_LIST         (BLDCFG_ADDITIONAL_TOPOLOGIES_LIST)
#else
  #define CFG_ADDITIONAL_TOPOLOGIES_LIST         (NULL)
#endif

#ifdef BLDCFG_USE_HT_ASSIST
  #define CFG_USE_HT_ASSIST               (BLDCFG_USE_HT_ASSIST)
#else
  #define CFG_USE_HT_ASSIST               (TRUE)
#endif

#ifdef BLDCFG_USE_ATM_MODE
  #define CFG_USE_ATM_MODE                (BLDCFG_USE_ATM_MODE)
#else
  #define CFG_USE_ATM_MODE                (TRUE)
#endif

#ifdef BLDCFG_PLATFORM_CONTROL_FLOW_MODE
  #define CFG_PLATFORM_CONTROL_FLOW_MODE  (BLDCFG_PLATFORM_CONTROL_FLOW_MODE)
#else
  #define CFG_PLATFORM_CONTROL_FLOW_MODE  (Nfcm)
#endif

#ifdef BLDCFG_PLATFORM_DEEMPHASIS_LIST
  #define CFG_PLATFORM_DEEMPHASIS_LIST  (BLDCFG_PLATFORM_DEEMPHASIS_LIST)
#else
  #define CFG_PLATFORM_DEEMPHASIS_LIST  (NULL)
#endif

#ifdef BLDCFG_VRM_ADDITIONAL_DELAY
  #define CFG_VRM_ADDITIONAL_DELAY      (BLDCFG_VRM_ADDITIONAL_DELAY)
#else
  #define CFG_VRM_ADDITIONAL_DELAY      (0)
#endif

#ifdef BLDCFG_VRM_CURRENT_LIMIT
  #define CFG_VRM_CURRENT_LIMIT            BLDCFG_VRM_CURRENT_LIMIT
#else
  #define CFG_VRM_CURRENT_LIMIT            24000
#endif

#ifdef BLDCFG_VRM_LOW_POWER_THRESHOLD
  #define CFG_VRM_LOW_POWER_THRESHOLD      BLDCFG_VRM_LOW_POWER_THRESHOLD
#else
  #define CFG_VRM_LOW_POWER_THRESHOLD      24000
#endif

#ifdef BLDCFG_VRM_SLEW_RATE
  #define CFG_VRM_SLEW_RATE                BLDCFG_VRM_SLEW_RATE
#else
  #define CFG_VRM_SLEW_RATE                (5000)
#endif

#ifdef BLDCFG_VRM_INRUSH_CURRENT_LIMIT
  #define CFG_VRM_INRUSH_CURRENT_LIMIT     BLDCFG_VRM_INRUSH_CURRENT_LIMIT
#else
  #define CFG_VRM_INRUSH_CURRENT_LIMIT     (6000)
#endif

#ifdef BLDCFG_VRM_NB_ADDITIONAL_DELAY
  #define CFG_VRM_NB_ADDITIONAL_DELAY      (BLDCFG_VRM_NB_ADDITIONAL_DELAY)
#else
  #define CFG_VRM_NB_ADDITIONAL_DELAY      (0)
#endif

#ifdef BLDCFG_VRM_NB_CURRENT_LIMIT
  #define CFG_VRM_NB_CURRENT_LIMIT         BLDCFG_VRM_NB_CURRENT_LIMIT
#else
  #define CFG_VRM_NB_CURRENT_LIMIT         (0)
#endif

#ifdef BLDCFG_VRM_NB_LOW_POWER_THRESHOLD
  #define CFG_VRM_NB_LOW_POWER_THRESHOLD   BLDCFG_VRM_NB_LOW_POWER_THRESHOLD
#else
  #define CFG_VRM_NB_LOW_POWER_THRESHOLD   (0)
#endif

#ifdef BLDCFG_VRM_NB_SLEW_RATE
  #define CFG_VRM_NB_SLEW_RATE             BLDCFG_VRM_NB_SLEW_RATE
#else
  #define CFG_VRM_NB_SLEW_RATE             (5000)
#endif

#ifdef BLDCFG_VRM_NB_INRUSH_CURRENT_LIMIT
  #define CFG_VRM_NB_INRUSH_CURRENT_LIMIT  BLDCFG_VRM_NB_INRUSH_CURRENT_LIMIT
#else
  #define CFG_VRM_NB_INRUSH_CURRENT_LIMIT  (0)
#endif


#ifdef BLDCFG_PLAT_NUM_IO_APICS
  #define CFG_PLAT_NUM_IO_APICS            BLDCFG_PLAT_NUM_IO_APICS
#else
  #define CFG_PLAT_NUM_IO_APICS            3
#endif

#ifdef BLDCFG_MEM_INIT_PSTATE
  #define CFG_MEM_INIT_PSTATE              BLDCFG_MEM_INIT_PSTATE
#else
  #define CFG_MEM_INIT_PSTATE              0
#endif

#ifdef BLDCFG_PLATFORM_C1E_MODE
  #define CFG_C1E_MODE                        BLDCFG_PLATFORM_C1E_MODE
#else
  #define CFG_C1E_MODE                        C1eModeDisabled
#endif

#ifdef BLDCFG_PLATFORM_C1E_OPDATA
  #define CFG_C1E_OPDATA                      BLDCFG_PLATFORM_C1E_OPDATA
#else
  #define CFG_C1E_OPDATA                      0
#endif

#ifdef BLDCFG_PLATFORM_C1E_OPDATA1
  #define CFG_C1E_OPDATA1                     BLDCFG_PLATFORM_C1E_OPDATA1
#else
  #define CFG_C1E_OPDATA1                     0
#endif

#ifdef BLDCFG_PLATFORM_C1E_OPDATA2
  #define CFG_C1E_OPDATA2                     BLDCFG_PLATFORM_C1E_OPDATA2
#else
  #define CFG_C1E_OPDATA2                     0
#endif

#ifdef BLDCFG_PLATFORM_CSTATE_MODE
  #define CFG_CSTATE_MODE                     BLDCFG_PLATFORM_CSTATE_MODE
#else
  #define CFG_CSTATE_MODE                     CStateModeC6
#endif

#ifdef BLDCFG_PLATFORM_CSTATE_OPDATA
  #define CFG_CSTATE_OPDATA                   BLDCFG_PLATFORM_CSTATE_OPDATA
#else
  #define CFG_CSTATE_OPDATA                   0x840
#endif

#ifdef BLDCFG_PLATFORM_CSTATE_IO_BASE_ADDRESS
  #define CFG_CSTATE_IO_BASE_ADDRESS       BLDCFG_PLATFORM_CSTATE_IO_BASE_ADDRESS
#else
  #define CFG_CSTATE_IO_BASE_ADDRESS       0x840
#endif

#ifdef BLDCFG_PLATFORM_CPB_MODE
  #define CFG_CPB_MODE                        BLDCFG_PLATFORM_CPB_MODE
#else
  #define CFG_CPB_MODE                        CpbModeAuto
#endif

#ifdef BLDCFG_CORE_LEVELING_MODE
  #define CFG_CORE_LEVELING_MODE           BLDCFG_CORE_LEVELING_MODE
#else
  #define CFG_CORE_LEVELING_MODE           CORE_LEVEL_LOWEST
#endif

#ifdef BLDCFG_AMD_PSTATE_CAP_VALUE
  #define CFG_AMD_PSTATE_CAP_VALUE           BLDCFG_AMD_PSTATE_CAP_VALUE
#else
  #define CFG_AMD_PSTATE_CAP_VALUE           0
#endif

#ifdef BLDCFG_HEAP_DRAM_ADDRESS
  #define CFG_HEAP_DRAM_ADDRESS                 BLDCFG_HEAP_DRAM_ADDRESS
#else
  #define CFG_HEAP_DRAM_ADDRESS                 AMD_HEAP_RAM_ADDRESS
#endif

#ifdef BLDCFG_MEMORY_BUS_FREQUENCY_LIMIT
  #define CFG_MEMORY_BUS_FREQUENCY_LIMIT        BLDCFG_MEMORY_BUS_FREQUENCY_LIMIT
#else
  #define CFG_MEMORY_BUS_FREQUENCY_LIMIT        DDR1333_FREQUENCY
#endif

#ifdef BLDCFG_MEMORY_MODE_UNGANGED
  #define CFG_MEMORY_MODE_UNGANGED              BLDCFG_MEMORY_MODE_UNGANGED
#else
  #define CFG_MEMORY_MODE_UNGANGED              TRUE
#endif

#ifdef BLDCFG_MEMORY_QUAD_RANK_CAPABLE
  #define CFG_MEMORY_QUAD_RANK_CAPABLE          BLDCFG_MEMORY_QUAD_RANK_CAPABLE
#else
  #define CFG_MEMORY_QUAD_RANK_CAPABLE          TRUE
#endif

#ifdef BLDCFG_MEMORY_QUADRANK_TYPE
  #define CFG_MEMORY_QUADRANK_TYPE              BLDCFG_MEMORY_QUADRANK_TYPE
#else
  #define CFG_MEMORY_QUADRANK_TYPE              QUADRANK_UNBUFFERED
#endif

#ifdef BLDCFG_MEMORY_RDIMM_CAPABLE
  #define CFG_MEMORY_RDIMM_CAPABLE              BLDCFG_MEMORY_RDIMM_CAPABLE
#else
  #define CFG_MEMORY_RDIMM_CAPABLE              TRUE
#endif

#ifdef BLDCFG_MEMORY_LRDIMM_CAPABLE
  #define CFG_MEMORY_LRDIMM_CAPABLE              BLDCFG_MEMORY_LRDIMM_CAPABLE
#else
  #define CFG_MEMORY_LRDIMM_CAPABLE              TRUE
#endif

#ifdef BLDCFG_MEMORY_UDIMM_CAPABLE
  #define CFG_MEMORY_UDIMM_CAPABLE              BLDCFG_MEMORY_UDIMM_CAPABLE
#else
  #define CFG_MEMORY_UDIMM_CAPABLE              TRUE
#endif

#ifdef BLDCFG_MEMORY_SODIMM_CAPABLE
  #define CFG_MEMORY_SODIMM_CAPABLE             BLDCFG_MEMORY_SODIMM_CAPABLE
#else
  #define CFG_MEMORY_SODIMM_CAPABLE             FALSE
#endif

#ifdef BLDCFG_MEMORY_ENABLE_BANK_INTERLEAVING
  #define CFG_MEMORY_ENABLE_BANK_INTERLEAVING   BLDCFG_MEMORY_ENABLE_BANK_INTERLEAVING
#else
  #define CFG_MEMORY_ENABLE_BANK_INTERLEAVING   TRUE
#endif

#ifdef BLDCFG_MEMORY_ENABLE_NODE_INTERLEAVING
  #define CFG_MEMORY_ENABLE_NODE_INTERLEAVING   BLDCFG_MEMORY_ENABLE_NODE_INTERLEAVING
#else
  #define CFG_MEMORY_ENABLE_NODE_INTERLEAVING   FALSE
#endif

#ifdef BLDCFG_MEMORY_CHANNEL_INTERLEAVING
  #define CFG_MEMORY_CHANNEL_INTERLEAVING       BLDCFG_MEMORY_CHANNEL_INTERLEAVING
#else
  #define CFG_MEMORY_CHANNEL_INTERLEAVING       TRUE
#endif

#ifdef BLDCFG_MEMORY_POWER_DOWN
  #define CFG_MEMORY_POWER_DOWN                 BLDCFG_MEMORY_POWER_DOWN
#else
  #define CFG_MEMORY_POWER_DOWN                 TRUE
#endif

#ifdef BLDCFG_POWER_DOWN_MODE
  #define CFG_POWER_DOWN_MODE                   BLDCFG_POWER_DOWN_MODE
#else
  #define CFG_POWER_DOWN_MODE                   POWER_DOWN_BY_CHIP_SELECT
#endif

#ifdef BLDCFG_ONLINE_SPARE
  #define CFG_ONLINE_SPARE                      BLDCFG_ONLINE_SPARE
#else
  #define CFG_ONLINE_SPARE                      FALSE
#endif

#ifdef BLDCFG_MEMORY_PARITY_ENABLE
  #define CFG_MEMORY_PARITY_ENABLE              BLDCFG_MEMORY_PARITY_ENABLE
#else
  #define CFG_MEMORY_PARITY_ENABLE              FALSE
#endif

#ifdef BLDCFG_BANK_SWIZZLE
  #define CFG_BANK_SWIZZLE                      BLDCFG_BANK_SWIZZLE
#else
  #define CFG_BANK_SWIZZLE                      TRUE
#endif

#ifdef BLDCFG_TIMING_MODE_SELECT
  #define CFG_TIMING_MODE_SELECT                BLDCFG_TIMING_MODE_SELECT
#else
  #define CFG_TIMING_MODE_SELECT                TIMING_MODE_AUTO
#endif

#ifdef BLDCFG_MEMORY_CLOCK_SELECT
  #define CFG_MEMORY_CLOCK_SELECT               BLDCFG_MEMORY_CLOCK_SELECT
#else
  #define CFG_MEMORY_CLOCK_SELECT               DDR1333_FREQUENCY
#endif

#ifdef BLDCFG_DQS_TRAINING_CONTROL
  #define CFG_DQS_TRAINING_CONTROL              BLDCFG_DQS_TRAINING_CONTROL
#else
  #define CFG_DQS_TRAINING_CONTROL              TRUE
#endif

#if CONFIG(CPU_AMD_AGESA_OPENSOURCE_MEM_CUSTOM)
  #undef BLDCFG_IGNORE_SPD_CHECKSUM
  #define BLDCFG_IGNORE_SPD_CHECKSUM            TRUE
#endif

#ifdef BLDCFG_IGNORE_SPD_CHECKSUM
  #define CFG_IGNORE_SPD_CHECKSUM               BLDCFG_IGNORE_SPD_CHECKSUM
#else
  #define CFG_IGNORE_SPD_CHECKSUM               FALSE
#endif

#ifdef BLDCFG_USE_BURST_MODE
  #define CFG_USE_BURST_MODE                    BLDCFG_USE_BURST_MODE
#else
  #define CFG_USE_BURST_MODE                    FALSE
#endif

#ifdef BLDCFG_MEMORY_ALL_CLOCKS_ON
  #define CFG_MEMORY_ALL_CLOCKS_ON              BLDCFG_MEMORY_ALL_CLOCKS_ON
#else
  #define CFG_MEMORY_ALL_CLOCKS_ON              FALSE
#endif

#ifdef BLDCFG_ENABLE_ECC_FEATURE
  #define CFG_ENABLE_ECC_FEATURE                BLDCFG_ENABLE_ECC_FEATURE
#else
  #define CFG_ENABLE_ECC_FEATURE                TRUE
#endif

#ifdef BLDCFG_ECC_REDIRECTION
  #define CFG_ECC_REDIRECTION                   BLDCFG_ECC_REDIRECTION
#else
  #define CFG_ECC_REDIRECTION                   FALSE
#endif

#ifdef BLDCFG_SCRUB_DRAM_RATE
  #define CFG_SCRUB_DRAM_RATE         BLDCFG_SCRUB_DRAM_RATE
#else
  #define CFG_SCRUB_DRAM_RATE         (0)
#endif

#ifdef BLDCFG_SCRUB_L2_RATE
  #define CFG_SCRUB_L2_RATE           BLDCFG_SCRUB_L2_RATE
#else
  #define CFG_SCRUB_L2_RATE           (0)
#endif

#ifdef BLDCFG_SCRUB_L3_RATE
  #define CFG_SCRUB_L3_RATE           BLDCFG_SCRUB_L3_RATE
#else
  #define CFG_SCRUB_L3_RATE           (0)
#endif

#ifdef BLDCFG_SCRUB_IC_RATE
  #define CFG_SCRUB_IC_RATE           BLDCFG_SCRUB_IC_RATE
#else
  #define CFG_SCRUB_IC_RATE           (0)
#endif

#ifdef BLDCFG_SCRUB_DC_RATE
  #define CFG_SCRUB_DC_RATE           BLDCFG_SCRUB_DC_RATE
#else
  #define CFG_SCRUB_DC_RATE           (0)
#endif

#ifdef BLDCFG_ECC_SYNC_FLOOD
  #define CFG_ECC_SYNC_FLOOD          BLDCFG_ECC_SYNC_FLOOD
#else
  #define CFG_ECC_SYNC_FLOOD          FALSE
#endif

#ifdef BLDCFG_ECC_SYMBOL_SIZE
  #define CFG_ECC_SYMBOL_SIZE         BLDCFG_ECC_SYMBOL_SIZE
#else
  #define CFG_ECC_SYMBOL_SIZE         0
#endif

#ifdef BLDCFG_1GB_ALIGN
  #define CFG_1GB_ALIGN               BLDCFG_1GB_ALIGN
#else
  #define CFG_1GB_ALIGN               FALSE
#endif

#ifdef BLDCFG_UMA_ALLOCATION_MODE
  #define CFG_UMA_MODE                BLDCFG_UMA_ALLOCATION_MODE
#else
  #define CFG_UMA_MODE                UMA_AUTO
#endif

#ifdef BLDCFG_UMA_ALLOCATION_SIZE
  #define CFG_UMA_SIZE                BLDCFG_UMA_ALLOCATION_SIZE
#else
  #define CFG_UMA_SIZE                0
#endif

#ifdef BLDCFG_UMA_ABOVE4G_SUPPORT
  #define CFG_UMA_ABOVE4G           BLDCFG_UMA_ABOVE4G_SUPPORT
#else
  #define CFG_UMA_ABOVE4G           FALSE
#endif

#ifdef BLDCFG_UMA_ALIGNMENT
  #define CFG_UMA_ALIGNMENT           BLDCFG_UMA_ALIGNMENT
#else
  #define CFG_UMA_ALIGNMENT           NO_UMA_ALIGNED
#endif

#ifdef BLDCFG_PROCESSOR_SCOPE_IN_SB
  #define CFG_PROCESSOR_SCOPE_IN_SB   BLDCFG_PROCESSOR_SCOPE_IN_SB
#else
  #define CFG_PROCESSOR_SCOPE_IN_SB   FALSE
#endif

#ifdef BLDCFG_S3_LATE_RESTORE
  #define CFG_S3_LATE_RESTORE         BLDCFG_S3_LATE_RESTORE
#else
  #define CFG_S3_LATE_RESTORE         TRUE
#endif

#ifdef BLDCFG_USE_32_BYTE_REFRESH
  #define CFG_USE_32_BYTE_REFRESH  (BLDCFG_USE_32_BYTE_REFRESH)
#else
  #define CFG_USE_32_BYTE_REFRESH  (FALSE)
#endif

#ifdef BLDCFG_USE_VARIABLE_MCT_ISOC_PRIORITY
  #define CFG_USE_VARIABLE_MCT_ISOC_PRIORITY  (BLDCFG_USE_VARIABLE_MCT_ISOC_PRIORITY)
#else
  #define CFG_USE_VARIABLE_MCT_ISOC_PRIORITY  (FALSE)
#endif

#ifdef BLDCFG_PROCESSOR_SCOPE_NAME0
  #define CFG_PROCESSOR_SCOPE_NAME0          BLDCFG_PROCESSOR_SCOPE_NAME0
#else
  #define CFG_PROCESSOR_SCOPE_NAME0          SCOPE_NAME_VALUE
#endif

#ifdef BLDCFG_PROCESSOR_SCOPE_NAME1
  #define CFG_PROCESSOR_SCOPE_NAME1          BLDCFG_PROCESSOR_SCOPE_NAME1
#else
  #define CFG_PROCESSOR_SCOPE_NAME1          SCOPE_NAME_VALUE1
#endif

#ifdef BLDCFG_CFG_GNB_HD_AUDIO
  #define CFG_GNB_HD_AUDIO                   BLDCFG_CFG_GNB_HD_AUDIO
#else
  #define CFG_GNB_HD_AUDIO                   TRUE
#endif

#ifdef BLDCFG_CFG_ABM_SUPPORT
  #define CFG_ABM_SUPPORT                    BLDCFG_CFG_ABM_SUPPORT
#else
  #define CFG_ABM_SUPPORT                    FALSE
#endif

#ifdef BLDCFG_CFG_DYNAMIC_REFRESH_RATE
  #define CFG_DINAMIC_REFRESH_RATE           BLDCFG_CFG_DYNAMIC_REFRESH_RATE
#else
  #define CFG_DYNAMIC_REFRESH_RATE           0
#endif

#ifdef BLDCFG_CFG_LCD_BACK_LIGHT_CONTROL
  #define CFG_LCD_BACK_LIGHT_CONTROL         BLDCFG_CFG_LCD_BACK_LIGHT_CONTROL
#else
  #define CFG_LCD_BACK_LIGHT_CONTROL         0
#endif

#ifdef BLDCFG_STEREO_3D_PINOUT
  #define CFG_GNB_STEREO_3D_PINOUT           BLDCFG_STEREO_3D_PINOUT
#else
  #define CFG_GNB_STEREO_3D_PINOUT           0
#endif

#ifdef BLDCFG_IGPU_SUBSYSTEM_ID
  #define CFG_GNB_IGPU_SSID                  BLDCFG_IGPU_SUBSYSTEM_ID
#else
  #define CFG_GNB_IGPU_SSID                  0
#endif

#ifdef BLDCFG_IGPU_HD_AUDIO_SUBSYSTEM_ID
  #define CFG_GNB_HDAUDIO_SSID               BLDCFG_IGPU_HD_AUDIO_SUBSYSTEM_ID
#else
  #define CFG_GNB_HDAUDIO_SSID               0
#endif

#ifdef BLFCFG_APU_PCIE_PORTS_SUBSYSTEM_ID
  #define CFG_GNB_PCIE_SSID                  BLFCFG_APU_PCIE_PORTS_SUBSYSTEM_ID
#else
  #define CFG_GNB_PCIE_SSID                  0x12341022
#endif

#ifdef BLDCFG_GFX_LVDS_SPREAD_SPECTRUM
  #define CFG_GFX_LVDS_SPREAD_SPECTRUM               BLDCFG_GFX_LVDS_SPREAD_SPECTRUM
#else
  #define CFG_GFX_LVDS_SPREAD_SPECTRUM               0
#endif

#ifdef BLDCFG_GFX_LVDS_SPREAD_SPECTRUM_RATE
  #define CFG_GFX_LVDS_SPREAD_SPECTRUM_RATE               BLDCFG_GFX_LVDS_SPREAD_SPECTRUM_RATE
#else
  #define CFG_GFX_LVDS_SPREAD_SPECTRUM_RATE               0
#endif

#ifdef BLDCFG_PCIE_REFCLK_SPREAD_SPECTRUM
  #define CFG_PCIE_REFCLK_SPREAD_SPECTRUM               BLDCFG_PCIE_REFCLK_SPREAD_SPECTRUM
#else
  #define CFG_PCIE_REFCLK_SPREAD_SPECTRUM               0
#endif

#ifdef BLDCFG_CFG_TEMP_PCIE_MMIO_BASE_ADDRESS
  #define CFG_TEMP_PCIE_MMIO_BASE_ADDRESS    BLDCFG_CFG_TEMP_PCIE_MMIO_BASE_ADDRESS
#else
  #define CFG_TEMP_PCIE_MMIO_BASE_ADDRESS    0xD0000000
#endif

#ifdef BLDOPT_REMOVE_EARLY_SAMPLES
  #if  BLDOPT_REMOVE_EARLY_SAMPLES == TRUE
    #undef  OPTION_EARLY_SAMPLES
    #define OPTION_EARLY_SAMPLES        FALSE
  #else
    #undef  OPTION_EARLY_SAMPLES
    #define OPTION_EARLY_SAMPLES        TRUE
  #endif
#endif

#ifdef BLDOPT_REMOVE_ALIB
  #if  BLDOPT_REMOVE_ALIB == TRUE
    #undef  OPTION_ALIB
    #define OPTION_ALIB                 FALSE
  #else
    #undef  OPTION_ALIB
    #define OPTION_ALIB                 TRUE
  #endif
#endif

#ifdef BLDCFG_LVDS_MISC_888_FPDI_MODE
  #define CFG_LVDS_MISC_888_FPDI_MODE                 BLDCFG_LVDS_MISC_888_FPDI_MODE
#else
  #define CFG_LVDS_MISC_888_FPDI_MODE                 FALSE
#endif

#ifdef BLDCFG_LVDS_MISC_DL_CH_SWAP
  #define CFG_LVDS_MISC_DL_CH_SWAP                 BLDCFG_LVDS_MISC_DL_CH_SWAP
#else
  #define CFG_LVDS_MISC_DL_CH_SWAP                 FALSE
#endif

#ifdef BLDCFG_LVDS_MISC_VSYNC_ACTIVE_LOW
  #define CFG_LVDS_MISC_VSYNC_ACTIVE_LOW                 BLDCFG_LVDS_MISC_VSYNC_ACTIVE_LOW
#else
  #define CFG_LVDS_MISC_VSYNC_ACTIVE_LOW                 FALSE
#endif

#ifdef BLDCFG_LVDS_MISC_HSYNC_ACTIVE_LOW
  #define CFG_LVDS_MISC_HSYNC_ACTIVE_LOW                 BLDCFG_LVDS_MISC_HSYNC_ACTIVE_LOW
#else
  #define CFG_LVDS_MISC_HSYNC_ACTIVE_LOW                 FALSE
#endif

#ifdef BLDCFG_LVDS_MISC_BLON_ACTIVE_LOW
  #define CFG_LVDS_MISC_BLON_ACTIVE_LOW                 BLDCFG_LVDS_MISC_BLON_ACTIVE_LOW
#else
  #define CFG_LVDS_MISC_BLON_ACTIVE_LOW                 FALSE
#endif

#ifdef BLDCFG_PLATFORM_POWER_POLICY_MODE
  #define CFG_PLATFORM_POWER_POLICY_MODE  (BLDCFG_PLATFORM_POWER_POLICY_MODE)
#else
  #define CFG_PLATFORM_POWER_POLICY_MODE  (Performance)
#endif

#define CFG_PCI_MMIO_BASE                 (CONFIG_ECAM_MMCONF_BASE_ADDRESS)

#define CFG_PCI_MMIO_SIZE                 (CONFIG_ECAM_MMCONF_BUS_NUMBER)

#ifdef BLDCFG_AP_MTRR_SETTINGS_LIST
  #define CFG_AP_MTRR_SETTINGS_LIST           (BLDCFG_AP_MTRR_SETTINGS_LIST)
#else
  #define CFG_AP_MTRR_SETTINGS_LIST           (&OntarioApMtrrSettingsList)
#endif

/*---------------------------------------------------------------------------
 *       Processing the options:  Third, perform the option cross checks
 *--------------------------------------------------------------------------*/
// Check that deprecated options are not used
#ifdef BLDCFG_PCI_MMIO_BASE
  #error  BLDOPT: BLDCFG_PCI_MMIO_BASE has been deprecated in coreboot. Do not use!
#endif
#ifdef BLDCFG_PCI_MMIO_SIZE
  #error  BLDOPT: BLDCFG_PCI_MMIO_SIZE has been deprecated in coreboot. Do not use!
#endif
// Assure that at least one type of memory support is included
#if OPTION_UDIMMS == FALSE
  #if OPTION_RDIMMS == FALSE
    #if OPTION_SODIMMS == FALSE
      #if OPTION_LRDIMMS == FALSE
        #error  BLDOPT: No DIMM support selected. Either BLDOPT_REMOVE_UDIMMS_SUPPORT or BLDOPT_REMOVE_RDIMMS_SUPPORT or BLDOPT_REMOVE_SODIMMS_SUPPORT or BLDOPT_REMOVE_LRDIMMS_SUPPORT must be FALSE.
      #endif
    #endif
  #endif
#endif
// Ensure at least one dimm type is capable
#if CFG_MEMORY_RDIMM_CAPABLE == FALSE
  #if CFG_MEMORY_UDIMM_CAPABLE == FALSE
    #if CFG_MEMORY_SODIMM_CAPABLE == FALSE
      #if CFG_MEMORY_LRDIMM_CAPABLE == FALSE
        #error   BLDCFG: No dimm type is capable
      #endif
    #endif
  #endif
#endif
//  Turn off multi-socket based features if only one node...
#if OPTION_MULTISOCKET == FALSE
  #undef  OPTION_PARALLEL_TRAINING
  #define OPTION_PARALLEL_TRAINING    FALSE
  #undef  OPTION_NODE_INTERLEAVE
  #define OPTION_NODE_INTERLEAVE      FALSE
#endif
// Ensure that at least one write leveling option is selected
#if OPTION_DDR3 == TRUE
  #if OPTION_HW_WRITE_LEV_TRAINING == FALSE
    #if OPTION_SW_WRITE_LEV_TRAINING == FALSE
      #error  No Write leveling option selected for DDR3
    #endif
  #endif
  #if OPTION_SW_DRAM_INIT == FALSE
    #error   Software dram init must be enabled for DDR3 dimms
  #endif
#endif
// Ensure at least one DQS receiver training option is selected
#if OPTION_HW_DQS_REC_EN_TRAINING == FALSE
  #if OPTION_NON_OPT_SW_DQS_REC_EN_TRAINING == FALSE
    #if OPTION_OPT_SW_DQS_REC_EN_TRAINING == FALSE
      #error    No DQS receiver training option has been slected
    #endif
  #endif
#endif
// Ensure at least one Rd Wr position training option has been selected
#if OPTION_NON_OPT_SW_RD_WR_POS_TRAINING == FALSE
  #if OPTION_OPT_SW_RD_WR_POS_TRAINING == FALSE
    #error    No Rd Wr position training option has been selected
  #endif
#endif
// Ensure at least one dram init option has been selected
#if OPTION_HW_DRAM_INIT == FALSE
  #if OPTION_SW_DRAM_INIT == FALSE
    #error    No Dram init option has been selected
  #endif
#endif
// Ensure the frequency limit is valid
#if (CFG_MEMORY_BUS_FREQUENCY_LIMIT != DDR1866_FREQUENCY) && (CFG_MEMORY_BUS_FREQUENCY_LIMIT != 933)
  #if (CFG_MEMORY_BUS_FREQUENCY_LIMIT != DDR1600_FREQUENCY) && (CFG_MEMORY_BUS_FREQUENCY_LIMIT != 800)
    #if (CFG_MEMORY_BUS_FREQUENCY_LIMIT != DDR1333_FREQUENCY) && (CFG_MEMORY_BUS_FREQUENCY_LIMIT != 667)
      #if (CFG_MEMORY_BUS_FREQUENCY_LIMIT != DDR1066_FREQUENCY) && (CFG_MEMORY_BUS_FREQUENCY_LIMIT != 533)
        #if (CFG_MEMORY_BUS_FREQUENCY_LIMIT != DDR800_FREQUENCY) && (CFG_MEMORY_BUS_FREQUENCY_LIMIT != 400)
          #if (CFG_MEMORY_BUS_FREQUENCY_LIMIT != DDR667_FREQUENCY) && (CFG_MEMORY_BUS_FREQUENCY_LIMIT != 333)
            #if (CFG_MEMORY_BUS_FREQUENCY_LIMIT != DDR533_FREQUENCY) && (CFG_MEMORY_BUS_FREQUENCY_LIMIT != 266)
              #if (CFG_MEMORY_BUS_FREQUENCY_LIMIT != DDR400_FREQUENCY) && (CFG_MEMORY_BUS_FREQUENCY_LIMIT != 200)
                #error    BLDCFG: Unsupported memory bus frequency
              #endif
            #endif
          #endif
        #endif
      #endif
    #endif
  #endif
#endif
// Ensure timing mode is valid
#if CFG_TIMING_MODE_SELECT != TIMING_MODE_SPECIFIC
  #if CFG_TIMING_MODE_SELECT != TIMING_MODE_LIMITED
    #if CFG_TIMING_MODE_SELECT != TIMING_MODE_AUTO
      #error    BLDCFG: Invalid timing mode is set
    #endif
  #endif
#endif
// Ensure the scrub rate is valid
#if ((CFG_SCRUB_DRAM_RATE > 0x16) && (CFG_SCRUB_DRAM_RATE != 0xFF))
  #error    BLDCFG: Unsupported dram scrub rate set
#endif
#if CFG_SCRUB_L2_RATE > 0x16
  #error   BLDCFG: Unsupported L2 scrubber rate set
#endif
#if CFG_SCRUB_L3_RATE > 0x16
  #error   BLDCFG: unsupported L3 scrubber rate set
#endif
#if CFG_SCRUB_IC_RATE > 0x16
  #error    BLDCFG: Unsupported Instruction cache scrub rate set
#endif
#if CFG_SCRUB_DC_RATE > 0x16
  #error   BLDCFG: Unsupported Dcache scrub rate set
#endif
// Ensure Quad rank dimm type is valid
#if CFG_MEMORY_QUADRANK_TYPE != QUADRANK_UNBUFFERED
  #if CFG_MEMORY_QUADRANK_TYPE != QUADRANK_REGISTERED
    #error     BLDCFG: Invalid quad rank dimm type set
  #endif
#endif
// Ensure ECC symbol size is valid
#if CFG_ECC_SYMBOL_SIZE != ECCSYMBOLSIZE_USE_BKDG
  #if CFG_ECC_SYMBOL_SIZE != ECCSYMBOLSIZE_FORCE_X4
    #if CFG_ECC_SYMBOL_SIZE != ECCSYMBOLSIZE_FORCE_X8
      #error   BLDCFG: Invalid Ecc symbol size set
    #endif
  #endif
#endif
// Ensure power down mode is valid
#if CFG_POWER_DOWN_MODE != POWER_DOWN_BY_CHIP_SELECT
  #if CFG_POWER_DOWN_MODE != POWER_DOWN_BY_CHANNEL
    #error     BLDCFG: Invalid power down mode set
  #endif
#endif

/*****************************************************************************
 *
 * Process the option logic, setting local control variables
 *
 ****************************************************************************/
#if OPTION_ACPI_PSTATES == TRUE
  #define OPTFCN_ACPI_TABLES           CreateAcpiTablesMain
  #define OPTFCN_GATHER_DATA           PStateGatherData
  #if OPTION_MULTISOCKET == TRUE
    #define OPTFCN_PSTATE_LEVELING     PStateLeveling
  #else
    #define OPTFCN_PSTATE_LEVELING     CommonReturnAgesaSuccess
  #endif
#else
  #define OPTFCN_ACPI_TABLES           CommonReturnAgesaSuccess
  #define OPTFCN_GATHER_DATA           CommonReturnAgesaSuccess
  #define OPTFCN_PSTATE_LEVELING       CommonReturnAgesaSuccess
#endif


/*****************************************************************************
 *
 * Include the structure definitions for the defaults table structures
 *
 ****************************************************************************/
#include <CommonReturns.h>
#include <agesa-entry-cfg.h>
#include  "Options.h"
#include  "OptionCpuFamiliesInstall.h"
#include  "OptionsHt.h"
#include  "OptionHtInstall.h"
#include  "OptionMemory.h"
#include  "OptionMemoryInstall.h"
#include  "OptionCpuFeaturesInstall.h"
#include  "OptionDmi.h"
#include  "OptionDmiInstall.h"
#include  "OptionPstate.h"
#include  "OptionPstateInstall.h"
#include  "OptionWhea.h"
#include  "OptionWheaInstall.h"
#include  "OptionSrat.h"
#include  "OptionSratInstall.h"
#include  "OptionSlit.h"
#include  "OptionSlitInstall.h"
#include  "OptionMultiSocket.h"
#include  "OptionMultiSocketInstall.h"
#include  "OptionIdsInstall.h"
#include  "OptionGfxRecovery.h"
#include  "OptionGfxRecoveryInstall.h"
#include  "OptionGnb.h"
#include  "OptionGnbInstall.h"
#include  "OptionS3ScriptInstall.h"


/*****************************************************************************
 *
 *  Generate the output structures (defaults tables)
 *
 ****************************************************************************/
CONST BUILD_OPT_CFG UserOptions = {
  {                                             // AGESA version string
    AGESA_CODE_SIGNATURE,                       //    code header Signature
    AGESA_PACKAGE_STRING,                       //    8 character ID
    AGESA_VERSION_STRING,                       //    12 character version string
    0                                           //    null string terminator
  },
  //Build Option Area
  OPTION_UDIMMS,                        //UDIMMS
  OPTION_RDIMMS,                        //RDIMMS
  OPTION_LRDIMMS,                       //LRDIMMS
  OPTION_ECC,                           //ECC
  OPTION_BANK_INTERLEAVE,               //BANK_INTERLEAVE
  OPTION_DCT_INTERLEAVE,                //DCT_INTERLEAVE
  OPTION_NODE_INTERLEAVE,               //NODE_INTERLEAVE
  OPTION_PARALLEL_TRAINING,             //PARALLEL_TRAINING
  OPTION_ONLINE_SPARE,                  //ONLINE_SPARE
  OPTION_MEM_RESTORE,                   //MEM CONTEXT RESTORE
  OPTION_MULTISOCKET,                   //MULTISOCKET
  OPTION_ACPI_PSTATES,                  //ACPI_PSTATES
  OPTION_SRAT,                          //SRAT
  OPTION_SLIT,                          //SLIT
  OPTION_WHEA,                          //WHEA
  OPTION_DMI,                           //DMI
  OPTION_EARLY_SAMPLES,                 //EARLY_SAMPLES
  OPTION_ADDR_TO_CS_TRANSLATOR,         //ADDR_TO_CS_TRANSLATOR

  //Build Configuration Area
  CFG_PCI_MMIO_BASE,
  CFG_PCI_MMIO_SIZE,
  {
    // CoreVrm
    {
      CFG_VRM_CURRENT_LIMIT,              // VrmCurrentLimit
      CFG_VRM_LOW_POWER_THRESHOLD,        // VrmLowPowerThershold
      CFG_VRM_SLEW_RATE,                  // VrmSlewRate
      CFG_VRM_ADDITIONAL_DELAY,           // VrmAdditionalDelay
      CFG_VRM_HIGH_SPEED_ENABLE,          // VrmHiSpeedEnable
      CFG_VRM_INRUSH_CURRENT_LIMIT        // VrmInrushCurrentLimit
    },
    // NbVrm
    {
      CFG_VRM_NB_CURRENT_LIMIT,           // VrmNbCurrentLimit
      CFG_VRM_NB_LOW_POWER_THRESHOLD,     // VrmNbLowPowerThershold
      CFG_VRM_NB_SLEW_RATE,               // VrmNbSlewRate
      CFG_VRM_NB_ADDITIONAL_DELAY,        // VrmNbAdditionalDelay
      CFG_VRM_NB_HIGH_SPEED_ENABLE,       // VrmNbHiSpeedEnable
      CFG_VRM_NB_INRUSH_CURRENT_LIMIT     // VrmNbInrushCurrentLimit
    }
  },
  CFG_PLAT_NUM_IO_APICS,                //PlatformApicIoNumber
  CFG_MEM_INIT_PSTATE,                  //MemoryInitPstate
  CFG_C1E_MODE,                         //C1eMode
  CFG_C1E_OPDATA,                       //C1ePlatformData
  CFG_C1E_OPDATA1,                      //C1ePlatformData1
  CFG_C1E_OPDATA2,                      //C1ePlatformData2
  CFG_CSTATE_MODE,                      //CStateMode
  CFG_CSTATE_OPDATA,                    //CStatePlatformData
  CFG_CSTATE_IO_BASE_ADDRESS,           //CStateIoBaseAddress
  CFG_CPB_MODE,                         //CpbMode
  CFG_CORE_LEVELING_MODE,               //CoreLevelingCofig
  {
    CFG_PLATFORM_CONTROL_FLOW_MODE,       // The platform's control flow mode.
    CFG_USE_HT_ASSIST,                    // CfgUseHtAssist
    CFG_USE_ATM_MODE,                     // CfgUseAtmMode
    CFG_USE_32_BYTE_REFRESH,              // Display Refresh uses 32 byte packets.
    CFG_USE_VARIABLE_MCT_ISOC_PRIORITY,   // The Memory controller will be set to Variable Isoc Priority.
    CFG_PLATFORM_POWER_POLICY_MODE        // The platform's power policy mode.
  },
  (CPU_HT_DEEMPHASIS_LEVEL *)CFG_PLATFORM_DEEMPHASIS_LIST,         // Deemphasis settings
  CFG_AMD_PLATFORM_TYPE,                //AmdPlatformType
  CFG_AMD_PSTATE_CAP_VALUE,             // Amd pstate ceiling enabling deck

  CFG_MEMORY_BUS_FREQUENCY_LIMIT,       // CfgMemoryBusFrequencyLimit
  CFG_MEMORY_MODE_UNGANGED,             // CfgMemoryModeUnganged
  CFG_MEMORY_QUAD_RANK_CAPABLE,         // CfgMemoryQuadRankCapable
  CFG_MEMORY_QUADRANK_TYPE,             // CfgMemoryQuadrankType
  CFG_MEMORY_RDIMM_CAPABLE,             // CfgMemoryRDimmCapable
  CFG_MEMORY_LRDIMM_CAPABLE,            // CfgMemoryLRDimmCapable
  CFG_MEMORY_UDIMM_CAPABLE,             // CfgMemoryUDimmCapable
  CFG_MEMORY_SODIMM_CAPABLE,            // CfgMemorySodimmCapable
  CFG_MEMORY_ENABLE_BANK_INTERLEAVING,  // CfgMemoryEnableBankInterleaving
  CFG_MEMORY_ENABLE_NODE_INTERLEAVING,  // CfgMemoryEnableNodeInterleaving
  CFG_MEMORY_CHANNEL_INTERLEAVING,      // CfgMemoryChannelInterleaving
  CFG_MEMORY_POWER_DOWN,                // CfgMemoryPowerDown
  CFG_POWER_DOWN_MODE,                  // CfgPowerDownMode
  CFG_ONLINE_SPARE,                     // CfgOnlineSpare
  CFG_MEMORY_PARITY_ENABLE,             // CfgMemoryParityEnable
  CFG_BANK_SWIZZLE,                     // CfgBankSwizzle
  CFG_TIMING_MODE_SELECT,               // CfgTimingModeSelect
  CFG_MEMORY_CLOCK_SELECT,              // CfgMemoryClockSelect
  CFG_DQS_TRAINING_CONTROL,             // CfgDqsTrainingControl
  CFG_IGNORE_SPD_CHECKSUM,              // CfgIgnoreSpdChecksum
  CFG_USE_BURST_MODE,                   // CfgUseBurstMode
  CFG_MEMORY_ALL_CLOCKS_ON,             // CfgMemoryAllClocksOn
  CFG_ENABLE_ECC_FEATURE,               // CfgEnableEccFeature
  CFG_ECC_REDIRECTION,                  // CfgEccRedirection
  CFG_SCRUB_DRAM_RATE,                  // CfgScrubDramRate
  CFG_SCRUB_L2_RATE,                    // CfgScrubL2Rate
  CFG_SCRUB_L3_RATE,                    // CfgScrubL3Rate
  CFG_SCRUB_IC_RATE,                    // CfgScrubIcRate
  CFG_SCRUB_DC_RATE,                    // CfgScrubDcRate
  CFG_ECC_SYNC_FLOOD,                   // CfgEccSyncFlood
  CFG_ECC_SYMBOL_SIZE,                  // CfgEccSymbolSize
  CFG_HEAP_DRAM_ADDRESS,                // CfgHeapDramAddress
  CFG_1GB_ALIGN,                        // CfgNodeMem1GBAlign
  CFG_S3_LATE_RESTORE,                  // CfgS3LateRestore
  CFG_ACPI_PSTATE_PSD_INDPX,            // CfgAcpiPstateIndependent
  (AP_MTRR_SETTINGS *) CFG_AP_MTRR_SETTINGS_LIST, // CfgApMtrrSettingsList
  CFG_UMA_MODE,                         // CfgUmaMode
  CFG_UMA_SIZE,                         // CfgUmaSize
  CFG_UMA_ABOVE4G,                      // CfgUmaAbove4G
  CFG_UMA_ALIGNMENT,                    // CfgUmaAlignment
  CFG_PROCESSOR_SCOPE_IN_SB,            // CfgProcessorScopeInSb
  CFG_PROCESSOR_SCOPE_NAME0,            // CfgProcessorScopeName0
  CFG_PROCESSOR_SCOPE_NAME1,            // CfgProcessorScopeName1
  CFG_GNB_HD_AUDIO,                     // CfgGnbHdAudio
  CFG_ABM_SUPPORT,                      // CfgAbmSupport
  CFG_DYNAMIC_REFRESH_RATE,             // CfgDynamicRefreshRate
  CFG_LCD_BACK_LIGHT_CONTROL,           // CfgLcdBackLightControl
  CFG_GNB_STEREO_3D_PINOUT,             // CfgGnb3dStereoPinIndex
  CFG_TEMP_PCIE_MMIO_BASE_ADDRESS,      // CfgTempPcieMmioBaseAddress
  CFG_GNB_IGPU_SSID,                    // CfgGnbIGPUSSID
  CFG_GNB_HDAUDIO_SSID,                 // CfgGnbHDAudioSSID
  CFG_GNB_PCIE_SSID,                    // CfgGnbPcieSSID
  CFG_GFX_LVDS_SPREAD_SPECTRUM,         // CfgLvdsSpreadSpectrum
  CFG_GFX_LVDS_SPREAD_SPECTRUM_RATE,    // CfgLvdsSpreadSpectrumRate

  {{
	CFG_LVDS_MISC_888_FPDI_MODE,          // CfgLvdsMiscControl
	CFG_LVDS_MISC_DL_CH_SWAP,             // CfgLvdsMiscControl
	CFG_LVDS_MISC_VSYNC_ACTIVE_LOW,       // CfgLvdsMiscControl
	CFG_LVDS_MISC_HSYNC_ACTIVE_LOW,       // CfgLvdsMiscControl
	CFG_LVDS_MISC_BLON_ACTIVE_LOW,        // CfgLvdsMiscControl
  }},
  CFG_PCIE_REFCLK_SPREAD_SPECTRUM,      // CfgPcieRefClkSpreadSpectrum
  0,                                    //reserved...
};


CONST DISPATCH_TABLE ROMDATA ApDispatchTable[] =
{
  IDS_LATE_RUN_AP_TASK
  // Get DMI info
  CPU_DMI_AP_GET_TYPE4_TYPE7
  // Probe filter enable
  HT_ASSIST_AP_DISABLE_CACHE
  HT_ASSIST_AP_ENABLE_CACHE

  { 0, NULL }
};

#if AGESA_ENTRY_INIT_RESET == TRUE
  #if IDSOPT_IDS_ENABLED == TRUE
    #if IDSOPT_TRACING_ENABLED == TRUE
      #define MAKE_DBG_STR(x, y)  MAKE_AS_A_STRING(x : y)
      CONST CHAR8 * CONST BldOptDebugOutput[] = {
        #if IDS_TRACE_SHOW_BLD_OPT_CFG == TRUE
          //Build Option Area
          MAKE_DBG_STR (\nOptUDIMM,             OPTION_UDIMMS)
          MAKE_DBG_STR (\nOptRDIMM,             OPTION_RDIMMS)
          MAKE_DBG_STR (\nOptLRDIMM,            OPTION_LRDIMMS)
          MAKE_DBG_STR (\nOptECC,               OPTION_ECC)
          MAKE_DBG_STR (\nOptCsIntlv,           OPTION_BANK_INTERLEAVE)
          MAKE_DBG_STR (\nOptDctIntlv,          OPTION_DCT_INTERLEAVE)
          MAKE_DBG_STR (\nOptNodeIntlv,         OPTION_NODE_INTERLEAVE)
          //MAKE_DBG_STR (\nOptParallelTraining,  OPTION_PARALLEL_TRAINING)
          MAKE_DBG_STR (\nOptOnlineSpare,       OPTION_ONLINE_SPARE)
          MAKE_DBG_STR (\nOptAddr2CsTranslator, OPTION_ADDR_TO_CS_TRANSLATOR)
          MAKE_DBG_STR (\nOptMemRestore,        OPTION_MEM_RESTORE)
          MAKE_DBG_STR (\nOptMultiSocket,       OPTION_MULTISOCKET)
          MAKE_DBG_STR (\nOptPstates,           OPTION_ACPI_PSTATES)
          MAKE_DBG_STR (\nOptSRAT,              OPTION_SRAT)
          MAKE_DBG_STR (\nOptSLIT,              OPTION_SLIT)
          MAKE_DBG_STR (\nOptWHEA,              OPTION_WHEA)
          MAKE_DBG_STR (\nOptDMI,               OPTION_DMI)
          MAKE_DBG_STR (\nOptEarlySamples,      OPTION_EARLY_SAMPLES),

          //Build Configuration Area
          // CoreVrm
          MAKE_DBG_STR (\nVrmCurrentLimit      , CFG_VRM_CURRENT_LIMIT)
          MAKE_DBG_STR (\nVrmLowPowerThreshold , CFG_VRM_LOW_POWER_THRESHOLD)
          MAKE_DBG_STR (\nVrmSlewRate          , CFG_VRM_SLEW_RATE)
          MAKE_DBG_STR (\nVrmAdditionalDelay   , CFG_VRM_ADDITIONAL_DELAY)
          MAKE_DBG_STR (\nVrmHiSpeedEnable     , CFG_VRM_HIGH_SPEED_ENABLE)
          MAKE_DBG_STR (\nVrmInrushCurrentLimit, CFG_VRM_INRUSH_CURRENT_LIMIT)
          // NbVrm
          MAKE_DBG_STR (\nNbVrmCurrentLimit      , CFG_VRM_NB_CURRENT_LIMIT)
          MAKE_DBG_STR (\nNbVrmLowPowerThreshold , CFG_VRM_NB_LOW_POWER_THRESHOLD)
          MAKE_DBG_STR (\nNbVrmSlewRate          , CFG_VRM_NB_SLEW_RATE)
          MAKE_DBG_STR (\nNbVrmAdditionalDelay   , CFG_VRM_NB_ADDITIONAL_DELAY)
          MAKE_DBG_STR (\nNbVrmHiSpeedEnable     , CFG_VRM_NB_HIGH_SPEED_ENABLE)
          MAKE_DBG_STR (\nNbVrmInrushCurrentLimit, CFG_VRM_NB_INRUSH_CURRENT_LIMIT),

          MAKE_DBG_STR (\nNumIoApics            , CFG_PLAT_NUM_IO_APICS)
          MAKE_DBG_STR (\nMemInitPstate         , CFG_MEM_INIT_PSTATE)
          MAKE_DBG_STR (\nC1eMode               , CFG_C1E_MODE)
          MAKE_DBG_STR (\nC1eOpData             , CFG_C1E_OPDATA)
          MAKE_DBG_STR (\nC1eOpdata1            , CFG_C1E_OPDATA1)
          MAKE_DBG_STR (\nC1eOpdata2            , CFG_C1E_OPDATA2)
          MAKE_DBG_STR (\nCStateMode            , CFG_CSTATE_MODE)
          MAKE_DBG_STR (\nCStateOpData          , CFG_CSTATE_OPDATA)
          MAKE_DBG_STR (\nCStateIoBaseAddr      , CFG_CSTATE_IO_BASE_ADDRESS)
          MAKE_DBG_STR (\nCpbMode               , CFG_CPB_MODE)
          MAKE_DBG_STR (\nCoreLevelingMode      , CFG_CORE_LEVELING_MODE),

          MAKE_DBG_STR (\nControlFlowMode       , CFG_PLATFORM_CONTROL_FLOW_MODE)
          MAKE_DBG_STR (\nUseHtAssist           , CFG_USE_HT_ASSIST)
          MAKE_DBG_STR (\nUseAtmMode            , CFG_USE_ATM_MODE)
          MAKE_DBG_STR (\nUse32ByteRefresh      , CFG_USE_32_BYTE_REFRESH)
          MAKE_DBG_STR (\nUseVarMctIsocPriority , CFG_USE_VARIABLE_MCT_ISOC_PRIORITY)
          MAKE_DBG_STR (\nPowerPolicy           , CFG_PLATFORM_POWER_POLICY_MOD)

          MAKE_DBG_STR (\nDeemphasisList        , CFG_PLATFORM_DEEMPHASIS_LIST)

          MAKE_DBG_STR (\nPciMmioAddr           , CFG_PCI_MMIO_BASE)
          MAKE_DBG_STR (\nPciMmioSize           , CFG_PCI_MMIO_SIZE)
          MAKE_DBG_STR (\nPlatformType          , CFG_AMD_PLATFORM_TYPE)
          MAKE_DBG_STR (\nPstateCapValue        , CFG_AMD_PSTATE_CAP_VALUE),

          MAKE_DBG_STR (\nMemBusFreqLimit       , CFG_MEMORY_BUS_FREQUENCY_LIMIT)
          MAKE_DBG_STR (\nTimingModeSelect      , CFG_TIMING_MODE_SELECT)
          MAKE_DBG_STR (\nMemoryClockSelect     , CFG_MEMORY_CLOCK_SELECT)

          MAKE_DBG_STR (\nMemUnganged           , CFG_MEMORY_MODE_UNGANGED)
          MAKE_DBG_STR (\nQRCap                 , CFG_MEMORY_QUAD_RANK_CAPABLE)
          MAKE_DBG_STR (\nQRType                , CFG_MEMORY_QUADRANK_TYPE)
          MAKE_DBG_STR (\nRDimmCap              , CFG_MEMORY_RDIMM_CAPABLE)
          MAKE_DBG_STR (\nLRDimmCap             , CFG_MEMORY_LRDIMM_CAPABLE)
          MAKE_DBG_STR (\nUDimmCap              , CFG_MEMORY_UDIMM_CAPABLE)
          MAKE_DBG_STR (\nSODimmCap             , CFG_MEMORY_SODIMM_CAPABLE)
          MAKE_DBG_STR (\nDqsTrainingControl    , CFG_DQS_TRAINING_CONTROL)
          MAKE_DBG_STR (\nIgnoreSpdChecksum     , CFG_IGNORE_SPD_CHECKSUM)
          MAKE_DBG_STR (\nUseBurstMode          , CFG_USE_BURST_MODE)
          MAKE_DBG_STR (\nAllMemClkOn           , CFG_MEMORY_ALL_CLOCKS_ON),

          MAKE_DBG_STR (\nPowerDownEn           , CFG_MEMORY_POWER_DOWN)
          MAKE_DBG_STR (\nPowerDownMode         , CFG_POWER_DOWN_MODE)
          MAKE_DBG_STR (\nOnlineSpare           , CFG_ONLINE_SPARE)
          MAKE_DBG_STR (\nAddrParityEn          , CFG_MEMORY_PARITY_ENABLE)
          MAKE_DBG_STR (\nBankSwizzle           , CFG_BANK_SWIZZLE)
          MAKE_DBG_STR (\nCsIntlvEn             , CFG_MEMORY_ENABLE_BANK_INTERLEAVING)
          MAKE_DBG_STR (\nNodeIntlvEn           , CFG_MEMORY_ENABLE_NODE_INTERLEAVING)
          MAKE_DBG_STR (\nDctIntlvEn            , CFG_MEMORY_CHANNEL_INTERLEAVING),

          MAKE_DBG_STR (\nUmaMode                , CFG_UMA_MODE)
          MAKE_DBG_STR (\nUmaSize                , CFG_UMA_SIZE)
          MAKE_DBG_STR (\nUmaAbove4G             , CFG_UMA_ABOVE4G)
          MAKE_DBG_STR (\nUmaAlignment           , CFG_UMA_ALIGNMENT)

          MAKE_DBG_STR (\nEccEn                 , CFG_ENABLE_ECC_FEATURE)
          MAKE_DBG_STR (\nEccRedirect           , CFG_ECC_REDIRECTION)
          MAKE_DBG_STR (\nScrubDramRate         , CFG_SCRUB_DRAM_RATE)
          MAKE_DBG_STR (\nScrubL2Rate           , CFG_SCRUB_L2_RATE)
          MAKE_DBG_STR (\nScrubL3Rate           , CFG_SCRUB_L3_RATE)
          MAKE_DBG_STR (\nScrubIcRate           , CFG_SCRUB_IC_RATE)
          MAKE_DBG_STR (\nScrubDcRate           , CFG_SCRUB_DC_RATE)
          MAKE_DBG_STR (\nEccSyncFlood          , CFG_ECC_SYNC_FLOOD)
          MAKE_DBG_STR (\nEccSymbolSize         , CFG_ECC_SYMBOL_SIZE)
          MAKE_DBG_STR (\nHeapDramAddress       , CFG_HEAP_DRAM_ADDRESS)
          MAKE_DBG_STR (\nNodeMem1GBAlign       , CFG_1GB_ALIGN),

          MAKE_DBG_STR (\nS3LateRestore         , CFG_S3_LATE_RESTORE)
          MAKE_DBG_STR (\nAcpiPstateIndependent , CFG_ACPI_PSTATE_PSD_INDPX)

          MAKE_DBG_STR (\nApMtrrSettingsList     , CFG_AP_MTRR_SETTINGS_LIST)

          MAKE_DBG_STR (\nProcessorScopeInSb     , CFG_PROCESSOR_SCOPE_IN_SB)
          MAKE_DBG_STR (\nProcessorScopeName0    , CFG_PROCESSOR_SCOPE_NAME0)
          MAKE_DBG_STR (\nProcessorScopeName1    , CFG_PROCESSOR_SCOPE_NAME1)
          MAKE_DBG_STR (\nGnbHdAudio             , CFG_GNB_HD_AUDIO)
          MAKE_DBG_STR (\nAbmSupport             , CFG_ABM_SUPPORT)
          MAKE_DBG_STR (\nDynamicRefreshRate     , CFG_DYNAMIC_REFRESH_RATE)
          MAKE_DBG_STR (\nLcdBackLightControl    , CFG_LCD_BACK_LIGHT_CONTROL)
          MAKE_DBG_STR (\nGnb3dStereoPinIndex    , CFG_GNB_STEREO_3D_PINOUT)
          MAKE_DBG_STR (\nTempPcieMmioBaseAddress, CFG_TEMP_PCIE_MMIO_BASE_ADDRESS),
          MAKE_DBG_STR (\nCfgGnbIGPUSSID         , CFG_GNB_IGPU_SSID),
          MAKE_DBG_STR (\nCfgGnbHDAudioSSID      , CFG_GNB_HDAUDIO_SSID),
          MAKE_DBG_STR (\nCfgGnbPcieSSID         , CFG_GNB_PCIE_SSID),

          MAKE_DBG_STR (\nCfgLvdsSpreadSpectrum  , CFG_GFX_LVDS_SPREAD_SPECTRUM),
          MAKE_DBG_STR (\nCfgLvdsSpreadSpectrumRate , CFG_GFX_LVDS_SPREAD_SPECTRUM_RATE),
          MAKE_DBG_STR (\nCfgLvdsMiscControl.FpdiMode   , CFG_LVDS_MISC_888_FPDI_MODE),
          MAKE_DBG_STR (\nCfgLvdsMiscControl.DlChSwap           , CFG_LVDS_MISC_DL_CH_SWAP),
          MAKE_DBG_STR (\nCfgLvdsMiscControl.VsyncActiveLow     , CFG_LVDS_MISC_VSYNC_ACTIVE_LOW),
          MAKE_DBG_STR (\nCfgLvdsMiscControl.HsyncActiveLow     , CFG_LVDS_MISC_HSYNC_ACTIVE_LOW),
          MAKE_DBG_STR (\nCfgLvdsMiscControl.BLONActiveLow      , CFG_LVDS_MISC_BLON_ACTIVE_LOW),
          MAKE_DBG_STR (\nCfgPcieRefClkSpreadSpectrum   , CFG_PCIE_REFCLK_SPREAD_SPECTRUM),
        #endif
        NULL
      };
    #endif
  #endif
#endif
