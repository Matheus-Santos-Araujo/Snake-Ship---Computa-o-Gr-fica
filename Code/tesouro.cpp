#include <GL/glut.h>
#include <stdio.h>

class Tesouro{
    public:
        Tesouro(int pX, int pZ){
            x = pX; // POSIÇÃO X
            z = pZ; // POSICAO Y
            angle = 0.0f; // ANGULO
        };

        ~Tesouro(); // CONSTRUTOR

        void draw(){ // DESENHA TESOURO
            angle+=2.0f; // ANGULO DE ROTAÇÃO
            glPushMatrix(); // CHAMA MATRIZ
            glTranslatef(-x,0,z); // TRANSLADA
            //glRotatef(45,0,0,1);
            glRotatef(angle,0,1,0); // ROTACIONA COM O ANGULO
            glScalef(0.9, 0.9, 0.9); // DIMINUI O TESOURO
            //glutSolidCube(1);
            float gC = 0.5; // DEFINE COR
            glColor3f(0.8,0.8,0); // COLORE O TESOURO
            
            // CUBO QUE REPRESENTA TESOURO
            glBegin(GL_POLYGON);            
            glVertex3f( -0.5, -0.5, -0.5);       // P1
            glVertex3f( -0.5,  0.5, -0.5);       // P2
            glVertex3f(  0.5,  0.5, -0.5);       // P3
            glVertex3f(  0.5, -0.5, -0.5);       // P4
            glEnd();

            glColor3f(0.5,0.5,0);
            // TRASEIRA
            glBegin(GL_POLYGON);
            glVertex3f(  0.5, -0.5, 0.5 );
            glVertex3f(  0.5,  0.5, 0.5 );
            glVertex3f( -0.5,  0.5, 0.5 );
            glVertex3f( -0.5, -0.5, 0.5 );
            glEnd();
            
             glColor3f(0.7,0.7,0);
            // DIREITA
            glBegin(GL_POLYGON);
            glVertex3f( 0.5, -0.5, -0.5 );
            glVertex3f( 0.5,  0.5, -0.5 );
            glVertex3f( 0.5,  0.5,  0.5 );
            glVertex3f( 0.5, -0.5,  0.5 );
            glEnd();
            
             glColor3f(0.9,0.9,0);
            // ESQUERDA
            glBegin(GL_POLYGON);
            glVertex3f( -0.5, -0.5,  0.5 );
            glVertex3f( -0.5,  0.5,  0.5 );
            glVertex3f( -0.5,  0.5, -0.5 );
            glVertex3f( -0.5, -0.5, -0.5 );
            glEnd();
            
            glColor3f(0.6,0.6,0);
            // TOPO
            glBegin(GL_POLYGON);
            glVertex3f(  0.5,  0.5,  0.5 );
            glVertex3f(  0.5,  0.5, -0.5 );
            glVertex3f( -0.5,  0.5, -0.5 );
            glVertex3f( -0.5,  0.5,  0.5 );
            glEnd();
            
            // BASE
            glColor3f(0.8,0.8,0);
            glVertex3f(  0.5, -0.5, -0.5 );
            glVertex3f(  0.5, -0.5,  0.5 );
            glVertex3f( -0.5, -0.5,  0.5 );
            glVertex3f( -0.5, -0.5, -0.5 );
            glEnd();
            glBindTexture(GL_TEXTURE_2D,0);
            glPopMatrix();
        };

        // GETTERS E SETTERS
        float getX(){
            return x;
            };
        float getZ(){
            return z;
            };
        float setX(float pX){
            x = pX;
            };
        float setZ(float pZ){
            z = pZ;
            };
        float getAngle(){
            return angle;
            };
    private:
        float x,z,angle;
};