#include <GL/glut.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>

enum Dir{ D_LEFT, D_RIGHT, D_UP, D_DOWN }; // DIREÇÕES DO BARCO

Tesouro* tesouro = new Tesouro(1,1); // INVOCA OBJETO TESOURO

class Barco{ // CONTÉM DEFINIÇÕES, MOVIMENTO E COLISÃO DO BARCO

    public:
        std::vector<Container*> containers; // BARCO É UM ARRAY DE CONTAINERS

        Barco(float startX, float startZ, int containerCount){ //CONSTRÓI BARCO POSICAO INICIAL E NUMERO DE CONTAINES
            for(float i = 0; i < containerCount; i++){ // LAÇO PARA CRIAR CONTAINERS
                Container* temp = new Container(startX+i,0,startZ); // CRIANDO CONTAINERS INICIAIS
                if(i == 0)
                    temp->setColor(0.4,0.4,0.0); //COLORINDO ELES
                containers.push_back(temp); //ADICIONANDO ELES AO ARRAY
            }
            ehAtualizado = false; // INICIA FALSE PARA ATUALIZAÇÃO
            direcaoAtual = D_LEFT; // POSIÇÃO INICIAL É PRA ESQUERDA
            pontuacao = 0; // pontuacao INICIA ZERO
        }; 
        ~Barco(); // CONSTRUTOR DO BARCO

        void draw(){ // DESENHA BLOCOS

            Container* proa = containers.at(0);
            Container* popa = containers.at(containers.size() - 1);

            proa->drawponta();
            popa->drawponta();

            for(int i = 1; i <= containers.size()-2; i++){ // PERCORRE O ARRAY DE BLOCOS
                Container* temp = containers.at(i);
                if (i !=  (containers.size() - 1) / 2) {
                temp->drawnormal(); // DESENHA ELES
                } else { temp->drawvela(); }
            } 
        };     

        void move(Dir direcao){ //MOVIMENTO DO BARCO
            Container* proa = containers.at(0); // PEGA PROA DO BARCO

            if(direcao == D_LEFT && direcaoAtual != D_RIGHT){ //SE A DIREÇÃO FOR IGUAL A ESQUERDA E A ATUAL DIFERENTE DE DIREITA 
                pushBarco(); // CHAMA DEMAIS CONTAINERS
                proa->setX(proa->getX()-0.5f); // A CABEÇA VIRA ṔRA ESQUERDA
                direcaoAtual = direcao; // A DIREÇÃO ATUAL AGORA É ESQUERDA
                ehAtualizado = true; // É ATUALIZADO
            }else if(direcao == D_RIGHT && direcaoAtual != D_LEFT){ //SE A DIREÇÃO ATUAL FOR DIREITA E A ATUAL DIFERENTE DE ESQUERDA
                pushBarco();  // CHAMA DEMAIS CONTAINERS
                proa->setX(proa->getX()+0.5f);  // A CABEÇA VIRA ṔRA DIREITA
                direcaoAtual = direcao; // A DIREÇÃO ATUAL AGORA É DIREITA
                ehAtualizado = true; // É ATUALIZADO
            }else if(direcao == D_UP && direcaoAtual != D_DOWN){ //SE A DIREÇÃO FOR IGUAL A ACIMA E A ATUAL DIFERENTE DE ABAIXO 
                pushBarco(); // CHAMA DEMAIS CONTAINERS
                proa->setZ(proa->getZ()+0.5f); // A CABEÇA VIRA ṔRA CIMA
                direcaoAtual = direcao; // A DIREÇÃO ATUAL AGORA É ACIMA
                ehAtualizado = true; // É ATUALIZADO
            }else if(direcao == D_DOWN && direcaoAtual != D_UP){ //SE A DIREÇÃO FOR IGUAL A ABAIXO E A ATUAL DIFERENTE DE ACIMA 
                pushBarco(); // CHAMA DEMAIS CONTAINERS
                proa->setZ(proa->getZ()-0.5f); // A CABEÇA VIRA ṔRA BAIXO
                direcaoAtual = direcao; // A DIREÇÃO ATUAL AGORA É ABAIXO
                ehAtualizado = true; // É ATUALIZADO
            }

                if (proa->getX() < -5.0) {  
                   std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                   printf("Seu barco encalhou!\n"); // PRINTA O pontuacao
                   exit(0); // PERDEU, FECHA O JOGO 
                   }
               if (proa->getX() > 5.5) {  
                   std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
                   printf("Seu barco encalhou!\n"); 
                   exit(0); // PERDEU, FECHA O JOGO 
                   }
               if (proa->getZ() > 6.0) {  
                   std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
                   printf("Seu barco encalhou!\n"); 
                   exit(0); // PERDEU, FECHA O JOGO 
                   }
               if (proa->getZ() < -5.5) {   
                   std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                   printf("Seu barco encalhou!\n"); 
                   exit(0); // PERDEU, FECHA O JOGO 
                   }
        };

        void pushBarco(){ // AVANÇA JUNTO COM A PROA O RESTANTE DOS CONTAINERS
            for(int i = containers.size()-1; i >= 1; i--){ // PERCORRE DEMAIS CONTAINERS
                Container* temp = containers.at(i); 
                Container* containerAnterior = containers.at(i-1);
                temp->setX(containerAnterior->getX()); // ACOMPANHA EM X
                temp->setZ(containerAnterior->getZ()); // ACOMPANHA EM Z
            }
        };

        void update(){ // ATUALIZA A FUNÇÃO CHAMADA A CADA FRAME
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            if(!ehAtualizado) // SE O MOVIMENTO NÃO FOI ALTERADO DEIXE-O CONTINUAR
                move(direcaoAtual); // CONTINUE MOVENDO PARA A ATUAL DIREÇÃO
            ehAtualizado = false; // NÃO É ATUALIZADO
            deteccaoDeColisao(); // CHAMA DETECÇÃO DE COLISÃO
        };

        void deteccaoDeColisao(){ // CHECA DE O BARCO SE CHOCOU CONSIGO MESMO OU COM 
            float x = containers.at(0)->getX(); // PEGA PROA X
            float z = containers.at(0)->getZ(); // PEGA PROA Z

            if(tesouro->getX() == x && tesouro->getZ() == z){ // CHEGA COORDENADAS COM O TESOURO
                pontuacao++; // INCREMENTA A pontuacao
                printf("Pontuação = %i belly\n",pontuacao); // PRINTA A pontuacao
                bool deNovo = false; // NÃO REPITA
                
                do{ // CONFERE SE O TESOURO FOI PEGO
                    deNovo = false; // NÃO REPITA
                    tesouro->setX(rand()%11-5); // SETA NOVAMENTE TESOURO EM X ALEATORIO
                    tesouro->setZ(rand()%11-5); // SETA NOVAMENTE TESOURO EM Seta Y ALEATORIO
                    for(int i = 0; i<=containers.size()-1;i++){ // PERCORRE CONTAINERS
                        x = containers.at(i)->getX(); //X DO CONTAINER
                        z = containers.at(i)->getZ(); //Y DO CONTAINER
                        if(tesouro->getX()==x && tesouro->getZ()==z) //VERIFICA COORDENADAS TESOURO COM COORDENADAS DO CONTAINER
                            deNovo = true;
                    }
                }while(deNovo); // ENQUANTO É FALSO
                addContainer(); // ADICIONA CONTAINER
            }
            for(int i = 1; i<= containers.size()-1; i++){ // VERIFICA COLISÃO COM O CORPO
                if(containers.at(i)->getX() == containers.at(0)->getX() && containers.at(i)->getZ() == containers.at(0)->getZ()){ // SE AS COORDENADAS DA PROA SE BATE COM OUTRA
                    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
                   printf("Seu barco afundou!\n"); 
                   exit(0); // PERDEU, FECHA O JOGO
                }
            }
        };

        void addContainer(){ // ADICIONA NOVO CONTAINER AO BARCO
            Container* novoContainer = new Container(-100,0, -100); // DEFINE NOVO CONTAINER
            containers.push_back(novoContainer); // ADICIONAR ELE NO ARRAY DE CONTAINERS
        };

        Dir getDir(){return direcaoAtual;}; //PEGA ATUAL DIREÇÃO

    private:
        Dir direcaoAtual; // POSIÇÃO ATUAL
        bool ehAtualizado; // É ATUALIZADO
        int pontuacao; // pontuacao
};