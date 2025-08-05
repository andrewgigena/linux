// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2025 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <video/mipi_display.h>

#include <drm/display/drm_dsc.h>
#include <drm/display/drm_dsc_helper.h>
#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct nt37280_lh568wf3_ed01 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct drm_dsc_config dsc;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data nt37280_lh568wf3_ed01_supplies[] = {
	{ .supply = "vddio" },
	{ .supply = "vci" },
};

static inline struct nt37280_lh568wf3_ed01 *to_nt37280_lh568wf3_ed01(struct drm_panel *panel)
{
	return container_of(panel, struct nt37280_lh568wf3_ed01, panel);
}

static void nt37280_lh568wf3_ed01_reset(struct nt37280_lh568wf3_ed01 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(1000, 2000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
}

static int nt37280_lh568wf3_ed01_on(struct nt37280_lh568wf3_ed01 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0xe0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x28, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x89, 0x7f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0d, 0x9b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x27);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc9, 0x0d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xca, 0x0a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcb, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcc, 0xf9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcd, 0x0a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcf, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd0, 0x35);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd1, 0x05);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd3, 0x0d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd4, 0x0a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd5, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd6, 0xf9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd7, 0x0a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd9, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xda, 0x35);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdb, 0x05);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdc, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x2c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb4,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0xe6, 0x01, 0xce,
				     0x02, 0x26);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb5,
				     0x02, 0x3a, 0x02, 0x3a, 0x02, 0x3a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb8,
				     0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02,
				     0x40, 0x02, 0x40, 0x01, 0x5a, 0x00, 0x72,
				     0x00, 0x1a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb9,
				     0x00, 0x06, 0x00, 0x06, 0x00, 0x06);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x88, 0x07);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8a, 0x00);
	mipi_dsi_dcs_set_column_address_multi(&dsi_ctx, 0x0000, 0x0437);
	mipi_dsi_dcs_set_page_address_multi(&dsi_ctx, 0x0000, 0x08e7);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7f, 0x07);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe9, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbb, 0x90);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_GAMMA_CURVE, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbf, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0, 0x03);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);

	return dsi_ctx.accum_err;
}

static int nt37280_lh568wf3_ed01_off(struct nt37280_lh568wf3_ed01 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x10);
	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 20);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 100);

	return dsi_ctx.accum_err;
}

static int nt37280_lh568wf3_ed01_prepare(struct drm_panel *panel)
{
	struct nt37280_lh568wf3_ed01 *ctx = to_nt37280_lh568wf3_ed01(panel);
	struct device *dev = &ctx->dsi->dev;
	struct drm_dsc_picture_parameter_set pps;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(nt37280_lh568wf3_ed01_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	nt37280_lh568wf3_ed01_reset(ctx);

	ret = nt37280_lh568wf3_ed01_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(nt37280_lh568wf3_ed01_supplies), ctx->supplies);
		return ret;
	}

	drm_dsc_pps_payload_pack(&pps, &ctx->dsc);

	ret = mipi_dsi_picture_parameter_set(ctx->dsi, &pps);
	if (ret < 0) {
		dev_err(panel->dev, "failed to transmit PPS: %d\n", ret);
		return ret;
	}

	ret = mipi_dsi_compression_mode(ctx->dsi, true);
	if (ret < 0) {
		dev_err(dev, "failed to enable compression mode: %d\n", ret);
		return ret;
	}

	msleep(28); /* TODO: Is this panel-dependent? */

	return 0;
}

static int nt37280_lh568wf3_ed01_unprepare(struct drm_panel *panel)
{
	struct nt37280_lh568wf3_ed01 *ctx = to_nt37280_lh568wf3_ed01(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = nt37280_lh568wf3_ed01_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(nt37280_lh568wf3_ed01_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode nt37280_lh568wf3_ed01_90_mode = {
	.clock = (1080 + 36 + 8 + 16) * (2280 + 16 + 4 + 28) * 90 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 36,
	.hsync_end = 1080 + 36 + 8,
	.htotal = 1080 + 36 + 8 + 16,
	.vdisplay = 2280,
	.vsync_start = 2280 + 16,
	.vsync_end = 2280 + 16 + 4,
	.vtotal = 2280 + 16 + 4 + 28,
	.width_mm = 62,
	.height_mm = 130,
	.type = DRM_MODE_TYPE_DRIVER,
};

static const struct drm_display_mode nt37280_lh568wf3_ed01_60_mode = {
	.clock = (1080 + 36 + 8 + 16) * (2280 + 16 + 4 + 28) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 36,
	.hsync_end = 1080 + 36 + 8,
	.htotal = 1080 + 36 + 8 + 16,
	.vdisplay = 2280,
	.vsync_start = 2280 + 16,
	.vsync_end = 2280 + 16 + 4,
	.vtotal = 2280 + 16 + 4 + 28,
	.width_mm = 62,
	.height_mm = 130,
	.type = DRM_MODE_TYPE_DRIVER,
 };

static int nt37280_lh568wf3_ed01_get_modes(struct drm_panel *panel,
				struct drm_connector *connector)
{
	struct drm_display_mode *mode;

	mode = drm_mode_duplicate(connector->dev, &nt37280_lh568wf3_ed01_90_mode);
	if (!mode)
		return -ENOMEM;
	drm_mode_probed_add(connector, mode);

	mode = drm_mode_duplicate(connector->dev, &nt37280_lh568wf3_ed01_60_mode);
	if (!mode)
		return -ENOMEM;
	drm_mode_probed_add(connector, mode);

	connector->display_info.width_mm = nt37280_lh568wf3_ed01_90_mode.width_mm;
	connector->display_info.height_mm = nt37280_lh568wf3_ed01_90_mode.height_mm;

	return 2;
}

static const struct drm_panel_funcs nt37280_lh568wf3_ed01_panel_funcs = {
	.prepare = nt37280_lh568wf3_ed01_prepare,
	.unprepare = nt37280_lh568wf3_ed01_unprepare,
	.get_modes = nt37280_lh568wf3_ed01_get_modes,
};

static int nt37280_lh568wf3_ed01_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

static const struct backlight_ops nt37280_lh568wf3_ed01_bl_ops = {
	.update_status = nt37280_lh568wf3_ed01_bl_update_status,
};

static struct backlight_device *
nt37280_lh568wf3_ed01_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 4079,
		.max_brightness = 4079,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &nt37280_lh568wf3_ed01_bl_ops, &props);
}

static int nt37280_lh568wf3_ed01_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct nt37280_lh568wf3_ed01 *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(nt37280_lh568wf3_ed01_supplies),
					    nt37280_lh568wf3_ed01_supplies,
					    &ctx->supplies);
	if (ret < 0)
		return ret;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_NO_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	drm_panel_init(&ctx->panel, dev, &nt37280_lh568wf3_ed01_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);
	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = nt37280_lh568wf3_ed01_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	/* This panel only supports DSC; unconditionally enable it */
	dsi->dsc = &ctx->dsc;

	ctx->dsc.dsc_version_major = 1;
	ctx->dsc.dsc_version_minor = 1;

	/* TODO: Pass slice_per_pkt = 1 */
	ctx->dsc.slice_height = 20;
	ctx->dsc.slice_width = 540;
	/*
	 * TODO: hdisplay should be read from the selected mode once
	 * it is passed back to drm_panel (in prepare?)
	 */
	WARN_ON(1080 % ctx->dsc.slice_width);
	ctx->dsc.slice_count = 1080 / ctx->dsc.slice_width;
	ctx->dsc.bits_per_component = 8;
	ctx->dsc.bits_per_pixel = 8 << 4; /* 4 fractional bits */
	ctx->dsc.block_pred_enable = true;

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void nt37280_lh568wf3_ed01_remove(struct mipi_dsi_device *dsi)
{
	struct nt37280_lh568wf3_ed01 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id nt37280_lh568wf3_ed01_of_match[] = {
	{ .compatible = "lg,nt37280-lh568wf3-ed01" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, nt37280_lh568wf3_ed01_of_match);

static struct mipi_dsi_driver nt37280_lh568wf3_ed01_driver = {
	.probe = nt37280_lh568wf3_ed01_probe,
	.remove = nt37280_lh568wf3_ed01_remove,
	.driver = {
		.name = "panel-lg-nt37280-lh568wf3-ed01",
		.of_match_table = nt37280_lh568wf3_ed01_of_match,
	},
};
module_mipi_dsi_driver(nt37280_lh568wf3_ed01_driver);

MODULE_AUTHOR("Andrew Gigena <mail@andrewgigena.dev>"); 
MODULE_DESCRIPTION("MIPI-DSI based Panel Driver for LH568WF3-ED01 AMOLED LCD with a NT37280 controller");
MODULE_LICENSE("GPL V2");
