/* Hello Triangle - código adaptado de https://learnopengl.com/#!Getting-started/Hello-Triangle
 *
 * Adaptado por Rossana Baptista Queiroz
 * para a disciplina de Processamento Gráfico - Jogos Digitais - Unisinos
 * Versão inicial: 7/4/2017
 * Última atualização em 09/08/2021
 *
 */

#include <iostream>
#include <string>
#include <assert.h>
#include <cmath>


using namespace std;

// GLAD
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>

#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "stb_image.h"

#include "Shader.h"

#include "Object.h"




// Protótipo da função de callback de teclado
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

// Protótipos das funções
int loadTexture(string path);

// Dimensões da janela (pode ser alterado em tempo de execução)
const GLuint WIDTH = 800, HEIGHT = 800;

float X = 0.0;
int stk = 0;

float Xstk = 280.0;
float Ystk = 120.0;

float Xstk2 = 340.0;
float Ystk2 = 120.0;

float Xstk3 = 400.0;
float Ystk3 = 120.0;

float Xstk4 = 460.0;
float Ystk4 = 120.0;

float Xstk5 = 520.0;
float Ystk5 = 120.0;

// Função MAIN
int main()
{
	// Inicialização da GLFW
	glfwInit();

	//Muita atenção aqui: alguns ambientes não aceitam essas configurações
	//Você deve adaptar para a versão do OpenGL suportada por sua placa
	//Sugestão: comente essas linhas de código para desobrir a versão e
	//depois atualize (por exemplo: 4.5 com 4 e 5)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Essencial para computadores da Apple
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Criação da janela GLFW
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "lista 4", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Fazendo o registro da função de callback para a janela GLFW
	glfwSetKeyCallback(window, key_callback);

	glfwSetCursorPosCallback(window, cursor_position_callback);

	glfwSetMouseButtonCallback(window, mouse_button_callback);

	// GLAD: carrega todos os ponteiros d funções da OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

	}

	// Obtendo as informações de versão
	const GLubyte* renderer = glGetString(GL_RENDERER); /* get renderer string */
	const GLubyte* version = glGetString(GL_VERSION); /* version as a string */
	cout << "Renderer: " << renderer << endl;
	cout << "OpenGL version supported " << version << endl;

	// Compilando e buildando o programa de shader
	Shader* shader = new Shader("./shaders/sprite.vs", "./shaders/sprite.fs");
	Shader* shader0 = new Shader("./shaders/sprite.vs", "./shaders/colorizblue.fs");
	Shader* shader1 = new Shader("./shaders/sprite.vs", "./shaders/colorizverm.fs");
	Shader* shader2 = new Shader("./shaders/sprite.vs", "./shaders/colorizverd.fs");
	Shader* shader3 = new Shader("./shaders/sprite.vs", "./shaders/invers.fs");
	Shader* shader4 = new Shader("./shaders/sprite.vs", "./shaders/binariz.fs");
	Shader* shader5 = new Shader("./shaders/sprite.vs", "./shaders/grey.fs");
	Shader* shader6 = new Shader("./shaders/sprite.vs", "./shaders/filtromeu.fs");

	GLuint texID = loadTexture("./textures/lena.jpg");
	GLuint texID4 = loadTexture("./textures/analise.png");
	GLuint texID3 = loadTexture("./textures/gatito.png");
	GLuint texID5 = loadTexture("./textures/+18.png");
	GLuint texID6 = loadTexture("./textures/plim.png");
	GLuint texID2 = loadTexture("./textures/oclinhos.jpg");

	Object obj;
	obj.initialize();
	obj.setTexture(texID);
	obj.setShader(shader);
	obj.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj.setPosition(glm::vec3(190.0, 680.0, 0.0));

	Object obj1;
	obj1.initialize();
	obj1.setTexture(texID);
	obj1.setShader(shader0);
	obj1.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj1.setPosition(glm::vec3(250.0, 680.0, 0.0));

	Object obj2;
	obj2.initialize();
	obj2.setTexture(texID);
	obj2.setShader(shader1);
	obj2.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj2.setPosition(glm::vec3(310.0, 680.0, 0.0));

	Object obj3;
	obj3.initialize();
	obj3.setTexture(texID);
	obj3.setShader(shader2);
	obj3.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj3.setPosition(glm::vec3(370.0, 680.0, 0.0));

	Object obj4;
	obj4.initialize();
	obj4.setTexture(texID);
	obj4.setShader(shader3);
	obj4.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj4.setPosition(glm::vec3(430.0, 680.0, 0.0));

	Object obj5;
	obj5.initialize();
	obj5.setTexture(texID);
	obj5.setShader(shader4);
	obj5.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj5.setPosition(glm::vec3(490.0, 680.0, 0.0));

	Object obj6;
	obj6.initialize();
	obj6.setTexture(texID);
	obj6.setShader(shader5);
	obj6.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj6.setPosition(glm::vec3(550.0, 680.0, 0.0));

	Object obj7;
	obj7.initialize();
	obj7.setTexture(texID);
	obj7.setShader(shader6);
	obj7.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj7.setPosition(glm::vec3(610.0, 680.0, 0.0));

	Object obj8;
	obj8.initialize();
	obj8.setTexture(texID2);
	obj8.setShader(shader);
	obj8.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj8.setPosition(glm::vec3(280.0, 120.0, 0.0));

	Object obj9;
	obj9.initialize();
	obj9.setTexture(texID3);
	obj9.setShader(shader);
	obj9.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj9.setPosition(glm::vec3(340.0, 120.0, 0.0));

	Object obj10;
	obj10.initialize();
	obj10.setTexture(texID4);
	obj10.setShader(shader);
	obj10.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj10.setPosition(glm::vec3(400.0, 120.0, 0.0));

	Object obj11;
	obj11.initialize();
	obj11.setTexture(texID5);
	obj11.setShader(shader);
	obj11.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj11.setPosition(glm::vec3(460.0, 120.0, 0.0));

	Object obj12;
	obj12.initialize();
	obj12.setTexture(texID6);
	obj12.setShader(shader);
	obj12.setDimensions(glm::vec3(40.0, -40.0, 0.0));
	obj12.setPosition(glm::vec3(520.0, 120.0, 0.0));

	Object obj13;
	obj13.initialize();
	obj13.setTexture(texID);
	obj13.setShader(shader);
	obj13.setDimensions(glm::vec3(400.0, -400.0, 0.0));
	obj13.setPosition(glm::vec3(400.0, 400.0, 0.0));

	//Ativando o shader que será usado
	// Enviando a cor desejada (vec4) para o fragment shader
	// Utilizamos a variáveis do tipo uniform em GLSL para armazenar esse tipo de info
	// que não está nos buffers
	shader->Use();

	GLint projLoc = glGetUniformLocation(shader->Program, "projection");
	assert(projLoc > -1);

	glUniform1i(glGetUniformLocation(shader->Program, "tex1"), 0);

	shader0->Use();

	GLint projLoc0 = glGetUniformLocation(shader0->Program, "projection");
	assert(projLoc0 > -1);

	glUniform1i(glGetUniformLocation(shader0->Program, "tex1"), 0);

	shader1->Use();

	GLint projLoc1 = glGetUniformLocation(shader1->Program, "projection");
	assert(projLoc1 > -1);

	glUniform1i(glGetUniformLocation(shader1->Program, "tex1"), 0);

	shader2->Use();

	GLint projLoc2 = glGetUniformLocation(shader2->Program, "projection");
	assert(projLoc2 > -1);

	glUniform1i(glGetUniformLocation(shader2->Program, "tex1"), 0);

	shader3->Use();

	GLint projLoc3 = glGetUniformLocation(shader3->Program, "projection");
	assert(projLoc3 > -1);

	glUniform1i(glGetUniformLocation(shader3->Program, "tex1"), 0);

	GLint projLoc4 = glGetUniformLocation(shader4->Program, "projection");
	assert(projLoc4 > -1);

	glUniform1i(glGetUniformLocation(shader4->Program, "tex1"), 0);

	GLint projLoc5 = glGetUniformLocation(shader5->Program, "projection");
	assert(projLoc5 > -1);

	glUniform1i(glGetUniformLocation(shader5->Program, "tex1"), 0);

	GLint projLoc6 = glGetUniformLocation(shader6->Program, "projection");
	assert(projLoc6 > -1);

	glUniform1i(glGetUniformLocation(shader6->Program, "tex1"), 0);

	glm::mat4 ortho = glm::mat4(1); //inicializa com a matriz identidade

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Loop da aplicação - "game loop"
	while (!glfwWindowShouldClose(window))
	{
		// Checa se houveram eventos de input (key pressed, mouse moved etc.) e chama as funções de callback correspondentes
		glfwPollEvents();

		// Definindo as dimensões da viewport com as mesmas dimensões da janela da aplicação
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		ortho = glm::ortho(0.0, 800.0, 800.0, 0.0, -1.0, 1.0);

		// Limpa o buffer de cor
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //cor de fundo
		glClear(GL_COLOR_BUFFER_BIT);

		//Enviar a matriz de projeção ortográfica para o shader
		shader->Use();
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(ortho));
		shader0->Use();
		glUniformMatrix4fv(projLoc0, 1, GL_FALSE, glm::value_ptr(ortho));
		shader1->Use();
		glUniformMatrix4fv(projLoc1, 1, GL_FALSE, glm::value_ptr(ortho));
		shader2->Use();
		glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(ortho));
		shader3->Use();
		glUniformMatrix4fv(projLoc3, 1, GL_FALSE, glm::value_ptr(ortho));
		shader4->Use();
		glUniformMatrix4fv(projLoc4, 1, GL_FALSE, glm::value_ptr(ortho));
		shader5->Use();
		glUniformMatrix4fv(projLoc5, 1, GL_FALSE, glm::value_ptr(ortho));
		shader6->Use();
		glUniformMatrix4fv(projLoc6, 1, GL_FALSE, glm::value_ptr(ortho));

		glLineWidth(10);
		glPointSize(10);

		obj.update();
		obj.draw();

		obj1.update();
		obj1.draw();

		obj2.update();
		obj2.draw();

		obj3.update();
		obj3.draw();

		obj4.update();
		obj4.draw();

		obj5.update();
		obj5.draw();

		obj6.update();
		obj6.draw();

		obj7.update();
		obj7.draw();
		
		if (X == 1.0)
		{
			obj13.setShader(shader0);
		}
		else if (X == 2.0)
		{
			obj13.setShader(shader1);
		}
		else if (X == 3.0)
		{
			obj13.setShader(shader2);
		}
		else if (X == 4.0)
		{
			obj13.setShader(shader3);
		}
		else if (X == 5.0)
		{
			obj13.setShader(shader4);
		}
		else if (X == 6.0)
		{
			obj13.setShader(shader5);
		}
		else if (X == 7.0)
		{
			obj13.setShader(shader6);
		}
		else
		{
			obj13.setShader(shader);
		}
		obj13.update();
		obj13.draw();

		obj8.setPosition(glm::vec3(Xstk, Ystk, 0.0));
		obj8.update();
		obj8.draw();

		obj9.setPosition(glm::vec3(Xstk2, Ystk2, 0.0));
		obj9.update();
		obj9.draw();

		obj10.setPosition(glm::vec3(Xstk3, Ystk3, 0.0));
		obj10.update();
		obj10.draw();

		obj11.setPosition(glm::vec3(Xstk4, Ystk4, 0.0));
		obj11.update();
		obj11.draw();

		obj12.setPosition(glm::vec3(Xstk5, Ystk5, 0.0));
		obj12.update();
		obj12.draw();

		// Troca os buffers da tela
		glfwSwapBuffers(window);
	}

	// Finaliza a execução da GLFW, limpando os recursos alocados por ela
	glfwTerminate();
	return 0;
}

// Função de callback de teclado - só pode ter uma instância (deve ser estática se
// estiver dentro de uma classe) - É chamada sempre que uma tecla for pressionada
// ou solta via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);	
	if (stk == 1)
	{
		if (key == GLFW_KEY_S && action == GLFW_PRESS)
		{
			Ystk = Ystk + 10;
		}

		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		{
			Ystk = Ystk - 10;
		}

		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		{
			Xstk = Xstk + 10;
		}

		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			Xstk = Xstk - 10;
		}
	}

	if (stk == 2)
	{
		if (key == GLFW_KEY_S && action == GLFW_PRESS)
		{
			Ystk2 = Ystk2 + 10;
		}

		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		{
			Ystk2 = Ystk2 - 10;
		}

		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		{
			Xstk2 = Xstk2 + 10;
		}

		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			Xstk2 = Xstk2 - 10;
		}
	}

	if (stk == 3)
	{
		if (key == GLFW_KEY_S && action == GLFW_PRESS)
		{
			Ystk3 = Ystk3 + 10;
		}

		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		{
			Ystk3 = Ystk3 - 10;
		}

		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		{
			Xstk3 = Xstk3 + 10;
		}

		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			Xstk3 = Xstk3 - 10;
		}
	}

	if (stk == 4)
	{
		if (key == GLFW_KEY_S && action == GLFW_PRESS)
		{
			Ystk4 = Ystk4 + 10;
		}

		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		{
			Ystk4 = Ystk4 - 10;
		}

		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		{
			Xstk4 = Xstk4 + 10;
		}

		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			Xstk4 = Xstk4 - 10;
		}
	}

	if (stk == 5)
	{
		if (key == GLFW_KEY_S && action == GLFW_PRESS)
		{
			Ystk5 = Ystk5 + 10;
		}

		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		{
			Ystk5 = Ystk5 - 10;
		}

		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		{
			Xstk5 = Xstk5 + 10;
		}

		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			Xstk5 = Xstk5 - 10;
		}
	}
}

static void cursor_position_callback(GLFWwindow* window, double xPos, double yPos)
{
	std::cout << xPos << " : " << yPos << std::endl;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	double xPos;
	double yPos;
	glfwGetCursorPos(window, &xPos, &yPos);


	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && yPos > 620.0 && yPos < 655.0)
	{
		if (xPos > 230.0 && xPos < 270.0)
		{
			X = 1.0;
		}
		else if (xPos > 290.0 && xPos < 330.0)
		{
			X = 2.0;
		}
		else if (xPos > 350.0 && xPos < 390.0)
		{
			X = 3.0;
		}
		else if (xPos > 410.0 && xPos < 450.0)
		{
			X = 4.0;
		}
		else if (xPos > 470.0 && xPos < 510.0)
		{
			X = 5.0;
		}
		else if (xPos > 530.0 && xPos < 570.0)
		{
			X = 6.0;
		}
		else if (xPos > 590.0 && xPos < 630.0)
		{
			X = 7.0;
		}
		else if (xPos > 170.0 && xPos < 210.0)
		{
			X = 0.0;
		}
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		stk = 0;
	}
	
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && yPos > 95.0 && yPos < 130.0)
	{
		if (xPos > 260.0 && xPos < 300.0)
		{
				stk = 1;
		}
		else if (xPos > 320.0 && xPos < 360.0)
		{
				stk = 2;
		}
		else if (xPos > 380.0 && xPos < 420.0)
		{
				stk = 3;
		}
		else if (xPos > 440.0 && xPos < 480.0)
		{
				stk = 4;
		}
		else if (xPos > 500.0 && xPos < 540.0)
		{
				stk = 5;
		}
	}


	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		if (stk == 1)
		{
			Ystk = yPos;
			Xstk = xPos;
		}
		else if (stk == 2)
		{
			Ystk2 = yPos;
			Xstk2 = xPos;
		}
		else if (stk == 3)
		{
			Ystk3 = yPos;
			Xstk3 = xPos;
		}
		else if (stk == 4)
		{
			Ystk4 = yPos;
			Xstk4 = xPos;
		}
		else if (stk == 5)
		{
			Ystk5 = yPos;
			Xstk5 = xPos;
		}
	}
}


// Esta função está bastante harcoded - objetivo é criar os buffers que armazenam a 
// geometria de um triângulo
// Apenas atributo coordenada nos vértices
// 1 VBO com as coordenadas, VAO com apenas 1 ponteiro para atributo
// A função retorna o identificador do VAO


int loadTexture(string path)
{
	GLuint texID;

	// Gera o identificador da textura na memória 
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	//Ajusta os parâmetros de wrapping e filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Carregamento da imagem
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

	if (data)
	{
		if (nrChannels == 3) //jpg, bmp
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		else //png
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, 0);

	return texID;
}