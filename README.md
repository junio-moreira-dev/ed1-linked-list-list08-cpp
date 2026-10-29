<p align="right">
  <a href="#-ed1--linked-lists--list-08">🇺🇸 English</a> ·
  <a href="#-ed1--listas-encadeadas--lista-08">🇧🇷 Português</a>
</p>

# 📘 ED1 — Linked Lists — List 08

Practice exercises for **Data Structures I** — advanced techniques on singly linked lists in C++ (middle node with fast/slow pointers, in-place palindrome check, removal of duplicates with `delete`, odd-even regrouping, and addition of two numbers with carry).

> Federal Institute of Education, Science and Technology of Triângulo Mineiro — Campus Patrocínio
> Course: Systems Analysis and Development Technology — 3rd Term — Evening
> Curricular Unit: Data Structures I
> Professor: Júnio Moreira
> **Due: October 27, 2026**

---

## 📁 Project Structure

```
ed1-linked-list-list08-cpp/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   ├── List.h
│   └── LinkedList.h
└── src/
    ├── Exer01_MiddleNode.cpp
    ├── Exer02_PalindromeList.cpp
    ├── Exer03_RemoveDuplicates.cpp
    ├── Exer04_OddEvenList.cpp
    └── Exer05_AddTwoNumbers.cpp
```

The list structure lives in `include/`, and each exercise is solved independently in its own file inside `src/`. Every `Exer*.cpp` file is **self-contained** (has its own `main()`) and follows the same pattern:

| Part | Responsibility |
|---|---|
| `class Solution` | Implements the algorithm, using the `LinkedList` structure. |
| `main()` | Runs the test cases and prints each `Output` next to its `Expected` value. |

> **About `Solution`:** `LinkedList` declares `friend class Solution;`, so the `Solution` class can access `head`, `tail`, `count` and the `Node` type, which are private. Any other code still cannot touch them.

---

## 📝 Exercises

| # | File | Problem | Technique | Complexity |
|---|---|---|---|---|
| 1 | `Exer01_MiddleNode.cpp` | Find the middle node of the list | Fast/slow pointers, one pass | O(N) time, O(1) space |
| 2 | `Exer02_PalindromeList.cpp` | Check if the list is a palindrome | Find the middle, reverse the second half in place, compare | O(N) time, O(1) space |
| 3 | `Exer03_RemoveDuplicates.cpp` | Remove repeated values from a sorted list | Relink `next`, then free the node with `delete` | O(N) time, O(1) space |
| 4 | `Exer04_OddEvenList.cpp` | Group the nodes of odd positions, then the nodes of even positions | Relink the existing nodes in place | O(N) time, O(1) space |
| 5 | `Exer05_AddTwoNumbers.cpp` | Add two numbers stored digit by digit in reverse order | Carry + dummy head | O(max(N, M)) time |

<details>
<summary><strong>Examples for each exercise</strong></summary>

### 1. Middle Node
```
Input:  1 2 3 4 5          Output: 3 4 5
Input:  1 2 3 4 5 6        Output: 4 5 6
```
The output is the list from the middle node to the end. With an even number of nodes, the middle is the second one.

### 2. Palindrome Linked List
```
Input:  1 2 2 1            Output: true
Input:  1 2 3 2 1          Output: true
Input:  1 2 3 4            Output: false
```

### 3. Remove Duplicates from a Sorted List
```
Input:  1 1 2              Output: 1 2
Input:  1 1 2 3 3          Output: 1 2 3
Input:  4 4 4 4 4          Output: 4
```

### 4. Odd-Even Linked List
```
Input:  1 2 3 4 5          Output: 1 3 5 2 4
Input:  2 1 3 5 6 4 7      Output: 2 3 6 7 1 5 4
```

### 5. Add Two Numbers
```
Input:  2 4 3              Output: 7 0 8        (342 + 465 = 807)
        5 6 4

Input:  0                  Output: 0
        0

Input:  9 9 9 9 9 9 9      Output: 8 9 9 9 0 0 0 1
        9 9 9 9
```

</details>

---

## 💻 How to Run

Compile from the **root** of the repository (the include path is relative):

```bash
g++ -std=c++17 -Wall -Wextra -o exer01 src/Exer01_MiddleNode.cpp
./exer01
```

Use the same command for the other exercises, changing the file name.

---

## ⚠️ Read the Problem Statement Carefully

- **Exercise 1:** find the middle in **one pass** (no counting pass first). With an even number of nodes, return the **second** middle node, and print from it to the end of the list.
- **Exercise 2:** use **O(1)** extra memory: no array, no stack, no copy of the values. Find the middle, reverse the second half in place and compare node by node. Restoring the original list at the end is recommended.
- **Exercise 3:** the list is sorted and may be **empty**. Relink `next` **before** the `delete`, free every redundant node and create no auxiliary list.
- **Exercise 4:** group by **position** (1st, 2nd, 3rd...), not by value, keeping the relative order inside each group. Do it in place: no new nodes and no swapping of values.
- **Exercise 5:** the digits are in **reverse** order (the head holds the units). Handle lists of different lengths, keep a `carry`, and if a carry remains at the end, add one more node. The result is a **new** list; a dummy head makes the construction simpler.

---

## ✅ Requirements

- C++17 compiler or newer (GCC, Clang, or MSVC)
- CMake ≥ 3.20
- CLion (recommended) or any IDE/editor of your choice

---

## 📚 Reference

Original exercise list: *List 08 — Advanced Techniques in Linked Lists (C++)* (due October 27, 2026).

<br>

<p align="right">
  <a href="#-ed1--linked-lists--list-08">🇺🇸 English</a> ·
  <a href="#-ed1--listas-encadeadas--lista-08">🇧🇷 Português</a>
</p>

<br>

<details>
<summary><strong>🇧🇷 Clique para ver a versão em Português</strong></summary>

# 📘 ED1 — Listas Encadeadas — Lista 08

Exercícios de fixação para **Estrutura de Dados I** — técnicas avançadas em listas simplesmente encadeadas em C++ (nó central com ponteiros fast/slow, verificação de palíndromo in-place, remoção de duplicatas com `delete`, reagrupamento ímpar-par e soma de dois números com transporte).

> Instituto Federal de Educação, Ciência e Tecnologia do Triângulo Mineiro — Campus Patrocínio
> Curso: Tecnologia em Análise e Desenvolvimento de Sistemas — 3º Período — Noturno
> Unidade Curricular: Estrutura de Dados I
> Professor: Júnio Moreira
> **Entrega: 27/10/2026**

---

## 📁 Estrutura do Projeto

```
ed1-linked-list-list08-cpp/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   ├── List.h
│   └── LinkedList.h
└── src/
    ├── Exer01_MiddleNode.cpp
    ├── Exer02_PalindromeList.cpp
    ├── Exer03_RemoveDuplicates.cpp
    ├── Exer04_OddEvenList.cpp
    └── Exer05_AddTwoNumbers.cpp
```

A estrutura da lista fica em `include/`, e cada exercício é resolvido de forma independente em um arquivo próprio dentro de `src/`. Todo arquivo `Exer*.cpp` é **autocontido** (possui seu próprio `main()`) e segue o mesmo padrão:

| Parte | Responsabilidade |
|---|---|
| `class Solution` | Implementa o algoritmo, usando a estrutura `LinkedList`. |
| `main()` | Executa os casos de teste e imprime cada `Output` ao lado do valor `Expected`. |

> **Sobre a `Solution`:** a `LinkedList` declara `friend class Solution;`, então a classe `Solution` pode acessar `head`, `tail`, `count` e o tipo `Node`, que são privados. Nenhum outro código consegue acessá-los.

---

## 📝 Exercícios

| # | Arquivo | Problema | Técnica | Complexidade |
|---|---|---|---|---|
| 1 | `Exer01_MiddleNode.cpp` | Encontrar o nó central da lista | Ponteiros fast/slow, uma passagem | O(N) tempo, O(1) espaço |
| 2 | `Exer02_PalindromeList.cpp` | Verificar se a lista é um palíndromo | Achar o meio, inverter a segunda metade in-place e comparar | O(N) tempo, O(1) espaço |
| 3 | `Exer03_RemoveDuplicates.cpp` | Remover valores repetidos de uma lista ordenada | Religar o `next` e liberar o nó com `delete` | O(N) tempo, O(1) espaço |
| 4 | `Exer04_OddEvenList.cpp` | Agrupar os nós de posições ímpares e depois os de posições pares | Religar os nós existentes in-place | O(N) tempo, O(1) espaço |
| 5 | `Exer05_AddTwoNumbers.cpp` | Somar dois números guardados dígito a dígito em ordem inversa | Transporte (carry) + nó sentinela | O(max(N, M)) tempo |

<details>
<summary><strong>Exemplos de cada exercício</strong></summary>

### 1. Nó Central
```
Entrada: 1 2 3 4 5         Saída: 3 4 5
Entrada: 1 2 3 4 5 6       Saída: 4 5 6
```
A saída é a lista a partir do nó central até o fim. Com número par de nós, o central é o segundo.

### 2. Lista Encadeada Palíndromo
```
Entrada: 1 2 2 1           Saída: true
Entrada: 1 2 3 2 1         Saída: true
Entrada: 1 2 3 4           Saída: false
```

### 3. Remoção de Duplicatas em Lista Ordenada
```
Entrada: 1 1 2             Saída: 1 2
Entrada: 1 1 2 3 3         Saída: 1 2 3
Entrada: 4 4 4 4 4         Saída: 4
```

### 4. Lista Ímpar-Par
```
Entrada: 1 2 3 4 5         Saída: 1 3 5 2 4
Entrada: 2 1 3 5 6 4 7     Saída: 2 3 6 7 1 5 4
```

### 5. Soma de Dois Números
```
Entrada: 2 4 3            Saída: 7 0 8        (342 + 465 = 807)
         5 6 4

Entrada: 0                Saída: 0
         0

Entrada: 9 9 9 9 9 9 9    Saída: 8 9 9 9 0 0 0 1
         9 9 9 9
```

</details>

---

## 💻 Como Executar

Compile a partir da **raiz** do repositório (o caminho do `include` é relativo):

```bash
g++ -std=c++17 -Wall -Wextra -o exer01 src/Exer01_MiddleNode.cpp
./exer01
```

Use o mesmo comando para os demais exercícios, trocando o nome do arquivo.

---

## ⚠️ Leia o Enunciado com Atenção

- **Exercício 1:** encontre o meio em **uma única passagem** (sem uma passagem prévia para contar). Com número par de nós, retorne o **segundo** nó central e imprima a partir dele até o fim da lista.
- **Exercício 2:** use memória extra **O(1)**: sem vetor, sem pilha e sem copiar os valores. Ache o meio, inverta a segunda metade in-place e compare nó a nó. É recomendado restaurar a lista original no final.
- **Exercício 3:** a lista é ordenada e pode ser **vazia**. Religue o `next` **antes** do `delete`, libere cada nó redundante e não crie lista auxiliar.
- **Exercício 4:** agrupe por **posição** (1º, 2º, 3º...), e não por valor, mantendo a ordem relativa dentro de cada grupo. Faça in-place: sem nós novos e sem trocar valores.
- **Exercício 5:** os dígitos estão em ordem **inversa** (o `head` guarda as unidades). Trate listas de tamanhos diferentes, mantenha um `carry` e, se sobrar transporte no fim, acrescente mais um nó. O resultado é uma **nova** lista; um nó sentinela simplifica a construção.

---

## ✅ Requisitos

- Compilador C++17 ou mais recente (GCC, Clang ou MSVC)
- CMake ≥ 3.20
- CLion (recomendado) ou qualquer IDE/editor de sua preferência

---

## 📚 Referência

Lista de exercícios original: *Lista 08 — Técnicas Avançadas em Listas Encadeadas (C++)* (entrega 27/10/2026).

</details>
