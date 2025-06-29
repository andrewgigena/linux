/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __SOC_MEDIATEK_MT6768_PM_DOMAINS_H
#define __SOC_MEDIATEK_MT6768_PM_DOMAINS_H

#include "linux/soc/mediatek/infracfg.h"
#include "mtk-pm-domains.h"
#include <dt-bindings/power/mt6768-power.h>

/*
 * MT6768 power domain support
 */

static const struct scpsys_domain_data scpsys_domain_data_mt6768[] = {
	[MT6768_POWER_DOMAIN_MD1] = {
		.name = "md1",
		.sta_mask = BIT(0),
		.ctl_offs = 0x0320,
		/*.ext_buck_iso_offs = 0x398,
		.ext_buck_iso_mask = 0x3, // BIT(0)?*/
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = GENMASK(8, 8), // ???
		.sram_pdn_ack_bits = 0,
		/*.bp_cfg = {
			BUS_PROT_WR_IGN(INFRA, MT6768_TOP_AXI_PROT_EN_MD,
			      MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR,
				    MT8183_TOP_AXI_PROT_EN_STA1),
		},*/
	},
	[MT6768_POWER_DOMAIN_CONN] = {
		.name = "conn",
		.sta_mask = PWR_STATUS_CONN,
		.ctl_offs = 0x032c,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = 0,
		.sram_pdn_ack_bits = 0,
		/*.bp_cfg = {
			BUS_PROT_WR(INFRA,
				    MT6768_TOP_AXI_PROT_EN_CONN,
				    MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR,
				    MT8183_TOP_AXI_PROT_EN_STA1),
		},*/
		.caps = MTK_SCPD_KEEP_DEFAULT_OFF,
	},
	[MT6768_POWER_DOMAIN_DPY] = {
		.name = "dpy",
		.sta_mask = BIT(2),
		.ctl_offs = 0x031c,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = GENMASK(11, 8), // ???
		.sram_pdn_ack_bits = GENMASK(15, 12), // ???
		/*.bp_cfg = {
			BUS_PROT_WR(INFRA,
			      MT6768_TOP_AXI_PROT_EN_DPY,
			      MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR,
				    MT8183_TOP_AXI_PROT_EN_STA1),
		},*/
	},
	[MT6768_POWER_DOMAIN_DISP] = {
		.name = "disp",
		.sta_mask = PWR_STATUS_ISP,
		.ctl_offs = 0x030c,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_cfg = {
			BUS_PROT_WR(INFRA,
				    MT6768_TOP_AXI_PROT_EN_1_DISP,
				    MT8183_TOP_AXI_PROT_EN_1_SET,
				    MT8183_TOP_AXI_PROT_EN_1_CLR,
				    MT8183_TOP_AXI_PROT_EN_STA1_1),
			BUS_PROT_WR(INFRA,
				    MT8183_TOP_AXI_PROT_EN_DISP, // step 3
				    MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR,
				    MT8183_TOP_AXI_PROT_EN_STA1),
		},
	},
	[MT6768_POWER_DOMAIN_MFG] = {
		.name = "mfg",
		.sta_mask = BIT(11),
		.ctl_offs = 0x338,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT6768_POWER_DOMAIN_ISP] = {
		.name = "isp",
		.sta_mask = BIT(6),
		.ctl_offs = 0x0308,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		/*.bp_cfg = {
			BUS_PROT_WR_IGN(INFRA,
				    MT6768_TOP_AXI_PROT_EN_MM_ISP,
				    MT8183_TOP_AXI_PROT_EN_MM_SET,
				    MT8183_TOP_AXI_PROT_EN_MM_CLR,
				    MT8183_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR_IGN(INFRA,
					MT6768_TOP_AXI_PROT_EN_MM_ISP_2ND,
					MT8183_TOP_AXI_PROT_EN_MM_SET,
					MT8183_TOP_AXI_PROT_EN_MM_CLR,
					MT8183_TOP_AXI_PROT_EN_MM_STA1),
		},*/
	},

	[MT6768_POWER_DOMAIN_IFR] = {
		.name = "ifr",
		.sta_mask = BIT(3),
		.ctl_offs = 0x318,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT6768_POWER_DOMAIN_MFG_CORE0] = {
		.name = "mfg_core0",
		.sta_mask = BIT(12),
		.ctl_offs = 0x034c,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT6768_POWER_DOMAIN_MFG_CORE1] = {
		.name = "mfg_core1",
		.sta_mask = BIT(13),
		.ctl_offs = 0x0310,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT6768_POWER_DOMAIN_MFG_ASYNC] = {
		.name = "mfg_async",
		.sta_mask = PWR_STATUS_MFG_ASYNC, // 14 in downstream
		.ctl_offs = 0x0334,
		.pwr_sta_offs = 0x0180,
		.pwr_sta2nd_offs = 0x0184,
		.sram_pdn_bits = 0,
		.sram_pdn_ack_bits = 0,
		//.caps = MTK_SCPD_DOMAIN_SUPPLY,
	},
	// TODO: camera, vcodec
};

static const struct scpsys_soc_data mt6768_scpsys_data = {
	.domains_data = scpsys_domain_data_mt6768,
	.num_domains = ARRAY_SIZE(scpsys_domain_data_mt6768),
};

#endif /* __SOC_MEDIATEK_MT8183_PM_DOMAINS_H */
