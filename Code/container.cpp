#include <GL/glut.h>

float cR = 0.2; float cG = 0.2; float cB = 0.1; // LINHAS DE CENTRO
float eR = 0.2; float eG = 0.2; float eB = 0.1; // LINHAS DE BORDO
float bR = 80; float bG = 80; float bB = 10; // COR PADRÃO DO BLOCO
GLuint cubopadrao; // Container para praia e barco
GLuint vela; // Container especial da vela com bandeira
GLuint ponta; // Container especial para pro e popa

// CONSTRUTOR
class Container{ // REPRESENTA CADA CONTAINER INDIVIDUAL DO BARCO
    public:
        Container(float pX, float pY,float pZ, float pSize=1.0f){
            x = pX; // COORDENADA X
            y = pY; // COORDENADA Y
            z = pZ; // COORDENADA Z
            size = pSize; // TAMANHO
            r = bR; g = bG; b = bB; //CORES DO BLOCO
        };

	// CONSTRUTOR
        ~Container();

	// GETTER E SETTERS
        void setX(float pX){x=pX;}; 
        void setY(float pY){y=pY;};
        void setZ(float pZ){z=pZ;};
        float getX(){return x;};
        float getY(){return y;};
        float getZ(){return z;};

	// COR
        void setColor(float pR,float pG,float pB){r=pR;g=pG;b=pB;}; 

	//DESENHA BLOCOS DA PRAIA E BARCO
        void drawnormal(){ 
            glPushMatrix(); // CHAMA MATRIZ
            glTranslatef(-x,y,z); // TRANSLADA

            if(r > 1 || g > 1 || b > 1){ // VERIFICA O FORMATO DAS CORES
                glColor3ub(r,g,b);
            }else{
                glColor3f(r,g,b);
            }

            glCallList(cubopadrao); //CHAMA A LISTA DE CUBOS
            glPopMatrix(); // ENCERRA
        };

        void drawvela(){ 
            glPushMatrix(); // CHAMA MATRIZ
            glTranslatef(-x,y,z); // TRANSLADA


            if(r > 1 || g > 1 || b > 1){ // VERIFICA O FORMATO DAS CORES
                glColor3ub(r,g,b);
            }else{
                glColor3f(r,g,b);
            } 
        glCallList(vela); //CHAMA A LISTA DE CUBOS
        glPopMatrix();
        };

        // DESENHA BLOCO DA VELA
        void drawponta(){
              glPushMatrix(); // CHAMA MATRIZ
            glTranslatef(-x,y,z); // TRANSLADA

            if(r > 1 || g > 1 || b > 1){ // VERIFICA O FORMATO DAS CORES
                glColor3ub(r,g,b);
            }else{
                glColor3f(r,g,b);
            }

            glCallList(ponta); //CHAMA A LISTA DE CUBOS
            glPopMatrix(); // ENCERRA
        };


    private:
        float x,y,z,size,r,g,b; // ATRIBUTOS PRIVADOS
};