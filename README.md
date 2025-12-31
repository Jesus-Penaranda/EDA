# EDA - FIB Solutions

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=c%2B%2B&logoColor=white)
![FIB](https://img.shields.io/badge/FIB-UPC-orange?logo=cplusplus)
![Status](https://img.shields.io/badge/Jutge-Accepted%20🟢-success)

Bienvenido a mi repositorio de **Estructura de Datos y Algoritmos** de la **Facultad de Informática de Barcelona**.

Si en PRO2 aprendiste a *construir* las estructuras (listas, árboles, pilas...), aquí aprenderás a **usarlas** para resolver problemas complejos. La clave ya no es solo que funcione, sino que sea **rápido** (Eficiencia y Complejidad).

---

## Estructura del Repositorio

Los ejercicios están organizados según los bloques temáticos del Jutge y las prácticas de laboratorio:

### Uso de Estructuras de Datos (STL)
- **STL Data Structures** (Sets, Maps, Priority Queues...)
- Uso inteligente de contenedores para optimizar búsquedas.

### Algoritmia y Recursividad
- **Divide and Conquer** (MergeSort, Búsqueda Binaria, QuickSort...)
- **Exhaustive Search & Generation** (Backtracking puro y duro).

### Algoritmos en Grafos
- **Graph Algorithms** (DFS, BFS, Dijkstra, Topological Sort).
- Detección de ciclos y caminos mínimos.

## Puntos Clave
- Dominio absoluto de la **STL** de C++ (`std::map`, `std::set`, `std::priority_queue`).
- **Grafos**: Saber modelar un problema de la vida real como un grafo es el 80% de la asignatura.
- **Eficiencia**: Entender la notación Big O ($O(n \log n)$, $O(n^2)$...) es obligatorio para no tener *Time Limit Exceeded*.
- **Backtracking**: Poda efectiva para evitar explorar soluciones inútiles.

---

## The Harry Potter Game (EDA Project)

**Asignatura:** Estructura de Dades i Algorismes (FIB - UPC)

### Descripción del Juego
El objetivo es programar una IA (Bot) en C++ para controlar un equipo de magos y fantasmas en un tablero de 60x60.
La partida consiste en una competición de 4 jugadores (Gryffindor, Slytherin, Ravenclaw, Hufflepuff) durante 200 rondas.

### Mecánicas Principales
- **Unidades:** Cada jugador controla Magos (se mueven ortogonalmente) y Fantasmas (se mueven en todas direcciones y atraviesan obstáculos).
- **Objetivo:** Acumular puntos recolectando libros y convirtiendo a magos enemigos mediante batallas de fuerza mágica.
- **El Villano (Voldemort):** Una unidad autónoma controlada por el sistema que persigue y elimina a cualquier unidad cercana, obligándola a regenerarse y perder atributos.
- **Hechizos:** Los fantasmas pueden realizar hechizos resolviendo un sub-problema algorítmico (Subset Sum con ingredientes) para conquistar territorio.

### Tecnologías
- **Lenguaje:** C++
- **Algoritmos:** Búsqueda en grafos (BFS/DFS/Dijkstra etc...) para el pathfinding, gestión de estados y heurísticas de decisión.

---

>[!TIP]
> **Dirigido a los FIBers:**
>
> EDA es, para muchos, la asignatura más bonita pero también la que más "coco" requiere. Aquí copiar código sirve de poco si no entiendes el **por qué** un algoritmo es más rápido que otro.
>
> **Sobre el Juego:** Es muy divertido y te puedes picar mucho intentando ganar a tus compañeros.
>
> *Pequeño consejo: Si el Jutge te da TLE (Time Limit Exceeded), revisa si estás pasando estructuras enormes por valor en lugar de por referencia.* 

---
<p align="center">
  Hecho con 💻, ☕ y muchos <i>Time Limit Exceeded</i> en la FIB.
</p>
