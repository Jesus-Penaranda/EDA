#include "Player.hh"
#include <queue>
#include <set>
#include <vector>
#include <map>

#define PLAYER_NAME JP1

struct PLAYER_NAME : public Player {

  static Player* factory() 
  {
    return new PLAYER_NAME;
  }

  const vector<Dir> dirs = {Up, Down, Left, Right};
  const vector<Dir> dirs_ghost = {Up, Down, Left, Right, DR, RU, UL, LD};
  set<int> fantasmas_descansando;

  virtual void play() 
  {
    vector<int> ws = wizards(me());
    for (int id : ws) 
    {
      Unit w = unit(id);
      mover_mago(w);
    }

    // Mover al fantasma
    int ghost_id = ghost(me());
    if (ghost_id != -1) 
    {
      Unit g = unit(ghost_id);
      mover_fantasma(g);
    }
  }
  // Mover a los magos buscando libros
  void mover_mago(Unit& mago) 
  {
    Pos inicio = mago.pos;

    // Buscar libros
    Pos siguiente_paso = bfs_buscar_libro(inicio, false);
    if (siguiente_paso != Pos(-1, -1)) 
    {
      Dir direccion = obtener_direccion(inicio, siguiente_paso, false);
      move(mago.id, direccion);
      return;
    }

    // Si no encontramos un libro, mover aleatorio
    movimiento_random(mago, dirs);
  }

  void mover_fantasma(Unit& fantasma) 
  {
    Pos inicio = fantasma.pos;
    if (fantasmas_descansando.find(fantasma.id) != fantasmas_descansando.end()) return;
    
    Pos siguiente_paso = bfs_buscar_libro(inicio, true);
    if (siguiente_paso != Pos(-1, -1)) 
    {
      Dir direccion = obtener_direccion(inicio, siguiente_paso, true);
      move(fantasma.id, direccion);
      return;
    }
    if (round() > 50 and fantasma.resting_rounds() == 0) 
    { 
      vector<int> ingredientes = spell_ingredients();
      vector<int> solucion = resolver_hechizo(ingredientes);
      if (not solucion.empty()) 
      {
        spell(fantasma.id, solucion);
        fantasmas_descansando.insert(fantasma.id);
        return;
      }
    }

    // Movimiento aleatorio si no hay libros
    movimiento_random(fantasma, dirs_ghost);
  }
  vector<int> resolver_hechizo(const vector<int>& ingredientes) 
  {
    int suma_total = 0;

    //Suma total de los ingredientes
    for (int x : ingredientes) 
    {
      suma_total += x;
    }
    int suma_objetivo = suma_total / 3;
    vector<int> solucion(ingredientes.size(), -1); 
    vector<int> grupos(3, 0); 

    //Usamos backtracking para encontrar la solución
    if (backtrack_agrupacion(ingredientes, solucion, grupos, suma_objetivo, 0)) return solucion;
    return {}; // No se encontró nada
  }

  // Backtracking para agrupar ingredientes
  bool backtrack_agrupacion(const vector<int>& ingredientes, vector<int>& solucion, vector<int>& grupos, int suma_objetivo, size_t index) 
  {
  
    if (index == ingredientes.size()) 
    {
      return grupos[0] == suma_objetivo and grupos[1] == suma_objetivo and grupos[2] == suma_objetivo;
    }
    for (int g = 0; g < 3; ++g) 
    {
      if (grupos[g] + ingredientes[index] <= suma_objetivo) 
      {
        grupos[g] += ingredientes[index];
        solucion[index] = g;

        if (backtrack_agrupacion(ingredientes, solucion, grupos, suma_objetivo, index + 1)) return true;

        grupos[g] -= ingredientes[index];
        solucion[index] = -1;
      }
    }

    return false;
  }

  //Buscar libros
  Pos bfs_buscar_libro(Pos inicio, bool permitir_diagonal) 
  {
    queue<Pos> q;
    set<Pos> visitados;
    map<Pos, Pos> padres;
    q.push(inicio);
    visitados.insert(inicio);

    vector<Dir> direcciones;
    if (permitir_diagonal) direcciones = dirs_ghost;
    else direcciones = dirs;
    

    while (not q.empty()) 
    {
      Pos actual = q.front();
      q.pop();
      if (cell(actual).book) 
      {
        while (padres[actual] != inicio) actual = padres[actual];
        return actual; 
      }
      for (auto d : direcciones) 
      {
        Pos siguiente = actual + d;
        if (pos_ok(siguiente) and visitados.find(siguiente) == visitados.end() and cell(siguiente).type != Wall) 
        {
          visitados.insert(siguiente);
          padres[siguiente] = actual;
          q.push(siguiente);
        }
      }
    }

    return Pos(-1, -1); // No hay libro
  }

  // Movimiento aleatorio
  void movimiento_random(Unit& u, const vector<Dir>& direcciones) 
  {
    for (size_t i = 0; i < direcciones.size(); ++i) 
    {
      int random_index = random(0, direcciones.size() - 1);
      Dir direccion_random = direcciones[random_index];
      Pos pos_random = u.pos + direccion_random;

      if (pos_ok(pos_random)) 
      {
        if (cell(pos_random).type != Wall) 
        {
          move(u.id, direccion_random);
          return;
        }
      }
    }
  }

  // Obtener dirección hacia un objetivo
  Dir obtener_direccion(Pos desde, Pos hasta, bool permitir_diagonal) 
  {
    vector<Dir> direcciones;
    if (permitir_diagonal) direcciones = dirs_ghost;
    else direcciones = dirs;

    for (auto d : direcciones) if (desde + d == hasta) return d;
    return Up; // Por defecto
  }
};

/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
