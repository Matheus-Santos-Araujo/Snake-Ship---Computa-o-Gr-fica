// g++ -std=c++11  principal.cpp -o barco -lglut -lGLU -lGL
// ./barco

// IMPORTA BIBLIOTECAS 
#include <GL/glut.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include "tesouro.cpp"
#include "container.cpp"
#include "barco.cpp" 

Barco* barco = new Barco(0,0,6); // CRIA NOVO BARCO

void constroiCuboPadrao(){ //CONSTRUA AS LISTAS DE EXIBIÇÃO E COMPILA OS CONTAINERS DA PRAIA 
    cubopadrao = glGenLists(1);
    glNewList(cubopadrao,GL_COMPILE);

    // DESENHA CUBOS (CONTAINERS) QUE FORMAM A PRAIA E PARTE DO BARCO
        glBegin(GL_QUADS);
        
            glNormal3f(0,0,1);
            glVertex3f(0.5,0.5,0.5); // ATRÁS
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glNormal3f(0,0,-1);

            glVertex3f(0.5,0.5,-0.5); // NA FRENTE
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(0.5,-0.5,-0.5);

            glNormal3f(0,-1,0); // EMBAIXO
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);

            glNormal3f(0,1,0); // ENCIMA
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,0.5,-0.5);

            glNormal3f(-1,0,0); // NA DIREITA
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,-0.5);

            glNormal3f(1,0,0); //NA ESQUERDA
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);
        glEnd();
    glEndList();
}

void constroiVela(){ //CONSTRUA AS LISTAS DE EXIBIÇÃO E COMPILA OS CONTAINERS DO BARCO
  vela = glGenLists(1); // ARMAZENA EM VELA O NUMERO DE LISTAS
  glNewList(vela,GL_COMPILE); // Especifica o nome inteiro da lista de exibição a ser executada

  glPushMatrix();
  glTranslatef(0.0, 1.0, 0.0);   
  glScalef(0.1, 2.0, 0.2);  
  glColor3f (0.4f, 0.4f, 0.1f);

    // DESENHA CUBO (CONTAINER) ESPECIAL COM BANDEIRA VERMELHA
    glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0.5,0.5,0.5); // ATRÁS
            glVertex3f(-0.5,0.5,0.5);
            glColor3f (0.2f, 0.2f, 0.1f);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glNormal3f(0,0,-1);
            glColor3f (0.4f, 0.4f, 0.1f);

            glVertex3f(0.5,0.5,-0.5); // NA FRENTE
            glVertex3f(-0.5,0.5,-0.5);
            glColor3f (0.2f, 0.2f, 0.1f);
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(0.5,-0.5,-0.5);

            glColor3f (0.4f, 0.4f, 0.1f);
            glNormal3f(0,-1,0); // EMBAIXO
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glColor3f (0.2f, 0.2f, 0.1f);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);

            glColor3f (0.4f, 0.4f, 0.1f);
            glNormal3f(0,1,0); // ENCIMA
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
            glColor3f (0.2f, 0.2f, 0.1f);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,0.5,-0.5);

            glColor3f (0.4f, 0.4f, 0.1f);
            glNormal3f(-1,0,0); // NA DIREITA
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
            glColor3f (0.2f, 0.2f, 0.1f);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,-0.5);

            glColor3f (0.4f, 0.4f, 0.1f);
            glNormal3f(1,0,0); //NA ESQUERDA
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,0.5);
            glColor3f (0.2f, 0.2f, 0.1f);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);    
        glEnd();  

             glTranslatef(0.5, 0.0, 0.0);   
            glScalef(4.0, 2.0,4.0);  
            glColor3f (1.0f, 0.0f, 0.0f);
            glBegin(GL_POLYGON);
                 glVertex3f(2.5, 0.0, 0.5);
                 glVertex3f(2.5, 0.0, 0.0);
                 glVertex3f(0.0, 0.5, 0.0);
                 glVertex3f(0.0, 0.0, 0.5);
            glEnd();

        glPopMatrix();
        glColor3f (0.3f, 0.3f, 0.1f);
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0.5,0.5,0.5); // ATRÁS
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glNormal3f(0,0,-1);

            glVertex3f(0.5,0.5,-0.5); // NA FRENTE
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(0.5,-0.5,-0.5);

            glNormal3f(0,-1,0); // EMBAIXO
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);

            glNormal3f(0,1,0); // ENCIMA
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,0.5,-0.5);

            glNormal3f(-1,0,0); // NA DIREITA
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,-0.5);

            glNormal3f(1,0,0); //NA ESQUERDA
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);
        glEnd();
    glEndList();
}

void constroiPontas(){ //CONSTRUA AS LISTAS DE EXIBIÇÃO E COMPILA PROA E POPA DA PRAIA 
    ponta = glGenLists(1);
    glNewList(ponta,GL_COMPILE);
   glScalef(0.4, 1.5, 0.5);  
   //glRotatef (180, 1.0, 0.0, 0.0);
    glColor3f (0.4f, 0.4f, 0.1f);

    // DESENHA CUBO (CONTAINER) ESPECIA PARA PROA
    glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0.5,0.5,0.5); // ATRÁS
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glNormal3f(0,0,-1);

            glVertex3f(0.5,0.5,-0.5); // NA FRENTE
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-1.5,-0.5,-0.5);
            glVertex3f(1.5,-0.5,-0.5);

            glNormal3f(0,-1,0); // EMBAIXO
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);

            glNormal3f(0,1,0); // ENCIMA
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,0.5,-0.5);

            glNormal3f(-1,0,0); // NA DIREITA
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,-0.5);

            glNormal3f(1,0,0); //NA ESQUERDA
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);
        
        glEnd();  
    glEndList();
}

 Container* containerNext = NULL; // CONTAINER SEGUINTE
 Container* containerPrev = NULL; // CONTAINER ANTERIOR

void detalhesDoBarco(){ // DETALHES DO BARCO
    Container* Container = barco-> containers.at(1);
    glColor3f(cR,cG,cB);
    float c_lw = 20; //LINHA CENTRAL
    float e_lw = 3; //LINHA DE BORDA
    glLineWidth(3);
    if(barco->getDir() == D_UP || barco->getDir() == D_DOWN){
        glPushMatrix();
        glTranslatef(-Container->getX(),Container->getY(),Container->getZ());
        glBegin(GL_LINES);
            //glVertex3f(0,0.51,-0.5);
            //glVertex3f(0,0.51,0.5);
            glColor3f(eR,eG,eB);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,0.5);
            if(barco->getDir() == D_UP){
                glVertex3f(0.5,0.51,0.5);
                glVertex3f(-0.5,0.51,0.5);
            }else if(barco->getDir() == D_DOWN){
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,-0.5);
            }
        glEnd();
        glPopMatrix();
    }else{
        glPushMatrix();
        glTranslatef(-Container->getX(),Container->getY(),Container->getZ());
        glBegin(GL_LINES);
            //glVertex3f(-0.5,0.51,0);
            //glVertex3f(0.5,0.51,0);
            glColor3f(eR,eG,eB);
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,-0.5);
            if(barco->getDir() == D_LEFT){
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(0.5,0.51,0.5);
            }else if(barco->getDir() == D_RIGHT){
                glVertex3f(-0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,0.5);
            }
        glEnd();
        glPopMatrix();
    }
    for(int i = 1; i <= barco->containers.size()-2; i++){
        Container = barco->containers.at(i);
        containerNext = barco->containers.at(i+1);
        containerPrev = barco->containers.at(i-1);
        float x = Container->getX();
        float z = Container->getZ();
        float aX = containerNext->getX();
        float aZ = containerNext->getZ();
        float bX = containerPrev->getX();
        float bZ = containerPrev->getZ();
        glPushMatrix();
        glTranslatef(-x,Container->getY(),z);
        if(z != bZ && z != aZ){ //EM CIMA OU EMBAIXO
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,-0.5); //LINHA CENTRAL
                glVertex3f(0,0.51,0.5);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(-0.5,0.51,-0.5); //BORDAS ABAIXO
                glVertex3f(-0.5,0.51,0.5);
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(0.5,0.51,0.5);
            glEnd();
            glPopMatrix();
        }else if(x != bX && x != aX){ //ESQUERDA OU DIREITA
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(-0.5,0.51,0); //LINHA CENTRAL
                glVertex3f(0.5,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(-0.5,0.51,-0.5); //BORDAS ABAIXO
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,0.5);
                glVertex3f(0.5,0.51,0.5);
            glEnd();
        }else if(x > bX && z < aZ){  //DIREITA OU EM CIMA
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,0);
                glVertex3f(0.5,0.51,0);
                glVertex3f(0,0.51,0.5);
                glVertex3f(0,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(-0.5,0.51,-0.5);
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,0.5);
                glVertex3f(-0.5,0.51,-0.5);
            glEnd();
        }else if(x < bX && z < aZ){ //ESQUERDA OU EM CIMA
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,0);
                glVertex3f(-0.5,0.51,0);
                glVertex3f(0,0.51,0.5);
                glVertex3f(0,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,-0.5);
                glVertex3f(0.5,0.51,0.5);
                glVertex3f(0.5,0.51,-0.5);
            glEnd();
        }else if(x > bX && z > aZ){ //DIREITA OU ABAIXO
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,0);
                glVertex3f(0.5,0.51,0);
                glVertex3f(0,0.51,-0.5);
                glVertex3f(0,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(-0.5,0.51,0.5);
                glVertex3f(0.5,0.51,0.5);
                glVertex3f(-0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,0.5);
            glEnd();
        }else if(x < bX && z > aZ){ //ESQUERDA OU ABAIXO
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,0);
                glVertex3f(-0.5,0.51,0);
                glVertex3f(0,0.51,-0.5);
                glVertex3f(0,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(0.5,0.51,0.5);
                glVertex3f(-0.5,0.51,0.5);
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(0.5,0.51,0.5);
            glEnd();
        }else if(x < aX && z < bZ){  //DIREITA OU ACIMA
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,0);
                glVertex3f(-0.5,0.51,0);
                glVertex3f(0,0.51,0.5);
                glVertex3f(0,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,-0.5);
                glVertex3f(0.5,0.51,0.5);
                glVertex3f(0.5,0.51,-0.5);
            glEnd();
        }else if(x > aX && z < bZ){ // ESQUERDA OU ACIMA
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,0);
                glVertex3f(0.5,0.51,0);
                glVertex3f(0,0.51,0.5);
                glVertex3f(0,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(-0.5,0.51,-0.5);
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,0.5);
                glVertex3f(-0.5,0.51,-0.5);
            glEnd();
        }else if(x < aX && z > bZ){ //DIREITA OU ABAIXO
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,0);
                glVertex3f(-0.5,0.51,0);
                glVertex3f(0,0.51,-0.5);
                glVertex3f(0,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(0.5,0.51,0.5);
                glVertex3f(-0.5,0.51,0.5);
                glVertex3f(0.5,0.51,-0.5);
                glVertex3f(0.5,0.51,0.5);
            glEnd();
        }else if(x > aX && z > bZ){ //ESQUERDA OU ABAIXO
            glLineWidth(c_lw);
            glBegin(GL_LINES);
                glColor3f(cR,cG,cB);
                glVertex3f(0,0.51,0);
                glVertex3f(0.5,0.51,0);
                glVertex3f(0,0.51,-0.5);
                glVertex3f(0,0.51,0);
            glEnd();
            glLineWidth(e_lw);
            glBegin(GL_LINES);
                glColor3f(eR,eG,eB);
                glVertex3f(-0.5,0.51,0.5);
                glVertex3f(0.5,0.51,0.5);
                glVertex3f(-0.5,0.51,-0.5);
                glVertex3f(-0.5,0.51,0.5);
            glEnd();
        }
        glPopMatrix();
    }
    Container = barco->containers.at(barco->containers.size()-2); //ULTIMO CONTAINER
    containerPrev = barco->containers.at(barco->containers.size()-3);
    glPushMatrix();
    glTranslatef(-Container->getX(),Container->getY(),Container->getZ());
    if(Container->getX() > containerPrev->getX()){ //ESQUERDA
        glLineWidth(c_lw);
        glBegin(GL_LINES);
            glColor3f(cR,cG,cB);
            glVertex3f(0,0.51,0);
            glVertex3f(0.5,0.51,0);
        glEnd();
        glLineWidth(e_lw);
        glBegin(GL_LINES);
            glColor3f(eR,eG,eB);
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,0.5);
        glEnd();
    }else if(Container->getX() < containerPrev->getX()){ //DIREITA
        glLineWidth(c_lw);
        glBegin(GL_LINES);
            glColor3f(cR,cG,cB);
            glVertex3f(-0.5,0.51,0);
            glVertex3f(0,0.51,0);
        glEnd();
        glLineWidth(e_lw);
        glBegin(GL_LINES);
            glColor3f(eR,eG,eB);
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,0.5);
        glEnd();
    }else if(Container->getZ() < containerPrev->getZ()){ //ACIMA
        glLineWidth(c_lw);
        glBegin(GL_LINES);
            glColor3f(cR,cG,cB);
            glVertex3f(0,0.51,0);
            glVertex3f(0,0.51,0.5);
        glEnd();
        glLineWidth(e_lw);
        glBegin(GL_LINES);
            glColor3f(eR,eG,eB);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,-0.5);
        glEnd();
    }else if(Container->getZ() > containerPrev->getZ()){ //ABAIXO
        glLineWidth(c_lw);
        glBegin(GL_LINES);
            glColor3f(cR,cG,cB);
            glVertex3f(0,0.51,-0.5);
            glVertex3f(0,0.51,0);
        glEnd();
        glLineWidth(e_lw);
        glBegin(GL_LINES);
            glColor3f(eR,eG,eB);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,0.5);
        glEnd();
    }
    glPopMatrix();
    glLineWidth(2);
}

void desenhaMar(void){ // DESENHA O QUADRADO DO MAR E SEUS DETALHES

    glLineWidth(1); // LINHA
    glColor3ub(15,2,83); // COR DO MAR

    // QUADRADO DO MAR
    glBegin(GL_QUADS); 
        glNormal3f(0,1,0);
        glVertex3f(-5-0.5,-0.51,-6.5);
        glColor3ub(15,2,23); // COR DO MAR
        glVertex3f(-5-0.5,-0.51,6.5);
        glColor3ub(15,2,23); // COR DO MAR
        glVertex3f(6-0.5,-0.51,6.5);
         glColor3ub(15,2,83); // COR DO MAR
        glVertex3f(6-0.5,-0.51,-6.5);
    glEnd();

    // PRAIA
    glColor3f(0.6,0.7,0.2);
    for(int i = -5; i <= 5; i++){ // AO REDOR DO MAR

        glPushMatrix();
        glTranslatef(-6,0,i);
        glCallList(cubopadrao); // GERA CONTAINERS PADRÃO
        glColor3f(0.9,0.8,0.2);
        glLineWidth(10);
        glLineWidth(2);
        glBegin(GL_LINES); // LINHA DE CONTORNO
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,0.5);
        glEnd();
     glColor3f(0.6,0.7,0.2);
     glPopMatrix();


        glPushMatrix();
        glTranslatef(6,0,i);
        glCallList(cubopadrao); // GERA CONTAINERS PADRÃO
        glColor3f(0.9,0.8,0.2);
        glLineWidth(10);
        glLineWidth(2);
        glBegin(GL_LINES); // LINHA DE CONTORNO
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,0.5);
        glEnd();
     glColor3f(0.6,0.7,0.2);
     glPopMatrix();


        glPushMatrix();
        glTranslatef(i,0,-6);
        glCallList(cubopadrao);  // GERA CONTAINERS PADRÃO
        glColor3f(0.9,0.8,0.2);
        glLineWidth(10);
        glLineWidth(2);
        glBegin(GL_LINES); // LINHA DE CONTORNO
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,-0.5);
        glEnd();
     glColor3f(0.6,0.7,0.2);
     glPopMatrix();


        glPushMatrix();
        glTranslatef(i,0,6);
        glCallList(cubopadrao);  // GERA CONTAINERS PADRÃO
        glColor3f(0.9,0.8,0.2);
        glLineWidth(10);
        glLineWidth(2);
        glBegin(GL_LINES); // LINHA DE CONTORNO
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,-0.5);
        glEnd();
        glColor3f(0.6,0.7,0.2);
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(6,0,6); 
    glCallList(cubopadrao);  // GERA CONTAINERS PADRÃO
     glColor3f(0.9,0.8,0.2);
        glLineWidth(10);   
        glLineWidth(2);
        glBegin(GL_LINES);  // LINHA DE CONTORNO
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(-0.51,0.51,-0.51);
            glVertex3f(-0.51,-0.51,-0.51);
        glEnd();
     glColor3f(0.6,0.7,0.2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-6,0,6);
    glCallList(cubopadrao);  // GERA CONTAINERS PADRÃO
    glColor3f(0.9,0.8,0.2);
        glLineWidth(10);
        glLineWidth(2);
        glBegin(GL_LINES);  // LINHA DE CONTORNO
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.51,0.51,-0.51);
            glVertex3f(0.51,-0.51,-0.51);
        glEnd();
     glColor3f(0.6,0.7,0.2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-6,0,-6); 
    glCallList(cubopadrao);  // GERA CONTAINERS PADRÃO
     glColor3f(0.9,0.8,0.2);
        glLineWidth(10);
        glLineWidth(2);
        glBegin(GL_LINES); // LINHA DE CONTORNO
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(-0.5,0.51,0.5);
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.51,0.51,0.51);
            glVertex3f(0.51,-0.51,0.51);
        glEnd();
     glColor3f(0.6,0.7,0.2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6,0,-6);
    glCallList(cubopadrao);  // GERA CONTAINERS PADRÃO
     glColor3f(0.9,0.8,0.2);
        glLineWidth(10);
        glLineWidth(2);
        glBegin(GL_LINES);  // LINHA DE CONTORNO
            glVertex3f(-0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(0.5,0.51,0.5);
            glVertex3f(0.5,0.51,-0.5);
            glVertex3f(-0.51,0.51,0.51);
            glVertex3f(-0.51,-0.51,0.51);
        glEnd();
     glColor3f(0.6,0.7,0.2);
    glPopMatrix();
}

float yCamPos = 4.5f; // DEFINE POSIÇÃO VERTICAL DA CÂMERA

void redimensionaTela(int w, int h){ // REDIMENSIONAMENTO DA TELA 
    if(h == 0) // SE O H FOR 0
        h = 1; // REDEFINE PARA 1
    float ratio = w*1.0f/h; // AJUSTE DO RAIO
    glMatrixMode(GL_PROJECTION); // CHAMA PROJEÇÃO
    glLoadIdentity(); // CARREGA INDENTIDADE
    glViewport(0,0,w,h); // INVOCA VIEWPORT
    gluPerspective(60,ratio,0.5,60); // CONFIGURA PERSPECTIVA
    glMatrixMode(GL_MODELVIEW); 
}
   float angle = 0.0f; // ANGULO DAS NUVENS
   float sol = 0.0f; // ANGULO DO SOL

void draw(void){ // FAZ O DESENHOS
    glClearColor(0.3f, 0.3f, 0.8f, 0.5f);	
    barco->update(); // ATUALIZA POSIÇÃO DO BARCO
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // DEFINE CORES
    glLoadIdentity(); // CARRREGA INDENTIDADE
    gluLookAt( // CONFIGURA CÂMERA
        0,yCamPos,-10, //OLHO
        0,0,0,  //CENTRO
        0,1,0   //UP
    );

   glColor3f (1.0, 1.0, 0);
   glPushMatrix();
   glTranslatef(4.0,4.5, 0.0);
   sol+=2.0f;
   glRotatef(sol,0,1,0);
   glutSolidSphere(1.0, 20, 16);  
   glPopMatrix();

  glPushMatrix();
    glTranslatef(0.0, 4.0, 0.0);
    angle+=2.0f;
   glRotatef(angle,0,1,0);
     glColor3f (1.0, 1.0, 1.0);   
      glutSolidSphere(0.5, 20, 16);  
      glutSolidSphere(0.5, 20, 16); 
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 3.5, 0.0);
    angle+=2.0f;
   glRotatef(angle,0,1,0);
     glColor3f (1.0, 1.0, 1.0);   
      glutSolidSphere(0.5, 20, 16);  
      glutSolidSphere(0.5, 20, 16); 
    glPopMatrix();

  glPushMatrix();
    glTranslatef(0.3, 4.0, 0.0);
    angle+=2.0f;
   glRotatef(angle,0,1,0);
     glColor3f (1.0, 1.0, 1.0);   
      glutSolidSphere(0.5, 20, 16);  
      glutSolidSphere(0.5, 20, 16); 
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.6, 3.5, 0.0);
        angle+=2.0f;
   glRotatef(angle,0,1,0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glutSolidSphere(0.5, 20, 16); 
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.5, 4.5, 0.0);
        angle+=2.0f;
   glRotatef(angle,0,1,0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glutSolidSphere(0.5, 20, 16); 
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.4, 4.0, 0.0);
        angle+=2.0f;
   glRotatef(angle,0,1,0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glutSolidSphere(0.5, 20, 16); 
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.2, 3.5, 0.0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glutSolidSphere(0.5, 20, 16); 
        glPopMatrix();


        glPushMatrix();
        glTranslatef(-3.0, 4.0, 1.0);
        angle+=2.0f;
   glRotatef(angle,0,1,0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2.5, 4.0, 1.0);
        angle+=2.0f;
   glRotatef(angle,0,1,0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.0, 3.5, 1.0);
        angle+=2.0f;
   glRotatef(angle,0,1,0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.5, 4.0, 1.0);
        angle+=2.0f;
   glRotatef(angle,0,1,0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.5, 4.5, 1.0);
        angle+=2.0f;
   glRotatef(angle,0,1,0);
        glColor3f (1.0, 1.0, 1.0);   
        glutSolidSphere(0.5, 20, 16);  
        glPopMatrix();

        desenhaMar(); // DESENHA MAR
        barco->draw(); // DESENHA BARCO
        detalhesDoBarco();
        tesouro->draw(); // DESENHA TESOURO
        glutSwapBuffers(); // INICIA BUFFER
}

void specialKeys(int key, int x, int y){ // TECLAS DO TECLADO P/ MOVIMENTAR BARCO
    switch(key){
        case GLUT_KEY_F1:
            exit(0);
            break;
        case GLUT_KEY_LEFT:
            barco->move(D_LEFT); // MOVE PARA A ESQUERDA
            break;
        case GLUT_KEY_RIGHT:
            barco->move(D_RIGHT); // MOVE PARA A DIREITA
            break;
        case GLUT_KEY_UP:
            barco->move(D_UP); // MOVE PARA CIMA
            break;
        case GLUT_KEY_DOWN:
            barco->move(D_DOWN); // MOVE PARA BAIXO
            break;
    }
}

    GLfloat luzDifusa[] = {1,1,1,1}; // DEFINE LUZ DIFUSA
    GLfloat luzAmbiente[] = {0.5,0.5,0.5,1}; // DEFINE LUZ AMBIENTE 
    GLfloat psosicaoDaLuz[] = {0,3,0}; // DEFINE POSIÇÃO DA LUZ

void initGL(void){
    glShadeModel(GL_SMOOTH); // Especifica um valor simbólico representando uma técnica de sombreamento.
    glEnable(GL_DEPTH_TEST); // Faz comparações de profundidade e atualize o buffer de profundidade.
    glLightfv(GL_LIGHT1,GL_AMBIENT,luzAmbiente); //Luz ambiente
    glLightfv(GL_LIGHT1,GL_DIFFUSE,luzDifusa); // Luz difusa
    glLightfv(GL_LIGHT1,GL_POSITION,psosicaoDaLuz); // Posição da luz
    glEnable(GL_LIGHT1); // Inclui a luz 1 na avaliação da equação de iluminação
    glEnable(GL_LIGHTING); // Usa os parâmetros de iluminação atuais para calcular a cor do vértice. Caso contrário, simplesmente associe a cor atual a cada vértice. 
    glEnable(GL_COLOR_MATERIAL); // Os parâmetros ambiente e difuso rastreiam a cor atual
}

void mouseEvents(int button, int dir, int x, int y){ //FUNÇÃO MOUSE PARA ZOOM
    switch(button){
        case 3: //SCROLL PRA CIMA ZOOM PRA PERTO
            printf("zoom pra perto\n");
            yCamPos -= 0.5;
            break;
        case 4: //SCROLL PRA BAIXO ZOOM PRA LONGE
            printf("zoom pra longe\n");
            yCamPos += 0.5;
            break;
    }
}

void Anima(int value){
            tesouro -> draw(); // DESENHA TESOURO
            glutPostRedisplay(); // REDISPLAY
            glutTimerFunc(10, Anima, 1); //FUNÇÃO QUE ANIMA
}

int main(int argc, char **argv){
    srand(time(NULL));
    glutInit(&argc,argv);
    glutInitWindowPosition(-1,-1);
    glutInitWindowSize(900,900);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Trabalho Final de CG - Snake Ship");

    initGL();
    // Desenhos
    constroiCuboPadrao();
    constroiPontas();
    constroiVela();

    glutDisplayFunc(draw);
    glutIdleFunc(draw); 
    glutReshapeFunc(redimensionaTela); // Redimensiona telass
    glutSpecialFunc(specialKeys); // Eventos do teclado
    glutMouseFunc(mouseEvents); // Eventos do mouse
    glutTimerFunc(100, Anima, 1); // Função de animação

    glutMainLoop();

    return 1;
}