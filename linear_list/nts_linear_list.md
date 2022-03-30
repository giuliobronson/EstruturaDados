# Listas Lineares

## Como são representados números negativos de maneira binária?

$$
  a - b = a + (!b + 1)
$$

- *variável* = *tipo* + *alocação* + *identificador* + *escopo*
  - __*Tipo*__: Definir a representação interna do objeto de dados. Número de bits e código.

  - __*Alocação*__: Espaço de memória.

## Listas Lineares

> __*def*__: É um conjunto de $n \geq 0$ nós tais que suas propriedades estruturais decorrem da posição relaticva dos nós dentro da sequência linear.

- A declaração de estruturas de dados estática define a memória necessária para alocação antes do tempo de execução.

- Uma lista obrigatoriamente começa vazia e é populada conforme os elementos são inseridos em tempo de execução.

- A lista é sempre dinâmica, mas pode ser tratada por alocação dinâmica ou estática.

### Implementação com alocação estática da lista

- A implementação estática da lista usa um vetor com a posição $0$ como contador de elemento.

```c
  int lista[1000];
  lista[0] = 0;
```

- Inserções são ordem de $O(1)$

- Remoção de elementos é ordem $\Theta(n)$

### Casos particulares de interesse

- __*Deque*__: É uma fila no qual há a possibilidade de inserção e remoção por ambos os lados. Professor nunca utilizou na vida dele.

- __*Pilha*__: Último elemento a entrar é o primeiro a sair. Análogo a uma pilha de pratos. **LIFO**

- __*Fila*__: Inserção sempre na última posição e remoção sempre na primeira. **FIFO** 

### Tipos de armazenamento

- Armazenamento sequêncial

- Armazenamento encadeado

> __*Atenção*__: Não se faz busca binária em uma estrutura que não tenha alocação estática e sequencial


