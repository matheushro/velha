#include <iostream>
#define LINHA 3
#define COLUNA 3
void tabuleiro (char velha[LINHA][COLUNA]){
    for(int linha = 0; linha < LINHA; linha++){
        for(int coluna = 0; coluna < COLUNA; coluna++){
            std::cout << velha[linha][coluna] << " | ";
        }
        std::cout << "\n";
    }
}
int main (){
    int jogada_linha = 0;
    int jogada_coluna = 0;
    bool jogador = 0;
    int checar_jogada = 0;
    char sinal = ' ';
    // inicia o tabuleiro com valores vazios
    char velha[LINHA][COLUNA];
    for(int linha = 0; linha < LINHA; linha++){
        for(int coluna = 0; coluna < COLUNA; coluna++){
            velha[linha][coluna] = ' ';
        }
    }
    //inicio do jogo
    for(int jogada = 0; jogada < 9; jogada++){
    	system("cls");
    	do{
    		checar_jogada = 0;
    		//define quem e o jogador
    		if(!jogador){
    			sinal = 'x';
			} else if(jogador){
				sinal = 'o';
			}
    		tabuleiro(velha);
    		//pede valores de linha e coluna
	        std::cout << sinal << " jogador, escolha uma linha entre 1 e 3: ";
	        std::cin >> jogada_linha;
	        jogada_linha--;
	        std::cout << sinal << " jogador, escolha uma coluna entre 1 e 3: ";
	        std::cin >> jogada_coluna;
	        jogada_coluna--;
		    //checa se e uma posicao valida
		    if(jogada_coluna < 3 && jogada_coluna >= 0 && jogada_linha < 3 && jogada_linha >= 0){
	        	if(velha[jogada_coluna][jogada_linha] == ' '){
	        		//checa quem e o jogador e adiciona o valor dependendo do sinal
	        		if(!jogador){
			            velha[jogada_linha][jogada_coluna] = sinal;
			            jogador = 1;
			            checar_jogada = 1;
			        } else if(jogador){
			            velha[jogada_linha][jogada_coluna] = sinal;
			            jogador = 0;
			            checar_jogada = 1;
			        }
			   }else{
			   		std::cout << "Posicao ocupada!\n";	
			   }
			}else{
				std::cout << "posicao incorreta!\n";
			} 
		}while(checar_jogada == 0);
		//checa vencedor
		if((velha[0][0] == sinal && velha[0][1] == sinal && velha[0][2] == sinal)||
		   (velha[1][0] == sinal && velha[1][1] == sinal && velha[1][2] == sinal)||
		   (velha[2][0] == sinal && velha[2][1] == sinal && velha[2][2] == sinal)||
		   (velha[0][0] == sinal && velha[1][1] == sinal && velha[2][2] == sinal)||
		   (velha[1][2] == sinal && velha[1][1] == sinal && velha[2][0] == sinal)||
		   (velha[0][0] == sinal && velha[1][0] == sinal && velha[2][0] == sinal)||
		   (velha[0][1] == sinal && velha[1][1] == sinal && velha[2][1] == sinal)||
		   (velha[0][2] == sinal && velha[1][2] == sinal && velha[2][2] == sinal)){
		   		system("cls");
		   		tabuleiro(velha);
		   		std::cout << "Jogador " << sinal << " venceu! Parabens!!!!";
		   		return 0;
		   }
    }
    system("cls");
    tabuleiro(velha);
    std::cout << "Deu velha!";
    return 0;
}