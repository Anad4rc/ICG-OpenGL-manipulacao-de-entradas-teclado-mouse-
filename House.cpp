#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

//valores de posicoes comuns. Criei essas variaveis para facilitar o controle e futuras alteracoes dos valores. Possibilitando alteras as dimensoes e posicoes dos elementos mesmo depois de tudo feito.

const int BORDA = 8;

const int STARTCASA = 150;
const int COMCASA = 300;
const int TETOH = 250;
const int PICOH = 400;
const int BORDATETO = 35;
const int SOMBRAT = 15;

const int STARTPORTA = 200;
const int ALTURAPORTA = 180;
const int COMPORTA = 90;
const int BORDAPORTA = 8;

const int STARTJANELA = 345;
const int STARTJANELAH = 90;
const int ALTJANELA = 70;
const int LJANELA = 8;
const int COMJANELA = 70;
const int ALTPARAPEITO = 20;
GLint WINDOW_WIDTH  = 600,
      WINDOW_HEIGHT = 600;
      
void init();      
void draw_house();

void keyboard_func(GLubyte key, GLint x, GLint y);
void keyboard_func_spec(GLint key, GLint x, GLint y);

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  
  init();

  glutDisplayFunc(draw_house);
  
  glutKeyboardFunc(keyboard_func);
  glutSpecialFunc(keyboard_func_spec);
    
  glutMainLoop();
  
  
  return EXIT_SUCCESS;
}

void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
  GLint screen_width  = glutGet(GLUT_SCREEN_WIDTH),
        screen_height = glutGet(GLUT_SCREEN_HEIGHT);  
  
  glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_WIDTH);
  glutCreateWindow("My first draw in openGL");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  
  gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void draw_house()


{
   // Limpa a janela de visualização com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);



    //arbusto
    glColor3f(0.45f, 0.75f, 0.2f); 
    glBegin(GL_QUADS);

        glVertex2f(0, 100);
        glVertex2f(0, 0);
        glVertex2f(600, 0);
        glVertex2f(600, 100);

    glEnd();
    

   //chamine
    glColor3f(0.5f, 0.0f, 0.0f); 
    glBegin(GL_QUADS);

        glVertex2f(STARTCASA + 40, 0);
        glVertex2f(STARTCASA + 40, 400);
        glVertex2f(STARTCASA + 70, 400);
        glVertex2f(STARTCASA + 70, 0);

    glEnd();


   //parede da casa
    glColor3f(0.90f, 0.75f, 0.40f); 
    glBegin(GL_QUADS);
        glVertex2f(STARTCASA, 0);
        glVertex2f(STARTCASA, TETOH);
        glVertex2f(STARTCASA + COMCASA, TETOH);
        glVertex2f(STARTCASA + COMCASA, 0);
    glEnd();
    
    glColor3f(0.90f, 0.75f, 0.40f); 
    glBegin(GL_TRIANGLES);
        glVertex2f(STARTCASA, TETOH);
        glVertex2f(300, PICOH);
        glVertex2f(STARTCASA + COMCASA, TETOH);
    glEnd();


   //telhado
    glColor3f(0.79f, 0.06f, 0.06f);
    glBegin(GL_QUADS);	    
        glVertex2f(STARTCASA, TETOH); 
        glVertex2f(STARTCASA - BORDATETO, TETOH); 
        glVertex2f(300, PICOH + BORDATETO); 
        glVertex2f(300, PICOH); 
    glEnd();
    
    glColor3f(0.79f, 0.06f, 0.06f);
    glBegin(GL_QUADS);   
        glVertex2f(STARTCASA + COMCASA, TETOH); 
        glVertex2f(STARTCASA + COMCASA + BORDATETO, TETOH); 
        glVertex2f(300, PICOH + BORDATETO); 
        glVertex2f(300, PICOH);
    glEnd();
    
    //sombratelhado
     glColor3f(0.7f, 0.55f, 0.3f);
    glBegin(GL_QUADS);   
        glVertex2f(STARTCASA, TETOH); 
        glVertex2f(STARTCASA, TETOH - SOMBRAT); 
        glVertex2f(300, PICOH - SOMBRAT); 
        glVertex2f(300, PICOH); 
    glEnd();

    glColor3f(0.7f, 0.55f, 0.3f);
    glBegin(GL_QUADS);  
        glVertex2f(STARTCASA + COMCASA, TETOH); 
        glVertex2f(STARTCASA + COMCASA, TETOH - SOMBRAT); 
        glVertex2f(300, PICOH - SOMBRAT); 
        glVertex2f(300, PICOH); 
    glEnd();
    
      //batente
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
		   
        glVertex2f(STARTCASA - BORDA, 10); 
        glVertex2f(STARTCASA - BORDA, 0); 
        glVertex2f(STARTCASA + COMCASA + BORDA, 0); 
        glVertex2f(STARTCASA + COMCASA + BORDA, 10);
    glEnd();
    
    
    //borda da porta
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
		   
        glVertex2f(STARTPORTA, 10); 
        glVertex2f(STARTPORTA, ALTURAPORTA); 
        glVertex2f(STARTPORTA + COMPORTA, ALTURAPORTA); 
        glVertex2f(STARTPORTA + COMPORTA, 10);
    glEnd();
    
    
    glColor3f(0.79f, 0.06f, 0.06f);
    glBegin(GL_QUADS);   
        glVertex2f(STARTPORTA + BORDAPORTA, 10); 
        glVertex2f(STARTPORTA + BORDAPORTA, ALTURAPORTA - BORDAPORTA); 
        glVertex2f(STARTPORTA + COMPORTA - BORDAPORTA, ALTURAPORTA - BORDAPORTA); 
        glVertex2f(STARTPORTA + COMPORTA - BORDAPORTA, 10); 
    glEnd();
    
      glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);   
        glVertex2f(STARTPORTA - BORDA, 10); 
        glVertex2f(STARTPORTA - BORDA, 0); 
        glVertex2f(STARTPORTA + COMPORTA + BORDA, 0); 
        glVertex2f(STARTPORTA + COMPORTA + BORDA, 10); 
    glEnd();
    
    //macaneta
     glColor3f(0.0f, 0.0f, 0.0f); 
    glBegin(GL_QUADS); 
        glVertex2f(STARTPORTA + COMPORTA - 28, 90); 
        glVertex2f(STARTPORTA + COMPORTA - 28, 95);  
        glVertex2f(STARTPORTA + COMPORTA - 12, 95);  
        glVertex2f(STARTPORTA + COMPORTA - 12, 90);
    glEnd();
    
    
    
    //janela
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(STARTJANELA, STARTJANELAH); 
        glVertex2f(STARTJANELA, STARTJANELAH + ALTJANELA);
        glVertex2f(STARTJANELA + COMJANELA, STARTJANELAH + ALTJANELA); 
        glVertex2f(STARTJANELA + COMJANELA, STARTJANELAH); 
    glEnd();
    
    glColor3f(0.4f, 0.8f, 1.0f);
    glBegin(GL_QUADS);  
        glVertex2f(STARTJANELA + LJANELA, STARTJANELAH); 
        glVertex2f(STARTJANELA + LJANELA, STARTJANELAH + ALTJANELA - LJANELA); 
        glVertex2f(STARTJANELA + COMJANELA - LJANELA, STARTJANELAH + ALTJANELA - LJANELA);
        glVertex2f(STARTJANELA + COMJANELA - LJANELA, STARTJANELAH); 
    glEnd();
    
    //Parapeito
    glColor3f(0.0f, 0.0f, 0.0f); 
    glBegin(GL_QUADS);
        glVertex2f(STARTJANELA - BORDA, STARTJANELAH); 
        glVertex2f(STARTJANELA + COMJANELA + BORDA, STARTJANELAH);
        glVertex2f(STARTJANELA + COMJANELA + BORDA, STARTJANELAH - ALTPARAPEITO); 
        glVertex2f(STARTJANELA - BORDA, STARTJANELAH - ALTPARAPEITO); 
        
    glEnd();
     
        
    //Executa os comandos OpenGL 
    glFlush();
    glFlush();
}

 // pinta o fundo da imagem de preto
void keyboard_func(GLubyte key, GLint x, GLint y)
{
  

   if(key == 32 && key == 17){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   }
   glutPostRedisplay();
}



// pinta o fundo da imagem de cinza
void keyboard_func_spec(GLint key, GLint x, GLint y)
{
    glClearColor(0.66f, 0.66f, 0.66f, 1.0f);

    glutPostRedisplay();
}

