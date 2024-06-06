/*

    Construção do baralho para o jogo

*/
struct baralho 
{
    int supertrunfo;
    char type; 
    char nomecarta[15]; 
    int attack; 
    int defense; 
    int stamina;

};
/*

    construção da função que embaralha as cartas do jogo

*/
void embaralhar(int baralho1[24], int baralho2[24]) {

    int aux, j = 0, baralho[24];
    srand(time(NULL));

    do {
        baralho[j] = rand() % 24;//sorteia numero aleatorio de 0 a 23//
        aux = 0;
        for( int i=0; i<j; i++ ) {
            if(baralho[i] == baralho[j]) {//testa se algum numero ja repetiu//
                aux = 1;
            }
        }
        if(aux == 0) {
            j++;
        }
    } while (j < 24);//enquanto o vetor não tiver 24 numeros não  repetido o laço se mantem//

    // Divisão das posições do baralho principal entre os dos jogadores//
    for(int i=0; i<12; i++) {
        baralho1[i] = baralho[i];//metade para o jogador 1//
        baralho2[i] = baralho [i+12];//segunda metade para o jogador 2//
    }

    return;
}
/*


vitória do jogador 1



*/
int vitoria1(int baralho1[24], int baralho2[24], int mesa[24], int contador_jogador[3], int vez_jogador) {

    baralho1[contador_jogador[0]] = baralho1[0];//posiciona as cartas ja utilizadas nos baralhos//
    contador_jogador[0] ++;
    baralho1[contador_jogador[0]] = baralho2[0];//posiciona as cartas ja utilizadas nos baralhos//
    contador_jogador[1] --;

    int j = 0;
    //arruma as posições das cartas nos baralhos após uma rodada//
    while(j < contador_jogador[0]) {
        baralho1[j] = baralho1[j+1];
        j++;
    }

    j = 0;
    //arruma as posições das cartas nos baralhos após uma rodada//
    while (j < contador_jogador[1]) {
        baralho2[j] =  baralho2[j+1];
        j++;
    }
    vez_jogador = 1;//define o jogador da vez//

    //se tiver cartas na mesa, joga elas pro baralho vencedor//
    if(contador_jogador[2] > 0) {

        while(contador_jogador[2] > 0) {
            baralho1[contador_jogador[0]] = mesa[contador_jogador[2]];
            contador_jogador[0] ++;
            contador_jogador[2] --;
        }
    }

    printf ("\nJogador 1 ganhou a rodada!!\n");
    printf("cartas restante jogador 1-%d\tjogador 2-%d", contador_jogador[0], contador_jogador[1]);

    return vez_jogador;
}
/*

vitóruia jogador 2


*/
int vitoria2(int baralho1[24], int baralho2[24], int mesa[24], int contador_jogador[3], int vez_jogador) {

    baralho2[contador_jogador[1]] = baralho2[0];//joga as cartas pro baralho vencedor//
    contador_jogador[1] ++;
    baralho2[contador_jogador[1]] = baralho1[0];
    contador_jogador[0] --;

    int j = 0;
    while(j < contador_jogador[0]) {
        //arrunma as posições das cartas//
        baralho1[j] = baralho1[j+1];
        j++;
    }

    j = 0;
    while(j < contador_jogador[1]) {
        //arruma as posições das cartas//
        baralho2[j] = baralho2[j+1];
        j++;
    }
    vez_jogador = 0;//define o jogador da vez//

    //se tiver cartas na mesa atribui elas ao baralho ganhador da rodada//
    if (contador_jogador[2] > 0) {

        while (contador_jogador[2] > 0) {
            baralho2[contador_jogador[1]] = mesa[contador_jogador[2]];
            contador_jogador[1] ++;
            contador_jogador[2]--;
        }
    }

    printf ("\nJogador 2 ganhou a rodada!!\n");
    printf("cartas restante jogador 1-%d\tjogador 2-%d", contador_jogador[0], contador_jogador[1]);

    return vez_jogador;
}
/*

empate

*/
int empate(int baralho1[24], int baralho2[24], int mesa[24], int contador_jogador[3], int vez_jogador) {

    mesa[contador_jogador[2]] = baralho1[0];//cartas que empataram vao para a mesa//
    contador_jogador[2]++;
    mesa[contador_jogador[2]] = baralho2[0];
    contador_jogador[2]++;

    int j = 0;
    while (j < contador_jogador[0]) {
        //arruma as posições dos baralhos//
        baralho1[j] = baralho1[j+1];
        j++;
    }
    contador_jogador[0] --;

    j = 0;
    while(j < contador_jogador[1]) {
        baralho2[j] = baralho2[j+1];
    }
    contador_jogador[1] --;

    printf("\nhouve empate!!\n");
    printf("cartas restante jogador 1-%d\tjogador 2-%d", contador_jogador[0], contador_jogador[1]);

    return vez_jogador;
}

/*
 verifica vitória
 */

int verificaVitoria(int contador) {
   if (contador == 24) {
       return 1;
   }
   return 0;
}

/*

contrução da função que roda o jogo

*/
void jogo() {

    int baralho1[24], baralho2[24], mesa[24];//atribuição de valores as cartas//
    struct baralho card [24] = {1, 'A', "Mewtwo",       300,    182,    214, 
                                0, 'A', "Dragonite",    263,    198,    209,
                                0, 'A', "Gyarados",     237,    186,    216,
                                0, 'A', "Venossauro",   198,    189,    191,
                                0, 'A', "Charizard",    223,    173,    186,
                                0, 'A', "Blastoise",    171,    207,    188,
                                0, 'B', "Gengar",       261,    149,    155,
                                0, 'B', "Lapras",       165,    174,    277,
                                0, 'B', "Porygon",      153,    136,    163,
                                0, 'B', "Rhyhorn",      140,    127,    190,
                                0, 'B', "Pidgeot",      166,    154,    195,
                                0, 'B', "Beedrill",     169,    130,    162,
                                0, 'C', "Butterfree",   167,    135,    155,
                                0, 'C', "Grimer",       135,    90,     189,
                                0, 'C', "Raticate",     161,    139,    146,
                                0, 'C', "Lickitung",    108,    137,    207,
                                0, 'C', "Bulbasaur",    118,    111,    128,
                                0, 'C', "Charmander",   116,    93,     118,
                                0, 'D', "Squirtle",     94,     121,    127,
                                0, 'D', "Pikachu",      112,    96,     111,
                                0, 'D', "Ratata",       103,    70,     102,                             
                                0, 'D', "Weedle",       63,     50,     120,
                                0, 'D', "Caterpie",     55,     55,     126,
                                0, 'D', "Magikarp",     29,     85,     86};
    int contador_jogador[3], vez_jogador;
    int i, j;
    contador_jogador[0] = 12;//contador de cartas do jogador 1//
    contador_jogador[1] = 12;//contador de cartas do jogador 2//
    contador_jogador[2] = 0;//contador de cartas da mesa//
    vez_jogador = 1;//variavel que controla quem é o jogador da vez//
    embaralhar (baralho1, baralho2);//chama função que monta os baralhos//

    do { //laço em que roda o jogo//
        //vez do jogador 1
        if (vez_jogador == 1) {
            /* 
           
            situação do ataque ser maior 
                        
            */
            if (card[baralho1[0]].attack > card[baralho1[0]].defense && card[baralho1[0]].attack > card[baralho1[0]].stamina ) {

                if (card[baralho2[0]].supertrunfo == 1) { //testa se o jogador 2 tem carta super trunfo na vez do jogador 1//

                    if (card[baralho1[0]].type ==  'A') {//testa se jogador 1 tem carta tipo A//

                        printf("jogador 2: Super Trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: Carta tipo A!!\n");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return ;
                        }
                        getchar();
                    } else {//situação caso adversario tenha super trunfo e o jogador da vez não tenha carta tipo A//

                        printf("jogador 2 : super trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: ");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                        getchar();
                    } 
                } else if (card[baralho1[0]].supertrunfo == 1) {//testa se o jogador 1 tem super trunfo//

                    if (card[baralho2[0]].type == 'A') {// testa se jogador 2 tem carta do tipo A//

                        printf("jogador 1:Super Trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: Carta tipo A!!\n");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                        getchar();
                    } else {//jogador 1 tem super trunfo e o jogador 2 não tem carta do tipoo A//

                        printf("Jogdor 1 : Super Trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: ");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return ;
                        }
                        getchar();
                    }
                    //caso nao for super trunfo compara//
                } else if (card[baralho1[0]].attack == card[baralho2[0]].attack) {//empate!! cartas vão para mesa//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("\njogador 1 Attack-%d\tjogador 2 Attack-%d\n", card[baralho1[0]].attack, card[baralho2[0]].attack);

                    vez_jogador = empate(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    getchar();

                } else if (card[baralho1[0]].attack > card[baralho2[0]].attack) {//situação do ataque do jogador 1 for maior que do jogador 2//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Attack-%d\tjogador 2 Attack-%d", card[baralho1[0]].attack, card[baralho2[0]].attack);

                    vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                        printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                        return ;
                    }
                    getchar();

                } else if (card[baralho2[0]].attack > card[baralho1[0]].attack) {//situação do ataque do jogador 2 ser maior que do jogador 1//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Attack-%d\tjogador 2 Attack-%d", card[baralho1[0]].attack, card[baralho2[0]].attack);

                    vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                        printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                        return ;
                    }
                    getchar();
                }
            }
            /* 
            
            situação da defesa ser maior 
            
            */
            else if (card[baralho1[0]].defense > card[baralho1[0]].attack && card[baralho1[0]].defense > card[baralho1[0]].stamina ) {

                //testa se o adversario tem super trunfo na vez do jogador //
                if (card[baralho2[0]].supertrunfo == 1) {

                    if (card[baralho1[0]].type == 'A') {//testa se o jogador da vez tem carta do tipo A//

                        printf("jogador 2: Super Trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: Carta tipo A!!\n");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return ;
                        }
                        getchar();
                    } else {//jopgador da vez não tem carta tipo A//

                        printf("jogador 2 : super trunfo!!\n");
                        puts (card[baralho2[0]].nomecarta);
                        printf("jogador 1: ");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                        getchar();
                    }
                } else if (card[baralho1[0]].supertrunfo == 1) {//testa se o jogador da vez tem carta super trunfo//

                    if(card[baralho2[0]].type == 'A') {//verifica s eo adversário não tem cartas tipo A//

                        printf("jogador 1: Super Trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 2: Carta tipo A!!\n");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                        getchar();
                    } else {//adversário nao tem carta do tipo A//

                        printf("jogador 1 super trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: ");
                        puts(card[baralho2[0]].nomecarta);
                        printf("%d\t%d", card[baralho1[0]].defense, card[baralho2[0]].defense);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return ;
                        }
                        getchar();
                    }
                    //caso não for super trunfo compara//
                } else if (card[baralho1[0]].defense == card[baralho2[0]].defense) {//empate!! cartas vao para mesa//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("%d\t%d", card[baralho1[0]].defense, card[baralho2[0]].defense);

                    vez_jogador = empate(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    getchar();

                } else if (card[baralho1[0]].defense > card[baralho2[0]].defense) {//defesa do jogador 1 é maior que defesa do jogador 2//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Defense-%d\tjogador 2 Defense-%d", card[baralho1[0]].defense, card[baralho2[0]].defense);

                    vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                        printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                        return ;
                    }
                    getchar();
                } else if (card[baralho2[0]].defense > card[baralho1[0]].defense) {//defesa do jogador 2 é maior que defesa do jogador 1//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Defense-%d\tjogador 2 Defense-%d", card[baralho1[0]].defense, card[baralho2[0]].defense);

                    vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                }
            }
            /* 
            
            situação da stamina ser maior 
            
            */
            else if (card[baralho1[0]].stamina > card[baralho1[0]].attack && card[baralho1[0]].stamina > card[baralho1[0]].defense ) {

                if (card[baralho2[0]].supertrunfo == 1) {//testa se jogador 2 tem carta super trunfo na vez do jogador 1//

                    if (card[baralho1[0]].type == 'A') {//testa se jogador 1 tem carta do tipo A//

                        printf("jogador 2: Super Trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: Carta tipo A!!\n");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    } else {//jogador 1 não tem carta do tipo A//

                        printf("jogador 2 : super trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: ");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    }
                } else if (card[baralho1[0]].supertrunfo == 1) {//jogador 1 tem super trunfo//

                    if(card[baralho2[0]].type == 'A') {//jogador 2 tem carta do tipo A//

                        printf("jogador 1: Super Trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: Carta tipo A!!\n");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    } else {//jogador 1 não tem carta do tipo A//

                        printf("jogador 2: Super Trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: \n");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    }
                    // caso não for super trunfo compara
                } else if (card[baralho1[0]].stamina == card[baralho2[0]].stamina) {//empate!! cartas vao para a mesa//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Stamina-%d\tjogador 2 Stamina-%d", card[baralho1[0]].stamina, card[baralho2[0]].stamina);

                    vez_jogador = empate(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    getchar();
                }
                else if (card[baralho1[0]].stamina > card[baralho2[0]].stamina) {//stamina do jogador 1 é maior que stamina do jogador 2//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Stamina-%d\tjogador 2 Stamina-%d", card[baralho1[0]].stamina, card[baralho2[0]].stamina);

                    vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                } else if (card[baralho2[0]].stamina > card[baralho1[0]].attack) {//stamina do jogador 2 é maior que stamina do jogador 1//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Stamina-%d\tjogador 2 Stamina-%d", card[baralho1[0]].stamina, card[baralho2[0]].stamina);

                    vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                }
            }

        }
        /* 
        
        vez do jogador 2
        
        */
        else 
        {
            /*
            
            situação do ataque ser maior
            
            */
            if (card[baralho2[0]].attack > card[baralho2[0]].defense && card[baralho2[0]].attack > card[baralho2[0]].stamina ) {
                //compara se é super trunfo
                if (card[baralho1[0]].supertrunfo == 1) {
                    if(card[baralho2[0]].type == 'A') {//compara se o jogador 1 tem carta do tipo A//

                        printf("jogador 1: Super Trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: Carta tipo A!!\n");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    } else {//se jogador 2 não tem carta do tipo A//

                        printf("jogador 1: super trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: ");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    }
                } else if (card[baralho2[0]].supertrunfo == 1) {//jogador 2 tem  carta super trunfo//

                    if(card[baralho1[0]].type == 'A') {//jpgador 1 tem carta do tipo A//

                        printf("jogador 2: Super Trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: Carta tipo A!!\n");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    } else {//se o jogdaor 1 nao tiver carta do tipo A//

                        printf("jogador 2 super trunfo!!");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: ");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    }
                    // caso não for super trunfo compara
                } else if (card[baralho1[0]].attack == card[baralho2[0]].attack) {//empate!! cartas vao para a mesa//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Attack-%d\tjogador 2 Attack-%d", card[baralho1[0]].attack, card[baralho2[0]].attack);

                    vez_jogador = empate(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    getchar();
                } else if (card[baralho2[0]].attack > card[baralho1[0]].attack) {//jpgador 2 tem ataque maior que do jogador 1//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Attack-%d\tjogador 2 Attack-%d", card[baralho1[0]].attack, card[baralho2[0]].attack);

                    vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                } else if (card[baralho1[0]].attack > card[baralho2[0]].attack) {//jogador 1 tem ataque maior que o jogador 2//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Attack-%d\tjogador 2 Attack-%d", card[baralho1[0]].attack, card[baralho2[0]].attack);

                    vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                }
            }
            /*
            
            situação da defesa ser maior
            
            */
            else if (card[baralho2[0]].defense > card[baralho2[0]].attack && card[baralho2[0]].defense > card[baralho2[0]].stamina ) {
                //compara se é super trunfo//
                if (card[baralho1[0]].supertrunfo == 1) {
                    if(card[baralho2[0]].type == 'A') {//compara se o jogador 2 tem carta do tipo A//

                        printf("jogador 1: Super Trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: Carta tipo A!!\n");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    } else {//jogador 2 não tem carta do tipo A//

                        printf("jogador 1 : super trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: ");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    }
                } else if (card[baralho2[0]].supertrunfo == 1) {//verifica s eo jogador 2 nao tem super trunfo//

                    if(card[baralho1[0]].type == 'A') {//verifica se jogador 1 tem carta tipo A//

                        printf("jogador 2: Super Trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: Carta tipo A!!\n");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    } else {//jogador 1 nao tem carta do tipo A//

                        printf("jogador 2 super trunfo\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: ");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    }
                    // caso não for super trunfo compara
                } else if (card[baralho1[0]].defense == card[baralho2[0]].defense) {//empate!! cartas vão para a mesa//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Defense-%d\tjogador 2 Defense-%d", card[baralho1[0]].defense, card[baralho2[0]].defense);

                    vez_jogador = empate(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    getchar();
                } else if (card[baralho2[0]].defense > card[baralho1[0]].defense) {//jpgador 2 tem defesa maior que jogador 1//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Defense-%d\tjogador 2 Defense-%d", card[baralho1[0]].defense, card[baralho2[0]].defense);

                    vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                } else if (card[baralho1[0]].defense > card[baralho2[0]].defense) {//jpgador 1 tem defesa maior que jogador 2//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jpgador 1 Defense-%d\tjpgador 2 Defense-%d", card[baralho1[0]].defense, card[baralho2[0]].defense);

                    vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                }
            }
            /*
            
            situação da stamina ser maior
            
            */
            else if (card[baralho2[0]].stamina > card[baralho2[0]].attack && card[baralho2[0]].stamina > card[baralho2[0]].defense ) {

                if (card[baralho1[0]].supertrunfo == 1) { //compara se pe super trunfo//

                    if(card[baralho2[0]].type == 'A') {//compara se o jogador 2 tem carta do tipo A//

                        printf("jogador 1: Super Trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 2: Carta tipo A!!\n");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    } else {//jogador 2 nao tem carta do tipo A//

                        printf("jogador 1: super trunfo!!\n");
                        puts(card[baralho1[0]].nomecarta);
                        printf("jogador 1: ");
                        puts(card[baralho2[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                                printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                                return ;
                            }
                        getchar();
                    }
                } else if (card[baralho2[0]].supertrunfo == 1) {//jpgadpr 2 tem super trunfo//

                    if (card[baralho1[0]].type == 'A') {//jogador 1 tem carta do tipo A//

                        printf("Jogaodor 2: Super Trunfo!!\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: Carta tipo A!!\n");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return;
                        }
                        getchar();
                    } else {//jogador 1 nao tem carta do tipo A//

                        printf("jogador 2 super trunfo\n");
                        puts(card[baralho2[0]].nomecarta);
                        printf("jogador 1: ");
                        puts(card[baralho1[0]].nomecarta);

                        vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                        if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return;
                        }
                        getchar();
                    }
                    // caso não for super trunfo compara
                } else if (card[baralho1[0]].stamina == card[baralho2[0]].stamina) {//empate!! cartas vao para a mesa//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Stamina-%d\tjogador 2 Stamina-%d", card[baralho1[0]].stamina, card[baralho2[0]].stamina);

                    vez_jogador = empate(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    getchar();
                } else if (card[baralho2[0]].stamina > card[baralho1[0]].stamina) {//jpgador 2 tem estamina maior que jogador 1//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Stamina-%d\tjogador 2 Stamina-%d", card[baralho1[0]].stamina, card[baralho2[0]].stamina);

                    vez_jogador = vitoria2(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[1])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 2 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                } else if (card[baralho1[0]].stamina > card[baralho2[0]].stamina) {//jpgador 1 tem stamina maior que jogador 2//

                    printf("jogador 1: eu tenho:");
                    puts(card[baralho1[0]].nomecarta);
                    printf("jogador 2: eu tenho:");
                    puts(card[baralho2[0]].nomecarta);
                    printf("jogador 1 Stamina-%d\tjogador 2 Stamina-%d", card[baralho1[0]].stamina, card[baralho2[0]].stamina);

                    vez_jogador = vitoria1(baralho1, baralho2, mesa, contador_jogador, vez_jogador);

                    if (verificaVitoria(contador_jogador[0])) {//se jogador que venceu tem 24 cartas ele ganha o jogo//

                            printf("\n--JOGADOR 1 VENCEU O JOGO--\n");
                            return ;
                        }
                    getchar();
                }
            }
        }
        system("cls");
        getchar();

    } while (contador_jogador[0] < 24 || contador_jogador[1] < 24);//o jogo roda enquanto nenhum jogador tiver 24 cartas//
    
    return ;
}

    






