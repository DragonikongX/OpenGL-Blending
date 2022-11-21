class TextureDatabase {
public:
	vector<Texture> furnitureTextures, wallTextures, lampTextures, bowlTextures, floorTextures, potTextures, shelfTextures, flowersTextures, appleTextures, orangeTextures, imageTextures, frameTextures, bookTextures, windowTextures;

	TextureDatabase() {
		this->furnitureTextures.push_back(Texture("Textures/tableDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		this->furnitureTextures.push_back(Texture("Textures/tableSpecular.jpg", "Specular", 1, GL_RED, GL_UNSIGNED_BYTE, 4));
		
		this->wallTextures.push_back(Texture("Textures/wallDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		this->wallTextures.push_back(Texture("Textures/wallSpecular.jpg", "Specular", 1, GL_RED, GL_UNSIGNED_BYTE, 4));
		
		this->bowlTextures.push_back(Texture("Textures/bowlDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		this->bowlTextures.push_back(Texture("Textures/bowlSpecular.jpg", "Specular", 1, GL_RED, GL_UNSIGNED_BYTE, 4));
		
		this->floorTextures.push_back(Texture("Textures/floorDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		this->floorTextures.push_back(Texture("Textures/floorSpecular.jpg", "Specular", 1, GL_RED, GL_UNSIGNED_BYTE, 4));
		
		this->potTextures.push_back(Texture("Textures/potDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		this->potTextures.push_back(Texture("Textures/potSpecular.jpg", "Specular", 1, GL_RED, GL_UNSIGNED_BYTE, 4));
		
		this->shelfTextures.push_back(Texture("Textures/shelfDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		this->shelfTextures.push_back(Texture("Textures/shelfSpecular.jpg", "Specular", 1, GL_RED, GL_UNSIGNED_BYTE, 4));
		
		this->flowersTextures.push_back(Texture("Textures/grassDiffuse.png", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		this->flowersTextures.push_back(Texture("Textures/grassSpecular.png", "Specular", 1, GL_RED, GL_UNSIGNED_BYTE, 4));
		
		this->lampTextures.push_back(Texture("Textures/lampDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		
		this->appleTextures.push_back(Texture("Textures/appleDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		
		this->orangeTextures.push_back(Texture("Textures/orangeDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		
		this->imageTextures.push_back(Texture("Textures/imageDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		
		this->frameTextures.push_back(Texture("Textures/frameDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		
		this->bookTextures.push_back(Texture("Textures/bookDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
		
		this->windowTextures.push_back(Texture("Textures/windowDiffuse.jpg", "Diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE, 4));
	}
};

class VertexDatabase {
public:
	vector<Vertex> lightVertices, window1Vertices, window2Vertices, window3Vertices, window4Vertices;
	vector<GLuint> lightIndices, windowIndices;
	
	VertexDatabase() {
		this->lightVertices = {
			Vertex{vec3(-0.05f, -0.05f,  0.05f)},
			Vertex{vec3(-0.05f, -0.05f, -0.05f)},
			Vertex{vec3(0.05f,  -0.05f, -0.05f)},
			Vertex{vec3(0.05f,  -0.05f,  0.05f)},
			Vertex{vec3(-0.05f,  0.05f,  0.05f)},
			Vertex{vec3(-0.05f,  0.05f, -0.05f)},
			Vertex{vec3(0.05f,   0.05f, -0.05f)},
			Vertex{vec3(0.05f,   0.05f,  0.05f)}
		};
		this->lightIndices = {
			0, 1, 2,
			0, 2, 3,
			0, 4, 7,
			0, 7, 3,
			3, 7, 6,
			3, 6, 2,
			2, 6, 5,
			2, 5, 1,
			1, 5, 4,
			1, 4, 0,
			4, 5, 6,
			4, 6, 7
		};
		this->window1Vertices = {
			Vertex{vec3(-1.05f, -1.05f,  0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-1.05f, -1.05f, -0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(1.05f,  -1.05f, -0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(1.05f,  -1.05f,  0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-1.05f,  1.05f,  0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-1.05f,  1.05f, -0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(1.05f,   1.05f, -0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(1.05f,   1.05f,  0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)}
		};
		this->window2Vertices = {
			Vertex{vec3(-1.05f, -1.05f,  0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-1.05f, -1.05f, -0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(1.05f,  -1.05f, -0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(1.05f,  -1.05f,  0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-1.05f,  1.05f,  0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-1.05f,  1.05f, -0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(1.05f,   1.05f, -0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(1.05f,   1.05f,  0.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)}
		};
		this->window3Vertices = {
			Vertex{vec3(-0.05f, -1.05f,  1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-0.05f, -1.05f, -1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3( 0.05f, -1.05f, -1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3( 0.05f, -1.05f,  1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-0.05f,  1.05f,  1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-0.05f,  1.05f, -1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3( 0.05f,  1.05f, -1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3( 0.05f,  1.05f,  1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)}
		};
		this->window4Vertices = {
			Vertex{vec3(-0.05f, -1.05f,  1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-0.05f, -1.05f, -1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(0.05f, -1.05f, -1.05f), vec3(0.0f, 0.0f ,0.0f),  vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(0.05f, -1.05f,  1.05f), vec3(0.0f, 0.0f ,0.0f),  vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-0.05f,  1.05f,  1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(-0.05f,  1.05f, -1.05f), vec3(0.0f, 0.0f ,0.0f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(0.05f,  1.05f, -1.05f), vec3(0.0f, 0.0f ,0.0f),  vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)},
			Vertex{vec3(0.05f,  1.05f,  1.05f), vec3(0.0f, 0.0f ,0.0f),  vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)}
		};
		this->windowIndices = {
			0, 1, 2,
			0, 2, 3,
			0, 4, 7,
			0, 7, 3,
			3, 7, 6,
			3, 6, 2,
			2, 6, 5,
			2, 5, 1,
			1, 5, 4,
			1, 4, 0,
			4, 5, 6,
			4, 6, 7
		};
	}
};

class ModelDatabase {
public:
	vector<Light> lights;
	vector<Mesh> meshes;
	vector<Window> windows;

	ModelDatabase(){}
	ModelDatabase(VertexDatabase vertexDatabase, TextureDatabase textureDatabase, ShaderUseClass& lightShader, ShaderUseClass& basicShader, ShaderUseClass& windowShader, ShaderUseClass& flowerShader) {

		Light light(vertexDatabase.lightVertices, vertexDatabase.lightIndices, &lightShader);
		light.SetPosition(vec3(2.7f, 1.5f, -3.6f));
		lights.push_back(light);

		Mesh table("Obj/table.obj", &basicShader, textureDatabase.furnitureTextures);
		table.SetPosition(vec3(2.3f, 0.2f, -4.2f));
		meshes.push_back(table);

		Mesh bowl("Obj/bowl.obj", &basicShader, textureDatabase.bowlTextures);
		bowl.SetPosition(vec3(2.3f, 0.79f, -4.2f));
		bowl.SetScale(vec3(0.1f, 0.1f, 0.1f));
		meshes.push_back(bowl);

		Mesh apples("Obj/apples.obj", &basicShader, textureDatabase.appleTextures, 0.5f);
		apples.SetPosition(vec3(2.3f, 0.79f, -4.2f));
		apples.SetScale(vec3(0.1f, 0.1f, 0.1f));
		meshes.push_back(apples);

		Mesh oranges("Obj/oranges.obj", &basicShader, textureDatabase.orangeTextures, 0.5f);
		oranges.SetPosition(vec3(2.3f, 0.79f, -4.2f));
		oranges.SetScale(vec3(0.1f, 0.1f, 0.1f));
		meshes.push_back(oranges);

		Mesh chair1("Obj/chair.obj", &basicShader, textureDatabase.furnitureTextures);
		chair1.SetPosition(vec3(1.4f, 0.0f, -4.2f));
		meshes.push_back(chair1);

		Mesh chair2("Obj/chair.obj", &basicShader, textureDatabase.furnitureTextures);
		chair2.SetRotation(vec3(0.0f, 180.0f, 0.0f));
		chair2.SetPosition(vec3(-3.0f, 0.0f, 4.2f));
		meshes.push_back(chair2);

		Mesh lamp("Obj/lamp.obj", &basicShader, textureDatabase.lampTextures);
		lamp.SetPosition(vec3(2.7f, 1.5f, -3.6f));
		lamp.SetScale(vec3(6.0f, 6.0f, 6.0f));
		meshes.push_back(lamp);

		Mesh floor("Obj/floor.obj", &basicShader, textureDatabase.floorTextures);
		meshes.push_back(floor);

		Mesh room("Obj/room.obj", &basicShader, textureDatabase.wallTextures);
		meshes.push_back(room);

		Mesh sills("Obj/sills.obj", &basicShader, textureDatabase.floorTextures);
		meshes.push_back(sills);

		Mesh pots("Obj/pots.obj", &basicShader, textureDatabase.potTextures);
		meshes.push_back(pots);

		Mesh frame("Obj/frame.obj", &basicShader, textureDatabase.frameTextures, 1.0f);
		meshes.push_back(frame);

		Mesh image("Obj/image.obj", &basicShader, textureDatabase.imageTextures, 1.0f);
		meshes.push_back(image);

		Mesh books("Obj/books.obj", &basicShader, textureDatabase.bookTextures, 6.0f);
		meshes.push_back(books);

		Mesh shelf("Obj/shelf.obj", &basicShader, textureDatabase.shelfTextures);
		meshes.push_back(shelf);

		Window window1(vertexDatabase.window1Vertices, vertexDatabase.windowIndices, textureDatabase.windowTextures, &windowShader);
		window1.SetPosition(vec3(2.5f, 1.1f, 0.1f));
		windows.push_back(window1);
		Window window2(vertexDatabase.window2Vertices, vertexDatabase.windowIndices, textureDatabase.windowTextures, &windowShader);
		window2.SetPosition(vec3(2.5f, 1.2f, -7.1f));
		windows.push_back(window2);
		Window window3(vertexDatabase.window3Vertices, vertexDatabase.windowIndices, textureDatabase.windowTextures, &windowShader);
		window3.SetPosition(vec3(-0.1f, 1.1f, -4.8f));
		windows.push_back(window3);
		Window window4(vertexDatabase.window4Vertices, vertexDatabase.windowIndices, textureDatabase.windowTextures, &windowShader);
		window4.SetPosition(vec3(6.6f, 1.1f, -4.8f));
		windows.push_back(window4);

		Mesh flower1("Obj/flower1.obj", &flowerShader, textureDatabase.flowersTextures, 1.0f);
		meshes.push_back(flower1);
		Mesh flower2("Obj/flower2.obj", &flowerShader, textureDatabase.flowersTextures, 1.0f);
		meshes.push_back(flower2);
		Mesh flower3("Obj/flower3.obj", &flowerShader, textureDatabase.flowersTextures, 1.0f);
		meshes.push_back(flower3);
		Mesh flower4("Obj/flower4.obj", &flowerShader, textureDatabase.flowersTextures, 1.0f);
		meshes.push_back(flower4);
		Mesh flower5("Obj/flower5.obj", &flowerShader, textureDatabase.flowersTextures, 1.0f);
		meshes.push_back(flower5);
	}
};

class Database {
public:
	TextureDatabase textureDatabase;
	VertexDatabase vertexDatabase;
	ModelDatabase modelDatabase;

	map<float, Window> drawOrder;

	Database(ShaderUseClass& lightShader, ShaderUseClass& basicShader, ShaderUseClass& windowShader, ShaderUseClass& flowerShader) {
		this->textureDatabase = TextureDatabase();
		this->vertexDatabase = VertexDatabase();
		this->modelDatabase = ModelDatabase(this->vertexDatabase, this->textureDatabase, lightShader, basicShader, windowShader, flowerShader);
	}

	void DrawDatabase(Camera camera) {
		for (int i = 0; i < modelDatabase.lights.size(); i++) {
			modelDatabase.lights[i].SetUniform();
			modelDatabase.lights[i].DrawLight(camera);
		}
		for (int i = 0; i < modelDatabase.meshes.size(); i++) {
			modelDatabase.meshes[i].SetUniform(modelDatabase.lights[0]);
			modelDatabase.meshes[i].DrawMesh(camera);
		}
		for (int i = 0; i < modelDatabase.windows.size(); i++) {
			drawOrder.insert({length(camera.position - modelDatabase.windows[i].position), modelDatabase.windows[i]});
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		for (auto i = drawOrder.rbegin(); i != drawOrder.rend(); i++) {
			i->second.SetUniform(modelDatabase.lights[0]);
			i->second.DrawWindow(camera);
		}
		drawOrder.clear();
		glDisable(GL_BLEND);
	}
};