// SPDX-License-Identifier: GPL-2.0

#include "linux/mod_devicetable.h"
#include <linux/bits.h>
#include <linux/device.h>
#include <linux/hw_random.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/arm-smccc.h>

#define MT67XX_RNG_MAGIC	0x74726e67

#ifdef CONFIG_ARM64
#define MTK_SIP_KERNEL_GET_RND (0x8200026a | 0x40000000)
#else
#define MTK_SIP_KERNEL_GET_RND 0x8200026a
#endif


static int mtk_trng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
	struct arm_smccc_res res;
	unsigned int buf[4] = { 0 };
	unsigned int copied = 0;

	while (copied < max) {
	  arm_smccc_smc(MTK_SIP_KERNEL_GET_RND, MT67XX_RNG_MAGIC, 0, 0, 0, 0, 0, 0, &res);
	  buf[0] = res.a0;
	  buf[1] = res.a1;
	  buf[2] = res.a2;
	  buf[3] = res.a3;

    if (unlikely(max - copied < 0))
      panic("trng sanity check failed"); 

	  memcpy(data, buf, min(sizeof(buf), max - copied));
	  data += sizeof(buf);
	  copied += sizeof(buf);
	}

	return copied;
}

static int mtk_trng_probe(struct platform_device *pdev)
{
	struct hwrng *trng;

	trng = devm_kzalloc(&pdev->dev, sizeof(*trng), GFP_KERNEL);
	if (!trng)
		return -ENOMEM;

	trng->name = "mtk_trng";
	trng->read = mtk_trng_read;
	trng->quality = 900;

	pr_err("mtk_trng ok\n");

	return devm_hwrng_register(&pdev->dev, trng);
}

static const struct of_device_id mtk_trng_match[] = {
	{ .compatible = "mediatek,trng" },
	{},
};
MODULE_DEVICE_TABLE(of, mtk_trng_match);


static struct platform_driver mtk_trng_driver = {
	.driver = {
		.name		= "mtk_trng",
		.of_match_table = mtk_trng_match,
	},
	.probe		= mtk_trng_probe,
};
module_platform_driver(mtk_trng_driver);

MODULE_ALIAS("platform:mtk_trng");
MODULE_DESCRIPTION("MediaTek TRNG firmware interface support");
MODULE_LICENSE("GPL");

