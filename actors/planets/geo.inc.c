#include "src/game/envfx_snow.h"

const GeoLayout planets_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 47, 3, -90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, planets_big_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 518, -680, planets_smol_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, planets_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
