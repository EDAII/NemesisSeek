# Busca Nemesis

## Alunos  
| Matrícula | Nome |  
|-----------------------|---------------------|  
| 23/1033737 | Artur Mendonça Arruda |  
| 23/1035464 | Lucas Mendonça Arruda |  

## Descrição

O NemesisSeek é um jogo em C onde o jogador precisa abrir portas para avançar por diferentes fases, enquanto um monstro se aproxima constantemente. Cada porta possui uma chave que deve ser encontrada utilizando algoritmos de busca ou dicas fornecidas pelo próprio jogo. Algumas portas são especiais e permitem que o jogador passe de fase. O objetivo principal do jogo é completar todas as fases antes que o monstro alcance o jogador.
O projeto é inspirado em um cenário de labirinto, onde o jogador precisa escapar enquanto é perseguido. Cada porta possui uma combinação específica que deve ser descoberta usando diferentes algoritmos de busca. A escolha correta do algoritmo é crucial para a sobrevivência.

# Guia de instalação

### Dependências do projeto

- **Sistema operacional:** Linux
- **Compilador:** GCC (versão recomendada: 9.4 ou superior)
- **Linguagem:** C (padrão C99 ou superior)
- **Ferramentas opcionais:** Make (para automação da compilação, caso queira criar um Makefile)

Para usuários Windows, é necessário:
- Instalar o GCC (GNU Compiler Collection) ou
- Utilizar um compilador online como o [OnlineGDB](https://www.onlinegdb.com/)

Não são necessárias bibliotecas externas, apenas o compilador C padrão.  


## Como executar o projeto
1. Clone o repositório
```bash
git clone https://github.com/EDAII/NemesisSeek.git
```
1. Abra o terminal na pasta do projeto com o comando: `cd NemesisSeek`  
2. Compile todos os arquivos juntos usando o GCC:

```bash
gcc main.c busca_binaria.c busca_sequencial.c hash.c -o programa
```
3. Execute o programa:
   ```
   ./programa
   ```

## Capturas de tela

### Busca Sequencial

![Busca Sequencial](https://raw.githubusercontent.com/EDAII/Busca_Nemesis/refs/heads/master/assets/algoritmos/busca_sequencial.png)  

A busca sequencial percorre o vetor elemento por elemento até encontrar o valor desejado.  
- Cada verificação é contabilizada como um passo.  
- No contexto do jogo, cada passo aproxima o monstro.

### Busca Binária

![Busca Binária](https://raw.githubusercontent.com/EDAII/Busca_Nemesis/refs/heads/master/assets/algoritmos/busca_binaria.png) 

A busca binária só pode ser usada em vetores ordenados.  
- Ela divide o vetor ao meio a cada comparação, descartando metade dos elementos restantes.  
- Cada comparação também conta como um passo, impactando a distância do monstro.  
- Comparada à busca sequencial, geralmente requer muito menos passos para encontrar a chave, mas só funciona em portas ordenadas.

### Função Hash

![Função Hash](https://raw.githubusercontent.com/EDAII/Busca_Nemesis/refs/heads/master/assets/algoritmos/hash.png)

A função hash utilizada combina o algoritmo **djb2**, criado por Daniel J. Bernstein, com uma transformação baseada na **razão áurea (φ)**.  

- O algoritmo começa com um valor inicial de **5381**, escolhido empiricamente por Bernstein por gerar boa dispersão e poucas colisões.  
- Para cada caractere da string, a hash acumulada é multiplicada por 33 e somada ao valor ASCII do caractere.  
- Em seguida, o valor é multiplicado por uma constante derivada da razão áurea (**0.6180339887**). Essa etapa “embaralha” os números e ajuda a distribuir melhor as chaves.  
- A parte inteira do resultado é descartada, mantendo apenas a parte fracionária.  
- Por fim, o valor é escalonado para caber no tamanho da tabela (`TAM_HASH`).  


## Conclusões

Os algoritmos de busca implementados foram úteis para ilustrar a diferença de desempenho entre métodos de busca em vetores ordenados e desordenados. No contexto do jogo, eles tornam a experiência mais estratégica, pois o número de interações afeta diretamente o avanço do monstro, incentivando o jogador a escolher o algoritmo mais adequado para cada porta.

### Limitações

- A busca binária só pode ser utilizada em portas ordenadas, limitando sua aplicação em parte do jogo.  
- A busca sequencial pode ser lenta em vetores grandes, penalizando o jogador se o valor não estiver presente.  
- O jogo depende de sorte na geração das portas, tornando algumas partidas mais lentas ou rápidas. 

### Link do Vídeo de apresentação

[Link Vídeo](https://youtu.be/-i91VBz_8ek)

[Link Vídeo](https://youtube.com/embed/-i91VBz_8ek)


## Histórico de Versões

<div align="center">

| Versão | Data | Descrição | Autor | Revisor | Revisão |
|-----------|---------|--------------|----------|------------|------------|
| `v1.0` | 08/09/2025 | Estruturação inicial da README | [Artur Mendonça](https://github.com/ArtyMend07) | [Lucas Mendonça](https://github.com/lucasarruda9) | 08/09/2025 |
