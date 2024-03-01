#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int placa(int ponto1, int ponto2, int pontovelha, string jogador1, string jogador2){//imprimir o placar
    cout<<"\t\t\tJOGO DA VELHA\n";
    cout<<jogador1 <<"\n";
    cout<<"pontos: "<<ponto1<<"\n";
    cout<<jogador2 <<"\n";
    cout<<"pontos: "<<ponto2<<"\n";
    cout<<"velha\n";
    cout<<"pontos: "<<pontovelha<<"\n";
}
int tabuleiro(string casa1, string casa2, string casa3, string casa4, string casa5, string casa6, string casa7, string casa8, string casa9){
    cout<<"-----------------\n";
    cout<<"   "<<casa7<<" || "<<casa8<<" || "<<casa9<<"\n";
    cout<<"-----------------\n";
    cout<<"   "<<casa4<<" || "<<casa5<<" || "<<casa6<<"\n";
    cout<<"-----------------\n";
    cout<<"   "<<casa1<<" || "<<casa2<<" || "<<casa3<<"\n";
    cout<<"-----------------\n";
}//Imprimir o tabuleiro

int main() {
    int a=0, b=0, x, vitoria=0, ponto1=0, ponto2=0, pontovelha=0, troca=0, aux, jogadavelha=0;
    string jogador1, jogador2, valor="X";
    string casa1=" ", casa2=" ", casa3=" ", casa4=" ", casa5=" ", casa6=" ", casa7=" ", casa8=" ", casa9=" ";

    cout<<"\t\t\tJOGO DA VELHA\n";//faz o inicio da funçao pedindo informaçoes basicas.
    cout<<"Nome do primeiro jogador: \n";
    cin>>jogador1;
    cout<<"Nome do segundo jogador: \n";
    cin>>jogador2;

    system("cls");

    while(a==0){
        system("cls");//limpa tela e depois imprimi o jogo.
        placa(ponto1, ponto2, pontovelha, jogador1, jogador2);
        tabuleiro(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);
        
        aux=0;

        
        if(troca==0){//Pede para o jogador um iniciar e logo em seguida passa a vez para o proximo
            cout<<"Digite sua jogada, "<<jogador1 <<"\n";
            cin>>x;
            troca=1;
        }else{
            cout<<"Digite sua jogada, "<<jogador2<<"\n";
            cin>>x;
            troca=0;
        }
        //Sera feita a comparação se uma casa foi usada, sera dado seu valor para ela, de acordo com a casa escolhida.
        if(x==1 && casa1==" "){
            casa1=valor;
            aux=1;
        }
        if(x==2 && casa2==" "){
            casa2=valor;
            aux=1;
        }
        if(x==3 && casa3==" "){
            casa3=valor;
            aux=1;
        }
        if(x==4 && casa4==" "){
            casa4=valor;
            aux=1;
        }
        if(x==5 && casa5==" "){
            casa5=valor;
            aux=1;
        }
        if(x==6 && casa6==" "){
            casa6=valor;
            aux=1;
        }
        if(x==7 && casa7==" "){
            casa7=valor;
            aux=1;
        }
        if(x==8 && casa8==" "){
            casa8=valor;
            aux=1;
        }
        if(x==9 && casa9==" "){
            casa9=valor;
            aux=1;
        }
        //aux somente 1, se uma jogada for aprovada acima. Assim sera somando o valor de jogadas restante para velha e como foi aprovado o valor de x e o sera trocado.
        if(aux==1){
            jogadavelha++;
            if(valor=="X"){
                valor="O";
            }
            else{
                valor="X";
            }
        }else{
            cout<<"jogada invalida\n";//Caso a jogada nao seja valida, ela volta ao jogador para jogar novamente e informa jogado invalida.
            if(troca==0){
                troca=1;
            }else{
                troca=0;
            }
            system("pause");
        }
        //Em seguida, as proximas linhas comparam as vitorias. Caso ocorra o mesmo.
        if(casa1=="X" && casa2=="X" && casa3=="X" || casa4=="X" && casa5=="X" && casa6=="X" || casa7=="X" && casa8=="X" && casa9=="X" || casa1=="X" && casa4=="X" && casa7=="X" || casa2=="X" && casa5=="X" && casa8=="X" || casa3=="X" && casa6=="X" && casa9=="X" || casa1=="X" && casa5=="X" && casa9=="X" || casa7=="X" && casa5=="X" && casa3=="X"){
            vitoria=1;
        }

        if(casa1=="O" && casa2=="O" && casa3=="O" || casa4=="O" && casa5=="O" && casa6=="O" || casa7=="O" && casa8=="O" && casa9=="O" || casa1=="O" && casa4=="O" && casa7=="O" || casa2=="O" && casa5=="O" && casa8=="O" || casa3=="O" && casa6=="O" && casa9=="O" || casa1=="O" && casa5=="O" && casa9=="O" || casa7=="O" && casa5=="O" && casa3=="O"){
            vitoria=1;
        }
        
        if(vitoria==1){//Caso alguem ganhe, ele mostrara o resultado.
            if(troca==1){
                ponto1++;
            }else{
                ponto2++;
            }
            system("cls");
            placa(ponto1, ponto2, pontovelha, jogador1, jogador2);
            tabuleiro(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);
            if(troca==1){
                cout<<"Parabens ao jogador: "<<jogador1<<", voce venceu!\n";
            }else{
                cout<<"parabens ao jogador: "<<jogador2<<", voce venceu!\n";
            }
            cout<<"1-jogar novamente: \n";//Nessa parte, mostrara um menu de escolha, para definir o futuro do jogo.
            cout<<"2-reiniciar o jogo: \n";
            cout<<"3-sair: \n";
            cin>>b;
            if(b!=1 && b!=2 && b!=3){
                cout<<"houve um vencedor, reiniciando partida por informa valor fora da tabela\n";
                b=1;
                system("pause");
            }
            
        }

        if(jogadavelha==9 && vitoria==0){//Caso nenhum jogador venca a partida, vai imprimir na tela "A VELHA".
            pontovelha++;
            system("cls");
            placa(ponto1, ponto2, pontovelha, jogador1, jogador2);
            tabuleiro(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);
            cout<<"Ihh, DEU VELHA!\n";
            cout<<"1-jogar novamente: \n";
            cout<<"2-reiniciar o jogo: \n";
            cout<<"3-sair: \n";
            cin>>b;
            if(b!=1 && b!=2 && b!=3){
                cout<<"houve um vencedor, reiniciando partida por informa valor fora da tabela\n";
                b=1;
                system("pause");
            }
        }

        if(b==1){//Caso a opção jogar novamente seja selecionada, reiniciara o jogo, resentando o tabuleiro e as funçaoes de calculo.
            vitoria=0;
            casa1=" ", casa2=" ", casa3=" ", casa4=" ", casa5=" ", casa6=" ", casa7=" ", casa8=" ", casa9=" ";
            valor="X";
            b=0;
            jogadavelha=0;
        }
        if(b==2){//Caso o jogador queira jogar novamente, porém começando do zero, somente selecionar a segunda opçao, reiniciando o jogo por completo, sem precisar fechar e novos nomes serao solicitados.
            vitoria=0;
            casa1=" ", casa2=" ", casa3=" ", casa4=" ", casa5=" ", casa6=" ", casa7=" ", casa8=" ", casa9=" ";
            ponto1=0;
            ponto2=0;
            pontovelha=0;
            jogadavelha=0;
            valor="X";
            system("cls");
            cout<<"\t\t\tJOGO DA VELHA\n";
            cout<<"digite o nome do jogador 1: \n";
            cin>>jogador1;
            cout<<"digite o nome do jogador 2: \n";
            cin>>jogador2;
            b=0;
        }

        if(b==3){//Opçao para caso queira encerrar o jogo.
            a=1;
        }
        
        
    }
}