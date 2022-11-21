static class SoloFunctions {
public:
	static void DrawLine(float x1, float z1, float x2, float z2) {
		glBegin(GL_LINES);
		glVertex3f(x1, -0.01f, z1);
		glVertex3f(x2, -0.01f, z2);
		glEnd();
	}

	static void DrawWireMap(int start, int end, int diff) {
		for (int i = start; i < end; i += diff) {
			for (int j = start; j < end; j += diff) {
				DrawLine(i, i, i, j);
				DrawLine(i, i, j, i);
			}
		}
	}
};