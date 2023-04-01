void scroll_castle_grounds_dl_Fog_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 94;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_Fog_mesh_layer_5_vtx_0);

	deltaX = (int)(0.44999998807907104 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_castle_grounds_dl_Water_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 56;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_Water_mesh_layer_1_vtx_0);

	deltaY = (int)(0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_grounds() {
	scroll_castle_grounds_dl_Fog_mesh_layer_5_vtx_0();
	scroll_castle_grounds_dl_Water_mesh_layer_1_vtx_0();
};
